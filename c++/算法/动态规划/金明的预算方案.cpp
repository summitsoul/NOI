#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
int mw[30010], mv[30010], fw[30010][3], fv[30010][3], f[30010];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int v, q, p;
        scanf("%d %d %d", &v, &p, &q);
        if(!q){
            mv[i] = v;
            mw[i] = v * p;
        }
        else{
            fw[q][0]++;
            fw[q][fw[q][0]] = v;
            fv[q][fw[q][0]] = v * p;
        }
    }
    for(int i = 1; i <= m; i++)
        for(int j = n; mv[i] != 0 && j >= mv[i]; j--){
            f[j] = max(f[j], f[j - mv[i]] + mw[i]);
            if(j >= mv[i] + fw[i][1]) f[j] = max(f[j], f[j - mv[i] - fw[i][1]] + mw[i] + fv[i][1]);
            if(j >= mv[i] + fw[i][2]) f[j] = max(f[j], f[j - mv[i] - fw[i][2]] + mw[i] + fv[i][2]);
            if(j >= mv[i] + fw[i][1] + fw[i][2]) 
                f[j] = max(f[j], f[j - mv[i] - fw[i][1] - fw[i][2]] + mw[i] + fv[i][1] + fv[i][2]);
        }
    printf("%d\n", f[n]);
    return 0;
}   