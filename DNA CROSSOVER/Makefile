hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/chromosome.o -c ./src/chromosome.cpp
	g++ -I ./include/ -o ./lib/dna.o -c ./src/dna.cpp
	g++ -I ./include/ -o ./lib/gene.o -c ./src/gene.cpp
	g++ -I ./include/ -o ./bin/main ./lib/chromosome.o ./lib/dna.o ./lib/gene.o ./src/main.cpp
	
calistir:
	./bin/main