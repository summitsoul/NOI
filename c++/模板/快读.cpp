#include<cstdio>
using namespace std;

inline int read(){
	int x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -1; c = getchar();}
	while(c >= '0' || c <= '9'){x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}

int main(){
	int n; n = read();
	printf("%d\n", n);
	return 0;
}
