#include<cstdio>
using namespace std;
long long l, r;

long long sum(long long x){
	if(x <= 9) return x;
	long long a = x % 10;
	long long ans = x / 10 + 9;
	long long b = x; while(b >= 10) b /= 10;
	if(b > a) ans--;
	return ans;
}

int main(){
	scanf("%lld %lld", &l, &r);
	long long k = sum(r) - sum(l - 1);
	printf("%lld", k);
	return 0;
} 
