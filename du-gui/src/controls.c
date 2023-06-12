#include "controls.h"
#include "execute.h"


/* REFERENCES */

GtkTextView *outview;
GtkButton *btn_clear;
GtkButton *btn_execute;
GtkToggleButton *chb_incf;
GtkToggleButton *chb_stsz;
GtkToggleButton *chb_foll;
GtkToggleButton *chb_couh;
GtkToggleButton *chb_sepd;
GtkToggleButton *chb_sofs;


void _get_command_flags(char* flags) {
	// Checkboxes
	gboolean state = FALSE;
	GtkToggleButton *chb_array[] = {chb_incf, chb_stsz, chb_foll, chb_couh, chb_sepd, chb_sofs};
	char *flags_array[] = {FLAG_INCF, FLAG_STSZ, FLAG_FOLL, FLAG_COUH, FLAG_SEPD, FLAG_SOFS};

	for(int i = 0; i < 6; i++) {
		state = gtk_toggle_button_get_active(chb_array[i]);
		if(state) {
			sprintf(flags, "%s%s ", flags, flags_array[i]);
		}
	}

	// Radioboxes


}


void controls_init(GtkBuilder *builder)
{
	// Output textview
	outview = GTK_TEXT_VIEW(gtk_builder_get_object(builder, OUTPUT_VIEW_NAME));
	
	// Buttons
	btn_clear = GTK_BUTTON(gtk_builder_get_object(builder, BUTTON_CLR_NAME));
	btn_execute = GTK_BUTTON(gtk_builder_get_object(builder, BUTTON_EXE_NAME));

	// Checkboxes
	chb_incf = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_INCF_NAME));
	chb_stsz = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_STSZ_NAME));
	chb_foll = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_FOLL_NAME));
	chb_couh = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_COUH_NAME));
	chb_sepd = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_SEPD_NAME));
	chb_sofs = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, CHECKBOX_SOFS_NAME));

	// Radioboxes
	// TODO: declare and init
	
	// Combobox
	// TODO: declare and init

	// Choose dir button
	// TODO: declare and init
}

void btn_clear_on_click(GtkButton *button, gpointer user_data)
{
	// Get pointer to outview
	GtkTextView *textview = GTK_TEXT_VIEW(user_data);

	// Get textview text buffer
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);

	// Clear buffer
	gtk_text_buffer_set_text(buffer, "", -1);
}

void btn_execute_on_click(GtkButton *button, gpointer user_data)
{
	// Get pointer to outview
	GtkTextView *textview = GTK_TEXT_VIEW(user_data);

	// Get textview text buffer
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);

	// Create iterator at the end of text
	GtkTextIter end;
	gtk_text_buffer_get_end_iter(buffer, &end);

	// Get command flags
	char* flags = (char*) malloc(128 * sizeof(char));
	memset(flags, 0, 128);
	_get_command_flags(flags);

	// Execute command and get output
	// TODO: implement
	char *out = (char *)malloc(256 * sizeof(char));
	memset(out, 0, 256);
	sprintf(out, "du %s", flags);

	// Add output to buffer
	gtk_text_buffer_insert(buffer, &end, flags, -1);

	// Memory free
	free(flags);
}
