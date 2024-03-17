#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {
    std::string name;
    int value;
    bool _isValid;

public:
    std::string getName() {
        return name;
    }

    int getValue() {
        return value;
    }

    bool isValid() {
        return _isValid;
    }

    void setValid(bool valid) {
        this->_isValid = valid;
    }

    void initItem(const char* name, int gold) {
        this->name = name;
        this->value = gold;
        this->_isValid = true;
    }

    void initItem() {
        this->_isValid = false;
    }
};

#endif //ITEM_H
