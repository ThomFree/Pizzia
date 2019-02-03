/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** HelloWorld
*/

#include "http/MapContainer.hpp"
#include "RequestDebuggerModule.hpp"
#include "api/EHttpMethod.hpp"

Pizzia::EModuleStatus Pizzia::RequestDebuggerModule::run(Pizzia::IRequest &req, Pizzia::IResponse &res, 
	Pizzia::IMapContainer &/*websiteConf*/, Pizzia::IMapContainer &/*session*/)
{
	std::string tmp;
	std::string params;

	/*
	** Everyting here is to create the html page
	*/
	for (auto it = req.getParameters().begin(); it != req.getParameters().end(); it++)
		params += it->first + "=" + it->second + " ";

	std::string headers;
	for (auto it = req.getHeaders().begin(); it != req.getHeaders().end(); it++)
		headers += it->first + "=" + it->second + " ";

	std::string method;
	for (auto it = methodMap.begin(); it != methodMap.end(); ++it )
		if (it->second == req.getMethod())
			method = it->first;
	tmp = "<html> \
			<h1>This is a Basic HTTP Page</h1> \
			<p>The request you sent was in HTTP" + std::to_string(req.getHttpVersion().first) + "." + std::to_string(req.getHttpVersion().second) + " \
			</br>You asked for " + req.getUri() + " with a " + method + " method \
			</p> \
			<p>You have sent a request that contains : \
				<ul> \
					<li>GET parameters : " + params + "</li> \
					<li>Headers : " + headers + "</li> \
					<li>Body : |START|" + req.getBody() + "|END| </li> \
				</ul> \
			</p> \
			<p> Everything was received has follow : </br>" + req.getRaw() + " \
		</html>";

	/*
	** Here we fill the Response instance
	*/
	res.setBody(tmp);
	res.getHeaders().put("Content-Type", std::string("text/html"));
	res.setHttpVersion(1, 1);
	res.setStatusCode(200);
	res.setStatusReasonPhrase("OK");
	return EModuleStatus::SUCCESS;
}