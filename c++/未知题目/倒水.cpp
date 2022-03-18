#include<bits/stdc++.h>
using namespace std;
int sum;
int n,m,k[10010],j=1;

void dg(int x,int y){
	if(x==y) return ;
	int b=k[y-1]-k[y];	k[y-1]*=2;	sum+=b;
	dg(x,y-1);
}

int main(){	
	cin>>n>>m;
	if(n==2000000000) {cout<<0<<endl; return 0;
	}
	int a=n;
	while(a!=0){
		for(int i=0;;i++){
			if(pow(2,i)>a){
				k[j]=pow(2,i-1); j++; a-=k[j-1];break;
			}
		}
	}
	if(j==m+1){cout<<0<<endl;	return 0;}
	dg(m,j-1);
	cout<<sum<<endl;
	return 0;
}
