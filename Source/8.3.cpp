#include<stdio.h>
#define INF 32767
#define MAXV 30
#define OK 1
#define ERROR 0
typedef int Status;
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
typedef struct{
	int st[MAXV];
	int top;
}Stack;
typedef struct{
	int queue[MAXV];
	int front,rear;
}Queue;
void CreateMG(MGraph &G)
{
	int i,j;
	int A[9][9];
	G.vexnum=9;
	G.arcnum=11;
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			A[i][j]=INF;
	A[0][1]=6;A[0][2]=4;A[0][3]=5;
	A[1][4]=1;
	A[2][4]=1;A[3][5]=2;A[4][6]=9;
	A[4][7]=7;
	A[5][7]=4;
	A[6][8]=2;
	A[7][8]=4;
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=A[i][j];
		for(i=0;i<G.vexnum;i++)
			for(j=0;j<G.vexnum;j++)
				G.arcs[i][j]=A[i][j];
}
void OutputMG(MGraph G)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
			if(G.arc[i][j]==INF)
			printf(" 　∞");
			else
				printf("%4d",G.arcs[i][j]);
		printf("\n");
	}
}
Status ToplogicalOrder(MGraph G,Stack &S,int *ve){
	int i,j,count=0;
	Queue Q;
	Q.front=Q.rear=0;
	int Indegree[MAXV];
	for(i=0;i<G.vexnum;i++)
		Indegree[i]=0;
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			if(G.arcs[i][j]<INF)
				____1___;
			for(i=0;i<G.vexnum;i++)
				ve[i]=0;
			for(i=0;i<G.vexnum;i++)
				if(Indegree[i]==0)
					Q.queue[Q.rear++]=i;
				while(_____2____){
                    i=Q.queue[Q.front++];
					S.st[S.top++]=i;
					count++;
					for(j=0;j<G.vexnum;j++)
						if(G.arcs[i][j]<INF){
							Indegree[j]--;
						if(Indegree[j]==0)
							Q.queue[Q.rear++]=___3__;
						if(ve[i]+G.arcs[i][j]>ve[j])
							ve[j]=ve[i]+G.arcs[i][j];
						}
				}
				if(___4____)
					return ERROR;
				return OK;
}
int Criticalpath(MGraph G){
	int i,k,e,l;
	char tag;
	Stack S;
	int ve[MAXV],vl[MAXV];
	S.top=0;
	if(!ToplogicalOrder(G,S,ve))
		return 0;
	for(j=0;j<G.vexnum;j++)
		vl[j]=ve[G.vexnum-1];
	while(___5___){
		j=S.st[--S.top];
		for(k=0;k<G.vexnum;k++)
			if(___6____)
				if(vl[k]-G.arcs[j][k]<vl[j])
					vl[j]=vl[k]-G.arcs[j][k];
	}
	printf(" (活动)持续时间，最早开始时间，最晚开始时间，关键标志\n");
	for(j=0;j<G.vexnum;++j)
		for(k=0;k<G.vexnum;k++)
			if(____7___){
				e=ve[j];
				l=____8____;
				tag=(e==l)?'*':' ';
			    printf("(%d,%d)%5d\t\t%d\t    %d\t\t%c\n",j,k,G.arcs[j][k],e,l,tag);
			}
			return 1;
}
void main()
{
	MGraph G;
	printf("(1)构造图的邻接矩阵....\n");
	CreateMG(G);
	printf("(2)当前图的邻接矩阵如下：\n");
	OutputMG(G);
	getchar();
	printf("(3)AOE网的关键路径求解结果如下：\n");
	Criticalpath(G);
}
