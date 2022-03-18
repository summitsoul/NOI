#include<cstdio>
using namespace std;
int L, n, k;
int a[100010];

bool er(int mid){
	int sum = 0;
	for(int i = 0; i <= n; i++){
		if(a[i + 1] - a[i] >= mid){
			sum += (a[i + 1] - a[i]) / mid;
			if((a[i + 1] - a[i]) % mid == 0){
				sum--;
			}
		}
		if(sum > k) return false;
	}
	return true;
}

int main(){
	scanf("%d %d %d", &L, &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d" ,&a[i]);
	a[0] = 0; a[n + 1] = L;
	int l = 0, r = L;
	while(l < r){
		int mid = (l + r) >> 1;
		if(er(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}
