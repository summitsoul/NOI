#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct farm{
    int x1, x2, y1, y2;
}f[50010];

bool cmp(farm x, farm y){return x.x1 < y.x1;}

int main(){
    scanf("%d", &n);
    int ans = n;
    for(int i = 1; i <= n; i++)
        scanf("%d %d %d %d", &f[i].x1, &f[i].y1, &f[i].x2, &f[i].y2);
    sort(f + 1, f + n + 1, cmp);
    for(int L = 1, R = 2; R <= n; R++){
        while(f[L].x2 <= f[R].x1) L++;
        for(int i = L; i < R; i++)
        	if(f[i].y1 < f[R].y1 && f[i].x2 > f[R].x2 && f[i].y2 > f[R].y2){
            	ans--; break;
    	}
    }
    printf("%d\n", ans);
    return 0;
}
