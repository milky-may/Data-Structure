#define STACK_INIT_SIZE 100    //栈存储空间初始分配量
#define STACKINCREMENT 10   //栈存储空间分配增量
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int status;
typedef char SelemType;
typedef struct{              //顺序栈的定义
	SelemType *base;
    SelemType *top;
	int stacksize;
}SqStack;

status InitStack(SqStack &S){          //构造一个空栈S
	S.base=(SelemType*)malloc(STACK_INIT_SIZE*sizeof(SelemType));
	if(!S.base) exit(OVERFLOW);         //存储分配失败
	S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
	return OK;
}
status Push(SqStack &S,SelemType e){
	  //插入元素e为新的栈顶元素
	if(S.top-S.base>=S.stacksize){          //栈满，追加存储空间
		S.base=(SelemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SelemType));
		if(!S.base)   exit(OVERFLOW);       //存储分配失败
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;
}
status Pop(SqStack &S,SelemType &e){
	  //若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S.top==S.base)     return ERROR;
	e=*--S.top;
	return OK;
}
status StackEmpty(SqStack S){                        //判断栈S是否为空
    if(S.top==S.base)
        return TRUE;
    else return FALSE;
}

void conversion(){                                   //进制转换
//对于输入的任意一个非负十进制整数，打印输出与其等值的对应的进制数
    SqStack S;
    int N,d,ys;
    SelemType x,e;
    InitStack(S);                                    //构造空栈
    while(1){
        printf("请输入一个非负十进制数(0结束):");
        scanf("%d",&N);
        if(N==0) break;
        printf("请输入要转换的进制：");
        scanf("%d",&d);                              //2、8或16进制
        while(N){                                    //输出相应的符号
            ys=N%d;                        //求余
            if(ys<=9)
                x=ys+'0';
            else
                x=ys-10+'A';
            Push(S,x);
            N=N/d;                        //求商
        }
        printf("转换所得%d进制数为：",d);
        while(!StackEmpty(S)){                       //显示结果
    	    Pop(S,e);
    	    printf("%c",e);
        }
        printf("\n");
    }
}

void main(){
    conversion();	
}