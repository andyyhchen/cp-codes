#include <iostream>
using namespace std;
int main()
{
	int a[150], ans = 0;
	for(int i = 0; i < 150; i++){
		a[i] = i * i;
	}
	int f1,f2;
	for(ans = 1000; ans < 10000; ans++){
        f1 = f2 = 0;
		for(int i = 0; i < 150; i++){
			if(ans+111 == a[i]) f1=1;
			if(ans+1647+111 == a[i]) f2=1;
		}
		if(f1&&f2) cout << ans << "\n";
	}
	return 0;
}
