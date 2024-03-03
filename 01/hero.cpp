#include "hero.h"
#include "character.h"
#include <iostream>
#include <string>
#include <cstdlib>

void initHero(Hero_t* hero, char* name, int health, int gold) {
    hero->name =name;
    hero->health = health;
    hero->gold = gold;
    for (int i = 0; i < 10; ++i) hero->inventory[i].isValid = false;
    for (int i = 0; i < 2; ++i) hero->equipment[i].isValid = false;
}

void attack(Hero_t* hero, Character_t* enemy) {
    int damage = rand() % 11 + 15;
    enemy->health -= damage;
    std::cout << hero->name << " trifft " << enemy->name << " fuer " << damage << " Lebenspunkte!\n";
}

void sellItem(Hero_t* hero, int index) {
    hero->gold += hero->inventory[index].value;
    std::cout << "Gegenstand " << hero->inventory[index].name << " wurde verkauft. " << hero->name << " besitzt nun " << hero->gold << " Gold.\n";
    hero->inventory[index].isValid = false;
}

bool fight(Hero_t* hero, Character_t* enemy) {
    while (hero->health > 0 && enemy->health > 0) {
        attack(hero, enemy);
        if (enemy->health > 0) attack(enemy, hero);
    }
    if (hero->health > 0) {
        std::cout << enemy->name << " fiel in Ohnmacht! " << hero->name << " hat noch " << hero->health << " Lebenspunkte uebrig!\n";
        return true;
    }
    return false;
}