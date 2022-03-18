#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
inline long long read(void){
    long long x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return f*x;
}

const int maxn=1000005;

long long n,a[maxn],sum[maxn],ave,ans;

int main(){
    n=read();
    for(register int i=1;i<=n;i++){
        a[i]=read();ave+=a[i];
    }
    ave/=n;
    for(register int i=1;i<=n;i++)a[i]-=ave;
    for(register int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    sort(sum+1,sum+n+1);
    long long t=sum[(n+1)>>1];
    for(register int i=1;i<=n;i++)ans+=abs(t-sum[i]);
    printf("%lld\n",ans);
    return 0;
}