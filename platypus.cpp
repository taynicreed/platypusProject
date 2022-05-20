/*
    file: platypus.cpp
    summary: Implementation of the class Platypus
    author: Taylor Reed
    date: 5/21/21
    environment: VS code
*/


#include <cstdlib> // random
#include <ctime> // time
#include <fstream>
#include <iostream>
using namespace std;

string Platypus::nameGenerator(char sx)
{
    string name;
    string oneLine;
    int line = 0;
    int randNum = rand() % 51 + 1;
    ifstream fin; 

    if(sx == 'f')
    {
        fin.open("f_names.txt");
        if(fin.fail())
        {
            cout << "Error opening input file.\n";
            exit(1);
        }
       

        while(getline(fin, oneLine))
        {
            line++;
            if(line == randNum)
            {
                getline(fin, name);
            }
        }
        fin.close();
    }
    else
    {
        fin.open("m_names.txt");
        if(fin.fail())
        {
            cout << "Error opening input file.\n";
            exit(1);
        }
        while(getline(fin, oneLine))
        {
            line++;
            if(line == randNum)
            {
                getline(fin, name);
            }
        }
        fin.close();
    }

    return name; 
}

Platypus::Platypus()
{
    weight = 0.0;
    age = 0;
    name = "";
    sex = ' ';
    isAlive = false;
    isMutant = true;
}

Platypus::Platypus(float w, int a, string n, char s)
{
    weight = w;
    age = a;
    name = n;
    sex = s;
    isAlive = true;
    isMutant = false;
}

void Platypus::print()
{
    cout << "Name: " << name << endl
         << "Age: " << age << " months\n"
         << "Weight: " << weight << " pounds\n"
         << "Sex: " << sex << endl
         << "Alive? ";
    if(isAlive == true)
        cout << "true\n";
    else
        cout << "false\n";
    cout << "Mutant? ";
    if(isMutant == true) 
        cout << "true\n\n";
    else
        cout << "false\n\n";
}


void Platypus::ageMe()
{
    int randNum = rand() % 100 + 1;
    int mortRate;

    if(isAlive == false)
        cout << "A dead platypus can't age.\n";
    else
    {
        age ++; 
        if(isMutant == false)
        {
            if(randNum == 4)
                isMutant = true; 
        }
        if(weight >= 10)
            isAlive = false;
        else
        {
            mortRate = weight * 10; 
            randNum = rand() % 100;
            for(int i = 0; i < mortRate; i++)
            {
                int deathNum = rand() % 100;
                if(deathNum == randNum)
                    isAlive = false;
            }
        }
        
    }


}

void Platypus::fight(Platypus enemy)
{
    if(isAlive == false || enemy.isAlive == false)
    {
        cout << "One or both platypi are already dead...that's not a fair "
                "fight\n\n";
        return; 
    }
    float fightRatio = (weight / enemy.weight) * 50;
    int randNum = rand() % 1 + 100;
    if(randNum < fightRatio)
    {
        enemy.isAlive = false;
        cout << name << " won the fight.\n\n";
    }
    else
    {
        isAlive = false;
        cout << enemy.name << " won the fight.\n\n";
    }
}

void Platypus::eat()
{
    if(isAlive == false)
    {
        cout << "A dead platypus can't eat!\n";
        return;
    }
    int randNum = rand() % 50 + 1;
    float increase = static_cast<float>(randNum)/100 + 1;
    weight = weight * increase;
    
    return;
}

Platypus hatch()
{
    
    char s;
    string n;
    float w;
    int a = 0;

    int randNum = rand() % 2 + 1;
    if(randNum == 1)
    {
        s = 'f';
    }
        
    else
    {
        s = 'm';
    }
    randNum = rand() % 10 + 1;
    w = static_cast<float>(randNum) / 10.0;

    Platypus newP(w, a, newP.nameGenerator(s), s);
    

    
    return newP;
}
        