int entry(int argc, char **argv) {

	window.title = fixed_string("JAKES GAME");
	window.width = 1280;
	window.height = 720;
	window.x = 200;
	window.y = 200;
	window.clear_color = hex_to_rgba(0x2a2d3aff);

	while(!window.should_close) {
		reset_temporary_storage();
		os_update();

		if(is_key_just_pressed(KEY_ESCAPE)) { 
			window.should_close = true;
		}

		float64 now = os_get_elapsed_seconds();
		Matrix4 rect_xform = m4_scalar(1.0);
		rect_xform         = m4_rotate_z(rect_xform, (f32)now);
		rect_xform         = m4_translate(rect_xform, v3(-125, -125, 0));
		draw_rect_xform(rect_xform, v2(250, 250), COLOR_GREEN);
		
		draw_rect(v2(sin(now)*window.width*0.4-60, -60), v2(120, 120), COLOR_RED);
		
		gfx_update();
	}
	
	// // This is how we (optionally) configure the window.
	// // To see all the settable window properties, ctrl+f "struct Os_Window" in os_interface.c
	// window.title = STR("JAKES SIC AS MF GAME NIGGAAAA");
	
	// while (!window.should_close) {
	// 	reset_temporary_storage();

	// 	if(is_key_just_pressed(KEY_ESCAPE)) {
	// 		window.should_close = true;
	// 	}
		
	// 	float64 now = os_get_elapsed_seconds();
		
	// 	Matrix4 rect_xform = m4_scalar(1.0);
	// 	rect_xform         = m4_rotate_z(rect_xform, (f32)now);
	// 	rect_xform         = m4_translate(rect_xform, v3(-125, -125, 0));
	// 	draw_rect_xform(rect_xform, v2(250, 250), COLOR_GREEN);
		
	// 	draw_rect(v2(sin(now)*window.width*0.4-60, -60), v2(120, 120), COLOR_RED);
		
	// 	os_update(); 
	// 	gfx_update();
	// }

	return 0;

	

}