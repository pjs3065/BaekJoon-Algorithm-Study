#include <iostream>
#include <string>
using namespace std;
class Animal {
protected :
   bool isMammal;
   bool isCarnivorous;

public:
   Animal(bool isMammal, bool isCarnivorous) {
      this->isMammal = isMammal;
      this->isCarnivorous = isCarnivorous;
   }
   bool getIsMammal() {
      return this->isMammal;
   }
   bool getIsCarnivorous() {
      return this->isCarnivorous;
   }

   virtual string getGreeting() = 0;

   void printAnimal(string name) {
      cout << "A " << name << " says '" << this->getGreeting() << "', is " << (this->getIsCarnivorous() ? "" : "not") << "carnivorous, and is " <<
         (this->getIsMammal ? "" : "not") << "a mammal." << endl;
   }
};
class Dog : public Animal {
   public:
   Dog() :Animal(true, true) {
   };
   string getGreeting() {
      return string("ruff");
   }
};
class Cow : public Animal {
public:

   Cow() :Animal(false, true) {
   };
   string getGreeting() {
      return string("moo");
   }
};
class Duck : public Animal {
public:
   Duck() :Animal(false, false) {};
   string getGreeting() {
      return string("quack");
   }
};
int main() {
   Dog dog;
   Animal *pointer = &dog;
   dog.printAnimal("dog");

   Cow cow;
   pointer = &cow;
   cow.printAnimal("cow");

   Duck duck;
   pointer = &duck;
   duck.printAnimal("duck");
}