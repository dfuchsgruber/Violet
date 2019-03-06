.macro frame frameid
.hword \frameid
.endm

.equ COPYSET, 1
.equ COPYMAP, 2

.equ COPY, 0
.equ UNCOMP, 1

.macro endframe
.byte 0xFF
.endm

@ends script (return on subscripts)
.macro end
.byte 0
.endm

@continues at subscript with frame = startframe
.macro call subscript startframe
.byte 1
.word \subscript
.hword \startframe
.endm

@continues at another offset with frame = startframe
.macro jump script startframe
.byte 2
.word \script
.hword \startframe
.endm


@Creates a new oam by template
@template := oam template ptr
@x := s16 x coordinate of center
@y := s16 y coordinate of center
@unkown := byte unkown membere
@target_var := local ae_variable to store oam_id
.macro oam_new template x y unkown target_var
.byte 0x3
.word \template
.hword \x
.hword \y
.byte \unkown
.hword \target_var
.endm

@Loads and allocates lz77 for objvram and a graphic structre
.macro obj_vram_load graphic
.byte 0x5
.word \graphic
.endm

@Despawns an oam
.macro oam_despawn target_var:req
.byte 0x7
.hword \target_var
.endm

@spawns a big callback
.macro spawn_big_cb func prio init_data_hword_cnt
.byte 0x8
.word \func
.byte \prio
.byte \init_data_hword_cnt
.endm

@append max 16 .hword XXX to the command (the cnt must equal the init_data_hword_cnt)
@these hwords are copied into callback.params[n], copying the first one to n = 0


@resets bgs
.macro bg_reset unkown
.byte 9
.byte \unkown
.endm

@performs bg setups with list to confgs
.macro bg_setup tilemode cnfglist cnfgcount
.byte 0xA
.byte \tilemode
.word \cnfglist
.byte \cnfgcount
.endm

@syncs bg with its display configuratons (e.g. by bg_setup)
.macro bg_sync_and_show bgid
.byte 0xB
.byte \bgid
.endm

@syncs bgcntrl with all bgs display configurations
.macro bg_sync
.byte 0xd
.endm

@overrides bg tileset or tilemap on a certain bg
@source := data source comp
@size := uncompressed data size
@start := start tile on bg
@mode := SET(1) or MAP(2)
.macro bg_override id source size start mode
.byte 0xE
.byte \id
.word \source
.hword \size
.hword \start
.byte \mode
.endm


@loads obj palette
@tag := pal tag
@pal := ptr to pal src
@mode := mode (0=copy, 1=lz77uncomp)
@force := 0=to_restore_only, 1=force_to_palram_immideatly
.macro load_obj_pal tag pal mode force
.byte 0xF
.hword \tag
.word \pal
.byte \mode
.byte \force
.endm

@sets io to a value
.macro set_io_to_val val io
.byte 0x13
.hword \val
.hword \io
.endm


@prepeares a textbuffer
@target var := target variable to store textbox buffer id in
@x,y,w,h := boundaries of textbox (in 8x8 tiles)
@palid := pal id to be used by text
@desttile := destination tile to bgs own charset
.macro text_init target_var bgid x y w h palid desttile
.byte 0x14
.hword \target_var
.byte \bgid
.byte \x
.byte \y
.byte \w
.byte \h
.byte \palid
.hword \desttile
.endm

.macro display_text tbid font unkown bdistance ldistanceu ldistancel fontmap display text bgid
.byte 0x15
.hword \tbid
.byte \font
.byte \unkown
.byte \bdistance
.byte \ldistanceu
.byte \ldistancel
.word \fontmap
.byte \display
.word \text
.byte \bgid
.endm


@macro to clear a tbox
@boxid := tbox to clear, textbox buffer to 
.macro text_clear boxid
.byte 0x16
.hword \boxid
.endm

@macro to provide a font map for text display
@background, body, border: color ids of component in tbs given pal
.macro fontmap background body border
.byte \background
.byte \body
.byte \border
.byte 0
.endm

.equ DISPLAYALL, 0
.equ LOADONLY, 0xFF

@displays rendered text
@target var := var to hold renderer id
@tbid := textbox buffer id (e.g. by cmd "text_init"), can be read from var
@speed := frames / char
@font := font id
@unkown := ?
@bdistance := distance of text to box borders (in px)
@ldistance{u/l} := line distance from text to upper(u)/lower(l) line
@fontmap := pointer to fontmap
@display := 0:=displayall, 0xFF:=loadonly
@text := pointer to text
@bgid := bg to display text on
@initial_flags := initial flag field (Event-id is bitindex of field)
.macro text_render target_var tbid speed font unkown bdistance ldistanceu ldistancel fontmap display text bgid initial_flags
.byte 0x17
.hword \target_var
.hword \tbid
.byte \speed
.byte \font
.byte \unkown
.byte \bdistance
.byte \ldistanceu
.byte \ldistancel
.word \fontmap
.byte \display
.word \text
.byte \bgid
.byte \initial_flags
.endm

.equ EVENT_LINEBREAK, 0
.equ EVENT_PARAGRAPH, 1
.equ EVENT_ENDTEXT, 2
.equ EVENT_PASS_ALL_LINEBREAK, 4
.equ EVENT_PASS_ALL_PARAGRAPH, 5
.equ EVENT_PASS_ALL_ENDTEXT, 6

@notifies the textrenderer with an event
@targetrenderer := target rednerer callback id (can be read form var (suggested))
@event := the text event to allow
.macro text_event targetrenderer event
.byte 0x18
.hword \targetrenderer
.byte \event
.endm

.equ RESTORE, 0
.equ FORCE, 1

