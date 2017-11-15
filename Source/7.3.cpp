#include<stdio.h>
#define MAX 21
typedef struct{            //����Huffman�����ṹ
   char data;              //���ֵ
   int weight;             //Ȩ��
   int parent;             //�����
   int lchild;             //����
   int rchild;             //�Һ���
}HTNode;
typedef struct{             //����Huffman����ṹ
   char cd[MAX];
   int start;
}HCode;

void CreatHT(HTNode *HT,int n)
{
   int i,k,l,r;
   int m1,m2;
   int lnode,rnode;
   for(i=1;i<2*n;i++)
      HT[i].parent=HT[i].lchild=HT[i].rchild=0;  //��ʼ��
   for(i=n+1;i<2*n;i++){   //����Huffman��
      m1=m2=0x7fff;        //m1ȡ��СȨ�أ�m2ȡ��СȨ��
      lnode=rnode=0;       //lnode,rnode�ֱ�ȡ������СȨ�صĽ��λ��
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
           //if(____6__________)    //6   //c��f�����ӣ�����ȡ'0',����ȡ'1'
		   if(HT[f].lchild==c)
               hc.cd[--hc.start]='0';
           else
               hc.cd[--hc.start]='1';
           c=f;                //�����㷽������
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
    printf("(1)����Huffman ��������\n");
    do{
        printf(" ������Ԫ�ظ���(1-%d): ",MAX-1);
        scanf("%d",&n);
     }while(n<1||n>MAX-1);      //ȷ��nֵ�Ϲ�
    for(i=1;i<=n;i++){          //Huffman���������ht�����1�±꿪ʼ��λ��
        fflush(stdin);
        printf("  ��%d��Ԫ�صĽ��ֵ==>",i);
        scanf("%c",&HT[i].data);
        printf("\tȨ��==>");
        scanf("%d",&HT[i].weight);
     }
    CreatHT(HT,n);
    printf("  Huffman�������ɹ�!\n");
    fflush(stdin);
    getchar();
    printf("(2)����Huffman���롭��\n");
    CreatHCode(HT,hcd,n);
    printf("  Huffman���봴���ɹ�!\n");
    getchar();
    printf("(3)���Huffman���룺\n");
    PrintHCode(HT,hcd,n);
}

