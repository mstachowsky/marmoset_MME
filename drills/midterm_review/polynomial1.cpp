
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const double TOL = 1e-11; //tolerance - we shouldn't use == for doubles!
	double coeffs[6] = {0.0};
	cout << "Enter all 5 coefficients: ";
	for(int i = 0; i < 6; i++)
	{
		cin >> coeffs[i]; //I can read directly into the array,
		//and so should you!
	}
	
	//now we loop.  Notice, I'm only looping up to index 4, not 5.  Why?
	//because I need to output the symbol "+" at the end of each term EXCEPT
	//the last one. The last term is output after the loop
	for(int i = 0; i < 5; i++)
	{
		//don't output if it's zero
		if(fabs(coeffs[i]) > TOL)
		{
			//we don't want to display the 1
			if(fabs(coeffs[i] - 1) > TOL)
			{
				cout << coeffs[i] << "x^" << 5-i;
			}
			else
			{
				cout << "x^" << 5-i;
			}
			
			//Now we have an interesting challenge.  We need to make sure
			//we don't output a "+" at the very end if there is no coefficient
			//(if that coefficient is zero), so:
			if(i!=4 || (i == 4 && fabs(coeffs[5]) > TOL))
			{
				cout << " + ";
			}
		}
		
	}
	//have to check for zero again
	if(fabs(coeffs[5]) > TOL)
	{
		cout << coeffs[5];
	}
}
