#include <iostream>
#include "Cart.h"
#include "ProductDatabase.h"
using namespace std;

int main() {
    ProductDatabase database;
    Cart cart;

    int choice;
    do {
        cout << "\n=== �ʪ����t�� ===\n";
        cout << "1. ��ܩҦ��ӫ~\n";
        cout << "2. �s�W�ӫ~���ʪ���\n";
        cout << "3. �d���ʪ������e\n";
        cout << "4. �����ʪ��������ӫ~\n";
        cout << "5. ���b\n";
        cout << "0. ���}\n";
        cout << "�п�ܥ\��G";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "��J���~�A�Э��s��ܡC\n";
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
            cout << "��J�ӫ~�s���G";
            cin >> code;
            cout << "��J�ƶq�G";
            cin >> quantity;

            Product product;
            if (database.findProductByCode(code, product)) {
                cart.addProduct(product, quantity);
                cout << "�w�s�W�ӫ~�G" << product.getName() << " x " << quantity << endl;
            }
            else {
                cout << "�䤣��Ӱӫ~�N�X�C\n";
            }
            break;
        }

        case 3:
            cart.showCart();
            break;

        case 4: {
            string name;
            cout << "��J�n�������ӫ~�W�١G";
            cin >> name;
            cart.removeProduct(name);
            break;
        }

        case 5: {
            std::cout << "\n���b��...\n";
            cart.showCart();
            std::cout << "�P�±z���ʶR�I\n";

        }
        case 0:
            cout << "�P�¨ϥΡA�A���I\n";
            break;

        default:
            cout << "�L�Ī��ﶵ�C\n";
        }

    } while (choice != 0);

    return 0;
}