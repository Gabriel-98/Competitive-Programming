#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int k, ans = 0; string s;
	cin>>k>>s;
	k--;

	if(k == 1){
		int d1 = 0, d2 = 0;
		string a = "", b = "";
		for(int i=0; i<s.size(); i++){
			if(i % 2 == 0){
				a += "0"; b += "1";
				if(s[i] == '0') d2++;
				else d1++;
			}
			else{
				a += "1"; b += "0";
				if(s[i] == '0') d1++;
				else d2++;
			}
		}
		if(d1 < d2){ ans = d1; s = a; }
		else{ ans = d2; s = b; }
	}
	else{
		int counter = 1;
		for(int i=1; i<s.size(); i++){
			if(s[i] == s[i-1]) counter++;
			else counter = 1;
			if(counter > k){
				counter = 1;
				ans++;
				if(i+1 < s.size() && s[i] != s[i+1])
				s[i-1] = (s[i-1] == '0') ? '1' : '0';
				else
				s[i] = (s[i] == '0') ? '1' : '0';
			}
		}
	}
	cout<<ans<<" "<<s<<endl;
}