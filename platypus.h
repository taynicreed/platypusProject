/*
    file: platypus.cpp
    summary: definition of the class Platypus
    author: Taylor Reed
    date: 5/21/21
    environment: VS code
*/

#ifndef PLATYPUS_H
#define PLATYPUS_H
#include <string>
#include <iostream>
#include <iomanip> // static cast
#include <fstream>
#include <sstream> // string streams

using namespace std;

class Platypus
{
    private:
        float weight;
        int age;
        string name;
        char sex;
        bool isAlive;
        bool isMutant;

    public:
        Platypus(); // default, dead platypus
        Platypus(float, int, string, char); // pass weight, age, name, sex
        ~Platypus(){}

        void setWeight(float w) { weight = w; }
        void setAge(int a) { age = a; }
        void setName(string n) { name = n; }
        void setSex(char s) { sex = s; }
        void setIsAlive(bool a) { isAlive = a; }
        void setIsMutant(bool m) { isMutant = m; }

        string nameGenerator(char);
        float getWeight() { return weight; }
        int getAge() { return age; }
        string getName() { return name; }
        char getSex() { return sex; }
        bool getIsAlive() { return isAlive; }
        bool getisMutant() { return isMutant; }

        void print();
        void ageMe();
        void fight(Platypus); 
        void eat();
        friend Platypus hatch();
        

};

#include "platypus.cpp"
#endif