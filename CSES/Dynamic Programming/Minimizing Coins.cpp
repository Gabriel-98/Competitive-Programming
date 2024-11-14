#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define inf 1e9

const int maxX = 1000000;
vector<int> dp(maxX+1); // dp[i]: minimum number of coins with sum = i.

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int  n, x;
	cin>>n>>x;
	vector<int> coins(n);
	for(int i=0; i<n; i++)
	cin>>coins[i];

	dp[0] = 0;
	for(int sum=1; sum<=x; sum++){
		dp[sum] = inf;
		for(int i=0; i<n; i++){
			if(sum - coins[i] >= 0)
			dp[sum] = min(dp[sum], dp[sum-coins[i]] + 1);
		}
	}
	cout<<((dp[x] == inf) ? -1 : dp[x])<<endl;
}