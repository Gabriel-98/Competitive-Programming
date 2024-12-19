#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct SegmentTree{

	int n;
	vector<int> vect;
	vector<long long> T;

	long long funcion(long long a, long long b){
		return a + b;
	}

	void build(vector<int> V){
		vect.clear();
		vect.resize(V.size());
		for(int i=0; i<vect.size(); i++){
			vect[i] = V[i];
		}
		n = 4 * (V.size());
		T.clear();
		T.resize(n,0);
		build2(1,0,vect.size()-1);
	}

	void build2(int pos, int i, int j){
		if(i==j)
		T[pos] = vect[i];
		else{
			build2(2*pos, i, (i+j)/2);
			build2(2*pos+1, (i+j+2)/2, j);
			T[pos] = funcion(T[2*pos], T[2*pos+1]);
		}
	}

	void update(int id, int valor){
		vect[id] = valor;
		update2(1,0,vect.size()-1,id,valor);
	}

	void update2(int pos, int i, int j, int id, int valor){
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

	long long query(int i, int j){
		return query2(1, 0,vect.size()-1, i,j);
	}

	long long query2(int pos, int x, int y, int i, int j){
		if(j<x || i>y)
		return 0;
		else if(i<=x && y<=j)
		return T[pos];
		else
		return funcion(query2(2*pos, x,(x+y)/2, i,j), query2(2*pos+1, (x+y+2)/2,y, i,j));
	}

	int querySearch(long long x){
		return querySearch2(1, 0, vect.size()-1, x);
	}

	int querySearch2(int pos, int i, int j, long long x){
		if(i == j)
		return i;
		if(T[2*pos] >= x)
		return querySearch2(2*pos, i, (i+j)/2, x);
		else{
			x -= T[2*pos];
			return querySearch2(2*pos + 1, (i+j+2)/2, j, x);
		}
	}

};

SegmentTree st;
long long total;
vector<int> V;

long long funcion(int m){
	long long a,b,ans;
	a = 0;
	b = 0;
	if(m > 0)
	a = st.query(0,m-1);
	if(m < V.size()-1)
	b = total - (a + V[m]);

	a += V[m] / 2;
	b += V[m] / 2;
	if(V[m] % 2 == 1){
		if(a <= b)
		a++;
		else
		b++;
	}
	ans = abs(a-b);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,q,x,y,k,ans,i,j;
	long long z;
	cin>>n>>q;
	total = 0;
	for(i=0; i<n; i++){ cin>>x; V.push_back(x);	total += V[i]; }
	st.build(V);
	for(i=0; i<q; i++){
		cin>>x>>y;
		st.update(x,y);
		total -= V[x];
		V[x] = y;
		total += V[x];

		z = total / 2;
		if(total % 2 == 1)
		z++;
		k = st.querySearch(z);
		ans = k;

		for(j=1; j>=-1; j--){
			if(0 <= (k + j) &&  (k + j) < V.size()-1){
				if(funcion(k+j) <= funcion(ans))
				ans = k+j;
			}
		}

		cout<<ans<<endl;
	}
}