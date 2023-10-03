	.align 2
voicegroupslowstrings:: @ 8676AC0
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_string_ensemble_60, 10, 254, 255, 196  @ 8676AC0
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_string_ensemble_72, 10, 254, 255, 196  @ 8676ACC
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_string_ensemble_84, 10, 254, 255, 196  @ 8676AD8

	.align 2
voicegroup191::
	voice_keysplit voicegroup005, KeySplitTable1 @ piano
	voice_directsound 60, 0, DirectSoundWaveData_steinway_b_piano, 255, 165, 103, 235
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ electric grand
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ honky tonk
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_detuned_ep1_low, 255, 188, 128, 226  @ 86B3E7C
	voice_directsound 60, 65, DirectSoundWaveData_sd90_classical_detuned_ep1_high, 128, 204, 77, 246
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ soon to be harpsicord
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ soon to be clavinet
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ celesta
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_glockenspiel, 255, 165, 51, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ soon to be music box
	voice_directsound 60, 0, vibraphone, 255, 235, 0, 216 @ vibraphone
	voice_directsound 60, 0, marimba60, 255, 235, 0, 216 @ marimba
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_xylophone, 255, 235, 0, 216
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_tubular_bell, 255, 253, 0, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ dulcimer
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ drawbar organ (other percussive organ?)
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_organ2, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ rock organ (other percussive organ?)
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188  @ 8697754
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_high, 255, 76, 154, 188
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_accordion, 64, 188, 108, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ harmonica
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ tango accordian
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_nylon_str_guitar, 255, 249, 25, 127
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_nylon_str_guitar, 64, 216, 51, 224 @ maybe steel?
	voice_directsound 60, 0, DirectSoundWaveData_unused_guitar_separates_power_chord, 255, 165, 206, 127 @ electric guitar (jazz)?
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ electric guitar (clean)
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ electric guitar (muted)
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_overdrive_guitar, 128, 0, 255, 214
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_distortion_guitar_high, 128, 0, 255, 206
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ soon to be guitar harmonics
	voice_directsound 60, 0, acousticbass48, 255, 253, 0, 188 @ acoustic bass
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ soon to be electric bass (finger)
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fingered_bass, 255, 253, 0, 149 @ (should be pick bass)
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 253, 0, 188
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_slap_bass, 255, 235, 128, 99
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_slap_bass, 255, 255, 255, 127
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_synth_bass, 255, 252, 0, 115
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_square_wave, 255, 0, 255, 127
	voice_directsound 60, 0, violin, 255, 255, 0, 221
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ viola
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_cello, 255, 0, 255, 127
	voice_directsound 60, 0, contrabass, 255, 255, 0, 221 @ contrabass
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ tremolo strings
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_pizzicato_strings, 255, 216, 0, 165
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_harp, 255, 246, 0, 235
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_timpani, 255, 165, 154, 235 @ several different versions are in use
	voice_keysplit voicegroup006, KeySplitTable2 @ string ensemble
	voice_keysplit voicegroupslowstrings, KeySplitTable2 @ string ensemble 2
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ soon to be synth strings
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ synth strings 2
	voice_directsound 60, 0, DirectSoundWaveData_classical_choir_voice_ahhs, 128, 165, 128, 188 @ there are other versions
	voice_directsound 60, 0, DirectSoundWaveData_unknown_female_voice, 128, 165, 128, 204 @ ooh
	voice_directsound 60, 0, synth_voice, 128, 165, 128, 204 @ soon to be synth voice
	voice_directsound 60, 0, orchestrahit72, 200, 255, 255, 255 @ not sure about envelope values
	voice_keysplit voicegroup007, KeySplitTable3 @ trumpet
	voice_keysplit voicegroup008, KeySplitTable4 @ trombone
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_french_horn_60, 255, 0, 224, 165 @ tuba
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ muted trumpet
	voice_keysplit voicegroup009, KeySplitTable5 @ french horn
	voice_directsound 60, 0, brass_section, 255, 0, 224, 165 @ brass section
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ synth brass 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ synth brass 2
	voice_directsound 60, 0, sopranosax, 255, 0, 193, 127 @ soprano sax
	voice_directsound 60, 0, altosax72, 255, 0, 193, 127 @ alto sax
	voice_directsound 60, 0, tenorsax, 255, 0, 193, 127 @ tenor sax
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ baritone sax
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_oboe, 255, 165, 154, 127 @ two distinct versions, plus an unused voice
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ soon to be english horn
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ soon to be bassoon
	voice_directsound 60, 0, clarinet72, 255, 255, 0, 221 @ could do keysplit if I figure out how to make it work with clarinetgroup
	voice_directsound 60, 0, piccolo, 255, 127, 231, 127 @ piccolo (adjust a flute?)
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_flute, 255, 127, 231, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ recorder
	voice_directsound 60, 0, pan_flute, 255, 127, 231, 127 @ pan flute
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ blown bottle
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_shakuhachi, 255, 0, 255, 204
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_whistle, 255, 0, 255, 127
	voice_directsound 60, 0, ocarina, 255, 127, 231, 127 @ ocarina
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ square wave
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ sawtooth
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ calliope
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ chiff
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ charang
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ voice
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ fifths
	voice_programmable_wave 60, 0, ProgrammableWaveData_8, 0, 7, 15, 1 @ bass (rough) switch "9B" to "99" for smooth
	voice_directsound 60, 0, pad1, 255, 250, 0, 230 @ Pad 1
	voice_directsound 60, 0, pad2, 10, 254, 255, 250 @ Pad 2
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ Pad 3
	voice_directsound 60, 0, pad4, 255, 254, 0, 250 @ Pad 4
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ Pad 5
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ Pad 6  ↑ Add in via directsound? Via 8-bit?
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ Pad 7  Not in sounfont
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ Pad 8  Not in soundfont
	voice_keysplit_all voicegroup002 @ percussion 96
	voice_directsound 60, 0, rain, 255, 254, 0, 150 @ FX 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ FX 2
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ FX 3
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ FX 4
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ FX 5
	voice_directsound 60, 0, goblin, 10, 10, 255, 250 @ FX 6
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ FX 7
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ FX 8
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ sitar
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ soon to be banjo
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ shamisen
	voice_directsound 60, 0, DirectSoundWaveData_unknown_koto_low, 255, 0, 206, 242 @ also a high version
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ kalimba
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ bagpipe
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ fiddle
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ shanai
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ tinkle bell
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ agogo
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ soon to be steel drums
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ woodblock
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ taiko drum
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ melodic tom
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ synth drum
	voice_directsound 60, 0, gong, 255, 255, 255, 255 @ reverse symbal
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ guitar fret noise
	voice_directsound 60, 0, breath_noise, 255, 254, 0, 127 @ breath noise
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ seashore
	voice_directsound 60, 0, bird, 255, 253, 0, 255 @ bird tweet
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ telephone ring
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ helicopter
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @ applause (bottom two probably use voice_noise somehow)
