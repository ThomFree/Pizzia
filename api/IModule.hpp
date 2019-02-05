/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** IModule
*/

#include "EModuleStatus.hpp"
#include "IRequest.hpp"
#include "IResponse.hpp"

#pragma once

namespace Pizzia {

	/*
	** You need to inherit from this interface to create your module
	*/
	class IModule {
	public:
		/*
		** You MUST use a constructor with no parameters
		*/
		IModule() = default
		virtual ~IModule() noexcept = default

	public:
		/*
		** This function is called by the pipeline of module
		** Modules are called one after another
		*/
		virtual EModuleStatus run(
			IRequest &request,
			IResponse &response,
			IMapContainer &configuration,
			IMapContainer &session
		) = 0;

		/*
		** Get the name of the module to differentiate it from the others
		*/
		virtual const std::string getName() const = 0;
	};

}