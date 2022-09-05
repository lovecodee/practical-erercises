
/*ɢ�б�--->ɢ�б�Ĳ��ң�����Ԫ�صĴ洢λ�ú͹ؼ���֮��Ĺ�ϵ����ϣ������
                    �ؼ��㣺��1����ι���ɢ�к���
                            ��2����ν����ͻ����   */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//��������
//�ܸ���10
/*
�������£�
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
//˳����ҽڵ�
typedef struct LNode{
    int info;//�ؼ�����Ϣ
    int Key;//�ؼ���λ��
    struct LNode *next;
}LNode,*LinkList;
//��ϣ����
typedef struct HashTable
{
 int  data;
 HashTable *next;
}HashTable;


//�����
typedef struct BSTNode
{
  int data;                        //������
  struct BSTNode *rchild,*lchild;  //���Һ���ָ��
 } BSTNode,*BSTree;
 //���˵���������

void menu();                                                         //���˵�
void EnterMenu(int *S,int total);                                   //���˵����
int* SetArray(int *S,int total);                                    //��ʼ������
//˳����Һ�������
void SeqInformation();                        //˳�����ѡ��
void Seqsearch(int *S,int total);                 //˳��������
LNode* InitList(LNode *L);                        //��ʼ��������
void CreateList(LNode *L,int *S,int total);             //����������
void DispList(LNode *L);                      //����������
LinkList Search_Seq(LNode *L, int key);               //˳�����
int ListLength(LNode *L);
//�۰���Һ�������
void BOutInformation();                                             //ѡ����Ϣ��
void Compromise(int *S,int total);                                  //�۰����
void Search_Bin(int S[],int key,int n);                             //�۰����
void display(int s[],int end);                                      //�������Ԫ��
void  swap(int* a, int* b);                                         //�����ַ��ֱ�Ӹı�����
void sorted(int s[],int begin,int end);                             //�����㷨

//������Һ�������
int Binary(int *S,int total);                   //�������
int SearchBST(BSTree T,int key,int ci);                     //����
void InorderPrint(BSTree T);                              //�������
void DeleteBST(BSTree &T,int e);                    //ɾ��
int InsertBST(BSTree &T,int *S,int total);                //����
void JudgeBST(BSTree T,int S);                        //��ֵ����
//��ϣ���Һ�������
void Hash_Table(int *S,int total);                                  //��ϣ�����
void HOutInformation();                                              //���ѡ����
void InitHashTable(HashTable *HT,int M,int *S,int total);          //��ʼ����ϣ��
void SearchHash(HashTable *HT,int key,int M);                      //���ҹؼ���key
void DeleteHash(HashTable *HT,int key,int M);                      //ɾ���ؼ���key
void InsertHash(HashTable *HT,int key,int M);                      //����ؼ���key
float CalHashWPLS(HashTable *HT,int M,int data);                   //����ASL��succes��
float CalHashWPLUS(HashTable *HT,int M);                           //����ASL��unsuccess��
int HashKeyNumber(HashTable *HT,int M);                            //���ϣ��ؼ��ָ���
void PrintfHash(HashTable *HT,int M);                              //�����ϣ��
int HashFunction(int M,int key);                                   //��ϣ����
//쳲��������Һ�������
//B������
int main(){
int *S;
int choice;
int total;
printf("*      ���ݵĳ�ʼ��     *\n");
printf("������Ԫ���ܸ�����\n");
scanf("%d",&total);
S = SetArray(S,total);          //��ʼ�����鲢�ҷ���Ԫ�ظ���
menu();
EnterMenu(S,total);

return 0;
}
//���ݴ�������
int* SetArray(int *S,int total)
{
int i;
S = (int*)malloc(sizeof(int)*total); //��̬�����ڴ�ռ�
printf("������Ԫ�أ�\n");
for( i=0;i<total;i++)
{
    scanf("%d",(S+i));
}
if(i==total){
    printf("���ݴ洢�ɹ���\n");

}
return S;
}
//���˵�
void menu(){
printf("\t********************************************************\n");
printf("\t*                    1.˳�����                        *\n");
printf("\t*                    2.�۰����                        *\n");
printf("\t*                    3.�������                        *\n");
printf("\t*                    4.��ϣ����                        *\n");
//printf("\t*                    5.쳲���������                    *\n");
//printf("\t*                    6.B������                         *\n");
printf("\t********************************************************\n");
}

//���˵����
void EnterMenu(int *S,int total)
{
int choice;
while(1)
{
printf("��ѡ��������ͣ�\n");
scanf("%d",&choice);                                                        //��ʾ���Ҳ˵�
switch(choice)
{
case 1:{Seqsearch(S,total);break;}
case 2:{Compromise(S,total);break;}
case 3:{Binary(S,total);break;}
case 4:{Hash_Table(S,total);break;}
case 5:{break;}
case 6:{break;}
default:{printf("ѡ���������");break;}
}
}
}
//˳����Ҳ�����ʾ
void SeqInformation()
{
printf("\t********************************************************\n");
printf("\t*                       ˳�����                       *\n");
printf("\t*                    1.��ʼ������������                *\n");
printf("\t*                    2.������������                    *\n");
printf("\t*                    3.����ؼ�����Ϣ���в���          *\n");
printf("\t*                    4.����ʱ��                        *\n");
printf("\t*                    5.��ȡ����                        *\n");
printf("\t*                    6.�������˵�                      *\n");
printf("\t********************************************************\n");
}
void Seqsearch(int *S,int total){//˳��������
  int key;//Ҫ���ҵĹؼ�����Ϣ
  int choice;
    LinkList L;
    SeqInformation();

    while(1)
{
  printf("��ѡ���㽫Ҫ���еĲ�����\n");
  scanf("%d",&choice);
  switch(choice){
    case 1:{
      L=InitList(L);
      CreateList(L,S,total);
      break;
    }
    case 2:{
      printf("����������:\n");
      DispList(L);
      break;
    }
    case 3:{
      LinkList m;
      printf("������Ҫ���ҵĹؼ�����Ϣ:\n");
      scanf("%d",&key);
      m = Search_Seq(L,key);
      if(m)
        printf("�ؼ���λ��Ϊ:%d\n\n",m->Key);
      else
        printf("����ʧ��!\n");
      break;
    }
    case 4:{
      int begin,end;
      LinkList m;
      printf("������Ҫ���ҵĹؼ�����Ϣ:\n");
      scanf("%d",&key);
      begin = clock();
      m = Search_Seq(L,key);
      end = clock();
      if(m)
        printf("�ؼ���λ��Ϊ:%d\n\n",m->Key);
      else
        printf("����ʧ��!\n");
      printf("����ʱ��Ϊ��%d ms\n",(end-begin));
      break;
    }
    case 5:{
      printf("����Ϊ��%d\n",ListLength(L));
      break;
    }
    case 6:{ menu();EnterMenu(S,total);
      break;
    }
    default:{printf("����ѡ����ڣ�");break;}

  }
}
}
//��ʼ��������
LNode* InitList(LNode *L)
{
  L = (LNode *)malloc(sizeof(LNode));
  L->next = NULL;
  printf("�������ѳ�ʼ��!\n");
  return L;
}
void CreateList(LNode *L,int *S,int total)//����������
{
  LNode* p=L;
    int i;
    LNode *s;//����һ���½��
    //����㸳ֵ�ؼ��ּ���Ϣ
    for(i=1;i<=total;i++)
  {
        s = (LNode *)malloc(sizeof(LNode));//�����½��
        s->info=S[i-1];
        s->Key=i;
    //���½�����ν��뵥����
    s->next = NULL;
    p->next = s;
    p = p->next;
  }
  printf("���������ɹ�!\n");
}
//����������
void DispList(LNode *L)
{
  LinkList p = L, q = L;
    printf("�ؼ���λ��Ϊ��\n");
  while(p->next)
  {
    p = p->next;
    printf("%d ", p->Key);//�ؼ���λ��
  }
  printf("\n");
  printf("�ؼ�����ϢΪ��\n");
  while(q->next)
  {
    q = q->next;
    printf("%d ", q->info);//�ؼ�����Ϣ
  }
  printf("\n\n");
}
LinkList Search_Seq(LNode *L, int key)//˳�����
{
  LinkList p = L;
  int i;
  while(p->next)
  {
    i++;
    p = p->next;
    //printf("���Ҵ���Ϊ%d��\n",i);
    if(p->info == key)
    {
      printf("���Ҵ���Ϊ%d \n",i);
      return p;
    }

  }

}
int ListLength(LNode *L)//��ȡ����
    {
        LinkList p=L;
    int sum=0;
        while(p)
        {
         sum++;
         p=p->next;
        }
        return sum-1;//ȥ��ͷ���
    }

//��ϣ�������ʾ
void HOutInformation()
{
printf("\t********************************************************\n");
printf("\t*                       ��ϣ��                         *\n");
printf("\t*                    1.��ʼ����ϣ��                    *\n");
printf("\t*                    2.��ӡ��ϣ��                      *\n");
printf("\t*                    3.���ҹؼ���                      *\n");
printf("\t*                    4.��ӹؼ���                      *\n");
printf("\t*                    5.ɾ���ؼ���                      *\n");
printf("\t*                    6.ͳ��Ԫ�ظ���                    *\n");
printf("\t*                    7.����ASL��success��              *\n");
printf("\t*                    8.����ASL��unsucces)              *\n");
printf("\t*                    9.���ز��Ҳ˵�                    *\n");
printf("\t********************************************************\n");
}

//��ϣ����
int HashFunction(int M,int key)
{
return key%M;
}

//��ϣ��
void Hash_Table(int *S,int total){
HashTable L[15];
int M=15;
float num;
int key1,key2;
int choice;
clock_t begin,end;                                               //��¼���ҵĿ�ʼʱ��ͽ���ʱ��
HOutInformation();                                               //�����ϣ�����ز�����Ϣ
while(1)
{
printf("��ѡ���㽫Ҫ���еĲ�����\n");
scanf("%d",&choice);
switch(choice)
{
case 1:{InitHashTable(L,M,S,total);break;}
case 2:{PrintfHash(L,M);HOutInformation();break;}
case 3:{printf("������Ҫ���ҵĹؼ��֣�\n");
         scanf("%d",&key1);
         begin= clock();
         SearchHash(L,key1,M);
         end = clock();
         printf("\n���ҹؼ�������ʱ��Ϊ��%d ms\n",(end-begin));
         break;
        }
case 4:{printf("���������ӵĹؼ��֣�\n");
        scanf("%d",&key1);
        InsertHash(L,key1,M);
       }
case 5:{  printf("�������ɾ���Ĺؼ��֣�\n");
          scanf("%d",&key2);
          DeleteHash(L,key2,M);
          break;
        }
case 6:{key1=HashKeyNumber(L,M);
        printf("��ϣ���е���Ԫ�ظ���Ϊ��%d\n",key1);
          break;}
case 7:{ key1 = HashKeyNumber(L,M);
         num = CalHashWPLS(L,M,key1);
         printf("���ҳɹ�ƽ�����ҳ���Ϊ��ASL(success)=%.2f\n",num);
            break;}
case 8:{num =  CalHashWPLUS(L,M);
        printf("����ʧ��ƽ�����ҳ��ȣ�ASL��unsucces)=%.2f\n",num);
            break;}
case 9:{menu();EnterMenu(S,total);break;}
default:{printf("����ѡ����ڣ�");break;}
}
}
}
//�����ؼ���
void SearchHash(HashTable *HT,int key,int M)
{
 //��ɢ�б�HT�в��ҹؼ���Ϊkey��Ԫ�أ�������ҳɹ�������ɢ�б�ĵ�Ԫ���ţ����򷵻�-1
 int H0 = HashFunction(M,key);                 //����ɢ�б���H��key������ɢ�е�ַ
 int flag = 0;
 HashTable *q;                  //������һ��ָ��
 q= HT+H0;                      //��ָ��ָ��õ�ַ
if ((q->data)==key)             //�����ԪH0��Ԫ�صĹؼ���Ϊkey,����ҳɹ�
{
    printf("�õ�Ԫλ��Ϊ��%d ",H0);
    flag=1;
}

else
{
    while(q->next!=NULL)
    {
        q=q->next;
        if(q->data==key)
        {
            printf("\n���ҳɹ�,�õ�Ԫλ��Ϊ��%d",H0+1);
            flag=1;
            break;
        }
    }

if(flag==0)
{
    printf("�޴��ڴ浥Ԫ");
}
}
}

 //��ʼ����ϣ��
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
    s->data=S[j];                                 //�����ݴ����½���������
    if(p->next!=NULL)                            //������ռ��Ѿ�����Ԫ��
    {
        s->next=p->next;                         //ͷ�巨
        p->next=s;
    }
    else                                         //������ռ�û��Ԫ��
    {
        p->next=s;
        s->next=NULL;
    }
}
if(j==total)
{
    printf("��ϣ���ʼ���ɹ���\n");
}
}

//�����ϣ��
void PrintfHash(HashTable *HT,int M)
{
    printf("��ϣ��չʾ����:\n");
  HashTable *p,*q;
  int i=1;

  for(p=HT,i=1;p<(HT+M);p++,i++)
  {
    q=p;
    printf("%d",i);                       // ���Ԫ�ش����ַ
    while(q->next!=NULL){
        q=q->next;                        //�ƶ�ָ��������λ��
        printf("->%d",q->data);           //���ָ����ָ��Ԫ��������
    }
      printf("\n");
  }
}

//ɾ����ϣ��ؼ���

void DeleteHash(HashTable *HT,int key,int M)
{
    int y=HashFunction(M,key);
    HashTable *p,*q;
    p= HT+y;
    int flag=0;
    while(p->next!=NULL)
    {
            q=p;                         //����ɾ������ǰһ���
            p=p->next;                              //����ָ��ɾ�����
        if(p->data==key)
            {
            if(p->next==NULL)            //��ɾ���Ϊβ���
             {
                flag=1;                   //���ҹؼ��ִ��ڣ���־λ��1
                q->next=NULL;
                delete p;                //ɾ�����
                break;                   //�˳�ѭ��
             }
            else                         //��ɾ�����Ϊ��β���
            {  flag=1;
               q->next=q->next->next;    //����ָ��ָ��
               delete p;                 //ɾ�����
               break;                    //�˳�ѭ��
            }
        }
    }
  if(flag==1)
{
    printf("ɾ���ɹ���");

}
else
{
    printf("��ϣ���в����ڸ�Ԫ�أ�");
}
}

//��ӹؼ���
void InsertHash(HashTable *HT,int key,int M)
{
    int y = HashFunction(M,key);
    int flag=0;
    HashTable *p;
    p=HT+y;
    HashTable *s=new HashTable;             //�����½ڵ�
    s->data=key;                            //�½���������ĳ�ʼ��
    if(p->next==NULL)
    {
        p->next=s;
        s->next=NULL;
        flag=1;
    }
    else
    {
        s->next=p->next;     //ͷ�巨
        p->next=s;
        flag=1;
    }
 if(flag==1){
    printf("��ӳɹ���");
 }
 else{
    printf("����ʧ�ܣ�");
 }

}

//����ϣ���ASL
float CalHashWPLS(HashTable *HT,int M,int data)
{
HashTable *p,*q;
q=HT;
int number ;
int sum=0.0;
for(;q<(HT+M);q++)
{
    p=q;                         //��pָ��q��ָ�ռ�
    number=0;                    //������һ��Ԫnumber��0
    if(p->next==NULL);           //���Ϊ��,���Ҵ���Ϊ0
    while(p->next!=NULL)
    {number++;
     sum+=number;
     p=p->next;
    }
}
return (float)sum/data;
}

//ͳ�ƹ�ϣ���Ԫ�ظ���

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


//����ASL��unsuccess��

float CalHashWPLUS(HashTable *HT,int M)
{
  HashTable *p,*q;
     p=HT;
int failure=0;

for(;p<(HT+M);p++)
{   q=p;
    if(q->next==NULL)
    {
        failure++;                 //ʧ�ܴ������
    }
    else
    {
      while(q->next!=NULL)
        {
            failure++;
            q=q->next;
        }
        failure++;                      //����ѭ����ʧ�ܴ�����1
    }
}
return (float)failure/M;
}
//�۰���Ҳ�����ʾ
void BOutInformation()
{
printf("\t*************************************************************************\n");
printf("\t*                              �۰����                                 *\n");
printf("\t*                        1.��������                                     *\n");
printf("\t*                        2.���ң�����ʱ��+���Ҵ�����                    *\n");
printf("\t*                        3.�������˵�                                   *\n");
printf("\t*************************************************************************\n");
}

//�۰�������

void Compromise(int *S,int total)
{
int choice ,locate;
clock_t begin ,end;
int key;
BOutInformation();
while(1){
printf("������ѡ��:\n");
scanf("%d",&choice);
switch(choice){
case 1:{printf("����ǰ�Ľ��Ϊ��\n");
        display(S,total);
        sorted(S,0,total-1);
        printf("�����Ľ��Ϊ��\n");
        display(S,total);
        break;}
case 2:{ printf("������Ҫ���ҵĹؼ��֣�\n");
            scanf("%d",&key);
          begin =clock();
          Search_Bin(S,key,total);
          end = clock();
          printf("��������ʱ��Ϊ��%dms\n",(end-begin));
          break;}
case 3:{menu();EnterMenu(S,total);break;}
default:{printf("�޴˲����\n");break;}
}
}
}

//�۰����
void Search_Bin(int S[],int key,int n)
{
//����������۰������ؼ��ֵ���key��Ԫ�ء�����ҵ�������ֵΪ��Ԫ���ڱ�������λ�ã�����Ϊ0
int low=0;                                  //�ò���ȡ����ֵ
int high=n-1;
int mid;
int flag=0;
int times=1;
while(low<=high)
{
    mid=(low+high)/2;
    if(key==S[mid])
    {
        printf("���ҳɹ�������λ��Ϊ��%d\n",mid+1);
        flag=1;
        break;
    }
    else if(key < S[mid])
    {
        high=mid-1;                        //������ǰһ�ӱ��н��в���
        times++;
    }
    else
    {
        low=mid+1;                         //�����ں�һ�ӱ��н��в���
        times++;
    }

}
printf("���Ҵ���Ϊ��%d\n",times);
if(flag==0)
{
    printf("����ʧ�ܣ�\n");
}
}
void display(int s[],int end)//�������Ԫ��
{

for(int i=0;i<end;i++)
{
    printf("%d ",s[i]);
}
printf("\n");
}

//����Ԫ��ֵ
void  swap(int* a, int* b)
{
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

//�����㷨
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
        if(s[i]>=s[begin])//i��j����ʱ
        {
            i--;

        }
        swap(&s[i],&s[begin]);
        sorted(s,begin,i);
        sorted(s,j,end);

     }

}
//����
int SearchBST(BSTree T,int key,int ci)
{

  if(!T) return 0;              //����ʧ��
  else if(key == T->data) {ci++;printf("���Ҵ���Ϊ%d\n",ci);return 1;}     //���ҳɹ�
  else if(key>T->data) {ci++;return SearchBST(T->rchild,key,ci);}// ����������
  else if(key<T->data) {ci++;return SearchBST(T->lchild,key,ci);}// ����������
}
//����
int InsertBST(BSTree &T,int e)
{

   if(1)                         //��������������ʱ
  {
    if(T == NULL)
    {
        T = (BSTree)malloc(sizeof(BSTNode));
      T->data = e;
      T->lchild = T->rchild = NULL;
      //printf("����ɹ�!\n");
        return 1;             //���Ϊ�� ������ڵ�

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
//�������
void InorderPrint(BSTree T)
{

if(T)                    //T����
   {
      InorderPrint(T->lchild);
      printf("%d  ",T->data);
      InorderPrint(T->rchild);
  }
 }
//ɾ��
void DeleteBST(BSTree &T)
{
  printf("��������Ҫɾ����Ԫ��:\n");
  int e;
  scanf("%d",&e);

  //������ʼ��
  BSTNode *p=NULL;
  BSTNode *f=NULL;
  BSTNode *q=NULL;
  BSTNode *s=NULL;
  p = T;
  f = NULL;

  /***********whileѭ��Ѱ��key�Ľڵ�*************/
  while(p)
  {
    if(p->data == e) break;
    f = p;               //fΪ��˫�׽ڵ�
    if(p->data > e) p = p->lchild;
    else if(p->data < e) p = p->rchild;
   }
   if(!p) return;


   /********������������з��� ������Ϊ�� ������Ϊ�� ���Ҿ���Ϊ��*********/

   q = p;
   if((p->lchild)&&(p->rchild))       //���Ҿ���Ϊ��
   {
     s = p->lchild;
     while(s->rchild)
     {
      q = s;s = s->rchild;     //sָ�������������ֵ
     }
      p->data = s->data;       // Sָ��ɾ�ڵ��ǰ��

      /**********�ؽ���������******/

      if(q != p) q->rchild = s->lchild;
      else q->lchild = s->lchild;
      delete s;
        printf("ɾ��֮��Ķ�����Ϊ:\n");
      InorderPrint(T);
      printf("\n");
      return;
    }
   else if((p->lchild) != NULL)     //��Ϊ��
   {
    p = p->lchild;
   }
   else if((p->rchild)!=NULL)      //�Ҳ�Ϊ��
   {
    p = p->rchild;
    }

  else if((p->rchild)==NULL&&(p->lchild) == NULL)
  {

    if(p->data > f->data) f->rchild = NULL;
    else if (p->data < f->data) f->lchild = NULL;
  }

  /********��p��ָ�������ҵ���˫�׽ڵ�F��Ӧλ��***********/
  if(!f) T = p;                           //��ɾ����Ϊ���ڵ�
  else if(q==f->lchild) f->lchild = p;   //�ҽӵ�������
  else if(q==f->rchild) f->rchild=p;    //�ҽӵ�������λ��
  delete q;
  printf("ɾ��֮��Ķ���������Ϊ:\n");
  InorderPrint(T);
  printf("\n");
}
void InitBST(BSTree &T,int S[],int total)
{
  int i;
  for( i = 0;i<total;i++)
  {
    InsertBST(T,S[i]);               //�������в�����ֵ

  }
}
//���ҿ�ʼ
void JudgeBST(BSTree T)
{

  int key;

  int begin,end;
  int ci;
    printf("����������Ҫ���ҵ�ֵ:\n");
    scanf("%d",&key);
    begin = clock();
    if(SearchBST(T,key,ci) == 0)       //����ʧ��
    {
      printf("����ʧ��!\n");

    }
     else                          //���ҳɹ�
     {
      printf("�ڶ������в��ҵ���ֵ\n");
     }
     end = clock();  //����
    printf("���ҹؼ�������Ҫ��ʱ��Ϊ:%d ms\n",(end-begin));


 }
 void Binaryformation()
{
printf("\t********************************************************\n");
printf("\t*                       ������                         *\n");
printf("\t*                    1.��ʼ��������                    *\n");
printf("\t*                    2.��ӡ������                      *\n");
printf("\t*                    3.��ӹؼ���                      *\n");
printf("\t*                    4.���ҹؼ���                      *\n");
printf("\t*                    5.ɾ���ؼ���                      *\n");
printf("\t*                    6.���ز��Ҳ˵�                    *\n");
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
  printf("���������ѡ��:\n");
  scanf("%d",&choice);
  if(choice==1){BSTree T;printf("��ʼ���ɹ���\n");T = NULL;} //��ʼ��
  else if(choice==2){printf("����������Ϊ:\n");InorderPrint(T);printf("\n");}              //�������
  else if(choice==3){printf("����������Ҫ�����ֵ:\n");scanf("%d",&e);if(InsertBST(T,e)==1) printf("����ɹ�!\n");else printf("����ʧ��!\n");}//��ֵ����
  else if(choice==4){JudgeBST(T);}
  else if(choice==5){DeleteBST(T);}//ɾ��
  else if(choice==6){menu();EnterMenu(S,total);}

    }

  return 0;

}









