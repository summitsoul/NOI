#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int x1, y, x2, y2, m1, m2;
double ans = 0.00;
int a[110],b[110],c[110],d[110];

int gcd(int m, int n){
	int ans;
	while(n > 0){
		ans = m % n;
		m = n;
		n = ans;
	}
	return m;
}

int main(){
	scanf("%d %d %d", &x1, &y, &m1);
	for(int i = 1; i <= m1; i++){char c; scanf("%d %c", &a[i], &c); if(c == Y) b[i] = } 
	scanf("%d %d %d", &x2, &y2, &m2);
	for(int i = 1; i <= m2; i++) scanf("%d %d", &c[i], &d[i]);
	int x = gcd(m1, m2) * min(m1, m2);
	ans = (double)sqrt((x1- x2) * (x1 - x2) + (y - y2) * (y - y2));
	for(int i = 1; i <= x; i++) ans = min(ans, (double)sqrt((a[i] - c[i])*(a[i] - c[i])+(b[i] - d[i])*(b[i] - d[i])));
	printf("%.2f",ans);
	return 0;
}
