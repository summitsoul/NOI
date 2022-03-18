#include<bits/stdc++.h>
using namespace std;
long long b,q,k;

long long quickpower(long long a, long long b){
	long long ans = 1 , base = a;
	while(b > 0){
		if(b & 1) ans = ans * base % k;
		base = base * base % k;
		b >>= 1;
	}
	return ans;
}

int main(){
	cin >> b >> q >> k;
	int ans = quickpower(b, q);
	printf("%lld^%lld mod %lld=%lld", b, q, k, ans % k);
	return 0;
}

long long quick(int a, int b){
	int ans = 1, base = a;
	while(b > 0){
		if(k & 1) ans = ans * base % k;
		base *= base % k;
		b >>= 1;
	}
	return ans;
}