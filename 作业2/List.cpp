#include "sqList.h"

int main()
{
    int a[] ={-1,2,-3,4,-5,6,-7};
    sqList<int> *l=new sqList<int>(a,7);
    l->dispList();

    int i=0;
    int j=0;
    int tmp;
    for(i=0,j=l->length-1;i<j;)
    {
        if(l->data[i]>0&&l->data[j]<0) 
            {
                tmp=l->data[i];
                l->data[i]=l->data[j];
                l->data[j]=tmp;
                i++;
                j--;
            }
        if(l->data[i]<0)i++;
        if(l->data[j]>0)j--;
    }
    l->dispList();
}