#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

// SolverHanoiTower moves the n uppermost disks from stack x to stack y.
void SolverHanoiTower(int n, int x, int y){
	if(n == 1)
	cout<<x<<" "<<y<<endl;
	else{
		int z = 6 - x - y;
		SolverHanoiTower(n-1, x, z);
		cout<<x<<" "<<y<<endl;
		SolverHanoiTower(n-1, z, y);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n; cin>>n;
	int moves = (1<<n) - 1;
	cout<<moves<<endl;
	SolverHanoiTower(n, 1, 3);
}