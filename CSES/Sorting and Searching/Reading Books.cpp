#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	long long sum = 0, middle, ans;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
		sum += v[i];
	}
	middle = sum / 2;
	sort(v.begin(), v.end());

	ans = sum;
	if(v[n-1] > middle)
	ans = 2 * v[n-1];
	cout<<ans<<endl;
}