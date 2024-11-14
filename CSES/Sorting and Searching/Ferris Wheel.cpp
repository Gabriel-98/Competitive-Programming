#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

bool validate(const vector<int>& p, int gondolas, int x){
	for(int i=0,j=2*gondolas-1; i<gondolas; i++,j--){
		if(p[i]+p[j] > x)
		return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n, x; cin>>n>>x;
	vector<int> p(n);
	for(int i=0; i<n; i++)
	cin>>p[i];
	sort(p.begin(), p.end());

	int first = 0, last = n/2;
	while(first < last){
		int middle = (first + last + 1) / 2;
		if(validate(p, middle, x)) first = middle;
		else last = middle - 1;
	}
	int ans = first + (n - 2*first);
	cout<<ans<<endl;
}