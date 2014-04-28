/* See LICENSE file for license and copyright information */

#include "../annotations.h"
#include "../list.h"

#include "border.h"

struct zathura_annotation_popup_s {
  /**
   * The parent annotation with which this pop-up annotation is associated.
   * Note: If this entry is present, the parent annotation’s contents ,
   * modification date, color, and text entries (see Table 8.15 on page 606)
   * override those of the pop-up annotation itself.
   */
  zathura_annotation_t* parent;

  /**
   * A flag specifying whether the pop-up annotation should initially
   * be displayed open.
   */
  bool open;
};
