#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class dynamicArray
{

private:
    int* array;
    int len=0;
    int Size=0;
    
    int* createArray()
    {
        int *arr=(int*) malloc(len*sizeof(int));
        cout<<"Array Created" << endl;
        return arr;
    }

public:
    dynamicArray() { 
        setLen(); 
        array=createArray();
    }
    
    dynamicArray(int n) { 
        
        if(n<0)
        {
            throw "Invalid Allocation of size";
        }

        else
        {
            len=n;
            array=createArray();
        }
    }

    void setLen() { 
        len=8;
    }

    int getLen() {
        return len;
    }

    int size() {
        return Size;
    }

    bool isEmpty() {
        return Size==0;
    }

    int get(int index) {
        if(index<0) throw "Array Index Low of Bound!!";
        else
        {
            return array[index];
        }        
    }

    void set(int ind,int val)
    {
        if(ind<0) throw "Array Index Low of Bound!!";
        else
        {
            array[ind]=val;
        }
    }

    void clear()
    {
        for(int i=0;i<len;i++)
        {
            array[i]=0;
        }
        Size=0;
    }

    void add(int ele)
    {
        if(Size+1 == len)
        {
            int *new_array=(int*) malloc((Size*2)*(sizeof(int)));
            for(int i=0;i<Size;i++)
            {
                new_array[i]=array[i];
            }
            array=new_array;
            len=len*2;
        }
        array[Size++]=ele;
    }

    void forEach()
    {
        int n=Size;
        for(int i=0;i<n;i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

};

int main(int argc, char const *argv[])
{
    try {
        dynamicArray dy_cust(2);
        dynamicArray dy_defa;

        cout<< "Size Default: " << dy_defa.size() << endl;
        cout<< "Size Custom: " << dy_cust.size() << endl;

        cout << "Array \t isEmpty?" << endl;
        cout << "Cust \t " << dy_cust.isEmpty() << endl;
        cout << "Defa \t " << dy_defa.isEmpty() << endl;

        dy_cust.add(10);

        cout << "\nBefore Insert: \n\nArray \t Len" << endl;
        cout << "Cust  \t " << dy_cust.getLen() << endl;
        cout << "Defa  \t " << dy_defa.getLen() << endl;

        dy_cust.add(25);

        cout << "\nAfter Insert: \n\nArray \t Len" << endl;
        cout << "Cust  \t " << dy_cust.getLen() << endl;
        cout << "Defa  \t " << dy_defa.getLen() << endl;

        cout << "Array \t Size" << endl;
        cout << "Cust \t " << dy_cust.size() << endl;
        cout << "Defa \t " << dy_defa.size() << endl;
        
        cout << "Array \t isEmpty?" << endl;
        cout << "Cust \t " << dy_cust.isEmpty() << endl;
        cout << "Defa \t " << dy_defa.isEmpty() << endl;
        
        dy_cust.forEach();

    }
    catch(const char* err) {
        cerr << err << '\n';
    }

    return 0;
}
