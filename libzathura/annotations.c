/* See LICENSE file for license and copyright information */

#include <stdlib.h>
#include <string.h>

#include "annotations.h"

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
      zathura_annotation_markup_reply_type_t reply_type;
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
      char* icon_name;

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
      zathura_annotation_link_highlighting_mode_t highlighting_mode;

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

    /**
     * A line annotation displays a single straight line on the page. When
     * opened, it displays a pop-up window containing the text of the associated
     * note.
     */
    struct {
      /**
       * Specifying the starting and ending coordinates of the line in default
       * user space.
       */
      struct {
        zathura_point_t start; /**< Start point */
        zathura_point_t end; /*<< End point */
      } coordinates;

      /**
       * Border style
       */
      zathura_annotation_border_t border;

      /**
       * An array of two names specifying the line ending styles to be used in
       * drawing the annotation’s border. The first and second elements of the
       * array specify the line ending styles for the endpoints defined,
       * respectively, by the first and second pairs of coordinates, (x1, y1)
       * and (x2, y2), in the L array.
       */
      zathura_annotation_line_ending_t line_endings[2];

      /**
       * The color
       */
      zathura_annotation_color_t color;

      /**
       * The length of leader lines in default user space that extend from each
       * endpoint of the line perpendicular to the line itself. A positive value
       * means that the leader lines appear in the direction that is clockwise
       * when traversing the line from its starting point to its ending point
       * (as specified by @a coordinates); a negative value indicates the
       * opposite direction.
       */
      int leader_lines;

      /**
       * A non-negative number representing the length of leader line extensions
       * that extend from the line proper 180 degrees from the leader lines.
       */
      unsigned int leader_line_extensions_length;

      /**
       * If true, the text specified by the annotations contents or rich content
       * entries should be replicated as a caption in the appearance of the
       * line. The text should be rendered in a manner appropriate to the
       * content, taking into account factors such as writing direction.
       */
      bool caption;

      /**
       * A name describing the intent of the line annotation. Valid values are
       * @a ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_ARROW, which means that the
       * annotation is intended to function as an arrow, and
       * ZATHURA_ANNOTATION_MARKUP_INTENT_LINE_DIMENSION, which means that the
       * annotation is intended to function as a dimension line.
       */
      zathura_annotation_markup_intent_t intent;

      /**
       * A non-negative number representing the length of the leader line
       * offset, which is the amount of empty space between the endpoints of the
       * annotation and the beginning of the leader lines.
       */
      unsigned int leader_line_offset;

      /**
       * A name describing the annotation’s caption positioning. Valid values
       * are @a ZATHURA_ANNOTATION_CAPTION_POSITION_INLINE, meaning the caption
       * will be centered inside the line, and @a
       * ZATHURA_ANNOTATION_CAPTION_POSITION_TOP , meaning the caption will be
       * on top of the line.
       */
      zathura_annotation_line_caption_position_t caption_position;
    } line;

    /**
     * Square and circle annotations display, respectively, a rectangle or an
     * ellipse on the page. When opened, they display a pop-up window containing
     * the text of the associated note. The rectangle or ellipse is inscribed
     * within the annotation rectangle defined by the annotation position entry.
     * Despite the names square and circle, the width and height of the
     * annotation rectangle need not be equal.
     */
    struct {
      /**
       * The border
       */
      zathura_annotation_border_t border;

      /**
       * The color
       */
      zathura_annotation_color_t color;

      /**
       * A set of four numbers describing the numerical differences between two
       * rectangles: the position entry of the annotation and the actual
       * boundaries of the underlying square or circle. Such a difference can
       * occur in situations where a border effect causes the size of the
       * position to increase beyond that of the square or circle.
       *
       * The four numbers correspond to the differences in default user space
       * between the left, top, right, and bottom coordinates of the position
       * and those of the square or circle, respectively. Each value must be
       * greater than or equal to 0. The sum of the top and bottom differences
       * must be less than the height of the position, and the sum of the left
       * and right differences must be less than the width of the position.
       */
      struct {
        unsigned int left;
        unsigned int top;
        unsigned int right;
        unsigned int bottom;
      } padding;
    } square_and_circle;

    /**
     * Text markup annotations appear as highlights, underlines, strikeouts or
     * jagged ("squiggly") underlines in the text of a document. When opened,
     * they display a pop-up window containing the text of the associated note.
     *
     * The type of annotation that this dictionary describes; must be Highlight,
     * Underline, Squiggly, or StrikeOut for a highlight, underline,
     * squiggly-underline, or strikeout annotation, respectively.
     */
    struct {
      /**
       * An array of 8 × n numbers specifying the coordinates of n quadri-
       * laterals in default user space. Each quadrilateral encompasses a word
       * or group of contiguous words in the text underlying the annotation.
       *
       * The text is oriented with respect to the edge connecting points.
       */
      zathura_list_t* quad_points;
    } text_markup;

    /**
     * A caret annotation is a visual symbol that indicates the presence of text
     * edits.
     */
    struct {
      /**
       * A set of four numbers describing the numerical differences between two
       * rectangles: the Rect entry of the annotation and the actual boundaries
       * of the underlying caret. Such a difference can occur, for example, when
       * a paragraph symbol specified by @a symbol is displayed along with the caret.
       *
       * The four numbers correspond to the differences in default user space
       * between the left, top, right, and bottom coordinates of Rect and those
       * of the caret, respectively. Each value must be greater than or equal
       * to 0. The sum of the top and bottom differences must be less than the
       * height of Rect, and the sum of the left and right differences must be
       * less than the width of Rect.
       */
      struct {
        unsigned int left;
        unsigned int top;
        unsigned int right;
        unsigned int bottom;
      } padding;

      /**
       * A name specifying a symbol to be associated with the caret
       */
      zathura_annotation_caret_symbol_t symbol;
    } caret;

    /**
     * A rubber stamp annotation displays text or graphics intended to look as
     * if they were stamped on the page with a rubber stamp. When opened, it
     * displays a pop-up window containing the text of the associated note.
     */
    struct {
      /**
       * The name of an icon to be used in displaying the annotation. Viewer
       * applications should provide predefined icon appearances for at least
       * the following standard names:
       *
       * * Approved
       * * AsIs
       * * Confidential
       * * Departmental
       * * Draft
       * * Experimental
       * * Expired
       * * Final
       * * ForComment
       * * ForPublicRelease
       * * NotApproved
       * * NotForPublicRelease
       * * Sold
       * * TopSecret
       *
       * Additional names may be supported as well.
       */
      char* icon_name;
    } stamp;

    /**
     * An ink annotation represents a freehand "scribble" composed of one or
     * more disjoint paths. When opened, it displays a pop-up window containing
     * the text of the associated note. Table 8.33 shows the annotation
     * dictionary entries specific to this type of annotation.
     */
    struct {
      /**
       * An list of n zathura_path_t paths, each representing a stroked path.
       * Each array is a series of alternating horizontal and vertical
       * coordinates in default user space, specifying points along the path.
       * When drawn, the points are connected by straight lines or curves in an
       * implementation-dependent way.
       */
      zathura_list_t* paths;

      /**
       * A border style dictionary specifying the line width and dash pattern to
       * be used in drawing the paths.
       */
      zathura_annotation_border_t border;
    } ink;

    /**
     * A pop-up annotation displays text in a pop-up window for entry
     * and editing. It typically does not appear alone but is associated with a
     * markup annotation, its parent annotation, and is used for editing the
     * parent’s text. It has no appearance stream or associated actions of its
     * own and is identified by the Popup entry in the parent’s annotation
     * dictionary.
     */
    struct {
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
    } popup;

    /**
     * A file attachment annotation contains a reference to a file, which
     * typically is embedded in the document For example, a table of data might
     * use a file attachment annotation to link to a spreadsheet file based on
     * that data; activating the annotation extracts the embedded file and gives
     * the user an opportunity to view it or store it in the file system.
     *
     * The contents entry of the annotation dictionary may specify descriptive
     * text relating to the attached file. Viewer applications should use this
     * entry rather than the optional description entry.
     */
    struct {
      /**
       * The file associated with this annotation     .
       */
      zathura_attachment_t* file;

      /**
       * The name of an icon to be used in displaying the annotation.  Viewer
       * applications should provide predefined icon appearances for at least the
       * following standard names:
       *
       * * Graph
       * * PushPin
       * * Paperclip
       * * Tag
       *
       * Additional names may be supported as well.
       */
      char* icon_name;
    } file;

    /**
     * A sound annotation is analogous to a text annotation except that instead
     * of a text note, it contains sound recorded from the computer’s microphone
     * or imported from a file. When the annotation is activated, the sound is
     * played.  The annotation behaves like a text annotation in most ways, with
     * a different icon (by default, a speaker) to indicate that it represents a
     * sound.
     */
    struct {
      /**
       * A sound object defining the sound to be played when the annotation
       * is activated
       */
      zathura_sound_t* sound;

      /**
       * The name of an icon to be used in displaying the annotation. Viewer
       * applications should provide predefined icon appearances for at least
       * the following standard names:
       *
       * * Speaker
       * * Mic
       *
       * Additional names may be supported as well.
       */
      char* icon_name;
    } sound;

    /**
     * A movie annotation contains animated graphics and sound to be presented
     * on the computer screen and through the speakers. When the annotation is
     * activated, the movie is played.
     */
    struct {
      /**
       * The title of the movie annotation. Movie actions can use
       * this title to reference the movie annotation.
       */
      char* title;

      /**
       * The movie itself
       */
      zathura_movie_t* movie;

      /**
       * Movie activation
       *
       * If this is set the movie should be played with this specification and
       * the value of @a play_if_activated has to be ignored.
       */
      zathura_movie_activation_t* movie_activation;

      /**
       * A flag or dictionary specifying whether and how to play the movie when
       * the annotation is activated. If this value is a dictionary, it is a
       * movie activation dictionary specifying how to play the movie. If the
       * value is the boolean true, the movie should be played using default
       * activation parameters. If the value is false, the movie should not be
       * played.
       */
      bool play_if_activated;
    } movie;

    /**
     * A screen annotation specifies a region of a page upon which
     * media clips may be played. It also serves as an object from which actions
     * can be triggered.
     *
     * TODO: Apperance characteristics dictionary, Additional actions dictionary
     */
    struct {
      /**
       * The title of the screen annotation.
       */
      char* title;

      /**
       * An action to be performed when the annotation is activated.
       */
      zathura_action_t* action;
    } screen;
  } data;
};
