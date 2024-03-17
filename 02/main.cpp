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

Item generateRandomItem() {
    Item item;
    item.initItem(generateRandomName().c_str(), rand() % 50);
    return item;
}

int main() {
    srand(time(NULL));
    Hero hero;
    Character enemy;
    Character enemy2;

    char heroName[] = "Heldin";
    char enemyName[] = "Jämmerlicher Schurke";
    char enemy2Name[] = "Peinlicher Gauner";

    hero.initHero(heroName, 300, 100);
    enemy.initCharacter(enemyName, 50, 100);
    enemy2.initCharacter(enemy2Name, 100, 100);

    // fill enemy inventory
    for (int i = 0; i< 10; ++i) {
        enemy.setInventoryItem(i, generateRandomItem());
        enemy2.setInventoryItem(i, generateRandomItem());
    }

    hero.fight(enemy.getHealth(), enemy.attack(), enemy.getName());
    hero.setInventoryItem(0, *enemy.getInventoryItem(rand() % 10));
    std::cout << "Gegenstand " << hero.getInventoryItem(0)->getName() << " wurde zum Inventar der Heldin hinzugefügt.\n";

    hero.fight(enemy.getHealth(), enemy.attack(), enemy.getName());
    hero.setInventoryItem(1, *enemy2.getInventoryItem(rand() % 10));
    std::cout << "Gegenstand " << hero.getInventoryItem(1)->getName() << " wurde zum Inventar der Heldin hinzugefügt.\n";

    hero.sellItem(0);
    hero.sellItem(1);

    return 0;
};
