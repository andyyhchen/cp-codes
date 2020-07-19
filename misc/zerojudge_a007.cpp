#include <iostream>
#include <math.h>

#define MAX_LEN 46400

using namespace std;

char isPrime[MAX_LEN];

void reset(char *array){
	for(int i = 0; i < MAX_LEN; i++){
		array[i] = 1;
	}
}

int main(){
	reset(isPrime);
	for(int i = 3; i < MAX_LEN; i++){
		int u = (int)sqrt(i) + 1;
		for (int j = 2; j < u; j++){
			if(!(i % j)){
				isPrime[i] = 0;
				break;
			}
		}
	}
	int input;
	while(cin >> input){
		int up = (int)sqrt(input) + 1, f = 0;
		for(int i = 2; i < up; i++){
			if(isPrime[i]){
				if(!(input % i)) {
					cout << "非質數" << endl;
					f = 1;
					break;
				}
			} 
		}
		if(!f)cout << "質數" << endl;
	}
}