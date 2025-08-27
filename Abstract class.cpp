#include <iostream>
using namespace std;

// Abstract class Animal
// This serves as a base class for all animals and enforces that all derived classes implement makeSound().
class Animal{
public:
    virtual void makeSound() const = 0; // Pure virtual function, making this class abstract.
    virtual ~Animal() = default;        // Virtual destructor to allow proper cleanup of derived class objects.
};

// Derived class Dog
// Inherits from Animal and provides a concrete implementation of makeSound().
class Dog : public Animal
{
public:
    void makeSound() const override // Overrides the pure virtual function from Animal
    {
        cout << "Woof!" << endl; // Prints "Woof!" to the console
    }
};

// Derived class Cat
// Inherits from Animal and provides a specific implementation of makeSound().
class Cat : public Animal
{
public:
    void makeSound() const override // Overrides the pure virtual function from Animal
    {
        cout << "Meow!" << endl; // Prints "Meow!" to the console
    }
};

// Derived class Bird
// Inherits from Animal and implements makeSound() with a unique behavior.
class Bird : public Animal
{
public:
    void makeSound() const override // Overrides the pure virtual function from Animal
    {
        cout << "Tweet!" << endl; // Prints "Tweet!" to the console
    }
};

int main()
{
    // Creating objects of derived classes
    Dog dog;
    Cat cat;
    Bird bird;

    // Calling makeSound() for each object
    // Since makeSound() is overridden in each derived class, the appropriate function is executed.
    dog.makeSound();  // Outputs: Woof!
    cat.makeSound();  // Outputs: Meow!
    bird.makeSound(); // Outputs: Tweet!

    return 0; 
}


