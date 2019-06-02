/* See LICENSE file for license and copyright information */

#include <check.h>

#include <libzathura/annotations.h>

static void setup_annotation_widget(void) {
  setup_document_plugin(&plugin_manager, &document);

  fail_unless(zathura_document_get_page(document, 0, &page) == ZATHURA_ERROR_OK);
  fail_unless(page != NULL);

  fail_unless(zathura_annotation_new(page, &annotation, ZATHURA_ANNOTATION_WIDGET) == ZATHURA_ERROR_OK);
  fail_unless(annotation != NULL);
}

START_TEST(test_annotation_widget_new) {
} END_TEST

START_TEST(test_annotation_widget_get_type) {
  zathura_annotation_type_t type;
  fail_unless(zathura_annotation_get_type(annotation, &type) == ZATHURA_ERROR_OK);
  fail_unless(type == ZATHURA_ANNOTATION_WIDGET);
} END_TEST

START_TEST(test_annotation_widget_init) {
  /* invalid arguments */
  fail_unless(zathura_annotation_widget_init(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_init(annotation)
      == ZATHURA_ERROR_OK); // double initialization

  /* fault injection */
#ifdef WITH_LIBFIU
  fiu_enable("libc/mm/calloc", 1, NULL, 0);
  fail_unless(zathura_annotation_widget_init(annotation)
      == ZATHURA_ERROR_OUT_OF_MEMORY); // double initialization
  fiu_disable("libc/mm/calloc");
#endif
} END_TEST

START_TEST(test_annotation_widget_clear) {
  /* invalid arguments */
  fail_unless(zathura_annotation_widget_clear(NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
} END_TEST

START_TEST(test_annotation_widget_set_form_field) {
  zathura_form_field_t* form_field = (zathura_form_field_t*) 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_set_form_field(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_set_form_field(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_set_form_field(NULL, form_field) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_set_form_field(annotation, form_field) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_get_form_field) {
  zathura_form_field_t* form_field;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_get_form_field(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_form_field(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_form_field(NULL, &form_field) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_get_form_field(annotation, &form_field) == ZATHURA_ERROR_OK);
  fail_unless(form_field == NULL);

  fail_unless(zathura_annotation_widget_set_form_field(annotation, (zathura_form_field_t*) 0xCAFEBABE) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_widget_get_form_field(annotation, &form_field) == ZATHURA_ERROR_OK);
  fail_unless(form_field == (zathura_form_field_t*) 0xCAFEBABE);
} END_TEST

START_TEST(test_annotation_widget_set_highlighting_mode) {
  zathura_annotation_highlighting_mode_t highlighting_mode = ZATHURA_ANNOTATION_HIGHLIGHTING_NONE;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_set_highlighting_mode(NULL, highlighting_mode) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_set_highlighting_mode(annotation, highlighting_mode) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_get_highlighting_mode) {
  zathura_annotation_highlighting_mode_t highlighting_mode;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_get_highlighting_mode(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_highlighting_mode(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_highlighting_mode(NULL, &highlighting_mode) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_get_highlighting_mode(annotation, &highlighting_mode) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_set_action) {
  zathura_action_t* action = (zathura_action_t*) 0xCAFEBABE;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_set_action(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_set_action(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_set_action(NULL, action) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_set_action(annotation, action) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_get_action) {
  zathura_action_t* action;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_get_action(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_action(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_action(NULL, &action) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_get_action(annotation, &action) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_set_additional_actions) {
  zathura_list_t* additional_actions = zathura_list_alloc();
  fail_unless(additional_actions != NULL);

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_set_additional_actions(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_set_additional_actions(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_set_additional_actions(NULL, additional_actions) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_set_additional_actions(annotation, additional_actions) == ZATHURA_ERROR_OK);
  zathura_list_free(additional_actions);
} END_TEST

START_TEST(test_annotation_widget_get_additional_actions) {
  zathura_list_t* additional_actions;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_get_additional_actions(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_additional_actions(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_additional_actions(NULL, &additional_actions) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_get_additional_actions(annotation, &additional_actions) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_set_border) {
  zathura_annotation_border_t border = { 0,
    ZATHURA_ANNOTATION_BORDER_STYLE_SOLID, {NULL, 0},
    ZATHURA_ANNOTATION_BORDER_EFFECT_NONE, 0.0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_set_border(NULL, border) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_set_border(annotation, border) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_get_border) {
  zathura_annotation_border_t border = { 0,
    ZATHURA_ANNOTATION_BORDER_STYLE_SOLID, {NULL, 0},
    ZATHURA_ANNOTATION_BORDER_EFFECT_NONE, 0.0 };
  zathura_annotation_border_t border_input = { 0,
    ZATHURA_ANNOTATION_BORDER_STYLE_SOLID, {NULL, 0},
    ZATHURA_ANNOTATION_BORDER_EFFECT_NONE, 0.0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_get_border(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_border(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_border(NULL, &border) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_get_border(annotation, &border) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_widget_set_border(annotation, border_input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_widget_get_border(annotation, &border) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_set_background_color) {
  zathura_annotation_color_t color = { 0 };

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_set_background_color(NULL, color) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_set_background_color(annotation, color) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_get_background_color) {
  zathura_annotation_color_t color = { ZATHURA_ANNOTATION_COLOR_SPACE_NONE, {0, 0, 0, 0} };
  zathura_annotation_color_t color_input = { ZATHURA_ANNOTATION_COLOR_SPACE_NONE, {1, 2, 3, 4} };

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_get_background_color(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_background_color(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_background_color(NULL, &color) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_get_background_color(annotation, &color) == ZATHURA_ERROR_OK);

  fail_unless(zathura_annotation_widget_set_background_color(annotation, color_input) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_widget_get_background_color(annotation, &color) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_set_rotation) {
  int rotation = 0;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_set_rotation(NULL, rotation) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_set_rotation(annotation, 45) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_set_rotation(annotation, rotation) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_get_rotation) {
  int rotation = 90;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_get_rotation(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_rotation(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_rotation(NULL, &rotation) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_get_rotation(annotation, &rotation) == ZATHURA_ERROR_OK);
  fail_unless(rotation == 0);

  fail_unless(zathura_annotation_widget_set_rotation(annotation, 90) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_widget_get_rotation(annotation, &rotation) == ZATHURA_ERROR_OK);
  fail_unless(rotation == 90);
} END_TEST

START_TEST(test_annotation_widget_set_caption) {
  /* invalid arguments */
  fail_unless(zathura_annotation_widget_set_caption(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_set_caption(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_set_caption(NULL, "test")
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_set_caption(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_widget_set_caption(annotation, "test")
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_get_caption) {
  char* caption = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_get_caption(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_caption(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_caption(NULL, &caption)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_get_caption(annotation, &caption)
      == ZATHURA_ERROR_OK);
  fail_unless(caption == NULL);
  fail_unless(zathura_annotation_widget_set_caption(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_widget_get_caption(annotation, &caption)
      == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(caption, "test") == 0);
} END_TEST

START_TEST(test_annotation_widget_set_rollover_caption) {
  /* invalid arguments */
  fail_unless(zathura_annotation_widget_set_rollover_caption(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_set_rollover_caption(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_set_rollover_caption(NULL, "test")
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_set_rollover_caption(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_widget_set_rollover_caption(annotation, "test")
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_get_rollover_caption) {
  char* rollover_caption = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_get_rollover_caption(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_rollover_caption(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_rollover_caption(NULL, &rollover_caption)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_get_rollover_caption(annotation, &rollover_caption)
      == ZATHURA_ERROR_OK);
  fail_unless(rollover_caption == NULL);
  fail_unless(zathura_annotation_widget_set_rollover_caption(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_widget_get_rollover_caption(annotation, &rollover_caption)
      == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(rollover_caption, "test") == 0);
} END_TEST

START_TEST(test_annotation_widget_set_alternate_caption) {
  /* invalid arguments */
  fail_unless(zathura_annotation_widget_set_alternate_caption(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_set_alternate_caption(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_set_alternate_caption(NULL, "test")
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_set_alternate_caption(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_widget_set_alternate_caption(annotation, "test")
      == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_get_alternate_caption) {
  char* alternate_caption = NULL;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_get_alternate_caption(NULL, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_alternate_caption(annotation, NULL)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_alternate_caption(NULL, &alternate_caption)
      == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_get_alternate_caption(annotation, &alternate_caption)
      == ZATHURA_ERROR_OK);
  fail_unless(alternate_caption == NULL);
  fail_unless(zathura_annotation_widget_set_alternate_caption(annotation, "test")
      == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_widget_get_alternate_caption(annotation, &alternate_caption)
      == ZATHURA_ERROR_OK);
  fail_unless(g_strcmp0(alternate_caption, "test") == 0);
} END_TEST

START_TEST(test_annotation_widget_set_caption_position) {
  zathura_annotation_widget_caption_position_t caption_position = ZATHURA_ANNOTATION_WIDGET_CAPTION_POSITION_NO_CAPTION_ICON_ONLY;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_set_caption_position(NULL, caption_position) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_set_caption_position(annotation, caption_position) == ZATHURA_ERROR_OK);
} END_TEST

START_TEST(test_annotation_widget_get_caption_position) {
  zathura_annotation_widget_caption_position_t caption_position = ZATHURA_ANNOTATION_WIDGET_CAPTION_POSITION_NO_CAPTION_ICON_ONLY;

  /* invalid arguments */
  fail_unless(zathura_annotation_widget_get_caption_position(NULL, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_caption_position(annotation, NULL) == ZATHURA_ERROR_INVALID_ARGUMENTS);
  fail_unless(zathura_annotation_widget_get_caption_position(NULL, &caption_position) == ZATHURA_ERROR_INVALID_ARGUMENTS);

  /* valid arguments */
  fail_unless(zathura_annotation_widget_get_caption_position(annotation, &caption_position) == ZATHURA_ERROR_OK);
  fail_unless(caption_position == ZATHURA_ANNOTATION_WIDGET_CAPTION_POSITION_NO_ICON_CAPTION_ONLY);

  fail_unless(zathura_annotation_widget_set_caption_position(annotation, ZATHURA_ANNOTATION_WIDGET_CAPTION_POSITION_CAPTION_ABOVE_ICON ) == ZATHURA_ERROR_OK);
  fail_unless(zathura_annotation_widget_get_caption_position(annotation, &caption_position) == ZATHURA_ERROR_OK);
  fail_unless(caption_position == ZATHURA_ANNOTATION_WIDGET_CAPTION_POSITION_CAPTION_ABOVE_ICON );
} END_TEST
