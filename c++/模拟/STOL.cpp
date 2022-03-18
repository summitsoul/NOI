#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int r, s, ans = 0;
int a[410][410], sum[410][410];

int main(){
	char ch;
	scanf("%d %d", &r, &s);
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= s ; j++){
			cin >> ch;
			if(ch == '.') a[i][j] = 0;
			else a[i][j] = 1;
		}
	}
	for(int i = 1; i <= r + 1; i++) a[i][0] = a[i][s + 1] = 1;
	for(int i = 1; i <= s + 1; i++) a[0][i] = a[r + 1][i] = 1;
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= s; j++)
			if(!a[i][j]){
				if(a[i - 1][j]) sum[i][j] = 1;
				else sum[i][j] = sum[i - 1][j] + 1;
			} 
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= s; j++){
			int x = j, minn = 0x7f;
			while(!a[i][x]){
				minn = min(sum[i][x], minn);
				ans = max(ans, (x - j + 1 + minn) << 1);
				x++;
			}
		}
	if(ans == 0) printf("0\n");
	else printf("%d\n", ans - 1);
	return 0;
}
 
