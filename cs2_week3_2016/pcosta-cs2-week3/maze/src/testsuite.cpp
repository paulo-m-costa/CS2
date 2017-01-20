/**
 * @file testsuite.cpp
 * @author Ellen Price <<eprice@caltech.edu>>
 * @version 1.0
 * @date 2014-2015
 * @copyright see License section
 *
 * @brief Performs tests of the CoordinateQueue and CoordinateStack classes.
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

#include <cstdio>
#include "CoordinateStack.hpp"
#include "CoordinateQueue.hpp"

int main()
{
    Coordinate c1;
    Coordinate c2;
    Coordinate c3;
    CoordinateQueue *queue = new CoordinateQueue();
    CoordinateStack *stack = new CoordinateStack();
    c1 = Coordinate(1, 2);
    c2 = Coordinate(2, 3);
    c3 = Coordinate(0, 0);
    stack->push(c1);
    stack->printStack();//prints after pushing c1
    if (stack->is_empty())
    {
	//tests that c1 is in the stack
	printf ("empty\n");
    }
    else
    {
	printf ("not empty\n");
    }
    stack->push(c2);
    stack->printStack();//prints after pushing c2
    stack->push(c3);
    stack->printStack();
    stack->pop();
    stack->printStack();//prints after popping c3
    Coordinate peek = stack->peek();//peeks at the stack and stores it
    int x = peek.x;
    int y = peek.y;
    printf("X-Coordinate: %d    ", x);//x-value of peek variable
    printf("Y-Coordinate: %d \n\n", y);//y-value of peek variable
    stack->pop();
    stack->printStack();//prints after popping c2
    stack->pop();
    if (stack->is_empty())
    {
	//tests that the stack is empty
	printf ("empty\n");
    }
    else
    {
	printf ("not empty\n");
    }
    stack->pop();//pops the empty stack
    
    queue->enqueue(c1);
    queue->printQueue();//prints after enqueueing c1
    if (queue->is_empty())
    {
	//tests that c1 is in the queue
	printf ("empty\n");
    }
    else{
	printf ("not empty\n");
    }
    queue->enqueue(c2);
    queue->printQueue();//prints after enqueueing c2
    queue->enqueue(c3);
    queue->printQueue();
    queue->dequeue();
    queue->printQueue();//prints after dequeueing c3
    peek = queue->peek();//peeks at the queue and stores it
    x = peek.x;
    y = peek.y;
    printf("X-Coordinate: %d    ", x);//x-value of peek variable
    printf("Y-Coordinate: %d \n\n", y);//y-value of peek variable
    queue->dequeue();
    queue->printQueue();//prints after dequeueing c2
    queue->dequeue();
    if (queue->is_empty()){ 
	//tests that the queue is empty
	printf ("empty\n");
    }
    else{
	printf ("not empty\n");
    }
    queue->dequeue();//dequeues the empty queue
    delete queue;
    delete stack;
    return 0;
}