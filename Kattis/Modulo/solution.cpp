#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,j,acu=0;
	int V[10];
	for(i=0; i<=9; i++){
		cin>>V[i];
		V[i]%=42;
		for(j=0; j<i; j++){
			if(V[j]==V[i])
			break;
		}
		if(j==i)
		acu+=1;
	}
	cout<<acu<<endl;
}
