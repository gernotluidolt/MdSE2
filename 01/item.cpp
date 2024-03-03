#include "item.h"
#include <string>

void initItem(Item_t* ITEM, char* name, int gold) {
    ITEM->name = name;
    ITEM->value = gold;
    ITEM->isValid = true;
}

void initItem(Item_t* gegenstand) {
    gegenstand->isValid = false;
}