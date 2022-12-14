
/*散列表--->散列表的查找，建立元素的存储位置和关键字之间的关系（哈希函数）
                    关键点：（1）如何构造散列函数
                            （2）如何解决冲突问题   */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//测试数据
//总个数10
/*
数据如下：
2
34
45
6
78
80
79
89
9
65
*/
//顺序查找节点
typedef struct LNode{
    int info;//关键字信息
    int Key;//关键字位置
    struct LNode *next;
}LNode,*LinkList;
//哈希表结点
typedef struct HashTable
{
 int  data;
 HashTable *next;
}HashTable;


//树结点
typedef struct BSTNode
{
  int data;                        //数据域
  struct BSTNode *rchild,*lchild;  //左右孩子指针
 } BSTNode,*BSTree;
 //主菜单函数声明

void menu();                                                         //主菜单
void EnterMenu(int *S,int total);                                   //主菜单入口
int* SetArray(int *S,int total);                                    //初始化数组
//顺序查找函数声明
void SeqInformation();                        //顺序查找选项
void Seqsearch(int *S,int total);                 //顺序查找入口
LNode* InitList(LNode *L);                        //初始化单链表
void CreateList(LNode *L,int *S,int total);             //创建单链表
void DispList(LNode *L);                      //遍历单链表
LinkList Search_Seq(LNode *L, int key);               //顺序查找
int ListLength(LNode *L);
//折半查找函数声明
void BOutInformation();                                             //选项信息表
void Compromise(int *S,int total);                                  //折半入口
void Search_Bin(int S[],int key,int n);                             //折半查找
void display(int s[],int end);                                      //输出数组元素
void  swap(int* a, int* b);                                         //传入地址，直接改变内容
void sorted(int s[],int begin,int end);                             //快排算法

//二叉查找函数声明
int Binary(int *S,int total);                   //二叉入口
int SearchBST(BSTree T,int key,int ci);                     //查找
void InorderPrint(BSTree T);                              //中序遍历
void DeleteBST(BSTree &T,int e);                    //删除
int InsertBST(BSTree &T,int *S,int total);                //插入
void JudgeBST(BSTree T,int S);                        //数值输入
//哈希查找函数声明
void Hash_Table(int *S,int total);                                  //哈希表入口
void HOutInformation();                                              //输出选项栏
void InitHashTable(HashTable *HT,int M,int *S,int total);          //初始化哈希表
void SearchHash(HashTable *HT,int key,int M);                      //查找关键字key
void DeleteHash(HashTable *HT,int key,int M);                      //删除关键字key
void InsertHash(HashTable *HT,int key,int M);                      //插入关键字key
float CalHashWPLS(HashTable *HT,int M,int data);                   //计算ASL（succes）
float CalHashWPLUS(HashTable *HT,int M);                           //计算ASL（unsuccess）
int HashKeyNumber(HashTable *HT,int M);                            //求哈希表关键字个数
void PrintfHash(HashTable *HT,int M);                              //输出哈希表
int HashFunction(int M,int key);                                   //哈希函数
//斐波那契查找函数声明
//B树查找
int main(){
int *S;
int choice;
int total;
printf("*      数据的初始化     *\n");
printf("请输入元素总个数：\n");
scanf("%d",&total);
S = SetArray(S,total);          //初始化数组并且返回元素个数
menu();
EnterMenu(S,total);

return 0;
}
//数据存入数组
int* SetArray(int *S,int total)
{
int i;
S = (int*)malloc(sizeof(int)*total); //动态分配内存空间
printf("请输入元素：\n");
for( i=0;i<total;i++)
{
    scanf("%d",(S+i));
}
if(i==total){
    printf("数据存储成功！\n");

}
return S;
}
//主菜单
void menu(){
printf("\t********************************************************\n");
printf("\t*                    1.顺序查找                        *\n");
printf("\t*                    2.折半查找                        *\n");
printf("\t*                    3.二叉查找                        *\n");
printf("\t*                    4.哈希查找                        *\n");
//printf("\t*                    5.斐波那契查找                    *\n");
//printf("\t*                    6.B树查找                         *\n");
printf("\t********************************************************\n");
}

