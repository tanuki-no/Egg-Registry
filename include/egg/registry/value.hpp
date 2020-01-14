/*!
 *	\file		value.hpp
 *	\brief		Declares value, the registry root
 *	\author		Vladislav "Tanuki" Mikhailikov \<vmikhailikov\@gmail.com\>
 *	\copyright	GNU GPL v3
 *	\date		14/01/2020
 *	\version	1.0
 */

#ifndef EGG_REGISTRY_VALUE
#define EGG_REGISTRY_VALUE

#include <map>

#include <egg/common.hpp>
#include <egg/variable.hpp>


namespace egg
{
namespace registry
{

class EGG_PUBLIC value : public egg::variable
{
  typedef std::map<egg::variable, value>   R;
  R _r;

public:

  // Types
  typedef R::key_type                       key_type;
  typedef R::mapped_type                    mapped_type;
  typedef R::value_type                     value_type;
  typedef R::key_compare                    key_compare;
  typedef R::value_compare                  value_compare;

  typedef R::allocator_type                 allocator_type;
  typedef R::reference                      reference;
  typedef R::const_reference                const_reference;
  typedef R::pointer                        pointer;
  typedef R::const_pointer                  const_pointer;

  typedef R::iterator                       iterator;
  typedef R::const_iterator                 const_iterator;
  typedef R::reverse_iterator               reverse_iterator;
  typedef R::const_reverse_iterator         const_reverse_iterator;

  typedef R::difference_type                difference_type;
  typedef R::size_type                      size_type;

  // Construct/destruct
  value() noexcept;
  ~value() noexcept;

  value(const value& other);
  value& operator=(const value& other);

  value(value&& other) noexcept;
  value& operator=(value&& other) noexcept;

  // Create from value
  explicit value(const bool v) noexcept;

  explicit value(const std::int8_t    v) noexcept;
  explicit value(const std::uint8_t   v) noexcept;
  explicit value(const std::int16_t   v) noexcept;
  explicit value(const std::uint16_t  v) noexcept;
  explicit value(const std::int32_t   v) noexcept;
  explicit value(const std::uint32_t  v) noexcept;
  explicit value(const std::int64_t   v) noexcept;
  explicit value(const std::uint64_t  v) noexcept;

  explicit value(const float          v) noexcept;
  explicit value(const double         v) noexcept;
  explicit value(const long double    v) noexcept;

  explicit value(const char*          v);
  explicit value(const std::string&   v);
  explicit value(const stringlist&    v);

  explicit value(const variable&      v);

  // Assign from copy
  value& operator=(const bool v) noexcept;

  value& operator=(const std::int8_t    v) noexcept;
  value& operator=(const std::uint8_t   v) noexcept;
  value& operator=(const std::int16_t   v) noexcept;
  value& operator=(const std::uint16_t  v) noexcept;
  value& operator=(const std::int32_t   v) noexcept;
  value& operator=(const std::uint32_t  v) noexcept;
  value& operator=(const std::int64_t   v) noexcept;
  value& operator=(const std::uint64_t  v) noexcept;

  value& operator=(const float          v) noexcept;
  value& operator=(const double         v) noexcept;
  value& operator=(const long double    v) noexcept;

  value& operator=(const char*          v);
  value& operator=(const std::string&   v);
  value& operator=(const stringlist&    v);

  value& operator=(const variable&      v);

  // Iterators
  iterator begin() noexcept;
  const_iterator begin() const noexcept;

  iterator end() noexcept;
  const_iterator end() const noexcept;

  reverse_iterator rbegin() noexcept;
  const_reverse_iterator rbegin() const noexcept;

  reverse_iterator rend() noexcept;
  const_reverse_iterator rend() const noexcept;

  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  const_reverse_iterator crbegin() const noexcept;
  const_reverse_iterator crend() const noexcept;

  // Capacity
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  // Access
  inline mapped_type& operator[](const key_type& k)
  { return (_r[k]); }

  inline mapped_type& operator[](key_type&& k)
  { return (_r[k]); }

  mapped_type& at(const key_type& k);
  const mapped_type& at(const key_type& k) const;

  // Insert
  inline std::pair<iterator,bool>
  insert(
      const value_type& val)
  {
    return (_r.insert(val));
  }

  template <class P>
  inline std::pair<iterator, bool>
  insert (P&& val)
  {
    return (_r.insert(val));
  }

  inline iterator
  insert(
      const_iterator    position,
      const value_type& val)
  {
    return (_r.insert(position, val));
  }

  template <class P>
  inline iterator
  insert(
      const_iterator    position,
      P&&               val)
  {
    return (_r.insert(position, val));
  }

  template <class InputIterator>
  inline void
  insert(
      InputIterator first,
      InputIterator last)
  {
    _r.insert(first, last);
  }

  inline void
  insert(
      std::initializer_list<value_type> il)
  {
    return (_r.insert(il));
  }

  // Erase
  iterator  erase(const_iterator position);
  size_type erase(const key_type& k);
  iterator  erase(const_iterator first, const_iterator last);

  void swap(value& x);
  void clear() noexcept;

  template <class... Args>
  inline std::pair<iterator,bool>
  emplace (Args&&... args)
  {
    return (_r.emplace(args...));
  }

  template <class... Args>
  inline iterator emplace_hint (
      const_iterator position,
      Args&&... args)
  {
    return (_r.emplace_hint(position, args...));
  }

  // Observers
  key_compare key_comp() const;
  value_compare value_comp() const;

  // Operations
  iterator find (const key_type& k);
  const_iterator find (const key_type& k) const;

  size_type count (const key_type& k) const;

  iterator lower_bound (const key_type& k);
  const_iterator lower_bound (const key_type& k) const;

  iterator upper_bound (const key_type& k);
  const_iterator upper_bound (const key_type& k) const;

  inline std::pair<const_iterator,const_iterator>
  equal_range(const key_type& k) const
  {
    return (_r.equal_range(k));
  }

  std::pair<iterator,iterator>
  equal_range(const key_type& k)
  {
    return (_r.equal_range(k));
  }
};

} // End of egg::registry namespace
} // End of egg namespace

#endif  // EGG_REGISTRY_VALUE

/* End of file */
