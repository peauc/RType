/*
** EPITECH  PROJECT , 2020
** rtype
** File  description:
** 	No description
*/

#ifndef RTYPE_BACKGROUNDSFML_HPP_
# define RTYPE_BACKGROUNDSFML_HPP_

# include "Graphic/SpriteSFML.hpp"

class BackgroundSFML : public SpriteSFML
{
public:
	explicit BackgroundSFML(const std::string &filepath,
				int width, int height,
				float speedX = 1.0, float speedY = 0.0);
	BackgroundSFML(const BackgroundSFML &) = default;
	BackgroundSFML &operator=(const BackgroundSFML &) = default;
	~BackgroundSFML() override = default;

	void updateAnimation() noexcept override;
	float getSpeedX() const noexcept;
	float getSpeedY() const noexcept;
	void setSpeed(float x, float y) noexcept;

private:
	int _width;
	int _height;
	float _speedX;
	float _speedY;
};

#endif // !RTYPE_BACKGROUNDSFML_HPP_