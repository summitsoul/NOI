#include<bits/stdc++.h>
using namespace std;
int n;
int a[30],used[30];
char s1[30],s2[30],s3[30];
bool check(){
	int g = 0;
	for(int i = n-1; i >= 0 ; --i){
		if((a[s1[i]-65]+a[s2[i]-65]+g)%n != a[s3[i]-65]) return 0;
		g = (a[s1[i]-65]+a[s2[i]-65]+g)/n;
	}
	if(g>0) return 0;
	return 1;
}
void dfs(int k){
	if(k==n){
		if(check()){
			for(int i = 0; i < n; ++i) printf("%d ",a[i]);puts("");
		}
		return;
	}
	for(int i = 0; i < n; ++i){
		if(!used[ i ]){
			a[ k ] = i;
			used[ i ] = 1;
			dfs( k + 1 );
			used[ i ] = 0;
		}
	}
}
int main(){
	scanf("%d",&n);
	scanf("%s %s %s",s1,s2,s3);
	dfs(0);
	return 0;
}
//50分 
#include<bits/stdc++.h>
using namespace std;
int n;
int a[30],used[30];
char s1[30],s2[30],s3[30];
bool check(){
	int g = 0;
	for(int i = n-1; i >= 0 ; --i){
		if((a[s1[i]-65]+a[s2[i]-65]+g)%n != a[s3[i]-65]) return 0;
		g = (a[s1[i]-65]+a[s2[i]-65]+g)/n;
	}
	if(g>0) return 0;
	return 1;
}
bool canuse(){
	for(int i = n-1; i >= 0; --i){
		int x1 = s1[i]-65 , x2 = s2[i]-65, x3 = s3[i]-65;
		if(a[x1]==-1 || a[x2]==-1 || a[x3] == -1) continue;
		if((a[x1]+a[x2])%n!=a[x3]&&(a[x1]+a[x2]+1)%n!=a[x3]) return 0;
	}
	return 1;
}
void dfs(int k){
	if(k==n){
		if(check()){
			for(int i = 0; i < n; ++i) printf("%d ",a[i]);printf("\n");
		}
		return;
	}
	for(int i = n-1; i >= 0; --i){
		if(used[i]) continue;
		a[ k ] = i;
		if(canuse()){
			used[i] = 1;
			dfs(k+1);
			used[i] = 0;
		}
		a[ k ] = -1;
	}
}
int main(){
	scanf("%d",&n);
	scanf("%s %s %s",s1,s2,s3);
	memset(a,-1,sizeof(a));
	dfs(0);
	return 0;
}
//css100
//50分 
#include<bits/stdc++.h>
using namespace std;
int n;
int a[30],used[30],tot,order[30],vi[30];//搜索的顺序 
char s1[30],s2[30],s3[30];
bool check(){
	int g = 0;
	for(int i = n-1; i >= 0 ; --i){
		if((a[s1[i]-65]+a[s2[i]-65]+g)%n != a[s3[i]-65]) return 0;
		g = (a[s1[i]-65]+a[s2[i]-65]+g)/n;
	}
	if(g>0) return 0;
	return 1;
}
bool canuse(){
	if(a[s1[0]-65]+a[s2[0]-65]>=n) return 0;
	for(int i = n-1; i >= 0; --i){
		int x1 = s1[i]-65 , x2 = s2[i]-65, x3 = s3[i]-65;
		if(a[x1]==-1 || a[x2]==-1 || a[x3] == -1) continue;
		if((a[x1]+a[x2])%n!=a[x3]&&(a[x1]+a[x2]+1)%n!=a[x3]) return 0;
	}
	return 1;
}
void dfs(int k){
	if(k==n){
		if(check()){
			for(int i = 0; i < n; ++i) printf("%d ",a[i]);printf("\n");
			exit(0);
		}
		return;
	}
	for(int i = n-1; i >= 0; --i){
		if(used[i]) continue;
		a[ order[k] ] = i;
		if(canuse()){
			used[i] = 1;
			dfs(k+1);
			used[i] = 0;
		}
		a[ order[k] ] = -1;
	}
}
int main(){
	scanf("%d",&n);
	scanf("%s %s %s",s1,s2,s3);
	memset(a,-1,sizeof(a));
	for(int i = n-1; i >= 0; --i){//计算搜索的顺序 
		int x1 = s1[i]-65 , x2 = s2[i]-65, x3 = s3[i] - 65;
		if(!vi[x1]){
			vi[x1] = 1; order[ tot++ ] = x1;
		}
		if(!vi[x2]){
			vi[x2] = 1; order[ tot++ ] = x2;
		}
		if(!vi[x3]){
			vi[x3] = 1; order[ tot++ ] = x3;
		}
	}
	dfs(0);
	return 0;
}