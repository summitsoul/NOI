#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int a[41];
int f[200010];
long long ans = 0;

inline int read(){
	int s= 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){s = s * 10 + ch - '0'; ch = getchar();}
	return s; 
}

int main(){
	n = read(); k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	f[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = k; j >= a[i]; j--)
			f[j] += f[j - a[i]];
	for(int i = 0; i <= k; i++) ans += f[i];
	printf("%lld", ans);
	return 0;
}
