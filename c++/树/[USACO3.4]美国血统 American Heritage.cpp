#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
string pre,inor;

void work(string pre,string inor){
	if(pre.empty()) return ;
	char root=pre[0];
	int k=inor.find(root);
	pre.erase(pre.begin());
	string leftpre=pre.substr(0,k);
	string rightpre=pre.substr(k);
	string leftinor=pre.substr(0,k);
	string rightinor=pre.substr(k+1);
	work(leftpre,leftinor);
	work(rightpre,rightinor);
	printf("%c",root);
}

int main(){
	cin>>inor>>pre;
	work(pre,inor);
	putchar('\n');
	return 0;
}
