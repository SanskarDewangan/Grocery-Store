#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Mall {
    int pno;
    string name;
    float price, dis;

public:
    void getData() {
        cout << "\n\tEnter the details of the product...";
        cout << "\n\tProduct No: ";
        cin >> pno;
        cin.ignore();  // To ignore leftover newline from previous input
        cout << "\n\tProduct Name: ";
        getline(cin, name);
        cout << "\n\tProduct Price: ";
        cin >> price;
        cout << "\n\tProduct Discount(%): ";
        cin >> dis;
    }

    void showData() const {
        cout << setw(4) << pno << setw(20) << name << setw(8) << price << setw(10) << dis << "%" << "\n";
    }

    int retPno() const {
        return pno;
    }

    float retPrice() const {
        return price;
    }

    string retName() const {
        return name;
    }

    float retDis() const {
        return dis;
    }
};

// Utility function to display table headers
void menu() {
    cout << setw(4) << "P No" << setw(20) << "Product Name" << setw(8) << "Price" << setw(10) << "Discount";
    cout << "\n\t--------------------------------------------\n";
}

// Function to add product details to file
void enterProduct() {
    Mall m;
    fstream f("mall.txt", ios::out | ios::app | ios::binary);
    
    if (!f) {
        cerr << "\nError opening file!";
        return;
    }

    m.getData();
    f.write(reinterpret_cast<char*>(&m), sizeof(Mall));
    f.close();
    cout << "\n\n\tProduct has been created!";
}

// Function to display all products
void displayProducts() {
    Mall m;
    fstream f("mall.txt", ios::in | ios::binary);

    if (!f) {
        cerr << "\nError opening file!";
        return;
    }

    cout << "\n\n\tDISPLAYING ALL RECORDS !!!\n\n";
    menu();
    
    while (f.read(reinterpret_cast<char*>(&m), sizeof(Mall))) {
        m.showData();
    }

    f.close();
}

// Function to search for a product by product number
void searchProduct() {
    int no;
    Mall m;
    bool found = false;
    fstream f("mall.txt", ios::in | ios::binary);

    if (!f) {
        cerr << "\nError opening file!";
        return;
    }

    cout << "\nEnter the Product No. of the Product to be searched: ";
    cin >> no;

    menu();

    while (f.read(reinterpret_cast<char*>(&m), sizeof(Mall))) {
        if (m.retPno() == no) {
            m.showData();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nRecord does not exist!";
    }

    f.close();
}

// Function to update a product's details
void updateProduct() {
    int no;
    bool found = false;
    Mall m;
    fstream f("mall.txt", ios::in | ios::out | ios::binary);

    if (!f) {
        cerr << "\nError opening file!";
        return;
    }

    cout << "\nTo Update...Enter The Product No: ";
    cin >> no;

    while (f.read(reinterpret_cast<char*>(&m), sizeof(Mall)) && !found) {
        if (m.retPno() == no) {
            cout << "\nExisting product details:\n";
            m.showData();
            cout << "\nEnter new details for the product:\n";
            m.getData();

            // Move the file pointer back to the start of the record
            f.seekp(-static_cast<int>(sizeof(Mall)), ios::cur);
            f.write(reinterpret_cast<char*>(&m), sizeof(Mall));

            cout << "\nRecord has been updated!";
            found = true;
        }
    }

    if (!found) {
        cout << "\nRecord not found!";
    }

    f.close();
}

// Function to delete a product
void deleteProduct() {
    int no;
    Mall m;
    fstream f("mall.txt", ios::in | ios::binary);
    fstream temp("temp.txt", ios::out | ios::binary);

    if (!f || !temp) {
        cerr << "\nError opening file!";
        return;
    }

    cout << "\nEnter The Product No to delete: ";
    cin >> no;

    while (f.read(reinterpret_cast<char*>(&m), sizeof(Mall))) {
        if (m.retPno() != no) {
            temp.write(reinterpret_cast<char*>(&m), sizeof(Mall));
        }
    }

    f.close();
    temp.close();

    remove("mall.txt");
    rename("temp.txt", "mall.txt");

    cout << "\nRecord has been deleted!";
}

int main() {
    char choice;

    do {
        cout << "\n\n1. Create Products";
        cout << "\n2. Display Products";
        cout << "\n3. Search Products";
        cout << "\n4. Modify Products";
        cout << "\n5. Delete Products";
        cout << "\n6. EXIT";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                enterProduct();
                break;
            case '2':
                displayProducts();
                break;
            case '3':
                searchProduct();
                break;
            case '4':
                updateProduct();
                break;
            case '5':
                deleteProduct();
                break;
            case '6':
                exit(0);
            default:
                cout << "\nInvalid choice!";
        }
    } while (choice != '6');

    return 0;
}
