#include <iostream>
#include "list.h"


Node* addNode(int newValue, Node* pHead) {
    Node* newNode = new Node;
    newNode->value = newValue;
//    newNode->pNext = nullptr;
    newNode->pNext = pHead;
    /*if (pHead == nullptr) {
        pHead = newNode;
    }
    else {
        Node* last = pHead;
        while (last->pNext != nullptr) {
            last = last->pNext;
        }
        last->pNext = newNode;
    }*/
    return newNode;
}


void printList(Node* pHead) {
    Node* temp = pHead;
    while (temp != nullptr) {
        std::cout << temp->value << " ";
        temp = temp->pNext;
    }
    std::cout << std::endl;
}


void reversePrintList(Node* pHead) {
    if (pHead == NULL) {
        return;
    }
    reversePrintList(pHead->pNext);
    std::cout << pHead->value << " ";
}


void deleteNode(int key, Node* pHead) {
    Node* temp = pHead;
    Node* prev = NULL;
    if (temp == NULL) {
        return;
    }
    
    if (temp != NULL && temp->value == key) {
        pHead = temp->pNext;
        delete temp;
        return;
    }
    while (temp != NULL && temp->value != key) {
        prev = temp;
        temp = temp->pNext;
    }

    prev->pNext = temp->pNext;
    delete temp;
}


void clearList(Node* pHead) {
    Node* current = pHead;
    Node* next;

    while (current != NULL) {
        next = current->pNext;
        delete current;
        current = next;
    }

    pHead = NULL;
}
