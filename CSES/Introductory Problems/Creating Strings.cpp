#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	string s; cin>>s;
	sort(s.begin(), s.end());
	vector<string> ans;
	
	ans.push_back(s);
	while(next_permutation(s.begin(), s.end()))
	ans.push_back(s);

	cout<<ans.size()<<endl;
	for(int i=0; i<ans.size(); i++)
	cout<<ans[i]<<endl;
}