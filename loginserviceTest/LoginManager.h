// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.
#ifndef PLAYERLOGINMANAGER_H
#define PLAYERLOGINMANAGER_H

#include "LoginService_Impl.h"
#include "mysql_loginservice_impl.h"

#include <list>

// LoginService namespace
namespace LoginService{

typedef std::unique_ptr<std::list<LoginClient*>>(LoginClientList);
/*!	Controls all login services,
*	client logins and registers with
*	the server directory.
*/
class LoginManager
{
public:
	LoginManager(void);
	~LoginManager(void);

	/*! Creates a new LoginService of the type specified
	*	\param type The Login Service type required by client
	*	\returns Returns an instance of the specified type of LoginService
	*/
	std::unique_ptr<LoginService_Impl> createLoginService(const LoginClient::ACCT_TYPE& type) const;
private:
	LoginClientList			mLoginClientList;
};
}//end LoginService namespace

#endif
