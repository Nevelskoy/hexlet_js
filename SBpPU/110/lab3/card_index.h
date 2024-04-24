#pragma once
#include "book.h"

struct CARD_INDEX {
    BOOK** pB;
    size_t count;
    size_t capacity;
};

void printCatalog(const CARD_INDEX* catalog);

void exportCatalog(const CARD_INDEX* catalog);

void importCatalog(CARD_INDEX* catalog);

void clearCARD(CARD_INDEX* catalog);
