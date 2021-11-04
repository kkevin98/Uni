/***************************************************************************
 *                     pointer1.c
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

void d_value(int* v) 
{ 
   *v=2*(*v); 
}

int main(int argc, char *argv[])
{
  int a; a=1; d_value(&a);

  printf("%d\n", a);

  return 0;
}
