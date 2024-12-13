// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef RTC_INTERNAL_H_
    #define RTC_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "RTC_Port.h"
    #include "driver/STM32L496VGT6P/RTC_STM32L496VGT6P.h"
    // #include "driver/DS1307/" // TODO

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef RTC_TIM
        #define RTC_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef RTC_LOG
        #define RTC_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define RTC_NAME       "RTC"
    #define RTC_LOG_PREFIX UTIL_StringConcatenateConstant( RTC_NAME, "> " )

    #ifdef DEBUG
        #define RTC_Raw( Level, Format, ... ) LOG_Raw( RTC_LOG, Level, Format, ##__VA_ARGS__ )
        #define RTC_Trace( Format, ... )      LOG_Trace( RTC_LOG, UTIL_StringConcatenateConstant( RTC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define RTC_Debug( Format, ... )      LOG_Debug( RTC_LOG, UTIL_StringConcatenateConstant( RTC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define RTC_Info( Format, ... )       LOG_Info( RTC_LOG, UTIL_StringConcatenateConstant( RTC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define RTC_Warning( Format, ... )    LOG_Warning( RTC_LOG, UTIL_StringConcatenateConstant( RTC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define RTC_Error( Format, ... )      LOG_Error( RTC_LOG, UTIL_StringConcatenateConstant( RTC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define RTC_Fatal( Format, ... )      LOG_Fatal( RTC_LOG, UTIL_StringConcatenateConstant( RTC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define RTC_Raw( Level, Format, ... )
        #define RTC_Trace( Format, ... )
        #define RTC_Debug( Format, ... )
        #define RTC_Info( Format, ... )
        #define RTC_Warning( Format, ... )
        #define RTC_Error( Format, ... )
        #define RTC_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef struct RTC_Instance_Context_t RTC_Instance_Context_t;

    typedef struct RTC_Instance
    {
        RTC_t RTCx;

        union
        {
            RTC_Instance_Context_t * Context;
            RTC_STM32L496VGT6P_Instance_t * STM32L496VGT6P;
        };
    } RTC_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    RTC_Status_t RTC_IsValid( RTC_t RTC );

    RTC_Status_t RTC_Instance_Initialize( RTC_Instance_t * RTC_Instance );
    RTC_Status_t RTC_Instance_Cycle( RTC_Instance_t * RTC_Instance );
    RTC_Status_t RTC_Instance_DeInitialize( RTC_Instance_t * RTC_Instance );

    RTC_Status_t RTC_Instance_GetTimestamp( RTC_Instance_t * RTC_Instance, RTC_Timestamp_t * RTC_Timestamp );
    RTC_Status_t RTC_Instance_SetTimestamp( RTC_Instance_t * RTC_Instance, RTC_Timestamp_t RTC_Timestamp );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* RTC_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
