#include <iostream>
using namespace std;
 int table[256];
bool cmp(char a, char b)
{
    return table[a] < table[b]; 
}
int main()
{
    int n, len, t = 0;
    char a[100];
    for(int i = 'A'; i <= 'Z'; i++){
        table[i] = t++;
        table[tolower(i)] = t++;
    }
    scanf(" %d", &n);
    while(n--){
        scanf(" %s", a);
        len = strlen(a);
        sort(a, a + len, cmp);
        do{
            printf("%s\n", a);
        }while(next_permutation(a, a + len, cmp));
    }
}
