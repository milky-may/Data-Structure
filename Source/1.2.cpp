#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int Status;
typedef int ElemType;  //将元素类型定义为整型
typedef struct{
    ElemType *elem;
    int length;
    int listsize;
}SqlList;

Status CreatList(SqList &L){
    int i;
    do{
        printf("请输入元素个数:");
        scanf("%d",&L.Length);
    }while(______1______);
    L.elem=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));
    if(!L.elem)return ERROR;
    for(i=0;i<L.length;i++){
        printf("请输入第%d个元素值=>",i+1);
        scanf("%d",_____2_______);
    }
    return OK;
}

Status InsertList(SqList &L,int i,int m,ElemType *E){
    if(_______3__________)
        return ERROR;
    ElemType *p;
    int j;
    if(_______4_________){
        p=(ElemType *)realloc(L.elem,(L.length+m)*sizeof(ElemType));
        if(!p)exit(OVERFLOW);
        L.elem=p;
        L.listsize=L.length+m;
    }
    for(j=L.length-1;j>=i-1;--j)
        L.elem[j+m]=L.elem[j];
    for(j=0;j<m;j++)
        L.elem[i+j-1]=E[j];
    L.length=_______5__________;
    return OK;
}//InsertList

Status DeleteList(SqList &L,int x,int y){
    if(x>y)return ERROR;
    int i,j;
    for(i=j=0;i<L.length;i++)
        if(L.elem[i]>=x && L.elem[i]<=y)
            _______6________;
        else
            _______7________;
    L.length-=j;
    return OK;
}

void PrintList(SqList L){
    int i;
    printf("顺序表中有%d个元素：\n",L.length);
    for(i=0;i<L.length;i++)
        printf("%4d",L.elem[i]);
    printf("\n");
}

void main(){
    SqList L;
    int i,m=3;
    ElemType E[]={23,24,25};
    ElemType x,y;
    printf("(1)建立有n个元素的顺序表.....\n");
    if(!CreatList(L)){printf("创建顺序表失败！\n");return;}
    printf("当前顺序表如下：\n");
    PrintList(L);

    printf("(2)在顺序表第i个位置上插入m个新元素......\n");
    printf("请输入插入位置i:\n");
    scanf("%d",&i);
    if(!InsertList(L,i,m,E))
        printf("插入失败！\n");
    else{
        printf("插入成功！插入后的顺序表如下:\n");
        PrintList(L);
    }

    printf("(3)在顺序表中删除其值介于x到y之间的所有元素......\n");
    printf("请输入被删元素下限值x:");
    scanf("%d",&x);
    printf("请输入被删元素上限值y:");
    scanf("%d",&y);
    if(!DeleteList(L,x,y))
        printf("参数错误，删除失败！");
    else{
        printf("删除后的顺序表如下：");
        PrintList(L);
    }
}























