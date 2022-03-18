#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll a[5];
ll l[7];

int main(){
	int q; scanf("%d", &q);
	while(q--){
		scanf("%lld %lld %lld %lld", &a[1], &a[2], &a[3], &a[4]);
		if(a[1] == a[2] && a[1] == a[3] && a[1] == a[4]){printf("1\n"); continue;}
		sort(a + 1, a + 5);
		if(((a[1] + a[3]) == (a[2] + a[4]))||((a[1] + a[4]) == (a[2] + a[3]))){
			if(a[1] == a[2]){printf("4\n"); continue;} 
			else{printf("8\n"); continue;} 
		}
		printf("0\n");
	}
	return 0;
}
