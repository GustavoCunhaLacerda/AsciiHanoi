# Nome do projeto
NOME_PROJ=AsciiHanoi

# Compilador
CC=gcc

# Flags para o compilador
CC_FLAGS=-W -Wall

# arquivos .c
C_SOURCE=$(wildcard src/*)

# arquivos .h
H_SOURCE=$(wildcard headers/*)

# arquivos objeto (.o)
O_OBJ=$(subst .c,.o,$(subst src,build,$(C_SOURCE)))


# Compilação
build: $(NOME_PROJ)

$(NOME_PROJ): $(O_OBJ)
	@ echo 'Construíndo o binário final: $@'
	$(CC) -o $(NOME_PROJ) $(O_OBJ)
	@ echo ' '
	@ echo 'Compilação concluída: $@'
	@ echo ' '

build/%.o: src/%.c $(H_SOURCE)
	@ echo 'Compilando o arquivo: $<'
	$(CC) $(CC_FLAGS) -c $< -o $@
	@ echo ' '

clean:
	@ rm -rf $(wildcard build/*.o) $(NOME_PROJ)

run:
	@ ./$(NOME_PROJ)

test:
	@ valgrind ./$(NOME_PROJ)