#include "character.h"
#include "hero.h"
#include <iostream>

void initCharacter(Character_t* character, char* name, int health, int gold) {
    character->name = name;
    character->health = health;
    character->gold = gold;
    for (int i = 0; i < 10; ++i) character->inventory[i].isValid = false;
}

void attack(Character_t* character, Hero_t* hero) {
    int damage = rand() % 11 + 5;
    hero->health -= damage;
    std::cout << character->name << " trifft " << hero->name << " fuer " << damage << " Lebenspunkte!\n";
}