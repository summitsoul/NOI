#include<map>
#include<vector>
#include<cstdio>
#include<string>
#include<sstream>
#include<iostream>
#define ll long long
#define INF 0x7f7f7f7f7f7f7f7f
using namespace std;
int file, now_dir;   //文件的编号和现在的文件
vector<string> output; //输出
struct File{
    int fa; //父目录
    string name;    //文件名
    ll size;    //文件大小
    bool f_d;   //目录属性 directory attribute 文件还是文件夹
    bool f_h;   //隐藏属性 hidden
    map<string, int> son;   //子文件的编号
    inline int find(string str){
        if(!son.count(str)) return -1;
        return son[str];
    }
}f[1000010];

void clear(int x){
    f[x].fa = 0;
    f[x].f_d = f[x].f_h = 0;
    f[x].name = "";
    f[x].size = 0;
    f[x].son.clear();
}

inline bool bad_usage(){
    output.clear(); 
    output.push_back("bad usage\n");
}

inline void erase_space(string &str){   //清除空格
    while(str != "" && str[0] == ' ') str.erase(0, 1);
    while(str != "" && str[str.length() - 1] == ' ') str.erase(str.length() - 1, 1);
}

inline bool get_int(string str, ll &a){ 
    a = 0;
    for(int i = 0; i < str.length(); i++)
        if(isdigit(str[i]))
            a = a * 10 + str[i] ^ '0';
        else return 1;
    return 1;
}

inline int find_file(string path){  //寻找文件
    erase_space(path);
    if(path == "") return now_dir;
    int now = now_dir;
    if(path[0] == '/') now = 0;
    for(int i = 0; i < path.size(); i++)
        if(path[i] == '/') path[i] = ' ';
    istringstream in(path);
    string name;
    while(in >> name){
        if(now == -1 || f[now].f_d == 0) return -1;
        if(name == ".") continue;
        if(name == "..") now = f[now].fa;
        else now = f[now].find(name);
    }
    return now;
}

inline string get_path(int id){ //获取绝对路径
    if(f[id].fa == -1) return f[id].name;
    return get_path(f[id].fa) + "/" + f[id].name;
}

inline void get_tag(vector<string>&cs, int &tag, string ch){ //查找参数
    tag = 0;
    //for(int i = 0; i < cs.size(); i++)
}

void pwd(){
    string path = get_path(now_dir);
    if(path == "") path = "/";
    output.push_back(path + "\n");
}

void cd(vector<string>&args, vector<string>&cs){
    string bash = args[0];
    erase_space(bash);
    int f = find_file(bash);
}

void mkdir(vector<string>&args, vector<string>&cs){
    string filename = "";
    int h = 0;
    get_tag(cs, h, "h");
}

void KP_st(){  //回到初始界面
    for(int i = 0; i < file; i++)
        clear(i);
    f[0].fa = -1; f[0].f_d = 1;
    now_dir = 0;
}

inline int splitBash(string bash, string &Command, ll &size, vector<string> &str1, vector<string> &str2){   //分离命令
    str1.clear(); str2.clear();
    Command = ""; size = INF;
    erase_space(bash);  //把开头结尾空格清除
    istringstream in(bash);
    string str;
    if(!(in >> str)) return 2;    //空命令
    Command = str;
    while(in >> str){
        if(str[0] == '-'){
            str.erase(0, 1);
            if(isalpha(str[0])) str2.push_back(str);
            else
                if(isdigit(str[0])) get_int(str, size);
                else{
                    bad_usage();
                    return 1;
                }
        }
        else str1.push_back(str);   //必选参数
    } 
    return 0;
}

inline void run_command(string command, vector<string>&args, vector<string>&cs, ll size){
    if(command == "") return ;
    if(command == "cd"){
        if(args.size() != 1){
            bad_usage(); return ;
        }
        cd(args, cs);
    }
    else if(command == "pwd"){
        if(!args.empty()){
            bad_usage(); return ;
        }
        pwd();
    }
    else if(command == "mkdir"){
        if(args.size() != 1){
            bad_usage(); return ;
        }
        mkdir(args, cs);
    }
}

int main(){
    KP_st();   //初始化
    string bash;
    while(getline(cin, bash)){  //输入
        ll size = 0;
        string order, nw = "";
        vector<string>args, cs;
        vector<string> avx; //每条管道分割出来的指令
        output.clear(); //刷新
        bool flag = 0;  //标记记录"
        while(bash != ""){
            if(bash[0] == '|' && !flag) avx.push_back(nw), nw = "";
            else nw += bash[0];
            if(bash[0] == '"') flag ^= 1;
            bash.erase(0, 1);
        }
        avx.push_back(nw);
        if(splitBash(avx[0], order, size, args, cs)) bad_usage();   //判断是否按照规定输入
        else run_command(order, args, cs, size);    //判断指令
    }
}