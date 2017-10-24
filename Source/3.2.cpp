#define MAXN 1000
#define OK 1
#define ERROR 0
#include "stdio.h"
#include "malloc.h"
#include "string.h"
typedef int status;
typedef char SelemType;
typedef struct StackNode {//˳��ջ�Ķ���
    SelemType data;
    struct StackNode *next;
}StackNode,*linkstack;

void InitStack(linkstack &S){                       //����һ����ջS
	S=NULL;
}

status Push(linkstack &S, SelemType e){
	//����Ԫ��eΪ�������ջ��Ԫ��
	linkstack p;
	p=(linkstack)malloc(sizeof(StackNode));
	if(!p) return ERROR;             //�洢����ʧ��
	p->next=S;
	p->data=e;
	S=p;
    return OK;
}

status Pop(linkstack &S, SelemType &e){
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	linkstack p=S;
	if(!S) return ERROR;
	e=p->data;
	S=p->next;
	free(p);
	return OK;
}

int StackEmpty(linkstack S){//�ж�ջS�Ƿ�����
      return S==NULL;
}

int correct( char *exp, int max )           //��Ժ���
// �������Ϊ���ʽ�ͱ��ʽ���ȣ�����1Ϊ�ɹ�������0Ϊ���� 
{
    int i, flag = 1;                       // ����ƥ���־��1Ϊƥ��
    char e,x;
	linkstack S;
	InitStack(S);
    for( i=0;i<max && flag ==1 ; i++) {    // ѭ������Ϊ���ʽδ����������ƥ��
        x=exp[i];
		if( exp[i]=='('||exp[i]=='['||exp[i]=='{')   // �������Ž�ջ
            Push(S,x);
        if(x==')'||x==']'||x=='}')                             // �������ų�ջ
        {  if(!Pop(S,e)) flag=0;   // ��ջ������ջ������������̫�࣬ʧ��!
           else if((x==')'&&e!='(')||(x==']'&&e!='[')||(x=='}'&&e!='{')) flag = 0;       // ���Ų�ƥ�� 
		}
	}
    if(!StackEmpty(S))  // ���ʽɨ����ϣ���ջ�ǿ���������̫�࣬ʧ��!
        flag = 0;
    return flag;
}

void main()
{
    char exp[MAXN];
    while( 1 ) {
        printf("��������ʽ������0�˳���");
        gets(exp);               /* �ӱ�׼�����ж�ȡ���ʽ */
        if(strcmp(exp,"0")==0)
           break;
        if(correct(exp, strlen(exp))==0)
           printf("���ʽ����Ϊ��\n%s\n���ʽ���Ų�ƥ��\n", exp);
        else
           printf("���ʽ����ƥ��!\n");
    }
}