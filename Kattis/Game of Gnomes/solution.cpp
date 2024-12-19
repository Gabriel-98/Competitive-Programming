#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	long long n,m,k,dif,x, rep, r1, r2, z, ans = 0, ansTemp;
	cin>>n>>m>>k;
/*
	if(n <= (m*(k-1))){
		rep = n / m;
		r1 = n - (n % m);
		r2 = n % m;
		ans = ((m*(m+1))/2) * rep;
		ans += (r2 * (r2 + 1)) / 2;
	}
	else{*/
		dif = n - (m*(k-1));
		x = 0;
		if(dif > 0){
			x = dif / k;
			if(dif % k != 0)
			x++;
		}

		z = n - x * k;

		for(; z >= 0; x++,z-=k){
			rep = z / m;
			r1 = z - (z % m);
			r2 = z % m;
				
			ansTemp = ((m*(m+1))/2) * rep;
			ansTemp += (r2 * (r2 + 1)) / 2;

			ansTemp += n*x;
			ansTemp -= ((x*(x-1))/2) * k;
				
			//cout<<x<<" "<<ansTemp<<" "<<z<<endl;
			ans = max(ans, ansTemp);
		}

	/*	z = 0;
		for(; (n-z) % k !=  0; z++){ }
		for(; z <= (m*(k-1)); z+=k){
			x = (n - z) / k;

			rep = z / m;
			r1 = z - (z % m);
			r2 = z % m;
				
			ansTemp = ((m*(m+1))/2) * rep;
			ansTemp += (r2 * (r2 + 1)) / 2;

			ansTemp += n*x;
			ansTemp -= ((x*(x-1))/2) * k;
				
		//	cout<<x<<" "<<ansTemp<<" "<<z<<endl;
			ans = max(ans, ansTemp);
		}*/
	//}
	cout<<ans<<endl;
}