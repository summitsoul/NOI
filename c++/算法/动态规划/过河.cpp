#include<cmath>
#include<cstdio>
#include<iostream>
#define N 1000000001
using namespace std;
int l,s,t,m;	//青蛙一次跳跃的最小距离,最大距离及桥上石子的个数
int stone[N],f[N];

int main(){
	cin>>l; cin>>s>>t>>m;
	for(int i=1;i<=m;i++){
		cin>>stone[i]; f[stone[i]]=1;
	} 
	for(int i=1;i<=l;i++){
		int sum=0;
		for(int j=s;j<=t;j++)
			if((i-j)>=0&&f[i-j]==0) sum++;
		if(sum==s-t+1||sum==i) f[i]++;
	}
	cout<<f[l]<<endl;
	return 0;
}
