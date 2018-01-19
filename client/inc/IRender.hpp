/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_IRENDER_HPP
# define RTYPE_IRENDER_HPP

# include <string>
# include <queue>
# include "Texture.hpp"
# include "ISprite.hpp"

class IRender
{
public:
	virtual ~IRender() = default;

	virtual void	openWindow(unsigned int width, unsigned int height,
				   const std::string &windowName) = 0;
	virtual bool	isWindowOpen() = 0;
	virtual void	display() = 0;
	virtual void	clear() = 0;
	virtual void	closeWindow() = 0;
	virtual void	draw(const ISprite *sprite) = 0;
	virtual std::unique_ptr<ISprite> createSprite(const std::string
						      &fileName,
						      uint32_t sizeTileX,
						      uint32_t sizeTileY) = 0;
	virtual void	setAnimationToSprite(ISprite *sprite,
						 uint32_t idAnimation,
						 bool repeat) = 0;
	virtual void	loadAnimations(std::unordered_map<uint32_t,
		std::vector<Texture>> textureMap) = 0;
	
	enum	EventAction
	{
		UP	= 0,
		DOWN	= 1,
		LEFT	= 2,
		RIGHT	= 3,
		SPACE	= 4,
		UNKNOWN
	};
	
	virtual std::queue<EventAction>		pollEvents() = 0;
};

#endif //RTYPE_IRENDER_HPP
