#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
 public:
  Fixed();
  ~Fixed();
  Fixed(Fixed const &src);
  Fixed(int const val);
  Fixed(float const val);

 //assign
  Fixed &operator=(const Fixed &tmp);

//comparisons >, >=, <=, <, ==,!=.
  // bool operator>(const Fixed &tmp);

	bool   operator>(const Fixed &tmp) const;
  bool  operator>=(const Fixed &tmp) const;
  bool   operator<(const Fixed &tmp) const;
  bool  operator<=(const Fixed &tmp) const;
  bool  operator==(const Fixed &tmp) const;
  bool  operator!=(const Fixed &tmp) const;

  // in/de crements
  Fixed  &operator++(void);
  Fixed   operator++(int);
  Fixed  &operator--(void);
  Fixed   operator--(int);

  //the four arithmetics
  Fixed operator+(const Fixed &tmp);
  Fixed operator-(const Fixed &tmp);
  Fixed operator*(const Fixed &tmp);
  Fixed operator/(const Fixed &tmp);

  //max min
		// static Fixed	&max( Fixed & a, Fixed & b );
		static const Fixed	&max( const Fixed & a, const Fixed & b );
  // static Fixed& min(Fixed &f1, Fixed &f2);
		static const Fixed	&min( const Fixed & a, const Fixed & b );

  //getter
  int   getRawBits(void) const;
  float toFloat(void) const;
  int   toInt(void) const;

  //setter
  void  setRawBits(int const raw);

  private:
    int               fixed_point_value_;
    static const int  fractional_bits_ = 8;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& value);

#endif
