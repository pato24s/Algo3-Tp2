CC=g++
CFLAGS=-std=c++11

EJS = ej1 ej2 ej3 tiempo
DEPS =  grafos.h metodos.h
OBJS = grafos.o metodos.o

all: $(EJS)

ej1: ej1.o grafos.o metodos.o
	$(CC) $(CFLAGS) -o $@ $^

ej2: ej2.o grafos.o metodos.o
	$(CC) $(CFLAGS) -o $@ $^

ej3: ej3.o grafos.o metodos.o
	$(CC) $(CFLAGS) -o $@ $^

tiempo: tiempo.cpp grafos.o metodos.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp %$(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $^


clean: 
	rm -f $(EJS)
	rm -f $(OBJS)
	rm -f *.o

borrar_datos:
	sudo rm -rvf Inputs/Ej1/insTiempo
	sudo rm -rvf Inputs/Ej2/insTiempo
	sudo rm -rvf Inputs/Ej3/insTiempo
	sudo rm -rvf Outputs/Ej1/outsTiempo
	sudo rm -rvf Outputs/Ej2/outsTiempo
	sudo rm -rvf Outputs/Ej3/outsTiempo
