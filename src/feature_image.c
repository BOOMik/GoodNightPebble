#include "pebble.h"

static Window *window;

static BitmapLayer *image_layer;

static GBitmap *image;

int main(void) {
  window = window_create();
  window_set_fullscreen(window, false);
  window_stack_push(window, false /* Animated */);

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  // This needs to be deinited on app exit which is when the event loop ends
  image = gbitmap_create_with_resource(RESOURCE_ID_NIGHT);

  // The bitmap layer holds the image for display
  image_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_bitmap(image_layer, image);
  bitmap_layer_set_alignment(image_layer, GAlignCenter);
  layer_add_child(window_layer, bitmap_layer_get_layer(image_layer));

  app_event_loop();

  gbitmap_destroy(image);

  bitmap_layer_destroy(image_layer);
  window_destroy(window);
}
