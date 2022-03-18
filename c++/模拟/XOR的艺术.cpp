#include<cstdio>
#include<iostream>
using namespace std;
int n, m;
int a[200010];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		char c; cin >> c;
		a[i] = c - '0';
	} 
	for(int i = 1; i <= n; i++) cout << a[i];
}
