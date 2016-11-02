#include "types.h"
#include "pokedex.h"

pokedex_data dex_data[POKEDEX_CNT + 1] = {
    {
        {0xcf, 0xc8, 0xbc, 0xbf, 0xc5, 0xbb, 0xc8, 0xc8, 0xce, 0xff, 0x0, 0x0}, //category
        0, //height
        0, //weight
        (u8*) 0x8444b7d, //page0
        (u8*) 0x8444c0c, //page1
        0, //unused
        256, //poke scale
        0, //poke displace
        256, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbb, 0xc7, 0xbf, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        7, //height
        69, //weight
        (u8*) 0x8444c0d, //page0
        (u8*) 0x8444c62, //page1
        0, //unused
        356, //poke scale
        16, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbb, 0xc7, 0xbf, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        130, //weight
        (u8*) 0x8444c63, //page0
        (u8*) 0x8444cdb, //page1
        0, //unused
        332, //poke scale
        11, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbb, 0xc7, 0xbf, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        20, //height
        1000, //weight
        (u8*) 0x8444cdc, //page0
        (u8*) 0x8444d2c, //page1
        0, //unused
        256, //poke scale
        1, //poke displace
        375, //trainer scale
        6, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xbd, 0xc2, 0xcd, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        85, //weight
        (u8*) 0x8444d2d, //page0
        (u8*) 0x8444d9c, //page1
        0, //unused
        410, //poke scale
        16, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc6, 0xbb, 0xc7, 0xc7, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        11, //height
        190, //weight
        (u8*) 0x8444d9d, //page0
        (u8*) 0x8444e19, //page1
        0, //unused
        294, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc6, 0xbb, 0xc7, 0xc7, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        17, //height
        905, //weight
        (u8*) 0x8444e1a, //page0
        (u8*) 0x8444e8d, //page1
        0, //unused
        271, //poke scale
        0, //poke displace
        317, //trainer scale
        3, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xc3, 0xc8, 0xc3, 0xc5, 0xcc, 0xf2, 0xce, 0xbf, 0xff, 0x0, 0x0}, //category
        5, //height
        90, //weight
        (u8*) 0x8444e8e, //page0
        (u8*) 0x8444eef, //page1
        0, //unused
        412, //poke scale
        16, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xcc, 0xf2, 0xce, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        225, //weight
        (u8*) 0x8444ef0, //page0
        (u8*) 0x8444f66, //page1
        0, //unused
        334, //poke scale
        9, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xbb, 0xc8, 0xd4, 0xbf, 0xcc, 0xce, 0xc3, 0xbf, 0xcc, 0xff, 0x0}, //category
        16, //height
        855, //weight
        (u8*) 0x8444f67, //page0
        (u8*) 0x8444ff5, //page1
        0, //unused
        256, //poke scale
        1, //poke displace
        329, //trainer scale
        3, //trainer displace
        0 //unused 2
    },
    {
        {0xcc, 0xc9, 0xce, 0xc5, 0xbf, 0xc2, 0xc6, 0xbd, 0xc2, 0xbf, 0xc8, 0xff}, //category
        3, //height
        29, //weight
        (u8*) 0x88d0631, //page0
        (u8*) 0x8445052, //page1
        0, //unused
        549, //poke scale
        20, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xe9, 0xe2, 0xdf, 0xd9, 0xe2, 0xe6, 0xd9, 0xdb, 0xd9, 0xe2, 0xff}, //category
        7, //height
        160, //weight
        (u8*) 0x88d0737, //page0
        (u8*) 0x84450ba, //page1
        0, //unused
        350, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xe8, 0xdd, 0xd7, 0xdc, 0xda, 0xe0, 0xd5, 0xe1, 0xe1, 0xd9, 0xff}, //category
        12, //height
        320, //weight
        (u8*) 0x88d07cb, //page0
        (u8*) 0x8445127, //page1
        0, //unused
        312, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcc, 0xbb, 0xcf, 0xca, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        3, //height
        32, //weight
        (u8*) 0x8445128, //page0
        (u8*) 0x84451a2, //page1
        0, //unused
        455, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc9, 0xc5, 0xc9, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        100, //weight
        (u8*) 0x84451a3, //page0
        (u8*) 0x8445223, //page1
        0, //unused
        424, //poke scale
        14, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xdd, 0xda, 0xe8, 0xbc, 0xc3, 0xbf, 0xc8, 0xbf, 0xff, 0x0, 0x0}, //category
        10, //height
        295, //weight
        (u8*) 0x8445224, //page0
        (u8*) 0x844529d, //page1
        0, //unused
        366, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xce, 0xbb, 0xcc, 0xff, 0xd0, 0xc9, 0xc1, 0xbf, 0xc6, 0xff, 0x0}, //category
        3, //height
        18, //weight
        (u8*) 0x844529e, //page0
        (u8*) 0x8445320, //page1
        0, //unused
        492, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xce, 0xbb, 0xcc, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        11, //height
        300, //weight
        (u8*) 0x8445321, //page0
        (u8*) 0x8445396, //page1
        0, //unused
        334, //poke scale
        11, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xce, 0xbb, 0xcc, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        15, //height
        395, //weight
        (u8*) 0x8445397, //page0
        (u8*) 0x844540e, //page1
        0, //unused
        269, //poke scale
        65534, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xe6, 0xe3, 0xe2, 0xee, 0xd9, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        3, //height
        35, //weight
        (u8*) 0x88d083f, //page0
        (u8*) 0x844547a, //page1
        0, //unused
        481, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xe6, 0xe3, 0xe2, 0xee, 0xd9, 0xdb, 0xe0, 0xe3, 0xd7, 0xdf, 0xff}, //category
        7, //height
        185, //weight
        (u8*) 0x88d088f, //page0
        (u8*) 0x84454f0, //page1
        0, //unused
        401, //poke scale
        14, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcc, 0xdd, 0xe8, 0xe8, 0xff, 0xd0, 0xc9, 0xc1, 0xbf, 0xc6, 0xff, 0x0}, //category
        3, //height
        20, //weight
        (u8*) 0x88d23cc, //page0
        (u8*) 0x844556a, //page1
        0, //unused
        571, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcc, 0xdd, 0xe8, 0xe8, 0xff, 0xc9, 0xc1, 0xbf, 0xc6, 0xff, 0x0, 0x0}, //category
        12, //height
        380, //weight
        (u8*) 0x88d2442, //page0
        (u8*) 0x84455e3, //page1
        0, //unused
        282, //poke scale
        65535, //poke displace
        272, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xd5, 0xe9, 0xe1, 0xe7, 0xe8, 0xe9, 0xe1, 0xe4, 0xda, 0xff, 0x0}, //category
        20, //height
        69, //weight
        (u8*) 0x88d266d, //page0
        (u8*) 0x8445678, //page1
        0, //unused
        298, //poke scale
        13, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcf, 0xe6, 0xdb, 0xd9, 0xdc, 0xf5, 0xe0, 0xee, 0xff, 0x0, 0x0, 0x0}, //category
        35, //height
        650, //weight
        (u8*) 0x88d25ef, //page0
        (u8*) 0x84456df, //page1
        0, //unused
        256, //poke scale
        0, //poke displace
        296, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbb, 0xe9, 0xe7, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        60, //weight
        (u8*) 0x84456e0, //page0
        (u8*) 0x844573b, //page1
        0, //unused
        479, //poke scale
        16, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbb, 0xe9, 0xe7, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        8, //height
        300, //weight
        (u8*) 0x844573c, //page0
        (u8*) 0x84457d2, //page1
        0, //unused
        426, //poke scale
        10, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbb, 0xe9, 0xe7, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        120, //weight
        (u8*) 0x84457d3, //page0
        (u8*) 0x844582e, //page1
        0, //unused
        370, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbb, 0xe9, 0xe7, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        295, //weight
        (u8*) 0x844582f, //page0
        (u8*) 0x844589f, //page1
        0, //unused
        341, //poke scale
        10, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xdd, 0xda, 0xe8, 0xbe, 0xc9, 0xcc, 0xc8, 0xff, 0x0, 0x0, 0x0}, //category
        4, //height
        70, //weight
        (u8*) 0x84458a0, //page0
        (u8*) 0x8445920, //page1
        0, //unused
        488, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xdd, 0xda, 0xe8, 0xbe, 0xc9, 0xcc, 0xc8, 0xff, 0x0, 0x0, 0x0}, //category
        8, //height
        200, //weight
        (u8*) 0x8445921, //page0
        (u8*) 0x8445995, //page1
        0, //unused
        381, //poke scale
        13, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xc9, 0xc2, 0xcc, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        13, //height
        600, //weight
        (u8*) 0x8445996, //page0
        (u8*) 0x8445a05, //page1
        0, //unused
        283, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xdd, 0xda, 0xe8, 0xbe, 0xc9, 0xcc, 0xc8, 0xff, 0x0, 0x0, 0x0}, //category
        5, //height
        90, //weight
        (u8*) 0x8445a06, //page0
        (u8*) 0x8445a91, //page1
        0, //unused
        480, //poke scale
        17, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xdd, 0xda, 0xe8, 0xbe, 0xc9, 0xcc, 0xc8, 0xff, 0x0, 0x0, 0x0}, //category
        9, //height
        195, //weight
        (u8*) 0x8445a92, //page0
        (u8*) 0x8445b07, //page1
        0, //unused
        408, //poke scale
        13, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xc9, 0xc2, 0xcc, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        14, //height
        620, //weight
        (u8*) 0x8445b08, //page0
        (u8*) 0x8445b7f, //page1
        0, //unused
        304, //poke scale
        3, //poke displace
        323, //trainer scale
        2, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xdd, 0xe2, 0xd6, 0xe0, 0xf6, 0xe8, 0xe0, 0xd9, 0xe6, 0xff, 0x0}, //category
        6, //height
        75, //weight
        (u8*) 0x88d26ff, //page0
        (u8*) 0x8445bf2, //page1
        0, //unused
        425, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xd5, 0xe6, 0xe8, 0xd9, 0xe2, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        13, //height
        400, //weight
        (u8*) 0x88d2780, //page0
        (u8*) 0x8445c65, //page1
        0, //unused
        256, //poke scale
        3, //poke displace
        272, //trainer scale
        65535, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xcf, 0xbd, 0xc2, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        99, //weight
        (u8*) 0x8445c66, //page0
        (u8*) 0x8445cd8, //page1
        0, //unused
        497, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xcf, 0xbd, 0xc2, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        11, //height
        199, //weight
        (u8*) 0x8445cd9, //page0
        (u8*) 0x8445d3a, //page1
        0, //unused
        339, //poke scale
        6, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xbb, 0xc6, 0xc6, 0xc9, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        5, //height
        55, //weight
        (u8*) 0x8445d3b, //page0
        (u8*) 0x8445db6, //page1
        0, //unused
        419, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xbb, 0xc6, 0xc6, 0xc9, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        120, //weight
        (u8*) 0x8445db7, //page0
        (u8*) 0x8445e2a, //page1
        0, //unused
        328, //poke scale
        9, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc6, 0xbf, 0xbe, 0xbf, 0xcc, 0xc7, 0xbb, 0xe9, 0xe7, 0xff, 0x0}, //category
        8, //height
        75, //weight
        (u8*) 0x8445e2b, //page0
        (u8*) 0x8445e9b, //page1
        0, //unused
        355, //poke scale
        65532, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc6, 0xbf, 0xbe, 0xbf, 0xcc, 0xc7, 0xbb, 0xe9, 0xe7, 0xff, 0x0}, //category
        16, //height
        550, //weight
        (u8*) 0x8445e9c, //page0
        (u8*) 0x8445f19, //page1
        0, //unused
        291, //poke scale
        0, //poke displace
        296, //trainer scale
        2, //trainer displace
        0 //unused 2
    },
    {
        {0xcf, 0xc8, 0xc5, 0xcc, 0xbb, 0xcf, 0xce, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        5, //height
        54, //weight
        (u8*) 0x8445f1a, //page0
        (u8*) 0x8445f96, //page1
        0, //unused
        423, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcf, 0xc8, 0xc5, 0xcc, 0xbb, 0xcf, 0xce, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        8, //height
        86, //weight
        (u8*) 0x8445f97, //page0
        (u8*) 0x8446023, //page1
        0, //unused
        329, //poke scale
        10, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xc6, 0xcf, 0xc7, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        12, //height
        186, //weight
        (u8*) 0x8446024, //page0
        (u8*) 0x84460a2, //page1
        0, //unused
        256, //poke scale
        4, //poke displace
        272, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcf, 0xe2, 0xe6, 0xd9, 0xdd, 0xda, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        3, //height
        54, //weight
        (u8*) 0x88d2806, //page0
        (u8*) 0x84460ff, //page1
        0, //unused
        546, //poke scale
        21, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xdd, 0xe2, 0xd8, 0xe9, 0xe2, 0xdb, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        295, //weight
        (u8*) 0x88d2858, //page0
        (u8*) 0x8446166, //page1
        0, //unused
        307, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xe0, 0xd9, 0xd6, 0xd9, 0xe2, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        300, //weight
        (u8*) 0x88d28c7, //page0
        (u8*) 0x84461de, //page1
        0, //unused
        360, //poke scale
        14, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xe3, 0xe2, 0xe2, 0xd9, 0xe6, 0xe7, 0xe4, 0xdd, 0xe2, 0xe2, 0xff}, //category
        15, //height
        125, //weight
        (u8*) 0x88d293e, //page0
        (u8*) 0x844624f, //page1
        0, //unused
        256, //poke scale
        3, //poke displace
        293, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbb, 0xcf, 0xc6, 0xd1, 0xcf, 0xcc, 0xc0, 0xff, 0x0, 0x0, 0x0}, //category
        2, //height
        8, //weight
        (u8*) 0x8446250, //page0
        (u8*) 0x84462cc, //page1
        0, //unused
        706, //poke scale
        22, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbb, 0xcf, 0xc6, 0xd1, 0xcf, 0xcc, 0xc0, 0xff, 0x0, 0x0, 0x0}, //category
        7, //height
        333, //weight
        (u8*) 0x84462cd, //page0
        (u8*) 0x8446327, //page1
        0, //unused
        384, //poke scale
        14, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xe3, 0xe6, 0xe2, 0xda, 0xe6, 0xe9, 0xd7, 0xdc, 0xe8, 0xff, 0x0}, //category
        4, //height
        42, //weight
        (u8*) 0x88d29b0, //page0
        (u8*) 0x844637c, //page1
        0, //unused
        480, //poke scale
        17, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xe3, 0xe6, 0xe2, 0xdf, 0xe9, 0xdb, 0xd9, 0xe0, 0xff, 0xff, 0x0}, //category
        10, //height
        320, //weight
        (u8*) 0x88d2a07, //page0
        (u8*) 0x84463fb, //page1
        0, //unused
        320, //poke scale
        10, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc8, 0xce, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        8, //height
        196, //weight
        (u8*) 0x84463fc, //page0
        (u8*) 0x8446467, //page1
        0, //unused
        347, //poke scale
        11, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc8, 0xce, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        17, //height
        766, //weight
        (u8*) 0x8446468, //page0
        (u8*) 0x84464e0, //page1
        0, //unused
        272, //poke scale
        4, //poke displace
        287, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xd1, 0xad, 0xba, 0x0, 0xbb, 0xc0, 0xc0, 0xbf, 0xff}, //category
        5, //height
        280, //weight
        (u8*) 0x84464e1, //page0
        (u8*) 0x844655a, //page1
        0, //unused
        388, //poke scale
        16, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xd1, 0xad, 0xba, 0x0, 0xbb, 0xc0, 0xc0, 0xbf, 0xff}, //category
        10, //height
        320, //weight
        (u8*) 0x844655b, //page0
        (u8*) 0x84465ea, //page1
        0, //unused
        326, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc2, 0xcf, 0xc8, 0xbe, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        7, //height
        190, //weight
        (u8*) 0x84465eb, //page0
        (u8*) 0x844665d, //page1
        0, //unused
        346, //poke scale
        14, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbf, 0xc1, 0xbf, 0xc8, 0xbe, 0xf1, 0xcc, 0xff, 0x0, 0x0, 0x0}, //category
        19, //height
        1550, //weight
        (u8*) 0x844665e, //page0
        (u8*) 0x84466dd, //page1
        0, //unused
        256, //poke scale
        65535, //poke displace
        312, //trainer scale
        2, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xd7, 0xdc, 0xeb, 0xd9, 0xe6, 0xe8, 0xff, 0xd5, 0xda, 0xe8, 0xff}, //category
        6, //height
        124, //weight
        (u8*) 0x88d2a7a, //page0
        (u8*) 0x8446751, //page1
        0, //unused
        353, //poke scale
        17, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xd7, 0xdc, 0xeb, 0xd9, 0xe6, 0xe8, 0xd9, 0xe6, 0xff, 0xda, 0xff}, //category
        10, //height
        200, //weight
        (u8*) 0x88d2b17, //page0
        (u8*) 0x84467bd, //page1
        0, //unused
        288, //poke scale
        10, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xf5, 0xe2, 0xdd, 0xdb, 0xe7, 0xe8, 0xdd, 0xd7, 0xdc, 0xff, 0xff}, //category
        13, //height
        540, //weight
        (u8*) 0x88d2ba6, //page0
        (u8*) 0x8446833, //page1
        0, //unused
        256, //poke scale
        5, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xcd, 0xc3, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        9, //height
        195, //weight
        (u8*) 0x8446834, //page0
        (u8*) 0x844689d, //page1
        0, //unused
        374, //poke scale
        14, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xcd, 0xc3, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        13, //height
        565, //weight
        (u8*) 0x844689e, //page0
        (u8*) 0x8446916, //page1
        0, //unused
        272, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xcd, 0xc3, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        15, //height
        480, //weight
        (u8*) 0x8446917, //page0
        (u8*) 0x8446997, //page1
        0, //unused
        272, //poke scale
        65535, //poke displace
        271, //trainer scale
        65535, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xcc, 0xbb, 0xc0, 0xce, 0xca, 0xcc, 0xc9, 0xce, 0xd4, 0xff, 0x0}, //category
        8, //height
        195, //weight
        (u8*) 0x8446998, //page0
        (u8*) 0x8446a16, //page1
        0, //unused
        320, //poke scale
        12, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xcc, 0xbb, 0xc0, 0xce, 0xca, 0xcc, 0xc9, 0xce, 0xd4, 0xff, 0x0}, //category
        15, //height
        705, //weight
        (u8*) 0x8446a17, //page0
        (u8*) 0x8446a79, //page1
        0, //unused
        304, //poke scale
        6, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xcc, 0xbb, 0xc0, 0xce, 0xca, 0xcc, 0xc9, 0xce, 0xd4, 0xff, 0x0}, //category
        16, //height
        1300, //weight
        (u8*) 0x8446a7a, //page0
        (u8*) 0x8446acd, //page1
        0, //unused
        278, //poke scale
        2, //poke displace
        283, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xc6, 0xcf, 0xc7, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        7, //height
        40, //weight
        (u8*) 0x8446ace, //page0
        (u8*) 0x8446b39, //page1
        0, //unused
        354, //poke scale
        16, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc6, 0xc3, 0xbf, 0xc1, 0xbf, 0xc8, 0xce, 0xc9, 0xce, 0xff, 0x0}, //category
        10, //height
        64, //weight
        (u8*) 0x8446b3a, //page0
        (u8*) 0x8446bb1, //page1
        0, //unused
        256, //poke scale
        65535, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc6, 0xc3, 0xbf, 0xc1, 0xbf, 0xc8, 0xce, 0xc9, 0xce, 0xff, 0x0}, //category
        17, //height
        155, //weight
        (u8*) 0x8446bb2, //page0
        (u8*) 0x8446c2f, //page1
        0, //unused
        256, //poke scale
        2, //poke displace
        302, //trainer scale
        2, //trainer displace
        0 //unused 2
    },
    {
        {0xcb, 0xcf, 0xbb, 0xc6, 0xc6, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        9, //height
        455, //weight
        (u8*) 0x8446c30, //page0
        (u8*) 0x8446c8d, //page1
        0, //unused
        256, //poke scale
        0, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcb, 0xcf, 0xbb, 0xc6, 0xc6, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        16, //height
        550, //weight
        (u8*) 0x8446c8e, //page0
        (u8*) 0x8446d12, //page1
        0, //unused
        272, //poke scale
        65535, //poke displace
        312, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xbf, 0xcd, 0xce, 0xbf, 0xdd, 0xe2, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        200, //weight
        (u8*) 0x8446d13, //page0
        (u8*) 0x8446d96, //page1
        0, //unused
        330, //poke scale
        17, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xbf, 0xcd, 0xce, 0xbf, 0xdd, 0xe2, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        1050, //weight
        (u8*) 0x8446d97, //page0
        (u8*) 0x8446dfb, //page1
        0, //unused
        272, //poke scale
        8, //poke displace
        305, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xcf, 0xcc, 0xc1, 0xbf, 0xcd, 0xce, 0xbf, 0xdd, 0xe2, 0xff, 0x0, 0x0}, //category
        14, //height
        3000, //weight
        (u8*) 0x8446dfc, //page0
        (u8*) 0x8446e69, //page1
        0, //unused
        266, //poke scale
        3, //poke displace
        298, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xd9, 0xe9, 0xd9, 0xe6, 0xca, 0xc0, 0xbf, 0xcc, 0xbe, 0xff, 0x0}, //category
        10, //height
        300, //weight
        (u8*) 0x8446e6a, //page0
        (u8*) 0x8446ed0, //page1
        0, //unused
        288, //poke scale
        7, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xd9, 0xe9, 0xd9, 0xe6, 0xca, 0xc0, 0xbf, 0xcc, 0xbe, 0xff, 0x0}, //category
        17, //height
        950, //weight
        (u8*) 0x8446ed1, //page0
        (u8*) 0x8446f5e, //page1
        0, //unused
        282, //poke scale
        65535, //poke displace
        312, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xc8, 0xbb, 0xcc, 0xbd, 0xc2, 0xbf, 0xcc, 0xff, 0x0}, //category
        12, //height
        360, //weight
        (u8*) 0x8446f5f, //page0
        (u8*) 0x8446fce, //page1
        0, //unused
        271, //poke scale
        10, //poke displace
        272, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xd3, 0xc7, 0xbc, 0xc3, 0xc9, 0xcd, 0xbf, 0xff, 0x0, 0x0, 0x0}, //category
        16, //height
        785, //weight
        (u8*) 0x8446fcf, //page0
        (u8*) 0x844702e, //page1
        0, //unused
        257, //poke scale
        65534, //poke displace
        312, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbb, 0xc1, 0xc8, 0xbf, 0xce, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        3, //height
        60, //weight
        (u8*) 0x844702f, //page0
        (u8*) 0x8447092, //page1
        0, //unused
        294, //poke scale
        65528, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbb, 0xc1, 0xc8, 0xbf, 0xce, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        600, //weight
        (u8*) 0x8447093, //page0
        (u8*) 0x8447108, //page1
        0, //unused
        293, //poke scale
        65532, //poke displace
        273, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xc3, 0xc6, 0xbe, 0xbf, 0xc8, 0xce, 0xbf, 0xff, 0x0, 0x0, 0x0}, //category
        8, //height
        150, //weight
        (u8*) 0x8447109, //page0
        (u8*) 0x8447161, //page1
        0, //unused
        317, //poke scale
        65534, //poke displace
        256, //trainer scale
        65533, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xcf, 0xc9, 0xd0, 0xc9, 0xc1, 0xbf, 0xc6, 0xff, 0x0, 0x0, 0x0}, //category
        14, //height
        392, //weight
        (u8*) 0x8447162, //page0
        (u8*) 0x84471bd, //page1
        0, //unused
        256, //poke scale
        3, //poke displace
        287, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xce, 0xcc, 0xc3, 0xd0, 0xc9, 0xc1, 0xbf, 0xc6, 0xff, 0x0, 0x0, 0x0}, //category
        18, //height
        852, //weight
        (u8*) 0x84471be, //page0
        (u8*) 0x844722a, //page1
        0, //unused
        272, //poke scale
        65534, //poke displace
        296, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbf, 0xbf, 0xc2, 0xcf, 0xc8, 0xbe, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        11, //height
        900, //weight
        (u8*) 0x844722b, //page0
        (u8*) 0x84472a0, //page1
        0, //unused
        298, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbf, 0xbf, 0xc2, 0xcf, 0xc8, 0xbe, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        17, //height
        1200, //weight
        (u8*) 0x84472a1, //page0
        (u8*) 0x844730a, //page1
        0, //unused
        288, //poke scale
        1, //poke displace
        306, //trainer scale
        65535, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xc6, 0xbb, 0xc7, 0xc7, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        9, //height
        300, //weight
        (u8*) 0x844730b, //page0
        (u8*) 0x8447377, //page1
        0, //unused
        258, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xc6, 0xbb, 0xc7, 0xc7, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        12, //height
        300, //weight
        (u8*) 0x8447378, //page0
        (u8*) 0x8447403, //page1
        0, //unused
        288, //poke scale
        7, //poke displace
        288, //trainer scale
        65535, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xcf, 0xcd, 0xbd, 0xc2, 0xbf, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        3, //height
        40, //weight
        (u8*) 0x8447404, //page0
        (u8*) 0x8447455, //page1
        0, //unused
        643, //poke scale
        21, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xcf, 0xcd, 0xbd, 0xc2, 0xbf, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        15, //height
        1325, //weight
        (u8*) 0x8447456, //page0
        (u8*) 0x84474e2, //page1
        0, //unused
        264, //poke scale
        0, //poke displace
        288, //trainer scale
        65535, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xbb, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        13, //height
        1, //weight
        (u8*) 0x84474e3, //page0
        (u8*) 0x8447564, //page1
        0, //unused
        256, //poke scale
        0, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xbb, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        16, //height
        1, //weight
        (u8*) 0x8447565, //page0
        (u8*) 0x84475d2, //page1
        0, //unused
        269, //poke scale
        2, //poke displace
        308, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xbb, 0xce, 0xce, 0xbf, 0xc8, 0xff, 0x0, 0x0, 0x0}, //category
        15, //height
        405, //weight
        (u8*) 0x84475d3, //page0
        (u8*) 0x8447649, //page1
        0, //unused
        256, //poke scale
        4, //poke displace
        317, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xbf, 0xc6, 0xcd, 0xc8, 0xbb, 0xce, 0xce, 0xbf, 0xcc, 0xff, 0x0}, //category
        88, //height
        2100, //weight
        (u8*) 0x844764a, //page0
        (u8*) 0x84476b7, //page1
        0, //unused
        257, //poke scale
        0, //poke displace
        515, //trainer scale
        12, //trainer displace
        0 //unused 2
    },
    {
        {0xc2, 0xd3, 0xca, 0xc8, 0xc9, 0xcd, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        324, //weight
        (u8*) 0x84476b8, //page0
        (u8*) 0x8447733, //page1
        0, //unused
        274, //poke scale
        7, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc2, 0xd3, 0xca, 0xc8, 0xc9, 0xcd, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        16, //height
        756, //weight
        (u8*) 0x8447734, //page0
        (u8*) 0x84477a3, //page1
        0, //unused
        298, //poke scale
        3, //poke displace
        310, //trainer scale
        2, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xcc, 0xbb, 0xbc, 0xbc, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        65, //weight
        (u8*) 0x84477a4, //page0
        (u8*) 0x8447814, //page1
        0, //unused
        469, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc8, 0xbf, 0xc3, 0xc0, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        13, //height
        600, //weight
        (u8*) 0x8447815, //page0
        (u8*) 0x8447897, //page1
        0, //unused
        287, //poke scale
        3, //poke displace
        308, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xbb, 0xc6, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        5, //height
        104, //weight
        (u8*) 0x8447898, //page0
        (u8*) 0x8447902, //page1
        0, //unused
        364, //poke scale
        65528, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xbb, 0xc6, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        12, //height
        666, //weight
        (u8*) 0x8447903, //page0
        (u8*) 0x8447976, //page1
        0, //unused
        256, //poke scale
        0, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        25, //weight
        (u8*) 0x8447977, //page0
        (u8*) 0x84479fc, //page1
        0, //unused
        495, //poke scale
        65532, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xbb, 0xc6, 0xc7, 0xc0, 0xcc, 0xcf, 0xbd, 0xc2, 0xce, 0xff, 0x0}, //category
        20, //height
        1200, //weight
        (u8*) 0x84479fd, //page0
        (u8*) 0x8447a63, //page1
        0, //unused
        283, //poke scale
        0, //poke displace
        376, //trainer scale
        7, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xc8, 0xcd, 0xbb, 0xc7, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        65, //weight
        (u8*) 0x8447a64, //page0
        (u8*) 0x8447ad2, //page1
        0, //unused
        545, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc8, 0xc9, 0xbd, 0xc2, 0xbf, 0xc8, 0xc0, 0xbb, 0xc8, 0xff, 0x0}, //category
        10, //height
        450, //weight
        (u8*) 0x8447ad3, //page0
        (u8*) 0x8447b3a, //page1
        0, //unused
        293, //poke scale
        12, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc3, 0xbd, 0xc5, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        15, //height
        498, //weight
        (u8*) 0x8447b3b, //page0
        (u8*) 0x8447bbb, //page1
        0, //unused
        256, //poke scale
        0, //poke displace
        273, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xcf, 0xc8, 0xbd, 0xc2, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        14, //height
        502, //weight
        (u8*) 0x8447bbc, //page0
        (u8*) 0x8447c3d, //page1
        0, //unused
        256, //poke scale
        1, //poke displace
        264, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xc6, 0xbf, 0xbd, 0xc5, 0xbf, 0xcc, 0xff, 0x0, 0x0}, //category
        12, //height
        655, //weight
        (u8*) 0x8447c3e, //page0
        (u8*) 0x8447cc3, //page1
        0, //unused
        272, //poke scale
        3, //poke displace
        272, //trainer scale
        65533, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xdd, 0xda, 0xe8, 0xd1, 0xc9, 0xc6, 0xc5, 0xbf, 0xff, 0x0, 0x0}, //category
        6, //height
        10, //weight
        (u8*) 0x8447cc4, //page0
        (u8*) 0x8447d4c, //page1
        0, //unused
        369, //poke scale
        65535, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xdd, 0xda, 0xe8, 0xd1, 0xc9, 0xc6, 0xc5, 0xbf, 0xff, 0x0, 0x0}, //category
        12, //height
        95, //weight
        (u8*) 0x8447d4d, //page0
        (u8*) 0x8447daf, //page1
        0, //unused
        321, //poke scale
        65535, //poke displace
        276, //trainer scale
        65535, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xce, 0xbb, 0xbd, 0xc2, 0xc6, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0}, //category
        10, //height
        1150, //weight
        (u8*) 0x8447db0, //page0
        (u8*) 0x8447e23, //page1
        0, //unused
        291, //poke scale
        7, //poke displace
        276, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xc9, 0xc2, 0xcc, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        19, //height
        1200, //weight
        (u8*) 0x8447e24, //page0
        (u8*) 0x8447e96, //page1
        0, //unused
        272, //poke scale
        65535, //poke displace
        344, //trainer scale
        3, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        11, //height
        346, //weight
        (u8*) 0x8447e97, //page0
        (u8*) 0x8447eec, //page1
        0, //unused
        257, //poke scale
        6, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc3, 0xc8, 0xcd, 0xce, 0xbf, 0xcc, 0xc8, 0xc3, 0xcd, 0xff, 0x0}, //category
        5, //height
        110, //weight
        (u8*) 0x8746200, //page0
        (u8*) 0x8447f54, //page1
        0, //unused
        451, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xcf, 0xce, 0xce, 0xbf, 0xcc, 0xce, 0xc3, 0xbf, 0xcc, 0xff, 0x0}, //category
        22, //height
        800, //weight
        (u8*) 0x8447f55, //page0
        (u8*) 0x8447fd1, //page1
        0, //unused
        257, //poke scale
        65533, //poke displace
        349, //trainer scale
        5, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xe6, 0xd5, 0xd7, 0xdc, 0xd9, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        80, //weight
        (u8*) 0x8447fd2, //page0
        (u8*) 0x8448034, //page1
        0, //unused
        399, //poke scale
        65535, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xe6, 0xd5, 0xd7, 0xdc, 0xd9, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        12, //height
        250, //weight
        (u8*) 0x8448035, //page0
        (u8*) 0x84480b9, //page1
        0, //unused
        296, //poke scale
        3, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xc6, 0xbf, 0xc3, 0xce, 0xff, 0xcd, 0xbd, 0xc2, 0xff, 0x0, 0x0}, //category
        6, //height
        150, //weight
        (u8*) 0x84480ba, //page0
        (u8*) 0x8448142, //page1
        0, //unused
        379, //poke scale
        4, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xc6, 0xbf, 0xc3, 0xce, 0xff, 0xcd, 0xbd, 0xc2, 0xff, 0x0, 0x0}, //category
        13, //height
        390, //weight
        (u8*) 0x8448143, //page0
        (u8*) 0x84481bc, //page1
        0, //unused
        304, //poke scale
        1, //poke displace
        288, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xce, 0xbf, 0xcc, 0xc8, 0xc0, 0xc9, 0xcc, 0xc7, 0xff, 0x0, 0x0}, //category
        8, //height
        345, //weight
        (u8*) 0x84481bd, //page0
        (u8*) 0x8448218, //page1
        0, //unused
        326, //poke scale
        1, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xd3, 0xcd, 0xce, 0xbf, 0xcc, 0xc3, 0xf2, 0xcd, 0xff, 0x0, 0x0}, //category
        11, //height
        800, //weight
        (u8*) 0x8448219, //page0
        (u8*) 0x844829f, //page1
        0, //unused
        301, //poke scale
        3, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xcc, 0xbf, 0xc3, 0xcd, 0xbd, 0xc2, 0xbf, 0xcc, 0xff, 0xbf, 0xff}, //category
        7, //height
        10, //weight
        (u8*) 0x8746268, //page0
        (u8*) 0x844831c, //page1
        0, //unused
        407, //poke scale
        65528, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbb, 0xc8, 0xce, 0xc3, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        15, //height
        560, //weight
        (u8*) 0x844831d, //page0
        (u8*) 0x84483a1, //page1
        0, //unused
        272, //poke scale
        0, //poke displace
        293, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc6, 0xc3, 0xc8, 0xc1, 0xbf, 0xff, 0xc2, 0xce, 0xff, 0x0, 0x0}, //category
        14, //height
        406, //weight
        (u8*) 0x84483a2, //page0
        (u8*) 0x844841d, //page1
        0, //unused
        256, //poke scale
        3, //poke displace
        300, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xe0, 0xd9, 0xdf, 0xe8, 0xe6, 0xe3, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        11, //height
        300, //weight
        (u8*) 0x844841e, //page0
        (u8*) 0x844847f, //page1
        0, //unused
        330, //poke scale
        7, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xcc, 0xbf, 0xc8, 0xc8, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        13, //height
        445, //weight
        (u8*) 0x8448480, //page0
        (u8*) 0x84484f9, //page1
        0, //unused
        293, //poke scale
        4, //poke displace
        272, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc8, 0xbf, 0xc3, 0xc0, 0xc5, 0xf4, 0xda, 0xd9, 0xe6, 0xff, 0x0}, //category
        15, //height
        550, //weight
        (u8*) 0x84484fa, //page0
        (u8*) 0x844857e, //page1
        0, //unused
        256, //poke scale
        1, //poke displace
        257, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xc3, 0xc6, 0xbe, 0xbc, 0xcf, 0xc6, 0xc6, 0xbf, 0xff, 0x0, 0x0}, //category
        14, //height
        884, //weight
        (u8*) 0x844857f, //page0
        (u8*) 0x84485d7, //page1
        0, //unused
        256, //poke scale
        2, //poke displace
        312, //trainer scale
        3, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc3, 0xcd, 0xbd, 0xc2, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        9, //height
        100, //weight
        (u8*) 0x84485d8, //page0
        (u8*) 0x844864e, //page1
        0, //unused
        317, //poke scale
        4, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xcc, 0xbb, 0xcf, 0xcd, 0xbb, 0xc7, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        65, //height
        2350, //weight
        (u8*) 0x844864f, //page0
        (u8*) 0x84486c2, //page1
        0, //unused
        288, //poke scale
        65535, //poke displace
        512, //trainer scale
        11, //trainer displace
        0 //unused 2
    },
    {
        {0xce, 0xcc, 0xbb, 0xc8, 0xcd, 0xca, 0xc9, 0xcc, 0xce, 0xff, 0x0, 0x0}, //category
        25, //height
        2200, //weight
        (u8*) 0x84486c3, //page0
        (u8*) 0x8448749, //page1
        0, //unused
        256, //poke scale
        0, //poke displace
        425, //trainer scale
        8, //trainer displace
        0 //unused 2
    },
    {
        {0xce, 0xcc, 0xbb, 0xc8, 0xcd, 0xc0, 0xc9, 0xcc, 0xc7, 0xff, 0x0, 0x0}, //category
        3, //height
        40, //weight
        (u8*) 0x844874a, //page0
        (u8*) 0x84487af, //page1
        0, //unused
        602, //poke scale
        21, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xd0, 0xc9, 0xc6, 0xcf, 0xce, 0xc3, 0xc9, 0xc8, 0xff, 0x0, 0x0}, //category
        3, //height
        65, //weight
        (u8*) 0x84487b0, //page0
        (u8*) 0x8448805, //page1
        0, //unused
        476, //poke scale
        17, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xc6, 0xcf, 0xbc, 0xbc, 0xc6, 0xbb, 0xcd, 0xbf, 0xff, 0x0, 0x0}, //category
        10, //height
        290, //weight
        (u8*) 0x8448806, //page0
        (u8*) 0x8448897, //page1
        0, //unused
        316, //poke scale
        7, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xc6, 0xc3, 0xce, 0xd4, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        8, //height
        245, //weight
        (u8*) 0x8448898, //page0
        (u8*) 0x84488ef, //page1
        0, //unused
        283, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xd9, 0xe9, 0xd9, 0xe6, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        9, //height
        250, //weight
        (u8*) 0x84488f0, //page0
        (u8*) 0x8448971, //page1
        0, //unused
        302, //poke scale
        11, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd0, 0xc3, 0xcc, 0xce, 0xcf, 0xbf, 0xc6, 0xc6, 0xff, 0x0, 0x0, 0x0}, //category
        8, //height
        365, //weight
        (u8*) 0x8448972, //page0
        (u8*) 0x84489ea, //page1
        0, //unused
        328, //poke scale
        7, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xca, 0xc3, 0xcc, 0xbb, 0xc6, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        75, //weight
        (u8*) 0x84489eb, //page0
        (u8*) 0x8448a5a, //page1
        0, //unused
        521, //poke scale
        20, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xca, 0xc3, 0xcc, 0xbb, 0xc6, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        350, //weight
        (u8*) 0x8448a5b, //page0
        (u8*) 0x8448ada, //page1
        0, //unused
        307, //poke scale
        5, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xbb, 0xc8, 0xd4, 0xbf, 0xcc, 0xce, 0xc3, 0xbf, 0xcc, 0xff, 0x0}, //category
        5, //height
        115, //weight
        (u8*) 0x8448adb, //page0
        (u8*) 0x8448b56, //page1
        0, //unused
        438, //poke scale
        21, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xbb, 0xc8, 0xd4, 0xbf, 0xcc, 0xce, 0xc3, 0xbf, 0xcc, 0xff, 0x0}, //category
        13, //height
        405, //weight
        (u8*) 0x8448b57, //page0
        (u8*) 0x8448bc5, //page1
        0, //unused
        271, //poke scale
        1, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc9, 0xcd, 0xcd, 0xc3, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        18, //height
        590, //weight
        (u8*) 0x8448bc6, //page0
        (u8*) 0x8448c50, //page1
        0, //unused
        275, //poke scale
        65535, //poke displace
        317, //trainer scale
        2, //trainer displace
        0 //unused 2
    },
    {
        {0xce, 0xbb, 0xc1, 0xce, 0xcc, 0xf1, 0xcf, 0xc7, 0xbf, 0xcc, 0xff, 0x0}, //category
        21, //height
        4600, //weight
        (u8*) 0x8448c51, //page0
        (u8*) 0x8448cc9, //page1
        0, //unused
        275, //poke scale
        1, //poke displace
        408, //trainer scale
        7, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xdd, 0xe7, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        17, //height
        554, //weight
        (u8*) 0x8448cca, //page0
        (u8*) 0x8448d44, //page1
        0, //unused
        278, //poke scale
        0, //poke displace
        308, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xe0, 0xd9, 0xdf, 0xe8, 0xe6, 0xe3, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        16, //height
        526, //weight
        (u8*) 0x8448d45, //page0
        (u8*) 0x8448da4, //page1
        0, //unused
        275, //poke scale
        1, //poke displace
        330, //trainer scale
        3, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc6, 0xbb, 0xc7, 0xc7, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        20, //height
        600, //weight
        (u8*) 0x8448da5, //page0
        (u8*) 0x8448e32, //page1
        0, //unused
        270, //poke scale
        1, //poke displace
        379, //trainer scale
        6, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xe6, 0xd5, 0xd7, 0xdc, 0xd9, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        18, //height
        33, //weight
        (u8*) 0x8448e33, //page0
        (u8*) 0x8448ea8, //page1
        0, //unused
        256, //poke scale
        8, //poke displace
        386, //trainer scale
        6, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xe6, 0xd5, 0xd7, 0xdc, 0xd9, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        40, //height
        165, //weight
        (u8*) 0x8448ea9, //page0
        (u8*) 0x8448f0b, //page1
        0, //unused
        274, //poke scale
        0, //poke displace
        423, //trainer scale
        6, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xe6, 0xd5, 0xd7, 0xdc, 0xd9, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        22, //height
        2100, //weight
        (u8*) 0x8448f0c, //page0
        (u8*) 0x8448f74, //page1
        0, //unused
        283, //poke scale
        65535, //poke displace
        342, //trainer scale
        4, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xbf, 0xc8, 0xc7, 0xcf, 0xce, 0xbb, 0xc8, 0xce, 0xff, 0x0, 0x0}, //category
        20, //height
        1220, //weight
        (u8*) 0x8448f75, //page0
        (u8*) 0x8448feb, //page1
        0, //unused
        276, //poke scale
        65535, //poke displace
        342, //trainer scale
        5, //trainer displace
        0 //unused 2
    },
    {
        {0xc8, 0xbf, 0xcf, 0xbf, 0x0, 0xbb, 0xcc, 0xce, 0xff, 0x0, 0x0, 0x0}, //category
        4, //height
        40, //weight
        (u8*) 0x8448fec, //page0
        (u8*) 0x8449059, //page1
        0, //unused
        460, //poke scale
        65534, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbb, 0xcf, 0xbc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        9, //height
        64, //weight
        (u8*) 0x844905a, //page0
        (u8*) 0x84490be, //page1
        0, //unused
        512, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbb, 0xcf, 0xbc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        12, //height
        158, //weight
        (u8*) 0x84490bf, //page0
        (u8*) 0x8449119, //page1
        0, //unused
        296, //poke scale
        4, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xcc, 0xf1, 0xcf, 0xce, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        18, //height
        1005, //weight
        (u8*) 0x844911a, //page0
        (u8*) 0x8449182, //page1
        0, //unused
        286, //poke scale
        0, //poke displace
        317, //trainer scale
        2, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xd9, 0xe9, 0xd9, 0xe6, 0xc7, 0xbb, 0xe9, 0xe7, 0xff, 0x0, 0x0}, //category
        5, //height
        79, //weight
        (u8*) 0x8449183, //page0
        (u8*) 0x84491e9, //page1
        0, //unused
        539, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd0, 0xcf, 0xc6, 0xc5, 0xbb, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        9, //height
        190, //weight
        (u8*) 0x84491ea, //page0
        (u8*) 0x8449244, //page1
        0, //unused
        329, //poke scale
        10, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd0, 0xcf, 0xc6, 0xc5, 0xbb, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        17, //height
        795, //weight
        (u8*) 0x8449245, //page0
        (u8*) 0x84492a5, //page1
        0, //unused
        284, //poke scale
        65535, //poke displace
        287, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xcc, 0xc9, 0xcd, 0xcd, 0xc7, 0xbb, 0xcf, 0xc6, 0xff, 0x0, 0x0}, //category
        6, //height
        95, //weight
        (u8*) 0x84492a6, //page0
        (u8*) 0x8449303, //page1
        0, //unused
        487, //poke scale
        20, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xcc, 0xc9, 0xcd, 0xcd, 0xc7, 0xbb, 0xcf, 0xc6, 0xff, 0x0, 0x0}, //category
        11, //height
        250, //weight
        (u8*) 0x8449304, //page0
        (u8*) 0x844936a, //page1
        0, //unused
        378, //poke scale
        11, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xcc, 0xc9, 0xcd, 0xcd, 0xc7, 0xbb, 0xcf, 0xc6, 0xff, 0x0, 0x0}, //category
        23, //height
        888, //weight
        (u8*) 0x844936b, //page0
        (u8*) 0x84493d0, //page1
        0, //unused
        282, //poke scale
        65535, //poke displace
        375, //trainer scale
        6, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xd5, 0xd7, 0xdf, 0xd9, 0xe0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        8, //height
        60, //weight
        (u8*) 0x88d2c37, //page0
        (u8*) 0x8449434, //page1
        0, //unused
        439, //poke scale
        12, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xe3, 0xe2, 0xe2, 0xd9, 0xff, 0xc3, 0xbc, 0xff, 0x0, 0x0, 0x0}, //category
        18, //height
        325, //weight
        (u8*) 0x88d2cb4, //page0
        (u8*) 0x8449496, //page1
        0, //unused
        346, //poke scale
        10, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc8, 0xd9, 0xe9, 0xe7, 0xd7, 0xdc, 0xe2, 0xd9, 0xd9, 0xff, 0x0, 0x0}, //category
        7, //height
        212, //weight
        (u8*) 0x88d2d23, //page0
        (u8*) 0x8449504, //page1
        0, //unused
        380, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xe6, 0xd9, 0xe7, 0xe8, 0xe0, 0xdd, 0xe2, 0xdb, 0xff, 0x0, 0x0}, //category
        16, //height
        408, //weight
        (u8*) 0x88d2d72, //page0
        (u8*) 0x844955f, //page1
        0, //unused
        278, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xf3, 0xc8, 0xc0, 0xae, 0xca, 0xcf, 0xc8, 0xc5, 0xce, 0xff, 0x0}, //category
        10, //height
        108, //weight
        (u8*) 0x8449560, //page0
        (u8*) 0x84495c5, //page1
        0, //unused
        256, //poke scale
        4, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xf3, 0xc8, 0xc0, 0xae, 0xca, 0xcf, 0xc8, 0xc5, 0xce, 0xff, 0x0}, //category
        14, //height
        356, //weight
        (u8*) 0x84495c6, //page0
        (u8*) 0x8449621, //page1
        0, //unused
        256, //poke scale
        1, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xbb, 0xbe, 0xbf, 0xc8, 0xd1, 0xcf, 0xcc, 0xc0, 0xff, 0x0, 0x0}, //category
        5, //height
        85, //weight
        (u8*) 0x8449622, //page0
        (u8*) 0x8449687, //page1
        0, //unused
        414, //poke scale
        20, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbb, 0xc8, 0xc1, 0xbc, 0xbf, 0xdd, 0xe2, 0xff, 0x0, 0x0, 0x0}, //category
        11, //height
        335, //weight
        (u8*) 0x8449688, //page0
        (u8*) 0x84496eb, //page1
        0, //unused
        316, //poke scale
        7, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc6, 0xbf, 0xbe, 0xbf, 0xcc, 0xc7, 0xbb, 0xe9, 0xe7, 0xff, 0x0}, //category
        18, //height
        750, //weight
        (u8*) 0x84496ec, //page0
        (u8*) 0x8449751, //page1
        0, //unused
        279, //poke scale
        65535, //poke displace
        313, //trainer scale
        2, //trainer displace
        0 //unused 2
    },
    {
        {0xbb, 0xc8, 0xc1, 0xc6, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        5, //height
        120, //weight
        (u8*) 0x8449752, //page0
        (u8*) 0x84497b0, //page1
        0, //unused
        424, //poke scale
        65534, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbf, 0xcf, 0xbd, 0xc2, 0xce, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        12, //height
        225, //weight
        (u8*) 0x84497b1, //page0
        (u8*) 0x8449816, //page1
        0, //unused
        269, //poke scale
        6, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbb, 0xc1, 0xc8, 0xbf, 0xce, 0xc1, 0xbf, 0xbc, 0xc3, 0xbf, 0xff}, //category
        3, //height
        20, //weight
        (u8*) 0x8449817, //page0
        (u8*) 0x844987e, //page1
        0, //unused
        508, //poke scale
        17, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc4, 0xcf, 0xbc, 0xc3, 0xc6, 0xc3, 0xbf, 0xcc, 0xbf, 0xcc, 0xff, 0x0}, //category
        3, //height
        30, //weight
        (u8*) 0x844987f, //page0
        (u8*) 0x84498da, //page1
        0, //unused
        462, //poke scale
        22, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xdd, 0xe2, 0xd6, 0xe0, 0xf6, 0xe8, 0xe0, 0xd9, 0xe6, 0xff, 0x0}, //category
        3, //height
        10, //weight
        (u8*) 0x88d2dff, //page0
        (u8*) 0x8449936, //page1
        0, //unused
        457, //poke scale
        65535, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd4, 0xbb, 0xbd, 0xc5, 0xbf, 0xc8, 0xbc, 0xbb, 0xc6, 0xc6, 0xff, 0x0}, //category
        3, //height
        15, //weight
        (u8*) 0x8449937, //page0
        (u8*) 0x844999b, //page1
        0, //unused
        507, //poke scale
        21, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xcc, 0xbf, 0xcf, 0xbe, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        32, //weight
        (u8*) 0x844999c, //page0
        (u8*) 0x8449a00, //page1
        0, //unused
        424, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc6, 0xbf, 0xc3, 0xc8, 0xd0, 0xc9, 0xc1, 0xbf, 0xc6, 0xff, 0x0}, //category
        2, //height
        20, //weight
        (u8*) 0x8449a01, //page0
        (u8*) 0x8449a66, //page1
        0, //unused
        610, //poke scale
        23, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xd3, 0xcd, 0xce, 0xc3, 0xc5, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        15, //height
        150, //weight
        (u8*) 0x8449a67, //page0
        (u8*) 0x8449acb, //page1
        0, //unused
        258, //poke scale
        4, //poke displace
        317, //trainer scale
        3, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xc9, 0xc6, 0xc6, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        78, //weight
        (u8*) 0x8449acc, //page0
        (u8*) 0x8449b32, //page1
        0, //unused
        379, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xc9, 0xc6, 0xc6, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        8, //height
        133, //weight
        (u8*) 0x8449b33, //page0
        (u8*) 0x8449b8d, //page1
        0, //unused
        372, //poke scale
        13, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbf, 0xcf, 0xbd, 0xc2, 0xce, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        14, //height
        615, //weight
        (u8*) 0x8449b8e, //page0
        (u8*) 0x8449bf6, //page1
        0, //unused
        275, //poke scale
        2, //poke displace
        283, //trainer scale
        65535, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xc6, 0xcf, 0xc7, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        58, //weight
        (u8*) 0x8449bf7, //page0
        (u8*) 0x8449c5d, //page1
        0, //unused
        472, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbb, 0xcb, 0xcf, 0xbb, 0xc7, 0xbb, 0xe9, 0xe7, 0xff, 0x0, 0x0, 0x0}, //category
        4, //height
        85, //weight
        (u8*) 0x8449c5e, //page0
        (u8*) 0x8449cc3, //page1
        0, //unused
        476, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbb, 0xcb, 0xcf, 0xbb, 0xc2, 0xbb, 0xcd, 0xbf, 0xff, 0x0, 0x0, 0x0}, //category
        8, //height
        285, //weight
        (u8*) 0x8449cc4, //page0
        (u8*) 0x8449d28, //page1
        0, //unused
        448, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc3, 0xc7, 0xc3, 0xce, 0xbb, 0xce, 0xc3, 0xc9, 0xc8, 0xff, 0x0, 0x0}, //category
        12, //height
        380, //weight
        (u8*) 0x8449d29, //page0
        (u8*) 0x8449d90, //page1
        0, //unused
        305, //poke scale
        7, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xd7, 0xdc, 0xe0, 0xf6, 0xe7, 0xe7, 0xd9, 0xe0, 0xff, 0x0, 0x0}, //category
        11, //height
        339, //weight
        (u8*) 0x88d2e88, //page0
        (u8*) 0x8449df4, //page1
        0, //unused
        289, //poke scale
        5, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xd9, 0xe6, 0xee, 0xd9, 0xff, 0xbb, 0xc2, 0xc8, 0xff, 0x0, 0x0}, //category
        4, //height
        5, //weight
        (u8*) 0x88d2eec, //page0
        (u8*) 0x8449e58, //page1
        0, //unused
        562, //poke scale
        65529, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xd5, 0xe1, 0xe4, 0xd9, 0xff, 0xbb, 0xc2, 0xc8, 0xff, 0x0, 0x0}, //category
        6, //height
        10, //weight
        (u8*) 0x88d2f88, //page0
        (u8*) 0x8449ec0, //page1
        0, //unused
        387, //poke scale
        0, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xd9, 0xe0, 0xd9, 0xdd, 0xe8, 0xff, 0xc2, 0xc8, 0xff, 0x0, 0x0}, //category
        8, //height
        30, //weight
        (u8*) 0x88d2ffe, //page0
        (u8*) 0x8449f21, //page1
        0, //unused
        418, //poke scale
        65532, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbb, 0xc8, 0xc1, 0xcd, 0xbd, 0xc2, 0xd1, 0xbf, 0xc3, 0xc0, 0xff}, //category
        8, //height
        115, //weight
        (u8*) 0x8449f22, //page0
        (u8*) 0x8449f81, //page1
        0, //unused
        363, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xcc, 0xc9, 0xcd, 0xce, 0xbc, 0xbb, 0xcf, 0xc7, 0xff, 0x0, 0x0}, //category
        3, //height
        18, //weight
        (u8*) 0x8449f82, //page0
        (u8*) 0x8449fe0, //page1
        0, //unused
        541, //poke scale
        0, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xcc, 0xc9, 0xcd, 0xce, 0xbc, 0xbb, 0xcf, 0xc7, 0xff, 0x0, 0x0}, //category
        8, //height
        85, //weight
        (u8*) 0x8449fe1, //page0
        (u8*) 0x844a042, //page1
        0, //unused
        374, //poke scale
        12, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xc3, 0xbc, 0xbf, 0xc6, 0xc6, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        12, //height
        380, //weight
        (u8*) 0x844a043, //page0
        (u8*) 0x844a0a7, //page1
        0, //unused
        274, //poke scale
        65532, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc3, 0xcd, 0xbd, 0xc2, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        85, //weight
        (u8*) 0x844a0a8, //page0
        (u8*) 0x844a102, //page1
        0, //unused
        479, //poke scale
        20, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc3, 0xcd, 0xbd, 0xc2, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        14, //height
        750, //weight
        (u8*) 0x844a103, //page0
        (u8*) 0x844a168, //page1
        0, //unused
        273, //poke scale
        4, //poke displace
        273, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xc9, 0xc8, 0xc8, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        9, //height
        265, //weight
        (u8*) 0x844a169, //page0
        (u8*) 0x844a1cb, //page1
        0, //unused
        363, //poke scale
        12, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xc9, 0xc8, 0xbe, 0xcd, 0xbd, 0xc2, 0xbf, 0xdd, 0xe2, 0xff, 0x0}, //category
        10, //height
        270, //weight
        (u8*) 0x844a1cc, //page0
        (u8*) 0x844a233, //page1
        0, //unused
        317, //poke scale
        9, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc3, 0xc8, 0xcd, 0xce, 0xbf, 0xcc, 0xc8, 0xc3, 0xcd, 0xff, 0x0}, //category
        5, //height
        21, //weight
        (u8*) 0x844a234, //page0
        (u8*) 0x844a298, //page1
        0, //unused
        401, //poke scale
        65528, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xc9, 0xc8, 0xbb, 0xcc, 0xbd, 0xc2, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        20, //height
        795, //weight
        (u8*) 0x844a299, //page0
        (u8*) 0x844a301, //page1
        0, //unused
        265, //poke scale
        65535, //poke displace
        330, //trainer scale
        4, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xcc, 0xbf, 0xc3, 0xcd, 0xbd, 0xc2, 0xbf, 0xcc, 0xff, 0x0, 0x0}, //category
        7, //height
        10, //weight
        (u8*) 0x844a302, //page0
        (u8*) 0x844a361, //page1
        0, //unused
        407, //poke scale
        65528, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xd3, 0xc7, 0xbc, 0xc9, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        5, //height
        50, //weight
        (u8*) 0x844a362, //page0
        (u8*) 0x844a3c1, //page1
        0, //unused
        411, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xd7, 0xdc, 0xe2, 0xd9, 0xd9, 0xdb, 0xd9, 0xd6, 0xdd, 0xd9, 0xff}, //category
        68, //height
        285, //weight
        (u8*) 0x88d3074, //page0
        (u8*) 0x844a421, //page1
        0, //unused
        517, //poke scale
        4, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbb, 0xc8, 0xc1, 0xc2, 0xbb, 0xc6, 0xcd, 0xff, 0x0, 0x0, 0x0}, //category
        15, //height
        415, //weight
        (u8*) 0x844a422, //page0
        (u8*) 0x844a486, //page1
        0, //unused
        281, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xd9, 0xe9, 0xe8, 0xd9, 0xe0, 0xd1, 0xcf, 0xcc, 0xc7, 0xff, 0x0}, //category
        6, //height
        72, //weight
        (u8*) 0x844a487, //page0
        (u8*) 0x844a4ec, //page1
        0, //unused
        445, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xd9, 0xe9, 0xe8, 0xd9, 0xe0, 0xd1, 0xcf, 0xcc, 0xc7, 0xff, 0x0}, //category
        12, //height
        1258, //weight
        (u8*) 0x844a4ed, //page0
        (u8*) 0x844a550, //page1
        0, //unused
        293, //poke scale
        5, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xc9, 0xc8, 0xc8, 0xbf, 0xcc, 0xc5, 0xbf, 0xc3, 0xc6, 0xff, 0x0}, //category
        15, //height
        140, //weight
        (u8*) 0x844a551, //page0
        (u8*) 0x844a5bb, //page1
        0, //unused
        284, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xe0, 0xe9, 0xdb, 0xcd, 0xc5, 0xc9, 0xcc, 0xca, 0xc3, 0xff, 0x0}, //category
        11, //height
        648, //weight
        (u8*) 0x844a5bc, //page0
        (u8*) 0x844a61d, //page1
        0, //unused
        350, //poke scale
        65535, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xe8, 0xd5, 0xdc, 0xe0, 0xbc, 0xc9, 0xbb, 0xff, 0x0, 0x0, 0x0}, //category
        92, //height
        4000, //weight
        (u8*) 0x844a61e, //page0
        (u8*) 0x844a673, //page1
        0, //unused
        278, //poke scale
        65535, //poke displace
        557, //trainer scale
        13, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xd9, 0xd9, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        78, //weight
        (u8*) 0x844a674, //page0
        (u8*) 0x844a6d1, //page1
        0, //unused
        465, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xd9, 0xd9, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        14, //height
        487, //weight
        (u8*) 0x844a6d2, //page0
        (u8*) 0x844a730, //page1
        0, //unused
        256, //poke scale
        3, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xe3, 0xe4, 0xe4, 0xd9, 0xe0, 0xee, 0xd5, 0xdc, 0xe2, 0xff, 0xff}, //category
        18, //height
        1004, //weight
        (u8*) 0x878fe90, //page0
        (u8*) 0x844a78e, //page1
        0, //unused
        777, //poke scale
        0, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc8, 0xbf, 0xc3, 0xc0, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        18, //height
        1180, //weight
        (u8*) 0x844a78f, //page0
        (u8*) 0x844a7f9, //page1
        0, //unused
        282, //poke scale
        0, //poke displace
        282, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xc3, 0xc7, 0xc7, 0xbf, 0xc6, 0xff, 0x0, 0x0, 0x0}, //category
        6, //height
        205, //weight
        (u8*) 0x844a7fa, //page0
        (u8*) 0x844a861, //page1
        0, //unused
        485, //poke scale
        16, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xc8, 0xd4, 0xbf, 0xc6, 0xc2, 0xc9, 0xcc, 0xc8, 0xff, 0x0}, //category
        15, //height
        540, //weight
        (u8*) 0x844a862, //page0
        (u8*) 0x844a8c4, //page1
        0, //unused
        285, //poke scale
        0, //poke displace
        283, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd0, 0xbf, 0xcc, 0xbc, 0xc9, 0xce, 0xbf, 0xc8, 0xff, 0xbf, 0xff, 0x0}, //category
        9, //height
        280, //weight
        (u8*) 0x844a8c5, //page0
        (u8*) 0x844a926, //page1
        0, //unused
        413, //poke scale
        65533, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc6, 0xbf, 0xc3, 0xc8, 0xbc, 0xf1, 0xcc, 0xff, 0x0, 0x0, 0x0}, //category
        6, //height
        88, //weight
        (u8*) 0x844a927, //page0
        (u8*) 0x844a989, //page1
        0, //unused
        455, //poke scale
        17, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xc6, 0xf1, 0xc0, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0}, //category
        18, //height
        1258, //weight
        (u8*) 0x844a98a, //page0
        (u8*) 0x844a9ec, //page1
        0, //unused
        275, //poke scale
        0, //poke displace
        280, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbb, 0xd0, 0xbb, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        7, //height
        350, //weight
        (u8*) 0x844a9ed, //page0
        (u8*) 0x844aa57, //page1
        0, //unused
        329, //poke scale
        14, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbb, 0xd0, 0xbb, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        8, //height
        550, //weight
        (u8*) 0x844aa58, //page0
        (u8*) 0x844aab3, //page1
        0, //unused
        332, //poke scale
        14, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xbf, 0xcc, 0xc5, 0xbf, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        65, //weight
        (u8*) 0x844aab4, //page0
        (u8*) 0x844ab0b, //page1
        0, //unused
        324, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xd1, 0xbf, 0xdd, 0xe2, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        11, //height
        558, //weight
        (u8*) 0x844ab0c, //page0
        (u8*) 0x844ab6b, //page1
        0, //unused
        306, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc9, 0xcc, 0xbb, 0xc6, 0xc6, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        50, //weight
        (u8*) 0x844ab6c, //page0
        (u8*) 0x844abcb, //page1
        0, //unused
        410, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc2, 0xc9, 0xbd, 0xc2, 0xbe, 0xcc, 0xcf, 0xbd, 0xc5, 0xff, 0x0, 0x0}, //category
        6, //height
        120, //weight
        (u8*) 0x844abcc, //page0
        (u8*) 0x844ac31, //page1
        0, //unused
        316, //poke scale
        4, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc2, 0xc9, 0xbd, 0xc2, 0xbe, 0xcc, 0xcf, 0xbd, 0xc5, 0xff, 0x0, 0x0}, //category
        9, //height
        285, //weight
        (u8*) 0x844ac32, //page0
        (u8*) 0x844ac9c, //page1
        0, //unused
        296, //poke scale
        9, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xc3, 0xbf, 0xc0, 0xbf, 0xcc, 0xbb, 0xc8, 0xce, 0xff, 0x0, 0x0}, //category
        9, //height
        160, //weight
        (u8*) 0x844ac9d, //page0
        (u8*) 0x844ad06, //page1
        0, //unused
        293, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xe0, 0xe9, 0xdb, 0xcc, 0xc9, 0xbd, 0xc2, 0xbf, 0xc8, 0xff, 0x0}, //category
        21, //height
        2200, //weight
        (u8*) 0x844ad07, //page0
        (u8*) 0x844ad69, //page1
        0, //unused
        275, //poke scale
        0, //poke displace
        360, //trainer scale
        6, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xe0, 0xe9, 0xdb, 0xcd, 0xe8, 0xd5, 0xdc, 0xe0, 0xff, 0x0, 0x0}, //category
        17, //height
        505, //weight
        (u8*) 0x844ad6a, //page0
        (u8*) 0x844adc9, //page1
        0, //unused
        285, //poke scale
        0, //poke displace
        276, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xc2, 0xbb, 0xbe, 0xbf, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        108, //weight
        (u8*) 0x844adca, //page0
        (u8*) 0x844ae35, //page1
        0, //unused
        393, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc2, 0xbb, 0xbe, 0xbf, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        14, //height
        350, //weight
        (u8*) 0x844ae36, //page0
        (u8*) 0x844ae98, //page1
        0, //unused
        256, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xe6, 0xd5, 0xd7, 0xdc, 0xd9, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        18, //height
        1520, //weight
        (u8*) 0x844ae99, //page0
        (u8*) 0x844aef8, //page1
        0, //unused
        257, //poke scale
        1, //poke displace
        293, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbb, 0xc8, 0xc1, 0xcc, 0xf3, 0xcd, 0xcd, 0xbf, 0xc6, 0xff, 0x0}, //category
        5, //height
        335, //weight
        (u8*) 0x844aef9, //page0
        (u8*) 0x844af61, //page1
        0, //unused
        465, //poke scale
        20, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xbb, 0xc8, 0xd4, 0xbf, 0xcc, 0xce, 0xc3, 0xbf, 0xcc, 0xff, 0x0}, //category
        11, //height
        1200, //weight
        (u8*) 0x844af62, //page0
        (u8*) 0x844afc7, //page1
        0, //unused
        313, //poke scale
        9, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd0, 0xc3, 0xcc, 0xce, 0xcf, 0xbf, 0xc6, 0xc6, 0xff, 0x0, 0x0, 0x0}, //category
        6, //height
        325, //weight
        (u8*) 0x844afc8, //page0
        (u8*) 0x844b031, //page1
        0, //unused
        320, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xe3, 0xe1, 0xe4, 0xd5, 0xe7, 0xe7, 0xff, 0xcc, 0xff, 0x0, 0x0}, //category
        14, //height
        712, //weight
        (u8*) 0x88d30d1, //page0
        (u8*) 0x844b089, //page1
        0, //unused
        277, //poke scale
        65535, //poke displace
        277, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xcc, 0xc3, 0xce, 0xce, 0xbf, 0xcc, 0xc6, 0xc3, 0xbd, 0xc2, 0xff, 0x0}, //category
        12, //height
        580, //weight
        (u8*) 0x88d312e, //page0
        (u8*) 0x844b0e7, //page1
        0, //unused
        287, //poke scale
        5, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcc, 0xbb, 0xbd, 0xc5, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        7, //height
        210, //weight
        (u8*) 0x844b0e8, //page0
        (u8*) 0x844b149, //page1
        0, //unused
        292, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc9, 0xca, 0xc0, 0xcd, 0xce, 0xbb, 0xc8, 0xbe, 0xff, 0x0, 0x0}, //category
        14, //height
        480, //weight
        (u8*) 0x844b14a, //page0
        (u8*) 0x844b1ae, //page1
        0, //unused
        256, //poke scale
        2, //poke displace
        257, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xcf, 0xcd, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        60, //weight
        (u8*) 0x844b1af, //page0
        (u8*) 0x844b202, //page1
        0, //unused
        440, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xe0, 0xd9, 0xdf, 0xe8, 0xe6, 0xe3, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        235, //weight
        (u8*) 0x844b203, //page0
        (u8*) 0x844b25e, //page1
        0, //unused
        363, //poke scale
        13, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xc6, 0xcf, 0xce, 0xc2, 0xbf, 0xcc, 0xbe, 0xff, 0x0, 0x0, 0x0}, //category
        7, //height
        214, //weight
        (u8*) 0x844b25f, //page0
        (u8*) 0x844b2c4, //page1
        0, //unused
        284, //poke scale
        11, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xc3, 0xc6, 0xbd, 0xc2, 0xc5, 0xcf, 0xc2, 0xff, 0x0, 0x0, 0x0}, //category
        12, //height
        755, //weight
        (u8*) 0x844b2c5, //page0
        (u8*) 0x844b31d, //page1
        0, //unused
        280, //poke scale
        3, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xcc, 0xbf, 0xcf, 0xbe, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        15, //height
        468, //weight
        (u8*) 0x844b31e, //page0
        (u8*) 0x844b379, //page1
        0, //unused
        256, //poke scale
        3, //poke displace
        310, //trainer scale
        3, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xc9, 0xc8, 0xc8, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        19, //height
        1780, //weight
        (u8*) 0x844b37a, //page0
        (u8*) 0x844b3df, //page1
        0, //unused
        283, //poke scale
        0, //poke displace
        359, //trainer scale
        6, //trainer displace
        0 //unused 2
    },
    {
        {0xd0, 0xcf, 0xc6, 0xc5, 0xbb, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        21, //height
        1980, //weight
        (u8*) 0x844b3e0, //page0
        (u8*) 0x844b43e, //page1
        0, //unused
        283, //poke scale
        0, //poke displace
        370, //trainer scale
        7, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xc9, 0xc6, 0xbb, 0xcc, 0xc6, 0xc3, 0xbd, 0xc2, 0xce, 0xff, 0x0}, //category
        20, //height
        1870, //weight
        (u8*) 0x844b43f, //page0
        (u8*) 0x844b4a1, //page1
        0, //unused
        286, //poke scale
        0, //poke displace
        371, //trainer scale
        7, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xbf, 0xc6, 0xcd, 0xc2, 0xbb, 0xcf, 0xce, 0xff, 0x0, 0x0, 0x0}, //category
        6, //height
        720, //weight
        (u8*) 0x844b4a2, //page0
        (u8*) 0x844b510, //page1
        0, //unused
        472, //poke scale
        16, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc2, 0xbb, 0xcc, 0xce, 0xcd, 0xbd, 0xc2, 0xbb, 0xc6, 0xbf, 0xff, 0x0}, //category
        12, //height
        1520, //weight
        (u8*) 0x844b511, //page0
        (u8*) 0x844b56f, //page1
        0, //unused
        292, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xbb, 0xc8, 0xd4, 0xbf, 0xcc, 0xce, 0xc3, 0xbf, 0xcc, 0xff, 0x0}, //category
        20, //height
        2020, //weight
        (u8*) 0x844b570, //page0
        (u8*) 0x844b5d0, //page1
        0, //unused
        285, //poke scale
        0, //poke displace
        383, //trainer scale
        7, //trainer displace
        0 //unused 2
    },
    {
        {0xce, 0xbb, 0xcf, 0xbd, 0xc2, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        52, //height
        2160, //weight
        (u8*) 0x844b5d1, //page0
        (u8*) 0x844b637, //page1
        0, //unused
        283, //poke scale
        0, //poke displace
        742, //trainer scale
        18, //trainer displace
        0 //unused 2
    },
    {
        {0xcc, 0xbf, 0xc1, 0xbf, 0xc8, 0xbc, 0xc9, 0xc1, 0xbf, 0xc8, 0xff, 0x0}, //category
        38, //height
        1990, //weight
        (u8*) 0x844b638, //page0
        (u8*) 0x844b697, //page1
        0, //unused
        283, //poke scale
        0, //poke displace
        620, //trainer scale
        16, //trainer displace
        0 //unused 2
    },
    {
        {0xd4, 0xbf, 0xc3, 0xce, 0xcc, 0xbf, 0xc3, 0xcd, 0xbf, 0xff, 0x0, 0x0}, //category
        6, //height
        50, //weight
        (u8*) 0x844b698, //page0
        (u8*) 0x844b6f5, //page1
        0, //unused
        393, //poke scale
        65526, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xc9, 0xbd, 0xc5, 0xbf, 0xff, 0xbe, 0xbe, 0xd3, 0xff, 0xff, 0x0}, //category
        5, //height
        50, //weight
        (u8*) 0x87460e4, //page0
        (u8*) 0x844b78b, //page1
        0, //unused
        541, //poke scale
        17, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xd1, 0xbf, 0xcc, 0xce, 0xff, 0xd4, 0xbf, 0xff, 0x0}, //category
        9, //height
        216, //weight
        (u8*) 0x8746148, //page0
        (u8*) 0x844b7f4, //page1
        0, //unused
        360, //poke scale
        5, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcc, 0xc3, 0xce, 0xce, 0xbf, 0xcc, 0xff, 0xcd, 0xce, 0xbf, 0xcc, 0xff}, //category
        17, //height
        522, //weight
        (u8*) 0x87462cc, //page0
        (u8*) 0x844b877, //page1
        0, //unused
        282, //poke scale
        65535, //poke displace
        313, //trainer scale
        3, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xbf, 0xc6, 0xca, 0xbf, 0xff, 0xc8, 0xbe, 0xbf, 0xcc, 0xff, 0xff}, //category
        4, //height
        25, //weight
        (u8*) 0x844b878, //page0
        (u8*) 0x844b8d5, //page1
        0, //unused
        566, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc9, 0xcc, 0xce, 0xc2, 0xc9, 0xcd, 0xff, 0xbe, 0xbf, 0xcc, 0xff, 0x0}, //category
        9, //height
        195, //weight
        (u8*) 0x844b8d6, //page0
        (u8*) 0x844b957, //page1
        0, //unused
        343, //poke scale
        5, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd4, 0xbf, 0xcc, 0xbc, 0xbf, 0xcc, 0xcf, 0xcd, 0xff, 0xc9, 0xcc, 0xff}, //category
        19, //height
        520, //weight
        (u8*) 0x844b958, //page0
        (u8*) 0x844b9ed, //page1
        0, //unused
        275, //poke scale
        65535, //poke displace
        314, //trainer scale
        3, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xd5, 0xe7, 0xe7, 0xd9, 0xe6, 0xc7, 0xc9, 0xc6, 0xbd, 0xc2, 0xff}, //category
        4, //height
        76, //weight
        (u8*) 0x8746328, //page0
        (u8*) 0x844ba79, //page1
        0, //unused
        535, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xbf, 0xc6, 0xca, 0xc2, 0xc3, 0xc8, 0xff, 0xbf, 0xcc, 0xff, 0x0}, //category
        7, //height
        280, //weight
        (u8*) 0x874c5dc, //page0
        (u8*) 0x844bb03, //page1
        0, //unused
        340, //poke scale
        7, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbf, 0xbf, 0xcd, 0xbd, 0xc2, 0xc6, 0xbb, 0xc8, 0xc1, 0xbf, 0xff}, //category
        15, //height
        819, //weight
        (u8*) 0x87727c0, //page0
        (u8*) 0x844bb81, //page1
        0, //unused
        276, //poke scale
        65535, //poke displace
        282, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xc3, 0xcd, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        5, //height
        136, //weight
        (u8*) 0x844bb82, //page0
        (u8*) 0x844bc03, //page1
        0, //unused
        481, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xc3, 0xcd, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        370, //weight
        (u8*) 0x844bc04, //page0
        (u8*) 0x844bc84, //page1
        0, //unused
        359, //poke scale
        9, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc6, 0xbf, 0xc3, 0xc8, 0xbe, 0xbb, 0xbd, 0xc2, 0xcd, 0xff, 0x0}, //category
        4, //height
        175, //weight
        (u8*) 0x844bc85, //page0
        (u8*) 0x844bcd9, //page1
        0, //unused
        560, //poke scale
        21, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xca, 0xcc, 0xc3, 0xc8, 0xce, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0}, //category
        5, //height
        325, //weight
        (u8*) 0x844bcda, //page0
        (u8*) 0x844bd58, //page1
        0, //unused
        321, //poke scale
        5, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xcf, 0xcc, 0xc7, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        3, //height
        36, //weight
        (u8*) 0x844bd59, //page0
        (u8*) 0x844bdbf, //page1
        0, //unused
        711, //poke scale
        22, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc9, 0xc5, 0xc9, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        100, //weight
        (u8*) 0x844bdc0, //page0
        (u8*) 0x844be49, //page1
        0, //unused
        431, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xbb, 0xc6, 0xce, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        284, //weight
        (u8*) 0x844be4a, //page0
        (u8*) 0x844bed4, //page1
        0, //unused
        298, //poke scale
        65535, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc9, 0xc5, 0xc9, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        7, //height
        115, //weight
        (u8*) 0x844bed5, //page0
        (u8*) 0x844bf56, //page1
        0, //unused
        391, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xdd, 0xda, 0xe8, 0xc7, 0xc9, 0xce, 0xce, 0xbf, 0xff, 0x0, 0x0}, //category
        12, //height
        316, //weight
        (u8*) 0x844bf57, //page0
        (u8*) 0x844bfd8, //page1
        0, //unused
        269, //poke scale
        1, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xd5, 0xe7, 0xe7, 0xd9, 0xe6, 0xc6, 0xc3, 0xc8, 0xcd, 0xbf, 0xff}, //category
        5, //height
        26, //weight
        (u8*) 0x844bfd9, //page0
        (u8*) 0x844c047, //page1
        0, //unused
        406, //poke scale
        17, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xcc, 0xc9, 0xc2, 0xc7, 0xcf, 0xce, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        12, //height
        325, //weight
        (u8*) 0x844c048, //page0
        (u8*) 0x844c0b3, //page1
        0, //unused
        277, //poke scale
        7, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xc9, 0xcc, 0xc1, 0xc6, 0xc9, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        15, //height
        550, //weight
        (u8*) 0x844c0b4, //page0
        (u8*) 0x844c117, //page1
        0, //unused
        283, //poke scale
        0, //poke displace
        282, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xbd, 0xc2, 0xbf, 0xc6, 0xc8, 0xcf, 0xcd, 0xcd, 0xff, 0x0}, //category
        5, //height
        40, //weight
        (u8*) 0x844c118, //page0
        (u8*) 0x844c1ab, //page1
        0, //unused
        472, //poke scale
        20, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc2, 0xc3, 0xc8, 0xce, 0xbf, 0xcc, 0xc6, 0xc3, 0xcd, 0xce, 0xff, 0x0}, //category
        10, //height
        280, //weight
        (u8*) 0x844c1ac, //page0
        (u8*) 0x844c229, //page1
        0, //unused
        299, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd0, 0xbf, 0xcc, 0xcd, 0xbd, 0xc2, 0xc6, 0xbb, 0xc1, 0xbf, 0xc8, 0xff}, //category
        13, //height
        596, //weight
        (u8*) 0x844c22a, //page0
        (u8*) 0x844c2a0, //page1
        0, //unused
        290, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xd1, 0xf1, 0xc6, 0xbc, 0xc6, 0xbf, 0xdd, 0xe2, 0xff}, //category
        3, //height
        23, //weight
        (u8*) 0x844c2a1, //page0
        (u8*) 0x844c316, //page1
        0, //unused
        465, //poke scale
        20, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xd1, 0xbb, 0xc6, 0xbc, 0xbf, 0xff, 0x0, 0x0, 0x0}, //category
        7, //height
        198, //weight
        (u8*) 0x844c317, //page0
        (u8*) 0x844c39d, //page1
        0, //unused
        428, //poke scale
        13, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbf, 0xbf, 0xc7, 0xf2, 0xd1, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        95, //weight
        (u8*) 0x844c39e, //page0
        (u8*) 0x844c406, //page1
        0, //unused
        295, //poke scale
        65534, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xd5, 0xe7, 0xe7, 0xd9, 0xe6, 0xd0, 0xc9, 0xc1, 0xbf, 0xc6, 0xff}, //category
        12, //height
        280, //weight
        (u8*) 0x844c407, //page0
        (u8*) 0x844c497, //page1
        0, //unused
        288, //poke scale
        1, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xbf, 0xc0, 0xf3, 0xc2, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        66, //weight
        (u8*) 0x844c498, //page0
        (u8*) 0x844c50c, //page1
        0, //unused
        457, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc7, 0xc9, 0xce, 0xc3, 0xc9, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        8, //height
        202, //weight
        (u8*) 0x844c50d, //page0
        (u8*) 0x844c595, //page1
        0, //unused
        354, //poke scale
        10, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcf, 0xc7, 0xbb, 0xcc, 0xc7, 0xcf, 0xc8, 0xc1, 0xff, 0x0, 0x0, 0x0}, //category
        16, //height
        484, //weight
        (u8*) 0x844c596, //page0
        (u8*) 0x844c5f8, //page1
        0, //unused
        277, //poke scale
        0, //poke displace
        276, //trainer scale
        65535, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xd5, 0xe7, 0xe7, 0xd9, 0xe6, 0xc1, 0xbf, 0xc2, 0xbf, 0xcc, 0xff}, //category
        5, //height
        17, //weight
        (u8*) 0x844c5f9, //page0
        (u8*) 0x844c672, //page1
        0, //unused
        375, //poke scale
        17, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbb, 0xcf, 0xc1, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        8, //height
        36, //weight
        (u8*) 0x844c673, //page0
        (u8*) 0x844c6e8, //page1
        0, //unused
        378, //poke scale
        65535, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xc3, 0xc6, 0xd4, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        45, //weight
        (u8*) 0x844c6e9, //page0
        (u8*) 0x844c76b, //page1
        0, //unused
        513, //poke scale
        20, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xc3, 0xc6, 0xd4, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        12, //height
        392, //weight
        (u8*) 0x844c76c, //page0
        (u8*) 0x844c7e9, //page1
        0, //unused
        324, //poke scale
        6, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xbb, 0xcf, 0xc6, 0xca, 0xbf, 0xc6, 0xd4, 0xff, 0x0, 0x0, 0x0}, //category
        8, //height
        240, //weight
        (u8*) 0x844c7ea, //page0
        (u8*) 0x844c861, //page1
        0, //unused
        291, //poke scale
        16, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xc3, 0xc6, 0xbe, 0xbb, 0xc0, 0xc0, 0xbf, 0xff, 0x0, 0x0, 0x0}, //category
        14, //height
        465, //weight
        (u8*) 0x844c862, //page0
        (u8*) 0x844c8c5, //page1
        0, //unused
        301, //poke scale
        1, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xf3, 0xcd, 0xcd, 0xc3, 0xc1, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        20, //height
        1305, //weight
        (u8*) 0x844c8c6, //page0
        (u8*) 0x844c958, //page1
        0, //unused
        277, //poke scale
        5, //poke displace
        326, //trainer scale
        3, //trainer displace
        0 //unused 2
    },
    {
        {0xd0, 0xc9, 0xcc, 0xbc, 0xbf, 0xcc, 0xbf, 0xc3, 0xce, 0xbf, 0xcc, 0xff}, //category
        5, //height
        55, //weight
        (u8*) 0x844c959, //page0
        (u8*) 0x844c9dd, //page1
        0, //unused
        405, //poke scale
        20, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc8, 0xc3, 0xc8, 0xc4, 0xd5, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        8, //height
        120, //weight
        (u8*) 0x844c9de, //page0
        (u8*) 0x844ca44, //page1
        0, //unused
        383, //poke scale
        65527, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc2, 0xf1, 0xcf, 0xce, 0xcf, 0xc8, 0xc1, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        8, //height
        12, //weight
        (u8*) 0x844ca45, //page0
        (u8*) 0x844caab, //page1
        0, //unused
        372, //poke scale
        65528, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbb, 0xc8, 0xbe, 0xc2, 0xbb, 0xc3, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        163, //weight
        (u8*) 0x844caac, //page0
        (u8*) 0x844cb35, //page1
        0, //unused
        373, //poke scale
        16, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc2, 0xf2, 0xc2, 0xc6, 0xbf, 0xff, 0xc6, 0xcd, 0xff, 0x0, 0x0, 0x0}, //category
        10, //height
        405, //weight
        (u8*) 0x844cb36, //page0
        (u8*) 0x844cba8, //page1
        0, //unused
        356, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcc, 0xbb, 0xcd, 0xbb, 0xc8, 0xd4, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        21, //height
        840, //weight
        (u8*) 0x844cba9, //page0
        (u8*) 0x844cc1f, //page1
        0, //unused
        284, //poke scale
        1, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xbf, 0xc6, 0xc6, 0xbf, 0xc8, 0xcd, 0xca, 0xc3, 0xbf, 0xc6, 0xff}, //category
        10, //height
        864, //weight
        (u8*) 0x844cc20, //page0
        (u8*) 0x844cc84, //page1
        0, //unused
        256, //poke scale
        9, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbb, 0xcf, 0xcc, 0xbb, 0xff, 0xcc, 0xc0, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        23, //height
        2538, //weight
        (u8*) 0x844cc85, //page0
        (u8*) 0x844cd17, //page1
        0, //unused
        268, //poke scale
        65535, //poke displace
        375, //trainer scale
        6, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xbf, 0xca, 0xcf, 0xc8, 0xc5, 0xce, 0xbf, 0xce, 0xff, 0x0, 0x0}, //category
        2, //height
        20, //weight
        (u8*) 0x844cd18, //page0
        (u8*) 0x844cd90, //page1
        0, //unused
        603, //poke scale
        21, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc9, 0xc7, 0xca, 0xbb, 0xcd, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        970, //weight
        (u8*) 0x844cd91, //page0
        (u8*) 0x844cdf5, //page1
        0, //unused
        256, //poke scale
        9, //poke displace
        289, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xf1, 0xce, 0xd4, 0xbd, 0xc2, 0xbf, 0xc8, 0xff, 0x0, 0x0, 0x0}, //category
        6, //height
        110, //weight
        (u8*) 0x844cdf6, //page0
        (u8*) 0x844ce89, //page1
        0, //unused
        492, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xc8, 0xc1, 0xbf, 0xbc, 0xc3, 0xc6, 0xbe, 0xbf, 0xce, 0xff}, //category
        11, //height
        326, //weight
        (u8*) 0x844ce8a, //page0
        (u8*) 0x844cf0c, //page1
        0, //unused
        322, //poke scale
        9, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xcc, 0xbf, 0xc3, 0xc0, 0xbf, 0xcc, 0xff, 0xc3, 0xcd, 0xff, 0x0}, //category
        5, //height
        110, //weight
        (u8*) 0x844cf0d, //page0
        (u8*) 0x844cf6f, //page1
        0, //unused
        451, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xd1, 0xc3, 0xc8, 0xbe, 0xc6, 0xbf, 0xcc, 0xff, 0x0}, //category
        6, //height
        115, //weight
        (u8*) 0x844cf70, //page0
        (u8*) 0x844cff7, //page1
        0, //unused
        466, //poke scale
        15, //poke displace
        256, //trainer scale
        65533, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xcd, 0xbf, 0xc8, 0xca, 0xbb, 0xc8, 0xd4, 0xbf, 0xcc, 0xff}, //category
        4, //height
        600, //weight
        (u8*) 0x844cff8, //page0
        (u8*) 0x844d079, //page1
        0, //unused
        419, //poke scale
        21, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xcd, 0xbf, 0xc8, 0xca, 0xbb, 0xc8, 0xd4, 0xbf, 0xcc, 0xff}, //category
        9, //height
        1200, //weight
        (u8*) 0x844d07a, //page0
        (u8*) 0x844d10f, //page1
        0, //unused
        275, //poke scale
        11, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xcd, 0xbf, 0xc8, 0xca, 0xbb, 0xc8, 0xd4, 0xbf, 0xcc, 0xff}, //category
        21, //height
        3600, //weight
        (u8*) 0x844d110, //page0
        (u8*) 0x844d17f, //page1
        0, //unused
        274, //poke scale
        65535, //poke displace
        374, //trainer scale
        7, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbf, 0xbe, 0xc3, 0xce, 0xbb, 0xce, 0xc3, 0xc9, 0xc8, 0xff, 0x0}, //category
        6, //height
        112, //weight
        (u8*) 0x844d180, //page0
        (u8*) 0x844d1df, //page1
        0, //unused
        465, //poke scale
        17, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbf, 0xbe, 0xc3, 0xce, 0xbb, 0xce, 0xc3, 0xc9, 0xc8, 0xff, 0x0}, //category
        13, //height
        315, //weight
        (u8*) 0x844d1e0, //page0
        (u8*) 0x844d260, //page1
        0, //unused
        298, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xbf, 0xd1, 0xc3, 0xce, 0xce, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0}, //category
        6, //height
        152, //weight
        (u8*) 0x844d261, //page0
        (u8*) 0x844d2df, //page1
        0, //unused
        290, //poke scale
        16, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc8, 0xce, 0xc6, 0xbb, 0xbe, 0xcf, 0xc8, 0xc1, 0xff, 0x0, 0x0}, //category
        15, //height
        402, //weight
        (u8*) 0x844d2e0, //page0
        (u8*) 0x844d345, //page1
        0, //unused
        256, //poke scale
        1, //poke displace
        257, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc4, 0xcf, 0xbc, 0xbf, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        42, //weight
        (u8*) 0x844d346, //page0
        (u8*) 0x844d3ce, //page1
        0, //unused
        515, //poke scale
        65527, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc4, 0xcf, 0xbc, 0xbf, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        42, //weight
        (u8*) 0x844d3cf, //page0
        (u8*) 0x844d44a, //page1
        0, //unused
        512, //poke scale
        65529, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xc3, 0xbc, 0xbf, 0xc6, 0xc6, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        7, //height
        177, //weight
        (u8*) 0x844d44b, //page0
        (u8*) 0x844d4cd, //page1
        0, //unused
        442, //poke scale
        65532, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xc3, 0xbc, 0xbf, 0xc6, 0xc6, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        177, //weight
        (u8*) 0x844d4ce, //page0
        (u8*) 0x844d53d, //page1
        0, //unused
        572, //poke scale
        65532, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xc9, 0xcc, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        3, //height
        20, //weight
        (u8*) 0x844d53e, //page0
        (u8*) 0x844d5a6, //page1
        0, //unused
        677, //poke scale
        20, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbb, 0xc1, 0xbf, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        103, //weight
        (u8*) 0x844d5a7, //page0
        (u8*) 0x844d62a, //page1
        0, //unused
        593, //poke scale
        22, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xdd, 0xda, 0xe8, 0xbc, 0xd9, 0xe9, 0xe8, 0xd9, 0xe0, 0xff, 0x0}, //category
        17, //height
        800, //weight
        (u8*) 0x844d62b, //page0
        (u8*) 0x844d69f, //page1
        0, //unused
        256, //poke scale
        5, //poke displace
        345, //trainer scale
        4, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xc8, 0xbb, 0xbe, 0xbf, 0xc8, 0xc6, 0xc9, 0xcd, 0xff, 0x0, 0x0}, //category
        8, //height
        208, //weight
        (u8*) 0x844d6a0, //page0
        (u8*) 0x844d71b, //page1
        0, //unused
        362, //poke scale
        0, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xcc, 0xcf, 0xce, 0xbb, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        18, //height
        888, //weight
        (u8*) 0x844d71c, //page0
        (u8*) 0x844d794, //page1
        0, //unused
        265, //poke scale
        0, //poke displace
        342, //trainer scale
        4, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xcf, 0xc1, 0xbf, 0xc6, 0xd1, 0xbb, 0xc6, 0xff, 0x0, 0x0, 0x0}, //category
        20, //height
        1300, //weight
        (u8*) 0x844d795, //page0
        (u8*) 0x844d815, //page1
        0, //unused
        256, //poke scale
        10, //poke displace
        493, //trainer scale
        10, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc6, 0xcf, 0xce, 0xd1, 0xbb, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        145, //height
        3980, //weight
        (u8*) 0x844d816, //page0
        (u8*) 0x844d87d, //page1
        0, //unused
        276, //poke scale
        65535, //poke displace
        1428, //trainer scale
        20, //trainer displace
        0 //unused 2
    },
    {
        {0xce, 0xbb, 0xcf, 0xbc, 0xc2, 0xbf, 0xc3, 0xce, 0xff, 0x0, 0x0, 0x0}, //category
        7, //height
        240, //weight
        (u8*) 0x844d87e, //page0
        (u8*) 0x844d8f7, //page1
        0, //unused
        310, //poke scale
        14, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbb, 0xcf, 0xcd, 0xbc, 0xcc, 0xcf, 0xbd, 0xc2, 0xff, 0x0, 0x0, 0x0}, //category
        19, //height
        2200, //weight
        (u8*) 0x844d8f8, //page0
        (u8*) 0x844d96c, //page1
        0, //unused
        256, //poke scale
        6, //poke displace
        345, //trainer scale
        4, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xbf, 0xce, 0xe3, 0xe2, 0xbb, 0xce, 0xc3, 0xc9, 0xc8, 0xff, 0x0}, //category
        5, //height
        804, //weight
        (u8*) 0x844d96d, //page0
        (u8*) 0x844d9e6, //page1
        0, //unused
        392, //poke scale
        9, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xca, 0xcc, 0xcf, 0xc8, 0xc1, 0xc0, 0xbf, 0xbe, 0xbf, 0xcc, 0xff}, //category
        7, //height
        306, //weight
        (u8*) 0x844d9e7, //page0
        (u8*) 0x844da51, //page1
        0, //unused
        423, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbb, 0xc8, 0xc3, 0xca, 0xcf, 0xc6, 0xbb, 0xce, 0xc9, 0xcc, 0xff}, //category
        9, //height
        715, //weight
        (u8*) 0x844da52, //page0
        (u8*) 0x844dad9, //page1
        0, //unused
        358, //poke scale
        9, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xcf, 0xc8, 0xc5, 0xce, 0xae, 0xca, 0xbb, 0xc8, 0xbe, 0xbb, 0xff}, //category
        11, //height
        50, //weight
        (u8*) 0x844dada, //page0
        (u8*) 0x844db4f, //page1
        0, //unused
        321, //poke scale
        9, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbb, 0xc7, 0xbf, 0xc3, 0xcd, 0xbf, 0xc8, 0xc6, 0xf2, 0xd1, 0xbf, 0xff}, //category
        7, //height
        150, //weight
        (u8*) 0x844db50, //page0
        (u8*) 0x844dbcd, //page1
        0, //unused
        298, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd0, 0xc3, 0xbc, 0xcc, 0xbb, 0xce, 0xc3, 0xc9, 0xc8, 0xff, 0x0, 0x0}, //category
        11, //height
        153, //weight
        (u8*) 0x844dbce, //page0
        (u8*) 0x844dc4b, //page1
        0, //unused
        370, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xd3, 0xcd, 0xce, 0xc3, 0xc5, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        20, //height
        820, //weight
        (u8*) 0x844dc4c, //page0
        (u8*) 0x844dcbd, //page1
        0, //unused
        280, //poke scale
        0, //poke displace
        299, //trainer scale
        2, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xbb, 0xc5, 0xce, 0xcf, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        513, //weight
        (u8*) 0x844dcbe, //page0
        (u8*) 0x844dd2c, //page1
        0, //unused
        455, //poke scale
        19, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd0, 0xc9, 0xc1, 0xbf, 0xc6, 0xcd, 0xbd, 0xc2, 0xc9, 0xbd, 0xc5, 0xff}, //category
        13, //height
        774, //weight
        (u8*) 0x844dd2d, //page0
        (u8*) 0x844dda6, //page1
        0, //unused
        327, //poke scale
        3, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xc9, 0xc6, 0xc6, 0xd0, 0xc9, 0xc1, 0xbf, 0xc6, 0xff, 0x0, 0x0}, //category
        4, //height
        12, //weight
        (u8*) 0x844dda7, //page0
        (u8*) 0x844de16, //page1
        0, //unused
        422, //poke scale
        65528, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xcf, 0xc7, 0xc7, 0xcd, 0xbf, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        11, //height
        206, //weight
        (u8*) 0x844de17, //page0
        (u8*) 0x844de94, //page1
        0, //unused
        327, //poke scale
        0, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xcc, 0xbf, 0xce, 0xce, 0xc5, 0xbb, 0xce, 0xd4, 0xff, 0x0, 0x0}, //category
        13, //height
        403, //weight
        (u8*) 0x844de95, //page0
        (u8*) 0x844df0f, //page1
        0, //unused
        256, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcc, 0xbf, 0xc3, 0xcd, 0xcd, 0xd4, 0xbb, 0xc2, 0xc8, 0xff, 0x0, 0x0}, //category
        27, //height
        525, //weight
        (u8*) 0x844df10, //page0
        (u8*) 0x844dfa4, //page1
        0, //unused
        275, //poke scale
        6, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbf, 0xce, 0xbf, 0xc9, 0xcc, 0xc3, 0xce, 0xff, 0x0, 0x0, 0x0}, //category
        10, //height
        1680, //weight
        (u8*) 0x844dfa5, //page0
        (u8*) 0x844e009, //page1
        0, //unused
        300, //poke scale
        1, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbf, 0xce, 0xbf, 0xc9, 0xcc, 0xc3, 0xce, 0xff, 0x0, 0x0, 0x0}, //category
        12, //height
        1540, //weight
        (u8*) 0x844e00a, //page0
        (u8*) 0x844e07c, //page1
        0, //unused
        328, //poke scale
        65533, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xbb, 0xcc, 0xce, 0xc2, 0xbb, 0xbb, 0xcc, 0xff, 0x0, 0x0, 0x0}, //category
        4, //height
        19, //weight
        (u8*) 0x844e07d, //page0
        (u8*) 0x844e0fc, //page1
        0, //unused
        581, //poke scale
        65534, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xbb, 0xcc, 0xce, 0xc2, 0xbb, 0xbb, 0xcc, 0xff, 0x0, 0x0, 0x0}, //category
        9, //height
        236, //weight
        (u8*) 0x844e0fd, //page0
        (u8*) 0x844e16d, //page1
        0, //unused
        317, //poke scale
        1, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc1, 0xcc, 0xc9, 0xbc, 0xc3, 0xbb, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        115, //weight
        (u8*) 0x844e16e, //page0
        (u8*) 0x844e1d2, //page1
        0, //unused
        484, //poke scale
        18, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xc6, 0xc3, 0xc8, 0xc1, 0xbf, 0xc6, 0xff, 0x0, 0x0}, //category
        11, //height
        328, //weight
        (u8*) 0x844e1d3, //page0
        (u8*) 0x844e245, //page1
        0, //unused
        365, //poke scale
        7, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbf, 0xc2, 0xc7, 0xca, 0xcf, 0xca, 0xca, 0xbf, 0xff, 0x0, 0x0}, //category
        5, //height
        215, //weight
        (u8*) 0x844e246, //page0
        (u8*) 0x844e2b7, //page1
        0, //unused
        384, //poke scale
        18, //poke displace
        256, //trainer scale
        65533, //trainer displace
        0 //unused 2
    },
    {
        {0xc6, 0xbf, 0xc2, 0xc7, 0xca, 0xcf, 0xca, 0xca, 0xbf, 0xff, 0x0, 0x0}, //category
        15, //height
        1080, //weight
        (u8*) 0x844e2b8, //page0
        (u8*) 0x844e32f, //page1
        0, //unused
        256, //poke scale
        3, //poke displace
        280, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbf, 0xbf, 0xbb, 0xc8, 0xbf, 0xc7, 0xc9, 0xc8, 0xbf, 0xff, 0x0}, //category
        10, //height
        238, //weight
        (u8*) 0x844e330, //page0
        (u8*) 0x844e3bc, //page1
        0, //unused
        305, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcc, 0xbb, 0xc8, 0xc5, 0xc0, 0xf3, 0xcd, 0xcd, 0xbf, 0xcc, 0xff, 0x0}, //category
        15, //height
        604, //weight
        (u8*) 0x844e3bd, //page0
        (u8*) 0x844e426, //page1
        0, //unused
        275, //poke scale
        65535, //poke displace
        269, //trainer scale
        65535, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xcc, 0xbf, 0xbc, 0xcd, 0xcd, 0xbf, 0xc8, 0xc3, 0xc9, 0xcc, 0xff}, //category
        7, //height
        125, //weight
        (u8*) 0x844e427, //page0
        (u8*) 0x844e4a8, //page1
        0, //unused
        296, //poke scale
        4, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xc3, 0xc6, 0xbe, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        15, //height
        682, //weight
        (u8*) 0x844e4a9, //page0
        (u8*) 0x844e528, //page1
        0, //unused
        312, //poke scale
        2, //poke displace
        271, //trainer scale
        65535, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xc3, 0xcd, 0xbd, 0xc2, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        74, //weight
        (u8*) 0x844e529, //page0
        (u8*) 0x844e5ab, //page1
        0, //unused
        423, //poke scale
        3, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd4, 0xbb, 0xcc, 0xce, 0xc2, 0xbf, 0xc3, 0xce, 0xff, 0x0, 0x0, 0x0}, //category
        62, //height
        1620, //weight
        (u8*) 0x844e5ac, //page0
        (u8*) 0x844e60c, //page1
        0, //unused
        282, //poke scale
        65535, //poke displace
        382, //trainer scale
        7, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xbf, 0xce, 0xce, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        3, //height
        8, //weight
        (u8*) 0x844e60d, //page0
        (u8*) 0x844e689, //page1
        0, //unused
        435, //poke scale
        65531, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc0, 0xbb, 0xcc, 0xbc, 0xbf, 0xc8, 0xcd, 0xca, 0xc3, 0xbf, 0xc6, 0xff}, //category
        10, //height
        220, //weight
        (u8*) 0x844e68a, //page0
        (u8*) 0x844e6fb, //page1
        0, //unused
        316, //poke scale
        8, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xca, 0xcf, 0xca, 0xca, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        6, //height
        23, //weight
        (u8*) 0x844e6fc, //page0
        (u8*) 0x844e76f, //page1
        0, //unused
        440, //poke scale
        65533, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xbb, 0xcc, 0xc3, 0xc9, 0xc8, 0xbf, 0xce, 0xce, 0xbf, 0xff, 0x0}, //category
        11, //height
        125, //weight
        (u8*) 0x844e770, //page0
        (u8*) 0x844e7f0, //page1
        0, //unused
        262, //poke scale
        9, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcc, 0xbf, 0xcb, 0xcf, 0xc3, 0xbf, 0xc7, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        8, //height
        150, //weight
        (u8*) 0x844e7f1, //page0
        (u8*) 0x844e863, //page1
        0, //unused
        376, //poke scale
        13, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xc3, 0xc8, 0xc5, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        16, //height
        306, //weight
        (u8*) 0x844e864, //page0
        (u8*) 0x844e8d1, //page1
        0, //unused
        256, //poke scale
        2, //poke displace
        299, //trainer scale
        2, //trainer displace
        0 //unused 2
    },
    {
        {0xc9, 0xbc, 0xcd, 0xce, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        20, //height
        1000, //weight
        (u8*) 0x844e8d2, //page0
        (u8*) 0x844e944, //page1
        0, //unused
        283, //poke scale
        65535, //poke displace
        371, //trainer scale
        6, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xc3, 0xc8, 0xbe, 0xcd, 0xca, 0xc3, 0xbf, 0xc6, 0xff, 0x0, 0x0}, //category
        6, //height
        10, //weight
        (u8*) 0x844e945, //page0
        (u8*) 0x844e9c6, //page1
        0, //unused
        505, //poke scale
        65532, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xbf, 0xcd, 0xbb, 0xcd, 0xce, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0}, //category
        12, //height
        470, //weight
        (u8*) 0x844e9c7, //page0
        (u8*) 0x844ea53, //page1
        0, //unused
        301, //poke scale
        1, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xce, 0xcc, 0xbb, 0xc2, 0xc6, 0xbf, 0xc5, 0xc3, 0xc8, 0xbe, 0xff}, //category
        6, //height
        140, //weight
        (u8*) 0x844ea54, //page0
        (u8*) 0x844eabb, //page1
        0, //unused
        453, //poke scale
        17, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbd, 0xc2, 0xc8, 0xbf, 0xbf, 0xc2, 0xcf, 0xce, 0xff, 0x0, 0x0}, //category
        7, //height
        168, //weight
        (u8*) 0x844eabc, //page0
        (u8*) 0x844eb42, //page1
        0, //unused
        380, //poke scale
        14, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbb, 0xc8, 0xce, 0xc6, 0xc3, 0xce, 0xd4, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        15, //height
        2565, //weight
        (u8*) 0x844eb43, //page0
        (u8*) 0x844ebc4, //page1
        0, //unused
        256, //poke scale
        3, //poke displace
        344, //trainer scale
        2, //trainer displace
        0 //unused 2
    },
    {
        {0xbb, 0xca, 0xca, 0xc6, 0xbb, 0xe9, 0xe7, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        8, //height
        395, //weight
        (u8*) 0x844ebc5, //page0
        (u8*) 0x844ec50, //page1
        0, //unused
        315, //poke scale
        15, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xca, 0xc3, 0xbf, 0xc6, 0xbc, 0xbb, 0xc6, 0xc6, 0xff, 0x0, 0x0}, //category
        11, //height
        876, //weight
        (u8*) 0x844ec51, //page0
        (u8*) 0x844ecd0, //page1
        0, //unused
        338, //poke scale
        12, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xcd, 0xbc, 0xcc, 0xbf, 0xbd, 0xc2, 0xbf, 0xcc, 0xff, 0x0}, //category
        14, //height
        1506, //weight
        (u8*) 0x844ecd1, //page0
        (u8*) 0x844ed55, //page1
        0, //unused
        305, //poke scale
        2, //poke displace
        277, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xc7, 0xcf, 0xcd, 0xbd, 0xc2, 0xbf, 0xc6, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        4, //height
        525, //weight
        (u8*) 0x844ed56, //page0
        (u8*) 0x844edb8, //page1
        0, //unused
        691, //poke scale
        22, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xce, 0xc3, 0xbf, 0xc0, 0xcd, 0xbf, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        17, //height
        270, //weight
        (u8*) 0x844edb9, //page0
        (u8*) 0x844ee35, //page1
        0, //unused
        307, //poke scale
        1, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xf3, 0xbe, 0xcd, 0xbf, 0xbf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        18, //height
        226, //weight
        (u8*) 0x844ee36, //page0
        (u8*) 0x844eea3, //page1
        0, //unused
        278, //poke scale
        5, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbc, 0xbf, 0xcd, 0xce, 0xbb, 0xc8, 0xbe, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        10, //height
        234, //weight
        (u8*) 0x844eea4, //page0
        (u8*) 0x844ef0b, //page1
        0, //unused
        316, //poke scale
        5, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcc, 0xbf, 0xc8, 0xbe, 0xbf, 0xd4, 0xd0, 0xc9, 0xcf, 0xcd, 0xff, 0x0}, //category
        6, //height
        87, //weight
        (u8*) 0x844ef0c, //page0
        (u8*) 0x844ef7d, //page1
        0, //unused
        371, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xce, 0xbf, 0xc3, 0xc8, 0xc2, 0xbb, 0xcf, 0xca, 0xce, 0xff, 0x0}, //category
        6, //height
        421, //weight
        (u8*) 0x844ef7e, //page0
        (u8*) 0x844efec, //page1
        0, //unused
        448, //poke scale
        17, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xcf, 0xcc, 0xbd, 0xc2, 0xcd, 0xce, 0xbf, 0xc2, 0xbf, 0xcc, 0xff}, //category
        11, //height
        1105, //weight
        (u8*) 0x844efed, //page0
        (u8*) 0x844f06b, //page1
        0, //unused
        311, //poke scale
        10, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xe6, 0xd5, 0xd7, 0xdc, 0xd9, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        15, //height
        1026, //weight
        (u8*) 0x844f06c, //page0
        (u8*) 0x844f0cd, //page1
        0, //unused
        272, //poke scale
        2, //poke displace
        307, //trainer scale
        0, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xcd, 0xbf, 0xc8, 0xc5, 0xcf, 0xc1, 0xbf, 0xc6, 0xff, 0x0}, //category
        6, //height
        952, //weight
        (u8*) 0x844f0ce, //page0
        (u8*) 0x844f143, //page1
        0, //unused
        414, //poke scale
        65535, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xcd, 0xbf, 0xc8, 0xc5, 0xc6, 0xbb, 0xcf, 0xbf, 0xff, 0x0}, //category
        12, //height
        2025, //weight
        (u8*) 0x844f144, //page0
        (u8*) 0x844f1e0, //page1
        0, //unused
        256, //poke scale
        3, //poke displace
        272, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xcd, 0xbf, 0xc8, 0xc0, 0xcf, 0xcd, 0xcd, 0xff, 0x0, 0x0}, //category
        16, //height
        5500, //weight
        (u8*) 0x844f1e1, //page0
        (u8*) 0x844f262, //page1
        0, //unused
        272, //poke scale
        3, //poke displace
        461, //trainer scale
        4, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xce, 0xbf, 0xc3, 0xc8, 0xc1, 0xc3, 0xca, 0xc0, 0xbf, 0xc6, 0xff}, //category
        17, //height
        2300, //weight
        (u8*) 0x844f263, //page0
        (u8*) 0x844f2f6, //page1
        0, //unused
        256, //poke scale
        1, //poke displace
        309, //trainer scale
        1, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xcd, 0xbc, 0xbf, 0xcc, 0xc1, 0xff, 0x0, 0x0, 0x0, 0x0}, //category
        18, //height
        1750, //weight
        (u8*) 0x844f2f7, //page0
        (u8*) 0x844f368, //page1
        0, //unused
        265, //poke scale
        0, //poke displace
        317, //trainer scale
        3, //trainer displace
        0 //unused 2
    },
    {
        {0xbf, 0xc3, 0xcd, 0xbf, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        19, //height
        2050, //weight
        (u8*) 0x844f369, //page0
        (u8*) 0x844f3f7, //page1
        0, //unused
        256, //poke scale
        0, //poke displace
        359, //trainer scale
        6, //trainer displace
        0 //unused 2
    },
    {
        {0xf1, 0xc9, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        14, //height
        400, //weight
        (u8*) 0x844f3f8, //page0
        (u8*) 0x844f47a, //page1
        0, //unused
        291, //poke scale
        2, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xf1, 0xc9, 0xc8, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        20, //height
        600, //weight
        (u8*) 0x844f47b, //page0
        (u8*) 0x844f4fc, //page1
        0, //unused
        273, //poke scale
        0, //poke displace
        313, //trainer scale
        3, //trainer displace
        0 //unused 2
    },
    {
        {0xcd, 0xbf, 0xbf, 0xc1, 0xcc, 0xf3, 0xc8, 0xbe, 0xc6, 0xbf, 0xcc, 0xff}, //category
        45, //height
        3520, //weight
        (u8*) 0x844f4fd, //page0
        (u8*) 0x844f57a, //page1
        0, //unused
        272, //poke scale
        1, //poke displace
        639, //trainer scale
        13, //trainer displace
        0 //unused 2
    },
    {
        {0xc5, 0xc9, 0xc8, 0xce, 0xc3, 0xc8, 0xbf, 0xc8, 0xce, 0xff, 0x0, 0x0}, //category
        35, //height
        9500, //weight
        (u8*) 0x844f57b, //page0
        (u8*) 0x844f5f3, //page1
        0, //unused
        276, //poke scale
        0, //poke displace
        530, //trainer scale
        12, //trainer displace
        0 //unused 2
    },
    {
        {0xc2, 0xc3, 0xc7, 0xc7, 0xbf, 0xc6, 0xc2, 0xc9, 0xbd, 0xc2, 0xff, 0x0}, //category
        70, //height
        2065, //weight
        (u8*) 0x844f5f4, //page0
        (u8*) 0x844f65b, //page1
        0, //unused
        286, //poke scale
        65535, //poke displace
        483, //trainer scale
        9, //trainer displace
        0 //unused 2
    },
    {
        {0xd1, 0xf3, 0xc8, 0xcd, 0xbd, 0xc2, 0xbf, 0xcc, 0xff, 0x0, 0x0, 0x0}, //category
        3, //height
        11, //weight
        (u8*) 0x844f65c, //page0
        (u8*) 0x844f6be, //page1
        0, //unused
        608, //poke scale
        65528, //poke displace
        256, //trainer scale
        65534, //trainer displace
        0 //unused 2
    },
    {
        {0xbe, 0xc8, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, //category
        17, //height
        608, //weight
        (u8*) 0x844f6bf, //page0
        (u8*) 0x844f73b, //page1
        0, //unused
        293, //poke scale
        0, //poke displace
        337, //trainer scale
        2, //trainer displace
        0 //unused 2
    }
};
