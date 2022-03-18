#include<cmath>
#include<iostream>
using namespace std;
int n;
int minn=0x3f3f3f;
int mp[110][110];
bool rem[110];

void dfs(int x,int y,int sum,int step){
	if(step==n&&x==y) minn=min(minn,sum);
	for(int i=1;i<=n;i++){
		if(rem[i]) continue;
		else if(mp[y][i]!=0&&mp[i][y]==0){
			rem[i]=1;
			dfs(x,i,sum+mp[y][i],step+1);
			rem[i]=0;
		}
		else if(mp[y][i]==0&&mp[i][y]!=0){
			rem[i]=1;
			dfs(x,i,sum,step+1);
			rem[i]=0;
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y,z;	cin>>x>>y>>z;
		mp[x][y]=0;
		mp[y][x]=z;
	}
	dfs(1,1,0,0);
	cout<<minn<<endl;
	return 0;
}
