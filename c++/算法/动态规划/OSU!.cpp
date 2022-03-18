#include<cstdio>
#include<iostream>
#define N 100010
using namespace std;
int n,sum;
double a[N],x1[N],x2[N],dp[N];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		x1[i] = (x1[i - 1] + 1) * a[i];
		x2[i] = (x2[i - 1] + 2 * x1[i - 1] + 1) * a[i];
		dp[i] = dp[i - 1] + (3 * x2[i - 1] + 3 * x1[i - 1] + 1) * a[i];
	}
	printf("%.1lf", dp[n]);
	return 0;
}
