#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,i;
	char c;
	string cad;
	cin>>n;
	while(n--){
		cin>>c;
		getline(cin,cad);
		vector<int> V;
		for(i=1; cad[i]!='\0'; i++){
			if(cad[i]==' ')
			V.push_back(0);
			else
			V.push_back(cad[i]-'a'+1);
		}
		if(c=='e'){
			for(i=1; i<V.size(); i++){
				V[i]= (V[i]+V[i-1])%27;
			}
		}
		else{
			vector<int> K;
			K.push_back(V[0]);
			for(i=1; i<V.size(); i++){
				K.push_back((27+V[i]-V[i-1])%27);
			}
			for(i=1; i<V.size(); i++){
				V[i]= K[i];
			}
		}
		for(i=0; i<V.size(); i++){
			if(V[i]==0)
			cout<<" ";
			else
			cout<<char('a'+V[i]-1);
		}
		cout<<endl;
	}
}