//主菜单入口
void EnterMenu(int *S,int total)
{
int choice;
while(1)
{
printf("请选择查找类型：\n");
scanf("%d",&choice);                                                        //显示查找菜单
switch(choice)
{
case 1:{Seqsearch(S,total);break;}
case 2:{Compromise(S,total);break;}
case 3:{Binary(S,total);break;}
case 4:{Hash_Table(S,total);break;}
case 5:{break;}
case 6:{break;}
default:{printf("选项输入错误！");break;}
}
}
}
//顺序查找操作提示
void SeqInformation()
{
printf("\t********************************************************\n");
printf("\t*                       顺序查找                       *\n");
printf("\t*                    1.初始化并创建链表                *\n");
printf("\t*                    2.遍历链表数据                    *\n");
printf("\t*                    3.输入关键字信息进行查找          *\n");
printf("\t*                    4.查找时间                        *\n");
printf("\t*                    5.获取长度                        *\n");
printf("\t*                    6.返回主菜单                      *\n");
printf("\t********************************************************\n");
}
void Seqsearch(int *S,int total){//顺序查找入口
  int key;//要查找的关键字信息
  int choice;
    LinkList L;
    SeqInformation();

    while(1)
{
  printf("请选择你将要进行的操作：\n");
  scanf("%d",&choice);
  switch(choice){
    case 1:{
      L=InitList(L);
      CreateList(L,S,total);
      break;
    }
    case 2:{
      printf("遍历单链表:\n");
      DispList(L);
      break;
    }
    case 3:{
      LinkList m;
      printf("请输入要查找的关键字信息:\n");
      scanf("%d",&key);
      m = Search_Seq(L,key);
      if(m)
        printf("关键字位置为:%d\n\n",m->Key);
      else
        printf("查找失败!\n");
      break;
    }
    case 4:{
      int begin,end;
      LinkList m;
      printf("请输入要查找的关键字信息:\n");
      scanf("%d",&key);
      begin = clock();
      m = Search_Seq(L,key);
      end = clock();
      if(m)
        printf("关键字位置为:%d\n\n",m->Key);
      else
        printf("查找失败!\n");
      printf("所用时间为：%d ms\n",(end-begin));
      break;
    }
    case 5:{
      printf("长度为：%d\n",ListLength(L));
      break;
    }
    case 6:{ menu();EnterMenu(S,total);
      break;
    }
    default:{printf("输入选项不存在！");break;}

  }
}
}
//初始化单链表
LNode* InitList(LNode *L)
{
  L = (LNode *)malloc(sizeof(LNode));
  L->next = NULL;
  printf("单链表已初始化!\n");
  return L;
}
void CreateList(LNode *L,int *S,int total)//创建单链表
{
  LNode* p=L;
    int i;
    LNode *s;//定义一个新结点
    //给结点赋值关键字及信息
    for(i=1;i<=total;i++)
  {
        s = (LNode *)malloc(sizeof(LNode));//生成新结点
        s->info=S[i-1];
        s->Key=i;
    //将新结点依次接入单链表
    s->next = NULL;
    p->next = s;
    p = p->next;
  }
  printf("单链表创建成功!\n");
}
//遍历单链表
void DispList(LNode *L)
{
  LinkList p = L, q = L;
    printf("关键字位置为：\n");
  while(p->next)
  {
    p = p->next;
    printf("%d ", p->Key);//关键字位置
  }
  printf("\n");
  printf("关键字信息为：\n");
  while(q->next)
  {
    q = q->next;
    printf("%d ", q->info);//关键字信息
  }
  printf("\n\n");
}
LinkList Search_Seq(LNode *L, int key)//顺序查找
{
  LinkList p = L;
  int i;
  while(p->next)
  {
    i++;
    p = p->next;
    //printf("查找次数为%d！\n",i);
    if(p->info == key)
    {
      printf("查找次数为%d \n",i);
      return p;
    }

  }

}
int ListLength(LNode *L)//获取长度
    {
        LinkList p=L;
    int sum=0;
        while(p)
        {
         sum++;
         p=p->next;
        }
        return sum-1;//去除头结点
    }

