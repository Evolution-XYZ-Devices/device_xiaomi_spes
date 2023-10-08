echo 'Cloning sepolicy_vndr-legacy-um'
rm -rf device/qcom/sepolicy_vndr-legacy-um
git clone --depth=1 https://github.com/etylix/device_qcom_sepolicy_vndr-legacy-um device/qcom/sepolicy_vndr-legacy-um

echo 'Cloning clang-r450784e'
git clone https://gitlab.com/ThankYouMario/android_prebuilts_clang-standalone --depth=1 -b 14 prebuilts/clang/host/linux-x86/clang-r450784e

echo 'Removing Pixel kernel headers'
rm -rf hardware/google/pixel/kernel_headers/