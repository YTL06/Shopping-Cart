#ifndef CART_H
#define CART_H

#include "cartItem.h"
#include "Product.h"
#include <vector>
#include <string>



class Cart {
private:
    std::vector<CartItem> items;

public:
    void addProduct(const Product& product, int quantity);
    void removeProduct(const std::string& productName);
    void showCart() const;
    double getTotal() const;
    void clearCart();
};

#endif
