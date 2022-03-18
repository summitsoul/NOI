#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, sum = 0;

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= min(n, m); i++){
		int a = i, b = i;
		while(sum < m){
			sum += a; a++;
		}
		if(sum == m) printf("[%d,%d]\n", b, a - 1);
		sum = 0;
	}
	return 0;
}
