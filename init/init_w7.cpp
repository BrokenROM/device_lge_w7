/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#define CHUNK 2048 /* read 2048 bytes at a time */

int check_cmdline(const char param[]) {

    char buf[CHUNK];
    FILE *file;
    size_t nread;
    file = fopen("/proc/cmdline", "r");
    if (file) {
        while ((nread = fread(buf, 1, sizeof buf, file)) > 0) {
                /* fwrite(buf, 1, nread, stdout); */
                char delims[] = " ";
                char *word = NULL;
                word = strtok(buf, delims);

                while(word != NULL) {
                        if (!strcmp(param,word)) {
                                fclose(file);
                                return 1;
                        }
                        word = strtok(NULL, delims);
                }
        }
    }
    fclose(file);
    return 0;
}

void vendor_load_properties()
{
    char devicename[PROP_VALUE_MAX];

    std::string serial = property_get("ro.boot.serialno");
    if (serial.substr(0,6) == "LGD410") {
        /* D410, D410hn */
        if (check_cmdline("model.name=LG-D410hn") == 1) {
                property_set("ro.product.device", "w7nds");
                property_set("ro.product.model", "LG-D410hn");
                property_set("ro.nfc.port", "I2C");
        } else {
                property_set("ro.product.device", "w7ds");
                property_set("ro.product.model", "LG-D410");
        }
        property_set("ro.build.description", "w7ds_global_com-user 5.0.2 LRX22G.A1423481010 15040202274a7 release-keys");
        property_set("ro.build.fingerprint", "lge/w7ds_global_com/w7ds:5.0.2/LRX22G.A1423481010/15040202274a7:user/release-keys");
        property_set("persist.multisim.config", "dsds");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("ro.telephony.ril.config", "simactivation");
    } else if (serial.substr(0,6) == "LGD405") {
        /* D405, D405n */
        if (check_cmdline("model.name=LG-D405n") == 1) {
                property_set("ro.product.model", "LG-D405n");
                property_set("ro.product.device", "w7n");
                property_set("ro.nfc.port", "I2C");
        } else {
                property_set("ro.product.model", "LG-D405");
                property_set("ro.product.device", "w7");
        }
        property_set("ro.build.description", "w7_global_com-user 5.0.2 LRX22G.A1423481010 15040202274a7 release-keys");
        property_set("ro.build.fingerprint", "lge/w7_global_com/w7ds:5.0.2/LRX22G.A1423481010/15040202274a7:user/release-keys");
        property_set("persist.radio.multisim.config", "");
        property_set("persist.multisim.config", "");
    } else if (serial.substr(0,6) == "LGD415") {
        /* D415 */
        property_set("ro.product.model", "LG-D415");
        property_set("ro.product.device", "w7");
        property_set("ro.build.description", "w7_global_com-user 5.0.2 LRX22G.A1423481010 15040202274a7 release-keys");
        property_set("ro.build.fingerprint", "lge/w7_global_com/w7ds:5.0.2/LRX22G.A1423481010/15040202274a7:user/release-keys");
        property_set("persist.radio.multisim.config", "");
        property_set("persist.multisim.config", "");
    } else {
        /* None of the above matches */
        property_set("ro.product.device", "w7");
        property_set("ro.product.model", "Unknown model. Please message the maintainer!");
        property_set("persist.radio.multisim.config", "");
        property_set("persist.multisim.config", "");
    }

    std::string device = property_get("ro.product.device");
    strlcpy(devicename, device.c_str(), sizeof(devicename));
    ERROR("Found hardware id: %s setting build properties for %s device\n", serial.c_str(), devicename);
}
