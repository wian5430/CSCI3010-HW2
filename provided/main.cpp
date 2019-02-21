/**
William Anderson
Homework 2
This program allows a user to access an 
electronic store.
*/

#include<iostream>
#include "Item.h"
#include "Store.h"
#include "TextUI.h"

int main(int argc, char *argv[]) {
    if(argc == 2) {
        Store store(argv[1]);
        TextUI menu;
		std::string choice;
		while(choice != "Leave") {
			choice = menu.MainMenu(); 
			menu.RouteChoice(store, choice);
		}
		return 0;
	} else {
		return 0;
	}
}