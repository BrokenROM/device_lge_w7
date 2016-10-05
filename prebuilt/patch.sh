#!/bin/sh
echo "*** Patching ***"
mkdir out
mkdir out/host
mkdir out/host/linux-x86
mkdir out/host/linux-x86/bin
cp device/lge/w7/prebuilt/mkyaffs2image* out/host/linux-x86/bin/mkyaffs2image
echo "*** Done! ***"
echo "*** do mka otatools before building for w7 ***"