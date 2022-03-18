#include<cstdio>
using namespace std;
int n;
int a[10010], b[10010], c[10010];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		b[i] = 1;
		for(int j = 1; j < i; j++){
			if(a[i] >= a[j]){
				if(b[i] <= b[j]){
					b[i] = b[j] + 1;
					c[i] = c[j];
				}
			}
		}
		c[i] += a[i];
	}
	for(int i = 1; i <= n; i++) printf("%d ", c[i]);
	return 0;
}
