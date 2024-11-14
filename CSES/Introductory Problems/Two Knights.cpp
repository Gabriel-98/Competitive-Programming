#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

bool validate(int i1, int j1, int i2, int j2){
	return (abs(i1-i2) + abs(j1-j2) == 3) && i1 != i2 && j1 != j2;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t; cin>>t;
	for(int n=1; n<=t; n++){
		long long ans = 0;
		if(2 <= n && n <= 4){
			for(int id1=1; id1<=n*n; id1++){
				for(int id2=id1+1; id2<=n*n; id2++){
					int i1 = (id1+n-1) / n, j1 = ((id1-1) % n) + 1;
					int i2 = (id2+n-1) / n, j2 = ((id2-1) % n) + 1;
					if(!validate(i1,j1, i2, j2))
					ans++;
				}
			}
		}
		else if(n >= 5){
			long long n2, n4;
			n2 = n*n;
			n4 = n2*n2;
			ans = n4 - n2 - 8*(n-4)*(n-4) - 40 * (n-4) - 48;
			ans /= 2;
		}
		cout<<ans<<endl;
	}
}