#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
 
int Parent(int i){
	return(i/2);
}
 
int Left(int i){
	return(i*2);
}
 
int Right(int i){
	return((i*2)+1);
}
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,k,x,i,j,l,r,pos,cont;
	while(cin>>n>>k){
		int M[n][k];
		int POS[k];
		int V[k];
		for(i=0; i<k; i++){
			POS[i]=0;
		}
		for(i=0; i<n; i++){
			for(j=0; j<k; j++){
				cin>>x;
				V[j]=x;
				if(j==0)
				POS[0]=1;
				else{
					r=1;
					pos=0;
					while(true){
						if(x < V[pos])
						r= Left(r);
						else
						r= Right(r);
						
						for(l=0; l<j; l++){
							if(POS[l]==r)
							break;
						}
						if(l==j){
							POS[j]= r;
							break;
						}
						else
						pos= l;
					}
				}
			}
			sort(POS, POS+k);
			for(j=0; j<k; j++){
				M[i][j]= POS[j];
			}
		}
		cont=1;
		for(l=1; l<n; l++){
			for(i=0; i<l; i++){
				for(j=0; j<k; j++){
					if(M[l][j] != M[i][j])
					break;
				};
				if(j==k)
				break;
			}
			if(i==l)
			cont++;
		}
		cout<<cont<<endl;
	}
}
