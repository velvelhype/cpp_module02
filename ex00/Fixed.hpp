#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
 public:
  Fixed();
  ~Fixed();
  Fixed(Fixed const &src);
  // An assignation operator overload.
  Fixed &operator=(const Fixed &tmp);
  int getRawBits(void) const;
  void setRawBits(int const raw);

 private:
  int fixed_point_value_;
  static const int fractional_bits_ = 8;
};

#endif
