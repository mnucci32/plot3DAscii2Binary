OBJS = main.o plot3d.o
CC = g++
DEBUG = -ggdb -pg 
OPTIM = -O3 -march=native
PROF = -O3 -march=native -pg
CODENAME = ascii2Binary
CFLAGS = -std=c++11 -Wall -c $(OPTIM)
LFLAGS = -std=c++11 -Wall $(OPTIM) -o $(CODENAME)

$(CODENAME) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS)

plot3d.o : plot3d.cpp plot3d.hpp vector3d.hpp
	$(CC) $(CFLAGS) plot3d.cpp

main.o : main.cpp plot3d.hpp vector3d.hpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o *~ $(CODENAME)
