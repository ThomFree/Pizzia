/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** EModuleStatus
*/

#pragma once

namespace Pizzia {

	/*
	** This enum contain all the different return value that 
	** a module can answer
	*/
	enum EModuleStatus {
		
		/*
		** Everything is OK
		*/
		SUCCESS,

		/*
		** An error occured, module flow is interrupted but a 
		** respond message is sent to the client
		*/
		ERROR,

		/*
		** An unrecoverable error occured, module flow 
		** is interrupted and the server sends nothing to the client
		*/
		FATAL_ERROR,
	};

}