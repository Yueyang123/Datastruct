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
 *        佛曰:  
 *                写字楼里写字间，写字间里程序员；  
 *                程序人员写程序，又拿程序换酒钱。  
 *                酒醒只在网上坐，酒醉还来网下眠；  
 *                酒醉酒醒日复日，网上网下年复年。  
 *                但愿老死电脑间，不愿鞠躬老板前；  
 *                奔驰宝马贵者趣，公交自行程序员。  
 *                别人笑我忒疯癫，我笑自己命太贱；  
 *                不见满街漂亮妹，哪个归得程序员？
 */

#include <stdio.h>
#include <malloc.h>
#include <stack>
#include <string.h>
#include <iostream>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
 ElemType data;    //数据元素
 struct node *lchild;  //指向左孩子
 struct node *rchild;  //指向右孩子
} BTNode;
void CreateBTNode(BTNode *&b,char *str)  //由str串创建二叉链
{
 BTNode *St[MaxSize],*p=NULL;
 int top=-1,k,j=0; 
 char ch;
 b=NULL;    //建立的二叉树初始时为空
 ch=str[j];
 while (ch!='\0') //str未扫描完时循环
 {
    switch(ch)
  {
  case '(':top++;St[top]=p;k=1; break;  //为左节点
  case ')':top--;break;
  case ',':k=2; break;                       //为右节点
  default:p=(BTNode *)malloc(sizeof(BTNode));
   p->data=ch;p->lchild=p->rchild=NULL;
            if (b==NULL)                    //p指向二叉树的根节点
      b=p;
     else         //已建立二叉树根节点
     { 
      switch(k)
      {
      case 1:St[top]->lchild=p;break;
      case 2:St[top]->rchild=p;break;
      }
     }
  }
  j++;
  ch=str[j];
 }
}
BTNode *FindNode(BTNode *b,ElemType x) //返回data域为x的节点指针
{
 BTNode *p;
 if (b==NULL)
      return NULL;
 else if (b->data==x)
      return b;
 else
 { 
  p=FindNode(b->lchild,x);
  if (p!=NULL)
   return p;
  else
   return FindNode(b->rchild,x);
 }
}
BTNode *LchildNode(BTNode *p) //返回*p节点的左孩子节点指针
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p) //返回*p节点的右孩子节点指针
{
    return p->rchild;
}
int BTNodeDepth(BTNode *b) //求二叉树b的深度
{
    int lchilddep,rchilddep;
    if (b==NULL)
  return(0);        //空树的高度为0
    else 
 { 
  lchilddep=BTNodeDepth(b->lchild); //求左子树的高度为lchilddep
    rchilddep=BTNodeDepth(b->rchild); //求右子树的高度为rchilddep
  return (lchilddep>rchilddep)? (lchilddep+1):(rchilddep+1);
    }
}
void DispBTNode(BTNode *b) //以括号表示法输出二叉树
{
 if (b!=NULL)
 {
  printf("%c",b->data);
  if (b->lchild!=NULL || b->rchild!=NULL)
  {
   printf("(");
   DispBTNode(b->lchild);
   if (b->rchild!=NULL) printf(",");
   DispBTNode(b->rchild);
   printf(")");
  }
 }
}
int BTWidth(BTNode *b)  //求二叉树b的宽度
{
 struct
 {
  int lno;  //节点的层次编号
  BTNode *p;  //节点指针
 } Qu[MaxSize];  //定义顺序非循环队列
 int front,rear;       //定义队首和队尾指针
 int lnum,max,i,n;
 front=rear=0;       //置队列为空队
    if (b!=NULL)
 {
  rear++; 
  Qu[rear].p=b;      //根节点指针入队
  Qu[rear].lno=1;      //根节点的层次编号为1
  while (rear!=front)     //队列不为空
  {
   front++;
   b=Qu[front].p;     //队头出队
   lnum=Qu[front].lno;
   if (b->lchild!=NULL)   //左孩子入队
   {
    rear++;
    Qu[rear].p=b->lchild;
    Qu[rear].lno=lnum+1;
   }
   if (b->rchild!=NULL)   //右孩子入队
   {
    rear++;
    Qu[rear].p=b->rchild;
    Qu[rear].lno=lnum+1;
   }
  }
  max=0;lnum=1;i=1;
  while (i<=rear)
  {
   n=0;
   while (i<=rear && Qu[i].lno==lnum)
   {
    n++;i++;
   }
   lnum=Qu[i].lno;
   if (n>max) max=n;
  }
  return max;
 }
 else
  return 0;
}
int Nodes(BTNode *b) //求二叉树b的节点个数
{
 int num1,num2;
    if (b==NULL)
  return 0;
    else if (b->lchild==NULL && b->rchild==NULL)
  return 1;
    else
    {
        num1=Nodes(b->lchild);
        num2=Nodes(b->rchild);
        return (num1+num2+1);
 }
}
int LeafNodes(BTNode *b) //求二叉树b的叶子节点个数
{
 int num1,num2;
    if (b==NULL)
  return 0;
    else if (b->lchild==NULL && b->rchild==NULL)
  return 1;
    else
    {
        num1=LeafNodes(b->lchild);
        num2=LeafNodes(b->rchild);
        return (num1+num2);
 }
}
void DestroyBTNode(BTNode *&b)
{
 if (b!=NULL)
 {
  DestroyBTNode(b->lchild);
  DestroyBTNode(b->rchild);
  free(b);
 }
}

