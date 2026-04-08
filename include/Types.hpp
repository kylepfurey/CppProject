// .hpp
// TODO Type Declarations
// by Kyle Furey

#pragma once
#include <External.hpp>
#include <Export.hpp>

namespace TODO {
    /** A true or false boolean value. */
    using Bool = bool;

    /** An 8-bit signed integral number. */
    using SByte = std::int8_t;

    /** An 8-bit unsigned integral number. */
    using Byte = std::uint8_t;

    /** A 16-bit signed integral number. */
    using Short = std::int16_t;

    /** A 16-bit unsigned integral number. */
    using UShort = std::uint16_t;

    /** A 32-bit signed integral number. */
    using Int = std::int32_t;

    /** A 32-bit unsigned integral number. */
    using UInt = std::uint32_t;

    /** A 64-bit signed integral number. */
    using Long = std::int64_t;

    /** A 64-bit unsigned integral number. */
    using ULong = std::uint64_t;

    /** A 32-bit floating-point decimal number. */
    using Float = float;

    /** A 64-bit floating-point decimal number. */
    using Double = double;

    /** A 128-bit floating-point decimal number. */
    using Decimal = long double;

    /** A byte representing a single symbol of text. */
    using Char = char;

    /** A dynamically-sized array of characters. */
    using String = std::string;

    /** A smart pointer to heap-allocated data with unique ownership. */
    template<typename T>
    using Unique = std::unique_ptr<T>;

    /** A smart pointer to heap-allocated data with shared ownership. */
    template<typename T>
    using Shared = std::shared_ptr<T>;

    /** A smart pointer to heap-allocated data without ownership. */
    template<typename T>
    using Weak = std::weak_ptr<T>;

    /** A fixed-sized array of data. */
    template<ULong N, typename T>
    using Array = std::array<T, N>;

    /** A dynamically-sized array of data. */
    template<typename T>
    using Vector = std::vector<T>;

    /** A dynamic mapping of keys to values. */
    template<typename K, typename V>
    using Map = std::unordered_map<K, V>;

    /** A type-safe reference to a function or lambda. */
    template<typename R, typename... A>
    using Func = std::function<R(A...)>;

    /** Data that may or may not exist. */
    template<typename T>
    using Optional = std::optional<T>;

    /** An optional with no data. */
    constexpr std::nullopt_t NONE = std::nullopt;
}
