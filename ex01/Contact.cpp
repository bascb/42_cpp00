/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:21:27 by bcastelo          #+#    #+#             */
/*   Updated: 2024/02/04 15:41:41 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void    Contact::set_field(std::string field, std::string value)
{
    if (field == "first name")
        first_name = value;
    else if (field == "last name")
        last_name = value;
    else if (field == "nickname")
        nickname = value;
    else if (field == "phone number")
        phone_number = value;
    else if (field == "darkest secret")
        darkest_secret = value;
}

std::string Contact::get_field(std::string field)
{
    if (field == "first name")
        return (first_name);
    else if (field == "last name")
        return (last_name);
    else if (field == "nickname")
        return (nickname);
    else if (field == "phone number")
        return (phone_number);
    else if (field == "darkest secret")
        return (darkest_secret);
    return ("Field does not exists");
}