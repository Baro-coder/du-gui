#include "controls.h"
#include "execute.h"

/* DEFINITIONS */
#define _BLOCK_SIZE_DEF_IND 0
#define _BLOCK_SIZE_BYT_IND 1
#define _BLOCK_SIZE_KIB_IND 2
#define _BLOCK_SIZE_MIB_IND 3
#define _BLOCK_SIZE_GIB_IND 4

#define _EXCL_PATTERN_NONE_IND -1
#define _EXCL_PATTERN_C_IND 0
#define _EXCL_PATTERN_CPP_IND 1
#define _EXCL_PATTERN_PY_IND 2
#define _EXCL_PATTERN_SH_IND 3

/* REFERENCES */

// Menu items
GtkMenuItem *mitem_guide;
GtkMenuItem *mitem_about;
// Dialog windows
GtkWidget *dialog_guide;
GtkWidget *dialog_about;
// Output textview
GtkTextView *outview;
// Buttons
GtkButton *btn_clear;
GtkButton *btn_execute;
// Checkboxes
GtkToggleButton *chb_incf;
GtkToggleButton *chb_stsz;
GtkToggleButton *chb_foll;
GtkToggleButton *chb_couh;
GtkToggleButton *chb_sepd;
GtkToggleButton *chb_sofs;
// Radiobuttons
GtkRadioButton * rad_def;
GtkRadioButton *rad_byt;
GtkRadioButton *rad_kib;
GtkRadioButton *rad_mib;
GtkRadioButton *rad_gib;
// Combobox
GtkComboBox *combo_pattern;
// File Chooser
GtkFileChooserButton *dir_chooser_btn;

/* STATICS */

static int radio_flag_ind = _BLOCK_SIZE_DEF_IND;
static int combo_value_ind = _EXCL_PATTERN_NONE_IND;
static gchar *dirpath = NULL;

/* FUNCTIONS */

// Private function to collect all set program flags
void _get_command_flags(char *flags) {
	// Checkboxes
	gboolean state = FALSE;
	GtkToggleButton *chb_array[] = {
		chb_incf, 
		chb_stsz, 
		chb_foll, 
		chb_couh, 
		chb_sepd, 
		chb_sofs
	};
	char *arg_flags_array[] = {
		FLAG_INCF, 
		FLAG_STSZ, 
		FLAG_FOLL, 
		FLAG_COUH, 
		FLAG_SEPD, 
		FLAG_SOFS
	};

	for(int i = 0; i < 6; i++) {
		state = gtk_toggle_button_get_active(chb_array[i]);
		if(state) {
			strcat(flags, arg_flags_array[i]);
			strcat(flags, " ");
		}
	}

	// Radioboxes
	char *block_flags_array[] = {
		BLOCK_SIZE_DEF,
		BLOCK_SIZE_BYT,
		BLOCK_SIZE_KIB,
		BLOCK_SIZE_MIB,
		BLOCK_SIZE_GIB,
	};
	strcat(flags, block_flags_array[radio_flag_ind]);
	strcat(flags, " ");

	// Combobox
	char *excl_patterns_array[] = {
		EXCL_PATTERN_C,
		EXCL_PATTERN_CPP,
		EXCL_PATTERN_PY,
		EXCL_PATTERN_SH,
	};

	if(combo_value_ind != _EXCL_PATTERN_NONE_IND)
	{
		strcat(flags, "--exclude=");
		strcat(flags, excl_patterns_array[combo_value_ind]);
		strcat(flags, " ");
	}

	// Dir chooser
	if (dirpath != NULL)
	{
		// If dirpath is specified
		strcat(flags, dirpath);
	}
	else
	{
		// If not - get app current dir
		strcat(flags, ".");
	}
}


