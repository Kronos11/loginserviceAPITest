// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.
#ifndef LOGINSERVICE_OPTIONS_H
#define LOGINSERVICE_OPTIONS_H

#include <cstdint>
#include <string>

/// Namespace for LoginService
namespace LoginService {
class LoginServiceOptions
{
public:
	/*! only constructor accepts param for command line args
	*  \param argc Command line args passed from main()
	*  \param argv Command line args passed from main()
	*  \returns A data struct of the options used by the LoginService app.
	*/
	LoginServiceOptions(int argc, char* argv[]);

	/// Hostname of the data store in "tcp://127.0.0.1:3306" or "localhost" format
	std::string LoginServiceHostName;

	/// The username to connect to the data store with.
    std::string LoginServiceUserName;
    
    /// The password to connect to the data store with.
    std::string LoginServicePassword;
    
    /// The schema (or dbname) to connect to.
    std::string LoginServiceSchema;
    
    /// The name of the cluster to join with.
    std::string cluster_name;
    
    /// The address the active process will listen on.
    std::string process_address;
    
    /// The (udp) port the active process will listen on.
    uint16_t process_port;
    
    /// The directory to store log files in.
    std::string log_directory;
private:
	LoginServiceOptions();
};
} // end LoginService Namespace
#endif //LOGINSERVICE_OPTIONS_H