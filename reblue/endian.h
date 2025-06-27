#pragma once
#include <cstdint>
#include <type_traits>

namespace endian_util {
    template <typename T>
    constexpr T byteswap(T value) noexcept
    {
        if constexpr (sizeof(T) == 1)
        {
            return value;
        }
        else if constexpr (sizeof(T) == 2)
        {
            return static_cast<T>(__builtin_bswap16(static_cast<uint16_t>(value)));
        }
        else if constexpr (sizeof(T) == 4)
        {
            return static_cast<T>(__builtin_bswap32(static_cast<uint32_t>(value)));
        }
        else if constexpr (sizeof(T) == 8)
        {
            return static_cast<T>(__builtin_bswap64(static_cast<uint64_t>(value)));
        }
        else
        {
            static_assert(sizeof(T) <= 8, "Unsupported byteswap size");
            return value;
        }
    }

    template <typename T>
    constexpr void byteswap_inplace(T& v) noexcept
    {
        v = byteswap(v);
    }

    template <typename T>
    struct big_endian
    {
        T value{};

        constexpr big_endian() = default;
        constexpr big_endian(T v) noexcept { set(v); }

        constexpr big_endian& operator=(T v) noexcept
        {
            set(v);
            return *this;
        }

        constexpr operator T() const noexcept { return get(); }

        constexpr void set(T v) noexcept
        {
            value = byteswap(v);
        }

        constexpr T get() const noexcept
        {
            return byteswap(value);
        }
    };
}

using endian_util::big_endian;
using endian_util::byteswap;
using endian_util::byteswap_inplace;
