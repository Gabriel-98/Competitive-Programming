#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	if(n == 1) cout<<"1"<<endl;
	else if(n <= 3) cout<<"NO SOLUTION"<<endl;
	else if(n == 4) cout<<"2 4 1 3"<<endl;
	else{
		cout<<1;
		for(int i=3; i<=n; i+=2) cout<<" "<<i;
		for(int i=2; i<=n; i+=2) cout<<" "<<i;
		cout<<endl;
	}
}