	.include "src/voicegroup/VoiceDef.s"

	.section .rodata
	.global voicegroup002
	.align	2

voicegroup002:

@**************** Voice 000 ****************@ Drums FR

		.byte	DrumTable
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	DrumTbl4
		.byte	0,0,0,0


@**************** Voice 001 ****************@ Piano FR

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678


@**************** Voice 002 ****************@   Piano DPP (high frequencies best)


	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr2
	.word	snd_2_split


@**************** Voice 003 ****************@


	.byte	KeySplit                        @Piano DPP (low frequencies best)
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr3
	.word	snd_3_split


@**************** Voice 004 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86ae154
		.byte	64,249,0,188


@**************** Voice 005 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86b07bc
		.byte	51,249,0,165


@**************** Voice 006 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x869ff04
		.byte	255,249,25,76


@**************** Voice 007 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a23cc
		.byte	255,165,51,242


@**************** Voice 008 ****************@ Music Box DPP

            .byte	KeySplit
            .byte	0x0
            .byte	0x0
            .byte	0x0
            .word	KeySplitInstr4
            .word	snd_4_split


@**************** Voice 009 ****************@ Electric Piano DPP

            .byte	KeySplit
            .byte	0x0
            .byte	0x0
            .byte	0x0
            .word	KeySplitInstr5
            .word	snd_5_split


@**************** Voice 010 ****************@ glockenspiel DPP

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_9_Global
	.byte	255, 240, 0, 226


@**************** Voice 011 ****************@


	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr12
	.word	snd_12_split


@**************** Voice 012 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr13
	.word	snd_13_split


@**************** Voice 013 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x8508f9c
		.byte	255,235,180,204


@**************** Voice 014 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x8501558
		.byte	255,165,90,216


@**************** Voice 015 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr14
	.word	snd_14_split


@**************** Voice 016 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a2a70
		.byte	128,160,175,165


@**************** Voice 017 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr15
	.word	snd_15_split


@**************** Voice 018 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr17
	.word	snd_17_split


@**************** Voice 019 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	snd_wave_church_organ
		.byte	255,76,154,188


@**************** Voice 020 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	snd_wave_reed_organ
		.byte	255,76,154,188


@**************** Voice 021 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x850bdd8
		.byte	64,188,108,165


@**************** Voice 022 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr18
	.word	snd_18_split


@**************** Voice 023 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_19_Global
	.byte	255, 0, 255, 189


@**************** Voice 024 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x869ff04
		.byte	255,249,25,76


@**************** Voice 025 ****************@


	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_20_Global
	.byte	255, 0, 255, 189


@**************** Voice 026 ****************@


	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr21
	.word	snd_21_split

@**************** Voice 027 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_22_Global
	.byte	64, 0, 255, 189


@**************** Voice 028 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_23_Global
	.byte	255, 0, 255, 0


@**************** Voice 029 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86a5c40
		.byte	128,0,255,214


@**************** Voice 030 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86a7ab0
		.byte	128,0,255,206


@**************** Voice 031 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86a1e74
		.byte	255,0,255,165


@**************** Voice 032 ****************@ E-Bass DPP

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr7
	.word	snd_7_split


@**************** Voice 033 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84e9270
		.byte	255,253,0,149


@**************** Voice 034 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr24
	.word	snd_24_split



@**************** Voice 035 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a3268
		.byte	255,253,0,188


@**************** Voice 036 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a4d6c
		.byte	255,252,0,115


@**************** Voice 037 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_25_Global
	.byte	255, 0, 255, 226

@**************** Voice 038 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_26_Global
	.byte	255, 0, 255, 226


@**************** Voice 039 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr27
	.word	snd_27_split


@**************** Voice 040 ****************@

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b5c
		.word	0x84a16c0


@**************** Voice 041 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_28_Global
	.byte	255, 0, 255, 240


@**************** Voice 042 ****************@

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	KeySplitCello
		.word	snd_cello_map


@**************** Voice 043 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr29
	.word	snd_29_split


@**************** Voice 044 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr30
	.word	snd_30_split


