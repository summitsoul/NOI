#include<cstdio>
using namespace std;

int main(){
	int a,b,sum = 0;
	scanf("%d %d", &a, &b);
	for(int i = 1; i <= b; i++)
	for(int i = a; i <= b; i++)
		for(int j = 1; j <= i; j++){
			if(j & 1) sum += -i / j;
			else sum += i / j;
		}
	printf("%d\n", sum);
	return 0;
}
