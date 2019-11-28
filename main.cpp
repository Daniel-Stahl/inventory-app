#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class InventoryItem {
public:
    InventoryItem(string name, int qty, string sku, double price) {
        this->name = name;
        this->qty = qty;
        this->sku = sku;
        this->price = price;
    }
    
    InventoryItem() {}
    
    void setName(string name) {
        this->name = name;
    }
    
    string getName() {
        return name;
    }
    
    void setQTY(int qty) {
        this->qty = qty;
    }
    
    int getQTY() {
        return qty;
    }
    
    void setSKU(string sku) {
        this->sku = sku;
    }
    
    string getSKU() {
        return sku;
    }
    
    void setPrice(double price) {
        this->price = price;
    }
    
    double getPrice() {
        return price;
    }
    
    ~InventoryItem() {
        cout << name << " deleted from inventory." << endl;
    }
    
private:
    string name;
    int qty;
    string sku;
    double price;
};

int main() {
    vector<InventoryItem *>itemGroup;
    InventoryItem *item;
    string name;
    int qty;
    string sku;
    double price;
    int input;
    
    do {
        cout << "Welcome" << endl;
        cout << "1. Add item" << endl;
        cout << "2. Delete item" << endl;
        cout << "3. Exit program" << endl;
        cin >> input;
        
        if (input == 1) {
            cout << "Name: ";
            cin >> name;
            
            cout << "Quantity: ";
            cin >> qty;
            
            cout << "SKU: ";
            cin >> sku;
            
            cout << "Price: ";
            cin >> price;
            
            item = new InventoryItem(name, qty, sku, price);
            itemGroup.push_back(item);
            
            cout << name << " added to inventory." << endl;
            cout << endl;
        } else if (input == 2) {
            int input;
            for (int i = 0; i < itemGroup.size(); i++) {
                cout << i + 1 << ". Name: " << itemGroup.at(i)->getName() << " QTY: " << itemGroup.at(i)->getQTY() << " SKU: " << itemGroup.at(i)->getSKU() << " Price: $" << itemGroup.at(i)->getPrice() << endl;
            };
            
            cout << "Which item do you want to delete? (Enter number) ";
            cin >> input;
            delete itemGroup.at(input-1);
            itemGroup.erase(itemGroup.begin() + input - 1);
        }
        
        for (int i = 0; i < itemGroup.size(); i++) {
            cout << itemGroup.at(i)->getName() << endl;
        }
    } while (input != 3);
    
}

