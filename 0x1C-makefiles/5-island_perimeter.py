#!/usr/bin/python3

"""
5-island_perimeter - returns the perimeter of the island in grid
"""

def island_perimeter(island_grid):
    """
    Calculates the perimeter of an island
    """

    # Initialize variables to track island borders and island_size
    island_border_count = 0
    island_size = 0

    # Iterate over each cell in the island island_grid
    for row in range(len(island_grid)):
        for col in range(len(island_grid[0])):
            # Check if the current cell is part of an island
            if island_grid[row][col] == 1:
                island_size += 1
                if (col > 0 and island_grid[row][col - 1] == 1):
                    island_border_count += 1
                if (row > 0 and island_grid[row - 1][col] == 1):
                    island_border_count += 1

    # Calculate the perimeter of the island
    result = island_size * 4 - island_border_count * 2
    return result
