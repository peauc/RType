/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "EnemiesListModel.hpp"
#include "BackgroundsListModel.hpp"
#include "ListView.hpp"
#include "MapView.hpp"
#include "WindowManager.hpp"

//TODO Rajouter paramètres des dossiers pour les models
WindowManager::WindowManager(const std::string &enemiesDirectory,
							 const std::string &backgroundsDirectory,
							 const std::string &dest) : gridLayout(this) {
	this->window.create(sf::VideoMode(1400,800,32),"MapCreator");
	this->setWidth(this->window.getSize().x);
	this->setHeight(this->window.getSize().y);
	this->gridLayout.fillParent();
	this->fillGridView(enemiesDirectory, backgroundsDirectory, dest);
	this->associateEvents();
}

void WindowManager::fillGridView(const std::string &enemiesDirectory,
								 const std::string &backgroundsDirectory,
								 const std::string &dest) {
	auto	*listView = new ListView;
	auto	*mapView = new MapView(MapView::HORIZONTAL);

	//mapView->setModel(new EnemiesListModel("", listView));
	this->gridLayout.addChild(mapView,
							  GridLayout::Range {15, 100, 15, 100,} );
	listView->setModel(new EnemiesListModel(enemiesDirectory,
											listView, mapView));
	this->gridLayout.addChild(listView,
							  GridLayout::Range {0, 15, 15, 100,} );
	listView = new ListView(ListView::HORIZONTAL);
	listView->setModel(new BackgroundsListModel(backgroundsDirectory,
												listView, mapView));
	this->gridLayout.addChild(listView,
							  GridLayout::Range {15, 100, 0, 15,} );
}

void WindowManager::start() {
	this->timePoint = std::chrono::system_clock::now();
	while (this->window.isOpen()) {
		sf::Event event;
		while (this->window.pollEvent(event)) {
			this->receiveEvent(event);
		}
		if (this->needRefresh())
			this->refresh();
	}
}

bool WindowManager::needRefresh() {
	this->currentTime = std::chrono::system_clock::now();
	long timePassed = std::chrono::duration_cast<std::chrono::milliseconds>
			(this->currentTime - this->timePoint).count();
	if (timePassed >= 50) {
		this->timePoint = std::chrono::system_clock::now();
		return (true);
	}
	return (false);
}

void WindowManager::onClosed(const sf::Event &event) {
	this->window.close();
}

void WindowManager::onResized(const sf::Event &event) {

}

void WindowManager::onLostFocus(const sf::Event &event) {

}

void WindowManager::onGainedFocus(const sf::Event &event) {

}

void WindowManager::onKeyPressed(const sf::Event &event) {

}

void WindowManager::onKeyReleased(const sf::Event &event) {

}

void WindowManager::onMouseEntered(const sf::Event &event) {

}

void WindowManager::onMouseLeft(const sf::Event &event) {

}

void WindowManager::displayOnWindow(sf::RenderWindow &window) {
	this->window.draw(this->background);
	this->gridLayout.displayOnWindow(this->window);
}

void WindowManager::associateEvents() {
	this->actionsEvent[sf::Event::Closed] =
			static_cast<AItem::Callback>(&WindowManager::onClosed);
}

void WindowManager::receiveEvent(const sf::Event &event) {
	if (this->actionsEvent[event.type])
		(this->*(this->actionsEvent[event.type]))(event);
	this->gridLayout.receiveEvent(event);
}

void WindowManager::refresh() {
	this->window.clear(sf::Color::Black);
	this->displayOnWindow(this->window);
	this->window.display();
}

