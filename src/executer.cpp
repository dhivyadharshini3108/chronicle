#include <iostream>
#include <vector>
#include "executer.hpp"

ExecResult execute(const Command& command, WorldState& world)
{
    if(command.type == CommandType::SPAWN)
    {
        Player player;

        player.id = command.id;
        player.username = command.username;
        player.email = command.email;

        SpawnResult result = world.spawnPlayer(player);

        if(result == SpawnResult::SUCCESS)
        {
            std::cout << "Spawned." << std::endl;
            return ExecResult::SUCCESS;
        }

        std::cout << "Error: Entity already exists." << std::endl;
        return ExecResult::FAILURE;
    }

    if(command.type == CommandType::LIST)
    {
        const std::vector<Player>& players = world.getPlayers();

        for(const Player& player : players)
        {
            std::cout << "[" << player.id << "] "
                      << player.username
                      << " <" << player.email << ">"
                      << std::endl;
        }

        std::cout << players.size() << " entities." << std::endl;

        return ExecResult::SUCCESS;
    }

    return ExecResult::FAILURE;
}