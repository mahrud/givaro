// ==========================================================================
// $Source: /var/lib/cvs/Givaro/src/kernel/zpz/givzpz32uns.inl,v $
// Copyright(c)'1994-2009 by The Givaro group
// This file is part of Givaro.
// Givaro is governed by the CeCILL-B license under French law
// and abiding by the rules of distribution of free software.
// see the COPYRIGHT file for more details.
// Authors: T. Gautier
// $Id: givzpz32uns.inl,v 1.15 2011-02-02 17:16:43 bboyer Exp $
// ==========================================================================

#ifndef __GIVARO_zpz32_uns_INL
#define __GIVARO_zpz32_uns_INL

#include "givaro/modular-defines.h"
#include <cmath>

namespace Givaro {

	// ------------------------
	// ----- Classic arithmetic

	inline Modular<uint32_t>::Element& Modular<uint32_t>::mul
	    (Element& r, const Element& a, const Element& b) const
	{
		return __GIVARO_MODULAR_INTEGER_MUL(r,_p,a,b);
	}

	inline Modular<uint32_t>::Element& Modular<uint32_t>::sub
	    (Element& r, const Element& a, const Element& b) const
	{
		return __GIVARO_MODULAR_INTEGER_SUB(r,_p,a,b);
	}

	inline Modular<uint32_t>::Element& Modular<uint32_t>::add
	    (Element& r, const Element& a, const Element& b) const
	{
		__GIVARO_MODULAR_INTEGER_ADD(r,_p,a,b);
		return r;
	}

	inline Modular<uint32_t>::Element& Modular<uint32_t>::neg
	    (Element& r, const Element& a) const
	{
		return __GIVARO_MODULAR_INTEGER_NEG(r,_p,a);
	}

	inline Modular<uint32_t>::Element& Modular<uint32_t>::inv
	    (Element& r, const Element& a) const
	{
		return Modular<uint32_t>::invext(r, a, _p);
	}

	inline Modular<uint32_t>::Element& Modular<uint32_t>::div
	    (Element& r, const Element& a, const Element& b) const
	{
		return mulin( inv(r, b), a );
	}


	inline Modular<uint32_t>::Element& Modular<uint32_t>::mulin
	    (Element& r, const Element& a) const
	{
		return __GIVARO_MODULAR_INTEGER_MULIN(r,_p, a);
	}

	inline Modular<uint32_t>::Element& Modular<uint32_t>::divin
	    (Element& r, const Element& a) const
	{
		Modular<uint32_t>::Element ia;
		inv(ia, a);
		return mulin(r, ia);
	}

	inline Modular<uint32_t>::Element& Modular<uint32_t>::addin
	    (Element& r, const Element& a) const
	{
		uint32_t tmp = r;
		__GIVARO_MODULAR_INTEGER_ADDIN(tmp,_p, a);
		return r = (Element)tmp;
	}

	inline Modular<uint32_t>::Element& Modular<uint32_t>::subin
	    (Element& r, const Element& a) const
	{
		uint32_t tmp = r;
		__GIVARO_MODULAR_INTEGER_SUBIN(tmp,_p, a);
		return r = (Element)tmp;
	}


	inline Modular<uint32_t>::Element& Modular<uint32_t>::negin
	    (Element& r) const
	{
		return __GIVARO_MODULAR_INTEGER_NEGIN(r,_p);
	}

	inline Modular<uint32_t>::Element& Modular<uint32_t>::invin
	    (Element& r) const
	{
		return Modular<uint32_t>::invext(r, r, _p);
	}


	inline Modular<uint32_t>::Element& Modular<uint32_t>::axpy
	    (Element& r, const Element& a, const Element& b, const Element& c) const
	{
		uint32_t tmp;
		__GIVARO_MODULAR_INTEGER_MULADD(tmp, _p, a, b, c);
		return r = (Element)tmp;
	}

	inline Modular<uint32_t>::Element&  Modular<uint32_t>::axpyin
	    (Element& r, const Element& a, const Element& b) const
	{
		uint32_t tmp = r;
		__GIVARO_MODULAR_INTEGER_MULADDIN(tmp, _p, a, b);
		return r = (Element)tmp;
	}

	inline Modular<uint32_t>::Element&  Modular<uint32_t>::axmy
	    (Element& r, const Element& a, const Element& b, const Element& c) const
	{
		uint32_t tmp;
		__GIVARO_MODULAR_INTEGER_MULSUB(tmp, _p, a, b, c);
		return r = (Element)tmp;
	}

