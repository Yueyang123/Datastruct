
#define MaxSize 50
#include <iostream>

using namespace std;

template <typename T>
class sqList
{
  public:
    T data[MaxSize];
    int length;

    sqList(T* a,int n)
    {
        for(int i=0;i<=n;i++)
        {
            data[i]=a[i];
        }
        this->length=n;
    }


    sqList()
    {
        this->length=0;
    }

    void dispList()
    {
        for(int i=0;i<length;i++)
        cout<<data[i]<<" ";
        cout <<endl;
    }

    void dispList(int index)
    {
        cout<<data[index-1]<<" ";
        cout <<endl;
    }

    int get_length()
    {
        return length;
    }

    void insert_in_end(T x)
    {
        this->length++;
        data[length-1]=x;
    }

    bool is_empty()
    {
        if(length==0)
        {
        cout<<"empty"<<endl;
        return true;
        
        }
        else
        {
        cout<<"not empty"<<endl;
        return false;
        }
    }

    int get_index(T a)
    {
        int i=0;
        for(i=0;i<length;i++)
        {
           if(data[i]==a)
           {
            cout<<a<<" :"<<i+1<<endl;
            return i+1;
           }
        }
        if(i==length-1)
        {
            cout<<"without this num"<<endl;
            return -1;
        }
    }

    void insert(int index,T x)
    {
        for(int i=length;i>index-1;i--)
            data[i]=data[i-1];
        length++;
        data[index-1]=x;
    }

    void delete_one(int index)
    {
        length--;
        for(int i=index-1;i<length;i++)
            data[i]=data[i+1];
    }

    void max_remove(sqList *&L)
    {
    int i,j=0;
    for(i=1;i<L->length;i++)
        if(L->data[i]>L->data[j])//找到最大的所在的位置
            j=i;
    for(i=j;i<L->length-1;i++)
        L->data[i]=L->data[i+1];
    L->length--;
    }
    
    void add_in_min(sqList* &L,T x)
    {
    int i,j=0;
    for(i=1;i<L->length;i++)
        if(L->data[i]<=L->data[j])//找到最小值所在位�?
            j=i;
    for(i=L->length;i>j;i--)
        L->data[i]=L->data[i-1];//向后移动
    L->data[j]=x;
    L->length++;
    }


};
