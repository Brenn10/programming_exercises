CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) $(I) -c  # compilation to intermediary .o files

test : sorts.o test.o
	$(LINK) test.out $^

test.o : test.cpp
	$(COMPILE) $< -o $@

sorts.o : Sorts.cpp
	$(COMPILE) $< -o $@

clean:
	@rm *.o *.out
