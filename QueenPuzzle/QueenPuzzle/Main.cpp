#include"Queen.h"
using namespace std;

int main()
{
	int size;
	cin>>size;

	Queen configuration(size);
	SolveFrom(configuration);

	return 0;
}