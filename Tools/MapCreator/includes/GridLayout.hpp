/*
** EPITECH PROJECT , 2020
** MapCreator
** File description :
** No description
*/

#ifndef MAPCREATOR_GRIDLAYOUT_HPP
#define MAPCREATOR_GRIDLAYOUT_HPP

#include "AContainer.hpp"

class GridLayout : public AContainer {

public:

	GridLayout(AItem *parent);
	~GridLayout() = default;
	GridLayout(const GridLayout&) = delete;
	GridLayout	&operator=(const GridLayout&) = delete;

	struct Range {
		int		pSWidth;
		int		pEWidth;
		int		pSHeight;
		int		pEHeight;

		Range(int pSWidth, int pEWidth,
			  int pSHeight, int pEHeight)
		{
			this->pSWidth = (pSWidth > 100 ? 100 : pSWidth);
			this->pEWidth = (pEWidth > 100 ? 100 : pEWidth);
			this->pSHeight = (pSHeight > 100 ? 100 : pSHeight);
			this->pEHeight = (pEHeight > 100 ? 100 : pEHeight);
		}
	};


	virtual void	displayOnWindow(sf::RenderWindow &window);
	virtual void	associateEvents();
	virtual void	receiveEvent(const sf::Event &event);
	virtual void	refresh();

	virtual void	addChild(AItem *child, const Range &range);

private:

	int	getPValue(int p, int value) const;
};


#endif //MAPCREATOR_GRIDLAYOUT_HPP
