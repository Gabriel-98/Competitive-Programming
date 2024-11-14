#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct FenwickTreeNode {
	long long value;
	FenwickTreeNode() : value(0) {}
	FenwickTreeNode(long long _value) : value(_value) {}
	void SetNeutral(){ value = 0; } // Modify according to the operation (e.g. 0 for sum, 1 for multiplication, ...)
};

struct FenwickTree{
	int size;
	vector<FenwickTreeNode> nodes, blocks;

	FenwickTreeNode combine(FenwickTreeNode a, FenwickTreeNode b);
	FenwickTreeNode decombine(FenwickTreeNode a, FenwickTreeNode b);
	FenwickTreeNode calculatePrefix(int pos);
	void Build(int size);
	void Update(int pos, FenwickTreeNode newValue);
	FenwickTreeNode Query(int l, int r);
};

void FenwickTree::Build(int size) {
	this->size = size;
	nodes.clear(); blocks.clear();
	nodes.resize(size+1);
	blocks.resize(size+1);
	for(int i=0; i<=size; i++){
		nodes[i].SetNeutral();
		blocks[i].SetNeutral();
	}
}

void FenwickTree::Update(int pos, FenwickTreeNode newValue){
	FenwickTreeNode oldValue = nodes[pos];
	nodes[pos] = newValue;
	while(pos <= size){
		blocks[pos] = decombine(blocks[pos], oldValue);
		blocks[pos] = combine(blocks[pos], newValue);
		pos += pos & -pos;
	}
}

FenwickTreeNode FenwickTree::Query(int l, int r){
	return decombine(calculatePrefix(r), calculatePrefix(l-1));
}

FenwickTreeNode FenwickTree::combine(FenwickTreeNode a, FenwickTreeNode b){
	// Modify the combination logic here.
	return FenwickTreeNode(a.value + b.value);
}

FenwickTreeNode FenwickTree::decombine(FenwickTreeNode a, FenwickTreeNode b){
	// Modify the decombination logic here.
	return FenwickTreeNode(a.value - b.value);
}

FenwickTreeNode FenwickTree::calculatePrefix(int pos){
	FenwickTreeNode prefix = FenwickTreeNode();
	prefix.SetNeutral();
	while(pos > 0){
		prefix = combine(prefix, blocks[pos]);
		pos -= pos & -pos;
	}
	return prefix;
}

const int maxN = 200000;
vector<long long> v(maxN+1);
FenwickTree ft;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n, q;
	cin>>n>>q;

	ft.Build(n);
	for(int i=1; i<=n; i++){
		cin>>v[i];
		ft.Update(i, FenwickTreeNode(v[i]));
	}
	while(q--){
		int op; cin>>op;
		if(op == 1){
			int pos, value;
			cin>>pos>>value;
			ft.Update(pos, FenwickTreeNode(value));
		}
		else{
			int l, r;
			cin>>l>>r;
			long long sum = ft.Query(l,r).value;
			cout<<sum<<endl;
		}
	}
}