/***************************************************************************
 *                     strings_2.c
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
#include <string.h>

int main(int argc, char *argv[]) {
   char a_str[100]="Let me see ";
   char b_str[100]="how it works";
   char c_str[100];

   strcpy(c_str, a_str);
   printf("strcpy %s\n", c_str);

   strcat(c_str, b_str);
   printf("strcat %s\n", c_str);

   printf("strcmp %d %d %d\n", strcmp(a_str, b_str), strcmp(a_str, a_str),
		               strcmp(b_str, a_str));
   printf("strlen %lu\n", strlen(a_str));

   return 0;
}
