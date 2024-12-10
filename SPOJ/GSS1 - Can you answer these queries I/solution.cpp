#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
 
struct SegmentTreeNode{
 
	int null, minimo, maximo, ans;
 
	SegmentTreeNode(){ null = 1; }
 
	SegmentTreeNode(const SegmentTreeNode& s){
		null = s.null;
		minimo = s.minimo;
		maximo = s.maximo;
		ans = s.ans;
	}
 
	SegmentTreeNode(int minimo, int maximo, int ans){
		null = 0;
		this->minimo = minimo;
		this->maximo = maximo;
		this->ans = ans;
	}
 
};
 
struct SegmentTree{
	int n;
	vector<SegmentTreeNode> vect;
	vector<SegmentTreeNode> T;
 
	SegmentTreeNode funcion(SegmentTreeNode a, SegmentTreeNode b){
		if(a.null == 1 && b.null == 1)
		return SegmentTreeNode();
		if(a.null == 1)
		return b;
		if(b.null == 1)
		return a;
 
		int minimo, maximo, ans;
		ans = max(a.ans, b.ans);
		ans = max(ans, b.maximo - a.minimo);
 
		minimo = min(a.minimo, b.minimo);
		maximo = max(a.maximo, b.maximo);
 
		return SegmentTreeNode(minimo, maximo, ans);
	}
 
	void build(vector<SegmentTreeNode> V){
		vect.clear();
		vect.resize(V.size());
		for(int i=0; i<vect.size(); i++){
			vect[i] = V[i];
		}
		n = 4 * V.size();
		T.clear();
		T.resize(n, SegmentTreeNode());
		build2(1,0,vect.size()-1);
	}
 
	void build2(int pos, int i, int j){
		if(i==j)
		T[pos] = SegmentTreeNode(vect[i]);
		else{
			build2(2*pos, i, (i+j)/2);
			build2(2*pos+1, (i+j+2)/2, j);
			T[pos] = funcion(T[2*pos], T[2*pos+1]);
		}
	}
 
	void update(int id, SegmentTreeNode valor){
		vect[id] = valor;
		update2(1,0,vect.size()-1,id,valor);
	}
 
	void update2(int pos, int i, int j, int id, SegmentTreeNode valor){
		if(i==j){
			if(id==i)
			T[pos] = valor;
		}
		else{
			if(i<=id && id<=j){
				update2(2*pos, i,(i+j)/2, id, valor);
				update2(2*pos+1, (i+j+2)/2,j, id, valor);
				T[pos] = funcion(T[2*pos],T[2*pos+1]);
			}
		}
	}
 
	SegmentTreeNode query(int i, int j){
		return query2(1, 0,vect.size()-1, i,j);
	}
 
	SegmentTreeNode query2(int pos, int x, int y, int i, int j){
		if(j<x || i>y)
		return SegmentTreeNode();
		else if(i<=x && y<=j)
		return T[pos];
		else
		return funcion(query2(2*pos, x,(x+y)/2, i,j), query2(2*pos+1, (x+y+2)/2,y, i,j));
	}
};
 
vector<SegmentTreeNode> stVect;
SegmentTree st;
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,m,l,r;
	cin>>n;
	vector<int> v(n+1);
	v[0] = 0;
	for(int i=1; i<=n; i++){ cin>>v[i]; v[i] += v[i-1]; }
	for(int i=0; i<=n; i++)
	stVect.push_back(SegmentTreeNode(v[i], v[i], -1e9));
	
	st.build(stVect);
 
	cin>>m;
	while(m--){
		cin>>l>>r;
		SegmentTreeNode node = st.query(l,r);
		int ans = max(node.ans, node.maximo - v[l-1]);
		cout<<ans<<endl;
	}
}
