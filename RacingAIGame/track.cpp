#include "track.h"

sf::Texture track::texture;

track::track(float x, float y, std::string track_name) {
	texture.loadFromFile(track_name);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void track::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}