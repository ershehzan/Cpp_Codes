#include <iostream>
using namespace std;

// Class definition for Person
class Person {
public:
    string name;  // Stores the person's name
    int age;      // Stores the person's age

    // Constructor to initialize name and age
    Person(string personName, int personAge) {
        name = personName;
        age = personAge;
    }

    // Method to greet with the person's name
    void greet() {
        cout << "Hello, my name is " << name << "." << endl;
    }
};

int main() {
    // Creating an object of the Person class
    Person person1("Nand", 25);

    // Calling the greet method
    person1.greet();

    return 0;
}
