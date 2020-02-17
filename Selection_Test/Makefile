.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  main

C_SOURCES =  main.cpp
C_OBJS     =  main.o selection_algorithms.o
MY_INCLUDES = selection_algorithms.cpp
# merg.h


CCX = g++
CXXFLAGS = -g -std=c++11
# -Wall

#============================================================
all: $(TARGET) case_test 5_permuted_test 6_permuted_test 7_permuted_test no_input_file_test #8_permuted_test 9_permuted_test
	#run_random_data_100 #\
#run_random_data_1000 run_random_data_100K run_random_data_1M \
#	run_random_perm_data_100 run_random_perm_data_1000 run_random_perm_data_100K run_random_perm_data_1M
	

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
	rm *permuted.txt*

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

run_random_data_100:
	for file in ../ec504_kdtrees_and_rtrees/random_datasets/n_100/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_data_1000:
	for file in ../ec504_kdtrees_and_rtrees/random_datasets/n_1000/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_data_100K:
	for file in ../ec504_kdtrees_and_rtrees/random_datasets/n_100K/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_data_1M:
	for file in ../ec504_kdtrees_and_rtrees/random_datasets/n_1M/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_perm_data_100:
	for file in ../ec504_kdtrees_and_rtrees/random_dataset_permuted/n_100/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_perm_data_1000:
	for file in ../ec504_kdtrees_and_rtrees/random_dataset_permuted/n_1000/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_perm_data_100K:
	for file in ../ec504_kdtrees_and_rtrees/random_dataset_permuted/n_100K/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_perm_data_1M:
	for file in ../ec504_kdtrees_and_rtrees/random_dataset_permuted/n_1M/*.txt; \
	do ./$(TARGET) "$$file"; done
