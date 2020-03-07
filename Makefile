# This Makefile is based off of the Makefile from EC504 HW1 with Professor Brower (Fall 2019)
.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  main

C_SOURCES =  main.cpp
C_OBJS     =  main.o kd_tree.o node.o
MY_INCLUDES = kd_tree.cpp node.cpp



CCX = g++
CXXFLAGS = -g -std=c++11
# -Wall

#============================================================
all: $(TARGET) run_simple_tests \
run_simple_long_chain_tests \
run_simple_lowered_long_chain_tests run_random_data_100 \
run_random_data_1000 run_random_data_100K run run_random_data_1M \
run_random_perm_data_100 run_random_perm_data_1000 \
run_random_perm_data_100K run_random_perm_data_1M \
#run_quicksort_balanced_trees_on_simple_cases \


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

tar: $(ALL_SOURCES) $(NOTES)
	tar cvf $(TARGET).tar $(ALL_SOURCES)  $(NOTES)

$(TARGET).ps: $(ALL SOURCES)
	enscript -pcode.ps $(ALL_SOURCES)

run_simple_tests: 
	./$(TARGET) Handwritten_Test_Cases/simple_2d_test.txt Handwritten_Test_Cases/s2c_deletion_tests/from_root.txt 0
	./$(TARGET) Handwritten_Test_Cases/simple_2d_test.txt Handwritten_Test_Cases/s2c_deletion_tests/from_leaves.txt 0
	./$(TARGET) Handwritten_Test_Cases/simple_2d_test.txt Handwritten_Test_Cases/s2c_deletion_tests/from_intermediates.txt 0
	./$(TARGET) Handwritten_Test_Cases/simple_2d_test.txt Handwritten_Test_Cases/s2c_deletion_tests/null_right_subtree.txt 0
	./$(TARGET) Handwritten_Test_Cases/simple_2d_test.txt Handwritten_Test_Cases/s2c_deletion_tests/null_left_subtree.txt 0

# Only changed deletion test is null_left_subtree with a "Find 4 2" to make sure this was not lost.
run_simple_long_chain_tests:
	./$(TARGET) Handwritten_Test_Cases/simple_2d_long_chain_test.txt Handwritten_Test_Cases/s2lc_deletion_tests/from_root.txt 0
	./$(TARGET) Handwritten_Test_Cases/simple_2d_long_chain_test.txt Handwritten_Test_Cases/s2lc_deletion_tests/from_leaves.txt 0
	./$(TARGET) Handwritten_Test_Cases/simple_2d_long_chain_test.txt Handwritten_Test_Cases/s2lc_deletion_tests/from_intermediates.txt 0
	./$(TARGET) Handwritten_Test_Cases/simple_2d_long_chain_test.txt Handwritten_Test_Cases/s2lc_deletion_tests/null_right_subtree.txt 0
	./$(TARGET) Handwritten_Test_Cases/simple_2d_long_chain_test.txt Handwritten_Test_Cases/s2lc_deletion_tests/null_left_subtree.txt 0

# Deletion tests have been changed to measure the test case
run_simple_lowered_long_chain_tests:
	./$(TARGET) Handwritten_Test_Cases/simple_2d_lowered_long_chain_test.txt Handwritten_Test_Cases/s2llc_deletion_tests/from_root.txt 0
	./$(TARGET) Handwritten_Test_Cases/simple_2d_lowered_long_chain_test.txt Handwritten_Test_Cases/s2llc_deletion_tests/top_of_chain_then_middle_of_chain.txt 0
	./$(TARGET) Handwritten_Test_Cases/simple_2d_lowered_long_chain_test.txt Handwritten_Test_Cases/s2llc_deletion_tests/from_leaves.txt 0
	./$(TARGET) Handwritten_Test_Cases/simple_2d_lowered_long_chain_test.txt Handwritten_Test_Cases/s2llc_deletion_tests/from_intermediates.txt 0
	./$(TARGET) Handwritten_Test_Cases/simple_2d_lowered_long_chain_test.txt Handwritten_Test_Cases/s2llc_deletion_tests/null_right_subtree.txt 0
	./$(TARGET) Handwritten_Test_Cases/simple_2d_lowered_long_chain_test.txt Handwritten_Test_Cases/s2llc_deletion_tests/null_left_subtree.txt 0

