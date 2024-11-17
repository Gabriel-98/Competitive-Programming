#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pi 3.141592653589793238462643
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	double ang, ans = 0.0; int n;
	cin>>ang>>n;
	ang = ang / (180.0 / pi);
	vector<pii> v(n);
	for(int i=0; i<n; i++)
	cin>>v[i].first>>v[i].second;
	sort(v.begin(), v.end());

	double start = v[0].first, end = v[0].first;
	for(int i=0; i<n; i++){
		double l = v[i].second * (cos(ang) / sin(ang));
		double x1 = v[i].first, x2 = v[i].first + l;
		if(x1 <= end)
		end = max(end, x2);
		else{
			ans += end - start;
			start = x1;
			end = x2;
		}
	}
	ans += end - start;
	cout<<fixed<<setprecision(16)<<ans<<endl;
}