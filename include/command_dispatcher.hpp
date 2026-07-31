#ifndef COMMAND_DISPATCHER_HPP
#define COMMAND_DISPATCHER_HPP
#include <string>
#include "application_state.hpp"

AppState dispatchCommand(const std::string& command);
#endif