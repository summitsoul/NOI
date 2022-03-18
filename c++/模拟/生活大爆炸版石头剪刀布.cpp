#include<cstdio>
using namespace std;
int n,a,b;
int sum1=0,sum2=0;
int na[210],nb[210];

int main(){
	scanf("%d %d %d", & n, & a, & b);
	for(int i=1;i<=a;i++) scanf("%d", & na[i]);
	for(int i=1;i<=b;i++) scanf("%d", & nb[i]);
	for(int i=1;i<=n;i++){
		int x=na[i%a],y=nb[i%b];
		if(i%a==0) x=na[a]; if(i%b==0) y=nb[b];
		printf("%d %d\n",x,y);
		if(((x==0)&&((y==2)||(y==3)))||((x==1)&&(y==3))||((x==2)&&(y==4))||((x==3)&&(y==4))) sum1++;
		if(((y==0)&&((x==2)||(x==3)))||((y==1)&&(x==3))||((y==2)&&(x==4))||((y==3)&&(x==4))) sum2++;
	}
	printf("%d %d\n",sum1,sum2);
	return 0;
}
