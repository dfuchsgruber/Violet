#include "types.h"
#include "text.h"
#include "language.h"

const u8 person_names[2][128][12] = {
    {   
        LANGDEP(PSTRING("August"), PSTRING("August")),
        LANGDEP(PSTRING("Achim"), PSTRING("Achim")),
        LANGDEP(PSTRING("Hugo"), PSTRING("Hugo")),
        LANGDEP(PSTRING("Hubert"), PSTRING("Hubert")),
        LANGDEP(PSTRING("Konrad"), PSTRING("Konrad")),
        LANGDEP(PSTRING("Olaf"), PSTRING("Olaf")),
        LANGDEP(PSTRING("Franz"), PSTRING("Franz")),
        LANGDEP(PSTRING("Willibald"), PSTRING("Willibald")),
        LANGDEP(PSTRING("Ernst"), PSTRING("Ernst")),
        LANGDEP(PSTRING("Edwin"), PSTRING("Edwin")),
        LANGDEP(PSTRING("Matthias"), PSTRING("Matthias")),
        LANGDEP(PSTRING("Christoph"), PSTRING("Christoph")),
        LANGDEP(PSTRING("Udo"), PSTRING("Udo")),
        LANGDEP(PSTRING("Robert"), PSTRING("Robert")),
        LANGDEP(PSTRING("Kurt"), PSTRING("Kurt")),
        LANGDEP(PSTRING("Reiner"), PSTRING("Reiner")),
        LANGDEP(PSTRING("Gerd"), PSTRING("Gerd")),
        LANGDEP(PSTRING("Leonhard"), PSTRING("Leonhard")),
        LANGDEP(PSTRING("Kunibert"), PSTRING("Kunibert")),
        LANGDEP(PSTRING("Roger"), PSTRING("Roger")),
        LANGDEP(PSTRING("Wolfram"), PSTRING("Wolfram")),
        LANGDEP(PSTRING("Gerald"), PSTRING("Gerald")),
        LANGDEP(PSTRING("Heinrich"), PSTRING("Heinrich")),
        LANGDEP(PSTRING("Rolf"), PSTRING("Rolf")),
        LANGDEP(PSTRING("Rudolf"), PSTRING("Rudolf")),
        LANGDEP(PSTRING("Hagen"), PSTRING("Hagen")),
        LANGDEP(PSTRING("Karsten"), PSTRING("Karsten")),
        LANGDEP(PSTRING("Sebastian"), PSTRING("Sebastian")),
        LANGDEP(PSTRING("Alfred"), PSTRING("Alfred")),
        LANGDEP(PSTRING("Oswin"), PSTRING("Oswin")),
        LANGDEP(PSTRING("Kaspar"), PSTRING("Kaspar")),
        LANGDEP(PSTRING("Heinz"), PSTRING("Heinz")),
        LANGDEP(PSTRING("Manfred"), PSTRING("Manfred")),
        LANGDEP(PSTRING("Georg"), PSTRING("Georg")),
        LANGDEP(PSTRING("Joachim"), PSTRING("Joachim")),
        LANGDEP(PSTRING("Johann"), PSTRING("Johann")),
        LANGDEP(PSTRING("Fritz"), PSTRING("Fritz")),
        LANGDEP(PSTRING("Volker"), PSTRING("Volker")),
        LANGDEP(PSTRING("Siegfried"), PSTRING("Siegfried")),
        LANGDEP(PSTRING("Reinhold"), PSTRING("Reinhold")),
        LANGDEP(PSTRING("Emil"), PSTRING("Emil")),
        LANGDEP(PSTRING("Philipp"), PSTRING("Philipp")),
        LANGDEP(PSTRING("Paul"), PSTRING("Paul")),
        LANGDEP(PSTRING("Hans"), PSTRING("Hans")),
        LANGDEP(PSTRING("Hermann"), PSTRING("Hermann")),
        LANGDEP(PSTRING("Roland"), PSTRING("Roland")),
        LANGDEP(PSTRING("Friedolin"), PSTRING("Friedolin")),
        LANGDEP(PSTRING("Erwin"), PSTRING("Erwin")),
        LANGDEP(PSTRING("Gregor"), PSTRING("Gregor")),
        LANGDEP(PSTRING("Ralf"), PSTRING("Ralf")),
        LANGDEP(PSTRING("Arnold"), PSTRING("Arnold")),
        LANGDEP(PSTRING("Erich"), PSTRING("Erich")),
        LANGDEP(PSTRING("Eduard"), PSTRING("Eduard")),
        LANGDEP(PSTRING("Theodor"), PSTRING("Theodor")),
        LANGDEP(PSTRING("Anton"), PSTRING("Anton")),
        LANGDEP(PSTRING("Hartwig"), PSTRING("Hartwig")),
        LANGDEP(PSTRING("Bernd"), PSTRING("Bernd")),
        LANGDEP(PSTRING("Gero"), PSTRING("Gero")),
        LANGDEP(PSTRING("Friedrich"), PSTRING("Friedrich")),
        LANGDEP(PSTRING("Albrecht"), PSTRING("Albrecht")),
        LANGDEP(PSTRING("Veit"), PSTRING("Veit")),
        LANGDEP(PSTRING("Harald"), PSTRING("Harald")),
        LANGDEP(PSTRING("Luitpold"), PSTRING("Luitpold")),
        LANGDEP(PSTRING("Jochen"), PSTRING("Jochen")),
        LANGDEP(PSTRING("Benedikt"), PSTRING("Benedikt")),
        LANGDEP(PSTRING("Richard"), PSTRING("Richard")),
        LANGDEP(PSTRING("Bodo"), PSTRING("Bodo")),
        LANGDEP(PSTRING("Ingo"), PSTRING("Ingo")),
        LANGDEP(PSTRING("Klaus"), PSTRING("Klaus")),
        LANGDEP(PSTRING("Jakob"), PSTRING("Jakob")),
        LANGDEP(PSTRING("Theo"), PSTRING("Theo")),
        LANGDEP(PSTRING("Edgar"), PSTRING("Edgar")),
        LANGDEP(PSTRING("Leopold"), PSTRING("Leopold")),
        LANGDEP(PSTRING("Timm"), PSTRING("Timm")),
        LANGDEP(PSTRING("Herbert"), PSTRING("Herbert")),
        LANGDEP(PSTRING("Wolfgang"), PSTRING("Wolfgang")),
        LANGDEP(PSTRING("Thomas"), PSTRING("Thomas")),
        LANGDEP(PSTRING("Oskar"), PSTRING("Oskar")),
        LANGDEP(PSTRING("Baldur"), PSTRING("Baldur")),
        LANGDEP(PSTRING("Benno"), PSTRING("Benno")),
        LANGDEP(PSTRING("Walter"), PSTRING("Walter")),
        LANGDEP(PSTRING("Edmund"), PSTRING("Edmund")),
        LANGDEP(PSTRING("Falko"), PSTRING("Falko")),
        LANGDEP(PSTRING("Knut"), PSTRING("Knut")),
        LANGDEP(PSTRING("Sepp"), PSTRING("Sepp")),
        LANGDEP(PSTRING("Kuno"), PSTRING("Kuno")),
        LANGDEP(PSTRING("Gottlieb"), PSTRING("Gottlieb")),
        LANGDEP(PSTRING("Gustav"), PSTRING("Gustav")),
        LANGDEP(PSTRING("Vinzenz"), PSTRING("Vinzenz")),
        LANGDEP(PSTRING("Willi"), PSTRING("Willi")),
        LANGDEP(PSTRING("Armin"), PSTRING("Armin")),
        LANGDEP(PSTRING("Rainer"), PSTRING("Rainer")),
        LANGDEP(PSTRING("Josef"), PSTRING("Josef")),
        LANGDEP(PSTRING("Peter"), PSTRING("Peter")),
        LANGDEP(PSTRING("Rupert"), PSTRING("Rupert")),
        LANGDEP(PSTRING("Waldemar"), PSTRING("Waldemar")),
        LANGDEP(PSTRING("Christian"), PSTRING("Christian")),
        LANGDEP(PSTRING("Guido"), PSTRING("Guido")),
        LANGDEP(PSTRING("Anselm"), PSTRING("Anselm")),
        LANGDEP(PSTRING("Viktor"), PSTRING("Viktor")),
        LANGDEP(PSTRING("Albert"), PSTRING("Albert")),
        LANGDEP(PSTRING("Max"), PSTRING("Max")),
        LANGDEP(PSTRING("Bernhard"), PSTRING("Bernhard")),
        LANGDEP(PSTRING("Alwin"), PSTRING("Alwin")),
        LANGDEP(PSTRING("Klemens"), PSTRING("Klemens")),
        LANGDEP(PSTRING("Falk"), PSTRING("Falk")),
        LANGDEP(PSTRING("Alexander"), PSTRING("Alexander")),
        LANGDEP(PSTRING("Wolf"), PSTRING("Wolf")),
        LANGDEP(PSTRING("Leo"), PSTRING("Leo")),
        LANGDEP(PSTRING("Ferdinand"), PSTRING("Ferdinand")),
        LANGDEP(PSTRING("Jörg"), PSTRING("Jörg")),
        LANGDEP(PSTRING("Lorenz"), PSTRING("Lorenz")),
        LANGDEP(PSTRING("Andreas"), PSTRING("Andreas")),
        LANGDEP(PSTRING("Artur"), PSTRING("Artur")),
        LANGDEP(PSTRING("Alfons"), PSTRING("Alfons")),
        LANGDEP(PSTRING("Julius"), PSTRING("Julius")),
        LANGDEP(PSTRING("Otto"), PSTRING("Otto")),
        LANGDEP(PSTRING("Norbert"), PSTRING("Norbert")),
        LANGDEP(PSTRING("Edward"), PSTRING("Edward")),
        LANGDEP(PSTRING("Wilfried"), PSTRING("Wilfried")),
        LANGDEP(PSTRING("Ewald"), PSTRING("Ewald")),
        LANGDEP(PSTRING("Martin"), PSTRING("Martin")),
        LANGDEP(PSTRING("Felix"), PSTRING("Felix")),
        LANGDEP(PSTRING("Karl"), PSTRING("Karl")),
        LANGDEP(PSTRING("Wilhelm"), PSTRING("Wilhelm")),
        LANGDEP(PSTRING("Johannes"), PSTRING("Johannes")),
        LANGDEP(PSTRING("Immanuel"), PSTRING("Immanuel")),
    },{
        LANGDEP(PSTRING("Heiderose"), PSTRING("Heiderose")),
        LANGDEP(PSTRING("Annekristin"), PSTRING("Annekristin")),
        LANGDEP(PSTRING("Friedlind"), PSTRING("Friedlind")),
        LANGDEP(PSTRING("Heidrun"), PSTRING("Heidrun")),
        LANGDEP(PSTRING("Inka"), PSTRING("Inka")),
        LANGDEP(PSTRING("Clarissa"), PSTRING("Clarissa")),
        LANGDEP(PSTRING("Heidelies"), PSTRING("Heidelies")),
        LANGDEP(PSTRING("Fine"), PSTRING("Fine")),
        LANGDEP(PSTRING("Thea"), PSTRING("Thea")),
        LANGDEP(PSTRING("Gerdhild"), PSTRING("Gerdhild")),
        LANGDEP(PSTRING("Klothildis"), PSTRING("Klothildis")),
        LANGDEP(PSTRING("Margrit"), PSTRING("Margrit")),
        LANGDEP(PSTRING("Diethilde"), PSTRING("Diethilde")),
        LANGDEP(PSTRING("Hannah"), PSTRING("Hannah")),
        LANGDEP(PSTRING("Nadja"), PSTRING("Nadja")),
        LANGDEP(PSTRING("Petra"), PSTRING("Petra")),
        LANGDEP(PSTRING("Irmelin"), PSTRING("Irmelin")),
        LANGDEP(PSTRING("Gaby"), PSTRING("Gaby")),
        LANGDEP(PSTRING("Leni"), PSTRING("Leni")),
        LANGDEP(PSTRING("Annarose"), PSTRING("Annarose")),
        LANGDEP(PSTRING("Regine"), PSTRING("Regine")),
        LANGDEP(PSTRING("Sylke"), PSTRING("Sylke")),
        LANGDEP(PSTRING("Elfriede"), PSTRING("Elfriede")),
        LANGDEP(PSTRING("Betty"), PSTRING("Betty")),
        LANGDEP(PSTRING("Klementine"), PSTRING("Klementine")),
        LANGDEP(PSTRING("Debora"), PSTRING("Debora")),
        LANGDEP(PSTRING("Heidelind"), PSTRING("Heidelind")),
        LANGDEP(PSTRING("Clementine"), PSTRING("Clementine")),
        LANGDEP(PSTRING("Annemirl"), PSTRING("Annemirl")),
        LANGDEP(PSTRING("Juliane"), PSTRING("Juliane")),
        LANGDEP(PSTRING("Annetrud"), PSTRING("Annetrud")),
        LANGDEP(PSTRING("Dora"), PSTRING("Dora")),
        LANGDEP(PSTRING("Reintraud"), PSTRING("Reintraud")),
        LANGDEP(PSTRING("Felicitas"), PSTRING("Felicitas")),
        LANGDEP(PSTRING("Rauthgundis"), PSTRING("Rauthgundis")),
        LANGDEP(PSTRING("Waltrudis"), PSTRING("Waltrudis")),
        LANGDEP(PSTRING("Simone"), PSTRING("Simone")),
        LANGDEP(PSTRING("Sylvia"), PSTRING("Sylvia")),
        LANGDEP(PSTRING("Heidelinde"), PSTRING("Heidelinde")),
        LANGDEP(PSTRING("Ulrike"), PSTRING("Ulrike")),
        LANGDEP(PSTRING("Katrin"), PSTRING("Katrin")),
        LANGDEP(PSTRING("Heliane"), PSTRING("Heliane")),
        LANGDEP(PSTRING("Gudula"), PSTRING("Gudula")),
        LANGDEP(PSTRING("Karolina"), PSTRING("Karolina")),
        LANGDEP(PSTRING("Gudrun"), PSTRING("Gudrun")),
        LANGDEP(PSTRING("Marilu"), PSTRING("Marilu")),
        LANGDEP(PSTRING("Utta"), PSTRING("Utta")),
        LANGDEP(PSTRING("Edeltrud"), PSTRING("Edeltrud")),
        LANGDEP(PSTRING("Wilma"), PSTRING("Wilma")),
        LANGDEP(PSTRING("Luisa"), PSTRING("Luisa")),
        LANGDEP(PSTRING("Malwine"), PSTRING("Malwine")),
        LANGDEP(PSTRING("Camilla"), PSTRING("Camilla")),
        LANGDEP(PSTRING("Friedlinde"), PSTRING("Friedlinde")),
        LANGDEP(PSTRING("Karina"), PSTRING("Karina")),
        LANGDEP(PSTRING("Franziska"), PSTRING("Franziska")),
        LANGDEP(PSTRING("Dorit"), PSTRING("Dorit")),
        LANGDEP(PSTRING("Ivonne"), PSTRING("Ivonne")),
        LANGDEP(PSTRING("Ishild"), PSTRING("Ishild")),
        LANGDEP(PSTRING("Marielies"), PSTRING("Marielies")),
        LANGDEP(PSTRING("Karin"), PSTRING("Karin")),
        LANGDEP(PSTRING("Rena"), PSTRING("Rena")),
        LANGDEP(PSTRING("Edith"), PSTRING("Edith")),
        LANGDEP(PSTRING("Agnes"), PSTRING("Agnes")),
        LANGDEP(PSTRING("Alwine"), PSTRING("Alwine")),
        LANGDEP(PSTRING("Hermine"), PSTRING("Hermine")),
        LANGDEP(PSTRING("Corina"), PSTRING("Corina")),
        LANGDEP(PSTRING("Evelyn"), PSTRING("Evelyn")),
        LANGDEP(PSTRING("Dore"), PSTRING("Dore")),
        LANGDEP(PSTRING("Thurid"), PSTRING("Thurid")),
        LANGDEP(PSTRING("Leonie"), PSTRING("Leonie")),
        LANGDEP(PSTRING("Anneliese"), PSTRING("Anneliese")),
        LANGDEP(PSTRING("Richardis"), PSTRING("Richardis")),
        LANGDEP(PSTRING("Burghilde"), PSTRING("Burghilde")),
        LANGDEP(PSTRING("Elfrun"), PSTRING("Elfrun")),
        LANGDEP(PSTRING("Edeltraud"), PSTRING("Edeltraud")),
        LANGDEP(PSTRING("Jeannine"), PSTRING("Jeannine")),
        LANGDEP(PSTRING("Swanhild"), PSTRING("Swanhild")),
        LANGDEP(PSTRING("Verena"), PSTRING("Verena")),
        LANGDEP(PSTRING("Gottholde"), PSTRING("Gottholde")),
        LANGDEP(PSTRING("Nordrun"), PSTRING("Nordrun")),
        LANGDEP(PSTRING("Liselotte"), PSTRING("Liselotte")),
        LANGDEP(PSTRING("Burga"), PSTRING("Burga")),
        LANGDEP(PSTRING("Rommy"), PSTRING("Rommy")),
        LANGDEP(PSTRING("Kläre"), PSTRING("Kläre")),
        LANGDEP(PSTRING("Angelina"), PSTRING("Angelina")),
        LANGDEP(PSTRING("Gerburg"), PSTRING("Gerburg")),
        LANGDEP(PSTRING("Hiltrun"), PSTRING("Hiltrun")),
        LANGDEP(PSTRING("Heidegunde"), PSTRING("Heidegunde")),
        LANGDEP(PSTRING("Erdmuthe"), PSTRING("Erdmuthe")),
        LANGDEP(PSTRING("Alexa"), PSTRING("Alexa")),
        LANGDEP(PSTRING("Edwina"), PSTRING("Edwina")),
        LANGDEP(PSTRING("Rosehilde"), PSTRING("Rosehilde")),
        LANGDEP(PSTRING("Kathrein"), PSTRING("Kathrein")),
        LANGDEP(PSTRING("Josepha"), PSTRING("Josepha")),
        LANGDEP(PSTRING("Ursulina"), PSTRING("Ursulina")),
        LANGDEP(PSTRING("Almute"), PSTRING("Almute")),
        LANGDEP(PSTRING("Karen"), PSTRING("Karen")),
        LANGDEP(PSTRING("Katie"), PSTRING("Katie")),
        LANGDEP(PSTRING("Jenny"), PSTRING("Jenny")),
        LANGDEP(PSTRING("Ellentraud"), PSTRING("Ellentraud")),
        LANGDEP(PSTRING("Amalia"), PSTRING("Amalia")),
        LANGDEP(PSTRING("Theodeline"), PSTRING("Theodeline")),
        LANGDEP(PSTRING("Waltrud"), PSTRING("Waltrud")),
        LANGDEP(PSTRING("Martina"), PSTRING("Martina")),
        LANGDEP(PSTRING("Helgard"), PSTRING("Helgard")),
        LANGDEP(PSTRING("Filippina"), PSTRING("Filippina")),
        LANGDEP(PSTRING("Beatrix"), PSTRING("Beatrix")),
        LANGDEP(PSTRING("Birgitt"), PSTRING("Birgitt")),
        LANGDEP(PSTRING("Elise"), PSTRING("Elise")),
        LANGDEP(PSTRING("Ewalda"), PSTRING("Ewalda")),
        LANGDEP(PSTRING("Ferdinande"), PSTRING("Ferdinande")),
        LANGDEP(PSTRING("Friedoline"), PSTRING("Friedoline")),
        LANGDEP(PSTRING("Marlitt"), PSTRING("Marlitt")),
        LANGDEP(PSTRING("Susanne"), PSTRING("Susanne")),
        LANGDEP(PSTRING("Marietheres"), PSTRING("Marietheres")),
        LANGDEP(PSTRING("Annerose"), PSTRING("Annerose")),
        LANGDEP(PSTRING("Sarah"), PSTRING("Sarah")),
        LANGDEP(PSTRING("Richarda"), PSTRING("Richarda")),
        LANGDEP(PSTRING("Heideline"), PSTRING("Heideline")),
        LANGDEP(PSTRING("Rosa"), PSTRING("Rosa")),
        LANGDEP(PSTRING("Hildburga"), PSTRING("Hildburga")),
        LANGDEP(PSTRING("Agatha"), PSTRING("Agatha")),
        LANGDEP(PSTRING("Steffie"), PSTRING("Steffie")),
        LANGDEP(PSTRING("Elfie"), PSTRING("Elfie")),
        LANGDEP(PSTRING("Mechthilde"), PSTRING("Mechthilde")),
        LANGDEP(PSTRING("Hildburg"), PSTRING("Hildburg")),
        LANGDEP(PSTRING("Agnieszka"), PSTRING("Agnieszka")),
        LANGDEP(PSTRING("Isolde"), PSTRING("Isolde")),
    }
};