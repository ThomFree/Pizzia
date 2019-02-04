/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** DecryptionModule
*/

#include "api/IModule.hpp"

#pragma once
namespace Pizzia {

class DecryptionModule : public IModule {
	public:
		DecryptionModule() {}
		~DecryptionModule() {}

	public:
        EModuleStatus run(IRequest &, IResponse &, IMapContainer &, IMapContainer &);
		inline const std::string getName() const { return "DecryptionModule"; }
};

}