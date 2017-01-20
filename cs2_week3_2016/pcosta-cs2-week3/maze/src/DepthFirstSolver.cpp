/**
 * @file DepthFirstSolver.cpp
 * @author Ellen Price <<eprice@caltech.edu>>
 * @version 2.0
 * @date 2014-2015
 * @copyright see License section
 *
 * @brief Functions for maze solver that implements depth-first search.
 *
 * @section License
 * Copyright (c) 2014-2015 California Institute of Technology.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following disclaimer
 *   in the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of the  nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the California Institute of Technology.
 *
 */

#include "DepthFirstSolver.hpp"
#include "common.hpp"
#include <cstdio>

/**
 * @brief Initializes the solver.
 *
 * @param[in] app Pointer to the main MazeSolverApp class.
 */
DepthFirstSolver::DepthFirstSolver(class MazeSolverApp *app)
{
    stack = new CoordinateStack(app);
    init();
}

/**
 * @brief Initializes the solver (student-implemented).
 */
void DepthFirstSolver::init()
{
    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < HEIGHT; col++)
        {
            visited[row][col] = false;
        }
    }   
}

/**
 * @brief Deinitializes the solver.
 */
DepthFirstSolver::~DepthFirstSolver()
{
    deinit();
}


/**
 * @brief Deinitializes the solver (student-implemented).
 */
void DepthFirstSolver::deinit()
{
    delete stack;
}

/**
 * @brief Solves the maze given by `maze`.
 *
 * @param[in] maze MazeGrid object that stores the maze to be
 * solved.
 */
void DepthFirstSolver::solve(MazeGrid *maze)
{
    /* You are provided a `visited` member variable that you can use to
     * track which cells you have already visited; you are responsible for
     * maintaining it, filling it with useful information, and using it
     * in a consistent way. */
     Coordinate curP;
     Coordinate firstP;
     Coordinate lastP;
     firstP.x  = MAZE_START_X;
     firstP.y = MAZE_START_Y;
     lastP.x = MAZE_END_X;
     lastP.y = MAZE_END_Y;
     curP = firstP;
     stack->push(firstP);    
     while(stack->is_empty() == false and ((curP.x == lastP.x and curP.y == lastP.y) == false))
     {
	visited[curP.x][curP.y] = true;
	int res;
	res = maze->get_possible_moves(curP.x, curP.y);
	if(res & E and visited[curP.x + 1][curP.y] == false)
	{
	    curP.x = curP.x + 1;
	    stack->push(curP);
	}
	else if (res & S and visited[curP.x][curP.y + 1] == false)
	{
	    curP.y = curP.y + 1;
	    stack->push(curP);
	}
	else if (res & W and visited[curP.x - 1][curP.y] == false)
	{
	    curP.x = curP.x - 1;
	    stack->push(curP);
	}
	else if (res & N and visited[curP.x][curP.y - 1] == false)
	{
	    curP.y = curP.y - 1;
	    stack->push(curP);
	}
	else{
	    stack->pop();
	    visited[curP.x][curP.y] = true;
	    curP = stack->peek();
	}	
    }	
}

/**
 * @brief Retrieves the current path through the maze.
 *
 * @return Vector storing the current path through the maze.
 */
vector<Coordinate> DepthFirstSolver::get_path()
{
    vector<Coordinate> list;
    vector<Coordinate> final;
    /* TODO: Get the current path through the maze. For a DFS, this is quite
     * easy: just get all the Coordinates on the stack. */
	stackitem *ptr;
	ptr = stack->top;
	if(ptr == NULL)
	{
	    Coordinate n;
	    n.x = -1;
	    n.y = -1;
	    list.push_back(n);
	    return list;
	}
	else
	{
	    ptr = stack->top;
	    while(ptr != NULL)
	    {
		list.push_back(ptr->c);
		ptr = ptr->next;
	    }
	    for(int i = list.size() - 1; i >= 0; i--)
	    {
		final.push_back(list[i]);
	    }		
	}	
    return final;
}