//哈希表操作提示
void HOutInformation()
{
printf("\t********************************************************\n");
printf("\t*                       哈希表                         *\n");
printf("\t*                    1.初始化哈希表                    *\n");
printf("\t*                    2.打印哈希表                      *\n");
printf("\t*                    3.查找关键字                      *\n");
printf("\t*                    4.添加关键字                      *\n");
printf("\t*                    5.删除关键字                      *\n");
printf("\t*                    6.统计元素个数                    *\n");
printf("\t*                    7.计算ASL（success）              *\n");
printf("\t*                    8.计算ASL（unsucces)              *\n");
printf("\t*                    9.返回查找菜单                    *\n");
printf("\t********************************************************\n");
}

//哈希函数
int HashFunction(int M,int key)
{
return key%M;
}

//哈希表
void Hash_Table(int *S,int total){
HashTable L[15];
int M=15;
float num;
int key1,key2;
int choice;
clock_t begin,end;                                               //记录查找的开始时间和结束时间
HOutInformation();                                               //输出哈希表的相关操作信息
while(1)
{
printf("请选择你将要进行的操作：\n");
scanf("%d",&choice);
switch(choice)
{
case 1:{InitHashTable(L,M,S,total);break;}
case 2:{PrintfHash(L,M);HOutInformation();break;}
case 3:{printf("请输入要查找的关键字：\n");
         scanf("%d",&key1);
         begin= clock();
         SearchHash(L,key1,M);
         end = clock();
         printf("\n查找关键字所用时间为：%d ms\n",(end-begin));
         break;
        }
case 4:{printf("请输入待添加的关键字：\n");
        scanf("%d",&key1);
        InsertHash(L,key1,M);
       }
case 5:{  printf("请输入待删除的关键字：\n");
          scanf("%d",&key2);
          DeleteHash(L,key2,M);
          break;
        }
case 6:{key1=HashKeyNumber(L,M);
        printf("哈希表中的总元素个数为：%d\n",key1);
          break;}
case 7:{ key1 = HashKeyNumber(L,M);
         num = CalHashWPLS(L,M,key1);
         printf("查找成功平均查找长度为：ASL(success)=%.2f\n",num);
            break;}
case 8:{num =  CalHashWPLUS(L,M);
        printf("查找失败平均查找长度：ASL（unsucces)=%.2f\n",num);
            break;}
case 9:{menu();EnterMenu(S,total);break;}
default:{printf("输入选项不存在！");break;}
}
}
}
//搜索关键字
void SearchHash(HashTable *HT,int key,int M)
{
 //再散列表HT中查找关键字为key的元素，如果查找成功，返回散列表的单元符号，否则返回-1
 int H0 = HashFunction(M,key);                 //根据散列表函数H（key）计算散列地址
 int flag = 0;
 HashTable *q;                  //定义了一个指针
 q= HT+H0;                      //将指针指向该地址
if ((q->data)==key)             //如果单元H0中元素的关键字为key,则查找成功
{
    printf("该单元位置为：%d ",H0);
    flag=1;
}

else
{
    while(q->next!=NULL)
    {
        q=q->next;
        if(q->data==key)
        {
            printf("\n查找成功,该单元位置为：%d",H0+1);
            flag=1;
            break;
        }
    }

if(flag==0)
{
    printf("无此内存单元");
}
}
}

 //初始化哈希表
