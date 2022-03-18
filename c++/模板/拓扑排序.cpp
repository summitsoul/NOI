#include<queue>
#include<vector>
#include<cstdio>
#define N 10010
using namespace std;
int n, m, cnt = 0;
int head[N], in[N];
queue<int> q;
vector<int> qq;
struct edge{
	int next, to;
}e[N << 1];

void add(int u, int v){
	e[++cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}

void sort(){
	int tot = 0;
	for(int i = 1; i <= n; i++)
		if(in[i] == 0) q.push(i), qq.push_back(i);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = e[u].next){
			int v = e[u].to;
			in[v]--;
			if(in[v] == 0){
				q.push(v);
				qq.push_back(v);
			}
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		int u, v; scanf("%d %d", &u, &v);
		add(u, v); 
		in[v]++; //�����������¼��ȵ� 
	}
	sort();
	for(int i = 0; i < qq.size(); i++)
		printf("%d ", qq[i]);
	return 0;
}