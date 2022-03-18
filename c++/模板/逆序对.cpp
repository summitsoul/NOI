#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int rnk[500010],tree[500010];
struct point{
	int num,pos;
}a[500010];

inline bool cmp(point x,point y){return x.pos<y.pos;}

void insert(int p,int d){for(;p<=n;p+=p&-p) tree[p]+=d;}

int query(int p){
	int sum=0;
	for(;p;p-=p&-p)
		sum+=tree[p];
	return sum;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].pos,a[i].num=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) rnk[a[i].num]=i;
	for(int i=1;i<=n;i++){
		insert(rnk[i],1);
		ans+=i-query(rnk[i]);
	}
	cout<<ans<<endl;
	return 0;
}
