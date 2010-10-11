// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.

#include "mysql_loginservice_impl.h"

// msyql
//#ifdef _WIN32
//#pragma warning (disable : 4251)
//#endif
//#include <mysql_connection.h>
//#include <mysql_driver.h>
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>
//#include <cppconn/prepared_statement.h>
//// Re-enable the warning.
//#ifdef _WIN32
//#pragma warning (default : 4251)
//#endif

/// Project namespace for the LoginService
namespace LoginService{

MysqlLoginService_Impl::MysqlLoginService_Impl(
	const std::string& hostname,
	const std::string& username,
	const std::string& password,
	const std::string& schema)
: hostname_(hostname)
, username_(username)
, password_(password)
, schema_(schema)
//, connection_(nullptr)
{
	// Get a handle to the driver. This should NOT be deleted as per
    // documenation for Connector/C++.
    //sql::Driver* driver = sql::mysql::get_driver_instance();
    //connection_.reset(
    //    driver->connect(hostname, username, password)
    //);

    //connection_->setSchema(schema);
}
	
MysqlLoginService_Impl::~MysqlLoginService_Impl(void)
{
}

std::unique_ptr<AccountData> MysqlLoginService_Impl::getUserAccountData(uint32_t id) const
{
	//std::unique_ptr<sql::PreparedStatement> statement(connection_->prepareStatement(
	//	"SELECT * FROM useraccount"
	//	"WHERE id = ? LIMIT 1"));
	//
	//statement->setUInt64(1,id);

	//std::unique_ptr<sql::ResultSet> result(statement->executeQuery());

	//// nothing found
	//if (!result->next()) 
	//{
	//	return nullptr;
	//}

	//std::unique_ptr<AccountData> userAccount(new AccountData(
	//	result->getUInt("id"),
	//	result->getString("username"),
	//	result->getString("password"),
	//	result->getUInt("accountId"),
	//	result->getBoolean("banned"),
	//	result->getBoolean("active"),
	//	result->getUInt("charsAllowed"),
	//	result->getInt("csr")));

	//return userAccount;
	return nullptr;
}

//std::unique_ptr<CharacterData> MysqlLoginService_Impl::getCharacterData(uint64_t characterId) const
//{
//	return nullptr;
//}

	
} // end LoginService namespace
