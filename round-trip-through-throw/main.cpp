
#include <cassert>
#include <type_traits>
#include <vector>

#ifndef ROUND_TRIP_ERRORS_THROUGH_EH
 #warning "you should pass -DROUND_TRIP_ERRORS_THROUGH_EH=0 if you want that"
#endif

struct throw_colored_t{};

template<class T>
struct Result {
    T value;
    int error;
};

#define MAGIC_THROWING(...) \
    [&]() { \
        auto result = __VA_ARGS__; \
        if (result.error) throw result.error; \
        return result.value; \
    }()
#define MAGIC_UNTHROWING(dummy_result, ...) \
    try { __VA_ARGS__ } \
    catch (int error) { return {dummy_result, error}; }

namespace stdx {

Result<int> sqrt(int x, throw_colored_t) noexcept {
    if (x < 0) return {0, 1};
    // Make the compiler's job super easy. Don't even bother to take the square root here.
    return {x, 0};
}

// This is the "natively, perhaps conditionally, throw-colored std::transform".
// Notice that it requires work on the metaprogrammer's part.
template<class It, class OutIt, class ThrowColoredUnaryOp>
Result<OutIt> transform(It first, It last, OutIt dest, ThrowColoredUnaryOp f, throw_colored_t) noexcept
{
    static_assert(std::is_trivially_copyable<Result<OutIt>>::value, "");
    while (first != last) {
        auto temp = f(*first);
        if (temp.error) return {dest, temp.error};
        *dest = temp.value;
        ++dest;
        ++first;
    }
    return {dest, 0};
}

// This is the same old C++03-era std::transform,
// plus our hypothetical "compiler magic" to convert
// throw-colored lambdas into normal-colored ones.
template<class It, class OutIt, class ThrowColoredUnaryOp>
OutIt transform(It first, It last, OutIt dest, ThrowColoredUnaryOp f)
{
    while (first != last) {
        *dest = MAGIC_THROWING(f(*first));
        ++dest;
        ++first;
    }
    return dest;
}

} // namespace stdx

Result<int> convert_ints_to_sqrts(
    int *first, int *last,
    int *dst,
    throw_colored_t)
{
    static_assert(std::is_trivially_copyable<Result<int>>::value, "");
#if ROUND_TRIP_ERRORS_THROUGH_EH
    // This is our normal-looking call to std::transform,
    // plus the hypothetical compiler magic.
    MAGIC_UNTHROWING(0,
        stdx::transform(
            first, last,
            dst,
            [](auto&& p) noexcept { return stdx::sqrt(p, throw_colored_t{}); }
        );
    );
    return {0, 0};
#else
    // This is a "natively throw-colored" version,
    // involving no normal-colored EH machinery at all.
    auto result = stdx::transform(
        first, last,
        dst,
        [](auto&& p) noexcept { return stdx::sqrt(p, throw_colored_t{}); },
        throw_colored_t{}
    );
    return {0, result.error};
#endif
}

int main()
{
    int src[8] = { 1, 2, 9, -1, 4, -16, 16, 9 };
    int dst[8] = {};
    auto result = convert_ints_to_sqrts(src, src + 8, dst, throw_colored_t{});
    assert(result.error == 1);
    assert(dst[0] == 1);
    assert(dst[1] == 2);
    assert(dst[2] == 9);
    assert(dst[3] == 0);
    assert(dst[4] == 0);
    assert(dst[5] == 0);
    assert(dst[6] == 0);
    assert(dst[7] == 0);
}
