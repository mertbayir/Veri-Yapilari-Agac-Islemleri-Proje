all:derle bagla calistir

derle:
	g++ -c -I "./include" ./src/ornek.cpp -o ./lib/ornek.o
	g++ -c -I "./include" ./src/avlagaci.cpp -o ./lib/avlagaci.o
	g++ -c -I "./include" ./src/avldugum.cpp -o ./lib/avldugum.o	
	g++ -c -I "./include" ./src/yigin.cpp -o ./lib/yigin.o	

bagla:
	g++ ./lib/avlagaci.o ./lib/avldugum.o ./lib/yigin.o ./lib/ornek.o -o ./bin/program
calistir:
	./bin/program
