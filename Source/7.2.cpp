#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;
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
int LeafNodeCount(BiTree T)
{
	if(T==NULL)
		return 0;
	else if(T->lchild==NULL&&T->rchild==NULL)
		return 1;
	else
		return LeafNodeCount(T->lchild)+LeafNodeCount(T->rchild);
}
void ChangeLR(BiTree T)
{
	BiTree p;
	if(T==NULL||(T->lchild==NULL&&T->rchild==NULL))
		return;
	else
	{
		p=T->lchild;
		T->lchild=T->rchild;
		T->rchild=p;
	}
	ChangeLR(T->lchild);
	ChangeLR(T->rchild);
}
int D1_Nodes(BiTree T)
{
	int num1,num2;
	if(T==NULL||(!T->lchild&&!T->rchild))
		return 0;
	num1=D1_Nodes(T->lchild);
	num2=D1_Nodes(T->rchild);
	if(T->lchild&&!T->rchild)
		return num1+1;
	else if(!T->lchild&&T->rchild)
		return num2+1;
	else
		return num1+num2;
}
int Nodes(BiTree T)
{
	int num1,num2;
	if(T==NULL)
		return 0;
	else{
		num1=Nodes(T->lchild);
		num2=Nodes(T->rchild);
		return num1+num2+1;
	}
}
int BiTreeDepth(BiTree T)
{
	int leftdep,rightdep;
	if(T==NULL)
		return 0;
	else
	{
		leftdep=BiTreeDepth(T->lchild);
		rightdep=BiTreeDepth(T->rchild);
		return (leftdep>rightdep)? (leftdep+1):(rightdep+1);
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
	int n;
	BiTNode *proot;
	proot=NULL;
	printf("请输入根结点元素（#表无）：");
	CreateBiTree(proot);
	printf("\n(1)二叉树创建成功！其括号表示格式输出：\n\t");
	OutputBiTree(proot);
	printf("\n");
	n=Nodes(proot);
	printf("(2)二叉树结点总数是：%d\n",n);
	n=LeafNodeCount(proot);
	printf("(3)二叉树的叶子结点数是：%d\n",n);
	n=BiTreeDepth(proot);
	printf("(4)二叉树的深度是：%d\n",n);
	n=D1_Nodes(proot);
	printf("(5)二叉树中度为1的结点数是：%d\n",n);
	ChangeLR(proot);
	printf("(6)交换所有结点的左右孩子后二叉树括号表示法输出：%d\n",n);
    OutputBiTree(proot);
	printf("\n");
}
