#ifndef CRAT0
#define CRAT0
#include "main.h"
#include "CRat.h"
class CRat0 : public CRat {
public:
    CRat0();
    CRat0(int);
    CRat0(int, fr*, const string);
    void output();

    friend const CRat0 operator+ (const CRat0& left, const CRat0& right);
    friend const CRat0 operator- (const CRat0& left, const CRat0& right);
    friend const fr operator*(const CRat0& left, const CRat0& right);
    CRat0& operator=(const CRat0& oke);
    ~CRat0();
};

#endif // !CRAT1


