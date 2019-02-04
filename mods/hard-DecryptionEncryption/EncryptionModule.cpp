/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** EncryptionModule
*/

#include "http/MapContainer.hpp"
#include "EncryptionModule.hpp"
#include "api/EHttpMethod.hpp"

/**
 * CAUTION !
 * THIS EXAMPLE IS VOLUNTARILY NOT COMPLETELY FUNCTIONAL IT IS JUST FOR UNDERSTAND THE CONCEPT
 */
Pizzia::EModuleStatus Pizzia::EncryptionModule::run(Pizzia::IRequest &/*req*/, Pizzia::IResponse &res,
	Pizzia::IMapContainer &/*websiteConf*/, Pizzia::IMapContainer &/*session*/)
{
	std::string cipherText;
	std::string rawResponse = res.getRaw();
	int n = 42;

	// Encrypt the raw response into `cipherText` using Caesar cipher with `n` = 42
	// More information here: https://en.wikipedia.org/wiki/Caesar_cipher
	for (unsigned int i = 0; i < rawResponse.length(); i++)
	{
		if (islower(rawResponse[i]))
			cipherText += char(int(rawResponse[i] - n - 97) % 26 + 97);
		else cipherText += rawResponse[i];

	}

	// Update the response to set the encrypted cipher text as raw
	res.setRaw(cipherText);
	return EModuleStatus::SUCCESS;
}