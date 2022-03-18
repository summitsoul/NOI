#include<iostream>
using namespace std;

int main(){
	int n,sum=0,num;	cin>>n;
	int h[10010]={0};
	for(int i=1;i<=n;i++){
		cin>>h[i];
		if(h[i]>h[i-1]) sum+=h[i]-h[i-1];
	}
	cout<<sum<<endl;
	return 0;
}
