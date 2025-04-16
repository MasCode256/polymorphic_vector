#pragma once

#include <vector>
#include <memory>

template <typename BasicType>
class polymorphic_vector
{
private:
	std::vector<std::unique_ptr<BasicType>> vec;

public:
	inline auto get(size_t index) noexcept
	{
		return vec[index].get();
	}

	inline auto operator[](size_t index) noexcept
	{
		return vec[index].get();
	}

	inline const auto operator[](size_t index) const noexcept
	{
		return vec[index].get();
	}

	template <typename ElementType>
	inline void set(size_t index, ElementType &value) noexcept
	{
		std::unique_ptr<Basic> temp = std::make_unique<ElementType>();
		*temp = value;
		vec[index] = value;
	}

	template <typename ElementType>
	inline size_t push_pack(ElementType &value) noexcept
	{
		std::unique_ptr<BasicType> temp = std::make_unique<ElementType>();
		*temp = value;
		vec.push_back(std::move(temp));
		return vec.size() - 1;
	}

	inline auto getVector() noexcept
	{
		return vec;
	}

	inline auto size() const noexcept
	{
		return vec.size();
	}

	~polymorphic_vector()
	{
		~vec();
	}
};