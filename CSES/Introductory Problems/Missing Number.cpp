#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	vector<int> v(n+1, 0);
	for(int i=2; i<=n; i++){
		int x; cin>>x; v[x] = 1;
	}
	int ans = 0;
	for(int i=1; i<=n && ans == 0; i++){
		if(v[i] == 0)
		ans = i;
	}
	cout<<ans<<endl;
}