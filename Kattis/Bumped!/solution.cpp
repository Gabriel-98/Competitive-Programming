#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<long long,long long> par;
#define NIL -1
long long INF=10000000000000;

const int MaxNodos=1000000;
list<pair<long long,long long>> Grafo[MaxNodos];			// Grafo[vertex1] = (vertex2, weight)
vector<long long> P(MaxNodos), D(MaxNodos), S(MaxNodos), F(MaxNodos);

void DIJKSTRA(long long n, long long s){
	long long x,y,w,k,i;
	list<pair<long long,long long>>::iterator it;
	for(i=0; i<n; i++){
		P[i]= NIL;
		D[i]= INF;
		S[i]= 0;
		F[i]= 0;
	}
	S[s]= 1;
	D[s]= 0;
	priority_queue<pair<long long,long long>> Q;
	Q.push(par(0,s));
	while(!Q.empty()){
		x= Q.top().second;
		Q.pop();
		S[x]= 1;
		it= Grafo[x].begin();
		while(it!=Grafo[x].end()){
			y= it->first;
			w= it->second;
			k=0;
			if(w==0)
			k=1;
			if(S[y]==0 && D[y]>D[x]+w && F[x]+k<=1){
				D[y]= D[x]+w;
				P[y]= x;
				F[y]= F[x]+k;
				Q.push(par(D[y]*(-1), y));
			}
			it++;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	long long n,m,k,s,f,x,y,w,i;
	cin>>n>>m>>k>>s>>f;
	for(i=0; i<m; i++){
		cin>>x>>y>>w;
		Grafo[x].push_back(par(y,w));
		Grafo[y].push_back(par(x,w));
	}
	for(i=0; i<k; i++){
		cin>>x>>y;
		Grafo[x].push_back(par(y,0));
	}
	DIJKSTRA(n,s);
	cout<<D[f]<<endl;
}