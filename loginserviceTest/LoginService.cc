// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.

#include "LoginService.h"
#include "anh\event_dispatcher.h"

LoginService::LoginService()
{
	// load version

}
LoginService::~LoginService()
{
	//unload
}
void LoginService::handleLoginRequest(LoginClient* client, const BaseEvent& bEvent)
{
	// verify client and event
	if (!client)
	{
		// send error
		sendLoginErrorMessage(client, LoginClient::AUTH_FAILED);
		return;
	}
	if (isValidClient(client))
	{
		client->setAuthToken(generateAuthToken(client->getUserName(), client->getPassword()));
		//check the auth token is good
		sendLoginErrorMessage(client, LoginClient::AUTH_SUCCEEDED);
	}
	else
	{
		sendLoginErrorMessage(client, LoginClient::AUTH_INVALID_VERSION);
		return;
	}	
}

void LoginService::handleDeleteCharacter(LoginClient* client, const BaseEvent& bEvent)
{

}

bool LoginService::isValidClient(LoginClient* client)
{
	// make sure it's a valid client
	if (!client || client->getVersion() != "0.1.0")
	{
		return false;
	}
	return true;
}

std::string LoginService::generateAuthToken(const std::string& inUser, const std::string& inPass)
{
	//	connect to symphony web-api
	return "FAKE_AUTH_TOKEN";
}

void LoginService::sendLoginErrorMessage(LoginClient* client, LoginClient::AUTH_RESULT result)
{
	// send error message to client
	client->setState(result);

	// send packet too?
}