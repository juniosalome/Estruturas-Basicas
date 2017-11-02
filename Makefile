CC=gcc
OBJ=Inverte.o TipoPilha.o  TipoFila.o 
DEPS=TipoItem.h TipoFila.h  TipoPilha.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@  $< 

EP4: $(OBJ)
	$(CC) -o $@ $^ 

	@echo "Compilaçao pronta" 
	
.PHONY: clean	
	
clean: 
	rm -rf *.o EP4






