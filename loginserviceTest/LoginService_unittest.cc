// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.
#include <gtest\gtest.h>
#include "LoginClient.h"
#include "LoginService.h"
#include "tests\MockObjects\MockEvent.h"

#pragma once
namespace
{
class LoginService_unittest : public ::testing::Test
{
protected:
	LoginClient* client;
	virtual void SetUp()
	{
		client = new LoginClient();
		client->setAccountId(1);
		client->setLoginClientId(123456);
		client->setUserName("Test");
		client->setPassword("swganh");
		client->setVersion("0.1.0");
	}
};

TEST_F(LoginService_unittest, handleLoginRequestSuccess)
{
	LoginService service;
	MockEvent ev;
	service.handleLoginRequest(client, ev);
	EXPECT_EQ("FAKE_AUTH_TOKEN", client->getAuthToken());
	EXPECT_EQ(LoginClient::AUTH_SUCCEEDED, client->getState());
}

TEST_F(LoginService_unittest, handleLoginRequestFailureByVersion)
{
	LoginService service;
	client->setVersion("x.x.x");
	MockEvent ev;
	service.handleLoginRequest(client, ev);
	EXPECT_EQ(LoginClient::AUTH_INVALID_VERSION, client->getState());
}
} //end namespace

