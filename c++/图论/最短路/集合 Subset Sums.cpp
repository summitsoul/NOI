#include<iostream>
#define int long long
using namespace std;
int n, sum = 0;
int f[1000010];

signed main(){
	cin >> n;
	sum = (n * (n + 1)) / 2;
	if(sum % 2 == 1){cout << 0 << endl; return 0;}
	else{
		f[0] = 1;
		sum /= 2;
		for(int i = 1; i <= n; i++)
			for(int j = sum; j >= i; j--)
				f[j] += f[j - i];
	}
	cout << f[sum] / 2 << endl;
	return 0;
}
