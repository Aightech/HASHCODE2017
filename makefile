# options de compilation
CC = gcc
CCFLAGS = -Wall
LIBS = 
LDFLAGS =

# fichiers du projet
SRC = main.c input_reader.c optimization_computation.c qsort.c
OBJ = $(SRC:.c=.o)
EXEC = main


# règle initiale
all: $(EXEC)

# dépendance des .h
main.o: input_reader.h optimization_computation.h qsort.h structs.h
input_reader.o: structs.h
optimization_computation.o: structs.h
qsort.o: qsort.h structs.h

# règles de compilation
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<
	
# règles d'édition de liens
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LIBSDIR) $(LDFLAGS)

# règles supplémentaires
clean:
	rm -f *.o
rmproper:
	rm -f $(EXEC) *.o
