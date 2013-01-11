/* See LICENSE file for license and copyright information */

#ifndef ACTION_H
#define ACTION_H

typedef enum zathura_action_e {
  ZATHURA_ACTION_UNKNOWN,
  ZATHURA_ACTION_NONE,
  ZATHURA_ACTION_GOTO_DEST,
  ZATHURA_ACTION_GOTO_REMOTE,
  ZATHURA_ACTION_LAUNCH,
  ZATHURA_ACTION_NAMED
} zathura_action_t;

#endif /* ACTION_H */
