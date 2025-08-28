#include<bits/stdc++.h>
using namespace std;

class Animal {
    public:
    void makeSound() {
        std::cout << "Animal sound" << std::endl;
    }
}s

class Dog : public Animal {
    public:
    void makeSound() {
        std::cout << "Bark" << std::endl;
    }
};

class Cat : public Animal {
    public:
    void makeSound() {
        std::cout << "Meow" << std::endl;
    }
};

void main() {
    Animal * a = new Dog();
    cout << "can we see this?" << endl;
    a->makeSound();
}