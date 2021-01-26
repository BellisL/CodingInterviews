#pragma once
#if (defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__))
#if defined(UTILITIES_EXPORTS)
#define UTILITIES_DECLSPEC __declspec(dllexport)
#elif defined(CI_STATIC_LIBRARY)
#define UTILITIES_DECLSPEC
#else
#define UTILITIES_DECLSPEC __declspec(dllimport)
#endif
#else
#define UTILITIES_DECLSPEC
#endif