void PreOrder(BTNode *b)
{
    std::stack<char> LongPath;
    if(b!=NULL)
    {
        printf("%c ",b->data);
        LongPath.push(b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

int maxn = 0;
ElemType ans[100]; // 存储最长的逆序序列
void Reverse(BTNode *t,ElemType b[],int k)	// k用做数组下标
{
	if( t){
		b[k++] = t->data;
		if(t->lchild == NULL && t->rchild == NULL) {
			if(k > maxn) {
				maxn = k;
                strcpy(ans,b);
			}
			for(int i=k-1; i>=0; i--)
				std::cout << b[i] << " ";

                std::cout << std::endl;
		}
		else {
			Reverse(t->lchild,b,k);
			Reverse(t->rchild,b,k);
		}
	}
}

void PostOrder(BTNode *b)
{
  BTNode *p,*r;
  bool flag;
  std::stack<BTNode *> st;
  p=b;
  do
  {
    while (p!=NULL)
    {
      st.push(p);
      p=p->lchild;
    }
    r=NULL;
    flag =true;
      while (!st.empty()&&flag)
      {
         p=st.top();
         if(p->rchild==r)
         {
           printf("%c ",p->data);
           st.pop();
           r=p;
         }else
         {
           p=p->rchild;
           flag=false;
         }
         
      }
    
  }while (!st.empty());
  
}

#define MAX_SIZE	1024
#define STR_SIZE	1024
#define SPACE		6


typedef struct Quene {						//定义顺序队 
	int front;								//队头指针 
	BTNode* data[MAX_SIZE];					//存放队中元素 
	int rear;								//队尾指针 
}SqQueue; 

//初始化队列 
void initQueue(SqQueue*& q) {
	q = (SqQueue*)malloc(sizeof(SqQueue));	//分配一个空间 
	q->front = q->rear = -1;				//置 -1 
}

//判断队列是否为空
bool emptyQueue(SqQueue*& q) {
	if (q->front == q->rear) {				//首指针和尾指针相等，说明为空 
		return true;						//返回真 
	}
	else {
		return false;						//返回假 
	}
}

//进队列
bool enQueue(SqQueue*& q, BTNode*& BT) {
	if (q->rear == MAX_SIZE - 1) {			//判断队列是否满了 
		return false;						//返回假 
	}
	q->rear++;								//头指针加 1 
	q->data[q->rear] = BT;					//传值 
	return true;							//返回真 
}

//出队列 
bool deQueue(SqQueue*& q, BTNode*& BT) {
	if (q->front == q->rear) {				//判断是否空了 
		return false;						//返回假 
	}
	q->front++;								//尾指针加 1 
	BT = q->data[q->front];					//取值 
	return true;							//返回真 
}

//层次遍历 
void levelOrder(BTNode* BT) {
	SqQueue* q;									//定义队列 
	initQueue(q);								//初始化队列 
	if (BT != NULL) {
		enQueue(q, BT);							//根节点指针进队列 
	}
	while (emptyQueue(q) != true) {				//队不为空循环 
		deQueue(q, BT);							//出队时的节点 
		printf("%c ", BT->data);					//输出节点存储的值 
		if (BT->lchild != NULL) {				//有左孩子时将该节点进队列 
			enQueue(q, BT->lchild);
		}
		if (BT->rchild != NULL) {				//有右孩子时将该节点进队列 
			enQueue(q, BT->rchild);
		}										//一层一层的把节点存入队列 
	} 											//当没有孩子节点时就不再循环 
}

int main()
{ 
    BTNode *b,*p,*lp,*rp;;
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("basic :\n");
    printf("  (1)output:");DispBTNode(b);printf("\n");
    printf("  (2)H:");
    p=FindNode(b,'H');
    if (p!=NULL)
    { lp=LchildNode(p);
    if (lp!=NULL)
    printf("leftchild %c ",lp->data);
    else
    printf("no left child ");
    rp=RchildNode(p);
    if (rp!=NULL)
    printf("reght child %c",rp->data);
    else
    printf("no right child ");
    }
    printf("\n");
    printf("  (3)BTtree depth:%d\n",BTNodeDepth(b));
    printf("  (4)BTtree width:%d\n",BTWidth(b));
    printf("  (5)BTtree nodes num:%d\n",Nodes(b));
    printf("  (6)BTtree leaf  num:%d\n",LeafNodes(b));
    printf("  (7)BTtree\n");

    PreOrder(b);
    std::cout << std::endl;
    PostOrder(b);
    std::cout << std::endl;

    levelOrder(b);
    std::cout << std::endl;
    ElemType out[100];
    maxn = 0;
    Reverse(b,out,0);
    std::cout<<"MAXPATH: ";
    for(int i=maxn-1; i>=0; i--)
		std::cout << ans[i] << " ";

    DestroyBTNode(b);

return 0;
}