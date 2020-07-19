#include <stdio.h>
int change[16]={0x111f,0x222f,0x444f,0x888f,0x11f1,0x22f2,0x44f4,0x88f8,
           0x1f11,0x2f22,0x4f44,0x8f88,0xf111,0xf222,0xf444,0xf888};
int main()
{
    int ini, i, ans;
    char t;
    while(~scanf(" %c", &t)){
        ans = ini = 0;
        if(!(t ^ '+')){
            ini ^= change[0];
        }
        for(i = 1; i < 16; i++){
            scanf(" %c", &t);
            if(!(t ^ '+')){
                ini ^= change[i];
            }
        }
        for(i = 0; i < 16; i++){
            if(ini & (1 << i)) ans++;
        }
        printf("%d\n", ans);
        for(i = 0; i < 16; i++){
            if(ini & (1 << i)){
                printf("%d %d\n", (i / 4) + 1, (i % 4) + 1);
            }
        }
    }
    return 0;
}
