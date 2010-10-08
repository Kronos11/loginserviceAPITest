// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.
#ifndef LOGINCLIENT_H_
#define LOGINCLIENT_H_

#include <stdlib.h>
#include <string>
#include <cstdint>

/*	LoginClient represents the client that will be used to authenticate a user
*	
*
*/

class LoginClient
{
public:
	enum AUTH_RESULT
	{
		AUTH_SUCCEEDED = 0,
		AUTH_INVALID_VERSION,
		AUTH_INVALID_CREDENTIALS,
		AUTH_FAILED,
		AUTH_BANNED,
		AUTH_LOCKED
	};

	// getters & setters
	uint64_t getAccountId() { return mAccountId; }
	void setAccountId(uint64_t inAccId) { mAccountId = inAccId; }
	uint32_t getLoginClientId() { return mLoginClientId; }
	void setLoginClientId(uint32_t inLoginClientId) { mLoginClientId = inLoginClientId; }
	std::string getVersion() { return mVersion; }
	void setVersion(std::string inVersion) { mVersion = inVersion; }
	std::string getUserName() { return mUserName; }
	void setUserName(std::string inUser) { mUserName = inUser; }
	std::string getPassword() { return mPassword; } 
	void setPassword(std::string inPass) { mPassword = inPass; }
	std::string getAuthToken() { return mAuthToken; }
	void setAuthToken(std::string inToken) { mAuthToken = inToken; }
	AUTH_RESULT getState() { return mState; }
	void setState(AUTH_RESULT inState) { mState = inState; }

private:
	uint64_t mAccountId;
	uint32_t mLoginClientId;
	std::string mVersion;
	std::string mUserName;
	std::string mPassword;
	std::string mAuthToken;
	AUTH_RESULT mState;
};
#endif