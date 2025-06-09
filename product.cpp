#include "Product.h"

Product::Product() : name(""), price(0.0) {}

Product::Product(const std::string& name, double price) : name(name), price(price) {}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}
