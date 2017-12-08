#include<stdio.h>
#define INF 32767
#define MAXE 100
#define MAXV 30
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
	int adjvex;
	int lowcost;
}cledge;
typedef struct{
	int u;
	int v;
	int w;
}Edge;
void CreateMG(MGraph &mg)
{
	int i,j;
	int A[7][7];
	mg.vexnum=7;
	mg.arcnum=9;
	for(i=0;i<mg.vexnum;i++)
		for(j=0;j<mg.vexnum;j++)
			A[i][j]=INF;
	A[0][1]=5;A[0][2]=4;A[0][6]=1;
	A[1][3]=13;
	A[2][3]=3;A[2][5]=8;A[2][6]=15;
	A[3][4]=2;
	A[5][6]=11;
	for(i=1;i<mg.vexnum;i++)
		for(j=0;j<i;j++)
			A[i][j]=A[j][i];
		for(i=0;i<mg.vexnum;i++)
			for(j=0;j<mg.vexnum;j++)
				mg.arcs[i][j]=A[i][j];
}
void OutputMG(MGraph mg)
{
	int i,j;
	for(i=0;i<mg.vexnum;i++)
	{
		for(j=0;j<mg.vexnum;j++)
			if(mg.arcs[i][j]==INF)
			printf(" 　∞");
			else
				printf("%4d",mg.arcs[i][j]);
		printf("\n");
	}
}
void Prim(MGraph G,int u)
{
	int i,j,k,min;
	cledge closedge[MAXV];
	for(j=0;j<G.vexnum;++j)
		if(j!=u)
		{
              closedge[j].adjvex=u;
			  closedge[j].lowcost=G.arcs[u][j];
		}
    closedge[u].lowcost=0;
	for(i=0;i<G.vexnum;++i)
	{
		min=INF;
		k=0;
        for(j=0;j<G.vexnum;j++)
			if(closedge[j].lowcost!=0&&closedge[j].lowcost<min)
			{
				min=closedge[j].lowcost;
				//k=____1____;
				k=j;
			}
			printf("  %d, (%d, %d): %d\n",k,closedge[k].adjvex,k,min);
			closedge[k].lowcost=0;
			for(j=0;j<G.vexnum;++j)
				if(G.arcs[k][j]<closedge[j].lowcost)
				{
					closedge[j].adjvex=k;
					//closedge[j].lowcost=____2____;
					closedge[j].lowcost=G.arcs[k][j];
				}
	}
}
void SortEdge(MGraph G,Edge E[])
{
	int i,j,k,c=0;
	for(i=0;i<G.vexnum;i++)
		for(j=i+1;j<G.vexnum;j++)
			if(G.arcs[i][j]<INF)
			{
				for(k=c-1;k>=0&&E[k].w>G.arcs[i][j];k--)
					E[k+1]=E[k];
				// E[k+1].u=____3_____;
				// E[k+1].v=____4_____;
				// E[k+1].w=____5_____;
				E[k+1].u=i;
				E[k+1].v=j;
				E[k+1].w=G.arcs[i][j];
				c++;
			}
}
void Kruskal(Edge E[],int n,int e)
{
	int i,j,k,m1,m2,sn1,sn2;
	int vset[MAXE];
	for(i=0;i<n;i++)
		vset[i]=i;
	k=1;
    j=0;
	while(k<n){
		m1=E[j].u;
		m2=E[j].v;
		sn1=vset[m1];
		sn2=vset[m2];
		if(sn1!=sn2)
		{
			printf("  (%d, %d): %d\n",m1,m2,E[j].w);
			k++;
			for(i=0;i<n;i++)
				if(vset[i]==sn2)
					vset[i]=sn1;
		}
		j++;
	}
}
int main()
{
	int u=0;
	MGraph mg;
	Edge E[MAXE];
	printf("(1)构造图的邻接矩阵.....\n");
	CreateMG(mg);
	printf("(2)当前图的邻接矩阵如下：\n");
	OutputMG(mg);
	getchar();
	printf("(3)普里姆（Prim） 算法求解结果如下：\n");
	Prim(mg,u);
	getchar();
	printf("(4)克鲁斯卡尔（Kruskal） 算法求解结果如下：\n");
	SortEdge(mg,E);
	Kruskal(E,mg.vexnum,mg.arcnum);
}
