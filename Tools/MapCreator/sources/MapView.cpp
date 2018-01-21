/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#include "ChildMap.hpp"
#include "MapView.hpp"

MapView::MapView(Scroll scroll, AItem *parent)
		: AContainer(parent), spriteBackground(this) {
	this->scroll = scroll;
	this->scrollable = true;
	this->maxScroll = 0;
	this->scrollSpeed = 30;
	this->scrollValue = 0;
	this->childMarginTop = 0;
	this->childMarginBot = 0;
	this->childMarginLeft = 0;
	this->childMarginRight = 0;
	this->lastMouseX = 0;
	this->lastMouseY = 0;
	this->background.setFillColor(sf::Color::White);
	this->associateEvents();
}

void MapView::displayOnWindow(sf::RenderWindow &window) {
	unsigned int	repeat = 0;

	window.draw(this->background);
	while (repeat < 1 || -this->scrollValue > this->getWidth() * (repeat - 1)) {
		this->spriteBackground.setX(this->getX()
									+ this->scrollValue
									+ repeat * this->getWidth());
		this->spriteBackground.refresh();
		this->spriteBackground.displayOnWindow(window);
		++repeat;
	}
	for (auto &child : this->childs)
		child->displayOnWindow(window);
}

void MapView::associateEvents() {
	this->actionsEvent[sf::Event::MouseWheelScrolled] =
			static_cast<AItem::Callback>(&MapView::onMouseWheelScrolled);
	this->actionsEvent[sf::Event::MouseButtonPressed] =
			static_cast<AItem::Callback>(&MapView::onMouseButtonPressed);
	this->actionsEvent[sf::Event::MouseButtonReleased] =
			static_cast<AItem::Callback>(&MapView::onMouseButtonReleased);
	this->actionsEvent[sf::Event::MouseMoved] =
			static_cast<AItem::Callback>(&MapView::onMouseMoved);
	this->actionsEvent[sf::Event::KeyPressed] =
			static_cast<AItem::Callback>(&MapView::onKeyPressed);
}

void MapView::receiveEvent(const sf::Event &event) {
	if (this->actionsEvent[event.type])
		(this->*(this->actionsEvent[event.type]))(event);
}

void MapView::refresh() {
	this->spriteBackground.setX(this->getX() + this->scrollValue);
	this->spriteBackground.refresh();
	for (auto &child : this->childs) {
		auto	*upChild = dynamic_cast<ChildMap*>(child.get());

		upChild->setX(upChild->getX()
					  + (this->scrollValue - upChild->getScrollValue()));
		upChild->setScrollValue(this->scrollValue);
		child->refresh();
	}
}

void MapView::addChild(AItem *child) {
	dynamic_cast<ChildMap*>(child)->setScrollValue(this->scrollValue);
	dynamic_cast<ChildMap*>(child)->setResizing(false);
	child->setX(this->getX());
	child->setY(this->getY());
	child->setParent(this);
	AContainer::addChild(child);
	this->refresh();
}

void MapView::setModel(MapModel *model) {
	this->model.reset(model);
	this->model->loadDataModel();
}

void MapView::lendBackgroundTexture(sf::Texture &texture) {
	this->spriteBackground.setTexture(texture);
}

void MapView::onMouseWheelScrolled(const sf::Event &event) {
	int		newScrollValue;

	if (this->inBounds(event.mouseWheelScroll.x, event.mouseWheelScroll.y)) {
		if (this->scrollable) {
			newScrollValue = static_cast<int>(this->scrollValue
											  + event.mouseWheelScroll.delta
												* this->scrollSpeed);
			if (newScrollValue < 0)
				this->scrollValue = newScrollValue;
			else
				this->scrollValue = 0;
		} else
			this->resizeChild(event);
		this->refresh();
	}
}

void MapView::onMouseButtonPressed(const sf::Event &event) {
	unsigned int	childIndex;

	this->scrollable = false;
	if (!this->childs.empty() && event.mouseButton.button == sf::Mouse::Left) {
		childIndex = this->getClosestChild(event.mouseButton.x,
										   event.mouseButton.y);

		this->childs.at(childIndex)->receiveEvent(event);
	} else if (event.mouseButton.button == sf::Mouse::Right) {
		for (auto &child : this->childs)
			child->receiveEvent(event);
		if (!this->onExistingZone(event))
			this->createZone(event);

	}
}