void InitHashTable(HashTable *HT,int M,int *S,int total)
{
int y;
int i,j;
for( i=0;i<M;i++)
{
    HT[i].next=NULL;
}

for( j=0;j<total;j++)
{
    y = HashFunction(M,S[j]);
    HashTable *p,*q;
    p=HT+y;
    HashTable *s=new HashTable;
    s->data=S[j];                                 //将数据存入新结点的数据域
    if(p->next!=NULL)                            //该数组空间已经存在元素
    {
        s->next=p->next;                         //头插法
        p->next=s;
    }
    else                                         //该数组空间没有元素
    {
        p->next=s;
        s->next=NULL;
    }
}
if(j==total)
{
    printf("哈希表初始化成功！\n");
}
}

//输出哈希表
void PrintfHash(HashTable *HT,int M)
{
    printf("哈希表展示如下:\n");
  HashTable *p,*q;
  int i=1;

  for(p=HT,i=1;p<(HT+M);p++,i++)
  {
    q=p;
    printf("%d",i);                       // 输出元素储存地址
    while(q->next!=NULL){
        q=q->next;                        //移动指针至下移位置
        printf("->%d",q->data);           //输出指针所指单元的数据域
    }
      printf("\n");
  }
}

//删除哈希表关键字

void DeleteHash(HashTable *HT,int key,int M)
{
    int y=HashFunction(M,key);
    HashTable *p,*q;
    p= HT+y;
    int flag=0;
    while(p->next!=NULL)
    {
            q=p;                         //最终删除结点的前一结点
            p=p->next;                              //最终指向删除结点
        if(p->data==key)
            {
            if(p->next==NULL)            //待删结点为尾结点
             {
                flag=1;                   //查找关键字存在，标志位置1
                q->next=NULL;
                delete p;                //删除结点
                break;                   //退出循环
             }
            else                         //待删除结点为非尾结点
            {  flag=1;
               q->next=q->next->next;    //更改指针指向
               delete p;                 //删除结点
               break;                    //退出循环
            }
        }
    }
  if(flag==1)
{
    printf("删除成功！");

}
else
{
    printf("哈希表中不存在该元素！");
}
}

//添加关键字
void InsertHash(HashTable *HT,int key,int M)
{
    int y = HashFunction(M,key);
    int flag=0;
    HashTable *p;
    p=HT+y;
    HashTable *s=new HashTable;             //生成新节点
    s->data=key;                            //新结点的数据域的初始化
    if(p->next==NULL)
    {
        p->next=s;
        s->next=NULL;
        flag=1;
    }
    else
    {
        s->next=p->next;     //头插法
        p->next=s;
        flag=1;
    }
 if(flag==1){
    printf("添加成功！");
 }
 else{
    printf("插入失败！");
 }

}

//求解哈希表的ASL
float CalHashWPLS(HashTable *HT,int M,int data)
{
HashTable *p,*q;
q=HT;
int number ;
int sum=0.0;
for(;q<(HT+M);q++)
{
    p=q;                         //将p指向q所指空间
    number=0;                    //遍历下一单元number置0
    if(p->next==NULL);           //如果为空,查找次数为0
    while(p->next!=NULL)
    {number++;
     sum+=number;
     p=p->next;
    }
}
return (float)sum/data;
}

//统计哈希表的元素个数

int HashKeyNumber(HashTable *HT,int M){
HashTable *p,*q;
q=HT;
int total;
for(;q<(HT+M);q++)
{   p=q;
    while(p->next!=NULL)
    {
        total++;
        p=p->next;
    }
}
return total;
}


//计算ASL（unsuccess）

float CalHashWPLUS(HashTable *HT,int M)
{
  HashTable *p,*q;
     p=HT;
int failure=0;

for(;p<(HT+M);p++)
{   q=p;
    if(q->next==NULL)
    {
        failure++;                 //失败次数求和
    }
    else
    {
      while(q->next!=NULL)
        {
            failure++;
            q=q->next;
        }
        failure++;                      //跳出循环后失败次数加1
    }
}
return (float)failure/M;
}
//折半查找操作提示
void BOutInformation()
{
printf("\t*************************************************************************\n");
printf("\t*                              折半查找                                 *\n");
printf("\t*                        1.快速排序                                     *\n");
printf("\t*                        2.查找（查找时间+查找次数）                    *\n");
printf("\t*                        3.返回主菜单                                   *\n");
printf("\t*************************************************************************\n");
}

