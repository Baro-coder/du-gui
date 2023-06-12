#include "app.h"
#include "controls.h"
#include "execute.h"

GtkWidget *create_window(void)
{
	GtkWidget * window;
	GtkBuilder *builder;
	GError *error = NULL;

	// Builder constructor
	builder = gtk_builder_new();

	// UI File load
	if (!gtk_builder_add_from_file(builder, UI_FILE, &error))
	{
		g_warning("Unable to load builder file: %s", error->message);
		g_error_free(error);
	}

	// Controls references
	controls_init(builder);

	// Signals
	g_signal_connect(btn_clear, "clicked", G_CALLBACK(btn_clear_on_click), outview);
	g_signal_connect(btn_execute, "clicked", G_CALLBACK(btn_execute_on_click), outview);

	// Main window
	window = GTK_WIDGET(gtk_builder_get_object(builder, MAIN_WINDOW_NAME));

	// Memory free
	g_object_unref(builder);

	return window;
}


/* Main Drive */
int main(int argc, char *argv[])
{
	// Initializing GTK components
	gtk_init(&argc, &argv);

	// Creating app main window
	GtkWidget *window;
	window = create_window();

	// Show interface
	gtk_widget_show_all(window);

	// GTK main loop
	gtk_main();

	return 0;
}
