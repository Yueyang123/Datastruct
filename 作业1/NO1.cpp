#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int j=0,s =0,n =100;
    int index =0;//用于记录次数
    do
    {
        index++;
        /* code */
        j=j+1;
        s=s+10*j;
    } while (j<n&&s<n);
   cout<<index;
}

/**运行分析：
 * 第一次 ：j=1 s=11 n=100
 * 第二次 ：j=2 s=31 n=100
 * 第三次 ：j=3 s=61 n=100
 * 第四次 ：j=4 s=101 n=100
 * 
 */
