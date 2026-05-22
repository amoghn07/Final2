#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <vector>
#include <list>
using namespace std;

const int NAME = 15;
const int ORDER = 10;

struct Node{
    string name;
    string order;
    Node *next = nullptr;
};

struct List{
    Node *head = nullptr;
    Node *tail = nullptr;
};

// customer struct for deque
struct Mc{
    string name;
    string order;
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

    string muffinTypes[] = {
        "Blueberry Muffin", "Chocolate Chip Muffin", "Banana Nut Muffin",
        "Bran Muffin", "Apple Cinnamon Muffin", "Lemon Poppy Seed Muffin",
        "Pumpkin Muffin", "Double Chocolate Muffin", "Raspberry Muffin",
        "Cranberry Orange Muffin"
    };

    string braceletTypes[] = {
        "Beaded Bracelet", "Friendship Bracelet", "Charm Bracelet",
        "Leather Bracelet", "Woven Bracelet", "Braided Cord Bracelet",
        "Macrame Bracelet", "Shell Bracelet", "Pearl Bracelet",
        "Hemp Bracelet"
    };

    string bagTypes[] = {
        "Canvas Tote", "Leather Satchel", "Backpack", "Messenger Bag",
        "Crossbody Bag", "Clutch", "Duffel Bag", "Bucket Bag",
        "Fanny Pack", "Drawstring Bag"
    };

    int ct = 0;

    //linked list
    List line;

    //deque for muffin customers
    deque<Mc> mline;

    //vector for bracelet customers
    vector<Mc> bline;

    //list for bag customer
    list<Mc> nline;

    //initializing lines with 3 people
    for (int i = 0; i < 3; i++){
        //add node
        addCustomer(customerNames, drinkOrders, line);

        //add muffin customer
        Mc muffin;
        muffin.name = customerNames[rand() % NAME];
        muffin.order = muffinTypes[rand() % ORDER];
        mline.push_back(muffin);

        //add bracelet customer
        Mc bracelet;
        bracelet.name = customerNames[rand() % NAME];
        bracelet.order = braceletTypes[rand() % ORDER];
        bline.push_back(bracelet);

        //add bag customer
        Mc bag;
        bag.name = customerNames[rand() % NAME];
        bag.order = bagTypes[rand() % ORDER];
        nline.push_back(bag);
    }

    //simulation
    while (ct < 10){
        cout << "\nRound " << ct + 1 << endl;

        // SIM FOR LINKED LIST 
        if (line.head != nullptr) {
            cout << "Served (Coffee): " << line.head->name << " - " << line.head->order << "\n";
            removeCustomer(line);
        } 
        else {
            cout << "Served (Coffee): (none)\n";
        }

        //random number from 0 -99
        int ranNum = (rand() % 100);
        if (ranNum <= 49){
            addCustomer(customerNames, drinkOrders, line);
            cout << "Joined (Coffee): " << line.tail->name << " - " << line.tail->order << "\n";
        }

        cout << "Coffee queue:\n";
        printQueue(line);


        // SIM FOR DEQUE (Muffin Booth)
        if (!mline.empty()) {
            cout << "Served (Muffin): " << mline.front().name << " - " << mline.front().order << "\n";
            mline.pop_front();
        } 
        else {
            cout << "Served (Muffin): (none)\n";
        }

        int ranNumM = (rand() % 100);
        if (ranNumM <= 49){
            Mc m;
            m.name = customerNames[rand() % NAME];
            m.order = muffinTypes[rand()% ORDER];
            mline.push_back(m);
            cout << "Joined (Muffin): " << mline.back().name << " - " << mline.back().order << "\n";
        }

        cout << "Muffin queue:\n";
        if (mline.empty()){
            cout << "Muffin queue is empty.\n";
        } 
        else {
            for (const auto c : mline){
                cout << c.name << " - " << c.order << endl;
            }
        }

        //SIM FOR VECTOR
        if (!bline.empty()){
            cout << bline.front().name << " has been served.\n";
            bline.erase(bline.begin());
        
        }
        int ranNumB = (rand() % 100);

        if(ranNumB <= 49){
            Mc b;
            b.name = customerNames[rand() % NAME];
            b.order = braceletTypes[rand()% ORDER];
            bline.push_back(b);
            cout << "Joined (Bracelet): " << bline.back().name << " - " << bline.back().order << "\n";
        }

        //print bracelet queue
        cout << "Bracelet queue:\n";
        if (bline.empty()){
            cout << "Bracelet queue is empty.\n";
        } 
        else {
            for (const auto c : bline){
                cout << c.name << " - " << c.order << endl;
            }
        }

        // SIM FOR LIST
        if (!nline.empty()){
            cout << "Served (Bag): " << nline.front().name << " - " << nline.front().order << "\n";
            nline.pop_front();
        } 
        else {
            cout << "Served (Bag): (none)\n";
        }

        int ranNumN = (rand() % 100);
        if (ranNumN <= 49){
            Mc n;
            n.name = customerNames[rand() % NAME];
            n.order = bagTypes[rand() % ORDER];
            nline.push_back(n);
            cout << "Joined (Bag): " << nline.back().name << " - " << nline.back().order << "\n";
        }

        cout << "Bag queue:\n";
        if (nline.empty()){
            cout << "Bag queue is empty.\n";
        }
        else {
            for (auto c : nline){
                cout << c.name << " - " << c.order << endl;
            }
        }


        //increasing round counter
        ct++;
    }
    return 0;
}

void addCustomer(string n [] , string o [] , List &l){
    //randomly indexing for arrays
    int name = rand() % NAME;
    int order = rand() % ORDER;

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
    
    if (current == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }

    while (current != nullptr) {
        cout << current->name << " - " << current->order << endl;
        current = current->next;
    }
}