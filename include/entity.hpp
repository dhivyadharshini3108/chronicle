#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "player.hpp"

constexpr unsigned int ENTITY_SIZE = 291;

void serializePlayer(const Player& player, char* buffer);

Player deserializePlayer(const char* buffer);

#endif