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
#include<thread>
#include<chrono>
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

class Cart{
    private:

    public:
        void addToCart(){

        }


        
};

class Overall{
    private:

        struct Product {
            int productId;
            string name;
            string category;
            float price;
            string description;
        };

        

        vector<Product> products = {
        {101, "Laptop", "Electronics",54999,"A high-performance laptop, perfect for work, entertainment, and gaming. It features advanced processing power and ample storage for all your needs"},
        {102, "SmartPhone", "Electronics",24999,"A sleek and powerful smartphone with cutting-edge features, including a stunning display, high-resolution cameras, and long-lasting battery life."},
        {103, "CoffeeMaker", "Kitchen",14999,"A premium coffee maker that brews café-quality coffee right at home. Its user-friendly design ensures every cup is a delight."},
        {104, "Blender", "Kitchen",15999,"A versatile kitchen blender with multiple speed settings, perfect for smoothies, soups, and more. Designed for durability and ease of use."},
        {105, "Desk Lamp", "Home",799,"A stylish and energy-efficient desk lamp, ideal for study or work. It features adjustable brightness and a sleek design to enhance your workspace."}
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

        void filterProducts(){
            clearScreen();
            cout<<"Choose A Catrgories : "<<endl;
            set<string> categories;
            for (const auto& product : products) {
                categories.insert(product.category);
            }
            
            int i=1;
            for (auto it = categories.begin(); it != categories.end(); ++it, ++i) {
                cout<< i <<". "<<*it<<endl;
            }

            cout<<"Enter your Choice :"<<endl;
            int ch;
            cin>>ch;

            i=1;
            string targetCategory;
            for (auto it = categories.begin(); it != categories.end(); ++it, ++i) {
                if(i==ch){
                    targetCategory=*it;
                    break;
                }
            }

            cout<<"ProductId        Product Name                Category            Price           Stock           "<<endl;
            for(const auto& product : products){
                if(targetCategory==product.category){
                    printProducts(product);
                }
            }
            
        }

        void searchProductById(int id){
            for(const auto& product : products){
                if(id == product.productId){
                    printProductsDescription(product);
                    return;
                }
            }
            cout<<"Invalid Entry!"<<endl;
        }

        bool compareStrings(string& str1, string& str2)
        {
            if (str1.length() != str2.length())
                return false;

            for (int i = 0; i < str1.length(); ++i) {
                if (tolower(str1[i]) != tolower(str2[i]))
                    return false;
            }

            return true;
        }


        void searchProductByName(string pname){
            string p2;
            for(const auto& product : products){
                p2 = product.name;
                if(compareStrings(p2,pname)){
                    printProductsDescription(product);
                    return;
                }
            }
            cout<<"Invalid Entry!"<<endl;
        }

        void searchProducts(){
            cout<<"Choose One Option :"<<endl;
            cout<<"1. Search By Id"<<endl;
            cout<<"2. Search By Name"<<endl;
            cout<<"Enter your choice :"<<endl;
            int ch;
            string pname;
            cin>>ch;
            switch (ch)
            {
            case 1:
                cout<<"Enter the id of the product :";
                int id;
                cin >> id;
                searchProductById(id);
                break;
            case 2:
                cout<<"Enter the Name of the product :";
                
                cin>>pname;
                searchProductByName(pname);
                break;
            default:
                cout<<"Invalid Choice !"<<endl;
                break;
            }

        }

        void printProductsDescription(Product product){
            cout<<""<<endl;
            cout<<"Product Details :"<<endl;
            cout<<"Product ID : "<<product.productId<<endl;
            cout<<"Product Name : "<<product.name<<endl;
            cout<<"Product Category : "<<product.category<<endl;
            cout<<"Product Price : "<<product.price<<endl;
            cout<<"Product Stock : "<<productStock[product.productId]<<endl;
            cout<<""<<endl;
        }

        void printProducts(Product product){
            
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

        void viewProducts(){
            cout<<"ProductId        Product Name                Category            Price           Stock           "<<endl;
            for(const auto& product : products){
                printProducts(product);
            }

            while(true){
                cout<<"Choose one From Below Options: " <<endl;
                cout<<"1. Filter Products by Category"<<endl;
                cout<<"2. Search Product"<<endl;
                cout<<"3. Add Product to cart."<<endl;
                cout<<"4. Go Back to Main Page"<<endl;
                cout<<"Enter your choice :"<<endl;
                int ch;
                cin >> ch;
                switch (ch)
                {
                case 1:
                    filterProducts();
                    break;
                case 2:
                    searchProducts();
                    break;
                case 3:
                    break;
                case 4:
                    return;
                default:
                    break;
                }
            }

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
        while(true){
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
                this_thread::sleep_for(chrono::seconds(3));
                a.overallSession();
                break;
            case 2:
                clearScreen();
                createAccount();
                break;
            case 3:
                clearScreen();
                cout << "Exiting...";
                return;
            default:
                cout << "Invalid input!" << endl;
                break;
            }
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

    

    

    // Authentication object to manage login and account creation
    Auth auth;
    auth.loginSession();

    return 0;
}
