#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t; cin>>t;
	while(t--){
		int y, x;
		long long r, ans;
		cin>>y>>x;
		r = max(x,y);
		ans = r*r;

		if(r % 2 == 0)
		ans -= x - 1 + r - y;
		else
		ans -= y - 1 + r - x;
		
		cout<<ans<<endl;
	}
}