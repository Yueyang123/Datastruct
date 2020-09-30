/*
 * @Descripttion: 
 * @version: 
 * @Author: Yueyang
 * @email: 1700695611@qq.com
 * @Date: 2020-09-17 13:11:20
 * @LastEditors: Yueyang
 * @LastEditTime: 2020-09-30 15:36:35
 */
#ifndef LISTNODE_H
#define LISTNODE_H

template <class T>
class ListNode 
{
public:
    T data;
    ListNode* next;

    ListNode()
    {
        this->data=0;
        next=0;
    }

    ListNode(T data)
    {
        this->data =data;
        next=0;
    }

     ListNode(ListNode* node)
    {
        this->data =node->data;
        next=node->next;
    }
    
};





#endif // DEBUG