@oam_move
@target := oam id (or var that holds oam id) to move
@duration := duration in frames (0 = instantly)
@dx := total x movement
@dy := total y movement
.macro oam_move target:req duration:req dx:req dy:req
.byte 0x19
.hword \target
.hword \duration
.hword \dx
.hword \dy
.endm


@callasm
.macro callasm func param_cnt
.byte 0x1A
.word \func
.byte \param_cnt
.endm

@loads a palette
.macro loadpal source dest count copy force
.byte 0x1D
.word \source
.hword \dest
.hword \count
.byte \copy
.byte \force
.endm

@fades colors
@target := the overlay color to fade into
@first := first color to be faded
@count := colors to be faded
@duration := duration in frames for fading process (0 := imideately)
@from := base intensity to start
@to := intensity to be at end of fading
.macro fadescreen target first count duration from to
.byte 0x1E
.hword \target
.hword \first
.hword \count
.hword \duration
.byte \from
.byte \to
.endm

@plays sound
.macro sound soundid
.byte 0x20
.hword \soundid
.endm

@plays song
.macro song songid modulation
.byte 0x21
.hword \songid
.byte \modulation
.endm

@plays cry
.macro cry cryid modulation
.byte 0x22
.hword \cryid
.byte \modulation
.endm

@sets a simply maintenance callback as callback1
.macro maintain
.byte 0x23
.endm

@releases a scripts waitstate
.macro script_notify
.byte 0x24
.endm

@resets all oams
.macro oam_reset
.byte 0x25
.endm

@resets all big_callbacks
.macro callback_reset
.byte 0x26
.endm

@resets dma3
.macro dma3_reset
.byte 0x27
.endm

@resets bgscroll
.macro bg_disp_reset
.byte 0x28
.endm

@inits a new vmap for a bg
.macro bg_vmap_init bgid size
.byte 0x29
.byte \bgid
.hword \size
.endm

@drops a vmap for a bg (by freeing and nullfying)
.macro bg_vmap_drop bgid
.byte 0x2A
.byte \bgid
.endm

@bg scroll animation (deltas are the full deltas over all frames)
@deltas are calculated precisly, meaning after duration exactly hdelta
@and vdelta will be scrolled
.macro bg_scroll bgid duration hdelta vdelta
.byte 0x2B
.byte \bgid
.hword \duration
.hword \hdelta
.hword \vdelta
.endm

@mapreload
.macro mapreload
.byte 0x2C
.endm

@force pals to black
.macro force_pals_to_black
.byte 0x2D
.endm

@set a var to a value
.macro setvar var val
.byte 0x2F
.hword \var
.hword \val
.endm

@clear the vmap for a bg
.macro bg_clear_map id size
.byte 0x2E
.byte \id
.hword \size
.endm

@fadescreen for obj pal (by tag)
@target := the overlay color to fade into
@tag := the pal tag of the obj pal to fade
@first := first color relative to obj pal
@number := number of cols to fade
@duration := duration in frames for fading process (0 := imideately)
@from := base intensity to start
@to := intensity to be at end of fading
.macro fade_obj_pal color:req tag:req first:req number:req duration:req from:req to:req
.byte 0x30
.hword \color
.hword \tag
.byte \first
.byte \number
.hword \duration
.byte \from
.byte \to
.endm

@flushes a textbox
@target := boxid (or var that holds box id)
@flush := [first pixel] | [second pixel] >> 4
.macro tbox_flush target:req flush:req
.byte 0x31
.hword \target
.byte \flush
.endm

@forces the pal restore to the values that are currently visible
@first := first color to force
@count := number of colors to force relative to first
.macro pal_restore_force_current first count
.byte 0x32
.hword \first
.hword \count
.endm

.macro jump_if_female target:req startframe:req
.byte 0x33
.word \target
.hword \startframe
.endm

@0:= clearflag, <>0 := setflag
.macro setflag flag:req value:req
.byte 0x34
.hword \flag
.byte \value
.endm

@0: load from save, <>0 := push to save
.macro pal_restore_snapshot mode:req
.byte 0x35
.byte \mode
.endm

@loads obj palette
@pal := ptr to pal struct
@mode := mode (0=copy, 1=lz77uncomp)
@force := 0=to_restore_only, 1=force_to_palram_immideatly
.macro load_obj_pal_from_struct pal:req mode:req force:req
.byte 0x36
.word \pal
.byte \mode
.byte \force
.endm


@moves an object according to a function trace
@oam_id := oam id (or var) to oam
@duration := duration in frames (note that 0 is not always supported and usually provides edge cases)
@trace := id of the trace of the function that the oam will be moved according to
@... dependent on the traces additional parameters follow
.macro oam_move_trace oam_id:req duration:req trace:req
.byte 0x37
.hword \oam_id
.hword \duration
.byte \trace
.endm

.equ XAXIS, 0
.equ YAXIS, 1

.equ SINE, 0
.equ COSINE, 1
.equ TANGENS, 2
@Move oam along y axis on a trigonometric trace
@requires:
@   on_y_axis : byte
@   amplitude : hword
@   period : hword

.equ LSINE, 3
.equ LCOSINE, 4
.equ LTANGENS, 5
@Move oam along y axis on a trigonmetric trace whereas all areas are approximated by linear functions (edgy)
@requires:
@   on_y_axis : byte
@   amplitude : hword
@   period : hword

.equ LINEAR, 6
@Move along linear axis (equivalent to obj_move command)
@requires:
@   delta x : hword
@   delta y : hword


@field for bg setup
.macro bg_setup_cnfg id charbase mapbase size colmode priority
.word \id | (\charbase << 2) | (\mapbase << 4) | (\size << 9) | (\colmode << 11) | (\priority << 12)
.endm
