
all: eh.o noeh.o
	ls -l eh.o noeh.o

eh.o: main.cpp
	g++ -std=c++14 -O3 -c -o eh.o -DROUND_TRIP_ERRORS_THROUGH_EH=1 main.cpp

noeh.o: main.cpp
	g++ -std=c++14 -O3 -c -o noeh.o -DROUND_TRIP_ERRORS_THROUGH_EH=0 main.cpp

clean:
	rm -f eh.o noeh.o

.PHONY: all clean
