#include <iostream>
using namespace std;

// Class definition for Car
class Car {
public:
    string color;  // Stores the car's color
    string brand;  // Stores the car's brand

    // Method to simulate driving the car
    void drive() {
        cout << "The " << color << " " << brand << " is driving." << endl;
    }
};

int main() {
    // Creating an object of the Car class
    Car myCar;

    // Setting properties of the car
    myCar.color = "Red";
    myCar.brand = "Toyota";

    // Calling the drive method
    myCar.drive();

    return 0; // Indicate successful program execution
}
