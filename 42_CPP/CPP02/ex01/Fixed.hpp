#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	static const int	FRACTIONAL_BITS = 8;
	int					value;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	
	Fixed(const int num);
	Fixed(const float num);
	
	float toFloat() const;
	int toInt() const;

	int getRawBits() const;
	void setRawBits(const int raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixedNum);

#endif