############################# Makefile ##########################
#Variável
CC = gcc
#CFLAGS = 
OBJ = main.o Lista.o  TP1.o 
DEPS = Lista.h TP1.h
EXEC = main 

%.o: %.c $(DEPS)
	$(CC) -c -o $@  $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

	@echo "Compilaçao pronta" 
	
.PHONY: clean	
	
clean: 
	rm -rf *.o $(EXEC)






