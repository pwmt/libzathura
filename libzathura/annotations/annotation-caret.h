/* See LICENSE file for license and copyright information */

#ifndef ANNOTATION_CARET_H
#define ANNOTATION_CARET_H

/**
 * Specifying a symbol to be associated with the caret.
 */
typedef enum zathura_annotation_caret_symbol_e {
  /**
   * No symbol should be associated with the caret.
   */
  ZATHURA_ANNOTATION_CARET_SYMBOL_NONE,

  /**
   * A new paragraph symbol (¶) should be associated with the caret.
   */
  ZATHURA_ANNOTATION_CARET_SYMBOL_PARAGRAPH,
} zathura_annotation_caret_symbol_t;

#endif // ANNOTATION_CARET_H
