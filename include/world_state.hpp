#ifndef WORLD_STATE_HPP
#define WORLD_STATE_HPP

#include <vector>
#include "player.hpp"
#include "pager.hpp"
enum class SpawnResult
{
    SUCCESS,
    DUPLICATE
};

class WorldState
{
private:
    std::vector<Player> players;
    Pager pager;

public:
    WorldState(const std::string& filename);

    SpawnResult spawnPlayer(const Player& player);

    const std::vector<Player>& getPlayers() const;

    void save();

    void load();
};
#endif