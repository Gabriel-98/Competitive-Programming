#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxN = 500;
int ans[maxN+1][maxN+1];

vector<vector<int>> FindPermutationCycles(vector<int>& perm){
	vector<vector<int>> cycles;
	vector<bool> S(perm.size(), false);
	for(int i=1; i<perm.size(); i++){
		if(!S[i]){
			vector<int> cycle;
			int x = i;
			while(!S[x]){
				S[x] = true;
				cycle.push_back(x);
				x = perm[x];
			}
			cycles.push_back(cycle);
		}
	}
	return cycles;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n, t; cin>>n>>t;
	vector<int> rows(n+1), cols(n+1);
	for(int i=1; i<=n; i++)
	rows[i] = cols[i] = i;
	for(int i=0; i<t; i++){
		char c; int id1, id2;
		cin>>c>>id1>>id2;
		if(c == 'R') swap(rows[id1], rows[id2]);
		else swap(cols[id1], cols[id2]);
	}
	vector<vector<int>> rowcycles, colcycles;
	rowcycles = FindPermutationCycles(rows);
	colcycles = FindPermutationCycles(cols);

	// Test all cycles, both for rows and cols, all have the same size.
	bool cond = true;
	int cycleSize = rowcycles[0].size();
	if(rowcycles.size() != colcycles.size())
	cond = false;
	for(int i=0; i<rowcycles.size() && cond; i++){
		if(rowcycles[i].size() != cycleSize || colcycles[i].size() != cycleSize)
		cond = false;
	}

	// Generate the latin square.
	if(cond){
		for(int id1=0; id1<rowcycles.size(); id1++){
			for(int id2=0; id2<colcycles.size(); id2++){
				int base = (((rowcycles.size()) + id2 - id1) % rowcycles.size()) * cycleSize;
				for(int p1=0; p1<cycleSize; p1++){
					for(int p2=0; p2<cycleSize; p2++){
						int value = base + ((cycleSize + p2 - p1) % cycleSize) + 1;
						int i = rowcycles[id1][p1];
						int j = colcycles[id2][p2];
						ans[i][j] = value;
					}
				}
			}
		}
	}

	// Print answer.
	if(cond){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++)
			cout<<((j > 1) ? " " : "")<<ans[i][j];
			cout<<endl;
		}
	}
	else
	cout<<"*"<<endl;
}