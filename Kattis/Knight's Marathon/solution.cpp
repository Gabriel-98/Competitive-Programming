#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int funcion(int x, int y){
	int k,z,a,b,diagonal,ans;
	if(x < y){
		k = x;
		x = y;
		y = k;
	}
	if(2*y <= x){
		k = (x-1)/4;
		a = (k+1)*2;
		b = a+1;
		if((x-1)%4 <= 1)
		b = a-1;

		if((x+y) % 2 == 0)
		ans = a;
		else
		ans = b;
	}
	else{
		diagonal = x+y;
		if(diagonal%2 == 0){
			ans = ((diagonal+4)/6);
			ans *= 2;
		}
		else{
			ans = ((diagonal+7)/6);
			ans = (ans*2) - 1;
		}
	}
	return ans;
}

int main(){
/*	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int x,y;
	for(x=19; x>=0; x--){
		for(y=19; y>=0; y--){
			cout<<funcion(x,y)<<" ";
		}
		cout<<endl;
	}*/
	int nx,ny,kx,ky,cx,cy,ans,x,y;
	cin>>nx>>ny>>kx>>ky>>cx>>cy;
	x = abs(kx-cx);
	y = abs(ky-cy);
	ans = funcion(x,y);
	if(x==0 && y==0)
	ans = 0;
	else if((x==1 && y==0) || (x==0 && y==1))
	ans = 3;
	else if(x==2 && y==2)
	ans = 4;
	else if(x==1 && y==1){
		if((kx==0 && ky==0) || (cx==0 && cy==0))
		ans = 4;
		if((kx==0 && ky==ny-1) || (cx==0 && cy==ny-1))
		ans = 4;
		if((kx==nx-1 && ky==0) || (cx==nx-1 && cy==0))
		ans = 4;
		if((kx==nx-1 && ky==ny-1) || (cx==nx-1 && cy==ny-1))
		ans = 4;
	}
	cout<<ans<<endl;
}