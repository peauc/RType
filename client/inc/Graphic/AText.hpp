/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_ATEXT_HPP_
# define RTYPE_ATEXT_HPP_

# include "Graphic/IText.hpp"

class AText : public IText
{
public:
	AText(const std::string &text) noexcept;
	AText(const AText &other) noexcept;
	AText &operator=(const AText &other) noexcept;
	~AText() override = default;
	
	void	setFont(const std::string &font) override = 0;
	void	setCharSize(uint32_t charSize) noexcept override = 0;
	void	setText(const std::string &text) noexcept override;
	void	setPosX(int x) noexcept override;
	void 	setPosY(int y) noexcept override;
	void	setPos(int x, int y) noexcept override;
	int	getPosX() const noexcept override;
	int	getPosY() const noexcept override;
	const std::string	&getText() const noexcept override;

protected:
	std::string	_text;
	int 		_x{0};
	int 		_y{0};
};

#endif // !RTYPE_ATEXT_HPP_