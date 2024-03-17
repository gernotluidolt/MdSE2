#ifndef HERO_H
#define HERO_H
#include <string>
#include "item.h"
#include <iostream>

class Hero{
    std::string name;
    int health;
    int gold;
    Item inventory[10];
    Item equipment[2];

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

    void setInventoryItem(int index, Item item) {
        this->inventory[index] = item;
    }

    Item* getInventoryItem(int index) {
        return &inventory[index];
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

    int AddEquipmentItem(Item item) {
        for (int i = 0; i < 2; ++i) {
            if (!equipment[i].isValid()) {
                equipment[i] = item;
                return i;
            }
        }
        return -1;
    }

    Item removeInventarItem(int index) {
        Item item = inventory[index];
        inventory[index].setValid(false);
        return item;
    }

    Item removeEquipmentItem(int index) {
        Item item = equipment[index];
        equipment[index].setValid(false);
        return item;
    }

    void initHero(char* name, int health, int gold) {
        this->name =name;
        this->health = health;
        this->gold = gold;
        for (int i = 0; i < 10; ++i) this->inventory[i].setValid(false);
        for (int i = 0; i < 2; ++i) this->equipment[i].setValid(false);
    }

    int attack() {
        int damage = rand() % 11 + 15;
        std::cout << name << " trifft " << " fuer " << damage << " Lebenspunkte!\n";
        return damage;
    }

    void sellItem(int index) {
        this->gold += inventory[index].getValue();
        std::cout << "Gegenstand " << inventory[index].getName() << " wurde verkauft. " << name << " besitzt nun " << gold << " Gold.\n";
        inventory[index].setValid(false);
    }

    bool fight(int enemyHealth, int enemyAttack, std::string enemyName) {
        while (health > 0 && enemyHealth > 0) {
            health -= enemyAttack;
            if (enemyHealth > 0) {
                enemyHealth -= attack();
            };
        }
        if (health > 0) {
            std::cout << enemyName << " fiel in Ohnmacht! " << name << " hat noch " << health << " Lebenspunkte uebrig!\n";
            return true;
        }
        return false;
    }
};

#endif //HERO_H