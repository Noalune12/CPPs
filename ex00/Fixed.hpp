/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 07:31:25 by lbuisson          #+#    #+#             */
/*   Updated: 2025/05/28 07:31:26 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class Fixed {

	public:
		Fixed( void );
		Fixed( Fixed const& src );
		~Fixed( void );

		Fixed&	operator=(Fixed const& rhs);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int	_val;
		static const int	_bit;
};

#endif
