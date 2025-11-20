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

	bool operator>(const Fixed &fixedNum) const;
	bool operator<(const Fixed &fixedNum) const;
	bool operator>=(const Fixed &fixedNum) const;
	bool operator<=(const Fixed &fixedNum) const;
	bool operator==(const Fixed &fixedNum) const;
	bool operator!=(const Fixed &fixedNum) const;

	Fixed &operator++();
	Fixed &operator--();
	const Fixed operator++(int);
	const Fixed operator--(int);

	Fixed operator+(const Fixed &fixedNum);
	Fixed operator-(const Fixed &fixedNum);
	Fixed operator*(const Fixed &fixedNum);
	Fixed operator/(const Fixed &fixedNum);

	static Fixed &min(Fixed &fixed1, Fixed &fixed2);
	static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
	static Fixed &max(Fixed &fixed1, Fixed &fixed2);
	static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixedNum);

#endif