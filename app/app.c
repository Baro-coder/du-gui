#include "app.h"
#include "controls.h"
#include "execute.h"

GtkWidget *window;
GtkBuilder *builder;


void create_window(void)
{
	GError *error = NULL;

	// Builder constructor
	builder = gtk_builder_new();

	// UI File load
	printf("   [+] GTK :: UI File :: load : ...\n");
	if (!gtk_builder_add_from_file(builder, UI_FILE, &error))
	{
		printf("   [!] GTK :: UI File :: load : Error : Unable to load builder file (%s) :: error message : %s\n", UI_FILE, error->message);
		g_error_free(error);
		window = NULL;
		return;
	}
	printf("   [+] GTK :: UI File :: load : Done.\n");

	// Controls references
	printf("   [+] GTK :: Controls :: init : ...\n");
	controls_init(builder);
	printf("   [+] GTK :: Controls :: init : Done.\n");

	// Main window
	window = GTK_WIDGET(gtk_builder_get_object(builder, MAIN_WINDOW_NAME));

	// Signals
	printf("   [+] GTK :: Signals :: connect : ");
	g_signal_connect(mitem_guide, "activate", G_CALLBACK(on_menu_item_guide_activate), NULL);
	g_signal_connect(mitem_about, "activate", G_CALLBACK(on_menu_item_about_activate), NULL);
	g_signal_connect(btn_clear, "clicked", G_CALLBACK(btn_clear_on_click), outview);
	g_signal_connect(btn_execute, "clicked", G_CALLBACK(btn_execute_on_click), outview);
	g_signal_connect(rad_def, "toggled", G_CALLBACK(radio_toogle), NULL);
	g_signal_connect(rad_byt, "toggled", G_CALLBACK(radio_toogle), NULL);
	g_signal_connect(rad_kib, "toggled", G_CALLBACK(radio_toogle), NULL);
	g_signal_connect(rad_mib, "toggled", G_CALLBACK(radio_toogle), NULL);
	g_signal_connect(rad_gib, "toggled", G_CALLBACK(radio_toogle), NULL);
	g_signal_connect(combo_pattern, "changed", G_CALLBACK(on_combobox_changed), NULL);
	g_signal_connect(dir_chooser_btn, "file-set", G_CALLBACK(on_dir_chooser_btn_file_set), NULL);
	g_signal_connect(window, "destroy", G_CALLBACK(on_main_destroy), NULL);
	printf("Done.\n");

	// Memory free
	g_object_unref(builder);
}


/* Main Drive */
int main(int argc, char *argv[])
{
	// Initializing GTK components
	printf(" [*] GTK :: init : ");
	gtk_init(&argc, &argv);
	printf("Done.\n");

	// Creating app main window
	printf(" [*] GTK :: Main Window : init : ...\n");
	create_window();
	if (window == NULL) {
		exit(1);
	}
	printf(" [*] GTK :: Main Window : init : Done.\n");

	// Show interface
	printf(" [*] GTK :: Interface : building : ");
	gtk_widget_show_all(window);
	printf("Done.\n");

	// GTK main loop
	printf(" [*] GTK :: Main loop : start\n");
	gtk_main();

	printf(" [*] GTK :: Main loop : end\n");
	exit(0);
}
