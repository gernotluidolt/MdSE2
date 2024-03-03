#ifndef ITEM_H
#define ITEM_H
#include <string>

struct Item_t {
    std::string name;
    int value;
    bool isValid;
};

void initItem(Item_t* ITEM, char* name, int gold);
void initItem(Item_t* gegenstand);
#endif //ITEM_H
