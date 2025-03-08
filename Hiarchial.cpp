#include <iostream>

using namespace std;


class Animal
{
public:
    void makeSound(){
        cout << "Animal sound" << endl;
    }
};

// Derived class Dog
class Dog : public Animal
{
public:
    void makeSound()
    {
        cout << "Woof!" << endl;
    }
};

// Derived class Cat
class Cat : public Animal
{
public:
    void makeSound()
    {
        cout << "Meow!" << endl;
    }
};

// Derived class Bird
class Bird : public Animal
{
public:
    void makeSound()
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