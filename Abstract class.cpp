#include <iostream>

using namespace std;

// Abstract class Animal
class Animal
{
public:
    virtual void makeSound() const = 0; // Pure virtual function
    virtual ~Animal() = default;        // Virtual destructor
};

// Derived class Dog
class Dog : public Animal
{
public:
    void makeSound() const override
    {
        cout << "Woof!" << endl;
    }
};

// Derived class Cat
class Cat : public Animal
{
public:
    void makeSound() const override
    {
        cout << "Meow!" << endl;
    }
};

// Derived class Bird
class Bird : public Animal
{
public:
    void makeSound() const override
    {
        cout << "Tweet!" << endl;
    }
};

int main()
{
    Dog dog;
    Cat cat;
    Bird bird;

    dog.makeSound();
    cat.makeSound();
    bird.makeSound();

    return 0;
}