hepsi: derle calistir
Nesneler :=  ./lib/Dugum2.o ./lib/BST.o ./lib/Dugum.o ./lib/ListeGezici.o ./lib/BagliListe.o 
derle:

	g++ -I ./include/ -o ./lib/Dugum2.o -c ./src/Dugum2.cpp
	g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/ListeGezici.o -c ./src/ListeGezici.cpp
	g++ -I ./include/ -o ./lib/BagliListe.o -c ./src/BagliListe.cpp
	g++ -I ./include/ -o ./bin/test $(Nesneler) ./src/test.cpp
calistir:
	./bin/Test