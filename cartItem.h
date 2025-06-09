#ifndef CARTITEM_H
#define CARTITEM_H

#include "Product.h"
#include <vector>
#include <string>

class CartItem {
public:
    Product product;
    int quantity;

    CartItem(const Product& product, int quantity);
};

#endif