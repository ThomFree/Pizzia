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
	class IModule {
	public:
		IModule() {}
		virtual ~IModule() {}

	public:
		virtual EModuleStatus run(
			IRequest &request,
			IResponse &response,
			IMapContainer &configuration,
			IMapContainer &session
		) = 0;

		virtual const std::string getName() const = 0;
	};
}