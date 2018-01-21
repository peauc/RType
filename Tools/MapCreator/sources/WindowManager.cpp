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
WindowManager::WindowManager() : gridLayout(this) {
	this->window.create(sf::VideoMode(1400,800,32),"MapCreator");
	this->setWidth(this->window.getSize().x);
	this->setHeight(this->window.getSize().y);
	this->gridLayout.fillParent();
	this->associateEvents();
}

void WindowManager::fillGridView() {
	auto	*listView = new ListView;
	auto	*mapView = new MapView(MapView::HORIZONTAL);
	auto	*mapModel = new MapModel(mapView);

	mapModel->setOutputDirectory(this->outputDirectory);
	mapModel->setExecDirectory(this->execDirectory);
	mapModel->setExistingMap(this->existingMap);
	mapView->setModel(new MapModel(mapView));
	this->gridLayout.addChild(mapView,
							  GridLayout::Range {15, 100, 15, 100,} );
	listView->setModel(new EnemiesListModel(this->enemiesDirectory,
											listView, mapView));
	this->gridLayout.addChild(listView,
							  GridLayout::Range {0, 15, 15, 100,} );
	listView = new ListView(ListView::HORIZONTAL);
	listView->setModel(new BackgroundsListModel(this->backgroundsDirectory,
												listView, mapView));
	this->gridLayout.addChild(listView,
							  GridLayout::Range {15, 100, 0, 15,} );
}

void WindowManager::start() {
	this->fillGridView();
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
	if (event.key.code == sf::Keyboard::Escape)
		this->window.close();
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
	this->actionsEvent[sf::Event::KeyPressed] =
			static_cast<AItem::Callback>(&WindowManager::onKeyPressed);
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

void WindowManager::setEnemiesDirectory(const std::string &enemiesDirectory) {
	this->enemiesDirectory = enemiesDirectory;
}

void WindowManager::setBackgroundsDirectory(
		const std::string &backgroundsDirectory) {
	this->backgroundsDirectory = backgroundsDirectory;
}

void WindowManager::setOutputDirectory(const std::string &outputDirectory) {
	this->outputDirectory = outputDirectory;
}

void WindowManager::setExecDirectory(const std::string &execDirectory) {
	this->execDirectory = execDirectory;
}

void WindowManager::setExistingMap(const std::string &existingMap) {
	this->existingMap;
}

