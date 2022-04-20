#include "main.h"
#include "CRat0.h"
#include "CRat1.h"

int NOD(int n1, int n2)
{
	int div;
	if (n1 == n2)  return n1;
	int d = n1 - n2;
	if (d < 0) {
		d = -d;  div = NOD(n1, d);
	}
	else
		div = NOD(n2, d);
	return div;
}




int main(void) {
	//const char fname[] = "1.txt";
	int len;
	int I;
	fr* buff = (fr*)malloc(4);
	const string infile_name = "1.txt";
	string line;
	string outfile;
	int size = 0;

	ifstream infile;
	infile.open(infile_name);
	while (getline(infile, line))
		size++;
	infile.close();
	CRat** arr = (CRat**)malloc(sizeof(CRat*) * size);
	int i = 0;
	infile.open(infile_name);
	while (!infile.eof())
	{
		infile >> I;
		infile >> outfile;
		infile >> len;
		buff = (fr*)realloc(buff, sizeof(fr) * len);
		for (int i = 0; i < len; i++) {
			infile >> buff[i].p;
			infile >> buff[i].q;
		}
	

		if (I == 0)
			arr[i++] = new CRat0(len, buff, outfile);
		
		else if (I == 1)
			arr[i++] = new CRat1(len, buff, outfile);

	}

	for (int i = 0; i < size; i++) {
		arr[i]->output();
	}


	return 0;
}