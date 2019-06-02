/* See LICENSE file for license and copyright information */

#ifndef LIBZATHURA_FIU_H
#define LIBZATHURA_FIU_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WITH_LIBFIU
#define fiu_do_on(name, action)
#define fiu_exit_on(name)
#define fiu_fail(name)
#define fiu_failinfo()
#define fiu_init(flags)
#define fiu_return_on(name, retval)
#else
#include <fiu.h>
#endif

#ifdef __cplusplus
}
#endif

#endif /* FIU_H */
