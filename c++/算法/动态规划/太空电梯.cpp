#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n,ans=0;
bool f[410];
int cnt[410][200010];
struct node{
	int h,c,a;
}e[200010];

bool cmp(node x,node y){return x.a<y.a;}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	
		cin>>e[i].h>>e[i].a>>e[i].c;
	sort(e+1,e+n+1,cmp);
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=e[i].h;j<=e[i].a;j++)
			if(f[j-e[i].h]&&!f[j]&&cnt[i][j-e[i].h]<e[i].c){
				cnt[i][j]=cnt[i][j-e[i].h]+1;
				f[j]=1;
				ans=max(ans,j);
			}
	cout<<ans<<endl;
	return 0;
}
