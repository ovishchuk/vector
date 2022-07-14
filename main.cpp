#include <iostream>
#include "list.hpp"
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
    List<int> nList;

    nList.insertHead(10);
    std::cout << nList[0] << std::endl;

    int newInt = 9;
    nList.insertHead(newInt);
    std::cout << nList[0] << std::endl;

    //================================================//

    List<Cat> catList;

    catList.insertHead("Tommy");

    Cat *KittyCat = new Cat("Kitty");
    catList.insertHead(KittyCat);

    Cat BillyCat("Billy");
    catList.insertHead(BillyCat);

    catList.insertTail(new Cat("Donny"));
    catList.insertTail("Jimmy");

    for ( size_t i = 0; i < catList.length(); i++ )
    {
        std::cout << catList[i].Name() << " says ";
        catList[i].say();
    }

    catList.eraseTail();

    std::cout << std::endl;
    for ( size_t i = 0; i < catList.length(); i++ )
    {
        std::cout << catList[i].Name() << " says ";
        catList[i].say();
    }

    return 0;
}