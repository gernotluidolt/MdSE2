#include "hero.h"
#include "character.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "item.h"
#include <ctime>

std::string generateRandomName() {
    std::string adjektive[] = {"kleiner", "grosser", "boeser", "guter", "zerbrochener", "lächerlicher", "schleimiger", "interessanter", "durchschnittlicher", "netter"};
    std::string names[] = {"Spaten", "Bogen", "Speer", "Schild", "Helm", "Eimer", "Stiefel", "Ring", "Anhänger", "Heiltrank"};
    return adjektive[rand() % 10] + " " + names[rand() % 10];
}

Item_t generateRandomItem() {
    Item_t item;
    item.name = generateRandomName();
    item.value = rand() % 50;
    item.isValid = true;
    return item;
}

int main() {
    srand(time(NULL));
    Hero_t hero;
    Character_t enemy;
    Character_t enemy2;

    char heroName[] = "Heldin";
    char enemyName[] = "Jämmerlicher Schurke";
    char enemy2Name[] = "Peinlicher Gauner";

    initHero(&hero, heroName, 300, 100);
    initCharacter(&enemy, enemyName, 50, 100);
    initCharacter(&enemy2, enemy2Name, 100, 100);

    // fill enemy inventory
    for (int i = 0; i< 10; ++i) {
        enemy.inventory[i] = generateRandomItem();
        enemy2.inventory[i] = generateRandomItem();
    }

    fight(&hero, &enemy);
    hero.inventory[0] = enemy.inventory[rand() % 10];
    std::cout << "Gegenstand " << hero.inventory[0].name << " wurde zum Inventar der Heldin hinzugefügt.\n";

    fight(&hero, &enemy2);
    hero.inventory[1] = enemy2.inventory[rand() % 10];
    std::cout << "Gegenstand " << hero.inventory[1].name << " wurde zum Inventar der Heldin hinzugefügt.\n";

    sellItem(&hero, 0);
    sellItem(&hero, 1);

    return 0;
}