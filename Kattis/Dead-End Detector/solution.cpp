#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<int,int> par;

struct arista{
	int x,y;
};

int sortAristaAscendente(struct arista A, struct arista B){
	if(A.x < B.x)
	return 1;
	else if(B.x < A.x)
	return 0;
	else
	return A.y < B.y;
}

const int maxNodos = 501000;
int numeroNodos = 0;
set<int> Grafo[maxNodos + 1];
vector<int> S(maxNodos + 1);
set<int> pendientesBorrar[maxNodos+1];
vector<int> borrar;
vector<struct arista> ans;

void BFS_eliminarST(){
	int x,y,cont,cond,i,j;
	set<int>::iterator it,it2;
	queue<int> Q;
	for(i=1; i<=numeroNodos; i++){
		S[i] = 0;
	}
	for(i=1; i<=numeroNodos; i++){
		if(S[i] == 0){
			S[i] = i;
			Q.push(i);
			borrar.push_back(i);
			cond = 0;
			while(!Q.empty()){
				x = Q.front();
				Q.pop();
				cont = 0;
				for(it=Grafo[x].begin(); it!=Grafo[x].end(); it++){
					y = *it;
					if(S[y] == 0){
						Q.push(y);
						S[y] = i;
						borrar.push_back(y);
					}
					else
					cont++;
				}
				if(cont >= 2)
				cond = 1;
			}
			if(cond == 0){
				for(j=0; j<borrar.size(); j++){
					x = borrar[j];
					for(it=Grafo[x].begin(); it!=Grafo[x].end(); it++){
						y = *it;
						struct arista A;
						A.x = x;	A.y = y;

						if(Grafo[x].size() == 1)
						ans.push_back(A);
					}
				}
				for(j=0; j<borrar.size(); j++){
					x = borrar[j];
					for(it=Grafo[x].begin(); it!=Grafo[x].end(); it++){
						y = *it;
						it2 = Grafo[y].find(x);
						Grafo[y].erase(it2);
					}
					Grafo[x].clear();
				}
			}
			borrar.clear();
		}
	}
}

void BFS(){
	int x,y,cont=0,i,j;
	set<int>::iterator it,it2;
	queue<par> Q;
	for(i=1; i<=numeroNodos; i++){
		if(Grafo[i].size() == 1)
		Q.push(par(0,i));
	}
	while(!Q.empty()){
		x = Q.front().first;
		x = Q.front().second;
		Q.pop();
		for(it=pendientesBorrar[x].begin(); it!=pendientesBorrar[x].end(); it++){
			y = *it;
			borrar.push_back(y);
			pendientesBorrar[y].clear();
		}

		for(i=0; i<borrar.size(); i++){
			it = pendientesBorrar[x].find(borrar[i]);
			pendientesBorrar[x].erase(it);
		}

		borrar.clear();
		for(it=Grafo[x].begin(); it!=Grafo[x].end(); it++){
			y = *it;
			it2 = Grafo[y].find(x);
			Grafo[y].erase(it2);
			pendientesBorrar[y].insert(x);
			if(Grafo[y].size() == 1)
			Q.push(par(x,y));
		}
		Grafo[x].clear();
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m,x,y,i,j;
	set<int>::iterator it;
	cin>>n>>m;
	numeroNodos = n;
	for(i=0; i<m; i++){
		cin>>x>>y;
		Grafo[x].insert(y);
		Grafo[y].insert(x);
	}
	BFS_eliminarST();
	BFS();
	for(i=1; i<=n; i++){
		for(it=pendientesBorrar[i].begin(); it!=pendientesBorrar[i].end(); it++){
			struct arista A;
			A.x = i;	A.y = *it;
			ans.push_back(A);
		}
	}
	sort(ans.begin(), ans.end(), sortAristaAscendente);
	cout<<ans.size()<<endl;
	for(i=0; i<ans.size(); i++){
		cout<<ans[i].x<<" "<<ans[i].y<<endl;
	}
}