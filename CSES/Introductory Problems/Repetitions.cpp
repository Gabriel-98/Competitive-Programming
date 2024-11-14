#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int ans = 0, counter = 1;
	string s; cin>>s;
	for(int i=1; i<s.size(); i++){
		if(s[i] == s[i-1])
		counter++;
		else{
			ans = max(ans, counter);
			counter = 1;
		}
	}
	ans = max(ans, counter);
	cout<<ans<<endl;
}