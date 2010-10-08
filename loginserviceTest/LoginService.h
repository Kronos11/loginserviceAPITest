// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.
#ifndef LOGINSERVICE_H_
#define LOGINSERVICE_H_

#include "LoginClient.h"
#include <list>
#include <map>
#include "anh\event.h"

using anh::BaseEvent;

class LoginService
{
public:
	LoginService();
	~LoginService();

	/**
	 *	Handles the Login Request from the client
	 *	
	 */
	void handleLoginRequest(LoginClient* client, const BaseEvent& bEvent);
	/**
	 *	Handles the request from the client to Delete Character
	 *
	 */
	void handleDeleteCharacter(LoginClient* client, const BaseEvent& bEvent);

private:
	/**
	 *	Checks to make sure the client is valid
	 *	\param[out] bool The result of the check
	 *  \param[in] LoginClient The Client sending the message
	 */
	bool isValidClient(LoginClient* client);
	/**
	 *	Calls the symphony service to create the Login Auth Token
	 *	\param[in] user The user
	 *	\param[in] pass the Password for the user
	 */
	std::string generateAuthToken(const std::string& user, const std::string& pass);
	/**
	 *	Sends the Galaxy List to the Client
	 *
	 */
	void sendGalaxyList(const std::string& authToken);
	/**
	 *	Sends the Cluster Status to the Client
	 *
	 */
	void sendClusterStatus(const std::string& authToken);
	/**
	 *	Sends appropriate error message to the Client
	 *
	 */
	void sendLoginErrorMessage(LoginClient* client, LoginClient::AUTH_RESULT result);
	/**
	 *	Gets the Character List to send back to the LoginClient
	 *
	 */
	std::string getCharacterList(const std::string& authToken);
	/**
	 *	Gets the cluster status from the Server Directory
	 *
	 */

	
public:
	uint32_t mLastClusterPulse;
};
#endif