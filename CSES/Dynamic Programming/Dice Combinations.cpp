#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxN = 1000000;
const long long mod = 1000000007;
int dp[maxN+1];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	dp[0] = 1;
	for(int i=1; i<=n; i++){
		dp[i] = 0;
		for(int j=1; j<=6; j++){
			if(i-j >= 0)
			dp[i] = (dp[i] + dp[i-j]) % mod;
		}
	}
	cout<<dp[n]<<endl;
}