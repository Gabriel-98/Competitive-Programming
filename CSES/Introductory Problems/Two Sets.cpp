#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	long long n, sum, middle; cin>>n;
	string ans = "NO";
	sum = (n * (n+1)) / 2;
	if(sum % 2 == 0){
		cout<<"YES"<<endl;
		middle = sum / 2;

		vector<int> a, b, s(n+1, 0);
		long long accu = 0;
		for(int i=n; i>=1 && accu <= middle; i--){
			int x = min(middle - accu, (long long)i);
			accu += x;
			s[x] = 1;
		}
		for(int i=1; i<=n; i++){
			if(s[i] == 1) a.push_back(i);
			else b.push_back(i);
		}

		cout<<a.size()<<endl;
		for(int i=0; i<a.size(); i++) cout<<((i > 0) ? " " : "")<<a[i]; cout<<endl;
		cout<<b.size()<<endl;
		for(int i=0; i<b.size(); i++) cout<<((i > 0) ? " " : "")<<b[i]; cout<<endl;
	}
	else
	cout<<"NO"<<endl;
}