@**************** Voice 045 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84f17d4
		.byte	255,226,0,38


@**************** Voice 046 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x850856c
		.byte	255,242,0,242


@**************** Voice 047 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a59e0
		.byte	255,0,180,246


@**************** Voice 048 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr32
	.word	snd_32_split


@**************** Voice 049 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_33_Global
	.byte	255, 252, 51, 226


@**************** Voice 050 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_34_Global
	.byte	255, 252, 51, 226


@**************** Voice 051 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_35_Global
	.byte	255, 0, 255, 180


@**************** Voice 052 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a6eb0
		.byte	85,0,154,165


@**************** Voice 053 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_36_Global
	.byte	255, 0, 255, 226


@**************** Voice 054 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_37_Global
	.byte	255, 0, 255, 226


@**************** Voice 055 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_38_Global
	.byte	255, 0, 255, 226


@**************** Voice 056 ****************@

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b80
		.word	0x84a1708


@**************** Voice 057 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_39_Global
	.byte	255, 0, 255, 226


@**************** Voice 058 ****************@

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x84891a4
		.word	0x84a175c


@**************** Voice 059 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr40
	.word	snd_40_split


@**************** Voice 060 ****************@

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x84891bc
		.word	0x84a17a4


@**************** Voice 061 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86aaaa0
		.byte	255,0,255,209


@**************** Voice 062 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_41_Global
	.byte	255, 0, 255, 186


@**************** Voice 063 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_square_50
	.byte	255, 210, 127, 127


@**************** Voice 064 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a8560
		.byte	43,188,103,165


@**************** Voice 065 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_43_Global
	.byte	32, 0, 255, 226



@**************** Voice 066 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a8560
		.byte	43,188,103,165


@**************** Voice 067 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_44_Global
	.byte	32, 255, 0, 244

@**************** Voice 068 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr45
	.word	snd_45_split

@**************** Voice 069 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr46
	.word	snd_46_split


@**************** Voice 070 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr47
	.word	snd_47_split

@**************** Voice 071 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr48
	.word	snd_48_split


@**************** Voice 072 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84e8b0c
		.byte	255,127,231,127


@**************** Voice 073 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_49_Global
	.byte	255, 0, 255, 165


@**************** Voice 074 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_50_Global
	.byte	70, 0, 255, 127


@**************** Voice 075 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86b1b64
		.byte	255,191,97,165


@**************** Voice 076 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr51
	.word	snd_51_split


@**************** Voice 077 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_square_50
	.byte	255, 250, 127, 165


@**************** Voice 078 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86ad6f4
		.byte	255,0,255,127


@**************** Voice 079 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84e8b0c
		.byte	255,127,231,127


@**************** Voice 080 ****************@

		.byte	0x9
		.byte	0x3c
		.byte	0x0
		.byte	0x0
		.word	0x1
		.byte	0,2,3,4


@**************** Voice 081 ****************@

		.byte	0xa
		.byte	0x3c
		.byte	0x0
		.byte	0x0
		.word	0x3
		.byte	0,3,3,2


@**************** Voice 082 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_53_Global
	.byte	255, 0, 255, 127

@**************** Voice 083 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_54_Global
	.byte	255, 0, 255, 0


@**************** Voice 084 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_55_Global
	.byte	255, 248, 0, 165

@**************** Voice 085 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr56
	.word	snd_56_split


@**************** Voice 086 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr57
	.word	snd_57_split


@**************** Voice 087 ****************@

		.byte	KeySplit
		.byte	0x3c
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678


@**************** Voice 088 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr58
	.word	snd_58_split

@**************** Voice 089 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr59
	.word	snd_56_split


@**************** Voice 090 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr60
	.word	snd_60_split


@**************** Voice 091 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr61
	.word	snd_61_split


@**************** Voice 092 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_square_12
	.byte	255, 245, 120, 127

@**************** Voice 093 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_64_Global
	.byte	255, 253, 0, 189


@**************** Voice 094 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_65_Global
	.byte	255, 0, 255, 189


