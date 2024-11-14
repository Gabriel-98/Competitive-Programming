#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxN = 200000;
vector<int> v(maxN+1);
vector<long long> ps(maxN+1);
map<long long,int> counters;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n, a, b;
	cin>>n>>a>>b;
	ps[0] = 0;
	for(int i=1; i<=n; i++){
		cin>>v[i];
		ps[i] = ps[i-1] + v[i];
	}

	for(int i=a; i<=b; i++)
	counters[ps[i]]++;
	long long ans = counters.rbegin()->first;
	
	for(int i=a+1,j=b+1; i<=n; i++,j++){
		counters[ps[i-1]]--;
		if(j <= n)
		counters[ps[j]]++;
		if(counters[ps[i-1]] == 0)
		counters.erase(counters.find(ps[i-1]));

		long long aux = (counters.rbegin()->first) - ps[i-a];
		ans = max(ans, aux);
	}
	cout<<ans<<endl;
}