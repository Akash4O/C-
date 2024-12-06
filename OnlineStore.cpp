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

  return 0;  
}