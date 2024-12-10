#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
 
string cad;
vector<int> B(500000);		// Patron mas largo
 
void kmpPreprocess(){
	B[0] = -1;
	B[1] = 0;
	for(int i=1; i<cad.size(); i++){
		if(cad[B[i]] == cad[i])
		B[i+1] = B[i] + 1;
		else
		B[i+1] = 0;
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int tam,n,ans,i;
	string texto;
	while(cin>>cad && cad!="*"){
		kmpPreprocess();
		tam = cad.size();
		for(i=cad.size(); i>=0; i--){
			if(B[i] == 0){
				tam = i;
				break;
			}
		}
		i++;
		if(B[cad.size()] != 0 && B[cad.size()] % tam == 0)
		ans = (B[cad.size()] / tam) + 1;
		else
		ans = 1;
		cout<<ans<<endl;
	}
}
