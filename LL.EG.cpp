
/*Create a linked list of the name Person. Store name, 
age and country for each person. 
Store date of at least 4 persons.*/

#include <iostream>
using namespace std;

// Define a structure for a person in the linked list
struct person {
    int age;          // Holds the age of the person
    string name;      // Holds the name of the person
    string country;   // Holds the country of the person
    person* next;     // Pointer to the next node in the list
};

int main() {
    // Create nodes dynamically
    person* first = new person();
    person* second = new person();
    person* third = new person();
    person* fourth = new person();

    // Assign values to the first node and link it to the second node
    first->name = "Nand Kishor";
    first->age = 50;
    first->country = "India";
    first->next = second;

    // Assign values to the second node and link it to the third node
    second->name = "Bob";
    second->age = 40;
    second->country = "USA";
    second->next = third;

    // Assign values to the third node and link it to the fourth node
    third->name = "Abdullah";
    third->age = 35;
    third->country = "UAE";
    third->next = fourth;

    // Assign values to the fourth node and set next to nullptr (end of list)
    fourth->name = "Hamza";
    fourth->age = 90;
    fourth->country = "Turkey";
    fourth->next = nullptr;

    // Traverse the linked list and display details of each person
    person* current = first;
    while (current != nullptr) {
        cout << "Name: " << current->name 
             << ", Age: " << current->age 
             << ", Country: " << current->country << endl;
        current = current->next; // Move to the next node
    }

    // Free allocated memory to avoid memory leaks
    delete first;
    delete second;
    delete third;
    delete fourth;

    return 0;
}

