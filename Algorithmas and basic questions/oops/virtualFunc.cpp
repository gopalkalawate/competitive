#include <iostream>

class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal makes a generic sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Dog barks: Woof! Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Cat meows: Meow! Meow!" << std::endl;
    }
};

int main() {
    Animal* animalPtr;

    Dog myDog;
    Cat myCat;

    animalPtr = &myDog;
    animalPtr->makeSound(); // Calls Dog's makeSound()

    animalPtr = &myCat;
    animalPtr->makeSound(); // Calls Cat's makeSound()

    return 0;
}
