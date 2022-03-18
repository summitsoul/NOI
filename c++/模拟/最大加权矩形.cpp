#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int mp[125][125], sum[125][125], ans[125][125];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			scanf("%d", &mp[i][j]);
			sum[i][j] = sum[i][j - 1] + mp[i][j];
			ans[i][j] = sum[i][j] + ans[i - 1][j];
		}
	int mx=-1000010;
    for(int x1=1;x1<=n;x1++)
    	for(int y1=1;y1<=n;y1++)
    		for(int x2=1;x2<=n;x2++)
    			for(int y2=1;y2<=n;y2++){
    				if(x2<x1 || y2<y1) continue;
    				mx=max(mx,ans[x2][y2]+ans[x1-1][y1-1]-ans[x2][y1-1]-ans[x1-1][y2]);
				}
    printf("%d\n", mx);
	return 0;
}
