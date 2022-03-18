#include<bits/stdc++.h>
using namespace std;
int n,k,sum=0;
int farm[110][110];
int father[110];

struct f1{
	int x,y,t;
}f[110];

int cmp(const f1 &a,const f1 &b){return a.t<b.t;}

int find(int x){return father[x]==x?x:father[x]=find(father[x]);}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>farm[i][j];
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++){
			f[k].x=j;	f[k].y=i;	f[k].t=farm[i][j];	k++;	
		}
	sort(f,f+n+1,cmp);
	for(int i=1;i<=n;i++)	father[i]=i;
		for(int i=1;i<=n;i++){
		int fx=find(f[i].x),fy=find(f[i].y);
		if(fx!=fy)	father[fx]=fy,n--;
		if(n==1){cout<<f[i].t<<endl;return 0;} 
	}
} 
