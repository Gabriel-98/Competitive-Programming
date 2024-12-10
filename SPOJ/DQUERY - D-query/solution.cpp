#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
 
struct FenwickTree{
	int n;
	vector<int> v;
	vector<int> st;
	void build(int m);
	int prev(int pos);
	int next(int pos);
	void update(int pos, int value);
	int prefixSum(int pos);
	int query(int l, int r);
};
 
int FenwickTree::prev(int pos){ return pos - (pos & -pos); }
int FenwickTree::next(int pos){ return pos + (pos & -pos); }
 
void FenwickTree::build(int m){
	n = m;
	v.clear(); v.resize(n+1, 0);
	st.clear(); st.resize(n+1, 0);
}
 
void FenwickTree::update(int pos, int value){
	int old = v[pos];
	v[pos] = value;
	while(pos <= n){
		st[pos] = st[pos] - old;
		st[pos] = st[pos] + value;
		pos = next(pos);
	}
}
 
int FenwickTree::prefixSum(int pos){
	int ans = 0;
	while(pos > 0){
		ans += st[pos];
		pos = prev(pos);
	}
	return ans;
}
 
int FenwickTree::query(int l, int r){
	return prefixSum(r) - prefixSum(l-1);
}
 
 
struct Query{
	int id,l,r,ans;
	Query() : id(0), l(0), r(0), ans(0) {}
	Query(int _id, int _l, int _r, int _ans) : id(_id), l(_l), r(_r), ans(_ans) {}
};
 
int sortByIdAsc(Query a, Query b){ return a.id < b.id; }
int sortByLAsc(Query a, Query b){ return a.l < b.l; }
 
const int maxN = 30000;
const int maxValue = 1000000;
 
vector<int> a(maxN+1);
vector<int> ri(maxN+1);
vector<int> last(maxValue+1, -1);
vector<int> marks(maxN+1,0);
vector<Query> queries;
FenwickTree ft;
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	vector<int> a(n+1);
	for(int i=1; i<=n; i++)
	cin>>a[i];
	for(int i=n; i>=1; i--){
		ri[i] = last[a[i]];
		last[a[i]] = i;
		marks[i] = 1;
		if(ri[i] != -1)
		marks[ri[i]] = 0;
	}
 
	ft.build(n);
	for(int i=1; i<=n; i++)
	ft.update(i, marks[i]);
 
	int q;
	cin>>q;
	for(int id=0; id<q; id++){
		int l,r; cin>>l>>r;
		queries.push_back(Query(id, l, r, 0));
	}
	sort(queries.begin(), queries.end(), sortByLAsc);
	int lastL = 1;
	for(int i=0; i<queries.size(); i++){
		if(lastL != -1){
			if(queries[i].l > lastL){
				for(int j=lastL; j<queries[i].l; j++){
					marks[j] = 0;
					ft.update(j, 0);
					if(ri[j] != -1){
						marks[ri[j]] = 1;
						ft.update(ri[j], 1);
					}
				}
			}
		}
		queries[i].ans = ft.query(queries[i].l, queries[i].r);
		lastL = queries[i].l;
	}
	sort(queries.begin(), queries.end(), sortByIdAsc);
	for(int i=0; i<queries.size(); i++)
	cout<<queries[i].ans<<endl;
}
