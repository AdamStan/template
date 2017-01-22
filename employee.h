#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee 
{
public:
    string name, position;
    unsigned int age;
    Employee()
    {
        name = "\0";
        position = "\0";
        age = 0;
    }
    Employee(string n_name, string n_position, unsigned int n_age)
    {
        name = n_name;
        position = n_position;
        age = n_age;
    }
    ~Employee(){};
    Employee(const Employee& who)
    {
        name = who.name;
        position = who.position;
        age = who.age;
    }
    Employee& operator= (const Employee& who)
    {
        this->name = who.name;
        this->position = who.position;
        this->age = who.age;
        return *this;
    }
    friend ostream& operator<< (ostream& os, Employee& co)
    {
        os <<"Name: " << co.name << endl;
        os <<"Position: " << co.position << endl;
        os <<"Age: " << co.age << endl;
        return os;
    }
};

#endif
