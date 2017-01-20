/*
 * SeamCarveAlgorithm.cpp
 * Defines the seam carving algorithm.
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
 *
 */

#include "SeamCarveApp.hpp"

#define min(x,y)           ((x) < (y) ? (x) : (y))

/**
 * @brief Peforms the seam carving algorithm.
 *
 * @param smap 2-d saliency map with width `w` and height `h`; can be
 * indexed by `smap[i][j]`
 *
 * @param w Width of the saliency map
 *
 * @param h Height of the saliency map
 */
unsigned int *DoSeamCarve(unsigned int **smap, int w, int h)
{
    unsigned int *seam = new unsigned int[h];
    unsigned int cost[w][h];
    int i,j; // index    
    /*
     * The cost table calculates the minimum cost to get from the first row
     * the given coordinate. This is done by adding its cost to the minimum of
     * the 3 adjacaent ones above it.
     */
    for (i = 0; i < w; i++)  
    { 
      cost[i][0] = smap[i][0]; 
    }	// First row    
    for (i = 1; i < h; i++)
    {
      int p = i - 1; 
      // Left edge case
      cost[0][i] = smap[0][i] + min(cost[0][p], cost[1][p]);     
      // Normal cases
      for (j = 1; j < w - 1; j++)	
      {
	cost[j][i] = smap[j][i] + min(min(cost[j][p], cost[j - 1][p]), cost[j + 1][p]);
      }
      // Right edge case
      cost[w - 1][i] = smap[w - 1][i] + min(cost[w - 1][p], cost[w - 2][p]);
    }   
    /*
     * The backtrace finds the optimal path by taking the smallest of the
     * current row and then selecting the minimum of the three adjacent 
     * elements above it, and so on until the top is reached.
     */
    int min_index = 0;
    int a,b,c;	// Temp storage
    for (i = 0; i < w; i++)	
    {
      if (cost[min_index][h - 1] > cost[i][h - 1])	
      { 
	min_index = i; 
      }
    }
    seam[h - 1] = min_index;
    for (j = h - 2; j >= 0; j--)
    {
      if (seam[j + 1] == 0)
      {
	a = 0;  
	b = 1;  
	c = 0; 
      }
      else if (seam[j + 1] == w - 1)	
      {
	a = w - 1; 
	b = w - 2; 
	c = w - 2;
      }
      else	
      {
	a = seam[j + 1] - 1;
	b = seam[j + 1];
	c = seam[j + 1] + 1;
      }
      if (cost[a][j] <= cost[b][j] && cost[a][j] <= cost[c][j])
      {
	min_index = a;
      }
      else if (cost[b][j] <= cost[a][j] && cost[b][j] <= cost[c][j])	
      { 
	min_index = b; 
      }
      else if (cost[c][j] <= cost[b][j] && cost[c][j] <= cost[a][j])	
      { 
	min_index = c;
      }
      seam[j] = min_index;
    }    
    return seam;
}