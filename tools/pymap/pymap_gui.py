import tkinter
import PIL.Image as PImage
from tkinter import messagebox, filedialog
from . import tkinterx
from . import mapheader, mapfooter, mapconnection, mapevent, tileset
import PIL.ImageTk as ImageTk
import os, getopt


NONE, BLOCKS, LEVELS, EVENTS = range(4)


BLOCK_CANVAS_SIZE = 600

class Pymap_gui(tkinter.Frame):
    """ Main gui frame for the pymap module """
    def __init__(self, root):

        self.map = None
        self.context = NONE
        self.block_selection_size = 1, 1 #Keeping track of the block selection size
        self.block_selection = [[0]]
        self.block_selection_area = 0, 0, 0, 0
        self._init_gui(root)
        self.undo_stack = [] #Tuple: func(mode, arg), arg
        self.redo_stack = [] #as above


    def _init_gui(self, root):
        """ Initializes all members of the gui"""
        tkinter.Frame.__init__(self, root) #Superclass init
        self.root = root
        width, height = root.winfo_screenwidth(), root.winfo_screenheight()

        #Setup the menu
        menu = tkinter.Menu(root)
        root.config(menu=menu)
        file_menu = tkinter.Menu(menu, tearoff=0)
        menu.add_cascade(label="File", menu=file_menu)
        file_menu.add_command(label="New", command=self.file_new)
        file_menu.add_command(label="Open", command=self.file_open)
        file_menu.add_command(label="Save", command=self.file_save)
        menu.add_radiobutton(label="Footer", command=self.edit_footer)
        menu.add_radiobutton(label="Undo", command=self.undo)
        menu.add_radiobutton(label="Redo", command=self.redo)

        #Setup a context widget on the left of the frame
        self.context_widget = None
        self._setup_block_widget() #Start in context of editing the blocks on the map (self.context -> BLOCKS)
        


    def _setup_block_widget(self):
        """ Creates the block widget at the right part of the window """
        root = self.root
        if self.context_widget: self.context_widget.grid_forget() #Remove the old context widget if present
        self.context = BLOCKS
        self.context_widget = tkinter.Frame(root)
        self.context_widget.grid(row=0, column=2, sticky=tkinter.NW)

        tkinter.Label(self.context_widget, text="Border:", relief=tkinter.RIDGE).grid(row=4, column=0, sticky=tkinter.NW)
        self.border_canvas = tkinter.Canvas(self.context_widget, width=16 * 1, height=16* 1, background="black")
        self.border_canvas.grid(row=5, column=0, sticky=tkinter.NW)
        tkinter.Label(self.context_widget, text="Selection:", relief=tkinter.RIDGE).grid(row=2, column=0, sticky=tkinter.NW)
        self.selection_frame = tkinter.Frame(self.context_widget)
        self.selection_frame.grid(row=3, column=0, sticky=tkinter.NW)
        self.selection_canvas = tkinter.Canvas(self.selection_frame, width=16, height=16, background="black")
        self.selection_raw_pil_image = PImage.new("RGBA", (16, 16), "black")
        self.selection_raw_image = ImageTk.PhotoImage(self.selection_raw_pil_image)
        self.selection_canvas.pack(side=tkinter.LEFT)
        self.selection_canvas_image = self.selection_canvas.create_image(1, 1, image=self.selection_raw_image, anchor=tkinter.NW)
        tkinter.Label(self.context_widget, text="Blocks:", relief=tkinter.RIDGE).grid(row=0, column=0, sticky=tkinter.NW)
        self.block_canvas_frame = tkinter.Frame(self.context_widget)
        self.block_canvas_frame.grid(row=1, column=0, columnspan=2, sticky=tkinter.NW)
        self.block_canvas = tkinter.Canvas(self.block_canvas_frame, width=128, height=BLOCK_CANVAS_SIZE, background="black", scrollregion=(0, 0, 128, 2048))
        self.block_canvas.pack(side=tkinter.LEFT)
        self.block_canvas_bar_v = tkinter.Scrollbar(self.block_canvas_frame, orient=tkinter.VERTICAL)
        self.block_canvas_bar_v.pack(side=tkinter.RIGHT, fill=tkinter.Y)
        self.block_canvas_bar_v.config(command=self.block_canvas.yview)
        self.block_canvas.config(yscrollcommand=self.block_canvas_bar_v.set)
        self.block_raw_pil_image = PImage.new("RGBA", (128, 1024), "black")
        self.block_raw_image = ImageTk.PhotoImage(self.block_raw_pil_image)
        self.block_canvas_image = self.block_canvas.create_image(1, 1, image=self.block_raw_image, anchor=tkinter.NW)
        self.block_canvas_selection_rectangle = self.block_canvas.create_rectangle(0, 0, 16, 16, outline="red", fill="")
        self._refresh_blocks()
        self._refresh_borders()
        self._refresh_block_selection()
        self._refresh_map()

        #Event binding of block canvas (selection)
        def update_block_selection_by_area(x0, y0, x1, y1):
            """ Updates the block selection by the block selection area """
            if not self._can_draw or not self.context == BLOCKS: return
            #Check if the rectangle is valid (bottom right block is defined)
            if (y1 - 1) * 8 + x1 - 1 >= len(self.block_imgs): return
            self.block_selection_area = x0, y0, x1, y1
            self.block_selection = [[8 * y + x for x in range(x0, x1)] for y in range(y0, y1)]
            self.block_canvas.delete(self.block_canvas_selection_rectangle)
            self.block_canvas_selection_rectangle = self.block_canvas.create_rectangle(16 * x0, 16 * y0, 16 * x1, 16 * y1, fill="", outline="red")
            self._refresh_block_selection()

        def block_canvas_b_pressed(e):
            slider_top, slider_bottom = self.block_canvas_bar_v.get()
            x, y = e.x, e.y + (slider_top * 2048)
            x0, y0 = int(x / 16), int(y / 16)
            update_block_selection_by_area(x0, y0, x0 + 1, y0 + 1)
        
        def block_canvas_b_motion(e):
            x0, y0, _, _ = self.block_selection_area
            slider_top, slider_bottom = self.block_canvas_bar_v.get()
            x, y = e.x, e.y + (slider_top * 2048)
            x1, y1 = int(x / 16) + 1, int(y / 16) + 1
            if x1 > 8: x1 = 8
            if y1 > 256: y1 = 256
            if x1 <= x0: x1 = x0 + 1
            if y1 <= y0: y1 = y0 + 1
            update_block_selection_by_area(x0, y0, x1, y1)


        self.block_canvas.bind("<ButtonPress-1>", block_canvas_b_pressed)
        self.block_canvas.bind("<ButtonPress-3>", block_canvas_b_pressed)
        self.block_canvas.bind("<B3-Motion>", block_canvas_b_motion)




    def _can_draw(self):
        """ Checks if anything can drawn (juding from state of tss and tsp)"""
        if not self.map: return False
        if not self.map.footer: return False
        if not self.map.footer.tsp or not self.map.footer.tss: return False
        if self.map.footer.tsp.image.empty or self.map.footer.tss.image.empty: return False
        return True



    def _get_tile(self, id, pal, hflip, vflip):
        """ Retrieves a tile from the tile pool """
        if not self.map.footer.tsp or not self.map.footer.tss: return
        if pal < 7: colors = self.map.footer.tsp.palettes[pal].colors
        else: colors = self.map.footer.tss.palettes[pal - 7].colors
        if id < 0x280: return self.map.footer.tsp.get_tile(id, colors, hflip, vflip)
        else: return self.map.footer.tss.get_tile(id - 0x280, colors, hflip, vflip)

    def _compute_block(self, primary, id):
        """ Computes a block in a certain tileset """
        if not self.map.footer.tsp or not self.map.footer.tss: return
        t = self.map.footer.tsp if primary else self.map.footer.tss
        block = t.blocks[id]
        return self._compute_block_by_data(block)

    def _compute_block_by_data(self, data):
        """ Computes a block by its tilemap data"""
        img = PImage.new("RGBA", (16, 16), "black")
        for k in range(8):
            map_data = data[k]
            id, vflip, hflip = map_data & 0x3FF, bool(map_data & 0x400), bool(map_data & 0x800)
            pal_id = (map_data >> 12) & 0xF
            if pal_id > 12: continue
            j = k & 3 #Index of inner loop (the computing loop is 2 layered, j runs from 0 to 3 for every layer)
            x, y = j & 1, j >> 1
            tile_image = self._get_tile(id, pal_id, hflip, vflip)
            if k < 4: #Paste without alpha channel on color #0
                img.paste(tile_image, (8 * x, 8 * y))
            else: #Paste with alpha channel on color #0
                img.paste(tile_image, (8 * x, 8 * y), tile_image)
        return img


    def _refresh_blocks(self):
        """ Refreshes all blocks """
        if not self._can_draw() or not self.context == BLOCKS: return
        if not self.map.footer.tsp or not self.map.footer.tss: return
        tsp, tss = self.map.footer.tsp, self.map.footer.tss
        #First we create a pool of all blocks
        def get_tile(id, hflip, vflip, pal):
            #Inner method to retrieve a tile from the tile pool in a certain color
            colors = tsp.palettes[i].colors if pal < 7 else tss.palettes[i - 7].colors
            return tsp.get_tile(id, colors, hflip, vflip) if tile < 0x280 else tss.get_tile(id - 0x280, colors, hflip, vflip)
        self.block_imgs = [self._compute_block(True, i) for i in range(len(self.map.footer.tsp.blocks))] + [self._compute_block(False, i) for i in range(len(self.map.footer.tss.blocks))]
        self.block_raw_pil_image = PImage.new("RGBA", (128, 2048), "black")
        for i in range(len(self.block_imgs)):
            x, y = i & 7, i >> 3
            self.block_raw_pil_image.paste(self.block_imgs[i], (16 * x, 16 * y))
        self.block_canvas.delete(self.block_canvas_image)
        self.block_raw_image = ImageTk.PhotoImage(self.block_raw_pil_image)
        self.block_canvas_image = self.block_canvas.create_image(1, 1, image=self.block_raw_image, anchor=tkinter.NW)


    def _refresh_borders(self, b1binding=None):
        """ Refresh the borders """
        if not self._can_draw() or not self.context == BLOCKS: return
        bw, bh = self.map.footer.border_width, self.map.footer.border_height
        self.border_canvas.grid_remove()
        self.border_canvas = tkinter.Canvas(self.context_widget, width=16 * bw, height=16* bh, background="black")
        self.border_canvas.grid(row=5, column=0, sticky=tkinter.NW)
        self.border_raw_pil_image = PImage.new("RGBA", (bw * 16, bh * 16), "black")
        for y in range(len(self.map.footer.borders)):
            for x in range(len(self.map.footer.borders[y])):
                block_id, level = mapheader.block_data(self.map.footer.borders[y][x])
                img = self.block_imgs[block_id]
                self.border_raw_pil_image.paste(img, (16 * x, 16 * y))
        self.border_raw_image = ImageTk.PhotoImage(self.border_raw_pil_image)
        self.border_canvas.create_image(1, 1, image=self.border_raw_image, anchor=tkinter.NW)

        #Event binding of border canvas
        def border_canvas_b_pressed(e):
            print("asdf")
            x, y = int(e.x / 16), int(e.y / 16)
            action = Action_border_change(self, x, y, self.block_selection)
            self.undo_stack.append(action)
            action.do()

        self.border_canvas.bind("<ButtonPress-1>", border_canvas_b_pressed)

    def _refresh_block_selection(self):
        """ Refresh the selection widget"""
        if not self._can_draw() or not self.context == BLOCKS: return
        _selection_frame = self.selection_frame
        ow, oh = self.block_selection_size
        w, h = len(self.block_selection[0]), len(self.block_selection)
        if ow != w or oh != h:
            #Create a new frame and canvas
            cw, ch = min(w, 8), min(h, 4)
            self.selection_frame = tkinter.Frame(self.context_widget)
            self.selection_frame.grid(row=3, column=0, sticky=tkinter.NW)
            self.selection_canvas = tkinter.Canvas(self.selection_frame, width = 16 * cw, height = 16 * ch, background="black", scrollregion=(0, 0, 16 * w, 16 * h))
            if w > cw or h > ch:
                if h > ch:
                    #Add v scrollbar
                    self.selection_canvas_bar_v = tkinter.Scrollbar(self.selection_frame, orient=tkinter.VERTICAL)
                    self.selection_canvas_bar_v.pack(side=tkinter.RIGHT, fill=tkinter.Y)
                    self.selection_canvas_bar_v.config(command=self.selection_canvas.yview)
                    self.selection_canvas.config(yscrollcommand=self.selection_canvas_bar_v.set)
                if w > cw:
                    #Add h scrollbar
                    self.selection_canvas_bar_h = tkinter.Scrollbar(self.selection_frame, orient=tkinter.HORIZONTAL)
                    self.selection_canvas_bar_h.pack(side=tkinter.BOTTOM, fill=tkinter.X)
                    self.selection_canvas_bar_h.config(command=self.selection_canvas.xview)
                    self.selection_canvas.config(xscrollcommand=self.selection_canvas_bar_h.set)
            self.selection_canvas.pack(side=tkinter.LEFT)
            _selection_frame.grid_remove()
        self.block_selection_size = w, h

        self.selection_raw_pil_image = PImage.new("RGBA", (w * 16, h * 16), "black")
        for y in range(len(self.block_selection)):
            for x in range(len(self.block_selection[y])):
                block_id = self.block_selection[y][x]
                self.selection_raw_pil_image.paste(self.block_imgs[block_id], (16 * x, 16 * y))
        self.selection_raw_image = ImageTk.PhotoImage(self.selection_raw_pil_image)
        self.selection_canvas.create_image(1, 1, image=self.selection_raw_image, anchor=tkinter.NW)
        


    def undo(self):
        """ Pops from undo stack and undoes last action """
        if len(self.undo_stack):
            action = self.undo_stack.pop()
            self.redo_stack.append(action)
            action.undo()

    def redo(self):
        """ Pops from redo stack and redoes the last action """
        if len(self.redo_stack):
            action = self.redo_stack.pop()
            self.undo_stack.append(action)
            action.do()

    


    def _refresh_map(self):
        """ Refresh the map """
        pass
    
    def _refresh_title(self):
        """ Refreshes the title """
        if self.map: self.root.wm_title("Pymap - " + self.map.key)
        else: self.root.wm_title("Pymap - no map loaded")

    def _refresh(self):
        """ Refreshes all widgets """
        self._refresh_title()
        if self.context == BLOCKS:
            self._refresh_blocks()
            self._refresh_borders()
            self._refresh_block_selection()
            self._refresh_map()

    def file_new(self):
        """ Creates a new file """
        if self.map and tkinter.messagebox.askyesno("Save changes", "Do you want to save your changes to the map?"):
            if not self.file_save(): return #Save was unsucessfull, do not create a new file
        self.map = mapheader.Mapheader()
        self._refresh()

    def file_open(self):
        """ Opens a new file """
        if self.map and tkinter.messagebox.askyesno("Save changes", "Do you want to save your changes to the map?"):
            if not self.file_save(): return #Save was unsucessfull, do not create a new file
        options = {}
        if self.map and self.map.key != mapheader.PATH_UNSAFED:
            options["initialdir"] = os.path.dirname(self.map.key)
        options["filetypes"] = [('pymap map headers', '.pmh')]
        options["title"] = "Open map file"
        options["parent"] = self
        path = filedialog.askopenfilename(**options)
        self._load_map(path)

    def _load_map(self, path):
        """ Loads a map from a path if it is not emtpy """
        if not path or not len(path): return
        self.map = mapheader.load(path)
        self._refresh_title()
        self._refresh_blocks()
        self._refresh_map()
        self._refresh_borders()
        self._refresh_block_selection()
        print("Map file " + path + " opened successfully")

    def file_save(self):
        """ Saves a file """
        if not self.map: return
        options = {}
        if self.map.key != mapheader.PATH_UNSAFED:
            options["initialdir"] = os.path.dirname(self.map.key)
        options["defaultextension"] = ".pmh"
        options["filetypes"] = [('pymap map headers', '.pmh')]
        options["title"] = "Save map to file"
        options["parent"] = self
        path = filedialog.asksaveasfilename(**options)
        if not path or not len(path): return False
        self.map.save(path)
        self._refresh_title()
        print("Map file '" + path + "'saved sucessfully")
        return True

    def edit_footer(self):
        """ Opens a dialog for footer editing """
        if not self.map: return
        dialog = tkinter.Toplevel(self.root)
        #self.root.withdraw()
        dialog.wm_title("Edit mapfooter of map " + self.map.key)
        dialog.attributes("-toolwindow", 1)
        tkinter.Label(dialog, text="Primary tileset:").grid(row=0, column=0, sticky=tkinter.NW)
        tkinter.Label(dialog, text="Secondary tileset:").grid(row=1, column=0, sticky=tkinter.NW)
        entry_tsp, entry_tss = tkinter.Entry(dialog), tkinter.Entry(dialog)
        entry_tsp.grid(row=0, column=1, sticky=tkinter.NW), entry_tss.grid(row=1, column=1, sticky=tkinter.NW)
        if self.map.footer.tsp: entry_tsp.insert(0, self.map.footer.tsp.path)
        if self.map.footer.tss: entry_tss.insert(0, self.map.footer.tss.path)
        tkinter.Label(dialog, text="Map width:").grid(row=2, column=0, sticky=tkinter.NW)
        tkinter.Label(dialog, text="Map height:").grid(row=3, column=0, sticky=tkinter.NW)
        entry_width, entry_height = tkinter.Entry(dialog), tkinter.Entry(dialog)
        entry_width.grid(row=2, column=1, sticky=tkinter.NW), entry_height.grid(row=3, column=1, sticky=tkinter.NW)
        entry_width.insert(0, str(self.map.footer.width)), entry_height.insert(0, str(self.map.footer.height))
        tkinter.Label(dialog, text="Border width:").grid(row=4, column=0, sticky=tkinter.NW)
        tkinter.Label(dialog, text="Border height:").grid(row=5, column=0, sticky=tkinter.NW)
        entry_border_width, entry_border_height = tkinter.Entry(dialog), tkinter.Entry(dialog)
        entry_border_width.grid(row=4, column=1, sticky=tkinter.NW), entry_border_height.grid(row=5, column=1, sticky=tkinter.NW)
        entry_border_width.insert(0, str(self.map.footer.border_width)), entry_border_height.insert(0, str(self.map.footer.border_height))
        def apply_changes():
            try:
                self.map.footer.width, self.map.footer.height = int(entry_width.get(), 0), int(entry_height.get(), 0)
                self.map.footer.border_width, self.map.footer.border_height = int(entry_border_width.get(), 0), int(entry_border_height.get(), 0)
                #Extend or cut map and block data
                new_blocks = [[0 for i in range(self.map.footer.width)] for j in range(self.map.footer.height)]
                for y in range(min(self.map.footer.height, len(self.map.footer.blocks))):
                    for x in range(min(self.map.footer.width, len(self.map.footer.blocks[y]))):
                        new_blocks[y][x] = self.map.footer.blocks[y][x]
                new_borders = [[0 for i in range(self.map.footer.border_width)] for j in range(self.map.footer.border_height)]
                for y in range(min(self.map.footer.border_height, len(self.map.footer.borders))):
                    for x in range(min(self.map.footer.border_width, len(self.map.footer.borders[y]))):
                        new_borders[y][x] = self.map.footer.borders[y][x]
                self.map.footer.blocks = new_blocks
                self.map.footer.borders = new_borders
                if len(entry_tsp.get()): self.map.footer.tsp = tileset.from_file(entry_tsp.get())
                if len(entry_tss.get()): self.map.footer.tss = tileset.from_file(entry_tss.get())
                self._refresh_blocks()
                self._refresh_map()
                self._refresh_borders()
                self._refresh_block_selection()
            except Exception as e:
                messagebox.showerror("Footer error", "Unable to save footer properties: " + str(e))
        tkinter.Button(dialog, text="Apply", command=apply_changes).grid(row=6, column=0, sticky=tkinter.NW)
        def close():
            #self.root.deiconify()
            dialog.destroy()
        dialog.protocol("WM_DELETE_WINDOW", close)
        def open_tileset(primary):
            t = self.map.footer.tsp if primary else self.map.footer.tss
            options = {"filetypes" : [('python tileset files', '.pts')], "title" : "Load tileset", "parent" : dialog}
            if t and t.path: 
                options["initialdir"] = os.path.dirname(t.path)
            path = filedialog.askopenfilename(**options)
            if not path or not len(path): return
            try:
                t = tileset.from_file(path)
                if t.is_primary != primary: raise Exception("Wrong tileset type (tsp or tss)")
                if t.image.empty: raise Exception("Empty picture in tileset!")
                entry = entry_tsp if primary else entry_tss
                entry.delete(0, tkinter.END)
                entry.insert(0, t.path)
            except Exception as e:
                messagebox.showerror("Tileset error", "Unable to load tileset file: "+ str(e))
                return
        entry_tsp.bind("<Button-1>", lambda e: open_tileset(True)), entry_tss.bind("<Button-1>", lambda e: open_tileset(False))




