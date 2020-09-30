/*
 * @Descripttion: 
 * @version: 
 * @Author: Yueyang
 * @email: 1700695611@qq.com
 * @Date: 2020-09-28 18:27:01
 * @LastEditors: Yueyang
 * @LastEditTime: 2020-09-30 14:10:29
 */


#include <iostream>

#define MAX_SIZE 50

template <class T>
class Queue
{
public:
    T data[MAX_SIZE];
    int front;
    int rear;

    Queue()
    {
        this->front=this->rear=0;
    }

    ~Queue()
    {
    }

    bool is_empty()
    {
        return (this->front==this->rear);
    }
    
    bool queue_in(T data)
    {
        //判断是否队满
        if((this->rear+1)%MAX_SIZE==this->front)
        {
        std::cout<<"full!!";    
        return false;
        }
        this->rear=(this->rear+1)%MAX_SIZE;
        this->data[this->rear]=data;
        return true;
    }


    bool queue_out(T &data)
    {
        //判断是否队空
        if(this->front==this->rear)
         return false;
        this->front=(this->front+1)%MAX_SIZE;
        data =this->data[this->front];
        return true;
    }  

    int get_length()
    {
        return (this->rear-this->front+MAX_SIZE)%MAX_SIZE;
    } 

    void show()
    {
        std::cout<<"[";

        int i=0;
        int len =get_length();
        std::cout<<"length:"<<len<<" ";
        while (i!=len)  
        {
            std::cout << data[(this->front+i+1)%MAX_SIZE]<<">>";
            i++;
        }
        

        std::cout<<"]";
        std::cout<<std::endl;
    }
};
