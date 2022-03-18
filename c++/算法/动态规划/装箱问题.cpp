#include<cstdio>
#include<algorithm>
using namespace std;
int s, n;
int f[20010];
int w[40];

int main(){
	scanf("%d %d", &s, &n);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++)
		for(int j = s; j >= w[i]; j--)
			f[j] = max(f[j], f[j - w[i]] + w[i]); 
	printf("%d\n", s - f[s]);
	return 0;
}
