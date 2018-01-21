/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_TEXTSFML_HPP_
# define RTYPE_TEXTSFML_HPP_

# include <SFML/Graphics/Text.hpp>
# include "Graphic/AText.hpp"

class TextSFML : public AText
{
public:
	TextSFML(const std::string &font,
		 const std::string &text = "",
		 uint32_t charSize = 24) noexcept;
	TextSFML(const TextSFML &other) noexcept;
	TextSFML &operator=(const TextSFML &other) noexcept;
	~TextSFML() override = default;
	
	void setText(const std::string &text) noexcept override;
	void setFont(const std::string &font) override;
	void setCharSize(uint32_t charSize) noexcept override;
	void setPosX(int x) noexcept override;
	void setPosY(int y) noexcept override;
	void setPos(int x, int y) noexcept override;
	const std::string &getText() const noexcept override;
	const sf::Text &getSText() const noexcept;

private:
	sf::Text	_sText;
	sf::Font	_font;
};

#endif // !RTYPE_TEXTSFML_HPP_