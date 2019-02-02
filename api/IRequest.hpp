/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** IRequest
*/

#include <string>
#include <unordered_map>

#include "EHttpMethod.hpp"
#include "IMapContainer.hpp"

#pragma once

namespace Pizzia {

	/*
	** This interface describe how we save the request
	*/
	class IRequest {
	public:
		IRequest() {}
		virtual ~IRequest() {}
	public:
		virtual const std::string &getRaw() const = 0;
		virtual void setRaw(const std::string &raw) = 0;

		virtual EHttpMethod getMethod() const = 0;
		virtual void setMethod(EHttpMethod method) = 0;

		virtual const std::string &getUri() const = 0;
		virtual void setUri(const std::string &uri) = 0;

		virtual IMapContainer &getParameters() = 0;

		virtual const std::pair<unsigned int, unsigned int> &getHttpVersion() const = 0;
		virtual void setHttpVersion(unsigned int major, unsigned int minor) = 0;

		virtual IMapContainer &getHeaders() = 0;

		virtual void setBody(const std::string &body) = 0;
		virtual const std::string &getBody() const = 0;
	};

}