#include <iostream>
#include <string>

using namespace std;

const int MAX_ITEMS = 100; // Maximum number of inventory items

struct InventoryItem {
    string name;
    int stock;
};

InventoryItem inventory[MAX_ITEMS];
int itemCount = 0;

// Function to add an item to the inventory
void addItem() {
    if (itemCount < MAX_ITEMS) {
        cout << "Enter item name: ";
        cin >> inventory[itemCount].name;
        cout << "Enter initial stock: ";
        cin >> inventory[itemCount].stock;
        itemCount++;
        cout << "Item added successfully!endl";
    } else {
        cout << "Inventory is full!\n";
    }
}

// Function to update an item in the inventory
void updateItem() {
    string name;
    cout << "Enter the name of the item to update: ";
    cin >> name;

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].name == name) {
            int newStock;
            cout << "Enter new stock level: ";
            cin >> newStock;

            // Stock validation
            if (newStock < 0) {
                cout << "Stock cannot be negative!\n";
            } else {
                inventory[i].stock = newStock;
                cout << "Stock updated successfully!\n";
            }
            return;
        }
    }
    cout << "Item not found!\n";
}

// Function to view stock levels
void viewStock() {
    if (itemCount == 0) {
        cout << "No items in inventory.\n";
        return;
    }

    cout << "Current Inventory:\n";
    for (int i = 0; i < itemCount; i++) {
        cout << "Item: " << inventory[i].name << ", Stock: " << inventory[i].stock << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Update Item\n";
        cout << "3. View Stock\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                viewStock();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    system("pause"); // Keep the console open
    return 0;
}


