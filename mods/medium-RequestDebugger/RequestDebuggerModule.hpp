/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** RequestDebuggerModule
*/

#include "api/IModule.hpp"

#pragma once
namespace Pizzia {

class RequestDebuggerModule : public IModule {
	public:
		RequestDebuggerModule() {}
		~RequestDebuggerModule() {}

	public:
		EModuleStatus run(IRequest &, IResponse &, IMapContainer &, IMapContainer &);
		inline const std::string getName() const { return "RequestDebuggerModule"; }
};

}