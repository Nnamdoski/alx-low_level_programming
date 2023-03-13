#include "main.h"

#include <stdlib.h>

/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)
{
	int **nna;
	int x, y;

	if (width <= 0 || height <= 0)
		return (NULL);
	nna = malloc(sizeof(int *) * height);
	if (nna == NULL)
		return (NULL);
	for (x = 0; x < height; x++)
	{
		nna[x] = malloc(sizeof(int) * width);
		if (nna[x] == NULL)
		{
			for (; x >= 0; x--)
				free(nna[x]);
			free(nna);
			return (NULL);
		}
	}
	for (x = 0; x < height; x++)
	{
		for (y = 0; y < width; y++)
			nna[x][y] = 0;
	}
	return (nna);
}

