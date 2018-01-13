/*
** EPITECH  PROJECT , 2020
** r-type
** File  description:
** 	No description
*/

#include <boost/exception/diagnostic_information.hpp>
#include <AsioServer.hpp>
#include <iostream>
#include "Logger.hpp"

int main(int ac, char **av)
{
	try {
		AsioServer server;
		server.start();
		server.tick();
	} catch(boost::system::system_error& e)
	{
		std::cout<<"Error: " << e.what()<< std::endl;
		std::cout<<"Info: "  << boost::diagnostic_information(e)
		         << std::endl;
		return 1;
		
	}
	return (0);
}
