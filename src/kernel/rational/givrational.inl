// ==========================================================================
// $Source: /var/lib/cvs/Givaro/src/kernel/rational/givrational.inl,v $
// Copyright(c)'94-97 by Givaro Team
// see the copyright file.
// Authors: M. Samama
// $Id: givrational.inl,v 1.2 2005-06-14 14:53:14 pernet Exp $
// ==========================================================================
// Description:



//-------------------------------------------------inline comparaison operators
inline int operator != (const Rational& a , const Rational& b)
  { return compare(a,b) != 0 ; }

inline int operator == (const Rational& a, const Rational& b)
  {  return compare(a,b) == 0 ; }

inline int operator < (const Rational& a , const Rational& b)
  { return compare(a,b) == -1 ; }

inline int operator >  (const Rational& a , const Rational& b)
  { return compare(a,b) == 1 ; }

inline int operator <= (const Rational& a, const Rational& b)
  { return compare(a,b) <= 0 ; }

inline int operator >= (const Rational& a, const Rational& b)
  { return compare(a,b) >= 0 ; }

//----------------------------------arithmetic inline operators
inline const Rational operator + (const Rational& r, const int i)
  { return r + Rational(i) ; }  
inline const Rational operator - (const Rational& r, const int i)
  { return r - Rational(i) ; }  
inline const Rational operator * (const Rational& r, const int i)
  { return r * Rational(i) ; }  
inline const Rational operator / (const Rational &r, const int i)
  { return r / Rational(i) ; }  

inline const Rational operator + (const int i, const Rational& r) 
  { return Rational(i) + r; }  
inline const Rational operator - (const int i, const Rational& r) 
  { return Rational(i) - r; }  
inline const Rational operator * (const int i, const Rational& r) 
  { return Rational(i) * r; }  
inline const Rational operator / (const int i, const Rational& r) 
  { return Rational(i) / r ; }  

inline Rational Rational::operator + ()  const 
  { return *this ; } 

//----------------------------------miscellaneous inline functions
inline int isinteger(const Rational& r)
  { return isOne(r.den) ; }

inline int isOne(const Rational& a)
  { return (isOne(a.num) && isOne(a.den)) ; }

inline int isZero(const Rational& a)
  { return isZero(a.num) ; }

inline int sign(const Rational& a)
  { return sign(a.num) ; }

inline unsigned long length(const Rational& a)
  { return length(a.num) + length(a.den) ; }

inline const Rational abs(const Rational &r)
  { return Rational(abs(r.num), r.den, 0); }

inline const Integer Rational::nume() const 
  { return num ; }

inline const Integer Rational::deno() const 
  { return den ; }

inline Rational Rational::reduce( const Rational& R) const 
  { Rational tmp ; tmp = R ; tmp.reduce() ; return tmp ; }

//-------------------------------------------------inline >> & << operators
inline std::ostream& operator<< (std::ostream& o, const Rational& a)
  { return a.print(o); }

