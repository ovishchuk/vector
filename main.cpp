#include <iostream>
#include "vector.hpp"
#include <string>


class Cat
{
public:
    Cat() { name = "null"; }
    Cat(std::string newName) : name(newName) {}
    void say() { std::cout << "Meow!" << std::endl; }
    std::string Name() { return name; }
private:
    std::string name;
};

int main()
{
    ovi::Vector<int> nVector;

    nVector.insertHead(10);
    std::cout << nVector[0] << std::endl;

    int newInt = 9;
    nVector.insertHead(newInt);
    std::cout << nVector[0] << std::endl;

    //================================================//

    ovi::Vector<Cat> catVector;

    catVector.insertHead("Tommy");

    Cat *KittyCat = new Cat("Kitty");
    catVector.insertHead(KittyCat);

    Cat BillyCat("Billy");
    catVector.insertHead(BillyCat);

    catVector.insertTail(new Cat("Donny"));
    catVector.insertTail("Jimmy");

    for ( size_t i = 0; i < catVector.length(); i++ )
    {
        std::cout << catVector[i].Name() << " says ";
        catVector[i].say();
    }

    catVector.eraseTail();

    std::cout << std::endl;
    for ( size_t i = 0; i < catVector.length(); i++ )
    {
        std::cout << catVector[i].Name() << " says ";
        catVector[i].say();
    }

    return 0;
}