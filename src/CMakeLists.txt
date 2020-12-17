#
# Copyright 2020 Stéphane ALBERT
#
# This file is part of libascxx.
#
# libascxx is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# libascxx is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with libascxx.  If not, see <https://www.gnu.org/licenses/>.
#

set( SOURCES
  main.cpp
  template.hpp
  template.cpp
  )


message( "CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}" )
message( "CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}" )


add_executable( ${PROJECT_NAME} ${SOURCES} )

target_include_directories( ${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_BINARY_DIR}
  $<$<BOOL:${USE_LIBTCOD}>:${LIBTCOD_INCLUDE_DIRS}>
  )

target_link_libraries( ${PROJECT_NAME} PRIVATE
  $<$<BOOL:${USE_LIBTCOD}>:${LIBTCOD_LIBRARIES}>
  )
