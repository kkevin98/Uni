/***************************************************************************
 *                     realloc.c
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
#include <stdlib.h>

int main(int argc, char *argv[])
{
   char *ptr=(char *)malloc(1);

   printf("%lu\n", (unsigned long int)ptr);   

   char *ptr2=realloc(ptr, 1024*1024*10);

   fflush();
   printf("%c\n", ptr[1024*1024*10-1]);
   fflush();
   printf("%lu\n", (unsigned long int)ptr2);   
   fflush();

   free(ptr);
   return 0;
}
