#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Node{
    string name;
    string order;
    Node *next;
};

struct List{
    Node *head;
    Node *tail;
};

void addCustomer(string [], string [], List *);

int main(){

    //generated data arrays
    string customerNames[] = {
        "Ava", "Noah", "Mia", "Liam", "Emma",
        "Sophia", "Lucas", "Olivia", "Ethan", "Isabella",
        "Mason", "Charlotte", "Elijah", "Amelia", "James"
    };

    string drinkOrders[] = {
        "Latte", "Cappuccino", "Espresso", "Americano", "Mocha",
        "Caramel Macchiato", "Cold Brew", "Iced Coffee", "Chai Latte", "Flat White"
    };
    return 0;
}

void addCustomer(string n [] , string o [] , List *l){
    
}