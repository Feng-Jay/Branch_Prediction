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
run:
	./sim bimodal 7 gcc_trace.txt > ../my_run/my_bimodal_1.txt
	./sim bimodal 10 gcc_trace.txt > ../my_run/my_bimodal_2.txt
	./sim bimodal 5 jpeg_trace.txt > ../my_run/my_bimodal_3.txt
	./sim bimodal 6 perl_trace.txt > ../my_run/my_bimodal_4.txt
	./sim gshare 10 4 gcc_trace.txt > ../my_run/my_gshare_1.txt
	./sim gshare 14 9 gcc_trace.txt > ../my_run/my_gshare_2.txt
	./sim gshare 11 5 jpeg_trace.txt > ../my_run/my_gshare_3.txt
	./sim gshare 10 6 perl_trace.txt > ../my_run/my_gshare_4.txt
names = 
names2 = 

files := $(foreach n, $(names),$(n))
files2 := $(foreach m, $(names2),$(m))

test:
	diff -iw ../my_run/my_bimodal_1.txt ../Validation\ runs/val_bimodal_1.txt 
	diff -iw ../my_run/my_bimodal_2.txt ../Validation\ runs/val_bimodal_2.txt 
	diff -iw ../my_run/my_bimodal_3.txt ../Validation\ runs/val_bimodal_3.txt 
	diff -iw ../my_run/my_bimodal_4.txt ../Validation\ runs/val_bimodal_4.txt 
	diff -iw ../my_run/my_gshare_1.txt ../Validation\ runs/val_gshare_1.txt 
	diff -iw ../my_run/my_gshare_2.txt ../Validation\ runs/val_gshare_2.txt 
	diff -iw ../my_run/my_gshare_3.txt ../Validation\ runs/val_gshare_3.txt 
	diff -iw ../my_run/my_gshare_4.txt ../Validation\ runs/val_gshare_4.txt