#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
unsigned long long n, k, bk;
bool flag;

int main(){
	cin >> n >> k;
	bk = pow(2, n - 1);
	while(bk){
		if(!flag){
			if(k < bk) cout<< "0";
			else{
				cout << "1";
				k -= bk;
				flag = true;
			}
		}
		else{
			if(k < bk){
				cout << "1";
				flag = false;
			}
			else{
				cout << "0";
				k -= bk;
			}
		}
		bk >>= 1;
	}
	return 0;
}
