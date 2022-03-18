#include<cstdio>
using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		long long n, k;
		scanf("%lld %lld", &n, &k);
		printf("%d\n", (n & k) == k);
	}
	return 0;
}
