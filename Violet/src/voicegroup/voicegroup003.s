	.include "src/voicegroup/VoiceDef.s"

	.section .rodata
	.global voicegroup003
	.align	2

voicegroup003:
@**************** Voice 0 ****************@ Standard Drum Kit

		.byte	DrumTable
		.byte	0x3c
		.byte	0x0
		.byte	0x0
		.word	0x08488598
		.word   0
        
    

@**************** Voice 1 ****************@ Piano

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 2 ****************@ Modulated Synth 

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84fcba0
		.byte	255, 178, 180, 165
        
    

@**************** Voice 3 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 4 ****************@ E Piano 1 64_249_0_188

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86ae154
		.byte	64,249,0,188
		@ alternative envelopes
		@ .byte 255, 249, 0, 165
		@ .byte 128, 180, 108, 209
		@ .byte 255, 188, 128, 226
		@ .byte 255, 165, 180, 165
        
    

@**************** Voice 5 ****************@ E - Piano 2 255_204_77_246
		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86b07bc
		.byte	51,249,0,165
		@ alternative envelopes
		@ .byte 64, 188, 108, 244
		@ .byte 128, 204, 77, 246
		@ .byte 255, 204, 77, 246
		@ .byte 255, 188, 103, 165
		@ .byte 85, 204, 77, 246
		@ .byte 255, 137, 154, 165

        
@**************** Voice 6 ****************@ Harpsichord

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	KeySplitHarpsichord
		.word	snd_harpsichord_map
        
    

@**************** Voice 7 ****************@ E Piano 1 255_249_0_165

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86ae154
		.byte	255, 249, 0, 165
		@ alternative envelopes
        
    

@**************** Voice 8 ****************@ E - Piano 2  255_204_77_246
		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86b07bc
		.byte	255, 204, 77, 246
        
    

@**************** Voice 9 ****************@ Glockenspiel

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a23cc
		.byte	255,165,51,242
		@ alternative envelopes
		@ .byte 255, 165, 51, 235
		@ .byte 255, 204, 51, 242


@**************** Voice 10 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 11 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 12 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 13 ****************@ Xylophone

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x8508f9c
		.byte	255,235,180,204
		@ alternative envelopes
		@ .byte	255,235,0,204
		@ .byte 255,204,103,165
        
    

@**************** Voice 14 ****************@ Tubular Bells

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x8501558
		.byte	255,165,90,216
		@ alternative envelopes
		@ .byte 255, 165, 97, 236
        
    

@**************** Voice 15 ****************@ Synth square

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84ecd9c
		.byte	255, 226, 0, 127
		@ alternative envelopes
		@ .byte 255, 0, 255, 165
		@ .byte 255, 226, 0, 165
		@ .byte 255, 0, 255, 127
        
    

@**************** Voice 16 ****************@ percussive organ 128_160_175_165

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a2a70
		.byte	128,160,175,165
		@ alternative envelopes
		@ .byte 37, 165, 103, 127
		@ .byte 64, 188, 128, 201
		@ .byte 128, 146, 190, 115
		@ .byte 51, 0, 203, 127
		@ .byte 64, 195, 92, 235
		@ .byte 128, 123, 146, 165
		@ .byte 128, 118, 146, 137
		@ .byte 128, 108, 146, 137
		@ .byte 128, 103, 127, 201
		@ .byte 128, 175, 160, 165
		@ .byte 255, 133, 76, 137
		@ .byte 85, 188, 92, 165
		@ .byte 255, 0, 255, 127
		@ .byte 255, 0, 255, 210
		@ .byte 85, 180, 127, 165
        
    
@**************** Voice 17 ****************@ Percussive Organ 255_0_255_127

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a2a70
		.byte	255, 0, 255, 127
        
    

@**************** Voice 18 ****************@ Percussive Organ 37_165_103_127

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a2a70
		.byte	37, 165, 103, 127
        
    

@**************** Voice 19 ****************@ Church Organ

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	snd_wave_church_organ
		.byte	255,76,154,188
        
    

@**************** Voice 20 ****************@ Reed Organ

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	snd_wave_reed_organ
		.byte	255,76,154,188
        
    

@**************** Voice 21 ****************@ Accordion 64_188_108_165

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x850bdd8
		.byte	64,188,108,165
        @ alternative envelopes
		@ .byte	85, 137, 180, 204
		@ .byte 37, 127, 77, 165
		@ .byte 255, 0, 255, 165
    

@**************** Voice 22 ****************@ Accordion 85_137_180_204

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x850bdd8
		.byte	255, 0, 255, 165
        
    