class Action_border_change:
    """ Action class for border change """
    def __init__(self, root: Pymap_gui, x, y, blocks):
        self.root = root
        self.x0 = x
        self.y0 = y
        self.blocks = blocks
        dx, dy = root.block_selection_size
        self.last_blocks = _arrrange(root.block_selection, self.x0, self.y0, self.x0 + dy, self.y0 + dy)

    def do(self):
        _arrpaste(self.root.map.footer.borders, self.blocks, self.x0, self.y0)
        self.root._refresh_borders()

    def undo(self):
        _arrpaste(self.root.map.footer.borders, self.last_blocks, self.x0, self.y0)
        self.root._refresh_borders()
        



def _arrpaste(dst, src, x0, y0):
    """ Pastes src into dst at coordinates x0, y0 (where dst and src are defined)"""
    for y in range(min(y0, len(src), len(dst)), min(len(src), len(dst))):
        for x in range(min(x0, len(src[y]), len(dst[y])), min(len(src[y]), len(dst[y]))):
            dst[y][x] = src[y][x]

def _arrrange(src, x0, y0, x1, y1):
    """ Extracts an array range from source"""
    dst = [[-1 for x in range(x0, x1)] for y in range(y0, y1)]
    for y in range(y0, y1):
        if y in range(len(src)):
            for x in range(x0, x1):
                if x in range(len(src[y])):
                    dst[y - y0][x - x0] = src[y][x]
    return dst
    


def shell(args):
    """ Shell call for the gui """
    try:
        opts, args = getopt.getopt(args, "h", ["help"])
    except getopt.GetoptError:
        sys.exit(2)
    for opt, arg in opts:
        if opt in ("-h", "help"):
            print("Usage python pymap.py [mapfile]")
            return
    
    root = tkinter.Tk()
    root.wm_title("pymap")
    gui = Pymap_gui(root)
    if len(args):
        map = args[0]
        gui._load_map(map)
    
    root.mainloop()
    









