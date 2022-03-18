#include<cstdio>
#define ll long long
using namespace std;
int n, m;
ll a[400010];
struct tree{
	int l, r;
	ll pre, add;
}t[400010];

void build(int p, int l, int r){
	t[p].l = l; t[p].r = r;
	if(l == r){t[p].pre = a[l]; return ;}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	t[p].pre = t[p << 1].pre + t[p << 1 | 1].pre;
}

void spread(int p){
	if(t[p].add){
		t[p << 1].pre += t[p].add * (t[p << 1].r - t[p << 1].l + 1);
		t[p << 1 | 1].pre += t[p].add * (t[p << 1 | 1].r - t[p << 1 | 1].l + 1);
		t[p << 1].add += t[p].add;
		t[p << 1 | 1].add += t[p].add;
		t[p].add = 0;
	}
}

void change(int p, int x, int y, int z){
	if(x <= t[p].l && y >= t[p].r){
		t[p].pre += (ll) z * (t[p].r - t[p].l + 1);
		t[p].add += z;
		return ;
	}
	spread(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if(x <= mid) change(p << 1, x, y, z);
	if(y > mid) change(p << 1 | 1, x, y, z);
	t[p].pre = t[p << 1].pre + t[p << 1 | 1].pre;
}

ll ask(int p, int x, int y){
	if(x <= t[p].l && y >= t[p].r) return t[p].pre;
	spread(p);
	int mid = (t[p].l + t[p].r) >> 1;
	ll ans = 0;
	if(x <= mid) ans += ask(p << 1, x, y);
	if(y > mid) ans += ask(p << 1 | 1, x,y);
	return ans;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	build(1, 1, n);
	for(int i = 1; i <= m; i++){
		int q, x, y, z;
		scanf("%d", &q);
		if(q == 1){
			scanf("%d %d %d", &x, &y, &z);
			change(1, x, y, z);
		}
		else{
			scanf("%d %d", &x, &y);
			printf("%lld\n", ask(1, x, y));
		}
	}
	return 0;
}
