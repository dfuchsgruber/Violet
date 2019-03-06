#include "types.h"
#include "music.h"

song song_table[] = {
	//Song 0
	{(void*) 0x86b3c64, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 1
	{(void*) 0x86b3c84, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 2
	{(void*) 0x86b3cb0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 3
	{(void*) 0x86b3cd4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 4
	{(void*) 0x86b3d18, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 5
	{(void*) 0x86b3d44, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 6
	{(void*) 0x86b3d60, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 7
	{(void*) 0x86b3d7c, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 8
	{(void*) 0x86b3d98, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 9
	{(void*) 0x86b3dcc, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 10
	{(void*) 0x86b3df0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 11
	{(void*) 0x86b3e0c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 12
	{(void*) 0x86b3e38, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 13
	{(void*) 0x86b3e84, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 14
	{(void*) 0x86b3f00, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 15
	{(void*) 0x86b3f54, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 16
	{(void*) 0x86b3fa8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 17
	{(void*) 0x86b3ff8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 18
	{(void*) 0x86b4014, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 19
	{(void*) 0x86b4068, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 20
	{(void*) 0x86b40b0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 21
	{(void*) 0x86b40dc, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 22
	{(void*) 0x86b4100, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 23
	{(void*) 0x86b4124, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 24
	{(void*) 0x86b41a8, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 25
	{(void*) 0x86b41d4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 26
	{(void*) 0x86b4204, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 27
	{(void*) 0x86b4384, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 28
	{(void*) 0x86b43a8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 29
	{(void*) 0x86b43cc, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 30
	{(void*) 0x86b43f0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 31
	{(void*) 0x86b4420, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 32
	{(void*) 0x86b4444, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 33
	{(void*) 0x86b4490, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 34
	{(void*) 0x86b44c8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 35
	{(void*) 0x86b451c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 36
	{(void*) 0x86b4558, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 37
	{(void*) 0x86b45b0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 38
	{(void*) 0x86b45f4, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 39
	{(void*) 0x86b4630, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 40
	{(void*) 0x86b4670, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 41
	{(void*) 0x86b469c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 42
	{(void*) 0x86b46d8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 43
	{(void*) 0x86b4784, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 44
	{(void*) 0x86b47fc, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 45
	{(void*) 0x86b4828, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 46
	{(void*) 0x86b485c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 47
	{(void*) 0x86b4888, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 48
	{(void*) 0x86b48cc, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 49
	{(void*) 0x86b48f8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 50
	{(void*) 0x86b4924, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 51
	{(void*) 0x86b4950, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 52
	{(void*) 0x86b497c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 53
	{(void*) 0x86b49d0, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 54
	{(void*) 0x86b4a14, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 55
	{(void*) 0x86b4a48, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 56
	{(void*) 0x86b4a80, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 57
	{(void*) 0x86b4ab8, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 58
	{(void*) 0x86b4af0, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 59
	{(void*) 0x86b4b28, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 60
	{(void*) 0x86b4b60, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 61
	{(void*) 0x86b4b98, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 62
	{(void*) 0x86b4bd0, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 63
	{(void*) 0x86b4c04, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 64
	{(void*) 0x86b4c28, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 65
	{(void*) 0x86b4c74, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 66
	{(void*) 0x86b4cd4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 67
	{(void*) 0x86b4d08, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 68
	{(void*) 0x86b4d38, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 69
	{(void*) 0x86b4d70, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 70
	{(void*) 0x86b4db4, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 71
	{(void*) 0x86b4de4, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 72
	{(void*) 0x86b4e0c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 73
	{(void*) 0x86b4e74, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 74
	{(void*) 0x86b4eb0, SONG_PLAYER_3, SONG_PLAYER_3},
	//Song 75
	{(void*) 0x86b4ef0, SONG_PLAYER_3, SONG_PLAYER_3},
	//Song 76
	{(void*) 0x86b4f2c, SONG_PLAYER_3, SONG_PLAYER_3},
	//Song 77
	{(void*) 0x86b4f6c, SONG_PLAYER_3, SONG_PLAYER_3},
	//Song 78
	{(void*) 0x86b4fa8, SONG_PLAYER_3, SONG_PLAYER_3},
	//Song 79
	{(void*) 0x86b4fe8, SONG_PLAYER_3, SONG_PLAYER_3},
	//Song 80
	{(void*) 0x86b5050, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 81
	{(void*) 0x86b50a0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 82
	{(void*) 0x86b50dc, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 83
	{(void*) 0x86b510c, SONG_PLAYER_3, SONG_PLAYER_3},
	//Song 84
	{(void*) 0x86b5158, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 85
	{(void*) 0x86b517c, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 86
	{(void*) 0x86b51d0, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 87
	{(void*) 0x86b5264, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 88
	{(void*) 0x86b52a0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 89
	{(void*) 0x86b52c4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 90
	{(void*) 0x86b5328, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 91
	{(void*) 0x86b5390, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 92
	{(void*) 0x86b53b8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 93
	{(void*) 0x86b53ec, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 94
	{(void*) 0x86b5418, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 95
	{(void*) 0x86b5494, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 96
	{(void*) 0x86b5554, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 97
	{(void*) 0x86b563c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 98
	{(void*) 0x86b5754, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 99
	{(void*) 0x86b5778, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 100
	{(void*) 0x86b588c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 101
	{(void*) 0x86b58b8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 102
	{(void*) 0x86b58ec, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 103
	{(void*) 0x86b5950, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 104
	{(void*) 0x86b59b8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 105
	{(void*) 0x86b5bb4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 106
	{(void*) 0x86b5c40, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 107
	{(void*) 0x86b5c90, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 108
	{(void*) 0x86b5cbc, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 109
	{(void*) 0x86b5cdc, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 110
	{(void*) 0x86b5d18, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 111
	{(void*) 0x86b5dac, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 112
	{(void*) 0x86b5e18, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 113
	{(void*) 0x86b5e60, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 114
	{(void*) 0x86b5f24, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 115
	{(void*) 0x86b5f78, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 116
	{(void*) 0x86b5ff8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 117
	{(void*) 0x86b6030, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 118
	{(void*) 0x86b6064, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 119
	{(void*) 0x86b60a4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 120
	{(void*) 0x86b611c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 121
	{(void*) 0x86b619c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 122
	{(void*) 0x86b61f4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 123
	{(void*) 0x86b6298, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 124
	{(void*) 0x86b62e4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 125
	{(void*) 0x86b6360, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 126
	{(void*) 0x86b63ac, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 127
	{(void*) 0x86b63e0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 128
	{(void*) 0x86b642c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 129
	{(void*) 0x86b648c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 130
	{(void*) 0x86b64d8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 131
	{(void*) 0x86b655c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 132
	{(void*) 0x86b65b0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 133
	{(void*) 0x86b667c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 134
	{(void*) 0x86b671c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 135
	{(void*) 0x86b6758, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 136
	{(void*) 0x86b67a4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 137
	{(void*) 0x86b6828, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 138
	{(void*) 0x86b6898, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 139
	{(void*) 0x86b696c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 140
	{(void*) 0x86b6a10, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 141
	{(void*) 0x86b6a80, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 142
	{(void*) 0x86b6af4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 143
	{(void*) 0x86b6bd4, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 144
	{(void*) 0x86b6c10, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 145
	{(void*) 0x86b6c78, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 146
	{(void*) 0x86b6cf4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 147
	{(void*) 0x86b6d40, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 148
	{(void*) 0x86b6d88, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 149
	{(void*) 0x86b6df0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 150
	{(void*) 0x86b6e8c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 151
	{(void*) 0x86b6ff0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 152
	{(void*) 0x86b7058, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 153
	{(void*) 0x86b709c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 154
	{(void*) 0x86b7118, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 155
	{(void*) 0x86b7184, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 156
	{(void*) 0x86b7204, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 157
	{(void*) 0x86b7284, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 158
	{(void*) 0x86b7320, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 159
	{(void*) 0x86b736c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 160
	{(void*) 0x86b73ac, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 161
	{(void*) 0x86b7424, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 162
	{(void*) 0x86b7460, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 163
	{(void*) 0x86b74b8, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 164
	{(void*) 0x86b7580, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 165
	{(void*) 0x86b7674, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 166
	{(void*) 0x86b7784, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 167
	{(void*) 0x86b780c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 168
	{(void*) 0x86b7854, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 169
	{(void*) 0x86b78b4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 170
	{(void*) 0x86b7900, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 171
	{(void*) 0x86b7988, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 172
	{(void*) 0x86b7a44, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 173
	{(void*) 0x86b7a9c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 174
	{(void*) 0x86b7b18, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 175
	{(void*) 0x86b7be0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 176
	{(void*) 0x86b7c9c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 177
	{(void*) 0x86b7d88, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 178
	{(void*) 0x86b7dc8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 179
	{(void*) 0x86b7e24, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 180
	{(void*) 0x86b7e5c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 181
	{(void*) 0x86b7f10, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 182
	{(void*) 0x86b7fb0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 183
	{(void*) 0x86b8018, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 184
	{(void*) 0x86b813c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 185
	{(void*) 0x86b81b8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 186
	{(void*) 0x86b8214, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 187
	{(void*) 0x86b824c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 188
	{(void*) 0x86b829c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 189
	{(void*) 0x86b8328, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 190
	{(void*) 0x86b838c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 191
	{(void*) 0x86b8404, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 192
	{(void*) 0x86b846c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 193
	{(void*) 0x86b85c0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 194
	{(void*) 0x86b8694, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 195
	{(void*) 0x86b87a4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 196
	{(void*) 0x86b8888, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 197
	{(void*) 0x86b8968, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 198
	{(void*) 0x86b89b4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 199
	{(void*) 0x86b8a40, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 200
	{(void*) 0x86b8bd0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 201
	{(void*) 0x86b8d70, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 202
	{(void*) 0x86b8de0, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 203
	{(void*) 0x86b8e30, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 204
	{(void*) 0x86b8f54, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 205
	{(void*) 0x86b8fd4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 206
	{(void*) 0x86b90c4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 207
	{(void*) 0x86b9128, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 208
	{(void*) 0x86b9184, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 209
	{(void*) 0x86b9238, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 210
	{(void*) 0x86b9434, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 211
	{(void*) 0x86b9554, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 212
	{(void*) 0x86b96c4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 213
	{(void*) 0x86b9734, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 214
	{(void*) 0x86b97cc, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 215
	{(void*) 0x86b9804, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 216
	{(void*) 0x86b98dc, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 217
	{(void*) 0x86b99b4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 218
	{(void*) 0x86b9a60, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 219
	{(void*) 0x86b9af8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 220
	{(void*) 0x86b9b90, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 221
	{(void*) 0x86b9c38, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 222
	{(void*) 0x86b9c84, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 223
	{(void*) 0x86b9d80, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 224
	{(void*) 0x86b9e14, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 225
	{(void*) 0x86b9e78, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 226
	{(void*) 0x86b9f14, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 227
	{(void*) 0x86ba11c, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 228
	{(void*) 0x86ba218, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 229
	{(void*) 0x86ba308, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 230
	{(void*) 0x86ba38c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 231
	{(void*) 0x86ba400, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 232
	{(void*) 0x86ba580, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 233
	{(void*) 0x86ba684, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 234
	{(void*) 0x86ba6e4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 235
	{(void*) 0x86ba754, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 236
	{(void*) 0x86ba870, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 237
	{(void*) 0x86ba914, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 238
	{(void*) 0x86baa84, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 239
	{(void*) 0x86babb8, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 240
	{(void*) 0x86bac3c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 241
	{(void*) 0x86bac94, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 242
	{(void*) 0x86bacc4, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 243
	{(void*) 0x86bacfc, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 244
	{(void*) 0x86bad88, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 245
	{(void*) 0x86badc0, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 246
	{(void*) 0x86bae04, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 247
	{(void*) 0x86bae44, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 248
	{(void*) 0x86bae6c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 249
	{(void*) 0x86baf24, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 250
	{(void*) 0x86baf98, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 251
	{(void*) 0x86bb004, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 252
	{(void*) 0x86bb04c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 253
	{(void*) 0x86bb12c, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 254
	{(void*) 0x86bb1ec, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 255
	{(void*) 0x86bb220, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 256
	{(void*) 0x86bb2dc, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 257
	{(void*) 0x86bb3bc, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 258
	{(void*) 0x86bb508, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 259
	{(void*) 0x86bb6a4, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 260
	{(void*) 0x86bb97c, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 261
	{(void*) 0x86bbb08, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 262
	{(void*) 0x86bbbe0, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 263
	{(void*) 0x86bbc4c, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 264
	{(void*) 0x86bc1bc, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 265
	{mus_rin_battle, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 266
	{(void*) 0x86be08c, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 267
	{(void*) 0x86be3e4, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 268
	{(void*) 0x86be604, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 269
	{(void*) 0x86be744, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 270
	{(void*) 0x86be828, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 271
	{(void*) 0x86be920, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 272
	{(void*) 0x86bee08, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 273
	{(void*) 0x86bfd44, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 274
	{mus_encounter_violet, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 275
	{(void*) 0x86c2374, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 276
	{mus_deoxys_battle, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 277
	{(void*) 0x86c310c, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 278
	{mus_titlescreen, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 279
	{(void*) 0x86c5054, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 280
	{mus_ceometria, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 281
	{(void*) 0x86c5dd4, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 282
	{mus_riding_cloud, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 283
	{mus_encounter_beethoven, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 284
	{mus_encounter_staccato, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 285
	{mus_encounter_cello, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 286
	{(void*) 0x86c80c4, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 287
	{mus_silvania_forest, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 288
	{(void*) 0x86ca72c, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 289
	{(void*) 0x86cb968, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 290
	{(void*) 0x86cf978, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 291
	{mus_new_day, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 292
	{mus_melancholy, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 293
	{mus_windy, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 294
	{(void*) 0x86d2920, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 295
	{(void*) 0x86d3660, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 296
	{mus_gym_leader, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 297
	{mus_trainer_battle, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 298
	{mus_wild_battle, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 299
	{(void*) 0x8a0086c, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 300
	{mus_amonia2, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 301
	{mus_jorney, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 302
	{(void*) 0x86dcf90, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 303
	{mus_pokecenter, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 304
	{(void*) 0x86dec94, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 305
	{(void*) 0x86df60c, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 306
	{(void*) 0x86dfed8, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 307
	{mus_violet_headquarter, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 308
	{mus_orina_city, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 309
	{mus_inferior, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 310
	{mus_victory_trainer, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 311
	{(void*) 0x86e4240, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 312
	{(void*) 0x86e5130, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 313
	{mus_kaskada_unused, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 314
	{mus_meriana_city, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 315
	{mus_encounter_rival, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 316
	{(void*) 0x86e7e44, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 317
	{(void*) 0x86e8044, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 318
	{(void*) 0x86e8244, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 319
	{(void*) 0x86e85b4, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 320
	{(void*) 0x86e8724, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 321
	{(void*) 0x86e9028, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 322
	{(void*) 0x86e9460, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 323
	{(void*) 0x86e94ec, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 324
	{(void*) 0x86e96bc, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 325
	{(void*) 0x86e9778, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 326
	{(void*) 0x86ea6ec, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 327
	{mus_volcano, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 328
	{mus_darkness, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 329
	{mus_groudon_rise, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 330
	{mus_summit, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 331
	{mus_cave, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 332
	{(void*) 0x8a0be4c, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 333
	{(void*) 0x86efc24, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 334
	{mus_asterisk_castle, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 335
	{mus_silvania, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 336
	{mus_aktania, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 337
	{(void*) 0x86f3c8c, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 338
	{(void*) 0x86f3e50, SONG_TYPE_FANFARE, SONG_TYPE_FANFARE},
	//Song 339
	{(void*) 0x86f3fa0, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 340
	{(void*) 0x86f7150, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 341
	{(void*) 0x86f8408, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 342
	{(void*) 0x86f884c, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 343
	{(void*) 0x86f9194, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 344
	{(void*) 0x86f9b94, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 345
	{(void*) 0x86fa3d4, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 346
	{(void*) 0x86fa4b0, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 347
	{mus_battle_violet, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 348
	{sound_step, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 349
	{mus_jeropardy, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 350
	{mus_trainerschool, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 351
	{mus_rival_battle, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 352
	{mus_desert, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 353
	{mus_revolution_battle, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 354
	{mus_kaskada, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 355
	{mus_revolution, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 356
	{mus_magmatic, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 357
	{mus_fur_elise, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 358
	{mus_dimensional_traveler, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 359
	{mus_queen_of_darkness_battle, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 360
	{mus_consuming_darkness, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 361
	{mus_blackbeard, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 362
	{mus_criminal_intentions, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 363
	{mus_mistral, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 364
	{mus_sky, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 365
	{mus_violet_sphere_v1, SONG_TYPE_SONG, SONG_TYPE_SONG},
	//Song 366
	{sound_hint, SONG_TYPE_SOUND, SONG_TYPE_SOUND},
	//Song 367
	{mus_mistral_battle, SONG_TYPE_SONG, SONG_TYPE_SONG},
  //Song 368
  {mus_monumental, SONG_TYPE_SONG, SONG_TYPE_SONG},
  //Song 369
  {mus_route_7, SONG_TYPE_SONG, SONG_TYPE_SONG},
  //Song 370
  {mus_glyphs, SONG_TYPE_SONG, SONG_TYPE_SONG},
  // Song 371
  {mus_riding_cloud, SONG_TYPE_SONG, SONG_TYPE_SONG},
	// Song 372, (=0x174)
  {mus_gymleader_new, SONG_TYPE_SONG, SONG_TYPE_SONG},
        

};
