/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** RequestParserModule
*/

#include <sstream>
#include <regex>
#include "RequestParserModule.hpp"
#include "api/EHttpMethod.hpp"

//DEBUG
#include <iostream>

namespace Pizzia {

void RequestParserModule::_removeWhitespace(std::string &line)
{
	line = std::regex_replace(line, std::regex("^ +"), "");
	line = std::regex_replace(line, std::regex(" +$"), "");
}

void RequestParserModule::_addInHeader(IRequest &request, std::string line)
{	
	std::size_t i = line.find(":");
	std::string key = line.substr(0, i);
	std::string value = line.substr(i + 1, line.length());

	_removeWhitespace(key);
	_removeWhitespace(value);
	request.getHeaders().create(key, value);
}

bool RequestParserModule::_setHttpVersion(IRequest &request, std::string version)
{
	std::regex r("([0-9]+)");
	std::smatch smatch;
	std::vector<unsigned int> versions;

	while (std::regex_search(version, smatch, r)) {
		versions.push_back(std::stoi(smatch.str()));
		version = smatch.suffix();
	}

	if (versions.size() != 2) {
		// TODO Log une erreur
		std::cout << "Bad header" << std::endl;
		return false;
	} else {
		request.setHttpVersion(versions[0], versions[1]);
		return true;
	}
}

/**
 * This is experimental request URI parser, it don't work in 100% of cases for the real Zia we need to make-it in more robust way
 *
 * @param request
 */
void RequestParserModule::_parseUriParams(IRequest &request)
{
	std::string url = std::string(request.getUri());
	std::regex regex("[^&?]*?=[^&?]*");
	std::smatch smatch;

	while (std::regex_search(url, smatch, regex)) {
		std::string item = smatch.str();
		std::string key = item.substr(0, item.find("="));
		std::string value = item.substr(item.find("=") + 1);

		request.getParameters().create(key, value);
		url = smatch.suffix();
	}
}

EModuleStatus RequestParserModule::run(IRequest &request, IResponse &/*response*/, IMapContainer &/*configuration*/, IMapContainer &/*session*/)
{
	std::stringstream stream(request.getRaw());
	std::string method;
	std::string uri;
	std::string version;
	std::string line;

	stream >> method;
	stream >> uri;
	stream >> version;

	request.setUri(uri);
	if (methodMap.find(method) != methodMap.end()) {
		request.setMethod(methodMap.at(method));
	} else {
		return EModuleStatus::ERROR;
	}
	if (_setHttpVersion(request, version) == false) {
		return EModuleStatus::ERROR;
	}
	while (std::getline(stream, line, '\n')) {
		if (line.length() > 1) {
			_addInHeader(request, line);
		}
	}

	_parseUriParams(request);
	return EModuleStatus::SUCCESS;
}
}