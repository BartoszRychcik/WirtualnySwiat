#include <time.h>
#include <cstdlib>
#include "Interface.h"
using namespace std;

int main()
	{
	srand(int(time(NULL)));
	Interface graficzny;
	graficzny.Start();
	}