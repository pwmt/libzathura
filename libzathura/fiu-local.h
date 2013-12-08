/* See LICENSE file for license and copyright information */

#ifndef FIU_H
#define FIU_H

#ifndef FIU_ENABLE
#define fiu_do_on(name, action)
#define fiu_exit_on(name)
#define fiu_fail(name)
#define fiu_failinfo()
#define fiu_init(flags)
#define fiu_return_on(name, retval)
#else
#include <fiu.h>
#endif

#endif /* FIU_H */
