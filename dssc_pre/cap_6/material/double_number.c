/***************************************************************************
 *                     double_number.c
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

int main (int argc, char *argv[])
{
  int i;

  if (argc != 2) {
    fprintf(stderr, "Syntax error: the command expects one argument.\nUsage: %s <number>\n", 
            argv[0]);
    return 1;
  }

  sscanf (argv[1],"%d",&i);
  
  printf("%d\n", 2*i);

  return 0;
}
