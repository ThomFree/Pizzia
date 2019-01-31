/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** IResponse
*/

#include <string>
#include <unordered_map>

#include "EHttpMethod.hpp"
#include "IMapContainer.hpp"

#pragma once

namespace Pizzia {
	class IResponse {
	public:
		IResponse() {}
		virtual ~IResponse() {}
	public:
		virtual const std::string &getRaw() const = 0;
		virtual void setRaw(const std::string &raw) = 0;

		virtual unsigned int getStatusCode() const = 0;
		virtual void setStatusCode(unsigned int statusCode) = 0;

		virtual const std::string &getStatusReasonPhrase() const = 0;
		virtual void setStatusReasonPhrase(const std::string &reasonPhrase) = 0;

		virtual const std::pair<unsigned int, unsigned int> &getHttpVersion() const = 0;
		virtual void setHttpVersion(unsigned int major, unsigned int minor) = 0;

		virtual IMapContainer &getHeaders() = 0;

		virtual const std::string &getBody() const = 0;
		virtual void setBody(const std::string &body) = 0;
	};
}