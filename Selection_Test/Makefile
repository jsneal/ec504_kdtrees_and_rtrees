.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  main

C_SOURCES =  main.cpp
C_OBJS     =  main.o selection_algorithms.o
MY_INCLUDES = selection_algorithms.cpp



CCX = g++
CXXFLAGS = -g -std=c++11

#============================================================
all: $(TARGET) case_test 5_permuted_test 6_permuted_test 7_permuted_test no_input_file_test	

.o:.cpp	$(MY_INCLUDES)
	$(CCX)  -c  $(CXXFLAGS) $<

$(TARGET) :   $(C_OBJS)
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

# Implicit rules: $@ = target name, $< = first prerequisite name, $^ = name of all prerequisites
#============================================================

ALL_SOURCES = Makefile $(C_SOURCES) $(MY_INCLUDES)

NOTES =
%= otherstuff.np 

clean:
	rm -f $(TARGET) $(C_OBJS) core
	rm generate_selection_test_arrays
	rm *permuted.txt*
	rm *.txt_out

tar: $(ALL_SOURCES) $(NOTES)
	tar cvf $(TARGET).tar $(ALL_SOURCES)  $(NOTES)

$(TARGET).ps: $(ALL SOURCES)
	enscript -pcode.ps $(ALL_SOURCES)

no_input_file_test:
	for i in {1..100}; \
	do sleep 3; \
	./$(TARGET); done

case_test:
	./$(TARGET) test.txt

5_permuted_test: 
	g++ -std=c++11 -g -o generate_selection_test_arrays generate_selection_test_arrays.cpp
	./generate_selection_test_arrays 5
	./$(TARGET) 5_permuted.txt

6_permuted_test: 
	g++ -std=c++11 -g -o generate_selection_test_arrays generate_selection_test_arrays.cpp
	./generate_selection_test_arrays 6
	./$(TARGET) 6_permuted.txt

7_permuted_test: 
	g++ -std=c++11 -g -o generate_selection_test_arrays generate_selection_test_arrays.cpp
	./generate_selection_test_arrays 7
	./$(TARGET) 7_permuted.txt
