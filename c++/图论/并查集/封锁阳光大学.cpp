#include<bits/stdc++.h>
using namespace std;
int f[10001],a,b,n,m,t[10001],bj[10001],h[10001],ans;
int find(int x)//ģ�庯����
{
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}
void xx(int x,int y)//�жϺ�����
{
    int qq=find(x);
    if(qq!=y)//������Ǹ��ײ���Ƚ����Ǻϲ���
    {
        f[y]=qq;
        t[qq]+=t[y];
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
        t[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        int x1=find(a),x2=find(b);
        if(x1!=x2)//��������һ����ɫ��
        {
            if(h[a]) xx(h[a],x2);/*a�ĸ��׽ڵ�һ��
            ��a��ɫ��һ����a����ɫ��ͬɫ�����Խ�����
            �ϲ���*/
            if(h[b]) xx(h[b],x1);//ͬ�ϣ�
            h[a]=x2;//h�����a����ɫ�㣻
            h[b]=x1;//ͬ�ϣ�
        }
        else//�������ͬɫ����ʾ���У�
        {
            cout<<"Impossible";
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int q=find(i);
        if(!bj[q])//��ʾ������ϵĴ𰸻�û��ѡ����
        {
            int q1=find(h[i]);
            bj[q]=1;
            bj[q1]=1;
            ans+=min(t[q],t[q1]);//���������Сֵ��
        }
    }
    cout<<ans;
    return 0;
}
