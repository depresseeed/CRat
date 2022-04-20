#include "CRat0.h"

CRat0::CRat0() {
	vec = NULL;
	size = 0;
}

CRat0::CRat0(int input_size) {
	size = input_size;
	vec = (fr*)malloc(sizeof(fr) * size);
}

CRat0::CRat0(int input_size, fr* arr, const string FileName) {
	size = input_size;
	vec = (fr*)malloc(sizeof(fr) * size);
	for (int i = 0; i < size; i++) {
		vec[i].p = arr[i].p;
		vec[i].q = arr[i].q;
	}
	outfile = FileName;
}

void CRat0::output() {
	ofstream file;
	file.open(outfile);
	for (int i = 0; i < size; i++) {
		file << vec[i].p << " " << vec[i].q << " ";
	}
	file.close();
}



const CRat0 operator+(const CRat0& left, const CRat0& right) {
	if (left.size == 0 || left.size != right.size) {
		perror("Bad sizes");
		CRat0 error_return;
		return error_return;
	}
	CRat0 sum(left.size);

	for (int i = 0; i < sum.size; i++) {
		sum.vec[i].p = left.vec[i].p * right.vec[i].q + right.vec[i].p * left.vec[i].q;
		sum.vec[i].q = left.vec[i].q * right.vec[i].q;
	}
	sum.do_normal();
	return sum;
}

const CRat0 operator-(const CRat0& left, const CRat0& right) {
	if (left.size == 0 || left.size != right.size) {
		perror("Bad sizes");
		CRat0 error_return;
		return error_return;
	}
	CRat0 sum(left.size);
	for (int i = 0; i < sum.size; i++) {
		sum.vec[i].p = left.vec[i].p * right.vec[i].q - right.vec[i].p * left.vec[i].q;
		sum.vec[i].q = left.vec[i].q * right.vec[i].q;
	}
	sum.do_normal();
	return sum;
}

const fr operator*(const CRat0& left, const CRat0& right) {
	fr ret;
	fr buff;
	int nod;
	ret.p = 0;
	ret.q = 1;
	if (left.size == 0 || left.size != right.size) {
		perror("Bad sizes");
		return ret;
	}

	for (int i = 0; i < left.size; i++) {
		buff.p = left.vec[i].p * right.vec[i].p;
		buff.q = left.vec[i].q * right.vec[i].q;
		ret.p = buff.p * ret.q + ret.p * buff.q;
		ret.q *= buff.q;
		nod = NOD(ret.p, ret.q);
		ret.p /= nod;
		ret.q /= nod;
	}

	return ret;

}

 CRat0& CRat0::operator=(const CRat0& oke) {
	if (CRat0::size != oke.size) {
		perror("Wrong size");
		exit(228);
	}
	for (int i = 0; i < size; i++) {

		vec[i].p = oke.vec[i].p;
		vec[i].q = oke.vec[i].q;
	}
	return *this;
}





CRat0::~CRat0() { if(vec != NULL) free(vec); }

