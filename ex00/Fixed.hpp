/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:27:34 by mel-atti          #+#    #+#             */
/*   Updated: 2025/03/01 22:28:31 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <stdint.h>
#include <iostream>
#include <string>
#include <limits>
#include <stdbool.h>

class Fixed 
{
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &other);
    ~Fixed();
    
    Fixed& operator=(const Fixed &other);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