@**************** Voice 095 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr66
	.word	snd_32_split


@**************** Voice 096 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84feb7c
		.byte	255,0,255,127


@**************** Voice 097 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_square_50
	.byte	255, 245, 140, 165


@**************** Voice 098 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_68_Global
	.byte	255, 0, 255, 165


@**************** Voice 099 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_square_25
	.byte	32, 0, 255, 226

@**************** Voice 100 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_71_Global
	.byte	255, 240, 170, 226


@**************** Voice 101 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr73
	.word	snd_73_split


@**************** Voice 102 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_74_Global
	.byte	64, 247, 135, 127


@**************** Voice 103 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84f7538
		.byte	255,0,255,127


@**************** Voice 104 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_75_Global
	.byte	32, 0, 255, 165


@**************** Voice 105 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_76_Global
	.byte	100, 0, 255, 165


@**************** Voice 106 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_77_Global
	.byte	255, 0, 255, 165


@**************** Voice 107 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_78_Global
	.byte	80, 240, 95, 180



@**************** Voice 108 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_80_Global
	.byte	255, 0, 255, 127


@**************** Voice 109 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_81_Global
	.byte	255, 0, 255, 127

@**************** Voice 110 ****************@

	.byte	DirectSound
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_square_50
	.byte	255, 0, 170, 0


@**************** Voice 111 ****************@

	.byte	ProgWave
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	snd_square_50_wave
	.byte	0x0, 0x0, 0xF, 0x0


@**************** Voice 112 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a59e0
		.byte	255,0,180,246


@**************** Voice 113 ****************@


	.byte	SquareWave2
	.byte	Cn3
	.byte	0x0
	.byte	0x0
	.word	WaveDuty50
	.byte	0x0, 0x0, 0xF, 0x0


@**************** Voice 114 ****************@

	.byte	KeySplit
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	KeySplitInstr105
	.word	snd_105_split


@**************** Voice 115 ****************@

		.byte	DrumTable
		.byte	0x3c
		.byte	0x0
		.byte	0x0
		.word	0x84886f4
		.byte	0,0,0,0


@**************** Voice 116 ****************@

	.byte	DrumTable
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	DrumTbl1
	.byte	0x0, 0x0, 0x0, 0x0

@**************** Voice 117 ****************@

	.byte	DrumTable
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.word	DrumTbl2
	.byte	0x0, 0x0, 0x0, 0x0


@**************** Voice 118 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a59e0
		.byte	255,0,180,246


@**************** Voice 119 ****************@

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84b4b68
		.byte	8,0,255,216


@**************** Voice 120 ****************@

		.byte	DrumTable
		.byte	0x3c
		.byte	0x0
		.byte	0x0
		.word	0x84886f4
		.byte	0,0,0,0


@**************** Voice 121 ****************@

		.byte	DrumTable
		.byte	0x3c
		.byte	0x0
		.byte	0x0
		.word	0x08488598
		.byte	0,2,6,0


@**************** Voice 122 ****************@

		.byte	0xc
		.byte	0x3c
		.byte	0x0
		.byte	0x0
		.word	0x0
		.byte	0,2,6,0


@**************** Voice 123 ****************@

		.byte	0xc
		.byte	0x3c
		.byte	0x0
		.byte	0x0
		.word	0x0
		.byte	0,2,6,0


@**************** Voice 124 ****************@

		.byte	0xa
		.byte	0x3c
		.byte	0x0
		.byte	0x0
		.word	0x1
		.byte	0,1,4,0


@**************** Voice 125 ****************@

		.byte	0xc
		.byte	0x3c
		.byte	0x0
		.byte	0x0
		.word	0x0
		.byte	0,2,6,0


@**************** Voice 126 ****************@

		.byte	0xc
		.byte	0x3c
		.byte	0x0
		.byte	0x0
		.word	0x0
		.byte	0,2,6,0


@**************** Voice 127 ****************@

		.byte	0xc
		.byte	0x3c
		.byte	0x0
		.byte	0x0
		.word	0x0
		.byte	0,1,3,2
