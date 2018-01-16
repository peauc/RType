//
// Created by Clément Péau on 10/01/2018.
//

#ifndef RTYPE_CLIENTMANAGER_HPP
#define RTYPE_CLIENTMANAGER_HPP

#include <vector>
#include "IMessage.hpp"
#include "ClientObject.hpp"


class ClientObjectManager {
public:
	size_t size() const;
	std::vector<IMessage> getClientsMessages();
	bool addClient(ClientObject &client) noexcept;
	bool isClientContained(ClientObject &client) noexcept;
private:
	std::vector<ClientObject> _clientList;
};

#endif //RTYPE_CLIENTMANAGER_HPP
