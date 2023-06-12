#ifndef H_CONTROLS
#define H_CONTROLS

/* LIBRARIES */
#include <gtk/gtk.h>

/* DEFINITIONS */

// Main Components names
// -- Main Window name
#define MAIN_WINDOW_NAME "main_window"
// -- Output textview name
#define OUTPUT_VIEW_NAME "textview_out"

// Menu Items names
// -- Guide item name
#define MENU_GUIDE_NAME "menu_item_guide"
// -- About item name
#define MENU_ABOUT_NAME "menu_item_about"

// Buttons names
// -- Clear button name
#define BUTTON_CLR_NAME "button_clear"
// -- Execute button name
#define BUTTON_EXE_NAME "button_execute"
// -- Choose directory button name
#define BUTTON_CHOOSE_DIR_NAME "button_choose_dir"

// Combobox entry
// -- Exclude files entry name
#define EXCL_ENTRY_NAME "combobox_pattern_entry"

// Checkboxes names
// -- Check box name : Include files
#define CHECKBOX_INCF_NAME "check_a"
// -- Check box name : Show total size
#define CHECKBOX_STSZ_NAME "check_c"
// -- Check box name : Follow links
#define CHECKBOX_FOLL_NAME "check_L"
// -- Check box name : Count hardlinked
#define CHECKBOX_COUH_NAME "check_l"
// -- Check box name : Separate directories
#define CHECKBOX_SEPD_NAME "check_S"
// -- Check box name : Skip other file systems
#define CHECKBOX_SOFS_NAME "check_x"

// Radioboxes names
// -- Radiobox : Default
#define REDIOBOX_DEF_NAME "radio_default"
// -- Radiobox : Default
#define REDIOBOX_BYT_NAME "radio_b"
// -- Radiobox : Default
#define REDIOBOX_KIB_NAME "radio_K"
// -- Radiobox : Default
#define REDIOBOX_MIB_NAME "radio_M"
// -- Radiobox : Default
#define REDIOBOX_GIB_NAME "radio_G"

/* DECLARATIONS */
extern GtkButton *btn_clear;
extern GtkButton *btn_execute;
extern GtkTextView *outview;

/* FUNCTIONS */
void controls_init(GtkBuilder* builder);
void btn_clear_on_click(GtkButton *button, gpointer user_data);
void btn_execute_on_click(GtkButton *button, gpointer user_data);

#endif