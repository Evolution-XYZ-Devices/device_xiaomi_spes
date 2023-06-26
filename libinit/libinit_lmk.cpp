/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <sys/sysinfo.h>
#include <libinit_utils.h>

#include <libinit_lmk.h>

#define PARTIAL_STALL_MS_PROP "ro.lmk.psi_partial_stall_ms"
#define COMPLETE_STALL_MS_PROP "ro.lmk.psi_complete_stall_ms"
#define THRASHING_LIMIT_PROP "ro.lmk.thrashing_limit"
#define THRASHING_LIMIT_DECAY_PROP "ro.lmk.thrashing_limit_decay"
#define SWAP_UTIL_MAX_PROP "ro.lmk.swap_util_max"

#define GB(b) (b * 1024ull * 1024 * 1024)

// 6GB/8GB variant
static const lmk_info_t lmk_6144 = {
    .psi_partial_stall_ms = "70",
    .psi_complete_stall_ms = "700",
    .thrashing_limit = "100",
    .thrashing_limit_decay = "10",
    .swap_util_max = "90",
};

// 4GB (mostly low ram) variant
static const lmk_info_t lmk_4096 = {
    .psi_partial_stall_ms = "130",
    .psi_complete_stall_ms = "600",
    .thrashing_limit = "55",
    .thrashing_limit_decay = "37",
    .swap_util_max = "90",
};

void set_lmk() {
    struct sysinfo sys;
    const lmk_info_t *lmk_values;

    sysinfo(&sys);

    if (sys.totalram > GB(5))
        lmk_values = &lmk_6144;
    else
        lmk_values = &lmk_4096;

    property_override(PARTIAL_STALL_MS_PROP, lmk_values->psi_partial_stall_ms);
    property_override(COMPLETE_STALL_MS_PROP, lmk_values->psi_complete_stall_ms);
    property_override(THRASHING_LIMIT_PROP, lmk_values->thrashing_limit);
    property_override(THRASHING_LIMIT_DECAY_PROP, lmk_values->thrashing_limit_decay);
    property_override(SWAP_UTIL_MAX_PROP, lmk_values->swap_util_max);
}
