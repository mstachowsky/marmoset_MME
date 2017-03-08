#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const double TOL = 1e-11; //tolerance - we shouldn't use == for doubles!
	double coeffs[6] = {0.0};
	
	//might as well store both arrays
	double derivCoeffs[6] = {0.0};
	cout << "Enter all 5 coefficients: ";
	for(int i = 0; i < 6; i++)
	{
		cin >> coeffs[i]; //I can read directly into the array,
		//and so should you!
		
		//let's  compute the derivative all at once
		derivCoeffs[i] = coeffs[i] * (5 - i);
	}
	
	//now we loop.  Notice, I'm only looping up to index 3, not 4.  Why?
	//because I need to output the symbol "+" at the end of each term EXCEPT
	//the last one. The last term is output after the loop
	for(int i = 0; i < 4; i++)
	{
		//don't output if it's zero
		if(fabs(derivCoeffs[i]) > TOL)
		{
			//we don't want to display the 1
			if(fabs(derivCoeffs[i] - 1) > TOL)
			{
				cout << derivCoeffs[i] << "x^" << 4-i;
			}
			else
			{
				cout << "x^" << 4-i;
			}
			
			//Now we have an interesting challenge.  We need to make sure
			//we don't output a "+" at the very end if there is no coefficient
			//(if that coefficient is zero), so:
			if(i!=3 || (i == 3 && fabs(derivCoeffs[4]) > TOL))
			{
				cout << " + ";
			}
		}
		
	}
	//have to check for zero again
	if(fabs(derivCoeffs[4]) > TOL)
	{
		cout << derivCoeffs[4];
	}
}