	// r = c-a*b
	inline Modular<uint32_t>::Element&  Modular<uint32_t>::maxpy
	    (Element& r, const Element& a, const Element& b, const Element& c) const
	{
		uint32_t tmp=c;
		__GIVARO_MODULAR_INTEGER_SUBMULIN(tmp, _p, a, b);
		return r = (Element)tmp;
	}

	// r -= a*b
	inline Modular<uint32_t>::Element&  Modular<uint32_t>::maxpyin
	    (Element& r, const Element& a, const Element& b) const
	{
		uint32_t tmp = r;
		__GIVARO_MODULAR_INTEGER_SUBMULIN(tmp, _p, a, b );
		return r = (Element)tmp;
	}

	// r = a*b - r
	inline Modular<uint32_t>::Element&  Modular<uint32_t>::axmyin
	    (Element& r, const Element& a, const Element& b) const
	{
		maxpyin(r,a,b);
		return negin(r);
	}
	
	// ----------------------------------
	// ----- Classic arithmetic on arrays

	// -- inline array operations between Modular<uint32_t>::Element
	inline void Modular<uint32_t>::mul
	    (const size_t sz, Array r, constArray a, constArray b) const
	{
		for ( size_t i=sz ; --i ; ) {
			uint32_t tmp;
			__GIVARO_MODULAR_INTEGER_MUL(tmp, _p,a[i], b[i]);
			r[i] = (Element)tmp;
		}
	}

	inline void Modular<uint32_t>::mul
	    (const size_t sz, Array r, constArray a, Element b) const
	{
		for ( size_t i=sz ; --i ; ) {
			uint32_t tmp;
			__GIVARO_MODULAR_INTEGER_MUL(tmp, _p, a[i], b);
			r[i] = (Element)tmp;
		}
	}

	inline void Modular<uint32_t>::div
	    (const size_t sz, Array r, constArray a, constArray b) const
	{
		for ( size_t i=sz ; --i ; ) {
			div( r[i], a[i], b[i]);
		}
	}

	inline void Modular<uint32_t>::div
	    (const size_t sz, Array r, constArray a, Element b) const
	{
		Modular<uint32_t>::Element ib;
		inv(ib, b);
		mul(sz, r, a, ib);
	}

	inline void Modular<uint32_t>::add
	    (const size_t sz, Array r, constArray a, constArray b) const
	{
		for ( size_t i=sz ; --i ; ) {
			uint32_t tmp;
			__GIVARO_MODULAR_INTEGER_ADD(tmp, _p, a[i], b[i]);
			r[i] = (Element)tmp;
		}
	}

	inline void Modular<uint32_t>::add
	    (const size_t sz, Array r, constArray a, Element b) const
	{
		for ( size_t i=sz ; --i ; ) {
			uint32_t tmp;
			__GIVARO_MODULAR_INTEGER_ADD(tmp, _p, a[i], b);
			r[i] = (Element)tmp;
		}
	}

	inline void Modular<uint32_t>::sub
	    (const size_t sz, Array r, constArray a, constArray b) const
	{
		for ( size_t i=sz ; --i ; ) {
			uint32_t tmp;
			__GIVARO_MODULAR_INTEGER_SUB(tmp, _p, a[i], b[i]);
			r[i] = (Element)tmp;
		}
	}

	inline void Modular<uint32_t>::sub
	    (const size_t sz, Array r, constArray a, Element b) const
	{
		for ( size_t i=sz ; --i ; ) {
			uint32_t tmp;
			__GIVARO_MODULAR_INTEGER_SUB(tmp, _p, a[i], b);
			r[i] = (Element)tmp;
		}
	}

	inline void Modular<uint32_t>::neg
	    (const size_t sz, Array r, constArray a) const
	{
		for ( size_t i=sz ; --i ; ) {
			uint32_t tmp;
			__GIVARO_MODULAR_INTEGER_NEG(tmp, _p, a[i]);
			r[i] = (Element)tmp;
		}
	}


	inline void Modular<uint32_t>::axpy (const size_t sz, Array r,
					      constArray a, constArray x, constArray y) const
	{
		for ( size_t i=sz ; --i ; ) {
			uint32_t tmp;
			__GIVARO_MODULAR_INTEGER_MULADD(tmp, _p, a[i], x[i], y[i]);
			r[i] = (Element)tmp;
		}
	}

	inline void Modular<uint32_t>::axpyin (const size_t sz, Array r,
						constArray a, constArray x) const
	{
		for ( size_t i=sz ; --i ; ) {
			uint32_t tmp = r[i];
			__GIVARO_MODULAR_INTEGER_MULADDIN(tmp, _p, a[i], x[i]);
			r[i] = (Element)tmp;
		}
	}


