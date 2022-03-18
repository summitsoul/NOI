#include<cstdio>
using namespace std;
int n;
char letter[1010][1010][10];

void change(int x){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            letter[i][j][7] = '#';
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(letter[i][j][0] == 'O') letter[j][n + 1- i][7] = 'O';
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            letter[i][j][0] = letter[i][j][7];
}

int main(){
    scanf("%d" ,&n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%c", &letter[i][j][0]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%c", &letter[i][j][1]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(letter[i][j][0] == 'O') printf("%c", letter[i][j][1]);
    for(int i = 2; i <= 4; i++) change(i);
    
}