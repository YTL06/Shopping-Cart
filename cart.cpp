#include "Cart.h"
#include <iostream>
#include <iomanip>
using namespace std;



void Cart::addProduct(const Product& product, int quantity) {
    for (auto& item : items) {
        if (item.product.getName() == product.getName()) {
            item.quantity += quantity;
            return;
        }
    }
    items.push_back(CartItem(product, quantity));
}

void Cart::removeProduct(const std::string& productName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->product.getName() == productName) {
            items.erase(it);
            cout << "已從購物車移除商品：" << productName << endl;
            return;
        }
    }
    cout << "購物車中找不到此商品。" << endl;
}

void Cart::showCart() const {
    if (items.empty()) {
        cout << "購物車是空的。\n";
        return;
    }

    cout << left << setw(15) << "商品名稱" << setw(8) << "數量" << setw(8) << "單價" << "小計\n";
    for (const auto& item : items) {
        double subtotal = item.product.getPrice() * item.quantity;
        cout << left << setw(15) << item.product.getName()
            << setw(8) << item.quantity
            << setw(8) << item.product.getPrice()
            << subtotal << endl;
    }
    cout << "總計: $" << getTotal() << "\n";
}

double Cart::getTotal() const {
    double total = 0;
    for (const auto& item : items) {
        total += item.product.getPrice() * item.quantity;
    }
    return total;
}
void Cart::clearCart() {
    items.clear();
}