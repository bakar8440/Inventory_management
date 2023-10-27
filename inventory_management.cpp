#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

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

// Function to perform a stock out (sell) operation
void stockOut(vector<Product>& inventory) {
    int id, quantity;
    cout << "Enter product ID to sell: ";
    cin >> id;

    // Find the product with the given ID
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            cout << "Enter the quantity to sell: ";
            cin >> quantity;
            if (quantity <= it->quantity) {
                it->quantity -= quantity;
                cout << "Sold " << quantity << " units of " << it->name << endl;
                //if (it->quantity == 0) {
                    //cout << "Stocked out: " << it->name << endl;
                    //inventory.erase(it);
                //}
                return;
            } else {
                cout << "Insufficient stock. There are only " << it->quantity << " units available." << endl;
                return;
            }
        }
    }

    cout << "Product with ID " << id << " not found in the inventory." << endl;
}

// Function to display the inventory, including "Stocked out" for out-of-stock products
void displayInventory(const vector<Product>& inventory) {
    cout << "Inventory:" << endl;
    cout << "ID\tName\tQuantity\tPrice" << endl;
    for (const Product& product : inventory) {
            if(product.quantity >= 1){
        cout << product.id << "\t" << product.name << "\t" << product.quantity << "\t\t" << product.price;
            }
        else if (product.quantity == 0) {
            cout << product.id<<"\t" <<product.name<<"\t"<<"Stocked out"<<"\t"<<product.price;
        }
        cout << endl;
    }
}

int main() {
    vector<Product> inventory;
    int choice;

    while (choice != 5) {
        cout << "Inventory Management System" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Inventory" << endl;
        cout << "3. Delete Inventory" << endl;
        cout << "4. Sell product" << endl;
        cout << "5. Quit" << endl;
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
            stockOut(inventory);
        } else if (choice == 5) {
            cout << "Exiting the program." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

