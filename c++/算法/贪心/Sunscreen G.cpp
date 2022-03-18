#include<cstdio>
#include<algorithm>
using namespace std;
int c, l, ans = 0;
struct cow{
	int mis, mas;
}a[2510];
struct sun{
	int l, t;
}s[2510];

bool cmp1(cow x, cow y){return x.mis > x.mis;}

bool cmp2(sun x, sun y){return x.l > y.l;}

int main(){
	scanf("%d %d", &c, &l);
	for(int i = 1; i <= c; i++)
		scanf("%d %d", &a[i].mis, &a[i].mas);
	sort(a + 1, a + c + 1, cmp1);
	for(int i = 1; i <= l; i++)
		scanf("%d %d", &s[i].l, &s[i].t);
	sort(s + 1, s + l + 1, cmp2);
	for(int i = 1; i <= c; i++)
		for(int j = 1; j <= l; j++)
			if(s[j].l >= a[i].mis && s[j].l <= a[i].mas && s[j].t){
				ans++; s[i].t--; break;
			}
	printf("%d\n", ans);
	return 0;
}
