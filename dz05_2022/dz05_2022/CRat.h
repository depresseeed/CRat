#ifndef CRAT
#define CRAT
#include "main.h"
using namespace std;




struct fr {
	int p;
	int q;
};

class CRat {
public:
	fr* vec;
	int size;
	string outfile;

public:
	CRat();
	CRat(int input_size);
	CRat(int input_size, fr* arr, const string FileName);
	//CRat(string filename);
	virtual void output() = 0;
	void do_normal();
	
	const CRat& operator=(const CRat& oke);
	~CRat();
};

#endif