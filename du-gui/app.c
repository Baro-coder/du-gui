#include "app.h"
#include "controls.h"
#include "execute.h"


GtkWidget *create_window(void)
{
	GtkWidget *window;
	GtkBuilder *builder;
	GError *error = NULL;

	builder = gtk_builder_new();

	if (!gtk_builder_add_from_file(builder, UI_FILE, &error))
	{
		g_warning("Unable to load builder file: %s", error->message);
		g_error_free(error);
	}

	gtk_builder_connect_signals(builder, NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, MAIN_WINDOW_NAME));

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
	gtk_widget_show(window);

	// GTK main loop
	gtk_main();

	return 0;
}
