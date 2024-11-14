#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	vector<int> changeseq;
	changeseq.push_back(0);
	for(int i=2; i<=n; i++){
		int lim = changeseq.size();
		changeseq.push_back(i-1);
		for(int j=0; j<lim; j++)
		changeseq.push_back(changeseq[j]);
	}
	string bin(n, '0');
	cout<<bin<<endl;
	for(int i=0; i<changeseq.size(); i++){
		int pos = changeseq[i];
		bin[pos] = (bin[pos] == '0') ? '1' : '0';
		cout<<bin<<endl;
	}
}