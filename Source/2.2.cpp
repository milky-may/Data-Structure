#define OK 1
#define ERROR 0
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int status;
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

void CreateList(LinkList &L,int n){
	int i;
	LNode *p,*q,*s;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(i=0;i<n;++i){
		s=(LinkList)malloc(sizeof(LNode));
		printf("请输入第%d个结点值：",i+1);
		scanf("%d",&s->data);
		p=L;
		q=L->next;
		// while(_____1_____){
		// 	_____2_____;
		while(q!=NULL && (s->data > q->data)){
			p=q;
			q=q->next;
		}
		// _____3______;
		s->next=q;
		p->next=s;
	}
}//CreateList

void Mergesort(LinkList &A,LinkList &B,LinkList &C){
	LNode *pa,*pb,*pc;
	pa=A->next;
	pb=B->next;
	C=pc=A;
	while(pa && pb){
		if(pa->data<=pb->data){
			// _____4______;
			// _____5______;
			// _____6______;
			pc->next=pa;
			pc=pc->next;
			pa=pa->next;
		}
		else
		{
			// _____7______;
			// _____8______;
			// _____9______;
			pc->next=pb;
			pc=pc->next;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	free(B);
}//Mergesort

void OutputList(LinkList L)
{
	LinkList p=L->next;
	// while(_____10_______){
	while(p){
		printf("%d->",p->data);
		p=p->next;
	}
	printf("\n");
}

int main(void){
	LinkList La,Lb,Lc;
	int na=5,nb=4;
	printf("(1)创建有序单链表A......\n");
	CreateList(La,na);
	printf("A链表输出：");
	OutputList(La);
	printf("(2)创建有序单链表B......\n");
	CreateList(Lb,nb);
	printf("B链表输出：");
	OutputList(Lb);
	printf("(3)归并A、B到C，C链表仍有序......\n");
	Mergesort(La,Lb,Lc);
	printf("C链表输出：\n");
	OutputList(Lc);
}