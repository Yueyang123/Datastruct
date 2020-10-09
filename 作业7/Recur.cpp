/*
 * @Descripttion: 
 * @version: 
 * @Author: Yueyang
 * @email: 1700695611@qq.com
 * @Date: 2020-10-08 16:56:25
 * @LastEditors: Yueyang
 * @LastEditTime: 2020-10-09 11:59:02
 */
#include<stdio.h>
#include<string.h>
#include <iostream>
#include <list>


void reverse(char* str)
{	
	char tmp = *str;//用tmp存入 字符串的第一个字符
	int len = strlen(str);//求当前字符串的长度 ps:每次递归，长度都会变化
	*str = *(str+len-1);//将'\0'的前一个元素赋给第一个
	*(str+len-1) = '\0';//将'\0'的前一个元素先赋成'\0'
	if(strlen(str)>1)
    {//当字符串长度大于1，递归  ps:每次替换一直向中间逼近，当没有字符或只有一个字符的时候都不必继续
		reverse(str+1);//进行递归，首地址指针后移
        printf("%s\n",str);     
    }
    *(str+len-1) = tmp;//全部递归完成后，将'\0'还原成原来的中间元素	
}


#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct LNode{
    int data;
    LNode *next;
}LNode,*LinkList;
void CreatLinkList(LinkList &L){
    LinkList r,s;
    L=(LinkList)malloc(sizeof(LNode));
    int n;
    cin>>n;
    s=L;
    while(n--){
        r=(LinkList)malloc(sizeof(LNode));
        cin>>r->data;
        s->next=r;
        s=r;
    }
    s->next=NULL;
}
void showList(LinkList L){
    LNode *r;
    r=L->next;
    while(r){
        cout<<r->data<<" ";
        r=r->next;
    }
    cout<<endl;
}
//带头节点
void Tran_show(LinkList L,int n){//递归思想的，链表倒序
    if(n==0){
            n++;
        Tran_show(L->next,n);//先跳过头结点
    }else{
    if(!L){
        return;
    }else{
        Tran_show(L->next,n);
        cout<<L->data<<" ";
    }
    }
}
//不带头节点
/*
void Tran_show(LinkList L){
    if(!L){
        return;
    }else{
        Tran_show(L->next,n);
        cout<<L->data<<" ";
    }
}*/
int main(){
    LinkList L;
    CreatLinkList(L);
    showList(L);
    Tran_show(L,0);
    //Tran_show(L);
    return 0;
}



int main_T()
{		
	char str[] = "!dlroW olleH";
	reverse(str);
	printf("%s\n",str); 
	
    std::list<char> l;
    for(int i=0;i<strlen(str);i++)
    l.push_back(str[i]);
    std::cout<<l.size()<< std::endl;
    return 0;
}