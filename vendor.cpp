#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <vector>

using namespace std;


struct Node{
    string name;
    string order;
    Node *next = nullptr;
};

struct List{
    Node *head;
    Node *tail;
};

void addCustomer(string [], string [], List &);
void removeCustomer(List &);
void printQueue(List &);

int main(){
    //random seed
    srand(time(0));

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

    int ct = 0;

    //linked list
    List line;

    //initializing line with 3 people
    for (int i = 0; i < 3; i++){
        addCustomer(customerNames, drinkOrders, line);
    }

    //simulation
    while (ct < 10){
        cout << "\nRound " << ct + 1 << endl;

        //serving head of line
        if (line.head != nullptr) {
            cout << line.head -> name << " has been served.\n";
            removeCustomer(line);
        }

        //random number from 0 -99
        int ranNum = (rand() % 100);
        if (ranNum <= 49){
            addCustomer(customerNames, drinkOrders, line);
            cout << line.tail -> name << " joined the queue.\n";
        }

        printQueue(line);
        //increasing round counter
        ct++;
    }
    return 0;
}

void addCustomer(string n [] , string o [] , List &l){
    //randomly indexing for arrays
    int name = rand() % 15;
    int order = rand() % 10;

    Node *cust = new Node;
    cust->name = n[name];
    cust->order = o[order];

    //empty list
    if (l.head == nullptr) {
        l.head = cust;
        l.tail = cust;
    //not empty
    } 
    else {
        l.tail->next = cust;
        l.tail = cust;
    }
}

void removeCustomer(List &l){
    //func removes head 
    if (l.head == nullptr) {
        return;
    }

    Node *temp = l.head;
    l.head = l.head->next;

    if (l.head == nullptr) {
        l.tail = nullptr;
    }

    delete temp;

}

void printQueue(List &l){
    //traversing through list to print
    Node *current = l.head;

    cout << "Current queue:\n";
    if (current == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }

    while (current != nullptr) {
        cout << current->name << " - " << current->order << endl;
        current = current->next;
    }
}