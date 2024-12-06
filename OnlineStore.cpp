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

struct Product
{
    int productId;
    string name;
    string category;
};

struct Order
{
    int orderId;
    int productId;
    int quantity;
    string customerID;
    time_t orderDate;
};

struct Customers{
    string customerId;
    string customerName;
};

void clearScreen() {
#ifdef _WIN32
    system("cls"); // Clear screen on Windows
#else
    system("clear"); // Clear screen on Linux/macOS
#endif
}

void createAccount(){
    string username,userpassword;
    cout<<"Enter the UserName : ";
    cin >>username;
    cout<<"Enter the Password : ";
    cin >>userpassword;

    ofstream outFile("user_data.txt", ios::app);
    if(outFile.is_open()){
        outFile << username << "," << userpassword << endl;
        outFile.close();
        cout << "Account Created Successfully!" <<endl;
    }else{
        cerr << "Error: Unable to open file for writing! "<<endl;
    }
}

pair<string,string> split(const string& input){
    size_t delimiterPos = input.find(','); // Find the position of the comma
    pair<string,string> data;
    if (delimiterPos != string::npos) {
        data.first = input.substr(0, delimiterPos); // Get the first part before the comma
        data.second = input.substr(delimiterPos + 1); // Get the second part after the comma
    }
    return data;
}

void Login(){
    ifstream inFile("user_data.txt");
    string line;
    pair<string,string> data;

    string username,userpassword;
    cout<<"Enter the UserName : ";
    cin >>username;
    cout<<"Enter the Password : ";
    cin >>userpassword;

    bool userflag = false;

    if(inFile.is_open()){
        while(getline(inFile,line)){
            data = split(line);
            if(strcmp(data.first.c_str(),username.c_str())==0){
                userflag = true;
                if(strcmp(data.second.c_str(),userpassword.c_str())==0){
                    cout<<"Succesfully LoggedIn"<<endl;
                    cout<<"Welcome "<<username<<" !"<<endl;
                    return;
                }
            }
        }
        inFile.close();
    }else{
        cerr<< "Error :Unable to open file for reading!"<<endl;
    }

    if(userflag){
        cout<<"incorrect Password!"<<endl;
    }else{
        cout<<"Invalid UserName Or User Doesn't Exist"<<endl;
    }
    
}

void loginSession(){
    int ch;
    cout<<"Choose From Below Options : "<<endl;
    cout<<"1. Login \n2. Register \n3. Exit"<<endl;
    cout<< "Enter your choice : "<<endl;
    cin >> ch;
    switch (ch)
    {
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
        cout<<"Exiting...";
        break;
    default:
        cout<<"Invalid input!";
        break;
    }
}

int main(){
    vector<Product> products = {
        {101,"Laptop","Electronics"},
        {102,"SmartPhone","Electronics"},
        {103,"CoffeMaker","Kitchen"},
        {104,"Blender","Kitchen"},
        {105,"Desk Lamp","Home"}
    };

    deque<Customers> recentCustomers ={
        {"C001","Customer1"},
        {"C002","Customer2"},
        {"C003","Customer3"}
    };

    recentCustomers.push_back({"C004","Customer4"});

    list<Order> orderHistory;

    orderHistory.push_back({1,101,1,"C001",time(0)});
    orderHistory.push_back({2,102,2,"C003",time(0)});
    orderHistory.push_back({3,103,3,"C002",time(0)});

    set<string> categories;

    for(const auto &product : products ){
        categories.insert(product.category);
    }

    map<int,int> productStock = {
        {101,10},
        {102,5},
        {103,6},
        {104,18},
        {105,4}
    };

    multimap<string,Order> customerOrders;

    for(const auto &order: orderHistory){
        customerOrders.insert({order.customerID,order});
    }

    unordered_map<string,string> customerData = {
        {"C001","Alice"},
        {"C002","Bob"},
        {"C003","Akash"},
        {"C004","Anand"},
        {"C005","Max"},
    };

    unordered_set<int> uniqueProductIDs;

    for(const auto &product : products){
        uniqueProductIDs.insert(product.productId);
    }

    loginSession();    


  return 0;  
}