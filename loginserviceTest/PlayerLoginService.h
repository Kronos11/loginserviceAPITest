// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.

#ifndef PLAYERLOGINSERVICE_H
#define PLAYERLOGINSERVICE_H

#include "LoginService_Impl.h"

#include <list>
#include <map>
#include "anh\event.h"

using anh::BaseEvent;

namespace LoginService{
class PlayerLoginService : public LoginService_Impl
{
public:

	/*!	Handles the Login Request from the client
	 *	\param client the LoginClient requesting login	
	 *	\param bEvent the Event containing the request
	 */
	virtual void handleLoginRequest(LoginClient& client, const BaseEvent& bEvent);
	/*! Handles the request from the client to Delete Character
	 *	\param authToken the token used for authenticating the 
	 *	client to ensure this is a valid transaction
	 *	\param bEvent the Event containing the request
	 */
	virtual void handleDeleteCharacter(const std::string& authToken, const BaseEvent& bEvent);

private:

	/*! Checks to make sure the client is valid
	 *  \param LoginClient The Client sending the message
	 *	\return true if the client is valid, false if not
	 */
	virtual bool isValidClient(const LoginClient& client);

	/*! Calls the symphony service to create the Login Auth Token
	 *	\param user The user
	 *	\param pass the Password for the user
	 */
	virtual std::string generateAuthToken(const std::string& user, const std::string& pass);

	/*! uses the auth token from the client to send the client the Galaxy List
	 *	\param authToken The token identifying the user
	 *
	 */
	virtual void sendGalaxyList(const std::string& authToken);

	/*! sends the status of the cluster to the client by firing off an event
	 *	\param authToken the token identifying the user
	 */
	virtual void sendClusterStatus(const std::string& authToken);

	/*! sends a message back to the client indicating an error has occured
	 *	\param client the LoginClient
	 *	\param result the state of the LoginClient
	 */
	virtual void sendLoginErrorMessage(LoginClient& client, LoginClient::AUTH_RESULT result);

	/*! sends the character list to the client depending on the type
	 *	\param authToken the token identifying the user
	 *	\param type the type
	 */
	virtual std::string getCharacterList(const std::string& authToken, LoginClient::ACCT_TYPE type);
	
public:
	uint32_t mLastClusterPulse;
};
}	//end LoginService namespace
#endif