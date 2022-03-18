#include<stack>
#include<cstdio>
using namespace std;
int n;
int h[100010],f[100010];
stack <int> s;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	for(int i=n;i>=1;i--){
		while(!s.empty()&&h[s.top()]<=h[i]) s.pop();
		if(!s.empty()) f[i]=s.top();
		else f[i]=0;
		s.push(i);
	}
	for(int i=1;i<=n;i++)	printf("%d\n",f[i]);
	return 0;
}
