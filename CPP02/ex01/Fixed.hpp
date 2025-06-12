/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 07:31:35 by lbuisson          #+#    #+#             */
/*   Updated: 2025/05/28 07:31:36 by lbuisson         ###   ########lyon.fr   */
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

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int	_val;
		static const int	_bit;
};

std::ostream & operator<<( std::ostream& o, Fixed const& name );

#endif
