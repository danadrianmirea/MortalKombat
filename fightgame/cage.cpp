#include "cage.h"

#include <iostream>

#define ANIMATIONS "data/johnnycage/animations/"

void JohnnyCage::load_resources(bones::GraphicsLoader& loader)
{
	idle = loader.load_animation(ANIMATIONS "cage_idle.xml");
	crouch = loader.load_animation(ANIMATIONS "cage_crouch.xml");
	walk_forward = loader.load_animation(ANIMATIONS "cage_walk.xml");
	walk_backward = walk_forward.reverse();
	jump = loader.load_animation(ANIMATIONS "cage_jump_up.xml");
	jump_forward = loader.load_animation(ANIMATIONS "cage_jump_move.xml");
	jump_backward = jump_forward.reverse();
	block = loader.load_animation(ANIMATIONS "cage_block.xml");
	move_source.bind_owner(this);
	move_source.load_moves_from_file("data/johnnycage/moves.xml", loader);
	current_animation = &idle;
	x = 150;
	y = 350;
	x_vel = y_vel = 0;
}

void JohnnyCage::process_move(Move& move)
{
	perform_fight_move(move.animation);
}
