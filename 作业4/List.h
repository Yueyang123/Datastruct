
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
        
    }

    List(List *l1,List *l2)
    {
        ListNode<T> *p,*q1,*q2,*tmp1,*tmp2;
        int min_length=l1->length<l2->length?l1->length:l2->length;
        int max_length=l1->length>l2->length?l1->length:l2->length;
        this->head=l1->head;
        int len_flag;
        q1=l1->head->next;
        q2=l2->head;
        p=this->head;
        if(l1->length>l2->length)len_flag=1;
        else len_flag=0;
        for(int i=0;i<min_length;i++)
        {
            tmp1=q1->next;
            tmp2=q2->next;
            p->next=q2;
            p=p->next;
            p->next=q1;
            p=p->next;
            q2=tmp2;
            q1=tmp1;
            length+=2;
        }
        if(len_flag)
        {
            p->next=q1;
            length+= max_length-min_length;
        }
        else
        {
            p->next=q2;
            length+=max_length-min_length;
        }
        
    }

//不断从从源链表中找到第一小，第二小。。。，用头插法，到最后变为了降序排列
    List* desort()
    {
        ListNode<T> *p=NULL,*pmin=NULL,*qmin=NULL,*q=NULL,*hn =NULL;
        for(int i=0;i<length;i++){
            for (p = head,pmin=head; p;q=p,p=p->next)//循环找到链表中的最小值
            {
                if(p->data < pmin->data)
                {
                    pmin = p;
                    qmin = q;
                }
            }
            if (pmin == head)//如果最小值节点是头结点
                head = head->next;//将该最小值节点从链表上移除
            else
                qmin->next = pmin->next;//将该最小值节点从链表上移除
            //头插的方式创建一个新链表
            pmin->next = hn;//将新节点头插到降序链表中
            hn = pmin;//将原来的头结点指向现在的头结点
        }
        List<int> *l=new List<int>(hn,this->length);
        l->dispList();
        return l;
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

    ListNode<T>* get_node(int index)
    {
        ListNode<T> *p=head;
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        return p;
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

    void insert_before(T data,int index)
    {
        ListNode<T> *n=new ListNode<T>(data);
        ListNode<T> *p=head;

        if(index==1)
        {
            n->next=p;
            head=n;
        }
        else{

            for(int i=0;i<index-2;i++)
            {
                p=p->next;            
            }
            n->next=p->next;
            p->next=n;
        }
        length++;
    }


    int find_max()
    {
        ListNode<T> *p=head;
        ListNode<T> *mmax=head;     

        int i=0,index;
        for( i=0;i<length-1;i++)
        {            
            p=p->next;
            if(p->data>mmax->data)
            {
                mmax=p;
                index=i+2;
            }
        }
        return index;
    }

    void inster_before_max(int mmax)
    {
        int index =find_max();
        insert_before(mmax,index);
    }



    ~List<T>()
    {

    }
};



#endif

