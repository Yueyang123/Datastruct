/*
 * @Descripttion: 
 * @version: 
 * @Author: Yueyang
 * @email: 1700695611@qq.com
 * @Date: 2020-09-28 22:48:09
 * @LastEditors: Yueyang
 * @LastEditTime: 2020-09-28 23:48:10
 */
#include "Queue.h"
#include "stdlib.h"
#include <iostream>


using namespace std;

class Hospital:public Queue<int>
{
public:
    std::string str;

    Hospital():Queue()
    {
    }

    void queue()
    {
        std::cout << "/* please input you ID */" << std::endl;
        std::cin>>str;
        this->queue_in(atoi(str.c_str()));
    }

    void out()
    {
        int tmp;
        queue_out(tmp);
    }
    
    void go_home()
    {
        cout<<"GOOD BYE!!";
        exit(0);
    }
    void hos_progress()
    {
        char choose;


        cout<<"--------WELLCOME!!-------"<<endl;
        cout<<"----------GUIDE----------"<<endl;
        cout<<"--------q: queue---------"<<endl;
        cout<<"--------o: out-----------"<<endl;
        cout<<"--------s: show----------"<<endl;
        cout<<"-------x: go home--------"<<endl;
        while (1)
        {
            cin>>choose;
            switch (choose)
            {
            case 'q':
                queue();
                break;

            case 'o':
                out();
                break;


            case 's':
                show();
                break;

            case 'x':
                go_home();
                break;
            default:
                break;
            }
        }
            


    }
};

int main()
{
    Hospital *h=new Hospital();
    h->hos_progress();
    
}