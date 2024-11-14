#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	int ans = 0;
	for(int pw5=5; pw5<=n; pw5*=5)
	ans += n / pw5;
	cout<<ans<<endl;
}