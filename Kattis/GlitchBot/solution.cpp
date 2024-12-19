#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,x,y,sx,sy,s,k,i,j,l;
	string cad;
	cin>>x>>y;
	cin>>n;
	vector<int> V(n);
	for(i=0; i<n; i++){
		cin>>cad;
		if(cad=="Left")
		V[i]= 1;
		else if(cad=="Right")
		V[i]=2;
		else
		V[i]=3;
	}
	for(i=0; i<n; i++){
		for(j=1; j<=3; j++){
			sx=0; sy=0;
			s=0;
			for(l=0; l<n; l++){
				k=V[l];
				if(l==i)
				k=j;
				
				if(k==3){
					if(s==0)
					sy++;
					else if(s==2)
					sy--;
					else if(s==1)
					sx++;
					else
					sx--;
				}
				else{
					if(k==1)
					s= (4+s-1)%4;
					else
					s= (s+1)%4;
				}
			}
			if(sx==x && sy==y)
			break;
		}
		if(j<=3)
		break;
	}
	cout<<i+1<<" ";
	if(j==1)
	cout<<"Left"<<endl;
	else if(j==2)
	cout<<"Right"<<endl;
	else if(j==3)
	cout<<"Forward"<<endl;
}