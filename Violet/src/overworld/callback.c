#include "types.h"
#include "overworld/map_control.h"
#include "debug.h"
#include "callbacks.h"
#include "oam.h"
#include "fading.h"
#include "bg.h"

#define BENCHMARK 0
#if BENCHMARK
    #define BENCHMARK_WRAP(x) x
#else
    #define BENCHMARK_WRAP(x) ;
#endif

void overworld_proceed() {


    BENCHMARK_WRAP(benchmark_start();)
    overworld_script_proceed();
    BENCHMARK_WRAP(u32 time_ow_script = benchmark_end();)

    BENCHMARK_WRAP(benchmark_start();)
    big_callback_proceed();
    BENCHMARK_WRAP(u32 time_big_cb = benchmark_end();)

    BENCHMARK_WRAP(benchmark_start();)
    oam_animations_proceed();
    BENCHMARK_WRAP(u32 time_oam_anim = benchmark_end();)

    BENCHMARK_WRAP(benchmark_start();)
    overworld_camera_proceed();
    BENCHMARK_WRAP(u32 time_cam = benchmark_end();)
    
    // sub_8115798 is excluded, we don't care about the questlog

    BENCHMARK_WRAP(benchmark_start();)
    overworld_camera_panning_proceed();
    BENCHMARK_WRAP(u32 time_cam_pan = benchmark_end();)

    BENCHMARK_WRAP(benchmark_start();)
    oam_proceed();
    BENCHMARK_WRAP(u32 time_oam = benchmark_end();)

    BENCHMARK_WRAP(benchmark_start();)
    fading_proceed();
    BENCHMARK_WRAP(u32 time_fading = benchmark_end();)

    BENCHMARK_WRAP(benchmark_start();)
    tileset_anim_proceed();
    BENCHMARK_WRAP(u32 time_ts_anim = benchmark_end();)

    BENCHMARK_WRAP(benchmark_start();)
    bg_virtual_sync_reqeust_proceed();
    BENCHMARK_WRAP(u32 time_bg_cpy = benchmark_end();)

    BENCHMARK_WRAP(dprintf("Sum %d, owscr %d, bigcb %d, oamanim %d, cam %d, campan %d, oam %d, fade %d, tsanim %d, bgcpy %d\n",
        time_ow_script +  time_big_cb + time_oam_anim + time_cam + time_cam_pan + time_oam + time_fading + time_ts_anim + time_bg_cpy,
        time_ow_script, time_big_cb, time_oam_anim, time_cam, time_cam_pan, time_oam, time_fading, time_ts_anim, time_bg_cpy);)
}