	inline void Modular<uint32_t>::axmy (const size_t sz, Array r,
					      constArray a, constArray x, constArray y) const
	{
		for ( size_t i=sz ; --i ; ) {
			uint32_t tmp;
			__GIVARO_MODULAR_INTEGER_MULSUB(tmp, _p, a[i], x[i], y[i]);
			r[i] = (Element)tmp;
		}
	}

	// r -= a*b
	inline void Modular<uint32_t>::maxpyin (const size_t sz, Array r,
						 constArray a, constArray x) const
	{
		for ( size_t i=sz ; --i ; ) {
			uint32_t tmp = r[i];
			__GIVARO_MODULAR_INTEGER_SUBMULIN(tmp, _p, a[i], x[i]);
			r[i] = (Element)tmp;
		}
	}
	
	// --------------------
	// ----- Initialisation

	inline  Modular<uint32_t>::Element&  Modular<uint32_t>::init ( Element& r, const double a ) const
	{
		int sign; double ua;
		if (a < 0.0) { sign =-1; ua = -a;}
		else { ua = a; sign =1; }
		if ( ua > Signed_Trait<uint32_t>::max()){
			//     ua -= (double)floor(ua * _invdp)*_dp;
			ua = fmod(ua,_dp);
			r = (Element) ua;
		} else
			r = (ua >=_p) ? (uint32_t) ua % _p : (uint32_t) ua;
		if (r && (sign ==-1)) r = _p - r;
		return r;
	}

	inline  Modular<uint32_t>::Element&  Modular<uint32_t>::init ( Element& r, const float a ) const
	{
		return init(r, (double)a);
	}

	inline  Modular<uint32_t>::Element&  Modular<uint32_t>::init ( Element& r, const unsigned long a ) const
	{
		return r = (Element)( a >= (unsigned long)_p ? a % (unsigned long)_p : a);
	}

	inline  Modular<uint32_t>::Element&  Modular<uint32_t>::init ( Element& r, const long a ) const
	{
		int sign;
		unsigned long ua;
		if (a <0) {
			sign =-1;
			ua = (unsigned long)-a;
		}
		else {
			ua = (unsigned long)a;
			sign =1;
		}
		r = Element( (ua >=_p) ? ua % _p : ua );
		if (r && (sign ==-1))
			r = _p - r;
		return r;
	}

	inline Modular<uint32_t>::Element&  Modular<uint32_t>::init ( Element& r, const Integer& Residu ) const
	{
		long tr;
		if (Residu <0) {
			// -a = b [p]
			// a = p-b [p]
			if ( Residu <= (Integer)(-_p) )
				tr = long( (-Residu) % _p) ;
			else
				tr = long(-Residu);
			if (tr)
				return r = Element( _p - (unsigned long)tr );
			else
				return r = zero;
		} else {
			if (Residu >= (Integer)_p )
				tr =   long(Residu % _p) ;
			else
				tr = long(Residu);
			return r = Element(tr);
		}
	}

	inline Modular<uint32_t>::Element& Modular<uint32_t>::init( Element& a, const int i) const
	{
		return init(a,(long)i);
	}

	inline Modular<uint32_t>::Element& Modular<uint32_t>::init( Element& a, const unsigned int i) const
	{
		return init(a,(unsigned long)i);
	}


	inline void Modular<uint32_t>::assign
	( const size_t sz, Array r, constArray a ) const
	{
		for ( size_t i=sz ; --i ; ) {
			if (a[i] <Modular<uint32_t>::zero) {
				r[i] = a[i] + _p;
				if (r[i] <Modular<uint32_t>::zero) r[i] = r[i] % _p;
			}
			else if ((uint32_t)a[i] >_p) {
				r[i] = a[i] - _p;
				if ((uint32_t)r[i] >=_p) r[i] = r[i] % _p;
			}
			else r[i] = a[i];
		}
	}

	inline  Modular<uint32_t>::Element&  Modular<uint32_t>::assign
	( Element& r, const Element a ) const
	{
		return r = (a % _p);
	}


	inline void Modular<uint32_t>::init
	( const size_t sz, Array r, constArray a ) const
	{
		for ( size_t i=sz ; --i ; )
			r[i] = a[i];
	}

	inline Modular<uint32_t>::Element& Modular<uint32_t>::init ( Element& r ) const
	{
		return r = zero;
	}

