#ifndef SHOP_H
#define SHOP_H

#include "menu.h"

class Shop : public Menu
{
public:
    Shop(int w, int h, std::vector<std::string> MenuItems);
};

#endif // SHOP_H
