#include "types.h"
#include "anim_engine.h"
#include "agbmemory.h"
#include "debug.h"

/**
 * Nullsub for anim tasks (root holds nullsub)
 * @param root
 */
void anim_engine_task_nullsub(anim_engine_task *root) {
  (void)root;
}

/** Root node for the anim engine
 */
anim_engine_task anim_engine_task_root = {
    -1,
    0,
    NULL,
    NULL,
    anim_engine_task_nullsub,
    NULL
};

/**
 * Executes all anim engine tasks
 * @param head
 */
void anim_engine_tasks_execute(anim_engine_task *root){
    while(root){
        //DEBUG("Executing anim engine task @%x with func = %x\n", root, root->callback);
        anim_engine_task *next = root->next;
        root->callback(root);
        root = next;
    }
}
/**
 * Removes an anim engine task
 * You must never remove the root task
 * @param self
 * @return -1 if attempted to delete root, 0 otherwise
 */
int anim_engine_task_delete(anim_engine_task *self){
    if(self->prev == NULL) return -1;
    self->prev->next = self->next;
    self->next->prev = self->prev;
    free(self);
    //Free on var space not necessary as it is consecutive and connected
    //heap block with self
    return 0;
}

/**
 * Removes all anim tasks except the root node
 * @param root
 */
void anim_engine_task_delete_all(anim_engine_task *root){
    while(root->next){ // Never drop the root callback
        DEBUG("Deleting task %x\n", root->next->callback);
        anim_engine_task_delete(root->next);
    }
}

/**
 * Creates new anim task with given priority
 * @param priority priority of new task. Will be executed after all tasks of
 * same priority
 * @param callback the callback function
 * @param size_var_space size of allocated memory for variables
 * if 0 is passed no memory will be allocated
 * @param root root task
 * @return NULL on failure (not enough consecutive memory or no availible), pointer to task
 * structure else
 */
anim_engine_task *anim_engine_task_new(int priority, void (*callback)(anim_engine_task*), size_t size_var_space, anim_engine_task *root){
    int id = anim_engine_task_next_id(root);
    if(id < 0) return NULL;
    anim_engine_task *next = root->next;
    while(next && next->priority <= priority){
        root = next;
        next = next->next;
    }
    //Insert between root (root->priority <= priority) and next (either NULL or next->priority > priority)
    //DEBUG("New task inserted between prev @%x, next @%x\n", root, next);
    anim_engine_task *t = malloc_and_clear(sizeof(anim_engine_task));
    if(!t) 
        return NULL;
    if (size_var_space)
        t->vars = malloc_and_clear(size_var_space);
    t->priority = priority;
    t->callback = callback;
    t->id = id;
    t->prev = root;
    t->next = next;
    root->next = t;
    next->prev = t;
    return t;
}


/**
 * Sets up the anim engine root task
 * @return the root task
 */
anim_engine_task *anim_engine_task_setup(){
    anim_engine_task *t = malloc(sizeof(anim_engine_task));
    memcpy(t, &anim_engine_task_root, sizeof(anim_engine_task));
    return t;
}

/**
 * Frees all tasks and the root element (engine must re reinitialized)
 * @param root
 */
void anim_engine_task_tear_down(anim_engine_task *root){
    anim_engine_task_delete_all(root);
    free(root);
}
/**
 * Returns next availible task id
 * Each id is only assigned once during lifetime of engine
 * meaning they are not recycled after deletion
 * @param root
 * @return next free task id -1 if no task id availible
 */
int anim_engine_task_next_id(anim_engine_task *root){
    int id = -1;
    while(root){
        if(root->id > id) id = root->id;
        root = root->next;
    }
    if(id == -1 || id > 0xFFFF) return -1;
    return id + 1;
}

/**
 * Returns an anim engine task by its id
 * @param root
 * @param id
 * @return pointer to the task struct or NULL if id is not present
 */
anim_engine_task *anim_engine_task_get_by_id(anim_engine_task *root, int id){
    while(root){
        if(root->id == id) return root;
        root = root->next;
    }
    return NULL;
}
