// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.

#ifndef LOGINSERVICE_MYSQL_LOGINSERVICE_IMPL_H
#define LOGINSERVICE_MYSQL_LOGINSERVICE_IMPL_H

#include <memory>
#include <string>

#include <boost/noncopyable.hpp>

namespace sql {
	class Connection;
}

/// Project namespace for the LoginService
namespace LoginService{

class MysqlLoginService_Impl : boost::noncopyable
{
public:
	MysqlLoginService_Impl(const std::string& hostname,
							const std::string& username,
							const std::string& password,
							const std::string& schema);
	~MysqlLoginService_Impl(void);
protected:
private:
	MysqlLoginService_Impl();
	
	std::string hostname_;
    std::string username_;
    std::string password_;
    std::string schema_;
    
	std::unique_ptr<sql::Connection> connection_;
};

} // end LoginService namespace
#endif