#pragma once

#ifndef PP_HPP
#define PP_HPP 0x54470000F233C0D3

//
// https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Pragmas.html
//
// https://blog.kowalczyk.info/article/j/guide-to-predefined-macros-in-c-compilers-gcc-clang-msvc-etc..html
//


#ifdef _MSC_VER
# define PRAGMA( x ) __pragma( x )

# define PRAGMA_MESSAGE( str ) PRAGMA( message( str ) )
# define PRAGMA_WARNING( str ) PRAGMA_MESSAGE( "warning: " str )
# define PRAGMA_ERROR( str ) PRAGMA_MESSAGE( "error: " str )

# define PRAGMA_WARNING_PUSH PRAGMA( warning( push ) )
# define PRAGMA_WARNING_POP PRAGMA( warning( pop ) )

# define PRAGMA_WARNING_DISABLE( w ) PRAGMA( warning( disable : w ) )

//
// MSC Warnings
//
# define PRAGMA_WARNING_DISABLE_MSC_4251 PRAGMA_WARNING_DISABLE( 4251 )
# define PRAGMA_WARNING_DISABLE_MSC_4267 PRAGMA_WARNING_DISABLE( 4267 )
# define PRAGMA_WARNING_DISABLE_MSC_4275 PRAGMA_WARNING_DISABLE( 4275 )
# define PRAGMA_WARNING_DISABLE_MSC_4996 PRAGMA_WARNING_DISABLE( 4996 )

//
// GCC Warnings
//
# define PRAGMA_WARNING_DISABLE_GCC_Wsign_compare
# define PRAGMA_WARNING_DISABLE_GCC_Wtype_limits
#endif // _MSC_VER


#ifdef __GNUC__
// # define XSTR( s ) #s
// # define STR( s ) XSTR( s )
// # define CONCAT( s1, s2 ) s1 s2

# define PRAGMA( x ) _Pragma( #x )

# define PRAGMA_MESSAGE( str ) PRAGMA( message str )
# define PRAGMA_WARNING( str ) PRAGMA( GCC warning str )
# define PRAGMA_ERROR( str ) PRAGMA( GCC error str )

# define PRAGMA_WARNING_PUSH PRAGMA( GCC diagnostic push )
# define PRAGMA_WARNING_POP PRAGMA( GCC diagnostic pop )

#define PRAGMA_WARNING_DISABLE( w ) PRAGMA( GCC diagnostic ignored w )

//
// MSC Warnings
//
# define PRAGMA_WARNING_DISABLE_MSC_4251
# define PRAGMA_WARNING_DISABLE_MSC_4267
# define PRAGMA_WARNING_DISABLE_MSC_4275
# define PRAGMA_WARNING_DISABLE_MSC_4996

//
// GCC Warnings
//
# define PRAGMA_WARNING_DISABLE_GCC_Wshadow PRAGMA_WARNING_DISABLE( "-Wshadow" )
# define PRAGMA_WARNING_DISABLE_GCC_Wsign_compare PRAGMA_WARNING_DISABLE( "-Wsign-compare" )
# define PRAGMA_WARNING_DISABLE_GCC_Wtype_limits PRAGMA_WARNING_DISABLE( "-Wtype-limits" )

#endif // __GNUC__

#endif // PP_HPP
