#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1000000000

const int Q=2000000;
vector<int> DP(Q+1),DP2(Q+1);

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,ans1,x,i,j;
	cin>>n;
	vector<int> V(n);
	for(i=0; i<n; i++){
		cin>>V[i];
	}
	ans1=0;
	DP[0]=0;
	for(i=1,j=0; i<=Q; i++){
		if(j<n-1){
			if(i==V[j+1])
			j++;
		}
		DP[i]= DP[i-V[j]]+1;
	}
	DP2[0]=0;
	for(i=1; i<=Q; i++){
		DP2[i]= INF;
		for(j=0; j<n; j++){
			if(i-V[j]>=0)
			DP2[i]= min(DP2[i],DP2[i-V[j]]+1);
		}
	}
	for(i=1; i<=Q; i++){
		if(DP2[i] < DP[i])
		break;
	}
	if(i==Q+1)
	cout<<"canonical"<<endl;
	else
	cout<<"non-canonical"<<endl;
}