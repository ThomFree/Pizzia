/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** ResponseMakerModule
*/

#include "api/IModule.hpp"

#pragma once

namespace Pizzia {

class ResponseMakerModule : public IModule {
	public:
		ResponseMakerModule() = default;
		~ResponseMakerModule() = default;

    public:
        EModuleStatus run(IRequest &, IResponse &res, IMapContainer &, IMapContainer &) {
            std::string raw;
            res.getHeaders().put("Content-Length", std::to_string(res.getBody().size()));
            raw = "HTTP/" + std::to_string(res.getHttpVersion().first) + "." + std::to_string(res.getHttpVersion().second) + " " + std::to_string(res.getStatusCode()) + " " + res.getStatusReasonPhrase() + "\r\n";
            for (auto it = res.getHeaders().begin(); it != res.getHeaders().end(); it++)
                raw += it->first + ": " + it->second + "\r\n";
            raw += "\r\n" + res.getBody();
            res.setRaw(raw);
            return EModuleStatus::SUCCESS;
        }
		inline const std::string getName() const { return "ResponseMakerModule"; }

};

}