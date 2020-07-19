#include <iostream>
using namespace std;
int main()
{
    unsigned long long int sum;
    int n, m;
    while(scanf(" %d %d", &n, &m) && (n + m)){
        int bound, i, j;
        if(m > n / 2){
            bound = n - m;
        }else{
            bound = m;
        }
        for(i = 1, j = n, sum = 1; i <= bound; i++, j--){
            sum *= j;
            sum /= i;
        }
        printf("%llu\n", sum);
    }
}
