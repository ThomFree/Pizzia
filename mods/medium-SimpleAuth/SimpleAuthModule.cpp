/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** SimpleAuthModule
*/

#include "http/MapContainer.hpp"
#include "SimpleAuthModule.hpp"
#include "api/EHttpMethod.hpp"

Pizzia::EModuleStatus Pizzia::SimpleAuthModule::run(Pizzia::IRequest &req,
	Pizzia::IResponse &res, Pizzia::IMapContainer &/*websiteConf*/,
	Pizzia::IMapContainer &/*session*/)
{
	// If the `username` or `password` parameter are missing
	if (!req.getParameters().has("username") || !req.getParameters().has("password")) {
		res.setBody("<h1>Error: Username or password parameter are empty</h1>");
		// We set an 422 - Unprocessable Entity status: https://developer.mozilla.org/en-US/docs/Web/HTTP/Status/422
		res.setStatusCode(422);
		res.setStatusReasonPhrase("Unprocessable Entity");
	} else if (req.getParameters().getString("username") != "foo" || req.getParameters().getString("password") != "bar") {
		res.setBody("<h1>Error: Username or password parameter are bad</h1>");
		// We set an 401 - Unauthorized: https://developer.mozilla.org/en-US/docs/Web/HTTP/Status/401
		res.setStatusCode(401);
		res.setStatusReasonPhrase("Unauthorized");
	} else {
		res.setBody("<h1>Welcome !</h1><br /><img src=\"https://i.imgur.com/UuePYRp.jpg\">");
		res.setStatusCode(200);
		res.setStatusReasonPhrase("OK");
	}

	res.getHeaders().put("Content-Type", std::string("text/html"));
	res.setHttpVersion(1, 1);
	return EModuleStatus::SUCCESS;
}