void controls_init(GtkBuilder *builder)
{
	// Menu items
	printf("     [-] GTK :: Controls :: Menu items : init : ");
	mitem_guide = GTK_MENU_ITEM(gtk_builder_get_object(builder, MENU_GUIDE_NAME));
	mitem_about = GTK_MENU_ITEM(gtk_builder_get_object(builder, MENU_ABOUT_NAME));
	printf("Done.\n");

	// Output textview
	printf("     [-] GTK :: Controls :: Output TextView : init : ");
	outview = GTK_TEXT_VIEW(gtk_builder_get_object(builder, OUTPUT_VIEW_NAME));
	printf("Done.\n");

	// Buttons
	printf("     [-] GTK :: Controls :: Buttons : init : ");
	btn_clear = GTK_BUTTON(gtk_builder_get_object(builder, BUTTON_CLR_NAME));
	btn_execute = GTK_BUTTON(gtk_builder_get_object(builder, BUTTON_EXE_NAME));
	printf("Done.\n");

	// Checkboxes
	printf("     [-] GTK :: Controls :: Checkboxes : init : ");
	chb_incf = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_INCF_NAME));
	chb_stsz = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_STSZ_NAME));
	chb_foll = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_FOLL_NAME));
	chb_couh = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_COUH_NAME));
	chb_sepd = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_SEPD_NAME));
	chb_sofs = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_SOFS_NAME));
	printf("Done.\n");

	// Radioboxes
	printf("     [-] GTK :: Controls :: Radioboxes : init : ");
	rad_def = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, RADIOBTN_DEF_NAME));
	rad_byt = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, RADIOBTN_BYT_NAME));
	rad_kib = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, RADIOBTN_KIB_NAME));
	rad_mib = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, RADIOBTN_MIB_NAME));
	rad_gib = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, RADIOBTN_GIB_NAME));
	printf("Done.\n");

	// Combobox
	printf("     [-] GTK :: Controls :: Combobox : init : ");
	combo_pattern = GTK_COMBO_BOX(gtk_builder_get_object(builder, COMBOBOX_NAME));
	printf("Done.\n");

	// Choose dir button
	printf("     [-] GTK :: Controls :: Dir chooser : init : ");
	dir_chooser_btn = GTK_FILE_CHOOSER_BUTTON(gtk_builder_get_object(builder, BUTTON_CHOOSE_DIR_NAME));
	printf("Done.\n");
}

// Events

void on_menu_item_guide_activate(GtkMenuItem *menu_item, gpointer data)
{
	// Log
	printf(" [*] Event :: Menu Item :: Guide : Activate\n");

	// Create dialog window object
	dialog_guide = gtk_message_dialog_new(
		GTK_WINDOW(window),
		GTK_DIALOG_DESTROY_WITH_PARENT,
		GTK_MESSAGE_INFO,
		GTK_BUTTONS_CLOSE,
		COM_DIALOG_GUIDE_PRIMARY);

	// Set info message
	gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog_guide), COM_DIALOG_GUIDE_SECONDARY);
	
	// Show dialog and wait for close signal
	gtk_dialog_run(GTK_DIALOG(dialog_guide));
	
	// Close dialog
	gtk_widget_destroy(GTK_WIDGET(dialog_guide));
}

void on_menu_item_about_activate(GtkMenuItem *menu_item, gpointer data)
{
	// Log
	printf(" [*] Event :: Menu Item :: About : Activate\n");

	// Create dialog window object
	dialog_about = gtk_about_dialog_new();

	// Set up properties
	// -- Program name
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(dialog_about), PROGRAM_NAME);
	// -- Program version
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog_about), PROGRAM_VERSION);
	// -- Website
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog_about), WEBSITE_URL);
	gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(dialog_about), WEBSITE_LABEL);
	// -- Comments
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog_about), ABOUT_COMMENTS);
	// -- License
	gtk_about_dialog_set_license_type(GTK_ABOUT_DIALOG(dialog_about), GTK_LICENSE_GPL_3_0);
	// -- Copyright
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog_about), COPYRIGHT);
	// -- Authors
	const gchar *authors[] = {AUTHOR, NULL};
	gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(dialog_about), authors);
	// -- Logo
	GError *error = NULL;
	GdkPixbuf *logo_pixbuf = gdk_pixbuf_new_from_file(LOGO_PATH, &error);
	if (logo_pixbuf == NULL)
	{
		// If cannot load logo file
		printf("   [!] GDK :: Load Pixbuf from file : Error : Cannot open file = %s :: Error message = %s\n", LOGO_PATH, error->message);
		g_error_free(error);
	}
	else
	{
		// Set logo file pixels buffer
		gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog_about), logo_pixbuf);
	}
	
	// Show dialog and wait for close signal
	gtk_dialog_run(GTK_DIALOG(dialog_about));

	// Close dialog
	gtk_widget_destroy(GTK_WIDGET(dialog_about));

	// Memory free
	g_object_unref(logo_pixbuf);
}

void radio_toogle(GtkRadioButton *radiobutton, gpointer data) {
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton)))
	{
		if (radiobutton == rad_def) {
			radio_flag_ind = _BLOCK_SIZE_DEF_IND;
		}
		else if (radiobutton == rad_byt)
		{
			radio_flag_ind = _BLOCK_SIZE_BYT_IND;
		}
		else if (radiobutton == rad_kib)
		{
			radio_flag_ind = _BLOCK_SIZE_KIB_IND;
		}
		else if (radiobutton == rad_mib)
		{
			radio_flag_ind = _BLOCK_SIZE_MIB_IND;
		}
		else if (radiobutton == rad_gib)
		{
			radio_flag_ind = _BLOCK_SIZE_GIB_IND;
		} else 
		{
			printf(" [!] Event :: Radiobutton :: Toogle : Error : setting to default.");
			radio_flag_ind = _BLOCK_SIZE_DEF_IND;
			return;
		}

		// Log
		printf(" [*] Event :: Radiobutton :: Toogle : Value = %d\n", radio_flag_ind);
	}
}

