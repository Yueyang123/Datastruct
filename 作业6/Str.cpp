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
 */

/*
 * @Descripttion: 
 * @version: 
 * @Author: Yueyang
 * @email: 1700695611@qq.com
 * @Date: 2020-10-01 22:59:48
 * @LastEditors: Yueyang
 * @LastEditTime: 2020-10-06 15:01:30
 */
#include "Str.h"
#include <stack>

//abcd@dcba
bool if_rotate(Str s)
{
    std::stack<char> mystk;
    int i=0;
    while(s.data[i]!='@'&&i<s.length){
        mystk.push(s.data[i]);
        i++;
    }
    if(i==s.length)
        return false;
    else
    {
        i++;
        while(i<s.length&&s.data[i]==mystk.top()){
            i++;
            mystk.pop();  
        }

        if(i==s.length)return true;
        else return false;
    }
}


int main()
{
    // Str s1 =Str((char*)"abcabcdabcdeabcdefabcdefg");
    // Str s2 =Str((char*)"aaabc");
    // std::cout << Str::BF(s1,s2) << std::endl;
    // std::cout << Str::KMP1(s1,s2)<<std::endl;
    // std::cout << Str::KMP0(s1,s2)<<std::endl;


    Str s =Str((char*)"abcd@dcba");
    std::cout << if_rotate(s) << std::endl;
    return 0;
}