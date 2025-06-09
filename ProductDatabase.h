#ifndef PRODUCTDATABASE_H
#define PRODUCTDATABASE_H

#include "Product.h"
#include <vector>
#include <string>

class ProductDatabase {
private:
    std::vector<std::pair<std::string, Product>> products;

public:
    ProductDatabase();
    void showProductList() const;
    bool findProductByCode(const std::string& code, Product& result) const;
};

#endif
