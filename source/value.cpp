/*!
 *	\file		value.cpp
 *	\brief		Implements value, used by the registry
 *	\author		Vladislav "Tanuki" Mikhailikov \<vmikhailikov\@gmail.com\>
 *	\copyright	GNU GPL v3
 *	\date		14/01/2020
 *	\version	1.0
 */

#include <egg/registry/value.hpp>


namespace egg
{
namespace registry
{

// Construct/destruct
value::value() noexcept
  : variable()
{}

value::~value() noexcept
{}

value::value(
    const value& other)
  : variable(other),
    _r(other._r)
{}

value&
value::operator=(
    const value& other)
{
  variable::operator = (other);
  _r.operator = (other._r);

  return *this;
}

value::value(
    value&& other) noexcept
  : variable(std::move(other)),
    _r(std::move(other._r))
{}

value&
value::operator=(
    value&& other) noexcept
{
  variable::operator=(std::move(other));
  _r.operator=(std::move(other._r));

  return *this;
}

// Create from value
value::value(const bool v) noexcept
  : variable(v)
{}

value::value(
    const std::int8_t    v) noexcept
  : variable(v)
{}

value::value(
    const std::uint8_t   v) noexcept
  : variable(v)
{}

value::value(
    const std::int16_t   v) noexcept
  : variable(v)
{}

value::value(
    const std::uint16_t  v) noexcept
  : variable(v)
{}

value::value(
    const std::int32_t   v) noexcept
  : variable(v)
{}

value::value(
    const std::uint32_t  v) noexcept
  : variable(v)
{}

value::value(
    const std::int64_t   v) noexcept
  : variable(v)
{}

value::value(
    const std::uint64_t  v) noexcept
  : variable(v)
{}

value::value(
    const float          v) noexcept
  : variable(v)
{}

value::value(
    const double         v) noexcept
  : variable(v)
{}

value::value(
    const long double    v) noexcept
  : variable(v)
{}

value::value(
    const char*          v)
  : variable(v)
{}

value::value(
    const std::string&   v)
  : variable(v)
{}

value::value(
    const variable::stringlist&    v)
  : variable(v)
{}

value::value(
    const variable&    v)
  : variable(v)
{}

// Assignment
value&
value::operator=(
    const bool v) noexcept
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const std::int8_t   v) noexcept
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const std::uint8_t  v) noexcept
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const std::int16_t  v) noexcept
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const std::uint16_t v) noexcept
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const std::int32_t  v) noexcept
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const std::uint32_t v) noexcept
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const std::int64_t  v) noexcept
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const std::uint64_t v) noexcept
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const float v) noexcept
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const double v) noexcept
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const long double v) noexcept
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const char* v)
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const std::string& v)
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const variable::stringlist&  v)
{
  variable::operator = (v);
  return *this;
}

value&
value::operator=(
    const variable&  v)
{
  variable::operator = (v);
  return *this;
}

// Iterators
value::iterator
value::begin() noexcept
{
  return _r.begin();
}

value::const_iterator
value::begin() const noexcept
{
  return _r.begin();
}

value::iterator
value::end() noexcept
{
  return _r.end();
}

value::const_iterator
value::end() const noexcept
{
  return _r.end();
}

value::reverse_iterator
value::rbegin() noexcept
{
  return _r.rbegin();
}

value::const_reverse_iterator
value::rbegin() const noexcept
{
  return _r.rbegin();
}

value::reverse_iterator
value::rend() noexcept
{
  return _r.rend();
}

value::const_reverse_iterator
value::rend() const noexcept
{
  return _r.rend();
}

value::const_iterator
value::cbegin() const noexcept
{
  return _r.cbegin();
}

value::const_iterator
value::cend() const noexcept
{
  return _r.cend();
}

value::const_reverse_iterator
value::crbegin() const noexcept
{
  return _r.crbegin();
}

value::const_reverse_iterator
value::crend() const noexcept
{
  return _r.crend();
}

// Capacity
bool
value::empty() const noexcept
{
  return _r.empty();
}

value::size_type
value::size() const noexcept
{
  return _r.size();
}

value::size_type
value::max_size() const noexcept
{
  return _r.max_size();
}

// Element access
value::mapped_type&
value::at (const key_type& k)
{
  return _r.at(k);
}

const value::mapped_type&
value::at (const key_type& k) const
{
  return _r.at(k);
}

// Erase
value::iterator
value::erase (
    value::const_iterator position)
{
  return _r.erase(position);
}

value::size_type
value::erase(
    const key_type& k)
{
  return _r.erase(k);
}

value::iterator
value::erase (
    value::const_iterator first,
    value::const_iterator last)
{
  return _r.erase(first, last);
}

void
value::swap(
    value& x)
{
  value y = std::move(*this);
  this->operator=(std::move(x));
  x = std::move(y);
}

void
value::clear() noexcept
{
  _r.clear();
}

// Observers
value::key_compare
value::key_comp() const
{
  return _r.key_comp();
}

value::value_compare
value::value_comp() const
{
  return _r.value_comp();
}

// Operations
value::iterator
value::find(
    const key_type& k)
{
  return _r.find(k);
}

value::const_iterator
value::find(
    const key_type& k) const
{
  return _r.find(k);
}

value::size_type
value::count(
    const key_type& k) const
{
  return _r.count(k);
}

value::iterator
value::lower_bound(
    const key_type& k)
{
  return _r.lower_bound(k);
}

value::const_iterator
value::lower_bound(
    const key_type& k) const
{
  return _r.lower_bound(k);
}

value::iterator
value::upper_bound(
    const key_type& k)
{
  return _r.upper_bound(k);
}

value::const_iterator
value::upper_bound(
    const key_type& k) const
{
  return _r.upper_bound(k);
}

} // End of egg::registry namespace
} // End of egg namespace

/* End of file */
