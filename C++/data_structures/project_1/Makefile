VPATH=	./src
CXXFLAGS=	g++	-I	"./include/"	-o



Derle:	Dosyalar	Olustur	Oyna

Dosyalar:
	$(CXXFLAGS) ./lib/top.o 			-c ./src/top.cpp
	$(CXXFLAGS) ./lib/sepetKontrol.o 	-c ./src/sepetKontrol.cpp
	$(CXXFLAGS) ./lib/sepet.o			-c ./src/sepet.cpp

# .exe bin klasöründe oluşmaktadır.
Olustur:
	$(CXXFLAGS) ./bin/main ./lib/top.o ./lib/sepetKontrol.o	./lib/sepet.o	./src/main.cpp

Oyna:
	./bin/main

sil:
	del	./lib/*.o
	del	./bin/*.exe
