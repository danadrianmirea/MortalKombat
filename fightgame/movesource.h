#ifndef _FIGHTMOVE_INPUT_HANDLER_H
#define _FIGHTMOVE_INPUT_HANDLER_H

#include "fighter_state.h"
#include "fightmove.h"

#include <string>
#include <vector>
#include <map>
#include <functional>

class FightMoveInputHandler
{
public:
	using HandlerFunc = std::function<void(FightMove)>;
	using ActivationKey = std::pair<FighterState::FightMoveHook, std::string>;

	FightMoveInputHandler(HandlerFunc handler, std::map<ActivationKey, FightMove> move_map);
	FightMoveInputHandler(const FightMoveInputHandler& handler) = delete;
	FightMoveInputHandler& operator = (const FightMoveInputHandler& handler) = delete;

	void process_event(SDL_Event &event, FighterState::FightMoveHook hook, Orientation direction);
	void flush();

private:
	std::vector<std::string> input_buffer;
	std::map<ActivationKey, FightMove> move_map;
	HandlerFunc handler;
	bool first_press; /// start flush timer once this is true
};
#endif