#define EE_HANDS

#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 120000

#define USB_SUSPEND_WAKEUP_DELAY 0

// #define TAPPING_TERM_PER_KEY
#define RGB_MATRIX_STARTUP_SPD 60
#define MASTER_LEFT  
#define RGBLED_SPLIT { 28, 28 }
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define SPLIT_LAYER_STATE_ENABLE //allows layer leds to be addressed on the second side
#define SPLIT_MODS_ENABLE //allows mods to address leds on the second side.