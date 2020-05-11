PROGRAM = GeoRabbit
CC = g++
LDLIBS = -lglut -lGLU -lGL -lm

$(PROGRAM): rabbit.o
	$(CC) -o $(PROGRAM) $^ $(LDLIBS)
main.o: main.cpp

clean:
	-rm *.o $(PROGRAM)
