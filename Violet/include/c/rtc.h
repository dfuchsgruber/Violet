

#ifndef RTC
#define RTC


// Define how many seconds one inamge second is equivalent to
#define INGAME_CLOCK_SPEED_UP 6

typedef struct rtc_timestamp {
    u8 year;
    u8 month;
    u8 day;
    u8 day_of_week;
    u8 hour;
    u8 minute;
    u8 second;
} rtc_timestamp;

/**
 * Resets temporary flags that correspond to the current a-vector state
 */
void one_day_events_reset();

typedef struct gpio {
    u16 data;
    u16 pinDirection;
    bool portControl;
} gpio;

u8 ingame_clock_status;

void rtc_read(rtc_timestamp *s);
void rtc_send_byte(u8 byte);
void gpio_set_data(bool sck, bool sio, bool cs);
u8 rtc_read_byte();
u16 special_time_get();
void rtc_chip_wait();
u64 rtc_timestamp_to_seconds(rtc_timestamp *t);
/**
 * Initializes year, month and day of a timestamp with a certain amount of days that has passed.
 * @param days how many days have passed
 * @param t the timestamp to initialize
 **/
void days_to_rtc_timestamp(int days, rtc_timestamp *t);

bool rtc_test();

/**
 * Tests if the built-in time system is currently working.
 * @return if the built-in time system is working
 */
bool time_test();

/**
 * Gets the current game time (either rtc or built-in frame counter.)
 * @param s target timestamp to return the time at
 */
void time_read(rtc_timestamp *s);

/**
 * Gets the current game time from the ingame clock.
 * @param s target timestamp to return the time at
 */
void time_ingame_clock_read(rtc_timestamp *s);

/**
 * Resets all time based events.
 */
void time_reset_events();

/**
 * Tries to proceed time based events
 * @param vars space for local variables of the time based events (e.g. the ambient cry)
 **/
void time_based_events_proceed(u16 *vars);

gpio gpios;

#endif
