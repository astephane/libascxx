//
// Copyright 2020 Stéphane ALBERT
//
// This file is part of libascxx.
//
// libascxx is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libascxx is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with libascxx.  If not, see <https://www.gnu.org/licenses/>.
//

#include "config.hpp"

#include "pp.hpp"

#include <cstdlib>
#include <iostream>


int
main( int unused( argc ), char * unused( argv )[] )
{
  std::cout
    << "Welcome to libascxx version " LIBASCXX_VERSION_STRING " distributed under the terms of the " LIBASCXX_LICENCE
    << std::endl;

  return EXIT_SUCCESS;
}
