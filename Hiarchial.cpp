#include <iostream> 
using namespace std;

// Base class: Animal
class Animal
{
public:
    // Virtual function to allow dynamic (runtime) polymorphism
    virtual void makeSound()
    {
        cout << "Animal sound" << endl;
    }
};

// Derived class: Dog (inherits from Animal)
class Dog : public Animal
{
public:
    // Overriding the makeSound() method specific to Dog
    void makeSound()
    {
        cout << "Woof!" << endl; // Dog makes a barking sound
    }
};

// Derived class: Cat (inherits from Animal)
class Cat : public Animal
{
public:
    // Overriding the makeSound() method specific to Cat
    void makeSound()
    {
        cout << "Meow!" << endl; // Cat makes a meowing sound
    }
};

// Derived class: Bird (inherits from Animal)
class Bird : public Animal
{
public:
    // Overriding the makeSound() method specific to Bird
    void makeSound()
    {
        cout << "Tweet!" << endl; // Bird makes a tweeting sound
    }
};

int main()
{
    // Creating objects of derived classes
    Dog dog;
    Cat cat;
    Bird bird;

    // Calling the overridden makeSound() method for each object
    dog.makeSound();  // Outputs "Woof!"
    cat.makeSound();  // Outputs "Meow!"
    bird.makeSound(); // Outputs "Tweet!"

    return 0; 
}
