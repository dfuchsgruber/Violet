#ifndef H_CALLBACK
#define H_CALLBACK


void nullsub();

typedef struct {
    void (*function)(u8 self);
    u8 active_state;
    u8 u1;
    u8 u2;
    u8 u3;
    u16 params [0x10];
} big_callback;

extern big_callback big_callbacks[];


/**
 * Spawns a new big callback
 * @param function Function to be invoked each frame
 * @param priority Priority of the callback (0 being lowest)
 * @return The id of the newly spawned callback
 */
u8 big_callback_new(void (*function)(u8), u8 priority);

/**
 * Deletes a big callback
 * @param callback_id The id of the callback
 */
void big_callback_delete(u8 callback_id);

/**
 * Deletes all big callbacks
 */
void big_callback_delete_all();

/**
 * Checks if a function is currently invoked by an active big callback
 * @param function Function to check if it is being invoked
 * @return Whether the function is invoked by an active big callback
 */
bool big_callback_is_active(void (*function)(u8));

/**
 * Gets the id of a big callback object that currently invokes a certain function
 * @param function Function the desired callback must invoke
 * @return The index of the big callback or 0xFF if no match
 */
u8 big_callback_get_id(void *func);

/**
 * Sets an integer value to two consecutive big callback variables
 * @param callback the callback id
 * @param var the variable id (first one)
 * @param value the value to set
 */
void big_callback_set_int(u8 callback, u8 var, int value);

/**
 * Gets an integer value from two consecutive big callback variables
 * @param callback the callback id
 * @param var the variable id (first one)
 * @return value
 */
int big_callback_get_int(u8 callback, u8 var);

/**
 * Executes all big callbacks
 */
void big_callback_proceed();

#endif
