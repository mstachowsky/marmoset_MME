#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int responses[3] = {0};
	int numResponses = 0;
	int tempResponse = 0;
	double avgs[3] = {0.0};
	char keepGoing = 'Y';
	
	while(keepGoing == 'Y')
	{
		cout << "On a scale of 1 to 10: " << endl;
		cout << "How satisfied are you with your computer? ";
		cin >> tempResponse;
		responses[0] += tempResponse;
		cout << "How satisfied are you with your smartphone? ";
		cin >> tempResponse;
		responses[1] += tempResponse;
		cout << "How satisfied are you with Dev-C++? ";
		cin >> tempResponse;
		responses[2] += tempResponse;
		
		numResponses++;
		
		cout << "Are there any more people who want to do the survey? Y/N: ";
		cin >> keepGoing;
	}
	
	//compute the averages, you could use a for loop if you wish
	avgs[0] = 1.0*responses[0]/numResponses;
	avgs[1] = 1.0*responses[1]/numResponses;
	avgs[2] = 1.0*responses[2]/numResponses;
	
	cout << avgs[0] << " " << avgs[1] << " " << avgs[2];
}
