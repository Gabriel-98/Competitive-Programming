#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
 
long double DP[1001][1001];
 
long double funcion(int menores, int mayores, int nivel){
	int i,j,l;
	long double a,b,c;
	for(i=0; i<=menores; i++){
		for(j=0; j<=mayores; j++){
			DP[i][j] = 0;
		}
	}
	for(l=menores+mayores-nivel; l<=menores+mayores; l++){
		for(i=0; i<=menores; i++){
			j = l - i;
			if(j <= mayores){
				if(l == menores+mayores-nivel){
					DP[i][j] = 2*i;
					c = (i+j)*(i+j+1);
					DP[i][j] /= c;
				}
				else{
					DP[i][j] = 0;
					if(i > 0){
						a = i*(i-1);
						c = (i+j)*(i+j+1);
						DP[i][j] += (a * DP[i-1][j]) / c;
					}
					if(j > 0){
						b = ((i + j) * (i + j + 1)) - (i*(i+1));
						c = (i+j)*(i+j+1);
						DP[i][j] += (b * DP[i][j-1]) / c;
 
					}
				}
			}
		}
	}
	return DP[menores][mayores];
}
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,x,y,i;
	long double ans;
	while(cin>>n>>x>>y){
		if(y == 1){
			if(x==1)
			ans = 1.0;
			else
			ans = 0.0;
		}
		else
		ans = funcion(x-1, n-x, n-y);
		cout<<fixed<<setprecision(4)<<ans<<endl;
	}
}
