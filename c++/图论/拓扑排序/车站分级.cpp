#include<bits/stdc++.h>
using namespace std;
int n,m,num=1,l=0;	//n����վm�˳���
int a[1010][1010],b[1010];	//ֹͣ�ĵط� 

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int h;cin>>h;
		for(int j=1;j<=h;j++){
			int k;
			cin>>k;
			a[i][k]=1;
		}
	}
	for(int i=1;i<=m;i++){
		int k=num;
		for(int j=1;j<=n;j++)
			if(a[i][j]==1){				
				if(i>1&&k==num&&b[j]==0&&j<=l)	num++;
				l=max(l,j);
				b[j]=1;
			}
	} 
	cout<<num<<endl;
}
