#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<int,int> pii;

struct Movie{
	int l, r;
	Movie() : l(0), r(0) {}
	Movie(int _l, int _r) : l(_l), r(_r) {}
};

struct comparator{
	bool operator() (const pii& a, const pii& b){
		return a.first > b.first;
	}
};

bool sortMovieByLAsc(const Movie& a, const Movie& b){ return a.l < b.l; }

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	vector<Movie> movies(n);
	for(int i=0; i<n; i++)
	cin>>movies[i].l>>movies[i].r;
	sort(movies.begin(), movies.begin()+n, sortMovieByLAsc);

	priority_queue<pii, vector<pii>, comparator> pq;
	int ans = 0;
	for(int i=0; i<n; i++){
		while(!pq.empty() && pq.top().first <= movies[i].l){
			ans = max(ans, pq.top().second);
			pq.pop();
		}
		int aux = ans + 1;
		pq.push(pii(movies[i].r, aux));
	}
	while(!pq.empty()){
		ans = max(ans, pq.top().second);
		pq.pop();
	}
	cout<<ans<<endl;
}