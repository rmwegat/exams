#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int rows;
	int cols;
	char empty;
	char obstacle;
	char full;
	char **map;
} t_bsq;
