#include<string>
#include<iostream>
using namespace std;
int num, v[150], t;
string s, a, e, ans[50];

void change(string &s){
	int len = s.size();
	for(int i = 0; i < len; i++)
		if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
}

void translate(string &s, int t){
	int len = s.size();
	for(int i = 0; i < len; i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] += t;
			if(s[i] > 'Z') s[i] -= 26;
			if(s[i] < 'A') s[i] += 26;
		}
	}
}

int f(string s){
	int len = s.size();
	for(int i = 0; i < len; i++) v[(int)s[i]]++;
	int maxn = 0, k;
	for(int i = 'A'; i <= 'Z'; i++)
		if(v[i] > maxn){
			maxn = v[i]; k = i; 
		}
	int ans = 'E' - k;
	return 0;
}

int main(){
	while(cin >> s, getline(cin, a), getline(cin, a), cin >> e){
		change(a);
		num++;
		if(num == 1) t = f(a);
		translate(a, t);
		ans[num] = a;
	}
	for(int i = 1; i <= num; i++)
		cout << ans[i] << endl;
	return 0;
}

