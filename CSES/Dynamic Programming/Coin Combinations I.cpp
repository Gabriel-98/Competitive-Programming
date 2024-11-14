#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxX = 1000000;
const long long mod = 1e9 + 7;
vector<int> dp(maxX+1); // dp[i]: number of ways to obtain a sum = i with the coin values (can be the same values, but in different order).

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int  n, x;
	cin>>n>>x;
	vector<int> coins(n);
	for(int i=0; i<n; i++)
	cin>>coins[i];

	dp[0] = 1;
	for(int sum=1; sum<=x; sum++){
		dp[sum] = 0;
		for(int i=0; i<n; i++){
			if(sum - coins[i] >= 0)
			dp[sum] = (dp[sum] + dp[sum-coins[i]]) % mod;
		}
	}
	cout<<dp[x]<<endl;
}