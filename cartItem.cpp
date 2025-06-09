#include "cartItem.h"
#include <iostream>
#include <iomanip>
using namespace std;

CartItem::CartItem(const Product& product, int quantity)
    : product(product), quantity(quantity) {
}