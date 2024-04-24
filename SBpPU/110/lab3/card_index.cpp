#include <iostream>
#include <conio.h>
#include "book.h"
#include "card_index.h"


int menu() {
	int cmd = 0;
    printf("----------------MENU------------------\n");
	printf("1 - View the book catalog.\n");
	printf("2 - Enter a new book.\n");
    printf("3 - Export data to the file.\n");
    printf("4 - Import data from the file.\n");
	printf("5 - Delete a book.\n");
	printf("0 - Exit.\n");
    printf("--------------------------------------\n");
	scanf_s("%d", &cmd);
	return cmd;
}


void printCatalog(const CARD_INDEX* catalog) {
    if (catalog->count != 0) {
        for (size_t i = 0; i < catalog->count; i++) {
            std::cout << "Book " << i + 1 << " --- " << "(" \
                << "Author: " << catalog->pB[i]->author << ", " \
                << "Title: " << catalog->pB[i]->title << ", " \
                << "Year: " << catalog->pB[i]->year << ", " \
                << "Price: " << catalog->pB[i]->price << ", " \
                << "Category: ";
            switch (catalog->pB[i]->category) {
            case FICTION:
                printf("FICTION");
                break;
            case MYSTERY:
                printf("MYSTERY");
                break;
            case BIOGRAPHY:
                printf("BIOGRAPHY");
                break;
            case PROGRAMMING:
                printf("PROGRAMMING");
                break;
            case HISTORY:
                printf("HISTORY");
                break;
            default:
                printf("OTHER");
            }
            std::cout << ")" << std::endl;
        }
    }
    else {
        printf("The catalog is empty!");
    }
    printf("\nPress any key to return to the menu\n");
    _getch();
}


void exportCatalog(const CARD_INDEX* catalog) {
    FILE* file;
    fopen_s(&file, "data.txt", "w");

    if (file != NULL) {
        fprintf(file, "Number of books: %d\n", catalog->count);
        for (size_t i = 0; i < catalog->count; i++)
        {
            fprintf(file, "\nAuthor: %15s Title: %15s Year: %4d Price: %.2f Category: %d", catalog->pB[i]->author, catalog->pB[i]->title, catalog->pB[i]->year, catalog->pB[i]->price, catalog->pB[i]->category);
        }
        fclose(file);
        printf("Export finished");
        printf("\nPress any key to return to the menu\n");
        _getch();
    }
    else {
        std::cout << "Error! The file is unavailable!" << std::endl;
    }
}


void importCatalog(CARD_INDEX* catalog) {
    FILE* file = nullptr;
    fopen_s(&file, "data.txt", "r");
    if (file != NULL) {
        clearCARD(catalog);
        fscanf_s(file, "Number of books: %d", &(catalog->count));
        catalog->pB = new BOOK * [catalog->count];
        catalog->capacity = catalog->count;
        for (size_t i = 0; i < catalog->count; i++) {
            int tmp = -1;
            catalog->pB[i] = new BOOK;
            fscanf_s(file, " Author: %15s", catalog->pB[i]->author, _countof(catalog->pB[i]->author));
            fscanf_s(file, " Title: %15s", catalog->pB[i]->title, _countof(catalog->pB[i]->title));
            fscanf_s(file, " Year: %4d", &catalog->pB[i]->year);
            fscanf_s(file, " Price: %lf", &catalog->pB[i]->price);
            fscanf_s(file, " Category: %d", &tmp);
            catalog->pB[i]->category = static_cast<CategoryBook>(tmp);
        }
        fclose(file);
        printf("The data has been downloaded!");
        printf("\nPress any key to return to the menu\n");
        _getch();
    }
    else {
        std::cout << "Error! The data is unavailable!" << std::endl;
    }
}


void clearCARD(CARD_INDEX* catalog) {

    for (size_t i = 0; i < catalog->count; i++)
    {
        delete catalog->pB[i];
    }
    delete[] catalog->pB;
    catalog->pB = nullptr;
}
