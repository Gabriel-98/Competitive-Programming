#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int k, n; cin>>k>>n;
	int minN = 2*k - 1;
	int r3 = min(k, n - minN);
	int r2 = k - r3;
	
	string ans = "";
	for(int i=0; i<r3; i++) ans += "-X-";
	for(int i=0; i<r2; i++) ans += "X-";
	if(ans.size() > n) ans.pop_back();
	
	if(ans.size() == n) cout<<ans<<endl;
	else cout<<"*"<<endl;
}
