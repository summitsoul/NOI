#include<bits/stdc++.h>
using namespace std;
struct ren{
	long int ks,js;	//��ʼʱ�䡢����ʱ�� 
};
ren z[10010];
int cmp(ren a,ren b){
	return a.ks>b.ks;
}
int main(){
	int n,k,num=1;	//����ʱ�䡢k������
	int f[10010],sum[10010];	//���桢���� 
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++){
		cin>>z[i].ks>>z[i].js;
		sum[z[i].ks]++;
	} 
	sort(z+1,z+k+1,cmp);
	for(int i=n;i>=1;i--)
		if(sum[i]==0) f[i]=f[i+1]+1;
		else{
			for(int j=1;j<=sum[i];j++){
				if(f[i+z[num].js]>f[i]) f[i]=f[i+z[num].js];
				num++;
			}
		}
	cout<<f[1]<<endl;
	return 0;
}
