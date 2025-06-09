#include <iostream>
#include "Cart.h"
#include "ProductDatabase.h"
using namespace std;

int main() {
    ProductDatabase database;
    Cart cart;

    int choice;
    do {
        cout << "\n=== 購物車系統 ===\n";
        cout << "1. 顯示所有商品\n";
        cout << "2. 新增商品到購物車\n";
        cout << "3. 查看購物車內容\n";
        cout << "4. 移除購物車中的商品\n";
        cout << "5. 結帳\n";
        cout << "0. 離開\n";
        cout << "請選擇功能：";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "輸入錯誤，請重新選擇。\n";
            continue;
        }

        switch (choice) {
        case 1:
            database.showProductList();
            break;

        case 2: {
            string code;
            int quantity;
            database.showProductList();
            cout << "輸入商品編號：";
            cin >> code;
            cout << "輸入數量：";
            cin >> quantity;

            Product product;
            if (database.findProductByCode(code, product)) {
                cart.addProduct(product, quantity);
                cout << "已新增商品：" << product.getName() << " x " << quantity << endl;
            }
            else {
                cout << "找不到該商品代碼。\n";
            }
            break;
        }

        case 3:
            cart.showCart();
            break;

        case 4: {
            string name;
            cout << "輸入要移除的商品名稱：";
            cin >> name;
            cart.removeProduct(name);
            break;
        }

        case 5: {
            std::cout << "\n結帳中...\n";
            cart.showCart();
            std::cout << "感謝您的購買！\n";

        }
        case 0:
            cout << "感謝使用，再見！\n";
            break;

        default:
            cout << "無效的選項。\n";
        }

    } while (choice != 0);

    return 0;
}