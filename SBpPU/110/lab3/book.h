#pragma once

enum CategoryBook { FICTION, MYSTERY, BIOGRAPHY, PROGRAMMING, HISTORY, OTHER };


struct BOOK {
    char author[50];
    char title[50];
    int year;
    double price;
    CategoryBook category;
};

int menu();


//void printInfo(const struct BOOK* book);

void addBook(struct CARD_INDEX* catalog);

void deleteBook(CARD_INDEX* catalog);
