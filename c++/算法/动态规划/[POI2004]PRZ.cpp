#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 16
using namespace std;
int a, b, t[N], w[N], T[1 << N], W[1 << N], dp[1 << N];

int main() {
	scanf("%d %d", &a, &b);
	for(int i = 1; i <= b; i++) scanf("%d %d", &t[i], &w[i]);
	for(int i = 0; i < (1 << b); i++) 
		for(int j = 1; j <= b; j++) 
			if(i & (1 << (j - 1))){
				T[i] = max(T[i],t[j]);
				W[i] += w[j];
			}
	memset(dp,0x3f,sizeof(dp));
	dp[0] = 0;
	for(int i = 0;i < (1 << b); i++) {
		for(int j = i; ; j = i & (j - 1)) {
			if(W[i ^ j] <= a) dp[i] = min(dp[i], dp[j] + T[i ^ j]);
			if(!j) break;
		}
	}
	printf("%d\n", dp[(1 << b) -1]);
	return 0;
}
