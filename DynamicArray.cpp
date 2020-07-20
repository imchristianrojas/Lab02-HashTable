
#include "DLinkedList.cpp"
#include <array>

template<typename T>
class DynamicArray
{
    
private:
    
    DList<T> *arr;
    int length;//num of elements
    int greatestIndex;//greatest index
    
    
public:
    
    DynamicArray();
    DynamicArray(int);
    ~DynamicArray();
    
    DList<T>& operator[](int index);
    
   
    void ArrayListAppend(T data);
    void ArrayListResize(int newSize);
    void ArrayListPrepend(T data);
    void ArrayListInsertAfter(int index, T Data);
    int  ArrayListSearch(T item);
    void ArrayListRemoveAt(int index);
    
    int getSize(){return this->length;}
    
    
    
};


template<typename T>
void DynamicArray<T>::ArrayListResize(int newSize)
{
    DList<T>*pnew = new DList<T>[newSize];
    
    for(int i = 0; i< greatestIndex; i++)
        pnew[i] = arr[i];//copy all elements existed already
    for(int j = greatestIndex; j<newSize; j++)//for the rest initalize them
    {
        pnew[j].tail = NULL;
        pnew[j].head = NULL;
    }
        
    delete arr;
    arr = pnew;
    
}

template<typename T>
DynamicArray<T>::DynamicArray(int size)
{
    arr = new DList<T>[size];
    for(int i = 0; i<size; i++)
    {
        arr[i].head = NULL;
        arr[i].tail = NULL;
    }
    length = size;
    greatestIndex = 0;
}


//default constructor
template<typename T>
DynamicArray<T>::DynamicArray()
{
    
    arr = new DList<T>[10];
    
    for(int i = 0; i < 10; i++){
        arr[i].head = NULL;
        arr[i].tail = NULL;
    }
    length = 10;
    greatestIndex = 0;
    
    
}
template<typename T>
DynamicArray<T>::~DynamicArray()
{
    
    delete[] arr;

}

template<typename T>

//return the linked list located at the index
DList<T>& DynamicArray<T>::operator[](int index)
{
    DList<T> *pnew; //pointer to new array
    
    if(index>=length)
    {
        pnew = new DList<T>[index+10];
        for(int i = 0; i<greatestIndex; i++)
            pnew[i] = arr[i];
        
        for(int j = greatestIndex; j<index + 10; j++){
            pnew[j].tail = NULL;
            pnew[j].head = NULL;
        }
        length = index + 10;
        delete [] arr;
        arr = pnew;
        
            
    }
    
    if(index > greatestIndex)
    {
        greatestIndex = index + 1;
    }
    
    return *(arr+index);
    
}

template<typename T>
void DynamicArray<T>::ArrayListAppend(T data)
{
    
    DList<T> *pnew;
      if (greatestIndex == length) {
          length = length + 10;
          pnew = new DList<T>[length];
        for (int i = 0; i < greatestIndex; i++)
            pnew[i] = arr[i];
        for (int j = greatestIndex; j < length; j++)
        {
            //initalize to NULL
            pnew[j].tail =NULL;
            pnew[j].head = NULL;
            
           
        }
            delete [] arr;
    arr = pnew;
          
      }
    
    arr[greatestIndex++].append(data);//append onto linked list at position: greatestIndex + 1
    
    
}

template<typename T>
void DynamicArray<T>::ArrayListPrepend(T data)
{
    
        DList<T>*pnew;
    
    
        if (greatestIndex == length) {
            
            length = length + 10;
            pnew = new DList<T>[length];
            
        for (int i = 1; i < greatestIndex; i++)
        pnew[i] = arr[i+1];
            
        for (int j = greatestIndex; j < length; j++)
        {
        //initalize to NULL
        pnew[j].tail =NULL;
        pnew[j].head = NULL;
        }
            
            delete[] arr;
            arr = pnew;
            arr[0].append(data);
            
        }
    else
    {
        pnew = new DList<T>[length];
        for(int i = 1; i<greatestIndex; i++)
            pnew[i] = arr[i+1];
        delete[]arr;
        arr = pnew;
        arr[0].append(data);
            
    }
    
       
    }
    

template<typename T>

void DynamicArray<T>::ArrayListInsertAfter(int index, T data)
{
    
    DList<T>* pnew;
    
    if(greatestIndex == length)
    {
        length = length + 10;
        pnew = new DList<T>[length];
        
        for(int j = 0; j<index; j++)
            pnew[j] = arr[j];
        
        for(int i = index + 1; i <length; i++)
        {
            pnew[i] = arr[i+1];
            
            
            
        }
        delete[]arr;
        arr = pnew;
        arr[index+1].append(data);
        
        
    }
    else{
        //dynamically allocate new array of same size, copy the elements from OG array onto new array,
        //ignore the position at "index", and copy remaining elements from OG onto new with position + 1.
        pnew = new DList<T>[length];
        for(int i = 0; i<=index; i++)
            pnew[i] = arr[i];
        for(int i = index + 2; i<greatestIndex+1; i++)
        {
            pnew[i] = arr[i+1];
        }
        
        delete[]arr;
        arr = pnew;
        arr[index+1].append(data);
        
        
    }
    
    
}
    
    

template<typename T>
  int DynamicArray<T>::ArrayListSearch(T item)
{
    
    //Traverse until item is found
    for(int i = 0; i<length; i++)
    {
        if (arr[i]->data == item)
            return i;
    }
    
    return -1;
    
}


template<typename T>
void DynamicArray<T>::ArrayListRemoveAt(int index)
{
    DList<T>*pnew = new DList<T>[length];
    
    if((index>=0) && (index < length))
    {
        for(int i = index; i<length; i++)
        {
            pnew[i] = arr[i+1];
        }
        
        length--;
        
    }
    
}



    
    
    
    
    
    
