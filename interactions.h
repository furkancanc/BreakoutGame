#pragma once

#include "ball.h"
#include "paddle.h"
#include "brick.h"

// Determine whether two entitites overlap
bool is_interacting(const entity& e1, const entity& e2);

// Resolve potential collision between the ball and the paddle
void handle_collision(ball& b, const paddle& p);

// Resolve potential collision between the ball and a brick
void handle_collision(ball& b, brick& p);