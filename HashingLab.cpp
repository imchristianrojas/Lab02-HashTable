/*
Lab 02 Hashing
Christian Rojas
CIS 22C
Professor Larkin
July 19, 2020
Purpose: Read a csv file containing customer data and store it in a ADT. Place each ADT into the HashTable structure
using either string or numeric hash functions.

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <string>
#include "Customer.cpp"
#include "DynamicArray.cpp"


using namespace std;

array <Customer,512> customers;
const unsigned TABLE_SIZE = customers.size() * 1.25f;
static int maximum = TABLE_SIZE;



//concatetnate nums from left hand side of the dash with the right and cast it into a long.
long string2Int(string id)
{
    
    string temp = "";
    long num;
    for(int i = 0; i<id.length(); i++)
    {
        if(id[i] =='-' )
            i++;
        temp += id[i];
            
        
    }
    
    num = stol(temp);
    
    return num;
    
    
}

long numericHash(long key)
{
    
    long int squared = key * key;
    
    int lowBitsToRemove = (32-10)/2;//R = Logbase2(Table_Size) = 9.4 = 10
    
    int extractedBits = squared>>lowBitsToRemove;
    extractedBits = extractedBits & (0xFFFFFFFF)>>(32-10);//retrieve middle numbers
    
    return extractedBits%TABLE_SIZE;
    
    
}

int HashRemainder(string key)
{
    //poor performance. most basic
    int max = customers.size();
    int sum = key[0] - 'A' + 1;
    for(int c = 0; c<key.length(); c++)
    {
        sum += (key[c]-'a' + 1);
    }
    
    return sum % max;
    
    
}

int HashMultiplicative(string key){
    char stringHash = key[0];
    
    for(int i = 0; i< key.length(); i++)
    stringHash = (stringHash * 7) + key[i];
    return stringHash % customers.size();
    
    }

long getHash(string key)
{
    //return HashRemainder(key);//
    //return HashMultiplicative(key);//298 collisions
    return numericHash(string2Int(key)); // 168 collisions best so far.
    
}


//With each Customer a key is assign with it
class HashElement
{
private:
    int key = 0;
    Customer person;
    
public:
    int used = 0;
    HashElement(int k = 0, int u = 0)
    {
        key = k;
        used = u;
    }
    
    void setKeyValue(int k, Customer p, int u = 0)
    {
        key = k;
        person = p;
        used++;
        
    }
    
    int getKey(){return key;}
    Customer getValue(){return person;}
    
};


class hashTable{
    
    
private:
    
    DynamicArray<HashElement> htable;
    int collisions = 0;
public:
    hashTable();
    hashTable(int size = 1){htable.ArrayListResize(size);}
    
    
    int getCollisions(){return collisions;}
    
    int size(){return htable.getSize();}
    
    DList<HashElement> get(string key)
    {
        
        int hash = getHash(key);
        return htable[hash];
    }
    void set(Customer value)
    {
        
        string id = value.getId();
        HashElement element;
        int hash = getHash(id);
        element.setKeyValue(hash, value);
        
        if(htable[hash].head!=NULL){//if the index is not occupied already
            collisions++;
            element.used++;
            
        }
        
        htable[hash].append(element);
        
    }
    
    DList<HashElement> operator[](int index)
    {
        
        return htable[index];
        
    }

    
};



int main() {
    
    fstream customerFile;
    customerFile.open("Customer.csv");

    if(customerFile.fail())
    {
        cerr<<"Cannot Open File!"<<endl;
        exit(1);
    }

    int numCustomers = 0;
    string lastName,firstName,idNum,temp;

    //populating array of customers
    while(!(customerFile.eof()))
    {

        getline(customerFile,lastName,',');
        getline(customerFile,firstName,',');
        getline(customerFile,idNum);
        
        customers[numCustomers].setLastName(lastName);
        customers[numCustomers].setFirstName(firstName);
        customers[numCustomers].setId(idNum);

        numCustomers++;

    }
    
    
    hashTable htable(TABLE_SIZE);
    
    for(int i = 0; i<customers.size(); i++)
    {
        htable.set(customers[i]);
        
    }

    /*
     Test Sets:
     
     Node<HashElement> *rover;
    rover = htable.get("10402031-5995967").head;

    Customer reader;
    while(rover!= NULL)
    {
        reader = rover->data.getValue();
        cout<<reader.getLastName()<<" "<<reader.getFirstName()<<" "<<reader.getId();
        rover = rover->next;

    }

    cout<<htable.getCollisions()<<endl;*/

    
    int used = 0;
    for(int i = 0; i<htable.size(); i++)
    {
        if(htable[i].head == NULL)
        {
            used++;
        }
    }
    
    
    cout<<"\n\n Statistics:"<<endl;
    cout<<"\tMaximum = "<<maximum<<endl;
    cout<<"\tUsed = "<<(float)used/(float)htable.size()*100.0<<'%'<<endl;
    cout<<"\tCollisions = "<<(float)htable.getCollisions()/(float)customers.size()*100.0<<'%'<<endl;
    cout<<endl;


    
        
    /*
     
     Notes:
            Hashing with last + first name was a little better.
            *365 collisions with remainder function(Worst Function Yet)
            *166 collisions with number ID.(Best Function Yet)(32.421% Collisions, 46.687% Used(Could be better)
            
     To Do:
            Reduce Collisions
            Make or improve hashing functions
     
     */
     
    
   
    return 0;
}




