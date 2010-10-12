// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.
#include "LoginService_Options.h"

#include <stdexcept>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;
/// Namespace for LoginService
namespace LoginService {
LoginServiceOptions::LoginServiceOptions(int argc, char* argv[])
: LoginServiceHostName()
, LoginServiceUserName()
, LoginServicePassword()
, LoginServiceSchema()
, cluster_name()
, process_address()
, process_port(0)
, log_directory() {    
    // Create a container to hold the filename of the configuration file.
    std::string config_filename;
    
    // Create a container to store the processed options.
    po::variables_map vm;
    
    // Declare the supported generic options.
    po::options_description generic("Generic options");
    generic.add_options()
        ("version,v", "Print version string")
        ("help", "Display the help message and program options")
        ("config,c", po::value<std::string>(&config_filename),
            "Name of a configuration file")
        ; // End of add_options
    
    // Declare a group of options that are required for application operation.
    po::options_description LoginService("LoginService options");
    LoginService.add_options()
        ("LoginService.db.hostname", po::value<std::string>(&LoginServiceHostName)->default_value("localhost"),
            "Hostname of the LoginService database")
        ("LoginService.db.username", po::value<std::string>(&LoginServiceUserName)->default_value("ls_user"),
            "Username to connect to the LoginService database with")
        ("LoginService.db.password", po::value<std::string>(&LoginServicePassword)->default_value("ls_pass"),
            "Password to connect to the LoginService database with")
        ("LoginService.db.schema", po::value<std::string>(&LoginServiceSchema)->default_value("LoginService"),
            "Schema name of the LoginService database")
        ; // End of add_options
        
    // Declare a group of Galaxy/cluster specific options.
    po::options_description galaxy("Galaxy/cluster options");
    galaxy.add_options()
        ("cluster.name", po::value<std::string>(&cluster_name),
            "The name of the Galaxy or cluster this server is a part of")
        ("process.address", po::value<std::string>(&process_address)->default_value("127.0.0.1"),
            "The public address to use for this process")
        ("process.port", po::value<uint16_t>(&process_port)->default_value(44990),
            "The (udp) port to connect to this server on")
        ; // End of add_options
    
    // Declare a group of logging specific options.
    po::options_description logging("Logging options");
    logging.add_options()
        ("log.directory", po::value<std::string>(&log_directory)->default_value("./"),
            "The directory where log files are stored.")
        ; // End of add_options
    
    // Group all of the option categories into one.
    po::options_description options("Allowed options");
    options.add(generic).add(LoginService).add(galaxy).add(logging);
    
    po::store(po::parse_command_line(argc, argv, options), vm);
    po::notify(vm);
    
    // If a configuration file was passed read from it.
    if (config_filename.length()) {
        // Group all of the option categories into one.
        po::options_description file_options("Config file options");
        file_options.add(LoginService).add(galaxy).add(logging);
        
        std::ifstream ifs(config_filename.c_str());
        if (!ifs) {
            std::cerr <<"Cannot open configuration file: " << config_filename << "\n";
            exit(1);
        } else {
            po::store(po::parse_config_file(ifs, file_options), vm);
            po::notify(vm);
        }
    }
    
    // Requesting the help parameter should display and exit the application.
    if (vm.count("help")) {
        std::cout << options << "\n";
        exit(0);
    }
    
    // Make sure at the very least a cluster name was given.
    if (!vm.count("cluster.name")) {
        throw std::runtime_error("No cluster name was given, aborting.");
    }
}
} // end LoginService Namespace