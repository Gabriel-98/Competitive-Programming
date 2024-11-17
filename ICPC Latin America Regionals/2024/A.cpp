#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	string s; cin>>s;
	set<char> T;
	for(int i=0; i<s.size(); i++)
	T.insert(s[i]);
	int ans = s.size() - T.size();
	cout<<ans<<endl;
}