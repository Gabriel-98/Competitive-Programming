#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
 
const int maxN = 100000;
const int maxLogN = log2(maxN);
int st[maxLogN+1][maxN];
 
void build(vector<int> &v){
	int n = v.size();
	for(int j=0; j<n; j++)
	st[0][j] = v[j];
	for(int i=1,pw=1; i<=maxLogN; i++,pw<<=1){
		for(int j=0; j<n; j++){
			st[i][j] = st[i-1][j];
			if(j+pw < n)
			st[i][j] = max(st[i][j], st[i-1][j+pw]);
		}
	}
}
 
int query(int l, int r){
	int lg = log2(r+1-l);
	int pw = 1<<lg;
	int a = st[lg][l];
	int b = st[lg][r-pw+1];
	int ans = max(a, b);
	return ans;
}
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n, q; cin>>n>>q;
	vector<int> v(n);
	for(int i=0; i<n; i++)
	cin>>v[i];
	build(v);
 
	int ans = 0;
	while(q--){
		int l,r; cin>>l>>r; l--; r--;
		if(l == r) ans++;
		else if(l < r){
			int taller = query(l,r-1);
			if(taller <= v[l])
			ans++;
		}
		else{
			int taller = query(r+1, l);
			if(taller <= v[l])
			ans++;
		}
	}
	cout<<ans<<endl;
}
