#include<stdio.h>
#include<stdlib.h>
#define WHITE 2
#define BLACK 0
#define GRAY 1
#define NIL -1
#define MAXV 20005
#define INFINITE 2147483647

int V[MAXV];

struct nodo{
	int x0;
	int y0;
	struct nodo *sig;
};

struct edge{
	int v;
	struct edge *next;
};

typedef struct{
	struct edge *edges[MAXV+1];
	int nVertex;
	int nEdges;
}graph;

graph G;

void FreeMemoryGraph();
int BFS(int s, int phi[], int d[]);
void InsertNodo(int vertex1, int vertex2);

int main(){
	int TotalVertex, idVertex;
	int t,n,x,y,l,i,acu,k;
	struct nodo *Q;
	Q= (struct nodo*)malloc(sizeof(struct nodo));
	scanf("%d", &t);
	for(l=1; l<=t; l++){
		scanf("%d", &n);
		TotalVertex= 20000;
		
		G.nVertex= TotalVertex+1;
		int phi[G.nVertex+1];
		int d[G.nVertex+1];
		for(idVertex=1; idVertex<=G.nVertex; idVertex++){
			G.edges[idVertex]= NULL;
		}
		for(i=0; i<n; i++){
			scanf("%d %d", &x, &y);
			InsertNodo(x,y);
		}
		Q= NULL;
		for(idVertex=1; idVertex<=G.nVertex; idVertex++){
			V[idVertex]= -1;
		}
		acu=0;
		for(idVertex=1; idVertex<=G.nVertex; idVertex++){
			if(V[idVertex]==-1 && G.edges[idVertex]!=NULL){
				k=BFS(idVertex,phi,d);
				acu+= k;
			}			
		}
		printf("Case %d: %d\n",l,acu);
		FreeMemoryGraph();
	}
}

void InsertNodo(int vertex1, int vertex2){
	struct edge *NewNodo;
	NewNodo=(struct edge*)malloc(sizeof(struct edge));
	NewNodo->v=vertex1;
	NewNodo->next=G.edges[vertex2];
	G.edges[vertex2]=NewNodo;
	//................................................
	NewNodo=(struct edge*)malloc(sizeof(struct edge));
	NewNodo->v=vertex2;
	NewNodo->next=G.edges[vertex1];
	G.edges[vertex1]= NewNodo;
}

void FreeMemoryGraph(){
	int idVertex;
	struct edge *temp1, *temp2;
	for(idVertex=1; idVertex<=G.nVertex; idVertex++){
		temp1= G.edges[idVertex];
		while(temp1!=NULL){
			temp2= temp1->next;
			free(temp1);
			temp1= temp2;
		}
		G.edges[idVertex]= NULL;
	}
}

int BFS(int s, int phi[], int d[]){
	int idVertex, u, v, g1, g2, k;
	int color[G.nVertex+1];
	int Q[G.nVertex+1];
	int headQueue=1, tailQueue=1;
	struct edge *tempEdge;
	g1=0;g2=0;k=0;
	for(idVertex=1; idVertex<=G.nVertex; idVertex++){
		color[idVertex]= WHITE;
		d[idVertex]= INFINITE;
		phi[idVertex]= NIL;
	}
	color[s]= GRAY;
	d[s]= 0;
	phi[s]= NIL;
	V[s]= 0;
	
	Q[tailQueue]= s;
	tailQueue++;
	
	while(headQueue != tailQueue){
		u= Q[headQueue];
		V[u]= d[u]%2;
		if(V[u]==0)
		g1+= 1;
		else
		g2+=1;
		
		headQueue++;
		tempEdge= G.edges[u];
		while(tempEdge!=NULL){
			v= tempEdge->v;
			if(color[v]==WHITE){
				color[v]= GRAY;
				d[v]= d[u]+1;
				phi[v]= u;
				Q[tailQueue]= v;
				tailQueue++;
			}
			tempEdge= tempEdge->next;
		}
		color[u]= BLACK;
	}
	k= (g1+g2+abs(g1-g2))/2;
	return(k);
}