	inline Modular<uint32_t>::Element&  Modular<uint32_t>::dotprod
	( Element& r, const int bound, const size_t sz, constArray a, constArray b ) const
	{
		unsigned int stride = 1;
		if ((unsigned long)bound < GIVARO_MAXUINT32)
			//    stride = GIVARO_MAXULONG/((unsigned long)bound * (unsigned long)bound);
			stride = (unsigned int) ( GIVARO_MAXULONG/((unsigned long)bound) / ((unsigned long)bound) );
		unsigned long dot = zero;
		if ((sz <10) && (sz <stride)) {
			for(  size_t i= sz; i--; )
				dot += a[i] * b[i];
			if (dot > _p)
				return r = (Element)(dot % _p);
			else
				return r = (Element)dot;
		}
		size_t i_begin=0;
		stride &= (unsigned int)~0x1;
		if (stride ==0) {
			for(  size_t i= sz; --i; ) {
				dot += a[i] * b[i];
				if (dot>_p) dot %= _p;
			}
			return r = (Element)dot;
		}
		do {
			size_t min_sz = ((sz-i_begin) < stride ? (sz-i_begin) : stride);
			if ((min_sz & 0x1) !=0) {
				min_sz--;
				i_begin++;
				dot += a++[min_sz] * b++[min_sz];
			}
			if (min_sz > 1)
				for(  size_t i= min_sz; i>0; --i, --i, ++a, ++a, ++b, ++b )
				{
					dot += a[0] * b[0];
					dot += a[1] * b[1];
				}
			if (dot>_p)
				dot %= _p;
			i_begin += min_sz;
		} while (i_begin <sz);
		return r = (Element)dot;
	}

	inline Modular<uint32_t>::Element&  Modular<uint32_t>::dotprod
	( Element& r, const size_t sz, constArray a, constArray b ) const
	{
		return Modular<uint32_t>::dotprod(r, (int)_p, sz, a, b);
	}


	//  a -> r: uint32_t to double
	inline void
	Modular<uint32_t>::i2d ( const size_t sz, double* r, constArray a ) const
	{
		for (size_t i=0; i<sz; ++i) r[i] = a[i];
	}

	//  a -> r: double to uint32_t
	inline void
	Modular<uint32_t>::d2i ( const size_t sz, Array r, const double* a ) const
	{
		union d_2_l {
			double d;
			uint32_t r[2];
		};
		//  static const double offset = 4503599627370496.0; // 2^52
		double offset = 4503599627370496.0; // 2^52
		for (size_t i=0; i<sz; ++i)
		{
			d_2_l tmp;
			// - normalization: put fractional part at the end of the representation
			tmp.d = a[i] + offset;
			r[i] = tmp.r[1];
			if (r[i] <_p) r[i] %= _p;
		}
		//    r[i] = (tmp.r[1] <_p ? tmp.r[1] : tmp.r[1]-_p);
		//    r[i] = (r[i] <_p ? r[i] : r[i]%_p);
		//    r[i] = (tmp.r[1] <_p ? tmp.r[1] : tmp.r[1]%_p);
	}



	// -- Input: (z, <_p>)
	inline std::istream& Modular<uint32_t>::read (std::istream& s)
	{
		char ch;
		s >> std::ws >> ch;
		if (ch != '(')
			//    GivError::throw_error( GivBadFormat("Modular<uint32_t>::read: syntax error: no '('"));
			std::cerr << "GivBadFormat(Modular<uint32_t>::read: syntax error: no '('))" << std::endl;

		s >> std::ws >> ch;
		if (ch != 'z')
			//    GivError::throw_error( GivBadFormat("Modular<uint32_t>::read: bad domain object"));
			std::cerr << "GivBadFormat(Modular<uint32_t>::read: bad domain object))" << std::endl;

		s >> std::ws >> ch;
		if (ch != ',')
			//    GivError::throw_error( GivBadFormat("Modular<uint32_t>::read: syntax error: no ','"));
			std::cerr << "GivBadFormat(Modular<uint32_t>::read: syntax error: no ',')) " << std::endl;

		s >> std::ws >> _p;

		s >> std::ws >> ch;
		if (ch != ')')
			//    GivError::throw_error( GivBadFormat("Modular<uint32_t>::read: syntax error: no ')'"));
			std::cerr << "GivBadFormat(Modular<uint32_t>::read: syntax error: no ')')) " << std::endl;

		return s;
	}

	inline std::ostream& Modular<uint32_t>::write (std::ostream& s ) const
	{
		return s << "Uns32 Givaro Z/pZ modulo " << residu();
	}

	inline std::istream& Modular<uint32_t>::read (std::istream& s, Element& a) const
	{
		Integer tmp;
		s >> tmp;
		init(a, tmp);
		return s;
	}

	inline std::ostream& Modular<uint32_t>::write (std::ostream& s, const Element a) const
	{
		return s << a;
	}

} // namespace Givaro

#endif // __GIVARO_zpz32_uns_INL

// vim:sts=8:sw=8:ts=8:noet:sr:cino=>s,f0,{0,g0,(0,\:0,t0,+0,=s