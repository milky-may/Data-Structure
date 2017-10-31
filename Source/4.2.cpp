#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 10
#define OK 1
#define ERROR 0
typedef int Status;
typedef int QElemType;
typedef struct {
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue &Q){
	Q.base=(QElemType*)malloc(MAXSIZE*sizeof(QElemType));
	if(!Q.base) return ERROR;
	//________1_________;
	Q.front = Q.rear = 0;
	return OK;
}

Status EnQueue(SqQueue &Q,QElemType e){
	//if(__________2________) return ERROR;
	if((Q.rear+1)%MAXSIZE == Q.front) return ERROR;
	Q.base[Q.rear]=e;
	//Q.rear=_______3________;
	Q.rear = (Q.rear+1)%MAXSIZE;
	return OK;
} 

Status DeQueue(SqQueue &Q,QElemType &e){
	//if(______4_____) return ERROR;
	if(Q.rear == Q.front) return ERROR;
	e=Q.base[Q.front];
	//Q.front=__________5______;
	Q.front = (Q.front+1)%MAXSIZE;
	return OK;
}

void OutputQueue(SqQueue Q)
{
	while(Q.front!=Q.rear) {
		printf("%d ",Q.base[Q.front]);
		Q.front=(Q.front+1)%MAXSIZE;
	}
	printf("\n");
}
void main()
{
 SqQueue Q;
 InitQueue(Q);
 int op,x;
 while( 1 )
 {
     printf("请选择操作: 1.进队 2.出队 0.退出==>");
     scanf("%d",&op);
     switch(op){
     case 0:
          return;
     case 1:
          printf("请输入进队元素: ");
          scanf("%d",&x);
          //if(_____________________)
		  if(!EnQueue(Q,x))
             printf("   队列满！ \n");
          else{
              printf("进队成功，队内元素为: \n");
              OutputQueue(Q);
          }
         break;
     case 2:
         //if(___________){
		 if(DeQueue(Q,x) ){
            printf("出队元素为:[%d],队内元素为: \n",x);
            OutputQueue(Q);
         }
         else
             printf(" 队已空! \n");
         break;
    }
  }
}