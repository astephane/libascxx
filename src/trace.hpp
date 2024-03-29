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
#ifndef CXX_TRACE_HPP
#define CXX_TRACE_HPP


#include <iostream>


#define FUN( os ) \
  os << __PRETTY_FUNCTION__

#define THAT_FUN( os, p ) \
  os << ( p ) << __PRETTY__FUNCTION__

#define THIS_FUN( os ) \
  THAT_FUN( os, this )


#define TRACE_THAT_FUN( p ) \
  THAT_FUN( std::cout, p ) << std::endl

#define TRACE_THIS_FUN() \
  TRACE_THAT_FUN( this )


#define TRACE_FUN() \
  FUN( std::cout ) << std::endl

namespace cxx
{
} // end of namespace 'cxx'.

#endif // CXX_TRACE_HPP
