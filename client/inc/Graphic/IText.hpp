/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_ITEXT_HPP
# define RTYPE_ITEXT_HPP

# include <string>

class	IText
{
public:
	virtual ~IText() = default;
	virtual void	setText(const std::string &text) = 0;
	virtual void	setFont(const std::string &font) = 0;
	virtual void	setCharSize(uint32_t charSize) = 0;
	virtual void	setPosX(int x) = 0;
	virtual void	setPosY(int y) = 0;
	virtual void	setPos(int x, int y) = 0;
	virtual const	std::string &getText() const = 0;
	virtual int 	getPosX() const = 0;
	virtual int	getPosY() const = 0;
};
#endif //RTYPE_ITEXT_HPP
