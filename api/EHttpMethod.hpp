/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** EHttpMethod
*/

#pragma once

#include <unordered_map>

namespace Pizzia {

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