#ifndef H_CONTROLS
#define H_CONTROLS

/* LIBRARIES */
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
#define COMBOBOX_NAME "combobox_patterns"

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

// Radiobuttons names
// -- Radiobutton : Default
#define RADIOBTN_DEF_NAME "radio_default"
// -- Radiobutton : Block size B
#define RADIOBTN_BYT_NAME "radio_b"
// -- Radiobutton : Block size KiB
#define RADIOBTN_KIB_NAME "radio_K"
// -- Radiobutton : Block size MiB
#define RADIOBTN_MIB_NAME "radio_M"
// -- Radiobutton : Block size GiB
#define RADIOBTN_GIB_NAME "radio_G"

// COMMUNICATES
#define COM_RESULTS "Results:\n"
#define COM_INVALID_CMD "Invalid command!\n"
#define COM_SEPARATOR "------------------------------------------------------------\n"

/* DECLARATIONS */
extern GtkButton *btn_clear;
extern GtkButton *btn_execute;
extern GtkTextView *outview;
extern GtkRadioButton *rad_def;
extern GtkRadioButton *rad_byt;
extern GtkRadioButton *rad_kib;
extern GtkRadioButton *rad_mib;
extern GtkRadioButton *rad_gib;
extern GtkComboBox *combo_pattern;
extern GtkFileChooserButton *dir_chooser_btn;

/* FUNCTIONS */

// Get controls objects and assign to appropriate references
void controls_init(GtkBuilder *builder);

// Radiobutton toogle event handler
void radio_toogle(GtkRadioButton *radiobutton, gpointer user_data);

// Combobox item change event handler
void on_combobox_changed(GtkComboBox *combobox, gpointer user_data);

// Dir chooser file set event handler
void on_dir_chooser_btn_file_set(GtkFileChooserButton *chooser, gpointer user_data);

// Button `clear` clicked event handler
void btn_clear_on_click(GtkButton *button, gpointer user_data);

// Button `execute` clicked event handler
void btn_execute_on_click(GtkButton *button, gpointer user_data);

#endif