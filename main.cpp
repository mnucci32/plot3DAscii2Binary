/*  An open source Plot3D ascii to binary converter.
    Copyright (C) 2015  Michael Nucci (michael.nucci@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#include <iostream>      //cout, cerr, endl
#include "plot3d.hpp"
#include "vector3d.hpp"
#include <vector>        //stl vector
#include <string>        //stl string

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

int main( int argc, char *argv[] ) {

  const string inputFile = argv[1];  //name of input file is the second argument (the executable being the first)
  const string outputFile = argv[2];  //name of output file is the third argument

  //Parse input file
  double totalCells = 0.0;

  //Read grid
  vector<plot3dBlock> mesh = ReadP3dGridAscii(inputFile, 1.0, totalCells);
  cout << endl;

  //Write grid
  WriteP3dGrid(mesh, outputFile, 1.0);

  cout << "Program Complete" << endl;

  return 0;
}
