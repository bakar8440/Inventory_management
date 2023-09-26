#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Structure to represent a product
struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

// Function to add a new product to the inventory
void addProduct(vector<Product>& inventory, int id, string name, int quantity, double price) {
    Product product = {id, name, quantity, price};
    inventory.push_back(product);
    cout << "Product added to inventory." << endl;
}

// Function to delete all products from the inventory
void deleteInventory(vector<Product>& inventory) {
    inventory.clear();
    cout << "Inventory cleared." << endl;
}

// Function to display the inventory
void displayInventory(const vector<Product>& inventory) {
    cout << "Inventory:" << endl;
    cout << "ID\tName\tQuantity\tPrice" << endl;
    for (const Product& product : inventory) {
        cout << product.id << "\t" << product.name << "\t" << product.quantity << "\t\t" << product.price << endl;
    }
}

int main() {
    vector<Product> inventory;
    int choice;

    while(choice != 4) 
    {
        cout << "\nInventory Management System" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Inventory" << endl;
        cout << "3. Delete Inventory" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, quantity;
            string name;
            double price;
            cout << "Enter product details:" << endl;
            cout << "ID: ";
            cin >> id;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Quantity: ";
            cin >> quantity;
            cout << "Price: ";
            cin >> price;
            addProduct(inventory, id, name, quantity, price);
        } else if (choice == 2) {
            displayInventory(inventory);
        } else if (choice == 3) {
            deleteInventory(inventory);
        } else if (choice == 4) {
            cout << "Exiting the program." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
