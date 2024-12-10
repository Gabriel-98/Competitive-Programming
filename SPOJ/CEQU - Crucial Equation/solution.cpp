#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
 
int x, y, mcd;
 
void extendedEuclid(int a, int b){
	int k;
 	if(a < b){
 		k = a;
 		a = b;
 		b = k;
 	}
 	if(b == 0){
 		x = 1;
 		y = 0;
 		mcd = a;
 	}
 	else{
 		extendedEuclid(b, a%b);
 		x = y + b;
 		y = (mcd - a*x) / b;
 	}
}
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t,l,k,n,a,b,c;
	cin>>t;
	for(l=1; l<=t; l++){
		cin>>a>>b>>c;
		extendedEuclid(a,b);
		if(a < b){
			k = a;
			a = b;
			b = k;
		}
		cout<<"Case "<<l<<": ";
		if(c % mcd != 0)
		cout<<"No"<<endl;
		else
		cout<<"Yes"<<endl;
	}
}
