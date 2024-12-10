#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
 
const long long mod = 1000000007;
const int c = 1000010;
vector<long long> pow2(c+1), pow3(c+1), pow4(c+1);
 
void preprocesar(){
	pow2[0] = 1;	pow3[0] = 1; 	pow4[0] = 1;
	for(int i=1; i<=c; i++){
		pow2[i] = (pow2[i-1] * 2) % mod;
		pow3[i] = (pow3[i-1] * 3) % mod;
		pow4[i] = (pow4[i-1] * 4) % mod;
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	preprocesar();
	int t,n;
	long long ans;
	cin>>t;
	while(t--){
		cin>>n;
		ans = (pow4[n] - 2*pow3[n] + pow2[n]) % mod;
		if(ans < 0)
		ans += mod;
		cout<<ans<<endl;
	}
}
