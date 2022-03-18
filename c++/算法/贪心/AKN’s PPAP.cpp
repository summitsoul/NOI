#include<cstdio>
using namespace std;
int a[100010], b[1000010];

int main(){
	int t; scanf("%d", &t);
	for(int c = 1; c <= t; c++){
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int k = 20; k >= 0; k--){
			int top = 0;
			for(int i = 1; i <= n; i++)
				if(a[i] & (1 << k)) b[++top] = a[i];
			if(top > 1){
				for(int i = 1; i <= top; i++) a[i] = b[i];
				n = top;
			}
		}
		printf("Case #%d: %d\n", c, (a[1] & a[2]));
	}
}
