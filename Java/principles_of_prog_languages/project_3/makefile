hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/IMEINo.o -c ./src/IMEINo.c
	gcc -I ./include/ -o ./lib/Telefon.o -c ./src/Telefon.c
	gcc -I ./include/ -o ./lib/KimlikNo.o -c ./src/KimlikNo.c
	gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c
	gcc -I ./include/ -o ./lib/RastgeleKisi.o -c ./src/RastgeleKisi.c
	
	gcc -I ./include/ -o ./bin/Test ./lib/IMEINo.o ./lib/Telefon.o ./lib/KimlikNo.o  ./lib/Kisi.o ./lib/RastgeleKisi.o   ./src/Test.c
calistir:
	./bin/Test