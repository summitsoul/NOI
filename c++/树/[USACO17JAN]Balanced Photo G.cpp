#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,sum=0;
int h[10000010];
int c[100005];

inline int read()
{
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9') {if(c=='-')flag=1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x+(x<<2)<<1)+ c-'0';c=getchar();}
    return flag?-x:x;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++)	h[i]=read();
	for(int i=1;i<=n;i++){
		int sum1=0,sum2=0;
		for(int j=1;j<=i;j++) if(h[i]<h[j]) sum1++;
		for(int j=i;j<=n;j++) if(h[i]<h[j]) sum2++;
		if(min(sum1,sum2)*2<max(sum1,sum2)) sum++;
	}
	cout<<sum<<endl;
	return 0;
}
