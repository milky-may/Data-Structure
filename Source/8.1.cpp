#define MAXV 30
#include<stdio.h>
#include<malloc.h>
int visited[MAXV];
int queue[MAXV];
typedef int InfoType;
typedef struct{
	int no;
	InfoType info;
}VertexType;
typedef struct{
	VertexType vexs[MAXV];
	int arcs[MAXV][MAXV];
	int vexnum,arcnum;
}MGraph;
typedef struct ArcNode{
	int adjvex;
	int weight;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode{
	VertexType data;
    ArcNode *firstarc;
}VNode;
typedef struct{
	VNode vertices[MAXV];
	int vexnum,arcnum;
}LGraph;

void CreatMG(MGraph &mg)
{
	int i,j;
	int A[7][7];
	mg.vexnum=7;
	mg.arcnum=9;
	for(i=0;i<mg.vexnum;i++)
		for(j=0;j<mg.vexnum;j++)
			A[i][j]=0;
	A[0][1]=A[0][2]=A[0][6]=1;
	A[1][3]=1;
	A[2][3]=A[2][5]=A[2][6]=1;
	A[3][4]=1;
	A[5][6]=1;
	for(i=1;i<mg.vexnum;i++)
		for(j=0;j<i;j++)
			A[i][j]=A[j][i];
		for(i=0;i<mg.vexnum;i++)
			for(j=0;j<mg.vexnum;j++)
				mg.arcs[i][j]=A[i][j];
}

void CreatLG(LGraph *&lg,MGraph mg)
{
	int i,j;
	ArcNode *p;
	lg=(LGraph*)malloc(sizeof(LGraph));
	for(i=0;i<mg.vexnum;i++)
		lg->vertices[i].firstarc=NULL;
	for(i=0;i<mg.vexnum;i++)
		for(j=mg.vexnum-1;j>=0;j--)
			if(mg.arcs[i][j]!=0){
				p=(ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->weight=mg.arcs[i][j];
				p->nextarc=lg->vertices[i].firstarc;//修改
				lg->vertices[i].firstarc=p;
			}
			lg->vexnum=mg.vexnum;
			lg->arcnum=mg.arcnum;
}
void OutputMG(MGraph mg)
{
	int i,j;
	for(i=0;i<mg.vexnum;i++)
	{
		for(j=0;j<mg.vexnum;j++)
			printf("%3d",mg.arcs[i][j]);
		printf("\n");
	}
}
void OutputLG(LGraph *lg)
{
	int i;
	ArcNode *p;
	for(i=0;i<lg->vexnum;i++)
	{
		p=lg->vertices[i].firstarc;
		if(p) printf("%3d: ",i);
		while(p)
		{
			printf("%3d",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}
}
void LDFS(LGraph *lg,int i)
{
	ArcNode *p;
	printf("%3d",i);
	visited[i]=1;
	p=lg->vertices[i].firstarc;
	while(p){
		//if(___1____)
		if(visited[p->adjvex]==0)
			LDFS(lg,p->adjvex);
		//____2___;
		p=p->nextarc;
	}
}
void MDFS(MGraph mg,int i)
{
	int j;
	printf("%3d",i);
	visited[i]=1;
	for(j=0;j<mg.vexnum;j++){
		//if(___3___&&_____4____)
		if(mg.arcs[i][j]!=0 && visited[j]==0)
			MDFS(mg,j);
	}
}
void LBFS(LGraph *lg,int s){
	int i,v,w,front,rear;
	ArcNode *p;
	for(i=0;i<lg->vexnum;i++)
		visited[i]=0;
	front=rear=0;
	printf("%3d",s);
	visited[s]=1;
	//queue[____5____]=s;
	queue[rear++]=s;
	while(front<rear){
		//v=queue[____6_____];
		v=queue[front++];
		for(p=lg->vertices[v].firstarc;p!=NULL;p=p->nextarc){
			//w=____7____;
			w=p->adjvex;
			if(visited[w]==0){
				printf("%3d",w);
				visited[w]=1;
				//_____8_____=w;
				queue[rear++]=w;
			}
		}
	}
}
void MBFS(MGraph mg,int s)
{
	int i,j,v,front,rear;
	for(i=0;i<mg.vexnum;i++)
		visited[i]=0;
	front=rear=0;
	printf("%3d",s);
	visited[s]=1;
	queue[rear++]=s;
	//while(____9____)
	while(front<rear)
	{
		v=queue[front++];
		for(i=0;i<mg.vexnum;i++)
	        for(j=0;j<mg.vexnum;j++){
		        //if(___10___&&visited[j]==0)
				if(mg.arcs[i][j]==1 && visited[j]==0)
				{
                    printf("%3d",j);//改一哈
	                visited[j]=1;
					//____11_____=j;
					queue[rear++]=j;
				}
	}
	}
}
void main()
{
	LGraph *lg;
	MGraph mg;
	int i;
	CreatMG(mg);
	CreatLG(lg,mg);
	printf("(1) 当前图的邻接矩阵是：\n");
	OutputMG(mg);
    printf("(2) 当前图的邻接表是：\n");
	OutputLG(lg);
	for(i=0;i<mg.vexnum;i++)
		visited[i]=0;
	getchar();
    printf("(3) 邻接表表示的图的深度优先遍历序列是：\n");
	LDFS(lg,0);
	getchar();
	for(i=0;i<mg.vexnum;i++)
		visited[i]=0;
    printf("(4) 邻接矩阵表示的图的深度优先遍历序列是：\n");
	MDFS(mg,0);
	getchar();
    printf("(5) 邻接表表示的图的广度优先遍历序列是：\n");
	LBFS(lg,0);
	getchar();
    printf("(6) 邻接矩阵表示的图的广度优先遍历序列是：\n");
	MBFS(mg,0);
	printf("\n");
}
