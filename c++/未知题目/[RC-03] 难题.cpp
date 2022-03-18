#include<cstdio>
using namespace std;
long long two[64];

int main(){
	long long n; scanf("%lld",&n);
	if(n==1){printf("1"); return 0;} 
	two[1]=2;
	for(int i=2;i<=64;i++) two[i]=2*two[i-1];
	for(int i=2;i<=63;i++)
		if(n>=two[i-1]&&n<two[i]){
			 printf("%lld",2*(two[i]-1));return 0;
		}
	printf("36893488147419103230");
	return 0;
}
