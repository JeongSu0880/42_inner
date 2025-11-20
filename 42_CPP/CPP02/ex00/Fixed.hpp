#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	static const int	FRACTIONAL_BITS = 8;
	int					value;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator= (const Fixed &fixed);
	
	int getRawBits() const;
	void setRawBits(const int raw);
};

#endif