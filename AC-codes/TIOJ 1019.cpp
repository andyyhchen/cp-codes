#include <iostream>
using namespace std;
int main()
{
	long long int step[1001], a[1001];
	int t, n;
	scanf(" %d", &t);
 	while(t--){
		scanf(" %d", &n);
		for(int i = 0; i < n; i++) scanf(" %I64d", &a[i]);
		step[0] = 0;
		step[1] = abs(a[1] - a[0]);
		for(int i = 2; i < n; i++){
			step[i] = min(step[i - 1] + abs(a[i] - a[i - 1]), step[i - 2] + abs(a[i] - a[i - 2]));
		}
		printf("%I64d\n", step[n - 1]);
	}

	return 0;
}
