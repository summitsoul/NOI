#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int mp[10][10];
bool l[10][10],h[10][10],q[10][10];

void prin(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
}

void dfs(int x,int y){
	if(mp[x][y]!=0)
		if(x==9&&y==9) prin();
		else if(x==9) dfs(x,y+1);
		else if(y==9) dfs(x+1,y);
	if(mp[x][y]==0){
		for(int i=1;i<=9;i++){
			if(h[x][i]&&l[y][i]&&q[(x-1)/3*3+(y-1)/3+1][i]){
				mp[x][y]=i;
				h[x][i]=false;	l[y][i]=false;	q[(x-1)/3*3+(y-1)/3+1][i]=false;
				if(x==9&&y==9) prin();
				if(y==9) dfs(x+1,1); else dfs(x,y+1);
				mp[x][y]=0;
				h[x][i]=true;	l[y][i]=true;	q[(x-1)/3*3+(y-1)/3+1][i]=true;
			}
		}
	}
}

int main(){
	memset(l,true,sizeof(l)); 
	memset(h,true,sizeof(h)); 
	memset(q,true,sizeof(q)); 
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++){
			cin>>mp[i][j];
			if(mp[i][j]>0){
			l[j][mp[i][j]]==false;
			h[i][mp[i][j]]==false;
			q[(i-1)/3*3+(j-1)/3+1][mp[i][j]]==false;
			}
		}
	dfs(1,1);
	return 0;
}
