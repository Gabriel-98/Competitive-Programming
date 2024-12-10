/*
Solucion
Hay una secuencia oculta tras la secuencia de resultados, cada elemento de la secuencia oculta
corresponde al incremento con respecto al incremento al valor anterior, esta seceuencia oculta
se aplica de forma independiente a las posiciones pares e impares, estando en los pares un poco mas
desplazada
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t;
	long long n,k,ans;
	cin>>t;
	while(t--){
		cin>>n;
		ans = 0;
		if(n % 2 == 0){
			n /= 2;
			if(n >= 3){
				n -= 2;
				k = n / 6;
				ans += (3*k*(k+1)) - k;
				n -= 6*k;
				ans += n*(k+1);
				if(n >= 2)
				ans--;
			}
		}
		else{
			n /= 2;
			if(n >= 1){
				k = n / 6;
				ans += (3*k*(k+1)) - k;
				n -= 6*k;
				ans += n*(k+1);
				if(n >= 2)
				ans--;
			}
		}
		cout<<ans<<endl;
	}
}
 
// codigo para identificar la secuencia oculta
/*
int funcion(int n){
	int ans = 0, inf, sup, k, m;
	for(int a = 1; a <= n/3; a++){
		m = n / 2;
		m++;
		inf = max(a, m-a);
		sup = (n-a) / 2;
		k = sup - inf + 1;
		if(k >= 0)
		ans += k;
	}
	return ans;
}
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n,i;
	cout<<"Primeros 100 resultados"<<endl;
	for(i=1; i<=100; i++){
		cout<<i<<"\t"<<funcion(i)<<endl;
	}
	cout<<"Secuencia oculta"<<endl;
	for(i=3; i<=100; i+=2){
		cout<<i<<"\t"<<funcion(i) - funcion(i-2) << "\t" << funcion(i+3) - funcion(i+1) <<endl;
	}
}*/
