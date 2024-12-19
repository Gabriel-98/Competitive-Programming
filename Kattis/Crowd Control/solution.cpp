#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct edge{
    int x,y,w,id;
};

const int maxNodos = 2000;
int numeroNodos;
vector<struct edge> aristas(2000);
list<struct edge> Grafo[maxNodos];
list<int> sequence;
vector<int> ans,ans2;
set<int> T;

vector<int> S(maxNodos),P(maxNodos),D(maxNodos),A(maxNodos), ars(maxNodos);

void dijkstra(){
    int x,y,w,id,i;
    list<struct edge>::iterator it;
    for(i=0; i<numeroNodos; i++){
        S[i] = 0;
        D[i] = -1;
        P[i] = -1;
        A[i] = -1;
    }
    queue<int> Q;
    Q.push(0);
    D[0] = 0;
    while(!Q.empty()){
        x = Q.front();
        Q.pop();
        S[x] = 1;
        for(it=Grafo[x].begin(); it!=Grafo[x].end(); it++){
            y = it->y;
            w = it->w;
            id = it->id;
            if(D[y] == -1 || (D[y] != -1 && min(D[x],w) > D[y])){
                if(x != 0)
                D[y] = min(D[x],w);
                else
                D[y] = w;
                P[y] = x;
                A[y] = id;
            	Q.push(y);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n,m,x,y,w,i;
    list<int>::iterator it;
    set<int>::iterator its;
    cin>>n>>m;
    numeroNodos = n;
    for(i=0; i<m; i++){
        cin>>x>>y>>w;
        aristas[i].x = x;
        aristas[i].y = y;
        aristas[i].w = w;
        aristas[i].id = i;
        struct edge A, B;
        A.x = x;
        A.y = y;
        A.w = w;
        A.id = i;
        B.x = y;
        B.y = x;
        B.w = w;
        B.id = i;
        Grafo[x].push_back(A);
        Grafo[y].push_back(B);
    }
    dijkstra();
    x = n-1;
    while(x != 0){
        sequence.push_back(x);
        ans.push_back(A[x]);
        x = P[x];
    }
    sequence.push_back(x);
    for(it=sequence.begin(); it!=sequence.end(); it++){
        T.insert(*it);
    }   
    for(i=0; i<m; i++){
        its = T.find(aristas[i].x);
        if(its == T.end()){
            its = T.find(aristas[i].y);
            if(its == T.end()){
                ans.push_back(i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(i=0; i<m; i++){
        ars[i] = 0;
    }
    for(i=0; i<ans.size(); i++){
        ars[ans[i]] = 1;
    }
    for(i=0; i<m; i++){
        if(ars[i] == 0)
        ans2.push_back(i);
    }
    if(ans2.size() == 0)
    cout<<"none"<<endl;
    else{
        for(i=0; i<ans2.size(); i++){
            if(i > 0)
            cout<<" ";
            cout<<ans2[i];
        }
        cout<<endl;
    }
}