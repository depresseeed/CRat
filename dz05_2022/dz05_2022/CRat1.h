#ifndef CRAT1
#define CRAT1
#include "main.h"
#include "CRat.h"
class CRat1 : public CRat {
public:
    CRat1();
    CRat1(int);
    CRat1(const int, fr*, const string);
    void output();

    friend const CRat1 operator+ (const CRat1& left, const CRat1& right);
    friend const CRat1 operator- (const CRat1& left, const CRat1& right);
    friend const fr operator*(const CRat1& left, const CRat1& right);
    CRat1& operator=(const CRat1& oke);
    ~CRat1();
};

#endif // !CRAT1


