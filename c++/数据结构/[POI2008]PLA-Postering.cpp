#include<stack>
#include<cstdio>
#define ll long long 
using namespace std;
int n,ans=0;
ll w[250010];
stack <int> s;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){ll a;	 scanf("%lld %lld",&a,&w[i]);}
	for(int i=1;i<=n;i++){
		while(!s.empty()&&s.top()>w[i]) ans++,s.pop();
		if(s.empty()||s.top()!=w[i]) s.push(w[i]);
	}
	printf("%d\n",ans+s.size());
	return 0;
}
