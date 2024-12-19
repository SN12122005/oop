#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> states = {{"Maharashtra", 120000000}, {"Karnataka", 60000000},{"Goa" , 4500000}};
    string stateName;

    cout << "Enter state name: ";
    cin >> stateName;

    map<string,int>::iterator it = states.find(stateName);
    if (it != states.end()) {
        cout << "Population of " << stateName << ": " << it->second << endl;
    } else {
        cout << "State not found." << endl;
    }

    return 0;
}
