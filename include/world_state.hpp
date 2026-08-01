#ifndef WORLD_STATE_HPP
#define WORLD_STATE_HPP

#include <vector>
#include "player.hpp"

enum class SpawnResult
{
    SUCCESS,
    DUPLICATE
};

class WorldState
{
private:
    std::vector<Player> players;

public:
    SpawnResult spawnPlayer(const Player& player);

    const std::vector<Player>& getPlayers() const;
};

#endif