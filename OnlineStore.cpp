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
#include<iomanip>
#include<math.h>
using namespace std;

// Function to clear screen based on OS
    void clearScreen() {
        #ifdef _WIN32
            system("cls"); // Clear screen on Windows
        #else
            system("clear"); // Clear screen on Linux/macOS
        #endif
    }

class Overall{
    private:

        struct Product {
            int productId;
            string name;
            string category;
            float price;
        };

        

        vector<Product> products = {
        {101, "Laptop", "Electronics",54999},
        {102, "SmartPhone", "Electronics",24999},
        {103, "CoffeeMaker", "Kitchen",14999},
        {104, "Blender", "Kitchen",15999},
        {105, "Desk Lamp", "Home",799}
        };

        // Product stock map
        map<int, int> productStock = {
            {101, 10},
            {102, 5},
            {103, 6},
            {104, 18},
            {105, 4}
        };

    public:
        int countDigit(int n) { return floor(log10(n) + 1); }

        void viewProducts(){
            cout<<"ProductId        Product Name                Category            Price           Stock           "<<endl;
            for (const auto& product : products) {
            // Calculate dynamic width for productId and name
                int productIdWidth = 17 - countDigit(product.productId);
                int nameWidth = 28 - product.name.length();
                int categoryWidth = 20 - product.category.length();
                int priceWidth = 16 - countDigit(product.price);
                int stockWidth = countDigit(productStock[product.productId]);
                
                // Output product details with dynamic spaces
                cout << product.productId;
                cout << setw(productIdWidth) << "";  // This will print the space
                cout << product.name;
                cout << setw(nameWidth) << "";  // This will print the space
                cout << product.category;
                cout << setw(categoryWidth) << "";
                cout << product.price;
                cout << setw(priceWidth) << "";
                cout << productStock[product.productId] << "";
                cout << setw(stockWidth) << "";
                cout << endl;
            }

            cout<< ""
        }

        void overallSession(){
            while(true){
                clearScreen();
                cout << "Choose One From Below Options: " << endl;
                cout << "1. User Profile" << endl;
                cout << "2. View Products"<<endl;
                cout << "3. Logout"<<endl;
                cout << "Enter your choice : " << endl;
                int ch;
                cin >> ch;
                switch (ch)
                {
                case 1:
                    break;
                
                case 2:
                    viewProducts();
                    break;
                
                case 3:
                    cout<<"Bye 👋 Have A Nice Day!"<<endl;
                    return;

                default:
                    cout<<"invalid Choice"<<endl;
                    break;
                }
            }
        }

};

class Auth {
public:
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
        

        bool userflag = false;

        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                data = split(line);
                if (data.first == username) {
                    cout << "Enter the Password : ";
                    cin >> userpassword;
                    userflag = true;
                    if (data.second == userpassword) {
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
            Login();
        } else {
            cout << "Invalid UserName Or User Doesn't Exist" << endl;
            Login();
        }
    }

    // Function to manage login session
    void loginSession() {
        int ch;
        Overall a;
        cout << "Choose One From Below Options: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register"<<endl;
        cout << "3. Exit"<<endl;
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            clearScreen();
            Login();
            a.overallSession();
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

struct Order {
    int orderId;
    int productId;
    int quantity;
    string customerID;
    time_t orderDate;
};

int main() {

    set<string> categories;
    // for (const auto& product : products) {
    //     categories.insert(product.category);
    // }

    // Order history list
    list<Order> orderHistory ={
    {1, 101, 1, "C001", time(0)},
    {2, 102, 2, "C003", time(0)},
    {3, 103, 3, "C002", time(0)}};

    // Customer orders multi-map
    multimap<string, Order> customerOrders;
    for (const auto& order : orderHistory) {
        customerOrders.insert({order.customerID, order});
    }

    // Authentication object to manage login and account creation
    Auth auth;
    auth.loginSession();

    return 0;
}
