CXX = g++
CXXFLAGS = -std=c++17 -c
OBJECTS =  ./obj/main.o ./obj/Rubik.o ./obj/rubiksolver.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX)  -o $(TARGET) $(OBJECTS)
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
./obj/Rubik.o: ./cpp/Rubik.cpp
	$(CXX) $(CXXFLAGS) ./cpp/Rubik.cpp -o ./obj/Rubik.o
./obj/rubiksolver.o: ./cpp/rubiksolver.cpp
	$(CXX) $(CXXFLAGS) ./cpp/rubiksolver.cpp -o ./obj/rubiksolver.o
clean:
	rm -fv $(TARGET) $(OBJECTS)
