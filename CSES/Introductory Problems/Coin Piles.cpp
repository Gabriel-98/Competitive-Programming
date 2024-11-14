#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t; cin>>t;
	while(t--){
		int a, b; cin>>a>>b;
		if((a+b) % 3 == 0){
			int n = (a+b) / 3;
			cout<<((a >= n && b >= n) ? "YES" : "NO")<<endl; 
		}
		else
		cout<<"NO"<<endl;
	}
}