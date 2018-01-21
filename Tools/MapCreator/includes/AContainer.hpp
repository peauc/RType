/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_ACONTAINER_HPP
#define MAPCREATOR_ACONTAINER_HPP

#include <memory>
#include <vector>
#include "AItem.hpp"

class AContainer : public AItem {

public:

	AContainer(AItem *parent = nullptr);
	virtual ~AContainer() = default;
	AContainer(const AContainer &obj);
	AContainer	&operator=(const AContainer &obj);

	virtual void	addChild(AItem *child);
	virtual void	lendBackgroundTexture(sf::Texture &texture);

protected:

	std::vector<std::shared_ptr<AItem>>	childs;


	unsigned int	childMarginTop;
	unsigned int	childMarginBot;
	unsigned int	childMarginLeft;
	unsigned int	childMarginRight;

};


#endif //MAPCREATOR_ACONTAINER_HPP
