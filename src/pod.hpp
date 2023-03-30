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
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with libascxx.	If not, see <https://www.gnu.org/licenses/>.
//
#pragma once

#ifndef CXX_POD_HPP
#define CXX_POD_HPP

#include "enum_traits.hpp"

#include <stdexcept>
#include <tuple>
#include <utility>

namespace cxx
{

  namespace detail
  {

    /** */
    template< typename Enum,
              template< Enum > typename Traits,
              std::size_t ... I >
    auto make_pod_tuple( std::index_sequence< I ... > )
    {
      return
        std::tuple<
          typename Traits<
            static_cast< Enum >( I )
            >::element_type ...
        >();
    }


    /** */
    template< typename Enum,
              template< Enum > typename Traits,
              typename ... Args,
              std::size_t ... I >
    auto make_pod_tuple( std::index_sequence< I ... >, Args && ... args )
    {
      return
        std::tuple<
          typename Traits<
            static_cast< Enum >( I )
            >::element_type ...
        >( args ... );
    }

  } // namespace detail


  /** */
  template< typename Enum,
            template< Enum > typename Traits,
            typename Indices = std::make_index_sequence< cxx::count< Enum >() > >
  constexpr
  auto
  make_pod_tuple()
  {
    return detail::make_pod_tuple< Enum, Traits >( Indices{} );
  }


  /** */
  template< typename Enum,
            template< Enum > typename Traits,
            typename Indices = std::make_index_sequence< cxx::count< Enum >() >,
            typename ... Args >
  constexpr
  auto
  make_pod_tuple( Args && ... args )
  {
    return detail::make_pod_tuple< Enum, Traits >( Indices{}, args ... );
  }


  namespace detail
  {
    /** */
    template< typename Enum,
              template< Enum > typename Traits,
              std::size_t ... I >
    struct pod
    {
      using this_type = pod< Enum, Traits, I ... >;

      constexpr pod( std::index_sequence< I ... > ) noexcept
        {
        }

      using value_type = std::tuple< typename Traits< static_cast< Enum >( I ) >::element_type ... >;
    };


    /** */
    template< typename Enum,
              template< Enum > typename Traits,
              std::size_t ... I >
    constexpr
    pod< Enum, Traits, I ... >
    dummy_pod( std::index_sequence< I ... > indices ) noexcept
    {
      return pod< Enum, Traits, I ... >::pod( indices );
    }

  } // namespace detail


  /** */
  template< typename Enum,
            template< Enum > typename Traits >
  class pod
  {
    static_assert( std::is_enum_v< Enum > );
    // static_assert( std::is_pod_v< pod< Enum, Traits > > );

    using indices = std::make_index_sequence< count< Enum >() >;

    using detail_pod = decltype( detail::dummy_pod< Enum, Traits >( indices() ) );

  public:
    using value_type = typename detail_pod::value_type;
    using enum_type = Enum;

    template< Enum E >
    using traits_type = Traits< E >;

    template< Enum E >
    auto const &
    get() const noexcept
      {
        return std::get< index( E ) >( data );
      }

    template< Enum E >
    auto &
    get() noexcept
      {
        return std::get< index( E ) >( data );
      }

    value_type data;
  };

} // namespace cxx


namespace sample_pod
{

  enum class vector : int
  {
    x = 0,
    y,
    z,
    //
    count,
    //
    first = x,
    last = z,
  };


  enum class color : int
  {
    r = 0,
    g,
    b,
    a,
    //
    count,
    //
    first = r,
    last = a,
  };


  enum class vertex : int
  {
    v,
    n,
    c,
    //
    count,
    //
    first = v,
    last = c,
  };


#define DEFINE_VECTOR_TRAIT( enum_value, elt_name, elt_type )           \
  DEFINE_ENUM_CLASS_TRAIT( vector_traits, vector, enum_value, elt_name, elt_type )

#define DEFINE_COLOR_TRAIT( enum_value, elt_name, elt_type )            \
  DEFINE_ENUM_CLASS_TRAIT( color_traits, color, enum_value, elt_name, elt_type )

#define DEFINE_VERTEX_TRAIT( enum_value, elt_name, elt_type )           \
  DEFINE_ENUM_CLASS_TRAIT( vertex_traits, vertex, enum_value, elt_name, elt_type )


  DECLARE_ENUM_CLASS_TRAITS( vector, vector_traits );

  DEFINE_VECTOR_TRAIT( vector::x, "x", double );
  DEFINE_VECTOR_TRAIT( vector::y, "y", double );
  DEFINE_VECTOR_TRAIT( vector::z, "z", double );


  DECLARE_ENUM_CLASS_TRAITS( color, color_traits );

  DEFINE_COLOR_TRAIT( color::r, "r", std::uint8_t );
  DEFINE_COLOR_TRAIT( color::g, "g", std::uint8_t );
  DEFINE_COLOR_TRAIT( color::b, "b", std::uint8_t );
  DEFINE_COLOR_TRAIT( color::a, "a", std::uint8_t );


  DECLARE_ENUM_CLASS_TRAITS( vertex, vertex_traits );

  DEFINE_VERTEX_TRAIT( vertex::v, "v", vector );
  DEFINE_VERTEX_TRAIT( vertex::n, "n", vector );
  DEFINE_VERTEX_TRAIT( vertex::c, "c", color );


} // namespace sample_pod


#endif // CXX_POD_HPP
