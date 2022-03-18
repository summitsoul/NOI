#include<cstdio>
using namespace std;
int a, b, c, h, n, sum = 0, cnt = 0;
struct node{
    int x, y;
}p[100010];

int main(){
    scanf("%d", &n); h = 1;
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0){
            p[++cnt].x = b; p[cnt].y = c;
            sum += b;
        }
        else{
            bool flag = 0;
            for(int i = h; i <= cnt; i++){
                if(c - p[i].y <= 45 && b <= p[i].x){
                    flag = 1; p[i].x = -1; break;
                }
                else if(c - p[i].y > 45)
                    h = i + 1;
            }
            if(!flag) sum += b;
        }
    }
    printf("%d\n", sum);
    return 0;
}