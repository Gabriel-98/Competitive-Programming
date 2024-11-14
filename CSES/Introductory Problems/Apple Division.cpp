#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define inf 1e12

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	long long ans = inf, sum = 0;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
		sum += v[i];
	}

	int masks = 1<<n;
	for(int mask=0; mask<masks; mask++){
		long long x = 0, y;
		for(int i=0; i<n; i++){
			if((mask & (1<<i)) > 0)
			x += v[i];
		}
		y = sum - x;
		ans = min(ans, abs(x-y));
	}
	cout<<ans<<endl;
}