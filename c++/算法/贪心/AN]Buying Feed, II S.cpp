/*#include<bits/stdc++.h>
using namespace std;
int k,n,e,sum=0;	//FJ����ȥ��K��ʳ�������ĳ�����X��ʳ�ÿ��һ��ͻ���XԪ
int c[500];	//ÿ�ݼ�Ǯ 

struct road{
	int x,f;	//xλ��f��ʳ�� 
}r[500];

int main(){
	cin>>k>>e>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i].x>>r[i].f>>c[i];
		c[i]=c[i]+e-r[i].x;
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n&&k>=0;i++){
		sum+=min(k,r[i].f)*c[i];
		k-=r[i].f;
	}
	cout<<sum<<endl;
	return 0;
}*/
#include<cstdio>
#include<algorithm>
using namespace std;
struct shu {int jia,num;}a[505];//jia Ϊ�۸�   ��numΪ����
int k,m,n,t,c,ans;
int compare(shu x,shu y)
{
    return x.jia<y.jia;
}
int main()
{
    scanf("%d%d%d",&k,&m,&n);
    for (int i=1;i<=n;i++)
    {scanf("%d%d%d",&t,&a[i].num,&c);a[i].jia=(m-t)+c;}//Ԥ����
    sort(a+1,a+n+1,compare);//��������С
    for (int i=1;i<=n;i++)
    {ans+=min(k,a[i].num)*a[i].jia;
     k-=a[i].num;
     if (k<=0) break;//ȡ��Сֵ
    }
    printf("%d",ans);
}

