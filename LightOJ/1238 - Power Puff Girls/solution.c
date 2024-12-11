#include<stdio.h>
#include<stdlib.h>
#define WHITE 2
#define BLACK 0
#define GRAY 1
#define NIL -1
#define MAXV 30000
#define INFINITE 2147483647

char Mapa[20][20];

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

struct nodo *Enqueue(struct nodo *Q, int y0, int x0);
struct nodo *Dequeue(struct nodo *Q);
void FreeMemoryGraph();
void BFS(int s, int phi[], int d[]);
void InsertNodo(int vertex1, int vertex2);
struct nodo *InsertBox(struct nodo *Q, int p1, int p2, int y, int x, int y0, int x0);

int main(){
	int TotalVertex, idVertex;
	int a,b,c,posh,pos1,pos2,pos3,t,x,y,x0,y0,p1,p2,l,i,j;
	struct nodo *Q;
	Q= (struct nodo*)malloc(sizeof(struct nodo));
	scanf("%d", &t);
	for(l=1; l<=t; l++){
		scanf("%d %d", &y, &x);
		for(i=0; i<y; i++){
			scanf("%s", &Mapa[i]);
		}
		TotalVertex= x*y;
		G.nVertex= TotalVertex;
		int phi[G.nVertex];
		int d[G.nVertex];
		for(idVertex=0; idVertex<G.nVertex; idVertex++){
			G.edges[idVertex]= NULL;
		}
		Q= NULL;
		for(i=0; i<y; i++){
			for(j=0; j<x; j++){
				if(Mapa[i][j]=='a'){
					x0=j;
					y0=i;
					break;
				}
			}
			if(j<x)
			break;
		}
		pos1= (y0*x)+x0;
		for(i=0; i<y; i++){
			for(j=0; j<x; j++){
				if(Mapa[i][j]=='b'){
					x0=j;
					y0=i;
					break;
				}
			}
			if(j<x)
			break;
		}
		pos2= (y0*x)+x0;
		for(i=0; i<y; i++){
			for(j=0; j<x; j++){
				if(Mapa[i][j]=='c'){
					x0=j;
					y0=i;
					break;
				}
			}
			if(j<x)
			break;
		}
		pos3= (y0*x)+x0;
		for(i=0; i<y; i++){
			for(j=0; j<x; j++){
				if(Mapa[i][j]=='h'){
					x0=j;
					y0=i;
					break;
				}
			}
			if(j<x)
			break;
		}
		posh= (y0*x)+x0;
		Q= Enqueue(Q, y0,x0);
		Mapa[y0][x0]= '#';
		while(Q!=NULL){
			y0= Q->sig->y0;
			x0= Q->sig->x0;
			p1= (y0*x)+x0;
			if(x0+1 < x)
			Q= InsertBox(Q, p1,p2, y,x, y0,x0+1);
			if(x0-1 >= 0)
			Q= InsertBox(Q, p1,p2, y,x, y0,x0-1);
			if(y0+1 < y)
			Q= InsertBox(Q, p1,p2, y,x, y0+1,x0);
			if(y0-1 >= 0)
			Q= InsertBox(Q, p1,p2, y,x, y0-1,x0);
			
			Q= Dequeue(Q);
		}
		BFS(posh,phi,d);
		a= d[pos1];
		b= d[pos2];
		c= d[pos3];
		FreeMemoryGraph();
		a= (a+b+abs(a-b))/2;
		a= (a+c+abs(a-c))/2;
		printf("Case %d: %d\n", l, a);
	}
}

struct nodo *Enqueue(struct nodo *Q, int y0, int x0){
	struct nodo *p;
	p= (struct nodo*)malloc(sizeof(struct nodo));
	p->x0= x0;
	p->y0= y0;
	if(Q==NULL)
	p->sig= p;
	else{
		p->sig= Q->sig;
		Q->sig= p;
	}
	Q= p;
	return(Q);
}

struct nodo *Dequeue(struct nodo *Q){
	struct nodo *temp;
	temp= Q->sig;
			
	if(Q== Q->sig)
	Q= NULL;
	else
	Q->sig= Q->sig->sig;
		
	free(temp);
	return(Q);
}

struct nodo *InsertBox(struct nodo *Q, int p1, int p2, int y, int x, int y0, int x0){
	if(Mapa[y0][x0]!='#' && Mapa[y0][x0]!='m'){
		Mapa[y0][x0]= '#';
		Q= Enqueue(Q, y0,x0);
		p2= (y0*x)+x0;
		InsertNodo(p1,p2);
	}
	return (Q);
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

void BFS(int s, int phi[], int d[]){
	int idVertex, u, v;
	int color[G.nVertex+1];
	int Q[G.nVertex+1];
	int headQueue=1, tailQueue=1;
	struct edge *tempEdge;
	
	for(idVertex=0; idVertex<G.nVertex; idVertex++){
		color[idVertex]= WHITE;
		d[idVertex]= INFINITE;
		phi[idVertex]= NIL;
	}
	color[s]= GRAY;
	d[s]= 0;
	phi[s]= NIL;
	
	Q[tailQueue]= s;
	tailQueue++;
	
	while(headQueue != tailQueue){
		u= Q[headQueue];
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
}
