/*
** EPITECH PROJECT, 2019
** CPP_zia_github
** File description:
** DecryptionModule
*/

#include "http/MapContainer.hpp"
#include "DecryptionModule.hpp"
#include "api/EHttpMethod.hpp"

/**
 * CAUTION !
 * THIS EXAMPLE IS VOLUNTARILY NOT COMPLETELY FUNCTIONAL IT IS JUST FOR UNDERSTAND THE CONCEPT
 */
Pizzia::EModuleStatus Pizzia::DecryptionModule::run(Pizzia::IRequest &req, Pizzia::IResponse &/*res*/,
    Pizzia::IMapContainer &/*websiteConf*/, Pizzia::IMapContainer &/*session*/)
{
	std::string cipherText = std::string(req.getRaw());
	std::string decryptedRequest = "";
	int n = 42;

	// Decrypt the cipherText of raw request into `decryptedRequest` using Caesar cipher with `n` = 42
	// More information here: https://en.wikipedia.org/wiki/Caesar_cipher
	for (unsigned int i = 0; i < cipherText.length(); i++)
	{
		if (islower(cipherText[i]))
			decryptedRequest += char(int(cipherText[i] + n - 97) % 26 + 97);
		else decryptedRequest += cipherText[i];

	}

	// Update the request to set the decrypted plaintext as raw
	req.setRaw(decryptedRequest);
	return EModuleStatus::SUCCESS;
}