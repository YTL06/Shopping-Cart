#include "ProductDatabase.h"
#include <iostream>
#include <iomanip>
using namespace std;

ProductDatabase::ProductDatabase() {
    const string names[] = {
        "����", "���", "�@��", "����", "�T��", "�氮", "���J�O", "�w��", "�ն�", "�ѥ]",
        "���I", "����", "�~�v��", "�N�D��", "�~����", "�åͯ�", "����", "�٥�", "�~�篻", "�M�侯",
        "�ѥ�", "���O��", "��l��", "�]��", "�����", "�ŤM", "����", "�q�Ѿ�", "��Ƨ�", "�K�Q�K",
        "USB", "�ƹ�", "��L", "�վ�", "��z", "�R�q��", "��ʹq��", "�����", "�ù��O�@�K", "����",
        "��c", "���l", "�~�M", "�U�l", "����", "��M", "�ֱa", "�I�]", "�B��", "���",
        "�f�n", "��ŭp", "�Ĥ�", "OK�^", "�֪��", "���Ұ�", "���G�M", "�@����", "���Ψ�", "��Ȥy",
        "�۾�", "�O�Хd", "�T�}�[", "�q��", "�R�q��2", "������", "�O�w", "���y", "�����u", "�q����",
        "�N��", "�x��", "�[�㾹", "�����", "�Ů�M�b��", "�l�о�", "���a�����H", "�q��", "�L�i�l", "�N�c",
        "�B�c", "�~���", "�M���", "������", "�˴��l", "�q���l", "�q������", "�G�ľ�", "�@�ؾ�", "����",
        "���M", "�K��", "����", "�e�l", "�_�l", "�J", "�L�l", "��l", "������", "�z�O"
    };

    double basePrice = 12.5;
    for (int i = 0; i < 100; ++i) {
        char code[4];
        sprintf_s(code, sizeof(code), "%03d", i + 1);
        double price = basePrice + (i % 20) * 2.5;
        products.push_back({ code, Product(names[i], price) });
    }
}

void ProductDatabase::showProductList() const {
    cout << "\n�Ҧ��ӫ~�M��G" << endl;
    cout << left << setw(6) << "�s��" << setw(15) << "�ӫ~�W��" << "����" << endl;
    for (const auto& entry : products) {
        cout << left << setw(6) << entry.first
            << setw(15) << entry.second.getName()
            << fixed << setprecision(2) << entry.second.getPrice() << endl;
    }
}

bool ProductDatabase::findProductByCode(const std::string& code, Product& result) const {
    for (const auto& entry : products) {
        if (entry.first == code) {
            result = entry.second;
            return true;
        }
    }
    return false;
}
