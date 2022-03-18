#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
double h, s1, v, l, k;

int main(){
    scanf("%lf %lf %lf %lf %lf %d", &h, &s1, &v, &l, &k, &n);
    double t_max = sqrt(h / 5);
    double t_min = sqrt((h - k) / 5);
    int i_b = int(s1 - t_min * v + l), i_e = int(s1 - t_max * v);
    i_b = min(i_b, n); i_e = max(i_e, 0);
    printf("%d\n", i_b - i_e);
    return 0;
}