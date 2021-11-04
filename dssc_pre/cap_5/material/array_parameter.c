/***************************************************************************
 *                     array_parameter.c
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

void test(int A[])
{
  A[0]=0;
}

int main(int argc, char *argv[])
{
  int A[10];

  A[0]=1;

  test(A);

  printf("%d\n", A[0]);

  return 0;
}
