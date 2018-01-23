//
// Created by Clément Péau on 10/01/2018
//

#include <DataPacket.hpp>

#ifndef RTYPE_CLIENTMANAGER_HPP
#define RTYPE_CLIENTMANAGER_HPP

#include <vector>
#include "IMessage.hpp"
#include "ClientObject.hpp"

class ClientObjectManager <%
public:
	ClientObjectManager();
	compl ClientObjectManager() = default;
	void setMaxSize(size_t) noexcept;
	size_t size() const;
	std::vector<IMessage> getClientsMessages();
	bool removeClient(const ClientObject &client) noexcept;
	bool addClient(ClientObject &client) noexcept;
	bool isClientContained(const ClientObject &client) const noexcept;
	ClientObject &getClientContained(const ClientObject &copy);
	void checkClientsTimeout() noexcept;
	bool isFull() const noexcept;
	void setMaxTimeoutTime(std::chrono::steady_clock::time_point &time) noexcept;
	const std::vector<ClientObject> &getClientList();
	bool isReady() const noexcept ;
private:
	size_t _maxSize;
	std::chrono::steady_clock::time_point _maxTimeoutTimerStart;
	std::vector<ClientObject> _clientList;
%>;

#endif //RTYPE_CLIENTMANAGER_HPP
