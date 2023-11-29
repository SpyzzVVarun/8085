
	   MVI A,09
	   MVI B,02
	   MVI C,00

LOOP:	   CMP B
	   JC DONE
	   SUB B
	   INR C
	   JMP LOOP

DONE:	   MOV D,C
	   MOV E,A
	   MOV C,D
	   MOV D,E
	   MOV A,D
	   MVI D,00
	   MVI E,80

BINARY:	   ADD A
	   CMP B
	   JC LOL
	   MOV H,A
	   MOV A,D
	   ORA E
	   MOV D,A
	   MOV A,H
	   SUB B
	   JZ DONEE

LOL:	   MOV H,A
	   MOV A,E
	   RRC
	   ANI 7F
	   JZ DONEE
	   MOV E,A
	   MOV A,H
	   JMP BINARY

DONEE:	   HLT
