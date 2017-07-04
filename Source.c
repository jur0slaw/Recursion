#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <math.h>






int main(void) {
	ALLEGRO_DISPLAY *okno = NULL;





	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL, "ALLEGRO INIC FAIL", NULL, NULL);
	}


	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();

	okno = al_create_display(800, 500);
	if (!okno) {
		al_show_native_message_box(NULL, NULL, NULL, "ALLEGRO INIC FAIL", NULL, NULL);

	}
	if (al_show_native_message_box(okno, "czesc", "witam", "czy masz marka?", NULL, ALLEGRO_MESSAGEBOX_YES_NO))
		al_show_native_message_box(okno, "czesc", "Niestety", "przykro mi", NULL, ALLEGRO_MESSAGEBOX_WARN);

	ALLEGRO_FONT *comic = al_load_ttf_font("comic.ttf", 40, NULL);
	ALLEGRO_BITMAP *kappa = al_load_bitmap("kappa.jpg");
	ALLEGRO_KEYBOARD_STATE stan;
	al_convert_mask_to_alpha(kappa, al_map_rgb(255, 255, 255));


	int w = 200;
	int h = 300;

	al_draw_text(comic, al_map_rgb(255, 0, 255), 100, 100, 0,"asd");

	al_draw_textf(comic, al_map_rgb(255, 0, 0), 0, 0, ALLEGRO_ALIGN_LEFT, "WIELKA gsdasdasd %i  %i",w,h);

	bool flag=true;

	al_flip_display();

	double x = 1 / 24;
	int i=0;
	int j = 0;
	al_get_keyboard_state(&stan);
	while (!al_key_down(&stan,ALLEGRO_KEY_ESCAPE)) {

		if (flag) {
			i++;
		}
		else {
			i--;
		}

		al_draw_filled_rectangle(0, 100, 800, 400, al_map_rgb(255, 255, 255));
		al_draw_bitmap(kappa, 100*cos(i/100)+i/10,200 + 100*sin(i/100)+j, NULL);

		al_flip_display();

		al_clear_to_color(al_map_rgb(0, 0, 0));

		al_get_keyboard_state(&stan);

		if (al_key_down(&stan, ALLEGRO_KEY_UP)) {
			j--;
		}

		if (al_key_down(&stan, ALLEGRO_KEY_DOWN)) {
			j++;
		}

		al_rest(2*x);

		if (al_key_down(&stan, ALLEGRO_KEY_SPACE)) {
			flag = (!flag);
		}
	}

		al_uninstall_keyboard;
		al_destroy_display(okno);

		al_destroy_font(comic);



	return 0;
}

