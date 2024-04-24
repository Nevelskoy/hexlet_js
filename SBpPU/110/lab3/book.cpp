#include <cstdio>
#include <conio.h>
#include <cctype>
#include "book.h"
#include "card_index.h"


//const char* strCategory[] = { "FICTION", "MYSTERY", "BIOGRAPHY", "PROGRAMMING", "HISTORY", "OTHER" };

void addBook(CARD_INDEX* catalog) {
    BOOK* newBook = new BOOK;
    printf("Input the author: ");
    scanf_s("%49s", newBook->author,50);
    printf("Input the title: ");
    scanf_s("%49s", newBook->title,50); 

    do {
        printf("Enter the year of publication: ");
        newBook->year = 0;
        scanf_s(
            "%d", &newBook->year);
        if (newBook->year < 1500) {
            printf("Invalid year. Let's try again\n");
            scanf_s("%*s"); //  clear the input buffer
        }
    } while (newBook->year < 1500);

    do {
        printf("Enter the price: ");
        scanf_s("%lf", &newBook->price);
        if (newBook->price < 1) {
            printf("Invalid price. Let's try again\n");
            scanf_s("%*s"); //  clear the input buffer
        }
    } while (newBook->price < 1);

    int input = -1;
    printf("Enter the category: ");
    printf("0-FICTION, 1-MYSTERY, 2-BIOGRAPHY, 3-PROGRAMMING, 4-HISTORY\n");
    scanf_s("%d", &input);
    if ((input >= FICTION) && (input <= HISTORY)) {
        newBook->category = static_cast<CategoryBook>(input);

    } else newBook->category = OTHER;

    catalog->pB[catalog->count] = newBook;
    catalog->count++;
    printf("The book has been successfully added!");
    printf("\nPress any key to return to the menu\n");
    _getch();
}


void deleteBook(CARD_INDEX* catalog) {
    int input = -1;

    do {
        printf("Enter the number from 1 to %d:\n", catalog->count);
        scanf_s("%d", &input);

    } while (input < 1 || input > catalog->count);

    int idx = input - 1;
    catalog->count--;
    delete catalog->pB[idx];
    catalog->pB[idx] = nullptr;
    
    for (int i = idx; i < catalog->count; i++) {
        catalog->pB[i] = catalog->pB[i + 1];
    }
    printf("The book has been deleted!");
    printf("\nPress any key to return to the menu\n");
    _getch();
}
