#include<stdio.h>
#define MAX 21
typedef struct{            //定义Huffman树结点结构
   char data;              //结点值
   int weight;             //权重
   int parent;             //父结点
   int lchild;             //左孩子
   int rchild;             //右孩子
}HTNode;
typedef struct{             //定义Huffman编码结构
   char cd[MAX];
   int start;
}HCode;

void CreatHT(HTNode *HT,int n)
{
   int i,k,l,r;
   int m1,m2;
   int lnode,rnode;
   for(i=1;i<2*n;i++)
      HT[i].parent=HT[i].lchild=HT[i].rchild=0;  //初始化
   for(i=n+1;i<2*n;i++){   //构造Huffman树
      m1=m2=0x7fff;        //m1取最小权重，m2取次小权重
      lnode=rnode=0;       //lnode,rnode分别取两个最小权重的结点位置
      for(k=1;k<i;k++)
      {   if(HT[k].parent==0)
           {
              if(HT[k].weight<m1){
                  m2=m1;  rnode=lnode;
                  //m1=________1_______; 
				  m1=HT[k].weight;
		  lnode=k;    
               }
              else if(HT[k].weight<m2){
                   m2=HT[k].weight;
                   //rnode=______2_______;           //2
				   rnode = k;
               }
            }
       }
     HT[lnode].parent=i;
     HT[rnode].parent=i;
     //HT[i].weight=________3______;      //3
     //HT[i].lchild=________4______;      //4
     //HT[i].rchild=________5______;      //5
	 HT[i].weight=m1+m2;
	 HT[i].lchild=lnode;
	 HT[i].rchild=rnode;
   }
}

void CreatHCode(HTNode *HT,HCode *hcd,int n)
{
    int i,f,c;
    HCode hc;
    for(i=1;i<=n;i++)
    {
       hc.start=n;
       c=i;
       f=HT[i].parent;
       while(f!=0){
           //if(____6__________)    //6   //c是f的左孩子，编码取'0',否则取'1'
		   if(HT[f].lchild==c)
               hc.cd[--hc.start]='0';
           else
               hc.cd[--hc.start]='1';
           c=f;                //向根结点方向搜索
           //f=______7________;    //7
		   f=HT[c].parent;
        }
        hcd[i]=hc;
     }
}

void PrintHCode(HTNode *HT,HCode *hcd,int n)
{
    int i,k;
    for(i=1;i<=n;i++)
    {
        printf(" %c: ",HT[i].data);
        //for(k=_______8________;k<n;++)     //8
		for(k=hcd[i].start;k<n;k++)
            printf("%c",hcd[i].cd[k]);
        printf("\n");
    }
}

void main()
{
    int i,n;
    HTNode HT[2*MAX-1];
    HCode hcd[MAX];
    printf("(1)创建Huffman 树………\n");
    do{
        printf(" 请输入元素个数(1-%d): ",MAX-1);
        scanf("%d",&n);
     }while(n<1||n>MAX-1);      //确保n值合规
    for(i=1;i<=n;i++){          //Huffman树结点存放在ht数组从1下标开始的位置
        fflush(stdin);
        printf("  第%d个元素的结点值==>",i);
        scanf("%c",&HT[i].data);
        printf("\t权重==>");
        scanf("%d",&HT[i].weight);
     }
    CreatHT(HT,n);
    printf("  Huffman树创建成功!\n");
    fflush(stdin);
    getchar();
    printf("(2)创建Huffman编码……\n");
    CreatHCode(HT,hcd,n);
    printf("  Huffman编码创建成功!\n");
    getchar();
    printf("(3)输出Huffman编码：\n");
    PrintHCode(HT,hcd,n);
}

