#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++)
	cin>>v[i];
	
	long long ans = 0;
	for(int i=1; i<n; i++){
		ans += max(0, v[i-1] - v[i]);
		v[i] = max(v[i], v[i-1]);
	}
	cout<<ans<<endl;
}