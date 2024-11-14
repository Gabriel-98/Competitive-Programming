#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n, ans = 1; cin>>n;
	for(int i=1; i<=n; i++)
	ans = (ans * 2) % mod;
	cout<<ans<<endl;
}