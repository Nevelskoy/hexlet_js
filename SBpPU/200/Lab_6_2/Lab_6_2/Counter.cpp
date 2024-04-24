#include "Counter.h"

Counter* Counter::m_pHead = nullptr;
size_t Counter::m_curCounters = 0;


//Counter::Counter() {
//    m_pStr = new char[strlen("default string") + 1];
//    strcpy(m_pStr, "default string");
//    m_nOwners = 1;
//    pNext = nullptr;
//    if (!m_pHead) {
//        m_pHead = this;
//    }
//    else {
//        Counter* temp = m_pHead;
//        while (temp->pNext) {
//            temp = temp->pNext;
//        }
//        temp->pNext = this;
//    }
//    m_curCounters++;
//}


Counter::Counter(const char* str) {
    m_pStr = new char[strlen(str) + 1];
    strcpy(m_pStr, str);
    m_nOwners = 1;
    pNext = nullptr;

    if (!m_pHead) {
        m_pHead = this;
    }
    else {
        Counter* temp = m_pHead;
        while (temp->pNext) {
            temp = temp->pNext;
        }
        temp->pNext = this;
    }
    m_curCounters++;
}


Counter::~Counter() {
    if (m_pStr != nullptr) {
        delete[] m_pStr;
    }
    m_curCounters--;
}


const char* Counter::getStr() const {
    return m_pStr;
}


void Counter::addUser() {
    m_nOwners++;
}


void Counter::removeUser() {
    m_nOwners--;
    if (m_nOwners == 0) {
        // remove the counter if no more owners
        Counter* prev = nullptr;
        Counter* curr = m_pHead;
        while (curr != nullptr) {
            if (curr == this) {
                if (prev != nullptr) {
                    prev->pNext = curr->pNext;
                }
                else {
                    m_pHead = curr->pNext;
                }
                delete this;
                break;
            }
            prev = curr;
            curr = curr->pNext;
        }
    }
}


void Counter::changeCaseAll() {
    Counter* temp = m_pHead;
    while (temp) {
        for (int i = 0; i < strlen(temp->m_pStr); i++) {
            if (temp->m_pStr[i] >= 'a' && temp->m_pStr[i] <= 'z') {
                temp->m_pStr[i] -= 32;
            }
            else if (temp->m_pStr[i] >= 'A' && temp->m_pStr[i] <= 'Z') {
                temp->m_pStr[i] += 32;
            }
        }
        temp = temp->pNext;
    }
}


void Counter::sortAll() {
    Counter* temp = m_pHead;
    Counter* innerTemp = nullptr;
    char* swap;
    while (temp) {
        innerTemp = temp->pNext;
        while (innerTemp) {
            if (strcmp(temp->m_pStr, innerTemp->m_pStr) > 0) {
                swap = innerTemp->m_pStr;
                innerTemp->m_pStr = temp->m_pStr;
                temp->m_pStr = swap;
            }
            innerTemp = innerTemp->pNext;
        }
        temp = temp->pNext;
    }
}



///////////////////////////////////////////////////////
