#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define inf 1e9

const int maxNodes = 4100;
vector<int> graph[maxNodes];
int residual[maxNodes][maxNodes];

int FindAugmentingPath(int n, int s, int t, bool unit){
	queue<int> Q;
	vector<int> S(n,0), P(n,-1), flow(n, 0);
	Q.push(s);
	S[s] = 1;
	flow[s] = inf;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		for(int i=0; i<graph[x].size(); i++){
			int y = graph[x][i];
			if(residual[x][y] > 0 && S[y] == 0){
				Q.push(y);
				S[y] = 1;
				P[y] = x;
				flow[y] = min(flow[x], residual[x][y]);
			}
		}
	}
	if(flow[t] > 0){
		int f = unit ? 1 : flow[t];
		int x = t;
		while(x != s){
			int p = P[x];
			residual[p][x] -= f;
			residual[x][p] += f;
			x = p;
		}
		return f;
	}
	return 0;
}

int MaxFlow(int n, int s, int t){
	int flow = 0;
	for(int f; f = FindAugmentingPath(n,s,t,false); )
	flow += f;
	return flow;
}

const int maxN = 1000;
int table[maxN+1][maxN+1];
vector<int> cliques[maxN+1]; // cliques[x]: Specifies the 2 cliques connected to x.

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	for(int i=1; i<=n; i++){
		string s; cin>>s;
		for(int j=1; j<=n; j++)
		table[i][j] = s[j-1] - '0';
	}

	// Determines the cliques associated to each node.
	// - Iterate for each edge (x,y) and for each node z that is connected
	//   to both x and y, that node z allows to the same clique where is that edge.
	// - [Optimization] As all pair nodes in the clique found are connected, and
	//   that edges does not belong to other cliques, all edges in the clique are
	//   deleted.
	int idclique = 0;
	for(int x=1; x<=n; x++){
		for(int y=1; y<=n; y++){
			if(table[x][y] == 1){ // x != y (it's guaranteed)
				vector<int> nodes = {x, y};
				for(int z=1; z<=n; z++){
					if(table[z][x] == 1 && table[z][y] == 1)
					nodes.push_back(z);
				}
				idclique++;
				for(int l1=0; l1<nodes.size(); l1++){
					int u = nodes[l1];
					cliques[u].push_back(idclique);
					for(int l2=0; l2<nodes.size(); l2++){
						int v = nodes[l2];
						table[u][v] = 0;
					}
				}
			}
		}
	}

	// For each node, add new cliques to that is connected to 2 cliques.
	for(int x=1; x<=n; x++){
		while(cliques[x].size() < 2)
		cliques[x].push_back(++idclique);
	}

	// Build the flow net to solve the maximum bipartite matching problem.
	int cn = idclique;
	int totalNodes = 2*cn + 2;
	for(int i=0; i<totalNodes; i++){
		for(int j=0; j<totalNodes; j++)
		residual[i][j] = 0;
	}
	for(int i=1; i<=cn; i++)
	residual[0][i] = 1;
	for(int i=1; i<=n; i++){
		int id1 = cliques[i][0], id2 = cliques[i][1];
		residual[id1][cn+id2] = 1;
		residual[id2][cn+id1] = 1;
	}
	for(int i=1; i<=cn; i++)
	residual[cn+i][2*cn+1] = 1;
	
	// Create graph with adjacency lists for optimize the max flow algorithm
	// on not dense graphs.
	for(int x=0; x<totalNodes; x++){
		for(int y=x+1; y<totalNodes; y++){
			if(residual[x][y] > 0 || residual[y][x] > 0){
				graph[x].push_back(y);
				graph[y].push_back(x);
			}
		}
	}

	// Run the max flow algorithm.
	int ans = MaxFlow(totalNodes, 0, totalNodes-1);
	ans /= 2;
	cout<<ans<<endl;
}