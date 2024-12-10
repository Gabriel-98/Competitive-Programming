#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const long long zero = 0;

struct nodo{
	long long total;
	long long valor;
	long long valorIzq;
	long long valorDer;
	int nulo;
};

struct SegmentTree{
	int n;
	vector<long long> vect;
	vector<struct nodo> T;

	struct nodo funcion(struct nodo A, struct nodo B){
		long long a,b,c;
		struct nodo C;
		if(A.nulo == 1 && B.nulo == 1)
		C.nulo = 1;
		else if(A.nulo == 1){
			C.total = B.total;
			C.valor = B.valor;
			C.valorIzq = B.valorIzq;
			C.valorDer = B.valorDer;
			C.nulo = 0;
		}
		else if(B.nulo == 1){
			C.total = A.total;
			C.valor = A.valor;
			C.valorIzq = A.valorIzq;
			C.valorDer = A.valorDer;
			C.nulo = 0;
		}
		else{
			C.nulo = 0;
			C.total = A.total + B.total;
			C.valorIzq = max(A.valorIzq, A.total + B.valorIzq);
			C.valorDer = max(B.valorDer, B.total + A.valorDer);

			C.valor = max(A.total + B.total, A.total + B.valorIzq);
			C.valor = max(C.total, B.total + A.valorDer);
			C.valor = max(C.total, A.valorDer + B.valorIzq);
			C.valor = max(C.valor, A.valor);
			C.valor = max(C.valor, B.valor);
		}
		return C;
	}

	void built(vector<long long> V){
		vect = V;
		n= log2(V.size()*2 - 1) + 1;
		n = pow(2,n);
		T.clear();
		T.resize(n);
		built2(1,0,vect.size()-1);
	}

	void built2(int pos, int i, int j){
		if(i==j){
			T[pos].total = vect[i];
			T[pos].valor= vect[i];
			T[pos].valorIzq = vect[i];
			T[pos].valorDer = vect[i];
			T[pos].nulo = 0;
		}
		else{
			built2(pos*2, i, i+int((j-i)/2));
			built2((pos*2)+1, i+int((j-i)/2)+1, j);
			T[pos]= funcion(T[2*pos], T[(pos*2)+1]);
		}
	}

	void update(int id, long long valor){
		vect[id]= valor;
		update2(1, 0,vect.size()-1, id, valor);
	}

	void update2(int pos, int x, int y, int id, long long valor){
		if(x==y){
			if(x==id){
				T[pos].total = valor;
				T[pos].valor= valor;
				T[pos].valorIzq = valor;
				T[pos].valorDer = valor;
				T[pos].nulo = 0;
			}
		}
		else{
			if(x<=id && id<=y){
				update2(pos*2, x,x+int((y-x)/2), id, valor);
				update2((pos*2)+1, x+int((y-x)/2)+1,y, id, valor);
				T[pos]= funcion(T[pos*2], T[(pos*2)+1]);
			}
		}
	}
	
	int query(int i, int j){
		struct nodo C = subquery(1,0,vect.size()-1,i,j);
		return C.valor;
	}

	struct nodo subquery(int pos, int x, int y, int i, int j){
		if(i<=x && y<=j)
		return T[pos];
		else if(j<x || i>y){
			struct nodo C;
			C.nulo = 1;
			return C;
		}
		else
		return funcion(subquery((pos*2), x,x+int((y-x)/2), i,j), subquery((pos*2)+1, x+int((y-x)/2)+1,y, i,j));
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,q,op,x,y,i;
	long long ans;
	cin>>n;
	vector<long long> V(n);
	SegmentTree segment_tree;
	for(i=0; i<n; i++){
		cin>>V[i];
	}
	segment_tree.built(V);
	cin>>q;
	while(q--){
		cin>>op>>x>>y;
		if(op==0){
			segment_tree.update(x-1,y);
		}
		else{
			ans= segment_tree.query(x-1,y-1);
			cout<<ans<<endl;
		}
	}
}
