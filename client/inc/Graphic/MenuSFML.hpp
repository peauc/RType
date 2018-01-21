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
	MenuSFML() = default;
	MenuSFML(const MenuSFML &) = delete;
	MenuSFML &operator=(const MenuSFML &) = delete;
	~MenuSFML() override = default;
	
	const std::vector<std::unique_ptr<ISprite>>
			&getSpritesToDraw() const noexcept override;
	const std::vector<std::unique_ptr<IText>>
			&getTextsToDraw() const noexcept override;
	void	addSprite(std::unique_ptr<ISprite>sprite) noexcept override;
	void	addText(std::unique_ptr<IText> text) noexcept override;
	
private:
	std::vector<std::unique_ptr<ISprite>> _sprites;
	std::vector<std::unique_ptr<IText>> _texts;
};

#endif // !RTYPE_MENUSFML_HPP_