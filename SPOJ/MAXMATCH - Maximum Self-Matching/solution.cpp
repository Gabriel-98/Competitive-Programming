#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef complex<double> complejo;
#define pi 3.141592
 
vector<complejo> fft(vector<complejo> a, bool inverse=false){
	int n = a.size();
	if(n == 1)
	return a;
 
	complejo wn, w;
	if(inverse)
	wn = complejo(cos(2*pi/n), -sin(2*pi/n));
	else
	wn = complejo(cos(2*pi/n), sin(2*pi/n));
	w = 1.0;
 
	vector<complejo> aEven(n/2), aOdd(n/2);
	vector<complejo> yEven, yOdd, y(n);
 
	for(int i=0,j1=0,j2=1; i<n/2; i++,j1+=2,j2+=2){
		aEven[i] = a[j1];
		aOdd[i] = a[j2];
	}
 
	yEven = fft(aEven, inverse);
	yOdd = fft(aOdd, inverse);
 
	for(int i=0,j=n/2; i<n/2; i++,j++){
		y[i] = yEven[i] + w*yOdd[i];
		y[j] = yEven[i] - w*yOdd[i];
		w *= wn;
	}
 
	return y;
}
 
vector<complejo> reverse(vector<complejo> V){
	vector<complejo> ans;
	for(int i=V.size()-1; i>=0; i--){ ans.push_back(V[i]); }
	return ans;
}
 
vector<complejo> A, B, C, C1, C2, Z;
 
vector<int> solver(vector<int> V){
	int n,lg,pot,i,j;
	n = 2*V.size();
	lg = log2(n);
	pot = pow(2,lg);
	if(n > pot)
	n = 2*pot;
	
	A.resize(n,0);	B.resize(n,0);
	for(i=0,j=V.size()-1; i<V.size(); i++,j--){
		A[i] = V[i];
		B[i] = V[j];
	}
	C1 = fft(A);
	C2 = fft(B);
	C.resize(n);
	for(i=0; i<n; i++){ C[i] = C1[i] * C2[i]; }
	Z = fft(C, true);
 
	/*for(i=0; i<n; i++){ cout<<A[i]<<" "; }	cout<<endl;
	for(i=0; i<n; i++){ cout<<B[i]<<" "; }	cout<<endl;
	for(i=0; i<n; i++){ cout<<C1[i]<<" "; }	cout<<endl;	
	for(i=0; i<n; i++){ cout<<C2[i]<<" "; }	cout<<endl;	
	for(i=0; i<n; i++){ cout<<C[i]<<" "; }	cout<<endl;
	for(i=0; i<n; i++){ cout<<Z[i]<<" "; }	cout<<endl;	*/
 
	vector<int> ans;
	for(i=V.size()-1; i<(n-1); i++){
		double x = round(real(Z[i])/ n);
		ans.push_back(x);
	}
	return ans;
}
 
 
string cad;
vector<int> letras[3];
vector<int> X, Y, ans;
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	//vector<int> V = {0,1,0,0,1,0,1,1};
	//vector<int> V = {1,0,0,0,0,0,0,0};
	//vector<int> S = solver(V);
 
	//for(int i=0; i<S.size(); i++){ cout<<S[i]<<" "; }	cout<<endl;
	int n,mayor,i,j;
	cin>>cad;
	n = cad.size();
	for(i=0; i<3; i++){
		letras[i].resize(n);
		for(j=0; j<n; j++){
			if(cad[j] == ('a' + i))
			letras[i][j] = 1;
			else
			letras[i][j] = 0;
		}
	}
	X.resize(n);
	for(i=0; i<n; i++){ X[i] = 0; }
	for(i=0; i<3; i++){
		Y = solver(letras[i]);
		for(j=0; j<n; j++){ X[j] += Y[j]; }
	}
	mayor = 0;
	for(i=1; i<n; i++){
		if(X[i] > mayor)
		mayor = X[i];
	}
	for(i=1; i<n; i++){
		if(X[i] == mayor)
		ans.push_back(i);
	}
	cout<<mayor<<endl;
	for(i=0; i<ans.size(); i++){
		if(i > 0)
		cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
}
