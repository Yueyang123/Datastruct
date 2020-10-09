/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑       永不宕机     永无BUG
 * 
 */

/*
 * @Descripttion: 
 * @version: 
 * @Author: Yueyang
 * @email: 1700695611@qq.com
 * @Date: 2020-10-01 22:59:48
 * @LastEditors: Yueyang
 * @LastEditTime: 2020-10-08 00:41:08
 */
#include <iostream>

#define MAX_SIZE 50

class Str 
{
public:
    char data[MAX_SIZE];
    int length;
    Str(char *str)
    {
        int i=0;
        for(i=0;str[i]!='\0';i++)
        {
            this->data[i]=str[i];
        }
        this->length=i;
    }

    int get_length()
    {
        return length;
    }

    void disp()
    {
        std::cout << "[ " ;
        if(this->length>0)
        {
            for(int i=0;i<length;i++)
            std::cout << this->data[i]<<" ";
        }
        std::cout<<"]"<<std::endl;
    }

    static int BF(Str s1,Str s2)
    {
        int i=0,j=0;
        while (i<s1.length&&j<s2.length)
        {
            if(s1.data[i]==s2.data[j])
            {i++;j++;}
            else
            {i=i-j+1;j=0;}
        }
        if(j>=s2.length)
            return i-s2.length;
        else
            return -1;
    }


    static inline void get_next(int* next,Str& t)
    {
        int j=0,k=-1;
        next[0]=-1;
        while(j<t.length-1)
        {
            if(k == -1 || t.data[j] == t.data[k])
            {
                j++;k++;
                next[j] = k;
            }
            else k = next[k];//此语句是这段代码最反人类的地方，如果你一下子就能看懂，那么请允许我称呼你一声大神！
        }   
        for(int i=0;i<t.length;i++)
            std::cout << "next:" <<std::dec<<next[i]<< std::endl;
    }


    static inline void cal_next(int* nextval,Str& t)
    {
        int j=0,k=-1;
        
        nextval[0] = -1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀

        while(j<t.length){
            if(k == -1 || t.data[j] == t.data[k])
            {
                j++;k++;
                if(t.data[j]!=t.data[k])
                nextval[j] = k;
                else
                    nextval[j]=nextval[k];
                
            }
            else k = nextval[k];//此语句是这段代码最反人类的地方，如果你一下子就能看懂，那么请允许我称呼你一声大神！
        }
        for(int i=0;i<t.length;i++)
            std::cout << "next:" <<std::dec<<nextval[i]<< std::endl;
    }


    static int KMP0(Str& s,Str& t)
    {
        int i=0,j=0;
        int next[MAX_SIZE];
        get_next(next,t);
        while(i<s.length&&j<t.length)
        {
            if(j==-1 || s.data[i]==t.data[j])
            {
                i++;
                j++;
            }
            else j=next[j];               //j回退。。。
        }
        if(j>=t.length)
            return (i-t.length);         //匹配成功，返回子串的位置
        else
            return (-1);                  //没找到
    }
    
    static int KMP1(Str& s,Str& t)
    {
        int i=0,j=0;
        int nextval[MAX_SIZE];
        cal_next(nextval,t);
        while(i<s.length&&j<t.length)
        {
            if(j==-1 || s.data[i]==t.data[j])
            {
                i++;
                j++;
            }
            else j=nextval[j];               //j回退。。。
        }
        if(j>=t.length)
            return (i-t.length);         //匹配成功，返回子串的位置
        else
            return (-1);                  //没找到
    }
};
