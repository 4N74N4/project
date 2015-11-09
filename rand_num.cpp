#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

bool unique(long n)
{
	fstream f1;
	f1.open("num.txt", ios::in | ios::out);
	long m;
	f1.seekg(0, ios::beg);
	while(!f1.eof())
	{
		f1 >> m;
		if(m == n)
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	long i, randNum;
	fstream f;
	f.open("num.txt", ios::in | ios::out);
	unsigned long seedval;
	time_t t;
	seedval = (unsigned) time (&t);
	srand(seedval);
	for(i=0; i<500; i++)
	{
		randNum = rand();
		if(randNum > 999999999 && randNum <10000000000 && unique(randNum))
			f<< randNum << '\n';
		else
			i--;
	}
	return 0;
}
