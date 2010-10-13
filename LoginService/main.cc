// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.

#include <iostream>
#include "LoginService.h"
#include "LoginManager.h"



int main(int argc, char *argv[])
{
	std::cout << "Starting Login Service v0.1.0\n";
	
	LoginService::LoginManager login(argc, argv);

	login.run();

	return 0;
}