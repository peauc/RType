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
	ClientObjectManager();
	~ClientObjectManager() = default;
	void setMaxSize(size_t) noexcept;
	size_t size() const;
	std::vector<IMessage> getClientsMessages();
	bool addClient(ClientObject &client) noexcept;
	bool isClientContained(const ClientObject &client) const noexcept;
	ClientObject &getClientContained(const ClientObject &copy);
	void checkClientsTimeout() noexcept;
	bool isFull() const noexcept;
	void setMaxTimeoutTime(std::chrono::high_resolution_clock::time_point &time) noexcept;
//	long long int getTimeout() noexcept;
private:
	size_t _maxSize;
	std::chrono::steady_clock::time_point _maxTimeoutTimerStart;
	std::vector<ClientObject> _clientList;
};

#endif //RTYPE_CLIENTMANAGER_HPP
