/*
 * base64.h
 *
 *  Created on: Apr 10, 2025
 *      Author: athadebesh
 */

#ifndef UTIL_BASE64_H_
#define UTIL_BASE64_H_


#include <string>

std::string base64_encode     (std::string const& s, bool url = false);
std::string base64_encode_pem (std::string const& s);
std::string base64_encode_mime(std::string const& s);

std::string base64_decode(std::string const& s, bool remove_linebreaks = false);
std::string base64_encode(unsigned char const*, size_t len, bool url = false);


#endif /* UTIL_BASE64_H_ */
