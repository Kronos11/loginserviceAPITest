// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.
#include "LoginManager.h"
#include <glog\logging.h>

#include <iostream>
// LoginService namespace
namespace LoginService{
	
LoginManager::LoginManager(int argc, char* argv[])
: options_(argc, argv)
, mLoginClientList(nullptr)
, mLoginServiceList(nullptr)
{
	google::InitGoogleLogging(argv[0]);
	
	// set logging directory
	if (!options_.log_directory.empty()) {
		FLAGS_log_dir = options_.log_directory;
	}
	

}
std::unique_ptr<LoginService_Impl> LoginManager::createLoginService(LoginClient::ACCT_TYPE type) const
{
	// essentially this is a factory that crates new LoginServices
	switch (type)
	{
		case LoginClient::ACCT_PLAYER:
		case LoginClient::ACCT_GM:
		case LoginClient::ACCT_LAUNCHER:
			return std::unique_ptr<PlayerLoginService>(new PlayerLoginService());
			break;
		case LoginClient::ACCT_SOCIAL:
		case LoginClient::ACCT_WEB:
			break;
	}
	return nullptr;
}

void LoginManager::run()
{
	while (1)
	{
		// process new clients

		// take request check existing list to see if type exists
		// if not create new object then pass Client to service.
		mLoginServiceList->push_back(createLoginService(LoginClient::ACCT_PLAYER));
	}
}


}//end LoginService namespace
