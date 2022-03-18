#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
const double pi = 3.1415926535;
double n,X,Y,X1,Y1,ss,ans1;
double x[10],y[10],r[10];
bool s[10];

double cal(int i){
	double s1 = min(abs(x[i] - X), abs(x[i] - X1));
	double s2 = min(abs(y[i] - Y), abs(y[i] - Y1));
	double ans = min(s1, s2);
	for(int j = 1; j <= n; j++){
		if(i != j && s[j]){
			double d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			ans = min(ans, max(d - r[j], 0.0));
		}
	}
	return ans;
}

void dfs(int k, double sum){
	if(k > n){ans1 = max(ans1, sum); return ;}
	for(int i = 1; i <= n; i++)
		if(!s[i]){
			r[i] = cal(i); s[i] = true;
			dfs(k + 1, sum + r[i] * r[i] * pi);
			s[i] = 0;
		}
}

int main(){
	cin >> n;
	cin >> X >> Y >> X1 >> Y1;
	ss = abs(X - X1) * abs(Y - Y1);
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i]; 
	dfs(1, 0);
	printf("%d", int(ss - ans1 + 0.5));
	return 0;
}
