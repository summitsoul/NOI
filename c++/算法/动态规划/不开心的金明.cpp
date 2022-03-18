#include<cstdio>
#include<algorithm>
using namespace std;
int n,w,ans = 0;

struct thing{
	int v,p;
}t[110];

bool cmp(thing a, thing b){return a.p > b.p;}

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') w = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = s * 10 + ch - '0'; ch = getchar();}
	return s * w;
}

int main(){
	n = read(); w = read();
	for(int i = 1; i <= n; i++){t[i].v = read(); t[i].p = read();}
	sort(t + 1, t + n + 1, cmp);
	int sum1 = 0, sum2 = 0;
	for(int i = 1; i <= n; i++){
		if(sum1 + t[i].v <= w){
			sum1 += t[i].v; sum2 += t[i].p; 
			ans = max(ans, sum2);
		} 
	}
	printf("%d\n", ans);
	return 0;
}
