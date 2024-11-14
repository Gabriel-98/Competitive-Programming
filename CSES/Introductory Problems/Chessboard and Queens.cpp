#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<string> board(8);

int solver(vector<int>& cellids){
	if(cellids.size() == 8)
	return 1; 
	else{
		int lastId = -1;
		if(cellids.size() > 0)
		lastId = cellids[cellids.size()-1];
		
		int ans = 0;
		for(int id=lastId+1; id<64; id++){
			int y1 = id / 8, x1 = id % 8;
			if(board[y1][x1] == '.'){
				bool valid = true;
				for(int i=0; i<cellids.size() && valid; i++){
					int id2 = cellids[i];
					int y2 = id2 / 8, x2 = id2 % 8;
					if(abs(y1-y2) == abs(x1-x2) || y1 == y2 || x1 == x2)
					valid = false;
				}
				if(valid){
					cellids.push_back(id);
					ans += solver(cellids);
					cellids.pop_back();
				}
			}
		}
		return ans;
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	for(int i=0; i<8; i++)
	cin>>board[i];
	vector<int> cellids;
	int ans = solver(cellids);
	cout<<ans<<endl;
}