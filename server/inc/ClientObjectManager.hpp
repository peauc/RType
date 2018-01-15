//
// Created by Clément Péau on 10/01/2018.
//

#ifndef RTYPE_CLIENTMANAGER_HPP
#define RTYPE_CLIENTMANAGER_HPP

#include <vector>
#include "IClientObject.hpp"

class ClientObjectManager {
public:
	size_t size() const;
	std::vector<IMessage> getClientsMessages();
private:
	std::vector<IClientObject> _clientList;
};

#endif //RTYPE_CLIENTMANAGER_HPP
