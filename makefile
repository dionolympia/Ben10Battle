CXX = g++
CXXFLAGS = -Wall

proj4: Game.o Ben.o Pyronite.o Crystalsapien.o Monster.o proj4.cpp
	$(CXX) $(CXXFLAGS) Game.o Ben.o Pyronite.o Crystalsapien.o Monster.o  proj4.cpp -o proj4

Game.o: Game.h Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

Ben.o: Ben.h Ben.cpp
	$(CXX) $(CXXFLAGS) -c Ben.cpp

Pyronite.o: Pyronite.h Pyronite.cpp
	$(CXX) $(CXXFLAGS) -c Pyronite.cpp

Crystalsapien.o: Crystalsapien.h Crystalsapien.cpp
	$(CXX) $(CXXFLAGS) -c Crystalsapien.cpp

Monster.o: Monster.h Monster.cpp
	$(CXX) $(CXXFLAGS) -c Monster.cpp

clean:
	rm *.o
	rm *~

run:
	./proj4