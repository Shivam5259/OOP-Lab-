#include <iostream>
#include <exception>

using namespace std;


class NegativeStockException : public exception {};
class OverCapacityException : public exception {};

template <typename T>
class InventoryItem {
private:
    T stock;
    T maxCapacity;

public:
    InventoryItem(T maxCap) : stock(0), maxCapacity(maxCap) {}

    void setStock(T newStock) {
        if (newStock < 0) {
            throw NegativeStockException();
        } else if (newStock > maxCapacity) {
            throw OverCapacityException();
        } else {
            stock = newStock;
        }
    }
};

int main() {
    InventoryItem<int> item(100);

    try {
        item.setStock(-5);
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        item.setStock(120);
    } catch (exception& e) {
        cout  << e.what() << endl;
    }

}
