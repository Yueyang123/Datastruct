#include <iostream>
#include "stdlib.h"
using namespace std;


int fun(int n)
{
    int sum=0;
    int i=1;
    for(int k=1;k<=n;k++)
    {
        i=i*k;
        sum+=i;
    }
    return sum;

}

int main(int argc,char** argv)
{
    int n= atoi(argv[1]);
    int a= fun(n);
    cout<<a;

    return 0;
}
