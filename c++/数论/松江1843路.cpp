#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn = 100010;
ll l, n, sum = 0, ans = 0;
struct node{
	ll x, r;
}a[maxn];

inline bool cmp(node a, node b){return a.x < b.x;}

int main(){
	scanf("%lld %lld", &l, &n);
	for(ll i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].r;
		sum += a[i].r;
	}
	sort(a + 1, a + n + 1, cmp);
	ll mid = (sum + 1) >> 1;
	sum = 0;
	for(ll i = 1; i <= n; i++){
		sum += a[i].r;
		if(sum >= mid){
			mid = i;
			break;
		}
	}
	for(ll i = 1; i <= n; i++)
		ans += abs((a[i].x- a[mid].x) * a[i].r);
	printf("%lld\n", ans);
	return 0;
}
