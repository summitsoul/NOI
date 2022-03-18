#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 100010
using namespace std;
int n, m, ans = 0, cnt = 0;
int head[N], fa[N];
struct edge{
	int u, v, w;
}e[N << 1];

inline int read(){
	int s = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){s = s * 10 + ch - '0'; ch = getchar();}
	return s;
}

bool cmp(edge a, edge b){return a.w < b.w;}

int find(int x){	//!!!�ǳ���Ҫ,���鼯ģ�� 
	if(x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
}

void Kruskal(){	//Kruskalģ�� 
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++){
		int x = find(e[i].u), y = find(e[i].v);
		if(x == y) continue;	//����������Ѿ���ͨ��ô���� 
		ans += e[i].w;
		fa[x] = y;	//��������ϲ� 
		if(++cnt == n - 1) break; //��n - 1����ʱ���� 
	}
}

int main(){
	n = read(); m = read();
	for(int i = 1; i <= m; i++){
		int x, y, z; 
		x = read(); y = read(); z = read();
		e[i].u = x; e[i].v = y; e[i].w = z;
	}
	Kruskal();
	printf("%d\n", ans);
	return 0;
}