/*#include<set>
#include<cstring> 
#include<iostream>
int n;

int main(){
	std::cin >> n;
	std::set<std::string> set;
	for(int i = 1; i <= n; i++){
		std::string s; std::cin >> s;
		std::string dir = "";
		for(auto j : s){
			if(j == '/')
				set.insert(dir);
			dir += j;
		}
		set.insert(dir);
		std::cout <<set.size() - 1 << std::endl;
	}
	return 0;
}*/
#include <set>
#include <string>
#include <iostream> 

int main() {
    int n;
    std::cin >> n;
    std::set<std::string> set;
    
    for (int i = 1; i <= n; ++i) {
        std::string s;
        std::cin >> s;
        std::string dir = "";
        for (auto j : s) {
            if (j == '/')
                set.insert(dir);
            dir += j;
        }
        set.insert(dir);
        
        std::cout << set.size() - 1 << std::endl;
    }
}
