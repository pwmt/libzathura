/* See LICENSE file for license and copyright information */

#include "annotations.h"

#include <stdlib.h>
#include <string.h>

struct zathura_annotation_s {
  /**
   * The type of annotation that this dictionary describes
   */
  zathura_annotation_type_t type;

  /**
   * The annotation rectangle, defining the location of the annotation on
   * the page in default user space units.
   */
  zathura_rectangle_t position;

  /**
   * Text to be displayed for the annotation or, if this type of annotation does
   * not display text, an alternate description of the annotation’s contents in
   * human-readable form. In either case, this text is useful when extracting
   * the document’s contents in support of accessibility to users with
   * disabilities or for other purposes.
   */
  char* content;

  /**
   * The annotation name, a text string uniquely identifying it
   * among all the annotations on its page.
   */
  char* name;

  /**
   * The date and time when the annotation was most recently
   * modified.
   */
  time_t modification_date; /**< Modification date */

  /**
   * Set of flags specifying various characteristics of the annotation.
   */
  zathura_annotation_flag_t flags; /**< Flags of the annotation */

  /**
   * An color object representing a color used for the following purposes:
   *
   * * The background of the annotation’s icon when closed
   * * The title bar of the annotation’s pop-up window
   * * The border of a link annotation
   */
   zathura_annotation_color_t color;

  /**
   * Describes if the annotation is a markup annotation
   */
  bool is_markup;

  union {
    /**
     * Many annotation types are defined as markup annotations because they are
     * used primarily to mark up PDF documents. These annotations have text that
     * appears as part of the annotation and may be displayed in other ways by a
     * viewer application, such as in a Comments pane.
     */
    struct {
      /**
       * The text label to be displayed in the title bar of the annotation’s
       * pop-up window when open and active. By convention, this entry
       * identifies the user who added the annotation.
       */
      char* label;

      /**
       * An indirect reference to a pop-up annotation for entering or editing
       * the text associated with this annotation.
       */
      zathura_annotation_t* popup_annotation;

      /**
       * A rich text string to be displayed in the pop-up window when the
       * annotation is opened.
       */
      char* text;

      /**
       * The date and time when the annotation was created.
       */
      time_t creation_date;

      /**
       * A reference to the annotation that this annotation is “in reply to”.
       * Both annotations must be on the same page of the document. The
       * relationship between the two annotations is specified by the RT entry.
       */
      zathura_annotation_t* reply_to_annotation;

      /**
       * A type specifying the relationship (the “reply type”) between this
       * annotation and one specified by @a ::reply_type.
       */
      zathura_annotation_reply_type_t reply_type;
    } markup;

    /**
     * A text annotation represents a “sticky note” attached to a point in the PDF
     * document. When closed, the annotation appears as an icon; when open, it
     * displays a pop-up window containing the text of the note in a font and
     * size chosen by the viewer application. Text annotations do not scale and
     * rotate with the page; they behave as if the NoZoom and NoRotate
     * annotation flags were always set.
     */
    struct {
      /**
       * A flag specifying whether the annotation should initially be displayed
       * open.
       */
      bool open;

      /**
       * The name of an icon to be used in displaying the annotation. Viewer
       * applications should provide predefined icon appearances for at least
       * the following standard names:
       *
       * * Comment
       * * Help
       * * Insert
       * * Key
       * * NewParagraph
       * * Note
       * * Paragraph
       *
       * Additional names may be supported as well.
       */
      char* name;

      /**
       * The state to which the original annotation should be set
       */
      zathura_annotation_text_state_t state;
    } text;

    /**
     * A link annotation represents either a hypertext link to a destination
     * elsewhere in the document or an action to be performed.
     */
    struct {
      /**
       * An action to be performed when the link annotation is ac-
       * tivated
       */
      /* zathura_link_t action; */

      /**
       * The annotation’s highlighting mode, the visual effect to be used when
       * the mouse button is pressed or held down inside its active area.
       */
      zathura_annotation_highlighting_mode_t highlighting_mode;

      /**
       * An list of n @a zathura_quad_point_t objects specifying the coordinates
       * of n quadrilaterals in default user space that comprise the region in
       * which the link should be activated.
       *
       * If this entry is not present or the viewer application does not
       * recognize it, the region specified by the @a ::position entry should be
       * used.  @a region should be ignored if any coordinate in the array lies
       * outside the region specified by @a ::position.
       */
      zathura_list_t* quad_points;
    } link;

    /**
     * A free text annotation displays text directly on the page. Unlike an
     * ordinary text annotation , a free text annotation has no open or closed
     * state; instead of being displayed in a pop-up window, the text is always
     * visible.
     */
    struct {
      /**
       * The default appearance string to be used in formatting the text.
       */
      char* text;

      /**
       * Specifying the form of quadding (justification) to be
       * used in displaying the annotation’s text:
       */
      zathura_annotation_justification_t justification;

      /**
       * A rich text string.
       */
      char* rich_text;

      /**
       * A default style string,
       */
      char* style_string;

      /**
       * Specifying a call-out line attached to the free
       * text annotation.
       */
      zathura_callout_line_t callout_line;

      /**
       * Border of the annotation.
       */
      zathura_annotation_border_t border;

      /**
       * A name describing the intent of the markup annotation. Intents allow
       * viewer applications to distinguish between different uses and behaviors
       * of a single markup annotation type. If this entry is not present or its
       * value is the same as the annotation type, the annotation has no
       * explicit intent and should behave in a generic manner in a viewer
       * application.
       */
      zathura_annotation_markup_intent_t intent;

      /**
       * A set of four numbers describing the numerical differences between two
       * rectangles: the position entry of the annotation and a rectangle
       * contained within that rectangle. The inner rectangle is where the
       * annotation’s text should be displayed. Any border styles and/or border
       * effects specified by the border entry, respectively, are applied to the
       * border of the inner rectangle. The four numbers correspond to the
       * differences in default user space between the left, top, right, and
       * bottom coordinates of the position and those of the inner rectangle,
       * respectively. Each value must be greater than or equal to 0. The sum of
       * the top and bottom differences must be less than the height of
       * position, and the sum of the left and right differences must be less
       * than the width of position.
       */
      struct {
        unsigned int left;
        unsigned int top;
        unsigned int right;
        unsigned int bottom;
      } padding;

      /**
       * An array of two names specifying the line ending styles to be used in
       * drawing the annotation’s border. The first and second elements of the
       * array specify the line ending styles for the endpoints defined,
       * respectively, by the first and second pairs of coordinates, (x1, y1)
       * and (x2, y2), in the L array.
       */
      zathura_annotation_line_ending_t line_endings[2];
    } free_text;
  } data;
};
