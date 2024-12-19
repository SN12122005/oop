#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring> // For strcmp
using namespace std;

class item {
public:
    char name[10];
    int quantity;
    int cost;
    int code;

    bool operator==(const item& i1) const {
        return code == i1.code;
    }

    bool operator<(const item& i1) const {
        return cost < i1.cost;
    }
};

vector<item> o1;

void print(const item& i1);
void display();
void insert();
void search();
void dlt();
bool compare(const item& i1, const item& i2) {
    return i1.cost < i2.cost;
}

void insert() {
    item i1;
    cout << "Enter Item Name : ";
    cin >>i1.name; 
    cout << "Enter Item Quantity: ";
    cin >> i1.quantity;
    cout << "Enter Item Cost: ";
    cin >> i1.cost;
    cout << "Enter Item Code: ";
    cin >> i1.code;

    o1.push_back(i1);
}

void display() {
    if (o1.empty()) {
        cout << "No items to display.\n";
        return;
    }

    for_each(o1.begin(), o1.end(), print);
}

void print(const item& i1) {
    cout << "\n";
    cout << "Item Name: " << i1.name << "\n";
    cout << "Item Quantity: " << i1.quantity << "\n";
    cout << "Item Cost: " << i1.cost << "\n";
    cout << "Item Code: " << i1.code << "\n";
}

void search() {
    vector<item>::iterator p;
    item i1;
    cout << "Enter code to search for an item: ";
    cin >> i1.code;

    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end()) {
        cout << "Item not found.\n";
    } else {
        cout << "Item found:\n";
        print(*p);
    }
}

void dlt() {
    vector<item>::iterator p;
    item i1;
    cout << "Enter item code to delete: ";
    cin >> i1.code;

    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end()) {
        cout << "Item not found.\n";
    } else {
        o1.erase(p);
        cout << "Item deleted.\n";
    }
}

int main() {
    int ch;
    do {
        cout << "\n**** MENU ****\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Search\n";
        cout << "4. Sort (by cost)\n";
        cout << "5. Delete\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                sort(o1.begin(), o1.end(), compare);
                cout << "Items sorted by cost (ascending):\n";
                display();
                break;
            case 5:
                dlt();
                break;
            case 6:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (ch != 6);

    return 0;
}
