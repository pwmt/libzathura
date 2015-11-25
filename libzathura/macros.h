/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_MACROS_H
#define LIBZATHURA_MACROS_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef UNUSED
# if defined(__GNUC__) || defined(__clang__)
#  define UNUSED(x) UNUSED_ ## x __attribute__((unused))
# elif defined(__LCLINT__)
#  define UNUSED(x) /*@unused@*/ x
# else
#  define UNUSED(x) x
# endif
#endif

#ifndef HIDDEN
# if (defined(__GNUC__) && (__GNUC__ >= 4)) || defined(__clang__)
#  define HIDDEN __attribute__((visibility("hidden")))
# elif defined(__SUNPRO_C)
#  define HIDDEN __hidden
# else
#  define HIDDEN
# endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* MACROS_H */
