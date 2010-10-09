// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.
#ifndef LOGINSERVICE_IMPL_H
#define LOGINSERVICE_IMPL_H

#include "LoginClient.h"
#include "mysql_loginservice_impl.h"
#include "anh\event.h"

using namespace anh;
// LoginService namespace
namespace LoginService{
class LoginService_Impl
{
public:
	virtual ~LoginService_Impl() {} 
	/*!	Handles the Login Request from the client
	 *	
	 * \param client The LoginClient data object
	 * \param bEvent The event that has the packet information
	 */
	virtual void handleLoginRequest(LoginClient& client, const BaseEvent& bEvent) = 0;
	/*!	Handles the request from the client to Delete Character
	 *
	 * \param client The LoginClient data object
	 * \param bEvent The event that has the packet information
	 */
	virtual void handleDeleteCharacter(const std::string& authToken, const BaseEvent& bEvent) = 0;

private:
	/*!	Checks to make sure the client is valid
	 *
	 *  \param LoginClient The Client sending the message
	 *	\returns bool The result of the check
	 */
	virtual bool isValidClient(const LoginClient& client) = 0;
	/**
	 *	Calls the symphony service to create the Login Auth Token
	 *	\param user The user
	 *	\param pass the Password for the user
	 */
	virtual std::string generateAuthToken(const std::string& user, const std::string& pass) = 0;
	/**
	 *	Sends the Galaxy List to the Client
	 *
	 */
	virtual void sendGalaxyList(const std::string& authToken) = 0;
	/**
	 *	Sends the Cluster Status to the Client
	 *
	 */
	virtual void sendClusterStatus(const std::string& authToken) = 0;
	/**
	 *	Sends appropriate error message to the Client
	 *
	 */
	virtual void sendLoginErrorMessage(LoginClient& client, LoginClient::AUTH_RESULT result) = 0;
	/**
	 *	Gets the Character List to send back to the LoginClient
	 *
	 */
	virtual std::string getCharacterList(const std::string& authToken, LoginClient::ACCT_TYPE type) = 0;
	/**
	 *	Gets the cluster status from the Server Directory
	 *
	 */
};
} //end LoginService namespace
#endif