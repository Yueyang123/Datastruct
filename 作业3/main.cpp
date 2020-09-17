#include "ListNode.h"
#include "List.h"
#include <iostream>

int main()
{
    List<int> *l= new List<int>(10);
    std::cout << l->get_length()<< std::endl;
    l->dispList();

    int a[10]={1,2,3,4,5,6,7,8,9,10};
    List<int> *l1= new List<int>(a,10);
    std::cout << l1->get_length()<< std::endl;
    l1->dispList();
    l1->rotate();
    l1->dispList();

    std::cout << l1->get_num(3)<< std::endl;
    std::cout << l1->get_mid()<< std::endl;

    l1->depart(3);
}