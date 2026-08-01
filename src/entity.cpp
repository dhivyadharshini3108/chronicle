#include "entity.hpp"

#include <cstring>

void serializePlayer(const Player& player, char* buffer)
{
    std::memset(buffer, 0, ENTITY_SIZE);

    std::memcpy(buffer, &player.id, sizeof(player.id));

    std::memcpy(buffer + 4,
                player.username.c_str(),
                player.username.length());

    std::memcpy(buffer + 36,
                player.email.c_str(),
                player.email.length());
}
Player deserializePlayer(const char* buffer)
{
    Player player;

    std::memcpy(&player.id, buffer, sizeof(player.id));

    player.username = std::string(buffer + 4);

    player.email = std::string(buffer + 36);

    return player;
}