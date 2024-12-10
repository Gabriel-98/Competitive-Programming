#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
 
const long long mod = 1000000007;
const int c = 1000000;
vector<long long> V(c+1);

long long x, y, mcd;

void extendedEuclid(long long a, long long b){
	if(b == 0){
		x = 1;
		y = 0;
		mcd = a;
	}
	else{
		extendedEuclid(b, a % b);
		x = y;
		y = (mcd - a*x) / b;
	}
}
 
// retorna (a/b) mod m
long long moduloDivision(long long a, long long b, long long modulo){
	extendedEuclid(b,modulo);
	if(x < 0)
	x += modulo;
	return (x * (a / mcd)) % modulo;
}
 
 
void precalcular(){
	V[1] = 1;
	for(int i=2; i<=c; i++){
		V[i] = ((4*i - 2)*V[i-1]) % mod;
		V[i] = moduloDivision(V[i], i-1, mod);
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	precalcular();
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<V[n]<<endl;
	}
}
