#pragma once


struct Node {
	int value;
	Node* pNext;
};

Node* addNode(int newData, Node* pHead);

void printList(Node* pHead);

void reversePrintList(Node* pHead);

void deleteNode(int key, Node* pHead);

void clearList(Node* pHead);
