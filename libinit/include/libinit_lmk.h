/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef LIBINIT_LMK_H
#define LIBINIT_LMK_H

#include <string>

typedef struct lmk_info {
    std::string psi_partial_stall_ms;
    std::string psi_complete_stall_ms;
    std::string thrashing_limit;
    std::string thrashing_limit_decay;
    std::string swap_util_max;
} lmk_info_t;

void set_lmk(void);

#endif // LIBINIT_LMK_H
