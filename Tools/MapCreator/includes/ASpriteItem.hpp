/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_ASPRITEITEM_HPP
#define MAPCREATOR_ASPRITEITEM_HPP

#include <memory>
#include "AItem.hpp"

class ASpriteItem : public AItem {

public:

	ASpriteItem(AItem *parent = nullptr);
	~ASpriteItem() = default;
	ASpriteItem(const ASpriteItem &obj);
	ASpriteItem		&operator=(const ASpriteItem&) = delete;

protected:

	virtual void	displayOnlyInParentBounds() = 0;
	virtual void	refresh();

	sf::Texture		texture;
	sf::Sprite		icon;

	int		getXTexture();
	int		getYTexture();
	int 	getWidthTexture();
	int 	getHeightTexture();
	float	getScaleX();
	float	getScaleY();
	int		getXOutSize();
	int		getYOutSize();

	int		getRealWidth();
	int		getRealHeight();

	float	getRealScaleX();
	float 	getRealScaleY();

	bool	needMoveXTexture();
	bool	needReduceWidthTexture();
	bool	needMoveYTexture();
	bool	needReduceHeightTexture();
};


#endif //MAPCREATOR_ASPRITEITEM_HPP
