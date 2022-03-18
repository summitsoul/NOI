#include<bits/stdc++.h>
using namespace std;
int t,n,zhu[55],jia[55],boy[55],girl[55],mp[55][55];

int dfs(int x){
	for(int i=1;i<=n;i++){
		if(!girl[i]&&mp[x][i]&&zhu[i]){
			girl[i]=1;
			if(!boy[i]||dfs(boy[i])){
				boy[i]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(zhu,1,sizeof(zhu));
		memset(jia,0,sizeof(jia));
		memset(boy,0,sizeof(boy));
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++)	cin>>zhu[i];
		for(int i=1;i<=n;i++){
			int k;	cin>>k;
			if(zhu[i])	jia[i]=k;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
			if(zhu[i])	mp[i][i]=1;
		}
	int flag=1;
	for(int i=1;i<=n;i++){
		memset(girl,0,sizeof(girl));
		if(!jia[i] && dfs(i)==0){flag=0; break;}
		}
	if(!flag)cout<<"T_T"<<endl;
	else cout<<"^_^"<<endl;
	}
}
/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define N 100
using namespace std;
 
int a[N],match[N],p[N],as[N],kn[N][N];
int n;

int dfs(int x){//二分图匹配模板
	fr(i,1,n)
		if(!p[i] && kn[x][i] && a[i]){//若此人未匹配过且认识此人且此人是学生
			p[i]=1;
			if(!match[i] || dfs(match[i])){
				match[i]=x;
				return 1;
			}
		}
	return 0;
}

int main(){
	int i,j,k,m,t;
	cin>>t;
	while(t--){
		memset(a,1,sizeof(a));//初始化所有人均回家
		memset(as,0,sizeof(as));
		memset(match,0,sizeof(match));
		memset(kn,0,sizeof(kn));
		cin>>n;
		fr(i,1,n)
			scanf("%d",&a[i]);
		fr(i,1,n){
			scanf("%d",&k);
			if(a[i])as[i]=k;//如果是学生则保存k
		}
		fr(i,1,n){
			fr(j,1,n)
				scanf("%d",&kn[i][j]);
			if(a[i])kn[i][i]=1;//学生可以睡自己的床
		}
		int flag=1;
		fr(i,1,n){
			memset(p,0,sizeof(p));
			if(!as[i] && dfs(i)==0){flag=0;break;}//如果这个人不回家并且他找不到床，则退出，flag变成0
		}
		if(!flag)cout<<"T_T"<<endl;
		else cout<<"^_^"<<endl;
	}
	return 0;
}*/






