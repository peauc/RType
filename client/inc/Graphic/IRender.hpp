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
# include "Graphic/ISprite.hpp"
# include "Graphic/IText.hpp"

class IRender
{
public:
	virtual ~IRender() = default;

	enum class EventAction
	{
		UP	= 0,
		DOWN	= 1,
		LEFT	= 2,
		RIGHT	= 3,
		SPACE	= 4,
		MOUSE1	= 5,
		QUIT	= 6,
		UNKNOWN
	};

	virtual void	openWindow(unsigned int width, unsigned int height,
				   const std::string &windowName) = 0;
	virtual bool	isWindowOpen() = 0;
	virtual void	display() = 0;
	virtual void	clear() = 0;
	virtual void	closeWindow() = 0;
	virtual void	draw(const ISprite *sprite) = 0;
	virtual void	draw(const IText *text) = 0;

	/**
	 * Create sprite by loading it from fileName file
	 * @param fileName Path of the sprite to be load
	 * @param sizeTileX width of each tile in the sprite, set 0 if you
	 * don't use the size of the tiles
	 * @param sizeTileY height of each tile, set 0 if not used
	 * @return new sprite
	 */
	virtual std::unique_ptr<ISprite>
		createSprite(const std::string &fileName,
			     uint32_t sizeTileX = 0,
			     uint32_t sizeTileY = 0) = 0;

	/**
	 * Attach a vector of animations to a sprite
	 * @param sprite
	 * @param idAnimation Id of animation to attach
	 * @param repeat Looping the animation ?
	 */
	virtual void	setAnimationToSprite(ISprite *sprite,
						 uint32_t idAnimation,
						 bool repeat) = 0;
	
	/**
	 * Load the vector of animations
	 * @param textureMap
	 */
	virtual void	loadAnimations(std::unordered_map<uint32_t,
		std::vector<Texture>> textureMap) = 0;
	
	/**
	 * Get userEvents
	 * @return queue of user events
	 */
	virtual std::queue<EventAction>		pollEvents() = 0;

	/**
	 * Check if sprite has been clicked
	 * @param sprite to check
	 * @param event
	 */
	virtual bool	isSpriteClicked(const ISprite *sprite,
					    const EventAction &event) = 0;
	
	/**
	 * @return width of window screen
	 */
	virtual uint32_t getWidth() const noexcept = 0;

	/**
	 * @return height of window screen
	 */
	virtual uint32_t getHeight() const noexcept = 0;
};

#endif //RTYPE_IRENDER_HPP
