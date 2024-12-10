#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define inf 3000
 
const int maxNodos = 2000;
int numeroNodos;
vector<int> Grafo[maxNodos];
vector<int> S(maxNodos);
int cont = 0;
 
int bfs(int s){
	int x,y,i;
	queue<int> Q;
	vector<int> dist(numeroNodos);
	for(i=0; i<numeroNodos; i++){
		S[i] = 0;
		dist[i] = inf;
	}
	Q.push(s);
	while(!Q.empty()){
		x = Q.front();
		Q.pop();
		for(i=0; i<Grafo[x].size(); i++){
			y = Grafo[x][i];
 
			if(S[y] == 0){
				if(x == s){
					dist[y] = 1;
					Q.push(y);
				}
				else if(dist[x] + 1 < dist[y]){
					dist[y] = dist[x] + 1;
					Q.push(y);
				}
				S[y] = 1;
				if(y == s)
				return dist[y];
			}
		}
	}
	return inf;
}
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,w,ans,i,j;
	cin>>n;
	numeroNodos = n;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cin>>w;
			if(w == 1)
			Grafo[i].push_back(j);
		}
	}
	for(i=0; i<n; i++){
		ans = bfs(i);
		if(ans == inf)
		cout<<"NO WAY"<<endl;
		else
		cout<<ans<<endl;
	}
}
