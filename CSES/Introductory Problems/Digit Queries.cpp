#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int CalculateSize(long long x){
	if(x == 0)
	return 1;

	int digits = 0;
	while(x > 0){
		digits++;
		x /= 10;
	}
	return digits;
}

string NumberToString(long long x){
	if(x == 0)
	return "0";

	stack<int> stk;
	while(x > 0){
		stk.push(x % 10);
		x /= 10;
	}
	string s = "";
	while(!stk.empty()){
		s.push_back('0' + stk.top());
		stk.pop();
	}
	return s;
}

long long AccumulatedDigits(long long x){
	int size = CalculateSize(x);
	long long last = round((long double)pow(10,size-1) - 1);
	long long ans = (x - last) * size;
	for(int i=1; i<size; i++){
		last = round((long double)pow(10,i-1));
		ans += 9 * last * (long long)i;
	
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int q; cin>>q;
	while(q--){
		long long k; cin>>k;
		long long first = 1, last = 1e17;
		while(first < last){
			long long middle = (first + last) / 2;
			if(AccumulatedDigits(middle) >= k) last = middle;
			else first = middle + 1;
		}
		long long number = first;
		k -= AccumulatedDigits(number-1);
		string s = NumberToString(number);
		cout<<s[k-1]<<endl;
	}
}