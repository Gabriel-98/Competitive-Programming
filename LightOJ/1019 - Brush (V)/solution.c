#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXV 10005
#define INFINITE 2147483647
#define NIL -1
#define TRUE 1
#define FALSE 0

int heapSize=0;

struct edge{
	int vertex;
	int weight;
	struct edge *next;
};

typedef struct{
	struct edge *edges[MAXV+1];
	int nVertex;
	int nEdges;
}graph;

graph G;

int myMax(int x, int y){
	int maximum= x;
	if(y>maximum)
	maximum= y;
	
	return(maximum);
}

struct nodoPQ{
	int vertex;
	int distance;
};

int Left(int i){
	return(2*i);
}

int Right(int i){
	return((2*i)+1);
}

int Parent(int i){
	return(i/2);
}

void minHeapify(struct nodoPQ A[], int i, int PositionVertex[]){
	int L,R,little,positionTemp;
	L= Left(i);
	R= Right(i);
	struct nodoPQ nodoTemp;
	if(L<=heapSize && (A[L].distance < A[i].distance))
	little= L;
	else
	little= i;
	
	if(R<=heapSize && (A[R].distance < A[little].distance))
	little= R;
	if(little!=i){
		positionTemp= PositionVertex[A[i].vertex];
		nodoTemp= A[i];
		PositionVertex[A[i].vertex]= PositionVertex[A[little].vertex];
		A[i]= A[little];
		PositionVertex[A[little].vertex]= positionTemp;
		A[little]= nodoTemp;
		minHeapify(A,little,PositionVertex);
	}
}

int ExtractMinPQ(struct nodoPQ A[], int PositionVertex[]){
	int min=0;
	if(heapSize>=1){
		min= A[1].vertex;
		PositionVertex[A[heapSize].vertex]= 1;
		A[1]= A[heapSize];
		heapSize--;
		minHeapify(A,1,PositionVertex);
	}
	return(min);
}

void DecreaseKey(struct nodoPQ A[], int i, int key, int PositionVertex[]){
	int positionTemp;
	struct nodoPQ nodoTemp;
	if(key <= A[i].distance){
		A[i].distance= key;
		while(i>1 &&  (A[Parent(i)].distance > A[i].distance)){
			positionTemp = PositionVertex[A[i].vertex];
			nodoTemp= A[i];
			PositionVertex[A[i].vertex]= PositionVertex[A[Parent(i)].vertex];
			A[i]= A[Parent(i)];
			PositionVertex[A[Parent(i)].vertex]= positionTemp;
			A[Parent(i)]= nodoTemp;
			i= Parent(i);
		}
	}
}

void MinInsertPQ(struct nodoPQ A[], int key, int vertex, int PositionVertex[]){
	heapSize++;
	A[heapSize].distance= INFINITE;
	A[heapSize].vertex= vertex;
	PositionVertex[vertex]= heapSize;
	DecreaseKey(A, heapSize,key,PositionVertex);
}

void DIJKSTRA(int s, int P[], int d[]){
	int idVertex,u,v,weight;
	struct nodoPQ A[MAXV+1];
	int PositionVertex[MAXV+1];
	int inQueuePQ[MAXV+1];
	struct edge *tempEdge;
	heapSize= 0;
	for(idVertex=1; idVertex<=G.nVertex; idVertex++){
		P[idVertex]= NIL;
		inQueuePQ[idVertex]= TRUE;
		if(idVertex==s){
			MinInsertPQ(A,0,idVertex,PositionVertex);
			d[idVertex]= 0;
		}
		else{
			MinInsertPQ(A,INFINITE,idVertex,PositionVertex);
			d[idVertex]= INFINITE;
		}
	}
	while(heapSize>=1){
		u= ExtractMinPQ(A,PositionVertex);
		inQueuePQ[u]= FALSE;
		tempEdge= G.edges[u];
		if(d[u]==INFINITE)
		break;
		
		while(tempEdge!=NULL){
			v= tempEdge->vertex;
			weight= tempEdge->weight;
			if(inQueuePQ[v]==TRUE &&  d[v] > (d[u] + weight)){
				d[v]= d[u] + weight;
				P[v]= u;
				DecreaseKey(A, PositionVertex[v], d[v], PositionVertex);
			}
			tempEdge= tempEdge->next;		
		}
	}
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

void InsertNodo(int vertex1, int vertex2, int weight){
	struct edge *NewNodo;
	NewNodo= (struct edge*)malloc(sizeof(struct edge));
	NewNodo->weight= weight;
	NewNodo->vertex= vertex1;
	NewNodo->next= G.edges[vertex2];
	G.edges[vertex2]= NewNodo;
	//..................................................
	NewNodo= (struct edge*)malloc(sizeof(struct edge));
	NewNodo->weight= weight;
	NewNodo->vertex= vertex2;
	NewNodo->next= G.edges[vertex1];
	G.edges[vertex1]= NewNodo;
}

int main(){
	int t,l;
	int TotalVertex, TotalEdges, idVertex, idEdge, vertex1, vertex2, weight, min;
	scanf("%d", &t);
	for(l=1; l<=t; l++){
		scanf("%d %d", &TotalVertex, &TotalEdges);
		G.nVertex= TotalVertex;
		G.nEdges= TotalEdges;
		int P[G.nVertex+1];
		int D[G.nVertex+1];
		for(idVertex=1; idVertex<=G.nVertex; idVertex++){
			G.edges[idVertex]= NULL;
		}
		for(idEdge=1; idEdge<=G.nEdges; idEdge++){
			scanf("%d %d %d", &vertex1, &vertex2, &weight);
			InsertNodo(vertex1,vertex2,weight);
		}
		DIJKSTRA(1,P,D);
		min= D[G.nVertex];
		FreeMemoryGraph();
		printf("Case %d: ", l);
		if(min==INFINITE)
		printf("Impossible\n");
		else
		printf("%d\n", min);
	}
}