//折半查找入口

void Compromise(int *S,int total)
{
int choice ,locate;
clock_t begin ,end;
int key;
BOutInformation();
while(1){
printf("请输入选项:\n");
scanf("%d",&choice);
switch(choice){
case 1:{printf("排序前的结果为：\n");
        display(S,total);
        sorted(S,0,total-1);
        printf("排序后的结果为：\n");
        display(S,total);
        break;}
case 2:{ printf("请输入要查找的关键字：\n");
            scanf("%d",&key);
          begin =clock();
          Search_Bin(S,key,total);
          end = clock();
          printf("查找所用时间为：%dms\n",(end-begin));
          break;}
case 3:{menu();EnterMenu(S,total);break;}
default:{printf("无此操作项！\n");break;}
}
}
}

//折半查找
void Search_Bin(int S[],int key,int n)
{
//在有序表中折半查找其关键字等于key的元素。如果找到，则函数值为该元素在表中所在位置，否则为0
int low=0;                                  //置查找取件初值
int high=n-1;
int mid;
int flag=0;
int times=1;
while(low<=high)
{
    mid=(low+high)/2;
    if(key==S[mid])
    {
        printf("查找成功，查找位置为：%d\n",mid+1);
        flag=1;
        break;
    }
    else if(key < S[mid])
    {
        high=mid-1;                        //继续在前一子表中进行查找
        times++;
    }
    else
    {
        low=mid+1;                         //继续在后一子表中进行查找
        times++;
    }

}
printf("查找次数为：%d\n",times);
if(flag==0)
{
    printf("查找失败！\n");
}
}
void display(int s[],int end)//输出数组元素
{

for(int i=0;i<end;i++)
{
    printf("%d ",s[i]);
}
printf("\n");
}

