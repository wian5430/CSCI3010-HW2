CXX = g++
CXXFLAGS	= -std=c++11 -Wall

all: shop

clean:
	rm test Store.o Item.o TextUI.o

# update to include a test target when you have a test.cpp

test: Store.o TextUI.o Item.o test.cpp
	$(CXX) $(CXXFLAGS) test.cpp Store.o TextUI.o Item.o -o test

shop: main.cpp Store.o Item.o TextUI.o
	$(CXX) $(CXXFLAGS) main.cpp Store.o Item.o TextUI.o -o shop

TextUI.o: TextUI.cpp
	$(CXX) $(CXXFLAGS) -c TextUI.cpp

Store.o: Store.cpp
	$(CXX) $(CXXFLAGS) -c Store.cpp

Item.o: Item.cpp
	$(CXX) $(CXXFLAGS) -c Item.cpp