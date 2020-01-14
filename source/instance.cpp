/*!
 *	\file		instance.cpp
 *	\brief		Registry instance
 *	\author		Vladislav "Tanuki" Mikhailikov \<vmikhailikov\@gmail.com\>
 *	\copyright	GNU GPL v3
 *	\date		14/01/2020
 *	\version	1.0
 */

#include <egg/registry/version.hpp>
#include <egg/registry/instance.hpp>


namespace egg
{
namespace registry
{

// Construct destruct
instance::instance() noexcept
  : egg::registry::value(egg::registry::abi::full)
{}

instance::~instance() noexcept
{}

// Instance managenment
instance&
instance::self() noexcept
{
  static instance _instance;

  return _instance;
}

} // End of egg::registry namespace
} // End of egg namespace

// End of file
