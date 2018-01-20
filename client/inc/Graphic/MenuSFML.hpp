/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_MENUSFML_HPP_
# define RTYPE_MENUSFML_HPP_

# include <memory>
# include <vector>
# include "Graphic/IMenu.hpp"
# include "Graphic/ISprite.hpp"
# include "Graphic/IText.hpp"

class	MenuSFML : public IMenu
{
public:
	MenuSFML();
	MenuSFML(std::vector<const ISprite*> sprites) noexcept;
	MenuSFML(const MenuSFML &) = delete;
	MenuSFML &operator=(const MenuSFML &) = delete;
	~MenuSFML() override = default;
	
	std::vector<const ISprite *> &getSpritesToDraw() noexcept override;
	std::vector<const IText *> &getTextsToDraw() noexcept override;
	void	addSprite(const ISprite *sprite) noexcept override;
	void	addText(const IText *text) noexcept override;
	
private:
	std::vector<const ISprite*> _sprites;
	std::vector<const IText*> _texts;
};

#endif // !RTYPE_MENUSFML_HPP_