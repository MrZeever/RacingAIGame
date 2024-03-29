#include "entity.h"

sf::FloatRect entity::get_bounding_box() const noexcept {
	return sprite.getGlobalBounds();
}

sf::Sprite entity::return_sprite() {
	return this->sprite;
}

sf::Vector2f entity::get_centre() const noexcept {
	sf::FloatRect box = get_bounding_box();
	return { box.width / 2.0f, box.height / 2.0f };
}

float entity::x() const noexcept {
	return sprite.getPosition().x;
}

float entity::y() const noexcept {
	return sprite.getPosition().y;
}

float entity::left() const noexcept {
	auto box = get_bounding_box();
	return x() - box.width / 2.0f;
}

float entity::right() const noexcept {
	auto box = get_bounding_box();
	return x() + box.width / 2.0f;
}

float entity::top() const noexcept {
	auto box = get_bounding_box();
	return y() - box.height / 2.0f;
}

float entity::bottom() const noexcept {
	auto box = get_bounding_box();
	return y() + box.height / 2.0f;
}

void entity::destory() noexcept {
	destroyed = true;
}

bool entity::is_destroyed() const noexcept {
	return destroyed;
}