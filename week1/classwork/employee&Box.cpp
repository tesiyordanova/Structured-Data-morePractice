// classwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Employee {
    char name[100];
    double salary;
    Employee* boss;

    Employee(char* n, double s) {
        strcpy(name, n);
        salary = s;
        boss = nullptr;
    }

    Employee* findSuperBoss(Employee* e)
    {
        while (e->boss != nullptr)
        {
            e = e->boss;
            return e;
        }
    }

    Employee* findSuperBossRec(Employee* e) {
        if (e->boss==nullptr)
        {
            return e;
        }
        return findSuperBossRec(e->boss);
    }
};

struct Box {
    int data;
    Box* next;

    Box(int d, Box*n):data(d),next(n){}

    

};

int main()
{
    char stoyanName[100] = "Stoyan Petrov Ivanov";
    char ivanName[100] = "Ivan Petrov Ivanov";
    char ramzesName[100] = "Ramzes II";
    Employee stoyan (stoyanName, 700 ),
        ivan(ivanName, 800),
        ramzes(ramzesName, 1100);

    stoyan.boss = &ivan;
    ivan.boss = &ramzes;


    //insert infornt
    Box* first = new Box(1, new Box(2, nullptr));
    Box* newBox = new Box(3, nullptr);
    newBox->next = first;
    first = newBox;
    std::cout << first->data<<std::endl;

    //traversing 
    Box* crr = first;
    while (crr!=nullptr)
    {
        std::cout << crr->data << " ";
        crr = crr->next;
    }
    std::cout << std::endl;


    //insert in the middle
    first = new Box(1, new Box(2, new Box(3, nullptr)));
    Box* temp = first;
    while (2!=temp->data)
    {
        temp = temp->next;
    }
    Box* newOne = new Box(4, nullptr);
    newOne->next = temp->next;
    temp->next = newOne;
    while (first != nullptr)
    {
        std::cout << first->data << " ";
        first = first->next;
    }
    std::cout << std::endl;
    
    //delete first
    first = new Box(1, new Box(2, new Box(3, nullptr)));
    Box* save = first;
    first = first->next;
    delete save;
    while (first != nullptr)
    {
        std::cout << first->data << " ";
        first = first->next;
    }
    std::cout << std::endl;

    //delete in the middle
    first = new Box(1, new Box(2, new Box(3, new Box(4, nullptr))));
    Box* use = first;
    while (use->data!=3)
    {
        use = use->next;
    }
    Box* saveBox = use->next;
    use->next = use->next->next;
    delete saveBox;
    while (first != nullptr)
    {
        std::cout << first->data << " ";
        first = first->next;
    }
    std::cout << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
