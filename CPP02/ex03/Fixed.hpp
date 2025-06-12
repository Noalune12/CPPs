/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 07:32:46 by lbuisson          #+#    #+#             */
/*   Updated: 2025/05/28 07:32:47 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {

	public:
		Fixed( void );
		Fixed( int const n );
		Fixed ( float const f );
		Fixed( Fixed const& src );
		~Fixed( void );

		Fixed&	operator=(Fixed const& rhs);
		Fixed	operator+(Fixed const& rhs) const;
		Fixed	operator-(Fixed const& rhs) const;
		Fixed	operator*(Fixed const& rhs) const;
		Fixed	operator/(Fixed const& rhs) const;

		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		bool	operator==( const Fixed& rhs );
		bool	operator!=( const Fixed& rhs );
		bool	operator>( const Fixed& rhs );
		bool	operator<( const Fixed& rhs );
		bool	operator>=( const Fixed& rhs );
		bool	operator<=( const Fixed& rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed& min( Fixed& lhs, Fixed& rhs);
		static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
		static Fixed& max( Fixed& lhs, Fixed& rhs);
		static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

	private:
		int	_val;
		static const int	_bit;
};

std::ostream & operator<<( std::ostream& o, Fixed const& name );

#endif