//交换元素值
void  swap(int* a, int* b)
{
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

//快排算法
void sorted(int s[],int begin,int end)
{
    int i,j;
    if(begin<end)
        {
            i=begin+1;
            j=end;
    while(i<j)
        {
        if(s[i]>s[begin])
        {
            swap(&s[i],&s[j]);
            j--;

        }
        else
        {
            i++;
        }
        }
        if(s[i]>=s[begin])//i和j碰面时
        {
            i--;

        }
        swap(&s[i],&s[begin]);
        sorted(s,begin,i);
        sorted(s,j,end);

     }

}
//查找
int SearchBST(BSTree T,int key,int ci)
{

  if(!T) return 0;              //查找失败
  else if(key == T->data) {ci++;printf("查找次数为%d\n",ci);return 1;}     //查找成功
  else if(key>T->data) {ci++;return SearchBST(T->rchild,key,ci);}// 查找右子树
  else if(key<T->data) {ci++;return SearchBST(T->lchild,key,ci);}// 查找左子树
}
//插入
int InsertBST(BSTree &T,int e)
{

   if(1)                         //当二叉树不存在时
  {
    if(T == NULL)
    {
        T = (BSTree)malloc(sizeof(BSTNode));
      T->data = e;
      T->lchild = T->rchild = NULL;
      //printf("插入成功!\n");
        return 1;             //如果为空 插入根节点

    }
    else if(e==T->data)
    {
      return 1;
    }
     else if(e > T->data)
     {
        return InsertBST(T->rchild,e);
     }
     else if(e<T->data)
     {
        return  InsertBST(T->lchild,e);
     }

  }
}
//中序遍历
void InorderPrint(BSTree T)
{

if(T)                    //T存在
   {
      InorderPrint(T->lchild);
      printf("%d  ",T->data);
      InorderPrint(T->rchild);
  }
 }
//删除
void DeleteBST(BSTree &T)
{
  printf("请输入想要删除的元素:\n");
  int e;
  scanf("%d",&e);

  //变量初始化
  BSTNode *p=NULL;
  BSTNode *f=NULL;
  BSTNode *q=NULL;
  BSTNode *s=NULL;
  p = T;
  f = NULL;

  /***********while循环寻找key的节点*************/
  while(p)
  {
    if(p->data == e) break;
    f = p;               //f为其双亲节点
    if(p->data > e) p = p->lchild;
    else if(p->data < e) p = p->rchild;
   }
   if(!p) return;


   /********分三种情况进行分析 左子树为空 右子树为空 左右均不为空*********/

   q = p;
   if((p->lchild)&&(p->rchild))       //左右均不为空
   {
     s = p->lchild;
     while(s->rchild)
     {
      q = s;s = s->rchild;     //s指向左子树的最大值
     }
      p->data = s->data;       // S指向被删节点的前驱

      /**********重接左右子树******/

      if(q != p) q->rchild = s->lchild;
      else q->lchild = s->lchild;
      delete s;
        printf("删除之后的二叉树为:\n");
      InorderPrint(T);
      printf("\n");
      return;
    }
   else if((p->lchild) != NULL)     //左不为空
   {
    p = p->lchild;
   }
   else if((p->rchild)!=NULL)      //右不为空
   {
    p = p->rchild;
    }

  else if((p->rchild)==NULL&&(p->lchild) == NULL)
  {

    if(p->data > f->data) f->rchild = NULL;
    else if (p->data < f->data) f->lchild = NULL;
  }

  /********将p所指的子树挂到其双亲节点F相应位置***********/
  if(!f) T = p;                           //被删除的为根节点
  else if(q==f->lchild) f->lchild = p;   //挂接到左子树
  else if(q==f->rchild) f->rchild=p;    //挂接到右子树位置
  delete q;
  printf("删除之后的二叉树遍历为:\n");
  InorderPrint(T);
  printf("\n");
}
void InitBST(BSTree &T,int S[],int total)
{
  int i;
  for( i = 0;i<total;i++)
  {
    InsertBST(T,S[i]);               //二叉树中插入数值

  }
}
//查找开始
void JudgeBST(BSTree T)
{

  int key;

  int begin,end;
  int ci;
    printf("请输入你想要查找的值:\n");
    scanf("%d",&key);
    begin = clock();
    if(SearchBST(T,key,ci) == 0)       //查找失败
    {
      printf("查找失败!\n");

    }
     else                          //查找成功
     {
      printf("在二叉树中查找到该值\n");
     }
     end = clock();  //查找
    printf("查找关键字所需要的时间为:%d ms\n",(end-begin));


 }
 void Binaryformation()
{
printf("\t********************************************************\n");
printf("\t*                       二叉树                         *\n");
printf("\t*                    1.初始化二叉树                    *\n");
printf("\t*                    2.打印二叉树                      *\n");
printf("\t*                    3.添加关键字                      *\n");
printf("\t*                    4.查找关键字                      *\n");
printf("\t*                    5.删除关键字                      *\n");
printf("\t*                    6.返回查找菜单                    *\n");
printf("\t********************************************************\n");
}
int Binary(int S[],int total)
{
  BSTree T;
  T = NULL;
  int e;
  Binaryformation();
  int choice;
  InitBST(T,S,total);
  while(1){
  printf("请输入你的选择:\n");
  scanf("%d",&choice);
  if(choice==1){BSTree T;printf("初始化成功！\n");T = NULL;} //初始化
  else if(choice==2){printf("二叉树遍历为:\n");InorderPrint(T);printf("\n");}              //中序遍历
  else if(choice==3){printf("请输入你想要插入的值:\n");scanf("%d",&e);if(InsertBST(T,e)==1) printf("插入成功!\n");else printf("插入失败!\n");}//数值插入
  else if(choice==4){JudgeBST(T);}
  else if(choice==5){DeleteBST(T);}//删除
  else if(choice==6){menu();EnterMenu(S,total);}

    }

  return 0;

}









