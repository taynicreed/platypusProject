/*
    file: platypus.cpp
    summary: definition of the class Platypus
    author: Taylor Reed
    date: 5/21/21
    environment: VS code
*/

#include "platypus.h"

int main()
{
    srand(time(NULL));srand(time(NULL)); 
    
    Platypus p1;
    Platypus p2(11, 22, "Charlie", 'f');
    Platypus p3(hatch());
    Platypus p4(5.3, 15, "Cole", 'm');
    Platypus p5(hatch());

    cout << "\tTesting constructors\n";
    p1.print();
    p2.print();
    p4.print();
    cout << endl; 
    cout << "\tTesting hatch function\n";
    p3.print();
    p5.print();
    cout << endl << endl;

    p1.setAge(15);
    p1.setName("Jet");
    p1.setSex('f');
    p1.setWeight(1.2);
    p1.setIsMutant(true);
    p1.setIsAlive(false);

    cout << "\tTesting mutators\n";
    p1.print(); 
    cout << endl << endl; 

    cout << "\tTesting ageMe function\n";
    p1.ageMe();
    p1.print();
    p2.ageMe();
    p2.print();
    p3.ageMe();
    p3.print();
    p4.ageMe();
    p4.print();
    cout << endl << endl;

    cout << "\tTesting eat function\n";
    p1.eat();
    p1.print();
    p2.eat();
    p2.print();
    p3.eat();
    p3.print();
    p4.eat();
    p4.print();
    cout << endl << endl; 

    cout << "\tTesting fight function\n\n";
    cout << p3.getName() << " vs " << p4.getName() << endl;
    p3.fight(p4);
    p3.print();
    p4.print();

    if(p3.getIsAlive() == true)
    {
        cout << p5.getName() << " vs " << p3.getName() << endl;
        p5.fight(p3);
        p3.print();
        p5.print();
    }
    else
    {
        cout << p5.getName() << " vs " << p4.getName() << endl; 
        p5.fight(p4);
        p4.print();
        p5.print();
    }

    return 0;
}