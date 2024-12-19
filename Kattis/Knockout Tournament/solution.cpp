#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int funcionSort(int a, int b){ 	return a > b; }
int n;
vector<int> V;

vector<long double> solver(int inf, int sup){
	vector<long double> Z(n);
	for(int i=0; i<n; i++){ Z[i] = 0.0; }
	if(inf == sup)
	Z[inf] = 1.0;
	else{
		long double a,b;
		int lg2, pot2, x;
		vector<long double> V1, V2;
		lg2 = log2(sup+1-inf);
		pot2 = pow(2,lg2);
		x = pot2 / 2;
		x += min(pot2/2,(sup+1-inf)-pot2);

		V1 = solver(inf, inf+x-1);
		V2 = solver(inf+x, sup);
		for(int i=0; i<n; i++){
			if(V1[i] != 0){
				Z[i] = 0;
				a = V[i];
				for(int j=0; j<n; j++){
					if(V2[j] != 0){
						b = V[j];
						Z[i] += V2[j] / (a+b);
					}
				}
				Z[i] *= V1[i] * a;
			}
		}
		for(int i=0; i<n; i++){
			if(V2[i] != 0){
				Z[i] = 0;
				a = V[i];
				for(int j=0; j<n; j++){
					if(V1[j] != 0){
						b = V[j];
						Z[i] += V1[j] / (a+b);
					}
				}
				Z[i] *= V2[i] * a;
			}
		}
	}
	return Z;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x,y,i;
	long double ans;
	cin>>n;
	vector<long double> Z;
	cin>>y;
	for(i=0; i<n-1; i++){
		cin>>x;
		V.push_back(x);
	}
	V.push_back(y);
	sort(V.begin(), V.begin()+n-1, funcionSort);
	Z = solver(0, n-1);
	ans = Z[n-1];
	cout<<fixed<<setprecision(10)<<ans<<endl;
}