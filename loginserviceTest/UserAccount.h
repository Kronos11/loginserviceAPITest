// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.


#ifndef LOGINSERVICE_ACCOUNTDATA_H
#define LOGINSERVICE_ACCOUNTDATA_H

#include <cstdint>
#include <string>

namespace LoginService {

// These are for DB queries.
//======================================================================================================================
class AccountData
{
public:
	AccountData(uint32_t Id, std::string user,std::string pass, uint32_t acct, bool banned, bool active, uint32_t charsAllowed, int8_t csr) 
	: mId(Id)
	, mUsername(user)
	, mPassword(pass)
	, mAccountId(acct)
	, mBanned(banned)
	, mActive(active)
	, mCharsAllowed(charsAllowed)
	, mCsr(csr) {};

  uint32_t              mId;
  std::string           mUsername;
  std::string           mPassword;
  uint32_t              mAccountId;
  bool					mBanned;
  bool	                mActive;
  uint32_t              mCharsAllowed;
  int8_t				mCsr;
};


//======================================================================================================================
class ServerData
{
public:
  uint32_t				mId;
  std::string			mName;
  std::string			mAddress;
  uint16_t              mConnectionPort;
  uint16_t              mPingPort;
  uint32_t              mPopulation;
  uint32_t              mStatus;
  uint32_t              mLastUpdate;
};

//======================================================================================================================
// Session_Key is used by the launcher
//======================================================================================================================
class SessionKeyData
{
public:
    std::string        mSessionKey;
};
} // end LoginService namespace
#endif // LOGINSERVICE_ACCOUNTDATA_H