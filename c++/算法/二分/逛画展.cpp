#include<cstdio>
#include<iostream>
const int N=1000010;
using namespace std;
int n,m,h=1,t=1,k=1,ans=N,l,r;
int paint[N],Q[2010];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&paint[i]);
	Q[paint[1]]=1; 
	while(h<=t&&t<=n){
		if(k==m){
			if(ans>t-h+1){
				ans=t-h+1;
				l=h; r=t;
			}
			Q[paint[h]]--;
			if(Q[paint[h]]==0) k--;
			h++;	
		}
		else{
			t++;
			Q[paint[t]]++;
			if(Q[paint[t]]==1) k++;
		}
	}
	printf("%d %d\n",l,r);
	return 0;
}
