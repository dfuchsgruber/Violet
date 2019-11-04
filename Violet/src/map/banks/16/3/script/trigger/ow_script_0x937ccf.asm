.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"

// Removed this script, trigger remains for var consistency among versions

.global ow_script_0x937ccf
ow_script_0x937ccf:
addvar STORY_PROGRESS 1
end


