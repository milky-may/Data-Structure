#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream.h>
#include<string.h>
#define ERROR 0
#define OK 1
typedef int Status;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;

typedef struct Stack{
	BiTNode *t;
	int flag;
	struct Stack *next;
}Stack,*LinkStack;

typedef struct QNode{
	BiTree t;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

void Push(LinkStack &top,BiTree tree){
	LinkStack p;
	p=(Stack*)malloc(sizeof(Stack));
	p->t=tree;
	p->next=top;
	top=p;
}
void Pop(LinkStack &top,BiTree &tree)
{
	LinkStack p=top;
	if(top==NULL)
		tree=NULL;
	else{
		tree=top->t;
		top=top->next;
		free(p);
	}
}
Status InitQueue(LinkQueue &Q){
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) return ERROR;
	Q.front->next=NULL;
	return OK;
}
Status EnQueue(LinkQueue &Q,BiTree e){
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p) return ERROR;
	p->t=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}
Status DeQueue(LinkQueue &Q,BiTree &e){
	QueuePtr p;
	if(Q.rear==Q.front)
		return ERROR;
	p=Q.front->next;
    e=p->t;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	free(p);
	return OK;
}
void re_PreOrder(BiTNode *tree){
	if(tree!=NULL){
		printf("%c ",tree->data);
		re_PreOrder(tree->lchild);
		re_PreOrder(tree->rchild);
	}
}
void re_MidOrder(BiTNode *tree){
	//请编写中序遍历子程序
	
        if(tree!=NULL)
		{	re_MidOrder(tree->lchild);//1
			printf("%c ",tree->data);
            re_MidOrder(tree->rchild);
}
}
void re_PostOrder(BiTNode *tree){
	if(tree!=NULL){
		re_PostOrder(tree->lchild);
		re_PostOrder(tree->rchild);
		printf("%c ",tree->data);
	}
}
void st_PreOrder(BiTNode *tree)
{
	LinkStack top;
	top=NULL;
	while(tree!=NULL){
		printf("%c ",tree->data);//2
		if(tree->rchild)//3
			Push(top,tree->rchild);
		if(tree->lchild!=NULL)
                    Push(top,tree->lchild);//4
		Pop(top,tree);
	}
}
void st_MidOrder(BiTNode *tree)
{
	LinkStack top;
	top=NULL;
	while(tree||top){//5
		while(tree!=NULL){
			Push(top,tree);
                       tree=tree->lchild;//6
		}
		if(top!=NULL){
			Pop(top,tree);
			printf("%c ",tree->data);//7
			tree=tree->rchild;//8
		}
	}
}
void st_PostOrder(BiTNode *tree)
{
	LinkStack top;
	top=NULL;
	do{
		while(tree){//9
			Push(top,tree);
			top->flag=0;
			tree=tree->lchild;//10
		}
		if(top!=NULL){
			while(top!=NULL&&top->flag){//11
				Pop(top,tree);
				printf("%c ",tree->data);
			}
			if(top!=NULL){
				top->flag=1;//12
				tree=(top->t)->rchild;
			}
		}
	}while(top!=NULL);
}
void LevelOrder(BiTNode *root){
	LinkQueue Q;
	BiTree p;
	if(root!=NULL){
		InitQueue(Q);
		EnQueue(Q,root);
		while(Q.front!=Q.rear){//13
			DeQueue(Q,p);
			printf("%c ",p->data);
			if(p->lchild!=NULL) EnQueue(Q,p->lchild);
            if(p->rchild!=NULL) EnQueue(Q,p->rchild);
		}
		printf("\n");
	}
}
void CreateBiTree(BiTree &T)
{
	char ch;
	scanf("\n%c",&ch);
	if(ch=='#')
		T=NULL;
	else
	{
		T=(BiTree)malloc(sizeof(BiTNode));
		if(!T)
			exit(-1);
		T->data=ch;
		printf("\n请输入%c结点的左子结点（#表无）：",T->data);
		CreateBiTree(T->lchild);
		printf("\n请输入%c结点的右子结点（#表无）：",T->data);
		CreateBiTree(T->rchild);
	}
}
void OutputBiTree(BiTree T)
{
	if(T!=NULL)
	{
		printf("%c",T->data);
		if(T->lchild!=NULL||T->rchild!=NULL)
		{
			printf("(");
			OutputBiTree(T->lchild);
			if(T->rchild!=NULL)
				printf(",");
			OutputBiTree(T->rchild);
			printf(")");
		}
	}
}
void main()
{
	BiTNode *proot;
	proot=NULL;
	printf("请输入根结点元素（#表无）：");
	CreateBiTree(proot);//14
	printf("\n(1)二叉树创建成功，其括号表示格式输出：\n\t");
    OutputBiTree(proot);
    printf("\n(2)先序遍历，递归方法\n\t");
	re_PreOrder(proot);//15
    printf("\n(3)中序遍历，递归方法\n\t");
	re_MidOrder(proot);//16
    printf("\n(4)后序遍历，递归方法\n\t");
	re_PostOrder(proot);//17
    printf("\n(5)先序遍历，链接栈的迭代方法\n\t");
	st_PreOrder(proot);//18
    printf("\n(6)中序遍历，链接栈的迭代方法\n\t");
	st_MidOrder(proot);//19
    printf("\n(7)后序遍历，链接栈的迭代方法\n\t");
	st_PostOrder(proot);//20
    printf("\n(8)后序遍历，链接栈的迭代方法\n\t");
	LevelOrder(proot);
}