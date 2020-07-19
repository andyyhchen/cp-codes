#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    vector <int> a[4];
    for(int i = 0; i < 100; i++){
       	if((i / 10 + i % 10) * (i / 10 + i % 10) == i){
          	a[0].push_back(i);
        }
    }
    for(int i = 0; i < 10000; i++){
    	if((i / 100 + i % 100) * (i / 100 + i % 100) == i){
    		a[1].push_back(i);
    	}
    }
   	for(int i = 0; i < 1000000; i++){
  		if((i % 1000 + i / 1000)*(i % 1000 + i / 1000) == i){
  			a[2].push_back(i);
    	}
    }
    for(int i = 0; i < 100000000; i++){
    	if((i / 10000 + i % 10000) * (i / 10000 + i % 10000) == i){
            a[3].push_back(i);
        }
    }
    while(~scanf(" %d", &n)){
        if(n == 2){
            for(int i = 0; i < a[0].size(); i++){
                printf("%02d\n", a[0][i]);
            }
        }
    	if(n == 4){
    		for(int i = 0; i < a[1].size(); i++){
                printf("%04d\n", a[1][i]);
            }
    	}
    	if(n==6){
         	for(int i = 0; i < a[2].size(); i++){
                printf("%06d\n", a[2][i]);
            }
    	}
    	if(n == 8){
    		for(int i = 0; i < a[3].size(); i++){
                printf("%08d\n", a[3][i]);
            }
        }
    }
}

