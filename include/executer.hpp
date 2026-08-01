#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include "command.hpp"
#include "world_state.hpp"

enum class ExecResult
{
    SUCCESS,
    FAILURE
};

ExecResult execute(const Command& command, WorldState& world);

#endif