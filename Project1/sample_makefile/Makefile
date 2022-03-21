sim: gshare.o bim_predictor.o main.o
	g++ gshare.o bim_predictor.o main.o -o sim
gshare.o: gshare.cpp
	g++ -c gshare.cpp 
bim_predictor.o: bim_predictor.cpp
	g++ -c bim_predictor.cpp
main.o: main.cpp
	g++ -c main.cpp
.PHONY: clean
clean: 
	@rm -f *.o
	@rm -f sim
# test:
# 	# ./sim gshare 10 4 0 0 gcc_trace.txt