#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Store.h"
#include "Item.h"
#include "TextUI.h"

using namespace std;

ShoppingCart sc;
Item apple(0, "apple", 1.00, 1);
Item bike(1, "Bike", 50.00, 1); 
Item record(2, "Record", 15.00, 1);

TEST_CASE ( "Store", "[store]"){
	
    SECTION( "correct read in" ){
		Store store("store.txt");
		REQUIRE(store.DisplayInventory() == "Tea: 2.00 - 6\nTall Candle: 7.00 - 13\nKettle: 15.00 - 2\n");
	}
}


TEST_CASE("Adding item", "[Shopping Cart]") {
    
    SECTION("Adding item") {
		vector<Item *> test = sc.get_items();
        REQUIRE(test.size() == 0);
        sc.AddItem(&apple);
        //Require that item is in cart
        test = sc.get_items();
        REQUIRE(test.size() == 1);
    }
    
    SECTION("Adding another item") {
		sc.AddItem(&apple);
        vector<Item *> test = sc.get_items();
        REQUIRE(test.size() == 1);
        sc.AddItem(&bike);
        test = sc.get_items();
        REQUIRE(test.size() == 2); 
    }
    
    SECTION("Adding a repeated item") {
		sc.AddItem(&apple);
        vector<Item *> test = sc.get_items();
        REQUIRE(test.size() == 1);
        sc.AddItem(&bike);
        test = sc.get_items();
        REQUIRE(test.size() == 2);
        sc.AddItem(&bike);
        REQUIRE(test.size() == 2);
        REQUIRE(test[0]->get_quantity() == 1);
        REQUIRE(test[1]->get_quantity() == 2);
    }
}

TEST_CASE("Removing an item", "[Shopping Cart]") {

    SECTION("Removing an item") {
		sc.AddItem(&apple);
		vector<Item *> test = sc.get_items();
		REQUIRE(test[0]->get_quantity() == 1);
		sc.RemoveItem(&apple);
		test = sc.get_items();
		REQUIRE(test.size() == 0);
    }
    
    SECTION("Removing an Item from the cart that is not the first"){
        sc.AddItem(&apple);
		sc.AddItem(&bike);
        vector<Item *> test = sc.get_items();
		REQUIRE(test.size() == 2);
		sc.RemoveItem(&bike);
		test = sc.get_items();
		REQUIRE(test.size() == 1);
    }
    
    SECTION("Removing a repeated item") {
		sc.AddItem(&apple);
		sc.AddItem(&bike);
        vector<Item *> test = sc.get_items();
		REQUIRE(test.size() == 2);
		sc.AddItem(&bike);
		test = sc.get_items();
		REQUIRE(test.size() == 3);
		REQUIRE(test[1]->get_quantity() == 2); 
		sc.RemoveItem(&bike);
		REQUIRE(test.size() == 2);
		REQUIRE(test[1]-> get_quantity() == 1);
    }
    
     SECTION("Removing an item from an empty cart") {
		vector<Item *> test = sc.get_items(); 
		REQUIRE(test.size() == 0); 
        sc.RemoveItem(&apple);
        test = sc.get_items();
        REQUIRE(test.size() == 0); 
    }
}
    
TEST_CASE("Clearing the cart", "[Shopping Cart]") {

    SECTION("Clearing a cart") {
		sc.AddItem(&apple); 
        sc.AddItem(&bike);
		vector<Item *> test = sc.get_items();
		REQUIRE(test.size() == 2);
		sc.ClearCart();
		test = sc.get_items();
		REQUIRE(test.size() == 0);
    }
    
    SECTION("Clearing an empty cart") {
		vector<Item *> test = sc.get_items();
		REQUIRE(test.size() == 0);
		sc.ClearCart();
		test = sc.get_items();
		REQUIRE(test.size() == 0);
    }
}  
    
TEST_CASE("Getting the items from the cart", "[GetItems]") {

    SECTION("Getting items from cart") {
		sc.AddItem(&apple); 
        sc.AddItem(&bike); 
		vector<Item *> test = sc.get_items(); 
		REQUIRE(test.size() == 2);  
    }
    
    SECTION("Getting items from empty cart") {
		vector<Item *> test = sc.get_items();
		REQUIRE(test.size() == 0);
    }
}

TEST_CASE("Displaying the contents of the cart", "[DisplayCart]") {

    SECTION("Displaying the cart with items in it") {
        sc.AddItem(&apple);
        sc.AddItem(&bike);
        vector<Item *> test = sc.get_items();
        string str = "";
        stringstream stream;
		stream << fixed << setprecision(2) << test[0]->get_cost(); 
		string s = stream.str();
        str.append(test[0]->get_type() + ": " +  s + " - " + to_string(test[0]->get_quantity()) + "\n");
        stringstream stream2;
        stream2 << fixed << setprecision(2) << test[1]->get_cost();
		s = stream2.str();
        str.append(test[1]->get_type() + ": " + s + " - " + to_string(test[1]->get_quantity()) + "\n"); 
        REQUIRE(sc.DisplayCart() == str);
    }
}