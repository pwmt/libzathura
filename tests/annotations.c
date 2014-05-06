/* See LICENSE file for license and copyright information */

#include <check.h>
#include <limits.h>
#include <fiu.h>
#include <fiu-control.h>

#include "annotations.h"

zathura_annotation_t* annotation;

static void setup(void) {
  fail_unless(zathura_annotation_new(&annotation, ZATHURA_ANNOTATION_CARET) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

static void teardown(void) {
  fail_unless(zathura_annotation_free(annotation) == ZATHURA_ERROR_OK);
  annotation = NULL;
}

START_TEST(test_annotation_free) {
  fail_unless(zathura_annotation_free(NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_new) {
  zathura_annotation_t* test_annotation;
  fail_unless(zathura_annotation_new(NULL, 0) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_new(&test_annotation, INT_MAX) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* fault injection */
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_new(&test_annotation, ZATHURA_PAGE_TRANSITION_SPLIT) == ZATHURA_ERROR_OUT_OF_MEMORY);
  fiu_disable("libc/mm/calloc");
} END_TEST

START_TEST(test_annotation_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_type(NULL, &type) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_get_type(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

#include "annotations/annotation-text.c"
#include "annotations/annotation-link.c"
#include "annotations/annotation-markup.c"
#include "annotations/annotation-free-text.c"
#include "annotations/annotation-square.c"
#include "annotations/annotation-circle.c"
#include "annotations/annotation-polygon.c"
#include "annotations/annotation-poly-line.c"
#include "annotations/annotation-highlight.c"
#include "annotations/annotation-underline.c"
#include "annotations/annotation-squiggly.c"
#include "annotations/annotation-strike-out.c"
#include "annotations/annotation-stamp.c"
#include "annotations/annotation-caret.c"
#include "annotations/annotation-ink.c"
#include "annotations/annotation-popup.c"
#include "annotations/annotation-file-attachment.c"
#include "annotations/annotation-sound.c"
#include "annotations/annotation-movie.c"
#include "annotations/annotation-screen.c"
#include "annotations/annotation-printer-mark.c"
#include "annotations/annotation-trap-net.c"
#include "annotations/annotation-watermark.c"
#include "annotations/annotation-3d.c"

Suite*
suite_annotations(void)
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("annotations");

  tcase = tcase_create("basic");
  tcase_add_checked_fixture(tcase, setup, teardown);
  tcase_add_test(tcase, test_annotation_free);
  tcase_add_test(tcase, test_annotation_new);
  tcase_add_test(tcase, test_annotation_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("text");
  tcase_add_checked_fixture(tcase, setup_annotation_text, teardown);
  tcase_add_test(tcase, test_annotation_text_new);
  tcase_add_test(tcase, test_annotation_text_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("link");
  tcase_add_checked_fixture(tcase, setup_annotation_link, teardown);
  tcase_add_test(tcase, test_annotation_link_new);
  tcase_add_test(tcase, test_annotation_link_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("markup");
  tcase_add_checked_fixture(tcase, setup_annotation_markup, teardown);
  tcase_add_test(tcase, test_annotation_markup_new);
  tcase_add_test(tcase, test_annotation_is_markup_annotation);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("free-text");
  tcase_add_checked_fixture(tcase, setup_annotation_free_text, teardown);
  tcase_add_test(tcase, test_annotation_free_text_new);
  tcase_add_test(tcase, test_annotation_free_text_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("square");
  tcase_add_checked_fixture(tcase, setup_annotation_square, teardown);
  tcase_add_test(tcase, test_annotation_square_new);
  tcase_add_test(tcase, test_annotation_square_and_circle_init);
  tcase_add_test(tcase, test_annotation_square_and_circle_clear);
  tcase_add_test(tcase, test_annotation_square_get_type);
  tcase_add_test(tcase, test_annotation_square_set_rectangle);
  tcase_add_test(tcase, test_annotation_square_get_rectangle);
  tcase_add_test(tcase, test_annotation_square_set_color);
  tcase_add_test(tcase, test_annotation_square_get_color);
  tcase_add_test(tcase, test_annotation_square_set_border);
  tcase_add_test(tcase, test_annotation_square_get_border);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("circle");
  tcase_add_checked_fixture(tcase, setup_annotation_circle, teardown);
  tcase_add_test(tcase, test_annotation_circle_new);
  tcase_add_test(tcase, test_annotation_circle_get_type);
  tcase_add_test(tcase, test_annotation_circle_set_rectangle);
  tcase_add_test(tcase, test_annotation_circle_get_rectangle);
  tcase_add_test(tcase, test_annotation_circle_set_color);
  tcase_add_test(tcase, test_annotation_circle_get_color);
  tcase_add_test(tcase, test_annotation_circle_set_border);
  tcase_add_test(tcase, test_annotation_circle_get_border);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("polygon");
  tcase_add_checked_fixture(tcase, setup_annotation_polygon, teardown);
  tcase_add_test(tcase, test_annotation_polygon_new);
  tcase_add_test(tcase, test_annotation_polygon_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("poly-line");
  tcase_add_checked_fixture(tcase, setup_annotation_poly_line, teardown);
  tcase_add_test(tcase, test_annotation_poly_line_new);
  tcase_add_test(tcase, test_annotation_poly_line_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("highlight");
  tcase_add_checked_fixture(tcase, setup_annotation_highlight, teardown);
  tcase_add_test(tcase, test_annotation_highlight_new);
  tcase_add_test(tcase, test_annotation_highlight_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("underline");
  tcase_add_checked_fixture(tcase, setup_annotation_underline, teardown);
  tcase_add_test(tcase, test_annotation_underline_new);
  tcase_add_test(tcase, test_annotation_underline_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("squiggly");
  tcase_add_checked_fixture(tcase, setup_annotation_squiggly, teardown);
  tcase_add_test(tcase, test_annotation_squiggly_new);
  tcase_add_test(tcase, test_annotation_squiggly_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("strike-out");
  tcase_add_checked_fixture(tcase, setup_annotation_strike_out, teardown);
  tcase_add_test(tcase, test_annotation_strike_out_new);
  tcase_add_test(tcase, test_annotation_strike_out_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("stamp");
  tcase_add_checked_fixture(tcase, setup_annotation_stamp, teardown);
  tcase_add_test(tcase, test_annotation_stamp_new);
  tcase_add_test(tcase, test_annotation_stamp_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("caret");
  tcase_add_checked_fixture(tcase, setup_annotation_caret, teardown);
  tcase_add_test(tcase, test_annotation_caret_new);
  tcase_add_test(tcase, test_annotation_caret_get_type);
  tcase_add_test(tcase, test_annotation_caret_init);
  tcase_add_test(tcase, test_annotation_caret_clear);
  tcase_add_test(tcase, test_annotation_caret_set_symbol);
  tcase_add_test(tcase, test_annotation_caret_get_symbol);
  tcase_add_test(tcase, test_annotation_caret_set_padding);
  tcase_add_test(tcase, test_annotation_caret_get_padding);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("ink");
  tcase_add_checked_fixture(tcase, setup_annotation_ink, teardown);
  tcase_add_test(tcase, test_annotation_ink_new);
  tcase_add_test(tcase, test_annotation_ink_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("popup");
  tcase_add_checked_fixture(tcase, setup_annotation_popup, teardown);
  tcase_add_test(tcase, test_annotation_popup_new);
  tcase_add_test(tcase, test_annotation_popup_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("file-attachment");
  tcase_add_checked_fixture(tcase, setup_annotation_file, teardown);
  tcase_add_test(tcase, test_annotation_file_new);
  tcase_add_test(tcase, test_annotation_file_get_type);
  tcase_add_test(tcase, test_annotation_file_init);
  tcase_add_test(tcase, test_annotation_file_clear);
  tcase_add_test(tcase, test_annotation_file_set_attachment);
  tcase_add_test(tcase, test_annotation_file_get_attachment);
  tcase_add_test(tcase, test_annotation_file_set_icon_name);
  tcase_add_test(tcase, test_annotation_file_get_icon_name);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("sound");
  tcase_add_checked_fixture(tcase, setup_annotation_sound, teardown);
  tcase_add_test(tcase, test_annotation_sound_new);
  tcase_add_test(tcase, test_annotation_sound_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("movie");
  tcase_add_checked_fixture(tcase, setup_annotation_movie, teardown);
  tcase_add_test(tcase, test_annotation_movie_new);
  tcase_add_test(tcase, test_annotation_movie_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("screen");
  tcase_add_checked_fixture(tcase, setup_annotation_screen, teardown);
  tcase_add_test(tcase, test_annotation_screen_new);
  tcase_add_test(tcase, test_annotation_screen_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("printer-mark");
  tcase_add_checked_fixture(tcase, setup_annotation_printer_mark, teardown);
  tcase_add_test(tcase, test_annotation_printer_mark_new);
  tcase_add_test(tcase, test_annotation_printer_mark_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("trap-net");
  tcase_add_checked_fixture(tcase, setup_annotation_trap_net, teardown);
  tcase_add_test(tcase, test_annotation_trap_net_new);
  tcase_add_test(tcase, test_annotation_trap_net_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("watermark");
  tcase_add_checked_fixture(tcase, setup_annotation_watermark, teardown);
  tcase_add_test(tcase, test_annotation_watermark_new);
  tcase_add_test(tcase, test_annotation_watermark_get_type);
  suite_add_tcase(suite, tcase);

  tcase = tcase_create("3D");
  tcase_add_checked_fixture(tcase, setup_annotation_3d, teardown);
  tcase_add_test(tcase, test_annotation_3d_new);
  tcase_add_test(tcase, test_annotation_3d_get_type);
  suite_add_tcase(suite, tcase);

  return suite;
}