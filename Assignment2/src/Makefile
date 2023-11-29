IDIR = ./header
ODIR= ./object

CC = clang++
CFLAGS=-I$(IDIR)
LIBS=-lm

_DEPS = global.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ =  LDA.o hexToDecimal.o hexAdd.o hexAdd16bit.o hexSub.o hexSub16bit.o increaseAddress.o operationSize.o registerNumber.o LXI.o MOV.o MVI.o STA.o CMP.o JC.o JMP.o JNC.o JNZ.o JZ.o ADD.o ADI.o DAD.o DCR.o DCX.o INR.o INX.o SUB.o SUI.o  execution.o updatedAddress.o main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
	
emulator: $(OBJ)
	clang++ -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~