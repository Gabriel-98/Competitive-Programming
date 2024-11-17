#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int k, n; cin>>k>>n;
	int aux = n;
	if(((n+2)/3) <= k && k <= ((n+1)/2)){
		string ans = "";
		while(aux > 0){
			k--;
			if(((aux-2+2)/3) <= k && k <= ((aux-2+1)/2)){
				aux -= 2;
				ans += "X-";
			}
			else{
				aux -= 3;
				ans += "-X-";
			}
		}
		while(ans.size() > n)
		ans.pop_back();
		cout<<ans<<endl;
	}
	else
	cout<<"*"<<endl;
}