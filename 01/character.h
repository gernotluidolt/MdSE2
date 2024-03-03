#ifndef CHARACTER_H
#define CHARACTER_H
#include "item.h"
#include "hero.h"
#include <string>

struct Character_t {
    std::string name;
    int health;
    int gold;
    Item_t inventory[10];
};

struct Hero_t;

void initCharacter(Character_t* character, char* name, int health, int gold);
void attack(Character_t* character, Hero_t* hero);

#endif //CHARACTER_H
