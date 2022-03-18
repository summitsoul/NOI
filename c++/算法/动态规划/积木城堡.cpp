#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, x;
int a[1010], ans[100010], maxn = 0;
bool f[100010];
inline int read(){
	int s = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){s = s * 10 + ch - '0'; ch = getchar();}
	return s;
}

int main(){
	n = read();
	for(int i = 1; i <= n; i++){
		memset(f, 0, sizeof(f));
		int h = 0, sum = 0;
		while(1){
			scanf("%d", &x);
			if(x < 0) break;
			a[++h] = x;
			sum += x;
		}
		f[0] = 1;
		a[0] = h;
		maxn = max(maxn, sum);
		for(int i = 1; i <= h; i++)
			for(int j = sum; j >= a[i]; j--)
				if(f[j - a[i]] && !f[j])
					f[j] = 1, ans[j]++;	
	}
	for(int i = maxn; i >= 0; i--)
		if(ans[i] == n){
			printf("%d\n", i);
			return 0;
		}
	printf("0\n");
	return 0;
}
