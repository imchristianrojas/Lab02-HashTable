
#include <string>
#include <iostream>

using namespace std;
class Customer
{
private:
    string lastName,firstName,id;
    
public:
    Customer(){
        lastName = " ";firstName = " "; id = "";
        
    }
    
    Customer(string ln,string fn, string num)
    {
        lastName = ln;
        firstName =fn;
        id = num;
    }
    
    
    void setFirstName(string fn){firstName = fn;}
    void setLastName(string ln){lastName = ln;}
    void setId(string i){id = i;}
    
    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}
    string getId(){return id;}
    
};
