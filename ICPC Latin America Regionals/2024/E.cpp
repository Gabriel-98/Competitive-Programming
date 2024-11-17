#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxN = 100000;
vector<int> v(maxN), L(maxN, -1), R(maxN, -1);
vector<bool> used(maxN+1, false);
queue<int> unused;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
		if(v[i] != 0)
		used[v[i]] = true;
	}
	for(int i=1; i<=n; i++){
		if(!used[i])
		unused.push(i);
	}
	for(int i=0,last=-1; i<n; i++){
		if(v[i] == 0) L[i] = last;
		else last = v[i];
	}
	for(int i=n-1,last=-1; i>=0; i--){
		if(v[i] == 0) R[i] = last;
		else last = v[i];
	}

	// Two pointers.
	int maxLeft = 0, maxRight = 0;
	for(int i=0,j=n-1; i<=j; ){
		if(i-1 >= 0) maxLeft = max(maxLeft, v[i-1]);
		if(j+1 < n) maxRight = max(maxRight, v[j+1]);
		if(v[i] != 0) i++;
		else if(v[j] != 0) j--;
		else{
			int x = unused.front(); unused.pop();
			if(x > maxLeft && x > maxRight){
				if(R[i] < L[j]) v[i++] = x;
				else if(L[j] < R[i]) v[j--] = x;
				else if(R[i] == -1) v[i++] = x;
				else{
					if(v[i + R[i] - x] == R[i]) v[i++] = x;
					else v[j--] = x;
				}
			}
			else if(x > maxLeft) v[i++] = x;
			else if(x > maxRight) v[j--] = x;
			else break;
		}
	}

	// Validate answer.
	bool cond = true;
	int posN = -1;
	for(int i=0; i<n && posN == -1; i++){
		if(v[i] == n)
		posN = i;
	}
	if(posN == -1)
	cond = false;
	for(int i=0; i<posN && cond; i++){
		if(v[i] >= v[i+1])
		cond = false;
	}
	for(int i=posN; i<(n-1) && cond; i++){
		if(v[i] <= v[i+1])
		cond = false;
	}

	// Print answer.
	if(cond){
		for(int i=0; i<n; i++)
		cout<<((i > 0) ? " " : "")<<v[i];
		cout<<endl;
	}
	else
	cout<<"*"<<endl;
}