#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxN = 100, maxX = 1000000;
const int mod = 1e9 + 7;
int dp[maxX+1]; // Is an abstraction of dp[i][j]: number of ways to obtain sum = i using coins with values <= j.

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int  n, x;
	cin>>n>>x;
	vector<int> coins(n+1);
	for(int i=1; i<=n; i++)
	cin>>coins[i];

	dp[0] = 1;
	for(int sum=1; sum<=x; sum++)
	dp[sum] = 0;
	for(int i=1; i<=n; i++){
		int coin = coins[i];
		for(int sum=coin; sum<=x; sum++)
		dp[sum] = (dp[sum] + dp[sum-coin]) % mod;
	}
	cout<<dp[x]<<endl;
}