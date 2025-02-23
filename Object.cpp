#include <iostream>
using namespace std;
class Car {
public:
string color;
string brand;
void drive() {
cout << "The " << color << " " << brand << " is driving." << endl;
}
};
int main() {
Car myCar;
myCar.color = "Red";
myCar.brand = "Toyota";
myCar.drive();
return 0;
}
