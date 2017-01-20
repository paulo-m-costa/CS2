/**
 * @file test_solver.cpp
 * @author Ellen Price <<eprice@caltech.edu>>
 * @version 1.0
 * @date 2013-2016
 * @copyright see License section
 *
 * @brief Simple test suite for Solver.
 *
 * @section License
 * Copyright (c) 2013-2014 California Institute of Technology.
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

#include "Solver.hpp"
#include <cstdio>

using namespace Solver;

double f1(double xi)
{
    return xi + 5;
}
double fp1(double xi)
{
    return 1;
}

double f2(double xi)
{
    return pow(xi, 2) + 5 * xi + 4;
}
double fp2(double xi)
{
    return 2 * xi + 5;
}

double f3(double xi)
{
    return pow(xi, 5) + pow(xi, 2) - 8 * xi + 4;
}
double fp3(double xi)
{
    return 5 * pow(xi, 4) + 2 * xi - 8;
}

double f4(double xi)
{
    if (xi > 0)
    {
        return std::exp(-1/xi);
    }
    else
    {
        return 0;
    }
}
double fp4(double xi)
{
    if (xi > 0)
    {
        return std::exp(-1/xi) / pow(xi, 2);
    }
    else
    {
        return 0;
    }
}

int main()
{
    printf("<ANALYTIC FUNCTIONS>\n");
    
    printf("Function 1: f(x) = x + 5\nSolving for f(x) = 0 gives "
            "x = -5\n");
    double s1 = newton_raphson(f1, fp1, 5);
    printf("Newton Raphson solution is %g\n", s1);
    s1 = bisection(f1, -10, 10);
    printf("Bisection solution is %g\n\n", s1);

    printf("Function 2: f(x) = x^2 + 5x + 4\nSolving for f(x) = 0 gives "
            "x = -4 or x = -1\n");
    double s2 = newton_raphson(f2, fp2, 5);
    printf("Newton Raphson solution is %g\n", s2);
    s2 = bisection(f2, -3, 10);
    printf("Bisection solution is %g\n\n", s2);

    printf("Function 3: f(x) = x^5 + x^2 - 8x + 4\nSolving for f(x) = 0 "
            "gives REAL answers x = -1.9, x = .54, or x = 1.4\n");
    double s3 = newton_raphson(f3, fp3, 0);
    printf("Newton Raphson solution is %g\n", s3);
    s3 = bisection(f3, 0, 1);
    printf("Bisection solution is %g\n\n", s3);
    
    

    printf("<NON ANALYTIC FUNCTION>\n");
    
    printf("Function 4: f(x) = e^(-1/x) if x > 0 and "
            " 0 if x <= 0. \nSolving for f(x) = 0 "
            "gives REAL answer x = 0\n");
    double s4 = newton_raphson(f4, fp4, 1);
    printf("Newton Raphson solution is %g\n", s4);
    s4 = bisection(f4, -1, 1);
    printf("Bisection solution is %g\n", s4);

    return 0;
}