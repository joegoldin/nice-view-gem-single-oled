#if !defined(CONFIG_ZMK_SPLIT) || defined(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
#include "widgets/screen.h"
#else
#include "widgets/screen_peripheral.h"
#endif

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include "assets/pixel_operator_mono.c"
#include "assets/custom_fonts.h"

#if IS_ENABLED(CONFIG_NICE_VIEW_WIDGET_STATUS)
#if !defined(CONFIG_ZMK_SPLIT) || defined(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
static struct zmk_widget_screen screen_widget;
#else
static struct zmk_widget_screen_peripheral screen_widget;
#endif
#endif

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;
    screen = lv_obj_create(NULL);

#if IS_ENABLED(CONFIG_NICE_VIEW_WIDGET_STATUS)
#if !defined(CONFIG_ZMK_SPLIT) || defined(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    zmk_widget_screen_init(&screen_widget, screen);
    lv_obj_align(zmk_widget_screen_obj(&screen_widget), LV_ALIGN_TOP_LEFT, 0, 0);
#else
    zmk_widget_screen_peripheral_init(&screen_widget, screen);
    lv_obj_align(zmk_widget_screen_peripheral_obj(&screen_widget), LV_ALIGN_TOP_LEFT, 0, 0);
#endif
#endif

    return screen;
}
