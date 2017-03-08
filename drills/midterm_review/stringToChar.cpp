#include <iostream>
using namespace std;

class car{
	public:
	double speed;
	double gas;
	
	double getGasLeft()
	{
		return gas;
	}
	void addGas(double newGas)
	{
		this->gas += newGas;
	}

};

int main()
{
	bool x = "NotABool";
	cout << x << endl;
	car C;
	C.gas = 10;
	C.addGas(7);
	cout << C.gas;
}
