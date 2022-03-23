#pragma once

#include <memory>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

namespace hack::matrix_utils
{
  template<typename T, size_t N>
  struct generate_tuple 
  {
    using type = decltype(std::tuple_cat(typename generate_tuple<T, N - 1>::type{}, std::make_tuple(T{})));
  };

  template<typename T>
  struct generate_tuple<T, 1> 
  {
    using type = std::tuple<T>;
  };

  template<typename T,typename index_data, typename index_t>
  class proxy
  {
    using next_index_t = decltype(std::tuple_cat(index_t{}, std::make_tuple(std::size_t{})));

    public:
      proxy(const std::weak_ptr<index_data>& local_storage, const index_t& index) : local_storage_ { local_storage }, index_ { index } {};

      auto operator[](std::size_t index) const
      {
        return proxy<T, index_data, next_index_t>{ local_storage_, std::tuple_cat(index_, std::make_tuple(index)) };
      }

      auto& operator=(const T& value)
      {
        std::shared_ptr<index_data>(local_storage_)->set_value(index_, value);
        return *this;
      }

      operator T() const
      {
        return std::shared_ptr<index_data>(local_storage_)->get_value(index_);
      }

    private:
      std::weak_ptr<index_data> local_storage_;
      index_t index_;
  };
}

namespace hack
{
  template <typename... T, std::size_t... I>
  auto subtuple_s(const std::tuple<T...>& t, std::index_sequence<I...>) 
  {
    return std::make_tuple(std::get<I>(t)...);
  }

  template <typename... T>
  auto subtuple(const std::tuple<T...>& t) 
  {
    return subtuple_s(t, std::make_index_sequence<sizeof...(T) - 1>());
  }

  template<typename T, std::size_t dimensions>
  class matrix
  {
    public:
      matrix() : local_storage_ { new index_data{} } { }
      
      auto operator[](std::size_t index)
      {
        return matrix_utils::proxy<T, index_data, std::tuple<std::size_t>>{ local_storage_, std::make_tuple(index) };
      }

      int size() const
      {
        return local_storage_->values.size();
      }

      auto begin() noexcept
      {
        return local_storage_->values.begin();
      }

      auto begin() const noexcept
      {
        return local_storage_->values.begin();
      }

      auto end() noexcept
      {
        return local_storage_->values.end();
      }

      auto end() const noexcept
      {
        return local_storage_->values.end();
      }

      auto cbegin() const noexcept
      {
        return local_storage_->values.cbegin();
      }

      auto cend() const noexcept
      {
        return local_storage_->values.cend();
      }

    private:
      struct index_data
      {
        using index_t = typename matrix_utils::generate_tuple<std::size_t, dimensions>::type;    
        using index_data_t = std::vector<decltype(std::tuple_cat(index_t{}, std::make_tuple(T{})))>;

        void set_value(const index_t& index, const T& v)
        {
          auto value = std::tuple_cat(index, std::make_tuple(v));
          values.push_back(value);
        }

        auto get_value(const index_t& index)
        {
          auto it = std::find_if(values.begin(), values.end(), [&](auto a) { return subtuple(a) == index; });
          return std::get<dimensions>(*it);
        }

        index_data_t values;
      };

    private:
      std::shared_ptr<index_data> local_storage_;
  };

  template <typename T, typename U, std::size_t N>
  bool operator==(const matrix<T, N>& lhs, const matrix<U, N>& rhs) 
  { 
    return std::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin()); 
  }
}
