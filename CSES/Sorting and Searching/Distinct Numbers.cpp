#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	set<int> T;
	for(int i=0; i<n; i++){
		int x; cin>>x;
		T.insert(x);
	}
	cout<<T.size()<<endl;
}