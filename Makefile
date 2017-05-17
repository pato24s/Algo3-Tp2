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
	rm Inputs/Ej1/insTiempo/*ej1*
	rm Inputs/Ej2/insTiempo/*ej2*
	rm Inputs/Ej3/insTiempo/*ej3*
	rm Outputs/Ej1/outsTiempo/*ej1*
	rm Outputs/Ej2/outsTiempo/*ej2*
	rm Outputs/Ej3/outsTiempo/*ej3*
