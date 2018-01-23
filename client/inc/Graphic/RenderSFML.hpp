/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_RENDERSFML_HPP_
# define RTYPE_RENDERSFML_HPP_

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <unordered_map>
# include "Graphic/IRender.hpp"

class RenderSFML : public IRender
{
public:
	RenderSFML();
	RenderSFML(unsigned int width, unsigned int height,
		   const std::string &windowName);
	RenderSFML(const RenderSFML &) = delete;
	RenderSFML &operator=(const RenderSFML &) = delete;
	~RenderSFML() override = default;
	
	void	openWindow(unsigned int width,
			       unsigned int height,
			       const std::string &name) override;
	bool	isWindowOpen() noexcept override;
	void	display() noexcept override;
	void	clear() noexcept override;
	void	closeWindow() noexcept override;
	void	draw(const ISprite *sprite) noexcept override;
	void	draw(const IText *text) noexcept override;
	bool	isSpriteClicked(const ISprite *sprite,
				    const EventAction &ev) noexcept override;
	std::queue<IRender::EventAction> pollEvents() noexcept override;
	std::unique_ptr<ISprite> createSprite(const std::string &fileName,
					      uint32_t szX,
					      uint32_t szY) override;

	void	loadAnimations(std::unordered_map<uint32_t,
		std::vector<Texture>> textureMap) override;
	void	playMusic(const std::string &filePath) override;
	void	setAnimationToSprite(ISprite *sprite,
					 uint32_t idAnimation,
					 bool repeat) noexcept override;
	uint32_t getWidth() const noexcept override;
	uint32_t getHeight() const noexcept override;

private:
	const unsigned int					BPP = 32;

	using keyPressed = std::pair<IRender::EventAction, bool>;

	std::unique_ptr<sf::RenderWindow>			_window;
	std::unordered_map<int, keyPressed>			_eventMap;
	std::unordered_map<uint32_t, std::vector<sf::Texture>>	_textureMap;
	sf::Music						_music;
	bool						_musicLoaded = false;
	uint32_t 						_width;
	uint32_t 						_height;

	void		initEventMap();
	void		setKeyPressedOrReleased(int key, bool pressed);
	sf::Texture	loadTexture(const Texture &structTexture);
	void createEventQueue(std::queue<IRender::EventAction> &eventQueue);
};

#endif // !RTYPE_RENDERSFML_HPP_