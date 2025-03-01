#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
using Invetory = std::map<std::string, int>;
using Categories = std::set<std::string>;
using Orders =  std::queue<std::string>;
using Restocks = std::stack<std::pair<std::string, int>>;
using Cart = std::vector<std::string>;

//Functions for Taks 1
void displayInventory(const Invetory& inventory);
void addProduct(Invetory& invetory, std::string key, int value);
bool updQuantity(Invetory& invetory, std::string key, int newValue);

//Functions for Task 2
void displayCategories(const Categories& productCategories);
void addNewCategory(Categories& productCategories, std::string newCategory);

//Functions for Task 3
void displayOrders(Orders& orders);
void addNewOrder(Orders& orders, std::string order);

//Functions for Task 4
void processStock(Restocks& restocks);
void addRestock(Restocks& restocks, std::string objectRestock, int numberUnits);

//Functions for Task 5
void displayItems(Cart& customerCart);
void addItem(Cart& customeCart, std::string item);


// Managing Products with std::map TASK 1
int main() {
    std::map<std::string, int> inventory;

    // Adding products
    addProduct(inventory, "Laptop", 5);
    addProduct(inventory, "Mouse", 20);
    addProduct(inventory, "Keyboard", 10);


    // Adding new product to the map
    addProduct(inventory, "Monitors", 3);
    addProduct(inventory, "Play Station", 5);
    addProduct(inventory, "Ryzen processor", 4);


    //Update the value of a existence key in the map
    if (updQuantity(inventory, "Laptop", 10)){ //Check the existence of the key
        displayInventory(inventory);
    } else{
        NULL;
    }


    // Tracking Unique Products with std::set TASK 2
    std::set<std::string> productCategories;

    // Adding categories
    addNewCategory(productCategories, "Electronics");
    addNewCategory(productCategories, "Accessories");
    addNewCategory(productCategories, "Peripherals");
    addNewCategory(productCategories, "Consoles");
    displayCategories(productCategories);
    std::cout << std::endl;


    // Processing orders with std::queue TASK 3
    std::queue<std::string> orders;

    // Adding orders
    addNewOrder(orders, "Order#1: Laptop");
    addNewOrder(orders, "Order#2: Mouse");
    addNewOrder(orders, "Order#3: Keyboard");
    addNewOrder(orders, "Order#4: Ryzen Processor");
    displayOrders(orders);
    std::cout << std::endl;

    // Handling Restocks with std::stack TASK 4
    std::stack<std::pair<std::string, int>> restocks;

    // Adding restock batches
    addRestock(restocks, "Mouse", 10);
    addRestock(restocks, "Laptop", 2);
    addRestock(restocks, "Keyboard", 5);
    addRestock(restocks, "Play Station 5", 2);
    processStock(restocks);
    std::cout << std::endl;

    // Storing Customer Purchases with std::vector TASK 5
    std::vector<std::string> customerCart;

    // Adding items to cart
    addItem(customerCart, "Laptop");
    addItem(customerCart, "Mouse");
    addItem(customerCart, "Keyboard");
    addItem(customerCart, "Play Station 5");
    displayItems(customerCart);

    return 0;
}

// Functions to std::map TASK 1
    void displayInventory(const Invetory& inventory) {
        std::cout << "Current Inventory:\n";
        for (const auto& item : inventory) {
            std::cout << item.first << ": " << item.second << " in stock\n";
        }
        std::cout << std::endl;
    }


    //Function to add a new product in the original map
    void addProduct(Invetory& invetory, std::string key, int value){
        invetory.insert({key, value});
    }


    //Function to update the Quantity of a existence key in the original map
    bool updQuantity(Invetory& invetory, std::string key, int newValue){
        if (invetory.count(key)){
            invetory[key] = newValue;
            return true;
        } else{
            std::cout << "The key " << key << " doesn't exist." << std::endl;
            return false;
        }
    }


//Functions to std::set TASK 2
    // Function to display all categories
    void displayCategories(const Categories& productCategories){
        std::cout << "Product Categories:\n";
        for (const auto& category : productCategories) {
            std::cout << "- " << category << "\n";
        }
    }

    // Function to add a new category
    void addNewCategory(Categories& productCategories, std::string newCategory){
        productCategories.insert(newCategory);
    }


//Functions with std::queue TASK 3 
    // Function to display the processing orders
    void displayOrders(Orders& orders){
        // Processing orders
            while (!orders.empty()) {
                std::cout << "Processing " << orders.front() << std::endl;
                orders.pop();
            }
    }
    //Function to Add a new order
    void addNewOrder(Orders& orders, std::string order){
        //PUEDO HACER UNA ESTRUCTURA PARA HACER ESTO
        orders.push(order);
    }

//Functions with std::stack TASK 4
    //Function to process a restock batch
    void processStock(Restocks& restocks){
            while (!restocks.empty()) {
                auto item = restocks.top();
                std::cout << "Restocking " << item.second << " units of " << item.first << std::endl;
                restocks.pop();
            }
    }
    //Function to Add a restock batch
    void addRestock(Restocks& restocks, std::string objectRestock, int numberUnits){
        restocks.push({objectRestock, numberUnits});
    }

//Functions with std::vector TASK 5
    //Function to display the Items of a vector
    void displayItems(Cart& customerCart){
        std::cout << "Items in customer cart:\n";
        for (const auto& item : customerCart) {
            std::cout << "- " << item << "\n";
        }
    }
    //Function to add new item into the cart
    void addItem(Cart& customeCart, std::string item){
        customeCart.push_back(item);
    }
