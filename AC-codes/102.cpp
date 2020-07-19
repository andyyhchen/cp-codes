#include <iostream>
using namespace std;
int main()
{
    int b[3][3], cost[5];
    while(cin>>b[0][0]){
        cin>>b[0][1]>>b[0][2]>>b[1][0]>>b[1][1]>>b[1][2]>>b[2][0]>>b[2][1]>>b[2][2];
        cost[0] = b[0][1] + b[0][2] + b[1][0] + b[1][1] + b[2][0] + b[2][2]; //  bcg
        cost[1] = b[0][1] + b[0][2] + b[1][0] + b[1][2] + b[2][0] + b[2][1]; //  bgc
        cost[2] = b[0][0] + b[0][1] + b[1][1] + b[1][2] + b[2][0] + b[2][2]; //  cbg
        cost[3] = b[0][0] + b[0][1] + b[1][0] + b[1][2] + b[2][1] + b[2][2]; //  cgb
        cost[4] = b[0][0] + b[0][2] + b[1][1] + b[1][2] + b[2][0] + b[2][1]; //  gbc
        cost[5] = b[0][0] + b[0][2] + b[1][0] + b[1][1] + b[2][1] + b[2][2]; //  gcb
        
        int smallest = INT_MAX, ind = 0;
        for(int i = 0; i < 6; i++){
            if(smallest > cost[i]){
                smallest = cost[i];
                ind = i;
            }
        }
        switch(ind){
            case 0:
                printf("BCG %d\n", smallest);
                break;
            case 1:
                printf("BGC %d\n", smallest);
                break;
            case 2:
                printf("CBG %d\n", smallest);
                break;
            case 3:
                printf("CGB %d\n", smallest);
                break;
            case 4:
                printf("GBC %d\n", smallest);
                break;
            case 5:
                printf("GCB %d\n", smallest);
                break;                        
        }        
    }
}
