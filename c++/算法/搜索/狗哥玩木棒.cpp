#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[25],sum,m;
bool b[1010],flag=0;

bool cmp(int x,int y){return x>y;}

void dfs(int x,int y){
	if(!flag) return ;
	if(x>sum) return ;
	if(x==sum) x-=sum,y+=1;
	if(y==4) printf("yes\n"),flag=0;
	for(int i=1;i<=m;i++)
		if(!b[i]){
			b[i]=1;
			dfs(x+a[i],y);
			b[i]=0;
			if(x==0||x+a[i]==0) return ;
		}
}

int main(){
	int n; scanf("%d",&n);
	while(n--){
		sum=0; flag=1;
		memset(b,0,sizeof(b));
		scanf("%d",&m);
		for(int i=1;i<=m;i++) scanf("%d",&a[i]),sum+=a[i];
		sum/=4;
		sort(a+1,a+m+1,cmp);
		dfs(0,0);
		if(flag) printf("no\n");
	}
	return 0;
}
