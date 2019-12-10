.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  time_insert_and_find

C_SOURCES =  time_insert_and_find.cpp
C_OBJS     =  time_insert_and_find.o kd_tree.o node.o
MY_INCLUDES = kd_tree.cpp node.cpp
# merg.h


CCX = g++
CXXFLAGS = -g -std=c++11
# -Wall

#============================================================
all: $(TARGET) run_make_histograms 
	g++ -std=c++11 -o make_histograms make_histograms.cpp
	#run_random_perm_data_100 run_random_perm_data_1000 run_random_perm_data_100K # run_random_data_100 run_random_data_1000 run_random_data_100K  #run_less_simple_test # run_handwritten_tests

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
#	rm *.txt_out
#	rm Handwritten_Test_Cases/*.txt_out

tar: $(ALL_SOURCES) $(NOTES)
	tar cvf $(TARGET).tar $(ALL_SOURCES)  $(NOTES)

$(TARGET).ps: $(ALL SOURCES)
	enscript -pcode.ps $(ALL_SOURCES)

run_simple_test:
	./$(TARGET) Handwritten_Test_Cases/simple_2d_test.txt

run_less_simple_test:
	./$(TARGET) Handwritten_Test_Cases/less_simple_2d_case.txt

run_random_data_100:
	for file in random_datasets/n_100/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_data_1000:
	for file in random_datasets/n_1000/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_data_100K:
	for file in random_datasets/n_100K/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_data_1M:
	for file in random_datasets/n_1M/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_perm_data_100:
	for file in random_dataset_permuted/n_100/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_perm_data_1000:
	for file in random_dataset_permuted/n_1000/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_perm_data_100K:
	for file in random_dataset_permuted/n_100K/*.txt; \
	do ./$(TARGET) "$$file"; done

run_random_perm_data_1M:
	for file in random_dataset_permuted/n_1M/*.txt; \
	do ./$(TARGET) "$$file"; done

run_make_histograms:
	for file in 1*.txt; \
	do ./make_histograms "$$file"; done
