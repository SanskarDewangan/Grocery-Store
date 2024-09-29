# Grocery Store Management System
### A console-based application for managing a grocery store's inventory and processing customer orders, built with C++.
## Table of Contents
- Project Overview
- Features
- Getting Started
- Usage
- File Structure
- Requirements
- Technologies Used

## Project Overview
- The Grocery Store Management System is a simple, console-based C++ application designed to help manage product inventory in a grocery store. 
- The system supports basic operations such as adding, modifying, searching, deleting, and displaying products. Additionally, customers can place orders for products, and the system calculates the total cost with applicable discounts.
- This project makes use of Object-Oriented Programming (OOP) principles and File Handling to store and retrieve product details efficiently.

## Features
- Create Products: Add new products with details such as product number, name, price, and discount.
- Display Products: View all available products in the store's inventory.
- Search Products: Search for a product by its product number.
- Update Products: Modify existing product details.
- Delete Products: Remove products from the inventory.
- Place Orders: Customers can place an order for multiple products, and the system generates a detailed bill.
- File Handling: Product data is stored in and retrieved from a text file (mall.txt).
  
## Usage
Once the application starts, you will be presented with the following menu options:

1. Create Products
2. Display Products
3. Search Products
4. Modify Products
5. Delete Products
6. Place an Order
7. Exit

### Choose an option by entering the corresponding number.

- Create Products: Add a new product by entering the required details (product number, name, price, discount).
- Display Products: Shows all products stored in the system.
- Search Products: Enter the product number to search for a specific product.
- Modify Products: Modify the details of an existing product.
- Delete Products: Remove a product from the system.
- Place an Order: Select products by their product number, and the system will calculate the total price based on quantity and applicable discounts.

## File Structure

- ├── main.cpp          # Main source code
- ├── mall.txt          # File storing product details
- └── README.md         # Project documentation

## Requirements
C++11 or above
Basic knowledge of file handling in C++

## Technologies Used
- C++: The main programming language used for developing the system.
- File Handling: For reading from and writing to files to persist product data.
- Object-Oriented Programming (OOP): For managing product details and operations.
