#pragma once
#define p1idle "textures/p1idle.png"
#define p1shooting "textures/p1shooting.png"
#define p1jumping "textures/p1shooting.png"
#define p1moving "textures/p1moving.png"
#define p2idle "textures/p2idle.png"
#define ground1 "textures/stage1.png"
#define fireball1 "textures/fireball.png"
#include <vector>

typedef std::vector<const char*> char_vector_t;


static char_vector_t p1 = { p1idle , p1jumping, p1shooting};
static int p1size[3] = { 13, 9, 9 };

static char_vector_t p2 = { p1idle, p1jumping, p1shooting };
static int p2size[3] = { 13, 9, 9 };

static char_vector_t fireball = { fireball1 };
static int fireballsize[1] = { 9 };

static char_vector_t ground = { ground1 };
static int groundsize[1] = { 1 };
