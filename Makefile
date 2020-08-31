# Nome do Projeto
NOME_PROJ=AsciiHanoi

# Compilador
CC=gcc

# Arquivos .c
C_SOURCE=$(wildcard ./src/*.c)

# Arquivos .h
H_SOURCE=$(wildcard ./src/*.h)

# Compilação
AsciiHanoi:
	gcc $(C_SOURCE) -o ./$(NOME_PROJ)

# Make clean
clean:
	rm -rf $(NOME_PROJ)