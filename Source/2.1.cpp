#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FLASE 0
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int Status;
typedef int ElemType;

typedef struct LNode{
	ElemType data;   //数据域
	struct LNode*next;
}LNode,*LinkList;

Status CreatLinkL1(LinkList &L,int n,ElemType *E){
	int i;
	LinkList p;
	L=(LinkList) malloc(sizeof(LNode));
	if(!L) return ERROR;
	L->next=NULL;
	for(i=n-1;i>=0;--i)
	{
		if(!(p=(LinkList)malloc(sizeof(LNode))))
			return ERROR;
		p->data=E[i];
		// ______1______;
		// ______2______;
		p->next=L->next;
		L->next=p;
	}
	return OK;
}
Status  CreatLinkL2(LinkList  &L,int n,ElemType *E){
//用表尾插入法建立带头结点的单链表
	int i;
	LinkList p,r;
	L = (LinkList)malloc(sizeof(LNode));
	if(!L)  return ERROR;
	r=L;											//初始化尾指针
	for(i=0;i<n;i++)
	{
		if(!(p=(LinkList)malloc(sizeof(LNode))))	//生成新结点
			return ERROR;
		p->data=E[i];
		// ________3___________;						//新结点插入到表尾
		// _________4__________;
		r->next=p;
		r=r->next;
	}
	r->next=NULL;
	return OK;
}
Status InsertLinkL(LinkList &L, int i, ElemType e){
	//在带头结点的单链列表L中第i个位置之前插入元素e
	LinkList s, p=L;
	int k=0;               //初始化，p指向头结点，k为计数器
	while(p->next!=NULL && k<i-1){ //定位指针p指向第i-1个元素或p为空
		p=p->next;
		++k;
	}
	if(!p->next||k>i-1) return ERROR;  //定位插入点失败
	if(!(s=(LinkList)malloc(sizeof(LNode))))  //申请元素e的结点空间
		return OVERFLOW;           //内存无空闲单元，无法申请到空间
	s->data=e;
	// ____5____;          //将新结点s插入到链表中
	// ____6____;
	s->next=p->next;
	p->next=s;
	return OK;
}
Status Del_LinkL1(LinkList L,int i,ElemType &e){
	int k=0;
	LinkList q,p=L;
	while(p->next!=NULL&&k<i-1){
		p=p->next; ++k;
	}
	if(!p->next||k>i-1) return ERROR;
	q=p->next;
	// _______7________;
	p->next=q->next;
	e=q->data; free(q);
	return OK; 
}
Status Del_LinkL2(LinkList &L,ElemType e)
{
	LinkList p,q;
	p=L;
	q=L->next;
	// while(_______8________;){
	while(q->data!=e){
		p=q;
	    q=q->next;
	}
	if(q==NULL)
		return ERROR;
	p->next=q->next;
	free(q);
	return OK;
}
Status Del_LinkL3(LinkList &L,ElemType e)
{
	LinkList p,q;
	int tag=FLASE;
	p=L;
	q=L->next;
	while(q!=NULL){
		if(q->data==e)
		{
			// ________9_______;
			p->next=q->next;
			free(q);
			tag=TRUE;
		}
		else
		    p=q;
		q=p->next;
	}
	return tag;
}
void PrintLinkL(LinkList L)
{
	LinkList p=L->next;
	while(p){
		printf("%d→",p->data);
		p=p->next;
	}
	printf("∧\n");
}

void FreeLinkL(LinkList &L)
{
	LinkList p,q;
	p=L;
	while(p!=NULL){
		// __________10___________;
		q=p;
		p=p->next;
		free(q);
	}
	L=NULL;
}
int main()
{
	ElemType  E[]={34,12,45,64,28,36,45,56};    //准备线性表
	int i,n=8;
	LinkList head;
	ElemType rc;
	printf("(1)表头插入法创建单链表......\n");
	if(!CreatLinkL1(head,n,E)){
		printf(" 内存空间不够，创建失败! \n");
		return 0;
	}
	else {
		printf(" 创建完成。链表输出: ");
		PrintLinkL(head);
	}
	printf("(2)表尾插入法创建单链表......\n");
	FreeLinkL(head);
	if(!CreatLinkL2(head,n,E)) {
		printf(" 内存空间不够，创建失败! \n");
		return 0;
	}
	else {
		printf(" 创建完成。链表输出: ");
		PrintLinkL(head);
	}
	printf("(3)指定位置插入......\n");
	printf("输入插入位置和新元素值==>");
	scanf("%d%d",&i,&rc);
	if(!InsertLinkL(head,i,rc))
		printf(" 参数错误或内存空间不够，插入失败! \n");
	else {
        printf("插入成功！链表输出：");
	    PrintLinkL(head);
	}
    printf("(4)删除指定位置节点......\n");
    printf("输入被删除节点位置==>");
    scanf("%d",&i);
    if(!Del_LinkL1(head,i,rc))
        printf("参数错误，删除失败!\n");
    else{
	    printf("删除成功！被删除的节点键值是：%d\n 链表输出：",rc);
		PrintLinkL(head);
	}
    printf("(5)删除指定节点值......\n");
    printf("输入被删除键值==>");
    scanf("%d",&rc);
    if(!Del_LinkL2(head,rc))
        printf("输入的键值不存在！\n");
    else{
	    printf("删除成功！键表输出：");
	    PrintLinkL(head);
	}
    printf("(6)删除指定值所有节点.......\n");
    printf("输入所有被删节点的键值==>");
    scanf("%d",&rc);
    if(!Del_LinkL3(head,rc))
        printf("输入的键值不存在！\n");
    else{
	    printf("删除成功！链表输出：");
	    PrintLinkL(head);
	}
    printf("(7)清空链表......\n");
    FreeLinkL(head);
    if(!head)
        printf("链表已清空\n");
    else
        printf("清空链表失败！");
}
	



