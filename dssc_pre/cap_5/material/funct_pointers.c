/***************************************************************************
 *                     funct_pointers.c
 * 
 *   Copyright  2018-2019  Alberto Casagrande
 *   acasagrande@units.it
 ***************************************************************************/

/*
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <stdio.h>

double double_v(const double v)
{
   return 2*v;
}

double integral(double (*funct)(const double), 
                const double lb, const double ub, const double step)
{

   double acc=0;
   double x=lb;


   while ( x+step <= ub) {
      acc = acc + ((funct(x)+funct(x+step))*step)/2;

      x += step;
   }
   
   return acc;
}

int main()
{
  printf("%lf\n", integral(double_v, 0, 8, 0.0001));

  return 0;
}