@**************** Voice 23 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 24 ****************@ Accustic Guitar (nylon) 255_249_25_76

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x869ff04
		.byte	255,249,25,76
		@ alternative envelopes
		@ .byte 128, 204, 103, 226
		@ .byte 64, 195, 103, 220
		@ .byte 85, 249, 25, 226
		@ .byte 255, 249, 25, 0
		@ .byte 85, 165, 154, 127
		@ .byte 255, 165, 128, 204
		@ .byte 128, 249, 25, 127
		@ .byte 64, 249, 25, 226
		@ .byte 51, 204, 92, 226
		@ .byte 255, 165, 154, 165
		@ .byte 255, 249, 25, 127
		@ .byte 85, 249, 25, 127
		@ .byte 255, 204, 92, 226
		@ .byte 64, 216, 51, 224


@**************** Voice 25 ****************@ Acoustic Guitar (nylon) 64_195_103_220

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x869ff04
		.byte	64, 195, 103, 220
        
    

@**************** Voice 26 ****************@ Acoustic Guitar (nylon) 128_249_25_127

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x869ff04
		.byte	128, 249, 25, 127
        
    

@**************** Voice 27 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 28 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 29 ****************@ Low E-Guitar 128_0_255_214

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86a5c40
		.byte	128,0,255,214
		@ alternative envelopes
		@ .byte	128,195,72,127
		@ .byte	255,0,255,127
        
    

@**************** Voice 30 ****************@ Distortion Guitar 255_0_255_206

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86a7ab0
		.byte	128,0,255,206
		@ alternative envelopes
		@ .byte 255, 0, 255, 127
		@ .byte 255, 165, 154, 165
		@ .byte 85, 188, 103, 160
        
    

@**************** Voice 31 ****************@ E-Guitar Harmonics
	
		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86a1e74
		.byte	255,0,255,165
        
    

@**************** Voice 32 ****************@ Low E-Guitar  255_0_255_127

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86a5c40
		.byte	255,0,255,127
        
    

@**************** Voice 33 ****************@ Electric Bass (Finger)

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84e9270
		.byte	255,253,0,149
		@ alternative envelopes
		@ .byte 255, 204, 113, 235
        
    

@**************** Voice 34 ****************@ Distortion Guitar 255_0_255_127

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86a7ab0
		.byte	255, 0, 255, 127
        
    

@**************** Voice 35 ****************@ Fretless Bass

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a3268
		.byte	255,253,0,188
		@ alternative envelopes
		@ .byte 255,253,0,216
        
    

@**************** Voice 36 ****************@ EMPTY
		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84ab65c
		.byte	255, 165, 180, 216
        
    

@**************** Voice 37 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 38 ****************@ Synth Bass 255_252_0_115

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a4d6c
		.byte	255,252,0,115
		@ alternative envelopes
        @ .byte	255,252,0,165
		@ .byte	128,188,77,115
    

@**************** Voice 39 ****************@ Synth Bass 128_188_77_115

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a4d6c
		.byte	128,188,77,115
        
    

@**************** Voice 40 ****************@ Violin

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b5c
		.word	0x84a16c0
        
    

@**************** Voice 41 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 42 ****************@ Cello

	
		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	KeySplitCello
		.word	snd_cello_map
        
    

@**************** Voice 43 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 44 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 45 ****************@ Pizzicato Strings

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84f17d4
		.byte	255,226,0,38
        
    

@**************** Voice 46 ****************@ Orchestral Strings

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x850856c
		.byte	255,242,0,242
		@ alternative envelopes
		@ .byte 255, 242, 0, 204
		@ .byte 255, 246, 0, 235
		@ .byte 255, 242, 51, 242
		@ .byte 255, 242, 51, 226
        
    

@**************** Voice 47 ****************@ Timpani 255_0_180_246

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a59e0
		.byte	255,0,180,246
		@ alternative envelopes
		@ .byte 255, 127, 154, 235
		@ .byte 255, 165, 154, 235
		@ .byte 255, 0, 193, 153
		@ .byte 255, 0, 193, 76
		@ .byte 255, 0, 193, 127
		@ .byte 255, 246, 0, 226
		@ .byte 255, 165, 154, 153
        

@**************** Voice 48 ****************@ Timpani 255_127_154_235
        
		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a59e0
		.byte 255, 127, 154, 235
    

@**************** Voice 49 **************** @ Timpani 255_246_0_226

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a59e0
		.byte	255, 246, 0, 226
        
    

@**************** Voice 50 ****************@ Timpani 255_0_193_76

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a59e0
		.byte	255, 0, 193, 76
        
    

@**************** Voice 51 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
    

@**************** Voice 52 ****************@ Timpani with Hit

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84eaec0
		.byte	255,246,0, 226
        
    

