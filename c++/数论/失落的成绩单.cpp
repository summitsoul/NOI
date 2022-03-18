#include<cmath>
#include<cstdio>
#define p sqrt(2) - 1
using namespace std;
int n, m;
double d, a1, an;

double c(int x){return (x & 1) ? -1 : 1;}

double f(int x){return pow(p, x) - c(x) * pow(p + 2, x);}

int main(){
	scanf("%d %d", &n, &m);
	scanf("%lf %lf %lf", &d, &a1, &an);
	if(m == 0) printf("0.000");
	else printf("%.3lf", ((an - d) * f(m - 1) + c(m - 1) * (a1 - d) * f(n - m)) / f(n - 1) + d);
}
