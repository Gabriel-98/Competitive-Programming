#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef pair<long long, long long> par;
typedef pair<par, long long> par2;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,cont,i;
	long long ans,x,y,k;
	map<pair<long long, long long>, long long> T;
	map<pair<long long, long long>, long long>::iterator it;
	cin>>n;
	vector<pair<long long,long long>> V(n);
	for(i=0; i<n; i++){
		cin>>V[i].first>>V[i].second;
		x= V[i].first;
		y= V[i].second;
		it= T.find(par(x,y));
		if(it==T.end())
		T.insert(par2(par(x,y),1));
		else{
			cont= it->second;
			T.erase(it);
			T.insert(par2(par(x,y),cont+1));
		}
	}
	ans=0;
	for(i=0; i<n; i++){
		x= V[i].first + 2018;
		y= V[i].second;
		it= T.find(par(x,y));
		if(it!=T.end()){
			ans+= it->second;
		}
		x= V[i].first;
		y= V[i].second + 2018;
		it= T.find(par(x,y));
		if(it!=T.end()){
			ans+= it->second;
		}
		x= V[i].first + 1680;
		y= V[i].second + 1118;
		it= T.find(par(x,y));
		if(it!=T.end()){
			ans+= it->second;
		}
		x= V[i].first - 1680;
		y= V[i].second + 1118;
		it= T.find(par(x,y));
		if(it!=T.end()){
			ans+= it->second;
		}
		x= V[i].first + 1118;
		y= V[i].second + 1680;
		it= T.find(par(x,y));
		if(it!=T.end()){
			ans+= it->second;
		}
		x= V[i].first - 1118;
		y= V[i].second + 1680;
		it= T.find(par(x,y));
		if(it!=T.end()){
			ans+= it->second;
		}
	}
	cout<<ans<<endl;
}