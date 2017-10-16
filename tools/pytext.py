import tkinter as tk
import pstring

CHARS_PER_LINE = 35

class Pytext_gui:
    
    def __init__(self, root):
        self.root = root

        self.input = tk.Text(root, width=35, height=6, wrap=tk.WORD)
        self.input.grid(sticky=tk.NSEW)
        self.bt_convert = tk.Button(root, text="Convert and to clipboard", command=self.convert)
        self.bt_convert.grid(sticky=tk.NSEW)
        self.output = tk.Entry(root)
        self.output.grid(sticky=tk.NSEW)
        


    def convert(self):
        output = convert(self.input.get(1.0, tk.END))
        self.output.delete(0, tk.END)
        self.output.insert(0, output)
        self.root.clipboard_clear()
        self.root.clipboard_append(output)

    
    
def convert(input):
    output = ""
    delim = "n"
    chars = 0
    i = 0
    for mapping in (("[player]", "\\b\\01"), ("[rival]", "\\b\\06")):
        input = input.replace(mapping[0], mapping[1])
    while i < len(input) - 1: #Last char is \n which is not converted
        c = input[i]
        if c == "\\":
            #take next char and buffers
            if input[i+1] != "b": raise Exception("Expected b after \ character")
            output += input[i:i+5]
            i += 5
            chars += 7
        elif c == "\n":
            output += "\\p"
            delim = "n"
            chars = 0
            i += 1
        else:
            output += c
            chars += 1
            i += 1
        if chars > 35:
            #Insert respective linebreak at last space
            j = 1
            while j < 35:
                #print(i, j)
                if output[i - j] == " ": break
                j += 1
            if j == 35: raise Exception("Word too long at end of " + output)
            #print("Parts are left:", output[0: i - j], "middle", output[i-j], "right", output[i - j + 1:])
            output = output[0 : i - j] + "\\" + delim + output[i - j + 1:]
            if delim == "n": delim = "l"
            chars = j - 1
    for mapping in (("ä", "\\$ae"), ("ö", "\\$oe"), ("ü", "\\$ue"), ("Ä", "\\$AE"), ("Ö", "\\$OE"), ("Ü", "$\\UE"), ("é", "\\e"), ("ß", "\\$s")):
        output = output.replace(mapping[0], mapping[1])
    return output


if __name__ == "__main__":
    root = tk.Tk()
    screen_width, screen_height = root.winfo_screenwidth(), root.winfo_screenheight()
    root.wm_title("pytext")
    gui = Pytext_gui(root)
    root.mainloop()