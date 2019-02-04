/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** BasicModule
*/

#include "api/IModule.hpp"

#pragma once
namespace Pizzia {

class RequestParserModule : public IModule {
	public:
		RequestParserModule() {}
		~RequestParserModule() {}

	public:
		EModuleStatus run(IRequest &request, IResponse &response, IMapContainer &configuration, IMapContainer &session);
		inline const std::string getName() const { return "RequestParserModule"; }

	private:
		bool _setHttpVersion(IRequest &request, std::string version);
		void _addInHeader(IRequest &request, std::string line);
		void _removeWhitespace(std::string &line);
		void _parseUriParams(IRequest &request);
};

}