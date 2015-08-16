/*
 *	include/util/misc.hpp
 *
 *	...
 */
#pragma once

#include <compiler.h>
#include <stddef.h>

#if CONFIG_USE_MACRO == YES // may be found in kernel/config.h

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define array_length(array) (sizeof(array) / sizeof(array[0]))

#else // CONFIG_USE_MACRO == NO

template<typename T>
static constexpr const T& max(const T& a, const T& b)
{
	return a > b ? a : b;
}

template<typename T>
static constexpr const T& min(const T& a, const T& b)
{
	return a < b ? a : b;
}

template<typename T, size_t N>
static constexpr size_t array_length(T (&)[N])
{
	return N;
}

#endif // CONFIG_USE_MACRO
