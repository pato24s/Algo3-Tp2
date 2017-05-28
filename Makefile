CC=g++
CFLAGS=-std=c++11

EJS = problema1 problema2 problema3 tiempo
DEPS =  grafos.h metodos.h
OBJS = grafos.o metodos.o

all: $(EJS)

problema1: ej1.o grafos.o metodos.o
	$(CC) $(CFLAGS) -o $@ $^

problema2: ej2.o grafos.o metodos.o
	$(CC) $(CFLAGS) -o $@ $^

problema3: ej3.o grafos.o metodos.o
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
