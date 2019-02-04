/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** EncryptionModule
*/

#include "api/IModule.hpp"

#pragma once
namespace Pizzia {

class EncryptionModule : public IModule {
	public:
		EncryptionModule() {}
		~EncryptionModule() {}

	public:
        EModuleStatus run(IRequest &, IResponse &, IMapContainer &, IMapContainer &);
		inline const std::string getName() const { return "EncryptionModule"; }
};

}