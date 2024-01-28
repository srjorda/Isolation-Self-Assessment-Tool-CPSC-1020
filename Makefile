COMPILER = g++
OPTIONS = -Wall
PROGRAM = isolation.out

all: $(PROGRAM)

run:	$(PROGRAM)
	./$(PROGRAM)

$(PROGRAM):	main.cpp calcDays.cpp Date.cpp calcDays.h Date.h
	$(COMPILER) $(OPTIONS) main.cpp calcDays.cpp Date.cpp -std=c++11 -o $(PROGRAM)

clean:
	rm *.out
