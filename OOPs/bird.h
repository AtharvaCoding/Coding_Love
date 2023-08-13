#if !defined(BIRD_H)
#define BIRD_H

#include <iostream>

class Bird
{
public:
    virtual void eat() = 0;
    virtual void fly() = 0;
};

class sprrow : public Bird
{
public:
    void eat()
    {
        std::cout << "Sprrow is eating" << std::endl;
    }
    void fly()
    {
        std::cout << "Sprrow is flying" << std::endl;
    }
};
class pigion : public Bird
{
public:
    void eat()
    {
        std::cout << "pigion is eating" << std::endl;
    }
    void fly()
    {
        std::cout << "pigion is flying" << std::endl;
    }
};
class eagle : public Bird
{
public:
    void eat()
    {
        std::cout << "eagle is eating" << std::endl;
    }
    void fly()
    {
        std::cout << "eagle is flying" << std::endl;
    }
};

#endif // BIRD_H
