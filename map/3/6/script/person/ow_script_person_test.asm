.include "overworld_script.s"

.global ow_script_person_test

ow_script_person_test:
    callasm special_query_present_code
    waitstate
    release
    end