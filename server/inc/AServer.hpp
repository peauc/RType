/*
** EPITECH  PROJECT , 2020
** r-type
** File  description:
** 	No description
*/

#ifndef ASERVER_HPP
#define ASERVER_HPP
class AServer {
public:
	virtual bool start() = 0 {
		return (false);
	}
	virtual bool stop() = 0 {
		return(false);
	}
	virtual~AServer() = 0 {};
};

#endif //ASERVER_HPP
