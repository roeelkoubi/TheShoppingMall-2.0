#include <iostream>
#include "MallExceptions.h"


template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        deleteList();
    }

    void insert(const T& value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)        
            head = newNode;

        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void remove(const T& value) {
        if (head == nullptr)        
            return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void removeByIndex(int index) {
        if (head == nullptr) {              
            return;
        }

        if (index == 0) {                   
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;
        int currentIndex = 0;

        while (current != nullptr && currentIndex != index) {
            previous = current;
            current = current->next;
            currentIndex++;
        }

        if (current == nullptr) {           
            return;
        }

        previous->next = current->next;     
        delete current;
    }


    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    T getNodeByIndex(int index) const {
        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr) {
            if (currentIndex == index)
                return current->data;

            current = current->next;
            currentIndex++;
        }
        throw GeneralException("Index out of range");
    }

    void deleteList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }
};