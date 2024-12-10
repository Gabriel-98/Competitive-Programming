#include<bits/stdc++.h>
using namespace std;
#define nedl '\n'

const int maxNodos = 110;
int numeroNodos;
vector<int> Grafo[maxNodos];
vector<int> S(maxNodos), first(maxNodos), lider(maxNodos);
stack<int> pila;
int tiempo;

void scc_visit(int x){
	S[x] = 1;
	first[x] = tiempo;
	lider[x] = tiempo;
	pila.push(x);
	tiempo++;
	for(int i=0; i<Grafo[x].size(); i++){
		int y = Grafo[x][i];
		if(first[y] == -1)
		scc_visit(y);	
		if(S[y] == 1)
		lider[x] = min(lider[x], lider[y]);
	}

	if(first[x] == lider[x]){
		int y = -1;
		while(y != x){
			y = pila.top();	pila.pop();
			S[y] = 0;
		}
	}
}

void scc(){
	tiempo = 0;
	for(int x=0; x<numeroNodos; x++){
		S[x] = 0;
		first[x] = -1;
	}
	for(int x=0; x<numeroNodos; x++){
		if(first[x] == -1)
		scc_visit(x);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t,n,x,y,ans;
	string cad;
	cin>>t;
	while(t--){
		cin>>n;
		numeroNodos = n;
		for(x=0; x<n; x++){
			cin>>cad;
			for(y=0; y<n; y++){
				if(cad[y] == 'Y')
				Grafo[x].push_back(y);
			}
		}
		scc();
		ans = 0;
		for(x=0; x<n; x++){
			if(first[x] == lider[x])
			ans++;
		}
		cout<<ans<<endl;

		for(x=0; x<n; x++)
		Grafo[x].clear();
	}
}
