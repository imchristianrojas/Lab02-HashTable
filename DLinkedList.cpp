
#include <stdio.h>
#include <iostream>



using namespace std;
template <typename T>

class Node
{
public:
    T data;
    Node<T>* previous;
    Node<T> * next;
    Node<T>() { previous = NULL; next = NULL; data = 0; }
    Node<T>(T t) { previous = NULL; next = NULL; data = t; }
};

using namespace std;
template <typename T>
class DList
{
public:
    Node<T> * tail;
    Node<T> * head;
    int count;
    DList(){tail = NULL; head = NULL;}
    


void append(T data)
{

    Node<T>* pdata = new Node<T>(data);

    
    
           if (tail == NULL && head == NULL)
           {
               tail = pdata;
               head = pdata;
               pdata->previous = NULL;
               pdata->next = NULL;
           }
           else
           {
               
                   pdata->previous = tail;
                   pdata->next = NULL;
                   tail->next = pdata;
                   tail = pdata;

           }
       }

void prepend(T data)
    {
        
        cout<<"Prepending: "<<data<<" to the doubly linked list"<<endl;
        Node <T> *pdata = new Node<T>(data);
        
        
        if (tail == NULL)
        {

            tail = pdata;
            head = pdata;

        }
        else
        {

            pdata->previous = NULL;
            pdata->next = head;
            head->previous = pdata;
            head = pdata;

        }
    }


void insertAfter(T find, T data)
     {
         Node<T> *pdata = new Node<T>(data);
         Node<T>* rover = head;
         Node<T>* temp = nullptr;
         
         while (rover != NULL)
         {

             if(rover->data == find)
             {
                 temp = rover;
                 rover = rover->next;
                 temp->next = pdata;
                 rover->previous = pdata;
                 
                 pdata->previous = temp;
                 pdata->next = rover;
                 
                
                
                 break;

             }
             rover = rover->next;
         }
     }
     // inserts data before found data
     void insertBefore(T find, T data)
     {

         Node<T> *pdata = new Node<T>(data);
         Node<T>* rover = head;
         Node<T>* temp = nullptr;
         
         while (rover != NULL)
         {

             if(rover->data == find)
             {
                 rover->previous = pdata;
                 temp->next = pdata;
                 
                 pdata->previous = temp;
                 pdata->next = rover;
                 break;
               
             }
             temp = rover;
             rover = rover->next;
         }
     }

void Delete(T data)
    {

        Node<T> *rover = head;
        Node<T> *previousNode = nullptr;
        Node<T> *temp = NULL;
        
        if(head == NULL && tail == NULL)
        {
            cout<<"The List is Empty! "<<endl;
            return;
        }
        
        
        while(rover!= NULL)
        {
            if(rover->data == data)
            {
                if((rover->previous == NULL) && (rover->next != NULL))
                {
                    temp = rover;
                    rover = rover->next;
                    head = rover;
                    rover->previous = NULL;
                    delete temp;
                    break;
   
                    
                }
                else if((rover->next == NULL) && (rover->previous == NULL))
                {
                    delete rover;
                    tail = NULL;
                    head = NULL;
                    break;
                }
                else if(rover->next == NULL)
                {
                    
                    previousNode->next = NULL;
                    tail = previousNode;
                    delete rover;
                    break;
                    
                }

                    
              
                
                previousNode->next = rover->next;
                temp = rover;
                
                rover = rover->next;
                rover->previous = previousNode;
                
                
                delete temp;
                break;
                
                
            }
            
            previousNode = rover;
            rover = rover->next;
            
        }
        

    }
    
    Node<T>* Search(T data)
    {
        Node<T>* rover = head;
        while (rover != NULL)
        {
           if((rover->data) == data)
           {
               return rover;
           }
            rover = rover->next;
        }
        
        return NULL;
        
    }

    int Count()
    {
        
        Node<T>* rover = tail;

        while (rover != NULL)
        {
            count++;
            rover = rover->previous;

        }

        rover = tail;
        return count;
        
    }

    string getData()
    {
        
       
        
        

    }
    bool IsEmpty()
    {
        if((tail == NULL) && (head == NULL))
            return true;
       return false;

    }
    
    void Clear()
    {
        Node<T>*root = head;
        Node<T>*temp = nullptr;
        
        
        
        
        while(root!=NULL)
        {
            
            Delete(root->data);
           
            root = root->next;
            
            
            
        }
        
        
       
    }


    void Output()
    {
        
        Node<T>* rover = head;
    
        while (rover != NULL)
        {
            cout << rover->data << '\t';
            rover = rover->next;
        }
        cout << endl;
    }
    
};


