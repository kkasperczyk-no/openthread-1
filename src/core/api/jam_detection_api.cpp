/*
 *  Copyright (c) 2016, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *   This file implements the OpenThread Jam Detection API.
 */

#include "openthread-core-config.h"

#include <openthread/jam_detection.h>

#include "common/instance.hpp"
#include "common/locator-getters.hpp"

using namespace ot;

#if OPENTHREAD_ENABLE_JAM_DETECTION

otError otJamDetectionSetRssiThreshold(otInstance *aInstance, int8_t aRssiThreshold)
{
    Instance &instance = *static_cast<Instance *>(aInstance);

    instance.Get<Utils::JamDetector>().SetRssiThreshold(aRssiThreshold);

    return OT_ERROR_NONE;
}

int8_t otJamDetectionGetRssiThreshold(otInstance *aInstance)
{
    Instance &instance = *static_cast<Instance *>(aInstance);

    return instance.Get<Utils::JamDetector>().GetRssiThreshold();
}

otError otJamDetectionSetWindow(otInstance *aInstance, uint8_t aWindow)
{
    Instance &instance = *static_cast<Instance *>(aInstance);

    return instance.Get<Utils::JamDetector>().SetWindow(aWindow);
}

uint8_t otJamDetectionGetWindow(otInstance *aInstance)
{
    Instance &instance = *static_cast<Instance *>(aInstance);

    return instance.Get<Utils::JamDetector>().GetWindow();
}

otError otJamDetectionSetBusyPeriod(otInstance *aInstance, uint8_t aBusyPeriod)
{
    Instance &instance = *static_cast<Instance *>(aInstance);

    return instance.Get<Utils::JamDetector>().SetBusyPeriod(aBusyPeriod);
}

uint8_t otJamDetectionGetBusyPeriod(otInstance *aInstance)
{
    Instance &instance = *static_cast<Instance *>(aInstance);

    return instance.Get<Utils::JamDetector>().GetBusyPeriod();
}

otError otJamDetectionStart(otInstance *aInstance, otJamDetectionCallback aCallback, void *aContext)
{
    Instance &instance = *static_cast<Instance *>(aInstance);

    return instance.Get<Utils::JamDetector>().Start(aCallback, aContext);
}

otError otJamDetectionStop(otInstance *aInstance)
{
    Instance &instance = *static_cast<Instance *>(aInstance);

    return instance.Get<Utils::JamDetector>().Stop();
}

bool otJamDetectionIsEnabled(otInstance *aInstance)
{
    Instance &instance = *static_cast<Instance *>(aInstance);

    return instance.Get<Utils::JamDetector>().IsEnabled();
}

bool otJamDetectionGetState(otInstance *aInstance)
{
    Instance &instance = *static_cast<Instance *>(aInstance);

    return instance.Get<Utils::JamDetector>().GetState();
}

uint64_t otJamDetectionGetHistoryBitmap(otInstance *aInstance)
{
    Instance &instance = *static_cast<Instance *>(aInstance);

    return instance.Get<Utils::JamDetector>().GetHistoryBitmap();
}

#endif // OPENTHREAD_ENABLE_JAM_DETECTION
