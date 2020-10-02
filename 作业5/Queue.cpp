/*
 * @Descripttion: 
 * @version: 
 * @Author: Yueyang
 * @email: 1700695611@qq.com
 * @Date: 2020-09-28 18:27:01
 * @LastEditors: Yueyang
 * @LastEditTime: 2020-09-28 22:58:14
 */
#include <iostream>
#include "Queue.h"
#include "stdlib.h"
int queue_in_special()
{
    Queue<int> *p =new Queue<int>();
    char data;
    int tmp;
    while(true)
    {
        std:: cin>>data;
        std::cout << data << std::endl;
        if(data<='9'&&data>='0')
        {
            p->queue_in(atoi(&data));
        }
        else if(data<='z'&&data>='a')
        {
            p->queue_out(tmp); 
        }
        else
        {
            p->show();
            return 0;
        }
        
    }
}

int main_t()
{
    Queue<char> * q =new Queue<char>();
    int len=q->get_length();
    q->queue_in('a');
    q->queue_in('b');
    q->queue_in('c');
    q->show();
    q->queue_in('d');
   //q->queue_in('e');
    q->show();

    char tmp;
    q->queue_out(tmp);
    q->show();
    q->queue_out(tmp);
    q->show();

    q->queue_out(tmp);
    q->show();
    q->queue_out(tmp);
    q->show();

    q->queue_in('a');
    q->queue_in('b');
    q->show();
    bool em=q->is_empty();
    std::cout<<em<<std::endl<<q->front<<q->rear<<std::endl;

    queue_in_special();

    
}