# run_100_2_0_test:
# 	./$(TARGET) random_datasets/n_100/100_2_0.txt Random_Test_Cases/100_2_0_case.txt

run_less_simple_test:
	./$(TARGET) Handwritten_Test_Cases/less_simple_2d_case.txt 0

run_random_data_100:
	for file in random_datasets/n_100/*.txt; \
	do ./$(TARGET) "$$file" 0; done

run_random_data_1000:
	for file in random_datasets/n_1000/*.txt; \
	do ./$(TARGET) "$$file" 0; done

run_random_data_100K:
	for file in random_datasets/n_100K/*.txt; \
	do ./$(TARGET) "$$file" 0; done

run_random_data_1M:
	for file in random_datasets/n_1M/*.txt; \
	do ./$(TARGET) "$$file" 0; done

run_random_perm_data_100:
	for file in random_dataset_permuted/n_100/*.txt; \
	do ./$(TARGET) "$$file" 0; done

run_random_perm_data_1000:
	for file in random_dataset_permuted/n_1000/*.txt; \
	do ./$(TARGET) "$$file" 0; done

run_random_perm_data_100K:
	for file in random_dataset_permuted/n_100K/*.txt; \
	do ./$(TARGET) "$$file" 0; done

run_random_perm_data_1M:
	for file in random_dataset_permuted/n_1M/*.txt; \
	do ./$(TARGET) "$$file" 0; done

run_quicksort_balanced_trees_on_simple_cases: 
	./$(TARGET) Handwritten_Test_Cases/simple_2d_test.txt Handwritten_Test_Cases/s2c_deletion_tests/from_root.txt 1
	./$(TARGET) Handwritten_Test_Cases/simple_2d_test.txt Handwritten_Test_Cases/s2c_deletion_tests/from_leaves.txt 1
	./$(TARGET) Handwritten_Test_Cases/simple_2d_test.txt Handwritten_Test_Cases/s2c_deletion_tests/from_intermediates.txt 1
	./$(TARGET) Handwritten_Test_Cases/simple_2d_test.txt Handwritten_Test_Cases/s2c_deletion_tests/null_right_subtree.txt 1
	./$(TARGET) Handwritten_Test_Cases/simple_2d_test.txt Handwritten_Test_Cases/s2c_deletion_tests/null_left_subtree.txt 1
	###
	./$(TARGET) Handwritten_Test_Cases/simple_2d_long_chain_test.txt Handwritten_Test_Cases/s2lc_deletion_tests/from_root.txt 1
	./$(TARGET) Handwritten_Test_Cases/simple_2d_long_chain_test.txt Handwritten_Test_Cases/s2lc_deletion_tests/from_leaves.txt 1
	./$(TARGET) Handwritten_Test_Cases/simple_2d_long_chain_test.txt Handwritten_Test_Cases/s2lc_deletion_tests/from_intermediates.txt 1
	./$(TARGET) Handwritten_Test_Cases/simple_2d_long_chain_test.txt Handwritten_Test_Cases/s2lc_deletion_tests/null_right_subtree.txt 1
	./$(TARGET) Handwritten_Test_Cases/simple_2d_long_chain_test.txt Handwritten_Test_Cases/s2lc_deletion_tests/null_left_subtree.txt 1
	###
	./$(TARGET) Handwritten_Test_Cases/simple_2d_lowered_long_chain_test.txt Handwritten_Test_Cases/s2llc_deletion_tests/from_root.txt 1
	./$(TARGET) Handwritten_Test_Cases/simple_2d_lowered_long_chain_test.txt Handwritten_Test_Cases/s2llc_deletion_tests/top_of_chain_then_middle_of_chain.txt 1
	./$(TARGET) Handwritten_Test_Cases/simple_2d_lowered_long_chain_test.txt Handwritten_Test_Cases/s2llc_deletion_tests/from_leaves.txt 1
	./$(TARGET) Handwritten_Test_Cases/simple_2d_lowered_long_chain_test.txt Handwritten_Test_Cases/s2llc_deletion_tests/from_intermediates.txt 1
	./$(TARGET) Handwritten_Test_Cases/simple_2d_lowered_long_chain_test.txt Handwritten_Test_Cases/s2llc_deletion_tests/null_right_subtree.txt 1
	./$(TARGET) Handwritten_Test_Cases/simple_2d_lowered_long_chain_test.txt Handwritten_Test_Cases/s2llc_deletion_tests/null_left_subtree.txt 1
