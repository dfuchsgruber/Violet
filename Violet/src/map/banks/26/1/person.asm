.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_12_clouds_person_1
.global ow_script_route_12_clouds_person_2

ow_script_route_12_clouds_person_1:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_route_12_clouds_person_2:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich liebe den Glanz der goldenen Brücken.\pWie wundervoll dieser Ort wohl zu seiner Blütezeit gewesen sein muss?"
str_1:
    .autostring 34 2 "Die Inschriften auf den Ruinen hier sprechen von einer Stadt, die man am Boden errichtet hatte und über die man das Himmelreich betreten konnteDOTS\pWas wohl aus dieser Stadt geworden ist?"
.elseif LANG_EN
str_0:
    .autostring 34 2 "I really adore the shimmer of the golden bridges.\pHow beautiful this place must have been during its prime?"
str_1:
    .autostring 34 2 "The inscriptions on the ruins here speak about a city that was built on the ground and which was used to reach the cloud realm from below.\pI wonder what happened to this cityDOTS"
.endif
