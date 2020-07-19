#include <iostream>

using namespace std;

unsigned long long int reverse(unsigned long long int i)
{
	unsigned long long int ans=0;
	while(i) ans*=10,ans+=i%10,i/=10;
	return ans;
}
int main()
{
	unsigned long long int N,P,tmp,c;
	while(cin>>N)
		while(N--&&cin>>P)
		{
			c=1;P+=reverse(P);
			while(P!=reverse(P)) P+=reverse(P),c++;
			cout<<c<<" "<<P<<"\n";
		}
	return 0;
}
