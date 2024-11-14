#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct comparator{
	bool operator() (const int& a, const int& b){
		return a > b;
	}
};

const int maxN = 200000;
vector<int> v(maxN);
vector<int> prevpos(maxN);
map<int,int> lastpos;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	for(int i=0; i<n; i++){
		cin>>v[i];
		prevpos[i] = -1;
	}
	for(int i=n-1; i>=0; i--){
		if(lastpos.find(v[i]) != lastpos.end())
		prevpos[lastpos[v[i]]] = i;
		lastpos[v[i]] = i;
	}

	priority_queue<int, vector<int>, comparator> pq;
	for(int i=0; i<n; i++)
	pq.push(i);
	
	int ans = 0;
	for(int i=0; i<n; i++){
		int reppos = n;
		while(!pq.empty()){
			reppos = pq.top();
			if(prevpos[reppos] < i){
				pq.pop();
				reppos = n;
			}
			else
			break;
		}
		ans = max(ans, reppos - i);
	}
	cout<<ans<<endl;
}