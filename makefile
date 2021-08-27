main.exe: main.cpp candy_crush.o cool_map.o spec_rule1.o spec2.o spec3.o
	g++ -o main.exe main.cpp candy_crush.o cool_map.o spec_rule1.o spec2.o spec3.o -lncursesw

candy_crush.o: candy_crush.h candy_crush.cpp
	g++ -c candy_crush.cpp -lncursesw

cool_map.o: cool_map.h cool_map.cpp
	g++ -c cool_map.cpp -lncursesw

spec_rule1.o: spec_rule1.h spec_rule1.cpp
	g++ -c spec_rule1.cpp -lncursesw

spec2.o: spec2.h spec2.cpp
	g++ -c spec2.cpp -lncursesw

spec3.o: spec3.h spec3.cpp
	g++ -c spec3.cpp -lncursesw
back:
	cp main.cpp backup/mainback
	cp candy_crush.cpp backup/candy_crushback
	cp cool_map.cpp backup/cool_mapback
	cp spec_rule1.cpp backup/spec_rule1

rm:
	rm *.o
