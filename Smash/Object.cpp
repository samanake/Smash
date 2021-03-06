#include "Object.h"


Object::Object(char_vector_t* textures, int* text_size)
{

	sprite = new sf::Sprite;
	sprite->setScale(3.f, 3.f);
	sprite_height = sprite->getGlobalBounds().height;
	sprite_width = sprite->getGlobalBounds().width;

	initializeSpriteSheets(textures, text_size); //initializes current one as well

}

void Object::draw(sf::RenderWindow* window) {
	window->draw(*sprite);
}

void Object::play_spritesheet() {
	current_spritesheet->play();
	sprite->setTextureRect(*current_spritesheet->getRect());
}

void Object::switchSpriteSheets(int index) {
	if (current_spritesheet != spritesheets->at(index)) {
		if (current_spritesheet != NULL) current_spritesheet->stop();
		current_spritesheet = spritesheets->at(index);
		sprite->setTexture(*current_spritesheet->getTexture());
	}
}

void Object::initializeSpriteSheets(char_vector_t* textures, int* text_size) {
	size = textures->size();
	spritesheets = new vector<SpriteSheet*>;
	for (int i = 0; i < size; i++) {
		spritesheets->push_back(new SpriteSheet(textures->at(i), text_size[i]));
	}

	switchSpriteSheets(0);
}

bool Object::isColliding(Object* object) {
	if (this->sprite->getGlobalBounds().intersects(object->sprite->getGlobalBounds()))
		return true;
	return false;
}

int Object::checkCollisionDirection(Object* object) {
	int check = 0;
	check |= (this->checkCollisionDirectionX(object) | this->checkCollisionDirectionY(object));
	return check;
}

int Object::checkCollisionDirectionX(Object* object) {
	if (this->isLeftOf(object)) return 0x02;
	else if (this->isRightOf(object)) return 0x04;
	else return 0;
}

int Object::checkCollisionDirectionY(Object* object) {
	if (this->isAbove(object)) return 0x1;
	else if (this->isBelow(object)) return 0x8;
	else return 0;
}


sf::Sprite* Object::getSprite() {
	return sprite;
}


bool Object::isAbove(Object* object) { return get_bottom_y() - 6 <= object->get_top_y(); }

bool Object::isBelow(Object* object) { return get_top_y() + 6 >= object->get_bottom_y(); }

bool Object::isLeftOf(Object* object) { return get_right_x() - 6 <= object->get_left_x(); }

bool Object::isRightOf(Object* object) { return get_left_x() + 6 >= object->get_right_x(); }

float Object::get_left_x() { //leftmost pixel
	return sprite->getPosition().x;
}

float Object::get_right_x() { //rightmost pixel
	return sprite->getGlobalBounds().width + sprite->getPosition().x;
}

float Object::get_top_y() { //topmost pixel
	return sprite->getPosition().y;
}
float Object::get_bottom_y() { //bottommost pixel
	return sprite->getGlobalBounds().height + sprite->getPosition().y;
}

float Object::getWidth() { return sprite->getGlobalBounds().width; }

float Object::getHeight() { return sprite->getGlobalBounds().height; }

void Object::place_on(Object* object) {
	sprite->setPosition(get_left_x(), object->get_top_y() - getHeight() + 1);

	/*the +1 is there because setting the bottom ypos to exactly equal the object's top ypos
		is considered not actually "on" the object. It is then intended that every object will be
		placed 1 on top and inside the object, and have every object jump by -1 or less*/
}

void Object::place_right_of(Object* object) {
	sprite->setPosition(object->get_right_x(), get_top_y());
}

void Object::place_left_of(Object* object) {
	sprite->setPosition(object->get_left_x() - getWidth(), get_top_y());
}


Object::~Object()
{
	delete sprite;

	for (int i = 0; i < spritesheets->size(); i++) {
		delete spritesheets->at(i);
	}
	delete spritesheets;
}