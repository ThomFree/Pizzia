/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** HelloWorldModule
*/

#include "api/IModule.hpp"

#pragma once

namespace Pizzia {

/*
** This module simply return an http body that contain "Hello World !" for every request
*/
class HelloWorldModule : public IModule {
	public:
		HelloWorldModule() {}
		~HelloWorldModule() {}

	public:
		/*
		** The run function that set the rawData of IResponse
		*/
		EModuleStatus run(IRequest &/*req*/, IResponse &res, IMapContainer &/*config*/, IMapContainer &/*session*/) {
			res.setRaw("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 12\r\n\r\nHello World!");
			return EModuleStatus::SUCCESS; 
		}
		
		inline const std::string getName() const { return "HelloWorldModule"; }
};

}