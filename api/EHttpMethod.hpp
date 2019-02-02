/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** EHttpMethod
*/

#pragma once

#include <unordered_map>

namespace Pizzia {

	/*
	** This enum is used to identify the HTTP Method
	*/
	enum EHttpMethod {
		OPTIONS = 0,
		GET,
		HEAD,
		POST,
		PUT,
		DELETE,
		TRACE,
		CONNECT,
		UNDEFINED
	};

	/*
	** This map stores the name of the method and their enum equivalent
	** You can use this unordered map to convert from string to enum and vice versa
	*/
	const std::unordered_map<std::string, EHttpMethod> methodMap = {
		{ "GET", GET },
		{ "OPTIONS", OPTIONS },
		{ "HEAD", HEAD },
		{ "POST", POST },
		{ "PUT", PUT },
		{ "DELETE", DELETE },
		{ "TRACE", TRACE },
		{ "CONNECT", CONNECT },
		{ "UNDEFINED", UNDEFINED }
	};

}