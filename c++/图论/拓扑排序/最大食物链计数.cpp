#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0,ru[5010],chu[5010];	//生物种类n和吃与被吃的关系数m
int f[5010];	//记录 
int mp[5010][5010];
queue<int> q;

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		mp[a][b]=1;
		chu[a]++;	ru[b]++;
	}
	for(int i=1;i<=n;i++)
		if(ru[i]==0){
			f[i]=1;
			q.push(i);
		}
	while(!q.empty()){
		int a=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(mp[a][i]==0) continue;
			f[i]+=f[a];
			f[i]%=80112002;
			ru[i]--;
			if(ru[i]==0){
				if(chu[i]==0){
					sum+=f[i];
					sum%=80112002;
					continue;
				}
				q.push(i);
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
