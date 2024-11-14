#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	string s;
	cin>>s;
	vector<int> alp(26, 0);
	for(int i=0; i<s.size(); i++)
	alp[s[i]-'A']++;

	int oddCounter = 0;
	for(int i=0; i<26; i++)
	oddCounter += alp[i] % 2;

	if(oddCounter > 1)
	cout<<"NO SOLUTION"<<endl;
	else{
		string s1 = "", s2 = "", m = "";
		for(int i=0; i<26; i++){
			int middle = alp[i] / 2;
			for(int j=0; j<middle; j++)
			s1 += ('A' + i);

			if(alp[i] % 2 == 1)
			m = ('A' + i);
		}
		s2 = s1;
		reverse(s2.begin(), s2.end());
		string ans = s1 + m + s2;
		cout<<ans<<endl;
	}
}