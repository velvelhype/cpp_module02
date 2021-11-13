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
  // An assignation operator overload.
  Fixed &operator=(const Fixed &tmp);
  Fixed &operator++();
  Fixed operator++(int);
  Fixed operator*(const Fixed &tmp);

  static Fixed& max(Fixed &f1, Fixed &f2);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

 private:
  int fixed_point_value_;
  static const int fractional_bits_ = 8;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& value);

#endif
