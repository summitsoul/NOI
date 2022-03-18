#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;	
int father[100010];
struct hh{
	int x,y,t;
}a[100010];

int cmp(const hh &a,const hh &b){return a.t<b.t;}

int find(int x){return father[x]==x?x:father[x]=find(father[x]);}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)	cin>>a[i].x>>a[i].y>>a[i].t;
	sort(a,a+m+1,cmp);
	for(int i=1;i<=n;i++)	father[i]=i;
	for(int i=1;i<=m;i++){
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx!=fy)	father[fx]=fy,n--,sum++;
		if(n==1){cout<<sum<<' '<<a[i].t<<endl;return 0;} 
	}
	cout<<-1<<endl;
	return 0;
} 
