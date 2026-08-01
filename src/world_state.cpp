#include "world_state.hpp"

SpawnResult WorldState::spawnPlayer(const Player& player)
{
    for(const Player& existingPlayer : players)
    {
        if(existingPlayer.id == player.id)
        {
            return SpawnResult::DUPLICATE;
        }
    }

    players.push_back(player);
    return SpawnResult::SUCCESS;
}

const std::vector<Player>& WorldState::getPlayers() const
{
    return players;
}