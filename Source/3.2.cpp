#define MAXN 1000
#define OK 1
#define ERROR 0
#include "stdio.h"
#include "malloc.h"
#include "string.h"
typedef int status;
typedef char SelemType;
typedef struct StackNode {//顺序栈的定义
    SelemType data;
    struct StackNode *next;
}StackNode,*linkstack;

void InitStack(linkstack &S){                       //构造一个空栈S
	S=NULL;
}

status Push(linkstack &S, SelemType e){
	//插入元素e为新世界的栈顶元素
	linkstack p;
	p=(linkstack)malloc(sizeof(StackNode));
	if(!p) return ERROR;             //存储分配失败
	p->next=S;
	p->data=e;
	S=p;
    return OK;
}

status Pop(linkstack &S, SelemType &e){
	//若栈不空，则删除S的栈顶元素，用e反回其值，并返回OK；否则返回ERROR
	linkstack p=S;
	if(!S) return ERROR;
	e=p->data;
	S=p->next;
	free(p);
	return OK;
}

int StackEmpty(linkstack S){//判断栈S是否已满
      return S==NULL;
}

int correct( char *exp, int max )           //配对函数
// 传入参数为表达式和表达式长度，返回1为成功，返回0为错误 
{
    int i, flag = 1;                       // 括号匹配标志，1为匹配
    char e,x;
	linkstack S;
	InitStack(S);
    for( i=0;i<max && flag ==1 ; i++) {    // 循环条件为表达式未结束且括号匹配
        x=exp[i];
		if( exp[i]=='('||exp[i]=='['||exp[i]=='{')   // 遇左括号进栈
            Push(S,x);
        if(x==')'||x==']'||x=='}')                             // 遇右括号出栈
        {  if(!Pop(S,e)) flag=0;   // 出栈，若出栈出错，则右括号太多，失配!
           else if((x==')'&&e!='(')||(x==']'&&e!='[')||(x=='}'&&e!='{')) flag = 0;       // 括号不匹配 
		}
	}
    if(!StackEmpty(S))  // 表达式扫描完毕，若栈非空则左括号太多，失配!
        flag = 0;
    return flag;
}

void main()
{
    char exp[MAXN];
    while( 1 ) {
        printf("请输入表达式，输入0退出：");
        gets(exp);               /* 从标准输入中读取表达式 */
        if(strcmp(exp,"0")==0)
           break;
        if(correct(exp, strlen(exp))==0)
           printf("表达式内容为：\n%s\n表达式括号不匹配\n", exp);
        else
           printf("表达式括号匹配!\n");
    }
}