void on_combobox_changed(GtkComboBox *combobox, gpointer data) {
	GtkTreeIter iter;
	GtkTreeModel *model;
	gchar *entry_val;

	// Pobierz aktualnie wybrany element
	model = gtk_combo_box_get_model(combobox);
	if (gtk_combo_box_get_active_iter(combobox, &iter))
	{
		// Pobierz wartość elementu
		gtk_tree_model_get(model, &iter, 0, &entry_val, -1);

		if (strcmp(entry_val, "None") == 0)
		{
			combo_value_ind = _EXCL_PATTERN_NONE_IND;
		}
		else if (strcmp(entry_val, "C Source Files") == 0)
		{
			combo_value_ind = _EXCL_PATTERN_C_IND;
		}
		else if (strcmp(entry_val, "C++ Source Files") == 0)
		{
			combo_value_ind = _EXCL_PATTERN_CPP_IND;
		}
		else if (strcmp(entry_val, "Python Files") == 0)
		{
			combo_value_ind = _EXCL_PATTERN_PY_IND;
		}
		else if (strcmp(entry_val, "Shell Scripts") == 0)
		{
			combo_value_ind = _EXCL_PATTERN_SH_IND;
		}
		else 
		{
			printf(" [!] Event :: Combobox :: Change : Error - setting to default None.\n");
			combo_value_ind = _EXCL_PATTERN_NONE_IND;
			g_free(entry_val);
			return;
		}

		// Log
		printf(" [*] Event :: Combobox :: Change : Label = %s : Value = %d\n", entry_val, combo_value_ind);

		g_free(entry_val);
	}
}

void on_dir_chooser_btn_file_set(GtkFileChooserButton *chooser, gpointer data) {
	dirpath = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chooser));
	if (dirpath != NULL)
	{
		printf(" [*] Event :: Dir chooser : File set : %s\n", dirpath);
	}
}

void btn_clear_on_click(GtkButton *button, gpointer data) {
	// Log
	printf(" [*] Event :: Button :: Clicked : Clear\n");

	// Get pointer to outview
	GtkTextView *textview = GTK_TEXT_VIEW(data);

	// Get textview text buffer
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);

	// Clear buffer
	gtk_text_buffer_set_text(buffer, "", -1);
}

void btn_execute_on_click(GtkButton *button, gpointer data) {
	// Log
	printf(" [*] Event :: Button :: Clicked : Execute\n");

	// Get pointer to outview
	GtkTextView *textview = GTK_TEXT_VIEW(data);

	// Get textview text buffer
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);

	// Create iterator at the end of text
	GtkTextIter end;
	gtk_text_buffer_get_end_iter(buffer, &end);

	// Get command flags
	char* flags = (char*) malloc(FLAGS_BUFFER_SIZE * sizeof(char));
	memset(flags, 0, FLAGS_BUFFER_SIZE);
	_get_command_flags(flags);

	// Execute command and get output stream reference
	FILE *ostream = execute_cmd(flags);

	// Check outstream reference
	if (ostream == NULL)
	{
		// Invalid command
		gtk_text_buffer_insert(buffer, &end, COM_INVALID_CMD, -1);
	}
	else
	{
		// Valid command
		gtk_text_buffer_insert(buffer, &end, COM_RESULTS, -1);
		
		char* out = (char*) malloc(OUT_BUFFER_SIZE * sizeof(char));
		memset(out, 0, OUT_BUFFER_SIZE);

		// Print command output
		while (fgets(out, sizeof(out), ostream) != NULL)
		{
			gtk_text_buffer_insert(buffer, &end, out, -1);
		}

		// Close stream and print status code
		memset(out, 0, OUT_BUFFER_SIZE);
		int status = pclose(ostream);
		sprintf(out, "\nExecuted with code: %d\n", status);
		gtk_text_buffer_insert(buffer, &end, out, -1);

		// Print results separator
		gtk_text_buffer_insert(buffer, &end, COM_SEPARATOR, -1);

		// Memory free
		free(out);
	}

	// Memory free
	free(flags);
}

void on_main_destroy(GtkWindow *window, gpointer data) {
	// Log
	printf(" [*] Event :: Main Window :: Destroy\n");
	
	// GTK main loop break
	gtk_main_quit();
}