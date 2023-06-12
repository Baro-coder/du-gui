#ifndef H_CONTROLS
#define H_CONTROLS

/* LIBRARIES */

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DEFINITIONS */

// Metadata
#define PROGRAM_NAME "du-gui"
#define PROGRAM_VERSION "1.0.0"
#define LICENSE "GPL 3.0"
#define LOGO_PATH "ui/img/logo.png"
#define WEBSITE_URL "https://github.com/Baro-coder/du-gui"
#define WEBSITE_LABEL "Github repository"
#define COPYRIGHT "du-gui@Baro-coder"
#define ABOUT_COMMENTS "Graphical Overlay for UNIX console program `du`."
#define AUTHOR "Baro-coder"

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

// Dialog Windows
// -- Dialog window Guide
#define DIALOG_GUIDE_NAME "dialog_guide"
// -- Dialog window About
#define DIALOG_ABOUT_NAME "dialog_about"

// Buttons names
// -- Dialog `guide` button `OK` name
#define DIALOG_GUIDE_BUTTON_OK "dialog_guide_button_ok"
// -- Dialog `about` button `OK` name
#define DIALOG_ABOUT_BUTTON_OK "dialog_about_button_ok"
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
#define COM_DIALOG_GUIDE_PRIMARY "User guide"
#define COM_DIALOG_GUIDE_SECONDARY "1. Choose directory to examine (on default: program current dir).\n2. (Optional) Choose pattern of files to be excluded from output results.\n3. (Optional) Check auxillary options.\n4. (Optional) Select block size (on default: human readable format).\n5. Click `Execute` button."


/* DECLARATIONS */

extern GtkWidget *window;
extern GtkBuilder *builder;
extern GtkMenuItem *mitem_guide;
extern GtkMenuItem *mitem_about;
extern GtkWidget *dialog_guide;
extern GtkWidget *dialog_about;
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

// Menu item `guide` activate event handler
void on_menu_item_guide_activate(GtkMenuItem *menu_item, gpointer data);

// Menu item `about` activate event handler
void on_menu_item_about_activate(GtkMenuItem *menu_item, gpointer data);

// Radiobutton toogle event handler
void radio_toogle(GtkRadioButton *radiobutton, gpointer data);

// Combobox item change event handler
void on_combobox_changed(GtkComboBox *combobox, gpointer data);

// Dir chooser file set event handler
void on_dir_chooser_btn_file_set(GtkFileChooserButton *chooser, gpointer data);

// Button `clear` clicked event handler
void btn_clear_on_click(GtkButton *button, gpointer data);

// Button `execute` clicked event handler
void btn_execute_on_click(GtkButton *button, gpointer data);

// Main window destroy event handler
void on_main_destroy(GtkWindow *window, gpointer data);

#endif