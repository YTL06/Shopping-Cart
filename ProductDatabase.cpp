#include "ProductDatabase.h"
#include <iostream>
#include <iomanip>
using namespace std;

ProductDatabase::ProductDatabase() {
    const string names[] = {
        "紅茶", "綠茶", "咖啡", "牛奶", "汽水", "餅乾", "巧克力", "泡麵", "白飯", "麵包",
        "牙膏", "牙刷", "洗髮精", "沐浴乳", "洗面乳", "衛生紙", "面紙", "抹布", "洗衣粉", "清潔劑",
        "書本", "筆記本", "原子筆", "鉛筆", "橡皮擦", "剪刀", "膠水", "訂書機", "資料夾", "便利貼",
        "USB", "滑鼠", "鍵盤", "耳機", "喇叭", "充電器", "行動電源", "手機殼", "螢幕保護貼", "風扇",
        "拖鞋", "襪子", "外套", "帽子", "眼鏡", "手套", "皮帶", "背包", "雨傘", "手錶",
        "口罩", "體溫計", "藥水", "OK繃", "棉花棒", "指甲剪", "刮鬍刀", "護手霜", "防曬乳", "濕紙巾",
        "相機", "記憶卡", "三腳架", "電池", "充電器2", "遙控器", "燈泡", "插座", "延長線", "電風扇",
        "冷氣", "暖氣", "加濕器", "除濕機", "空氣清淨機", "吸塵器", "掃地機器人", "電鍋", "微波爐", "烤箱",
        "冰箱", "洗衣機", "烘衣機", "熱水器", "瓦斯爐", "電磁爐", "電熱水壺", "果汁機", "咖啡機", "水壺",
        "水杯", "便當盒", "湯匙", "叉子", "筷子", "碗", "盤子", "鍋子", "平底鍋", "砧板"
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
    cout << "\n所有商品清單：" << endl;
    cout << left << setw(6) << "編號" << setw(15) << "商品名稱" << "價格" << endl;
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
