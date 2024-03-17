#ifndef CHARACTER_H
#define CHARACTER_H
#include "item.h"
#include <string>
#include <cstdlib>
#include <iostream>

class Character {
    std::string name;
    int health;
    int gold;
    Item inventory[10];

public:
    int getHealth() {
        return health;
    }
    void setHealth(int health) {
        this->health = health;
    }
    int getGold() {
        return gold;
    }
    void setGold(int gold) {
        this->gold = gold;
    }

    std::string getName() {
        return name;
    }

    void initCharacter(char* name, int health, int gold) {
        this->name = name;
        this->health = health;
        this->gold = gold;
        for (int i = 0; i < 10; ++i) this->inventory[i].setValid(false);
    }

    int AddInventarItem(Item item) {
        for (int i = 0; i < 10; ++i) {
            if (!inventory[i].isValid()) {
                inventory[i] = item;
                return i;
            }
        }
        return -1;
    }

    Item removeInventarItem(int index) {
        Item item = inventory[index];
        inventory[index].initItem();
        return item;
    }

    int attack() {
        int damage = rand() % 11 + 5;
        std::cout << name << " trifft " << " fuer " << damage << " Lebenspunkte!\n";
        return damage;
    }

    void setInventoryItem(int index, Item item) {
        this->inventory[index] = item;
    }

    Item* getInventoryItem(int index) {
        return &inventory[index];
    }
};


#endif //CHARACTER_H