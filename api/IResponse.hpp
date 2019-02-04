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

	/*
	** This interface describe how we save the response
	*/
	class IResponse {
	public:
		IResponse() = default
		virtual ~IResponse() noexcept = default
	public:
		virtual const std::string &getRaw() const = 0;
		virtual void setRaw(const std::string &raw) = 0;

		virtual unsigned int getStatusCode() const noexcept = 0;
		virtual void setStatusCode(unsigned int statusCode) noexcept = 0;

		virtual const std::string &getStatusReasonPhrase() const = 0;
		virtual void setStatusReasonPhrase(const std::string &reasonPhrase) = 0;

		virtual const std::pair<unsigned int, unsigned int> &getHttpVersion() const = 0;
		virtual void setHttpVersion(unsigned int major, unsigned int minor) noexcept = 0;

		virtual IMapContainer &getHeaders() = 0;

		virtual const std::string &getBody() const = 0;²
		virtual void setBody(const std::string &body) = 0;
	};

}