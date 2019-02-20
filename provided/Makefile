CXX = g++
CXXFLAGS	= -std=c++11 -Wall

all: TextUI.o Store.o Item.o # update to include shop when you have a main.cpp

clean:
	rm shop Store.o Item.o TextUI.o

# update to include a test target when you have a test.cpp

#shop: main.cpp Store.o Item.o TextUI.o
#	$(CXX) $(CXXFLAGS) main.cpp Store.o Item.o TextUI.o -o shop

TextUI.o: TextUI.cpp
	$(CXX) $(CXXFLAGS) -c TextUI.cpp

Store.o: Store.cpp
	$(CXX) $(CXXFLAGS) -c Store.cpp

Item.o: Item.cpp
	$(CXX) $(CXXFLAGS) -c Item.cpp
