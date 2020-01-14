/*!
 *	\file		instance.hpp
 *	\brief		Declares storage that backing all kind of configuration
 *	\author		Vladislav "Tanuki" Mikhailikov \<vmikhailikov\@gmail.com\>
 *	\copyright	GNU GPL v3
 *	\date		14/01/2020
 *	\version	1.0
 */

#ifndef EGG_REGISTRY_INSTANCE
#define EGG_REGISTRY_INSTANCE

#include <egg/common.hpp>

#include <egg/registry/value.hpp>


namespace egg
{
namespace registry
{

  // Registry is singleton, that exists throughout the daemon
struct EGG_PUBLIC instance
    : public value
{
  // Delete copy
  instance(const instance&) = delete;
  instance& operator=(const instance&) = delete;

  // Delete move
  instance(instance&&) = delete;
  instance& operator=(instance&&) = delete;

  // Instance management
  static instance& self() noexcept;

protected:

  instance() noexcept;
 ~instance() noexcept;
};

} // End of egg::registry namespace
} // End of egg namespace

#endif  // RUNNER_REGISTRY

/* End of file */
