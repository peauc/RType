/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_RENDERSFML_HPP_
# define RTYPE_RENDERSFML_HPP_

# include <SFML/Graphics.hpp>
# include <unordered_map>
# include "IRender.hpp"

class RenderSFML : public IRender
{
public:
	RenderSFML() = default;
	RenderSFML(unsigned int width, unsigned int height,
		   const std::string &windowName) noexcept;
	RenderSFML(const RenderSFML &) = delete;
	RenderSFML &operator=(const RenderSFML &) = delete;
	~RenderSFML() override = default;
	
	void	openWindow(unsigned int width,
			       unsigned int height,
			       const std::string &name) noexcept override;
	bool	isWindowOpen() noexcept override;
	void	display() noexcept override;
	void	clear() noexcept override;
	void	closeWindow() noexcept override;
	void	draw(const ISprite *sprite) noexcept override;
	std::queue<IRender::EventAction>	pollEvents() noexcept override;
	std::unique_ptr<ISprite> createSprite(const std::string &fileName,
					      uint32_t szX,
					      uint32_t szY) noexcept override;

private:
	const unsigned int					BPP = 32;

	std::unique_ptr<sf::RenderWindow>			_window;
	std::unordered_map<sf::Keyboard::Key, EventAction>	_eventMap;

	void	addEventToQueue(std::queue<IRender::EventAction> &eventQueue,
				    sf::Keyboard::Key key);
};

#endif // !RTYPE_RENDERSFML_HPP_