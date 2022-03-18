#include<cmath>
#include<cstdio>
using namespace std;
int n, k;
int x[22];

bool isprime(int n){
	int s = sqrt(double(n));
	for(int i = 2; i <= s; i++)
		if(n % i == 0) return false;
	return true;
}

int rule(int l, int a_sum, int s, int e){
	if(l == 0) return isprime(a_sum);
	int sum = 0;
	for(int i = s; i <= e; i++) sum += rule(l - 1, a_sum + x[i], i + 1, e);
	return sum;
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &x[i]);
	printf("%d\n", rule(k, 0, 0, n - 1));
	return 0;
}