@**************** Voice 53 ****************@ Voice Oohs 85_0_156_165

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a6eb0
		.byte	85,0,154,165
		@ alternative envelopes
		@ .byte 255, 0, 255, 0
        
    

@**************** Voice 54 ****************@ Voice Oohs 255_0_255_0

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a6eb0
		.byte	255, 0, 255, 0
        
    

@**************** Voice 55 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 56 ****************@ Trumpet

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b80
		.word	0x84a1708
        
    

@**************** Voice 57 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 58 ****************@ Tuba

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x84891a4
		.word	0x84a175c
        
    

@**************** Voice 59 ****************@ Ship Horn

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x869e464
		.byte	255,0,206, 204
    

@**************** Voice 60 ****************@ French Horn

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x84891bc
		.word	0x84a17a4
        
    

@**************** Voice 61 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 62 ****************@ E-Guitar 255_0_255_209

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86aaaa0
		.byte	255,0,255,209
        @ alternative envelopes
		@ .byte	255,0,255,127
		@ .byte 255,165,180,165
		@ .byte 255,175,154,127
		@ .byte 255,0,236,188
    

@**************** Voice 63 ****************@ E-Guitar 255_165_180_165

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86aaaa0
		.byte	255,165,180,165
        
    

@**************** Voice 64 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 65 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 66 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 67 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 68 ****************@ Oboe

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a8560
		.byte	43,188,103,165
        
    

@**************** Voice 69 ****************@ English Horn

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a98a4
		.byte 43, 165, 103, 165 @ envelope
        
    

@**************** Voice 70 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 71 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 72 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 73 ****************@ Flute 255_127_231_127
	
		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84e8b0c
		.byte	255,127,231,127
		@ alternative envelopes
		@ .byte 255, 0, 255, 165
        
    

@**************** Voice 74 ****************@ Flute 255_0_255_165

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84e8b0c
		.byte	255, 0, 255, 165
        
    

@**************** Voice 75 ****************@ Pan Flute

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86b1b64
		.byte	255,191,97,165
        
    

@**************** Voice 76 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 77 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 78 ****************@ Whistle 255_0_255_127

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86ad6f4
		.byte	255,0,255,127
		@ alternative envelopes
		@ .byte 43, 76, 103, 216
		@ .byte 85, 204, 77, 127
        
    

@**************** Voice 79 ****************@ Whistle 43_76_103_216

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86ad6f4
		.byte	43, 76, 103, 216
        
    

@**************** Voice 80 ****************@ Square 1 Duty 12%

		.byte	SquareWave1
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	WaveDuty12
		.byte	0,2,3,4

        
    

@**************** Voice 81 ****************@ Square 1 Duty 25%

		.byte	SquareWave1
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	WaveDuty25
		.byte	0,2,3,4

    

@**************** Voice 82 ****************@ Square 1 Duty 50%

		.byte	SquareWave1
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	WaveDuty50
		.byte	0,2,3,4
        
    
@**************** Voice 83 ****************@ Square 1 Duty 75%

		.byte	SquareWave1
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	WaveDuty75
		.byte	0,2,3,4

@**************** Voice 84 ****************@ Square 2 Duty 12%

		.byte	SquareWave2
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	WaveDuty12
		.byte	0,2,3,4
        
    
@**************** Voice 85 ****************@ Square 2 Duty 25%

		.byte	SquareWave2
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	WaveDuty25
		.byte	0,2,3,4
        
    

@**************** Voice 86 ****************@ Square 2 Duty 50%

		.byte	SquareWave2
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	WaveDuty25
		.byte	0,2,3,4
        
    

@**************** Voice 87 ****************@ Square 2 Duty 75%

		.byte	SquareWave2
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	WaveDuty25
		.byte	0,2,3,4
        
    

@**************** Voice 88 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 89 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 90 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 91 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 92 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 93 ****************@ Hit SFX

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84ec390
		.byte	255, 249, 103, 165
        
    

@**************** Voice 94 ****************@ Bass Piano 255_165_103_235

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86a4a7c
		.byte	255,165, 103, 235
		@ alternative envelopes
		@ .byte 128, 204, 51, 242
        
    

@**************** Voice 95 ****************@ Bass Piano 128_204_51_242

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x86a4a7c
		.byte 128, 204, 51, 242
        
    

@**************** Voice 96 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 97 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 98 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 99 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 100 ****************@ pw_Square_50_0_0_15_0

		.byte	11
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	snd_square_50_wave
		.byte	0x0, 0x0, 0xF, 0x0
        
    

@**************** Voice 101 ****************@ pwA_0_1_12_0

		.byte	11
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a1880
		.byte	0,1,12,0
        
    

