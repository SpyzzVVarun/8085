
START:	   MVI A,02
	   MVI D,00
	   MOV C,A
	   RRC
	   JNC ONE
	   MVI D,08

ONE:	   ANI 7F
	   MOV B,A
	   MOV A,C
	   RRC
	   JNC TWO
	   MOV E,A
	   MOV A,D
	   ADI 01
	   MOV D,A
	   MOV A,E

TWO:	   ANI 7F
	   RRC
	   JNC THREE
	   MOV E,A
	   MOV A,D
	   ADI 02
	   MOV D,A
	   MOV A,E

THREE:	   ANI 7F
	   RRC
	   JNC FOUR
	   MOV E,A
	   MOV A,D
	   ADI 04
	   MOV D,A
	   MOV A,E

FOUR:	   ANI 7F
	   ADD B
	   MOV E,A
	   MOV A,D
	   RLC
	   ANI 7F
	   MOV D,A
	   MOV A,E
	   MOV B,A
	   MOV C,D
