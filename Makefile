.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  main

C_SOURCES =  main.cpp
C_OBJS     =  main.o kd_tree.o node.o
MY_INCLUDES = kd_tree.cpp node.cpp
# merg.h


CCX = g++
CXXFLAGS = -g -std=c++11
# -Wall

#============================================================
all: $(TARGET) run_random_data_100 #run_less_simple_test # run_handwritten_tests

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
	./$(TARGET) random_datasets/n_100/100_2_0.txt > out.txt
# run_handwritten_tests:
# 	for file in Handwritten_Test_Cases/*.txt; \
# 	do ./$(TARGET) "$$file"; done
# for file in random_datasets/n_100/*.txt; \
# do ./$(TARGET) "$$file"; done
