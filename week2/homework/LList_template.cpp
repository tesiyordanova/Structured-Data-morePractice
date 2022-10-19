// homework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T> 
class LList {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* first;

    void copy(const LList& other) {
        if (other.first == nullptr) return;
        first = new Node{ other.first->data, nullptr };

        Node* save = first;
        Node* otherCurr = other.first->next;

        while (otherCurr != nullptr)
        {
            first->next = new Node{ otherCurr->data, nullptr };
            first = first->next;
            otherCurr = otherCurr->next;
        }
        first = save;
       
    }

    void destroy() {
        while (first!=nullptr)
        {
            Node* save = first;
            first = save->next;
            delete save;
        }
    }

public:
    LList() {
        first = nullptr;
    }
    
    LList(const LList& other) {
        copy(other);
    }

    const LList& operator=(const LList& other) {
        if (this!=&other)
        {
            destroy();
            copy(&other);
        }
        return *this;
    }

    void print() {
        while (first!=nullptr)
        {
            std::cout << first->data << " ";
            first = first->next;
        }
        std::cout << std::endl;
    }

    //12.01
    void count(int x) {
        if (first == nullptr) return 0;

        size_t counter = 0;
        while (first!=nullptr)
        {
            if (first->data == x) counter++;

            first = first->next;
        }
        return counter;
    }

    //12.02
    void push(const T& elem) {
        first = new Node{ elem, first };
    }

    LList(int x, int y) {
        while (y>=x)
        {
            push(y);
            y--;
        }
    }

    //12.03
    void push_back(const T& elem) {
        Node* crr = first;
        while (crr->next!=nullptr)
        {
            crr = crr->next;
        }
        crr->next = new Node{ elem, nullptr };
    }

    //12.04
    LList& operator+=(const T& other) {
        push_back(other);
        return *this;
    }

    //12.07
    void append(const LList& other) {
        Node* other_first = other.first;
        while (other_first!=nullptr)
        {
            push_back(other_first->data);
            other_first = other_first->next;
        }
    }
};

int main()
{
    LList<int> list1(1, 2);
    list1.push_back(3);
    list1 += 4;

    LList<int> list2(10, 11);
    LList<int> listMix(list1);
    listMix.append(list2);

    listMix.print();
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
