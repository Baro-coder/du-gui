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
#define _EXCL_PATTERN_PY_IND 1
#define _EXCL_PATTERN_SH_IND 2

/* REFERENCES */

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
			sprintf(flags, "%s%s ", flags, arg_flags_array[i]);
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
	sprintf(flags, "%s%s ", flags, block_flags_array[radio_flag_ind]);

	// Combobox
	char *excl_patterns_array[] = {
		EXCL_PATTERN_C,
		EXCL_PATTERN_PY,
		EXCL_PATTERN_SH,
	};

	if(combo_value_ind != _EXCL_PATTERN_NONE_IND)
	{
		sprintf(flags, "%s--exclude=%s ", flags, excl_patterns_array[combo_value_ind]);
	}

	// Dir chooser
	if (dirpath != NULL)
	{
		// Specified dir path
		sprintf(flags, "%s%s", flags, dirpath);
	}
	else
	{
		// Current program dir
		sprintf(flags, "%s.", flags);
	}
}


void controls_init(GtkBuilder *builder)
{
	// Log
	printf(" [*] Controls :: init:\n");

	// Output textview
	printf("   [+] Controls :: Output TextView : init : ");
	outview = GTK_TEXT_VIEW(gtk_builder_get_object(builder, OUTPUT_VIEW_NAME));
	printf("Done.\n");

	// Buttons
	printf("   [+] Controls :: Buttons : init : ");
	btn_clear = GTK_BUTTON(gtk_builder_get_object(builder, BUTTON_CLR_NAME));
	btn_execute = GTK_BUTTON(gtk_builder_get_object(builder, BUTTON_EXE_NAME));
	printf("Done.\n");

	// Checkboxes
	printf("   [+] Controls :: Checkboxes : init : ");
	chb_incf = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_INCF_NAME));
	chb_stsz = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_STSZ_NAME));
	chb_foll = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_FOLL_NAME));
	chb_couh = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_COUH_NAME));
	chb_sepd = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_SEPD_NAME));
	chb_sofs = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_SOFS_NAME));
	printf("Done.\n");

	// Radioboxes
	printf("   [+] Controls :: Radioboxes : init : ");
	rad_def = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, RADIOBTN_DEF_NAME));
	rad_byt = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, RADIOBTN_BYT_NAME));
	rad_kib = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, RADIOBTN_KIB_NAME));
	rad_mib = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, RADIOBTN_MIB_NAME));
	rad_gib = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, RADIOBTN_GIB_NAME));
	printf("Done.\n");

	// Combobox
	printf("   [+] Controls :: Combobox : init : ");
	combo_pattern = GTK_COMBO_BOX(gtk_builder_get_object(builder, COMBOBOX_NAME));
	printf("Done.\n");

	// Choose dir button
	printf("   [+] Controls :: Dir chooser : init : ");
	dir_chooser_btn = GTK_FILE_CHOOSER(gtk_builder_get_object(builder, BUTTON_CHOOSE_DIR_NAME));
	printf("Done.\n");

	printf(" [*] Controls :: init : Done.\n");
}

// Events

void radio_toogle(GtkRadioButton *radiobutton, gpointer user_data) {
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

void on_combobox_changed(GtkComboBox *combobox, gpointer user_data) {
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
		else if (strcmp(entry_val, "*.c *.h *.cpp *.hpp") == 0)
		{
			combo_value_ind = _EXCL_PATTERN_C_IND;
		}
		else if (strcmp(entry_val, "*.py") == 0)
		{
			combo_value_ind = _EXCL_PATTERN_PY_IND;
		}
		else if (strcmp(entry_val, "*.sh") == 0)
		{
			combo_value_ind = _EXCL_PATTERN_SH_IND;
		}
		else 
		{
			printf(" [!] Event :: Combobox :: Change : Error - setting to default None.\n", entry_val);
			combo_value_ind = _EXCL_PATTERN_NONE_IND;
			g_free(entry_val);
			return;
		}

		// Log
		printf(" [*] Event :: Combobox :: Change : Value = %s\n", entry_val);

		g_free(entry_val);
	}
}

void on_dir_chooser_btn_file_set(GtkFileChooserButton *chooser, gpointer user_data) {
	dirpath = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chooser));
	if (dirpath != NULL)
	{
		printf(" [*] Event :: Dir chooser : File set : %s\n", dirpath);
	}
}

void btn_clear_on_click(GtkButton *button, gpointer user_data) {
	// Log
	printf(" [*] Event :: Button :: Clicked : Clear\n");

	// Get pointer to outview
	GtkTextView *textview = GTK_TEXT_VIEW(user_data);

	// Get textview text buffer
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);

	// Clear buffer
	gtk_text_buffer_set_text(buffer, "", -1);
}

void btn_execute_on_click(GtkButton *button, gpointer user_data) {
	// Log
	printf(" [*] Event :: Button :: Clicked : Execute\n");

	// Get pointer to outview
	GtkTextView *textview = GTK_TEXT_VIEW(user_data);

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