@**************** Voice 102 ****************@ pwB_7_15_0_0

		.byte	11
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a1890
		.byte   0, 7, 15, 0
		@ alternative envelopes
		@ .byte 0, 0, 12, 0
        
    

@**************** Voice 103 ****************@ pwC_7_15_0_0

		.byte	11
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a18a0
		.byte   0, 7, 15, 0
		@ alternative envelopes
		@ .byte 0, 1, 9, 2
        
    

@**************** Voice 104 ****************@ pwD_0_0_12_0

		.byte	11
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a1840
		.byte   0, 0, 12, 0
    

@**************** Voice 105 ****************@ pwE_0_7_15_0

		.byte	11
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a1870
		.byte   0, 7, 15, 0
		@ alternative envelopes
		@ .byte 0, 3, 6, 5
		@ .byte 0, 7, 15, 1
		@ .byte 0, 7, 15, 2
    

@**************** Voice 106 ****************@ pwF_0_7_15_0

		.byte	11
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a1820
		.byte   0, 7, 15, 0
		@ alternative envelopes
		@ .byte 1, 7, 0, 6
		@ .byte 0, 2, 9, 1
        
    

@**************** Voice 107 ****************@ pwG_0_7_15_1

		.byte	11
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a1810
		.byte   0, 7, 15, 1
		@ alternative envelopes
		@ .byte 0, 4, 6, 0
		@ .byte 0, 2, 4, 2
		@ .byte 0, 7, 15, 0
		@ .byte 0, 7, 9, 1
		@ .byte 0, 0, 12, 0
		@ .byte 0, 7, 15, 2
		@ .byte 0, 0, 15, 0
        
    

@**************** Voice 108 ****************@ pwH_0_7_15_0

		.byte	11
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a18b0
		.byte   0, 0, 12, 0
		@ alternative envelopes
		@ .byte 0, 7, 15, 0
		@ .byte 0, 4, 6, 0
        
    

@**************** Voice 109 ****************@ pwI_0_7_15_0

		.byte	11
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a1850
		.byte   0, 7, 15, 0
		@ alternative envelopes
		@ .byte 0, 7, 15, 2
		@ .byte 0, 0, 6, 0
		@ .byte 1, 5, 0, 3
		@ .byte 0, 2, 4, 1
		@ .byte 0, 0, 15, 1
        
    

@**************** Voice 110 ****************@ pwJ_0_7_15_1

		.byte	11
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a1860
		.byte   0, 7, 15, 1
		@ alternative envelopes
		@ .byte 0, 7, 15, 0
		@ .byte 1, 5, 0, 3
		@ .byte 0, 7, 15, 2
		@ .byte 0, 2, 4, 1
		@ .byte 0, 0, 12, 0
        
    

@**************** Voice 111 ****************@ pwK_0_7_15_2

		.byte	11
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84a1830
		.byte   0, 7, 15, 2
		@ alternative envelopes
		@ .byte 0, 2, 9, 0
		@ .byte 0, 7, 15, 1
        
    

@**************** Voice 112 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 113 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 114 ****************@ Steel Drum
		
		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	snd_steel_drum
		.byte	0xFF, 0xEB, 0x67, 0xB2
        
    

@**************** Voice 115 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 116 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 117 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 118 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 119 ****************@ EMPTY

		.byte	KeySplit
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x8488b2c
		.word	0x84a1678
        
    

@**************** Voice 120 ****************@ Drum Kit FX

		.byte	DrumTable
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x84886f4
		.word 0
        
    

@**************** Voice 121 ****************@ Drum Kit Unknown 1

		.byte	DrumTable
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x84a127c
		.word 0
        
    

@**************** Voice 122 ****************@ Drum Kit Unknown 2

		.byte	DrumTable
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x849d358
		.word 0
        

@**************** Voice 123 ****************@ EMPTY

		.byte	DrumTable
		.byte	0x0
		.byte	0x0
		.byte	0x0
		.word	0x849d118
		.word 0
        
    

@**************** Voice 124 ****************@ Clapping
@ assigned 126 in bprd

		.byte	DirectSound
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	0x84b28c8
		.byte	255,255, 255, 127
        
    

@**************** Voice 125 ****************@ Noise2_Rough_0_0_15_0

		.byte	ProgNoise2
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	RoughNoise
		.byte	0,0,15,0
        
    

@**************** Voice 126 ****************@ Noise2_Fine_0_2_6_0

		.byte	ProgNoise2
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	FineNoise
		.byte	0,2,6,0
        
    

@**************** Voice 127 ****************@ Noise2_Fine_0_1_3_2

		.byte	ProgNoise2
		.byte	Cn3
		.byte	0x0
		.byte	0x0
		.word	FineNoise
		.byte	0,1,3,2