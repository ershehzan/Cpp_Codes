#include <iostream>
using namespace std;

struct person {
    int age;
    string name;
    string country;
    person* next; // Points to the next node
};

int main() {
    // Create nodes
    person* first = new person();
    person* second = new person();
    person* third = new person();
    person* fourth = new person();

    // Assign values and link nodes
    first->name = "Nand Kishor";
    first->age = 50;
    first->country = "India";
    first->next = second;

    second->name = "Bob";
    second->age = 40;
    second->country = "USA";
    second->next = third;

    third->name = "Abdulla";
    third->age = 35;
    third->country = "UAE";
    third->next = fourth;

    fourth->name = "Hamza";
    fourth->age = 90;
    fourth->country = "Turkey";
    fourth->next = nullptr;

    // Traverse and display details
    person* current = first;
    while (current != nullptr) {
        cout << "Name: " << current->name 
             << ", Age: " << current->age 
             << ", Country: " << current->country << endl;
        current = current->next;
    }

    return 0;
}
