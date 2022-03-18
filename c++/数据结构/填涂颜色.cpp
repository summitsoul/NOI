#include<iostream>
using namespace std;
int n;
int mp[35][35];

int main(){
	cin>>n; 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j]; 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(mp[i][j]==0){
				int sum=0;
				for(int k=i;k>=1;k--) if(mp[k][j]==1){sum++; break;}
				for(int k=i;k<=n;k++) if(mp[k][j]==1){sum++; break;}
				for(int k=j;k>=1;k--) if(mp[i][k]==1){sum++; break;}
				for(int k=j;k<=n;k++) if(mp[i][k]==1){sum++; break;}
				if(sum==4) mp[i][j]=2;
			}
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<mp[i][j]<<" ";
		cout<<endl; 
	}
	return 0;
}
