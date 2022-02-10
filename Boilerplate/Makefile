COMPILER = g++
COMPILER_FLAGS = -Wall -std=c++17
PROGRAM_NAME = main.o
CPP_FILES = main.cpp 

build:
	rm -f $(PROGRAM_NAME) *.o
	$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES) -o $(PROGRAM_NAME)
	./$(PROGRAM_NAME)

t:
	rm -f $(PROGRAM_NAME) *.o
	$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES) -o $(PROGRAM_NAME)
	cat 1.in | ./$(PROGRAM_NAME) | diff - 1.ans
	cat 2.in | ./$(PROGRAM_NAME) | diff - 2.ans
	echo "All Kattis sample tests cases passed"

a:
	rm -f $(PROGRAM_NAME) *.o
	$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES) -o $(PROGRAM_NAME)
	cat 1.in | ./$(PROGRAM_NAME) 
	
a1:
	rm -f $(PROGRAM_NAME) *.o
	$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES) -o $(PROGRAM_NAME)
	cat 1.in | ./$(PROGRAM_NAME) | diff - 1.ans

clean:
	rm -f $(PROGRAM_NAME) *.o
