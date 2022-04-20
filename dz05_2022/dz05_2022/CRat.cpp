#include "CRat.h"

CRat::CRat() {
	vec = NULL;
	size = 0;
}


void CRat::do_normal() {
	for (int i = 0; i < size; i++) {
		int nod = NOD(vec[i].p, vec[i].q);
		vec[i].p /= nod;
		vec[i].q /= nod;
	}
}

CRat::CRat(int input_size) {
	size = input_size;
	vec = (fr*)malloc(sizeof(fr) * size);
}

CRat::CRat(int input_size, fr* arr, const string FileName) {
	size = input_size;
	for (int i = 0; i < size; i++) {
		vec[i].p = arr[i].p;
		vec[i].q = arr[i].q;
	}
	outfile = FileName;
}





CRat::~CRat() {
	

}


