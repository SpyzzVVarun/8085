MVI B,64
LXI H,4050
NEXTBYTE: 	MOV A,M
	XRI A0
	MOV M,A
	INX H
	DCR B
	JNZ NEXTBYTE 
	HLT
