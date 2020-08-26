.include "overworld_script.s"
.include "callstds.s"

.global ow_script_bruchfels_crypt_grandma

ow_script_bruchfels_crypt_grandma:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hier liegt Roman, der ehemalige Arenaleiter von Bruchfels, begraben.\pEr hat sein eigenes Leben gegeben, um diese Stadt vor Unheil zu beschützen.\pNach Romans Tod hat sein Sohn Lester die Arena übernommen.\pAber seitdem sein Vater gestorben war, ist Lester nicht mehr der selbe gewesen.\pEr hat mit bloßen Händen diese Krypta ausgehoben und seinen Vater hier bestattet.\pIn tiefe Verzweiflung gestürzt, weigert er sich bis heute, Bruchfels wieder aufzubauen.\pIch mag mir nur schwer vorstellen, was in diesem armen Jungen vor sich geht.\pEs muss schwer für ihn sein, diese Stadt zu beschützen, wo sie ihm doch den eigenen Vater genommen hatDOTS "
.elseif LANG_EN
.endif