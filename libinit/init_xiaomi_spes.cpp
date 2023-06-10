/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>
#include <libinit_utils.h>

#include "vendor_init.h"

static const variant_info_t spes_info = {
    .hwc_value = "Global",
    .sku_value = "",

    .brand = "Redmi",
    .device = "spes",
    .model = "2201117TG",
    .build_fingerprint = "Redmi/spes_global/spes:11/RKQ1.211001.001/V13.0.15.0.RGCMIXM:user/release-keys",

    .nfc = false,
};

static const variant_info_t spes_in_info = {
    .hwc_value = "India",
    .sku_value = "",

    .brand = "Redmi",
    .device = "spes",
    .model = "2201117TI",
    .build_fingerprint = "Redmi/spes_in/spes:11/RKQ1.211001.001/V13.0.10.0.RGCINXM:user/release-keys",

    .nfc = false,
};

static const variant_info_t spesn_info = {
    .hwc_value = "",
    .sku_value = "k7tn",

    .brand = "Redmi",
    .device = "spesn",
    .model = "2201117TY",
    .build_fingerprint = "Redmi/spesn_global/spesn:11/RKQ1.211001.001/V13.0.11.0.RGCMIXM:user/release-keys",

    .nfc = true,
};

static const std::vector<variant_info_t> variants = {
    spes_info,
    spes_in_info,
    spesn_info,
};

void vendor_load_properties() {
    search_variant(variants);
    set_dalvik_heap();

    // SafetyNet workaround
    property_override("ro.boot.verifiedbootstate", "green");
    property_override("ro.oem_unlock_supported", "0");
}
