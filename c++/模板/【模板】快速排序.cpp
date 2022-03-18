#include<cstdio>
using namespace std;

inline int read(){
	int x = 0; bool flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') flag = 0; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
	if(flag) return x;
	return ~(x - 1);
}

int main(){
	int n; n = read();
}
