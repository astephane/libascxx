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

#ifndef CXX_ENUM_TRAITS_HPP
#define CXX_ENUM_TRAITS_HPP


#include <type_traits>
#// include <stdexcept>
// #include <tuple>
// #include <utility>


namespace cxx
{

  /** */
  template< typename Enum >
  std::enable_if_t< std::is_enum_v< Enum >,
                    std::underlying_type_t< Enum > >
  constexpr
  index( Enum e ) noexcept
  {
    return static_cast< std::underlying_type_t< Enum > >( e );
  }

  /** */
  template< typename Enum >
  constexpr
  std::enable_if_t< std::is_enum_v< Enum >,
                    std::underlying_type_t< Enum > >
  count() noexcept
  {
    return index< Enum >( Enum::last ) - index< Enum >( Enum::first ) + 1;
  }

#define DECLARE_ENUM_CLASS_TRAITS( enum_class, enum_class_traits )      \
                                                                        \
  template< enum_class E >                                              \
  struct enum_class_traits                                              \
  {                                                                     \
    using value_type = enum_class;                                      \
                                                                        \
    using element_type = void;                                          \
                                                                        \
    static constexpr char const * name()                                \
    {                                                                   \
      throw std::domain_error(                                          \
        "unexpected '" #enum_class "' enum-class value." );             \
    }                                                                   \
                                                                        \
    static constexpr std::underlying_type_t< enum_class > index() noexcept \
    {                                                                   \
      return static_cast< std::underlying_type_t< enum_class > >( E );	\
    }                                                                   \
  }


#define DEFINE_ENUM_CLASS_TRAIT( enum_class_traits,	\
                                 enum_class,        \
                                 enum_value,        \
                                 elt_name,          \
                                 elt_type )         \
                                                    \
  template<>                                        \
  struct enum_class_traits< enum_value >            \
  {                                                 \
    using value_type = enum_class;                  \
                                                    \
    static_assert( std::is_enum_v< enum_class > );	\
                                                    \
    using element_type = elt_type;                  \
                                                    \
    static constexpr char const * name() noexcept   \
    {                                               \
      return elt_name;                              \
    }                                               \
  }


#define DECLARE_ENUM_CLASS_UNARY_EVALUATOR( enum_class, evaluator_name ) \
                                                                        \
    template< enum_class E,                                             \
              typename UnaryOp >                                        \
    constexpr                                                           \
    auto                                                                \
    eval( UnaryOp unary_op ) noexcept                                   \
    {                                                                   \
      using underlying_type_t = std::underlying_type_t< position >;     \
                                                                        \
      return                                                            \
        static_cast< E >(                                               \
          unary_op(                                                     \
            static_cast< underlying_type_t >( P )                       \
            )                                                           \
          );                                                            \
    }


#define DECLARE_ENUM_CLASS_NEXT( enum_class )   \
                                                \
    template< enum_class E >                    \
    constexpr                                   \
    auto                                        \
    next() noexcept                             \
    {                                           \
      return details::eval< E >(                \
        []( auto p ) { return p + 1; }          \
        );                                      \
    }


#define DECLARE_ENUM_CLASS_PREV( enum_class )   \
                                                \
    template< enum_class E >                    \
    constexpr                                   \
    auto                                        \
    prev() noexcept                             \
    {                                           \
      return details::eval< E >(                \
        []( auto p ) { return p - 1; }          \
        );                                      \
    }

} // cxx

#endif // CXX_ENUM_TRAITS_HPP
