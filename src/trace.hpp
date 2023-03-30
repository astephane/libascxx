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

/** */
#ifdef __func__
# define PFUNC __func__
#else // __func__
# define PFUNC __PRETTY_FUNCTION__
#endif // __func__

/** */
#define FUNC                                    \
  PFUNC

/** */
#define THAT_FUNC( p )                          \
  ( p ) << FUNC

/** */
#define THIS_FUNC                               \
  THAT_FUN( this )

/** */
#define COUT_THAT_FUNC( p )                     \
  std::cout << THAT_FUN( p )::endl

/** */
#define COUT_THIS_FUNC()                        \
  COUT_THAT_FUN( this )

/** */
#define COUT_FUNC()                             \
  std::cout << FUNC << std::endl

namespace cxx
{
} // end of namespace 'cxx'.

#endif // CXX_TRACE_HPP
