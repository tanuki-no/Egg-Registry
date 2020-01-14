/*!
 *	\file		version.hpp
 *	\brief		Declares registry library version and defaults
 *	\author		Vladislav "Tanuki" Mikhailikov \<vmikhailikov\@gmail.com\>
 *	\copyright	GNU GPL v3
 *	\date		14/01/2020
 *	\version	1.0
 */

#ifndef EGG_REGISTRY_VERSION
#define EGG_REGISTRY_VERSION

#include <string>
#include <egg/common.hpp>


namespace egg
{
namespace registry
{

/// Library version
struct EGG_PUBLIC version
{
  /// Library release
  static const int          major;

  /// Library branch
  static const int          minor;

  /// Library patch information
  static const int          patch;

  /// Library tweak information
  static const int          tweak;

  /// Library combined information
  static const std::string  full;
};

/// ABI (Application Building Interface) version
struct EGG_PUBLIC abi
{
  /// ABI release
  static const int          major;

  /// ABI branch
  static const int          minor;

  /// ABI patch information
  static const int          patch;

  /// ABI combined information
  static const std::string  full;
};

struct EGG_PUBLIC common
{
  /// Library name
  static const std::string  name;

  /// Library alias
  static const std::string  alias;

  /// Library author
  static const std::string  author;

  /// Library copyright
  static const std::string  copyright;

  /// Library description
  static const std::string  description;
};

} // End of egg::registry namespace
} // End of egg namespace

#endif  // EGG_REGISTRY_VERSION

/* End of file */
