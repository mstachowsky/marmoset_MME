#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	do{
		cout << "Enter a positive integer: ";
		cin >> n;
	}while(n<=0);
	
	//there is no super efficient way to do this, we just need to loop!
	for(int i = 1; i < n; i++)
	{
		//I could have gone only until n/2, but that doesn't save a TON
		//of efficiency and on a midterm would not really be needed
		if(n % i == 0)
		{
			cout << i << " is a factor." << endl;
		}
	}
}
