#ifndef HERO_H
#define HERO_H
#include <string>
#include "item.h"

struct Hero_t {
    std::string name;
    int health;
    int gold;
    Item_t inventory[10];
    Item_t equipment[2];
};

struct Character_t;

void initHero(Hero_t* hero, char* name, int health, int gold);
void attack(Hero_t* hero, Character_t* enemy);
void sellItem(Hero_t* hero, int index);
bool fight(Hero_t* hero, Character_t* enemy);
#endif //HERO_H