void MapView::onMouseButtonReleased(const sf::Event &event) {
	this->scrollable = true;
	for (auto child = this->childs.begin(); child != this->childs.end();) {
		auto	*upChild = dynamic_cast<ChildMap*>((*child).get());

		if (upChild->isResizing()
			&& (upChild->getWidth() < 10 || upChild->getHeight() < 10)) {
			child = this->childs.erase(child);
		} else {
			upChild->receiveEvent(event);
			++child;
		}
	}
}

void MapView::onMouseMoved(const sf::Event &event) {
	this->lastMouseX = event.mouseMove.x;
	this->lastMouseY = event.mouseMove.y;
	for (auto &child : this->childs)
		child->receiveEvent(event);
}

void MapView::onKeyPressed(const sf::Event &event) {
	unsigned int	childIndex;

	if (event.key.code == sf::Keyboard::Delete && !this->childs.empty()) {
		childIndex = this->getClosestChild(this->lastMouseX, this->lastMouseY);

		if (this->childs.at(childIndex)
				->inBounds(this->lastMouseX,
						   this->lastMouseY))
			this->childs.erase(std::next(this->childs.begin(), childIndex));
	} else if (event.key.code == sf::Keyboard::Return && this->model)
		this->model->saveMap();
}

unsigned int MapView::getClosestChild(int x, int y) {
	unsigned int	childIndex = 0;
	unsigned int	index = 0;
	int				distanceX;
	int 			distanceY;
	int				closestX = 0;
	int 			closestY = 0;
	bool			init = false;

	for (auto &child : this->childs) {
		distanceX = std::abs((child->getX() + child->getWidth() / 2) - x);
		distanceY = std::abs((child->getY() + child->getHeight() / 2) - y);
		if (!init || (distanceX + distanceY < closestX + closestY)) {
			closestX = distanceX;
			closestY = distanceY;
			childIndex = index;
			init = true;
		}
		++index;
	}
	return (childIndex);
}

void MapView::resizeChild(const sf::Event &event) {
	unsigned int	childIndex;
	int				newWidth = 0;
	int 			newHeight = 0;

	if (this->childs.empty())
		return;
	childIndex = this->getClosestChild(this->lastMouseX, this->lastMouseY);
	if (this->childs.at(childIndex)->inBounds(this->lastMouseX,
											  this->lastMouseY)) {
		newWidth += (this->childs.at(childIndex)->getWidth() / 20)
					* -event.mouseWheelScroll.delta;
		newHeight += (this->childs.at(childIndex)->getHeight() / 20)
					 * -event.mouseWheelScroll.delta;
		this->changeSize(childIndex, newWidth, newHeight);
	}
}

void MapView::changeSize(unsigned int childIndex,
						 int newWidth, int newHeight) {
	int		x;

	x = dynamic_cast<ChildMap*>(this->childs.at(childIndex).get())->getX();
	dynamic_cast<ChildMap*>(this->childs.at(childIndex).get())
			->setX(x - newWidth / 2);
	this->childs.at(childIndex)
			->setY(this->childs.at(childIndex)->getY() - newHeight / 2);
	this->childs.at(childIndex)
			->setWidth(this->childs.at(childIndex)->getWidth() + newWidth);
	this->childs.at(childIndex)
			->setHeight(this->childs.at(childIndex)->getHeight()
						+ newHeight);
}

void MapView::createZone(const sf::Event &event) {
	auto	*child = new ChildMap;

	this->addChild(child);
	this->sortChilds();
	child->setResizing(true);
	child->setX(event.mouseButton.x);
	child->setY(event.mouseButton.y);
}

void MapView::sortChilds() {
	std::sort(this->childs.begin(), this->childs.end(),
			  [](std::shared_ptr<AItem> one, std::shared_ptr<AItem> two) {
				  auto	*upOne = dynamic_cast<ChildMap*>(one.get());
				  auto	*upTwo = dynamic_cast<ChildMap*>(two.get());

				  if (upOne->getPathItem().empty()
					  && upTwo->getPathItem().empty())
					  return (true);
				  return (upOne->getPathItem().empty());
			  });
}

bool MapView::onExistingZone(const sf::Event &event) {
	for (auto &child : this->childs) {
		auto	*upChild = dynamic_cast<ChildMap*>(child.get());

		if (upChild->getPathItem().empty()
			&& upChild->inBounds(event.mouseButton.x, event.mouseButton.y))
			return (true);
	}
	return (false);
}
