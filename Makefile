CC=g++
CFLAGS=-std=c++11

objects = ej1 ej2
all: $(objects)
clean: 
	rm -f $(objects)

$(objects): %: %.cpp
	$(CC) $(CFLAGS) -o $@ $<
