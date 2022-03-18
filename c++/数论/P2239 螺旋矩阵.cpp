#include<cstdio>
#include<algorithm>
using namespace std;
int n, i, j, ans = 0, minn; 

int main(){
	scanf("%d %d %d", &n, &i, &j);
	minn = min(i, min(j, min(n - i + 1, n - j + 1)));
	if(i <= j) ans = minn * (4 * (n - 1) - 4 * minn) + 10 * minn - 4 * n - 3 + i + j;
	else ans = minn * (4 * n - 4 * minn) + 2 * minn + 1 - i - j;
	printf("%d\n", ans);
	return 0;
}
