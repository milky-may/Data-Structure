#define OK 1
#define ERROR 0
#include<stdio.h>
#include<malloc.h>
typedef int	Status;
typedef int	QElemType;

typedef struct QNode{ //链表结点类型
	QElemType data;
	struct QNode *next;
}QEode,*QueuePtr;

typedef struct{  //队列类型
	QueuePtr front;//对头指针
	QueuePtr rear; //队尾指针
}LinkQueue;

Status InitQueue(LinkQueue &Q){
	//构造一个带附加表头结点的空链队列Q
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) return ERROR;
	Q.front->next=NULL;
	return OK;
	}
	Status EnQueue(LinkQueue &Q,QElemType e){
		//将元素e插入到带头结点的链队列Q中
		QueuePtr p;
		p=(QueuePtr)malloc(sizeof(QNode));
		if(!p) return ERROR;
		p->data=e;
		p->next=NULL;
		//1_________________;
		//2_________________;
		Q.rear->next = p;
		Q.rear = p;
		return OK;
	}
Status DeQueue(LinkQueue &Q,QElemType &e){
	QueuePtr p;
	if(Q.rear==Q.front)
		return ERROR;
	p=Q.front->next;
	e=p->data;
	//_______3_______;
	Q.front->next = p->next;
	if(Q.rear==p)
		//________4______;
		Q.rear = Q.front;
	free(p);
	return OK;
}

void OutputQueue(LinkQueue Q)
{
	QueuePtr p;
	p=Q.front->next;
	while(p!=NULL){
		printf("%d ",p->data);
		//_5_____________;
		p = p->next;
	}
	printf("\n");
	return;
}

void main()
{
	LinkQueue Q;
	InitQueue(Q);
	int op,x;
	while(1){
		printf("请选择操作：1.进队  2.出队  0.退出==>");
		scanf("%d",&op);
		switch(op){
		case 0:
			return;
		case 1:
			printf("请输入进队元素：");
			scanf("%d",&x);
		    //__________6________;
			EnQueue(Q,x);
			printf("队内元素为：\n");
			OutputQueue(Q);
			break;
		case 2:
			//if(___________7_____){
			if(DeQueue(Q,x)){
				printf("出队元素为：[%d], 队内元素为：\n",x);
				OutputQueue(Q);
			}
			else
				printf("  队已空! \n");
			break;
		}
	}
}
