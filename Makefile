PROGRAM = GeoRabbit
CC = gcc
CFLAGS = -g -Wall
LDFLAGS=  -lGL -lGLU -lglut -lm
OBJECTS = stone.o igrac.o callback_fje.o texture.o image.o main.o

svi: $(PROGRAM)

$(PROGRAM): $(OBJECTS) 
	$(CC) -o $(PROGRAM) $(OBJECTS) $(LDFLAGS)

.PHONY: clean

clean:
	-rm -f *.o $(PROGRAM) *~
