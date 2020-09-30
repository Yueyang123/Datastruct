/*
 * @Descripttion: 
 * @version: 
 * @Author: Yueyang
 * @email: 1700695611@qq.com
 * @Date: 2020-09-17 13:38:36
 * @LastEditors: Yueyang
 * @LastEditTime: 2020-09-26 19:47:03
 */
#include "ListNode.h"
#include "List.h"
#include <iostream>

/**
 * @name: 
 * @msg: 
 * @param {type} 
 * @return {type} 
 */

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int b[7]={11,22,33,44,55,66,77};
    List<int> *l1= new List<int>(a,10);
        
    List<int> *l2= new List<int>(b,7);

    l1->dispList();
    int i=l1->find_max();
    std::cout<<i<<std::endl;

    l1->dispList();
    l1->inster_before_max(100);
    l1->dispList();

    ListNode<int>* p=l1->get_node(2);
    std::cout<<p->data<<std::endl;
    l1=l1->desort();
    l1->dispList();


    l2->dispList();
    List<int> *l3 =new List<int>(l1,l2);
    l3->dispList();

}