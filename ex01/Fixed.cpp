#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
  std::cout << "Copy constructor called" << std::endl;
  // fixed_point_value_ = src.getRawBits();
  *this = src;
}

Fixed::Fixed(int const val) {
  std::cout << "Int constructor called" << std::endl;
  setRawBits(val << fractional_bits_);
}

Fixed::Fixed(float const val) {
  std::cout << "Float constructor called" << val << std::endl;
    setRawBits(roundf(val * (1 << fractional_bits_)));
}

int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return fixed_point_value_;
}

void Fixed::setRawBits(int const raw) { fixed_point_value_ = raw; }

float Fixed::toFloat() const {
  return (float)getRawBits() / (1 << fractional_bits_);
}

int Fixed::toInt(void) const {
  return fixed_point_value_ >> fractional_bits_;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& value) {
    // std::cout<<"overrided operator called"<< value.getRawBits() <<std::endl;
    return stream << value.toFloat();
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;

	this->fixed_point_value_ = rhs.getRawBits();
	return *this;
}
