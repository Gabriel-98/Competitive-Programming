#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<int,int> par;

struct azulejo{
	int c,h,id;	// costo, altura
};

int funcionSortAscendente(struct azulejo A, struct azulejo B){ return A.c < B.c; }

multimap<int,int> HA, HB;			// (altura, id)
vector<int> ans1, ans2;

int main() {
	//ios_base::sync_with_stdio(false);cin.tie(0);
	int n,cond=1,i,j,j1,j2;
	multimap<int,int>::iterator it,it2;
	cin>>n;
	vector<struct azulejo> A(n), B(n);
	for(i=0; i<n; i++){ cin>>A[i].c;  A[i].id = i+1; }
	for(i=0; i<n; i++){ cin>>A[i].h; }
	sort(A.begin(), A.end(), funcionSortAscendente);
	
	for(i=0; i<n; i++){ cin>>B[i].c; B[i].id = i+1; }
	for(i=0; i<n; i++){ cin>>B[i].h; }
	sort(B.begin(), B.end(), funcionSortAscendente);
	
	/*cout<<endl;
	for(i=0; i<n; i++){ cout<<A[i].c<<" "; } cout<<endl;
	for(i=0; i<n; i++){ cout<<A[i].h<<" "; } cout<<endl;
	for(i=0; i<n; i++){ cout<<B[i].c<<" "; } cout<<endl;
	for(i=0; i<n; i++){ cout<<B[i].h<<" "; } cout<<endl;*/

	HA.insert(par(A[0].h, A[0].id));
	HB.insert(par(B[0].h, B[0].id));
	for(i=0,j1=1,j2=1; i<n; ){
		if((j1 < n && A[j1].c == A[j1-1].c) || (j2 < n && B[j2].c == B[j2-1].c)){
			if(j1 < n && A[j1].c == A[j1-1].c){
				HA.insert(par(A[j1].h, A[j1].id));
				j1++;
			}
			if(j2 < n && B[j2].c == B[j2-1].c){
				HB.insert(par(B[j2].h, B[j2].id));
				j2++;
			}
		}
		else{
			if(i >= j1 || i >= j2){
				if(i >= j1){
					HA.insert(par(A[j1].h, A[j1].id));
					j1++;
				}
				if(i >= j2){
					HB.insert(par(B[j2].h, B[j2].id));
					j2++;
				}
			}
			else{
				if(HA.size() <= HB.size()){
					it = HB.lower_bound(HA.begin()->first);
					if(it == HB.begin()){
						cond = 0;
						break;
					}
					else{
						it--;
						ans1.push_back(HA.begin()->second);
						ans2.push_back(it->second);
						HA.erase(HA.begin());
						HB.erase(it);
					}
				}
				else{
					it = HA.upper_bound(HB.begin()->first);
					if(it == HA.end()){
						cond = 0;
						break;
					}
					else{
						ans1.push_back(it->second);
						ans2.push_back(HB.begin()->second);
						HA.erase(it);
						HB.erase(HB.begin());
					}
				}
				i++;
			}
		}
	}

	if(cond == 0)
	cout<<"impossible"<<endl;
	else{
		for(i=0; i<n; i++){
			if(i > 0)
			cout<<" ";
			cout<<ans1[i];
		}
		cout<<endl;
		for(i=0; i<n; i++){
			if(i > 0)
			cout<<" ";
			cout<<ans2[i];
		}
		cout<<endl;
	}
}