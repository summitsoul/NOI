#include<bits/stdc++.h>
using namespace std;

int l, w, n, ans; 
struct S{
	int x, y;
}s[5010];

int read(){
	int a = 0, f = 1;
	char c = getchar();
	while(c < '0' or c > '9'){if(c == '-') f = -1; c = getchar();}
	while(c >= '0' and c <= '9'){a = (a << 1) + (a << 3) + c - '0';c = getchar();}
	return a * f;
}

bool cmp1(S a , S b){
	if(a.x != b.x) return a.x < b.x;
	else return a.y < b.y; 
}

bool cmp2(S a , S b){
	if(a.y != b.y) return a.y < b.y;
	else return a.x < b.x ; 
}


int main(){
    l = read() , w = read() , n = read();   
    for(int i = 1; i <= n; i++) s[i].x = read() , s[i].y = read();
    s[++ n].x = 0 , s[n].y = 0;
	s[++ n].x = 0 , s[n].y = w;
	s[++ n].x = l , s[n].y = 0;
	s[++ n].x = l , s[n].y = w;
    int x1, x2, y1, y2;
    sort(s + 1, s + n + 1, cmp1);
    for(int i = 1; i <= n; i ++){
    	x1 = s[i].x, y1 = 0, y2 = w;
    	for(int j = i + 1; j <= n; j++){
				x2 = s[j].x;
				ans = max(ans, (x2 - x1) * (y2 - y1));
	    		if(s[j].y < s[i].y) y1 = max(y1, s[j].y);
	    	    else y2 = min(y2, s[j].y);
		}
	}
    for(int i = n; i >= 1; i--){
    	x1 = s[i].x, y1 = 0, y2 = w;
    	for(int j = i - 1; j >= 1; j--){
	    		x2 = s[j].x;
				ans = max(ans, (x1 - x2) * (y2 - y1));
				if(s[j].y < s[i].y) y1 = max(y1, s[j].y);
	    	    else y2 = min(y2, s[j].y); 
		}
	}
	sort(s + 1, s + n + 1, cmp2); 
	for(int i = 1; i <= n - 1; i++)
		ans = max(ans, l * (s[i + 1].y - s[i].y));
	printf("%d", ans);
	return 0;
}