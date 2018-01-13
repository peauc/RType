//
// Created by Clément Péau on 10/01/2018.
//

#ifndef RTYPE_CLIENTMANAGER_HPP
#define RTYPE_CLIENTMANAGER_HPP

#include <vector>
#include "IClient.hpp"

class ClientManager {
public:
	size_t size() const;
	std::vector<IMessage> getClientsMessages();
private:
	std::vector<IClient> _clientList;
};

#endif //RTYPE_CLIENTMANAGER_HPP
