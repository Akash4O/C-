#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<string>
#include<ctime>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;

struct Product {
    int productId;
    string name;
    string category;
};

struct Order {
    int orderId;
    int productId;
    int quantity;
    string customerID;
    time_t orderDate;
};

struct Customers {
    string customerId;
    string customerName;
};

class Auth {
public:
    // Function to clear screen based on OS
    void clearScreen() {
#ifdef _WIN32
        system("cls"); // Clear screen on Windows
#else
        system("clear"); // Clear screen on Linux/macOS
#endif
    }

    // Function to create a new account
    void createAccount() {
        string username, userpassword;
        cout << "Enter the UserName : ";
        cin >> username;
        cout << "Enter the Password : ";
        cin >> userpassword;

        ofstream outFile("user_data.txt", ios::app);
        if (outFile.is_open()) {
            outFile << username << "," << userpassword << endl;
            outFile.close();
            cout << "Account Created Successfully!" << endl;
        } else {
            cerr << "Error: Unable to open file for writing! " << endl;
        }
    }

    // Function to split the account data
    pair<string, string> split(const string& input) {
        size_t delimiterPos = input.find(','); // Find the position of the comma
        pair<string, string> data;
        if (delimiterPos != string::npos) {
            data.first = input.substr(0, delimiterPos); // Get the first part before the comma
            data.second = input.substr(delimiterPos + 1); // Get the second part after the comma
        }
        return data;
    }

    // Function to login the user
    void Login() {
        ifstream inFile("user_data.txt");
        string line;
        pair<string, string> data;

        string username, userpassword;
        cout << "Enter the UserName : ";
        cin >> username;
        cout << "Enter the Password : ";
        cin >> userpassword;

        bool userflag = false;

        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                data = split(line);
                if (strcmp(data.first.c_str(), username.c_str()) == 0) {
                    userflag = true;
                    if (strcmp(data.second.c_str(), userpassword.c_str()) == 0) {
                        cout << "Successfully Logged In" << endl;
                        cout << "Welcome " << username << " !" << endl;
                        return;
                    }
                }
            }
            inFile.close();
        } else {
            cerr << "Error : Unable to open file for reading!" << endl;
        }

        if (userflag) {
            cout << "Incorrect Password!" << endl;
        } else {
            cout << "Invalid UserName Or User Doesn't Exist" << endl;
        }
    }

    // Function to manage login session
    void loginSession() {
        int ch;
        cout << "Choose From Below Options : " << endl;
        cout << "1. Login \n2. Register \n3. Exit" << endl;
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            clearScreen();
            Login();
            break;
        case 2:
            clearScreen();
            createAccount();
            break;
        case 3:
            clearScreen();
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid input!" << endl;
            break;
        }
    }
};

int main() {
    // Product list
    vector<Product> products = {
        {101, "Laptop", "Electronics"},
        {102, "SmartPhone", "Electronics"},
        {103, "CoffeeMaker", "Kitchen"},
        {104, "Blender", "Kitchen"},
        {105, "Desk Lamp", "Home"}
    };

    // Recent customers list
    deque<Customers> recentCustomers = {
        {"C001", "Customer1"},
        {"C002", "Customer2"},
        {"C003", "Customer3"}
    };

    recentCustomers.push_back({"C004", "Customer4"});

    // Order history list
    list<Order> orderHistory;
    orderHistory.push_back({1, 101, 1, "C001", time(0)});
    orderHistory.push_back({2, 102, 2, "C003", time(0)});
    orderHistory.push_back({3, 103, 3, "C002", time(0)});

    // Categories set
    set<string> categories;
    for (const auto& product : products) {
        categories.insert(product.category);
    }

    // Product stock map
    map<int, int> productStock = {
        {101, 10},
        {102, 5},
        {103, 6},
        {104, 18},
        {105, 4}
    };

    // Customer orders multi-map
    multimap<string, Order> customerOrders;
    for (const auto& order : orderHistory) {
        customerOrders.insert({order.customerID, order});
    }

    // Customer data unordered map
    unordered_map<string, string> customerData = {
        {"C001", "Alice"},
        {"C002", "Bob"},
        {"C003", "Akash"},
        {"C004", "Anand"},
        {"C005", "Max"}
    };

    // Unique product IDs unordered set
    unordered_set<int> uniqueProductIDs;
    for (const auto& product : products) {
        uniqueProductIDs.insert(product.productId);
    }

    // Authentication object to manage login and account creation
    Auth auth;
    auth.loginSession();

    return 0;
}
