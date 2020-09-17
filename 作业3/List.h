#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
#include "stddef.h"

template <class T>
class List
{
private:
    /* data */
    ListNode<T> *head;//链表的头结点

    int length;

public:
    List<T>(ListNode<T> *l,int n)
    {
        head=l;
        length=n;
    }

    List<T>(int n)//创建一个长度为n+1的空链表
    {
        this->length =1;
        head =new ListNode<T>();
        ListNode<T> *q;
        q=head;
        n--;
        while(n>0)
        {
            n--;
            length++;
            ListNode<T> *p = new ListNode<T>();
            q->next =p;
            q=p;
        }
    }

    List(T a[],int n)
    {
        int n_o=n;
        this->length =1;
        head =new ListNode<T>(a[0]);
        ListNode<T> *q;
        n--;
        q=head;
        while(n>0)
        {

            ListNode<T> *p = new ListNode<T>(a[n_o-n]);
            q->next =p;
            q=p;
            n--;
            length++;
        }
        delete q;
    }

    void dispList()
    {
        ListNode<T> *q;
        q =head;

        std::cout << "[";
        for(int i=0;i<length;i++){
    
        std::cout<<q->data<<" ";
        q=q->next;
        }
        std::cout << "]" << std::endl;
    }

    int get_length()
    {
        return this->length;
    }

    T get_num(int index)
    {
        if(index>length||index<0)return 0;
        ListNode<T> *p=head;
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        return p->data;
    }

    T get_mid()
    {
        this->get_num(1+length/2);
    }


    void is_empty()
    {
        if(length==0)std::cout<<"is is empty"<<std::endl;
        else std::cout<<"is is empty"<<std::endl;
    }

    //旋转链表
    void rotate()
    {
        ListNode<T>*p;
        ListNode<T>*q;
        ListNode<T>*r;
        p=head->next;
        q=p->next;
        head->next=NULL;//将头指针变为尾指针
        p->next=head;
        while(q)
        {
            r=q->next;
            q->next=p;
            p=q;
            q=r;
        }
        head=p;
    }



    void depart(int index)
    {
        List<T> *l1,*l2;
        l1=new List(head,index-1);

        ListNode<T> *p=head;
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        l2=new List(p,length-index+1);
        l1->dispList();
        l2->dispList();
    }

    ~List<T>()
    {

    }
};





#endif