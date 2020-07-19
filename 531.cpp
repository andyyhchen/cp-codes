#include <iostream>
#include <vector>
using namespace std;
struct word{
    char s[35];
};
vector <word> t1, t2, ans;
int dp[101][101];
bool operator == (const word a, const word b)
{
    return !strcmp(a.s, b.s);
}
void backtracking(int i, int j)
{
    if(!i || !j) return;
    if(t1[i - 1] == t2[j - 1]){
        ans.push_back(t1[i - 1]);
        backtracking(i - 1, j - 1);        
    }else{
        if(dp[i - 1][j] > dp[i][j - 1]){
            backtracking(i - 1, j);
        }else{
            backtracking(i, j - 1);
        }
    }
}
int main()
{
    word t_word;
    while(~scanf(" %s", t_word.s)){
        t1.clear(); t2.clear(); ans.clear();
        t1.push_back(t_word);
        while(scanf(" %s", t_word.s)&&t_word.s[0]!='#') t1.push_back(t_word);
        while(scanf(" %s", t_word.s)&&t_word.s[0]!='#') t2.push_back(t_word);
        int st1 = t1.size(), st2 = t2.size();
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= st1; i++){
            for(int j = 1; j <= st2; j++){
                if(t1[i - 1] == t2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }        
        }
        backtracking(st1, st2);
        if(dp[st1][st2] > 0)
            printf("%s", ans[ans.size() - 1].s);
        for(int i = ans.size() - 2; i >= 0; i--){
            printf(" %s", ans[i].s);
        }
        puts("");
    }
}
