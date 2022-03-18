#include<queue>
#include<cstdio>
using namespace std;
int n, m, x, ans = 0, s1= 1, s2 = 1;
priority_queue<int> q, qq;

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; i++) scanf("%d", &x), q.push(x);
	for(int i = 1; i < m; i++) scanf("%d", &x); qq.push(x);
	while(!q.empty() && !qq.empty()){
		if(q.top() > qq.top()){
			ans += q.top() * s2;
			s1++;
			q.pop();
		}
		else{
			ans += qq.top() * s1;
			s2++;
			qq.pop();
		}
	}
	while(!q.empty()){
		ans += q.top() * s2; q.pop();
	}
	while(!qq.empty()){
		ans += qq.top() * s1; q.pop();
	}
	printf("%d\n", ans);
	return 0;
}
#include<queue>
#include<cstdio>
using namespace std;
int n, m, s1 = 1, s2 = 1, sum = 0;
priority_queue<int> q1,q2;

inline int read(){
    int num = 0, k = 1; char c = getchar();
    while(c > '9' || c < '0') k = (c == '-') ? -1 : k , c = getchar();
    while(c >= '0' && c <= '9') num = num * 10 + c - '0', c = getchar();
    return num * k;
}

int main() {
    n = read(); m = read();
    for(int i = 1;i < n;i++) q1.push(read());
    for(int i = 1;i < m;i++) q2.push(read());
    while(!q1.empty() && !q2.empty()){
        if(q1.top() > q2.top()) {
            sum += q1.top() * s2;
            s1++; q1.pop();
        }
        else {
            sum += q2.top()*s1;
            s2++; q2.pop();
        }
    }
    while(!q1.empty()) {sum += q1.top()*s2; q1.pop();}
    while(!q2.empty()) {sum += q2.top()*s1; q2.pop();}
    printf("%d",sum);
    return 0;
}
