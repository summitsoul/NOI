#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
double n, m, k;

void print(double x){
	printf("%.1f", x * 100);
	exit(0);
}

void solve(double l, double r){
	double mid = (l + r) / 2, u = r - l;
	double a = n;
	if(u < 0.0001) print(mid);
	for(int i = 1; i <= k; i++) a = a * (1 + mid) - m;
	if(a > 0) solve(l, mid);
	if(a < 0) solve(mid, r);
	if(a == 0) print(mid);
}

int main() {
	cin >> n >> m >> k;
	solve(0, 5);
	return 0;	
 }
