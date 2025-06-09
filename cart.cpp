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
            cout << "�w�q�ʪ��������ӫ~�G" << productName << endl;
            return;
        }
    }
    cout << "�ʪ������䤣�즹�ӫ~�C" << endl;
}

void Cart::showCart() const {
    if (items.empty()) {
        cout << "�ʪ����O�Ū��C\n";
        return;
    }

    cout << left << setw(15) << "�ӫ~�W��" << setw(8) << "�ƶq" << setw(8) << "���" << "�p�p\n";
    for (const auto& item : items) {
        double subtotal = item.product.getPrice() * item.quantity;
        cout << left << setw(15) << item.product.getName()
            << setw(8) << item.quantity
            << setw(8) << item.product.getPrice()
            << subtotal << endl;
    }
    cout << "�`�p: $" << getTotal() << "\n";
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