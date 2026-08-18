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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "RTC.h"
#include "RTC_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

RTC_Status_t RTC_Initialize( RTC_t RTCx )
{
    RTC_Status_t Status = RTC_Status_Success;
    RTC_Status_t RTC_Status = RTC_Status_Success;

    do
    {
        RTC_Trace( "%s( RTCx=%d )", __FUNCTION__, RTCx );

        RTC_t RTC_start = ( RTCx == RTC_All ? RTC_Null : RTCx );
        RTC_t RTC_end = ( RTCx == RTC_All ? RTC_Count : RTCx + 1 );
        for ( RTC_t RTC_x = RTC_start; RTC_x < RTC_end; ++RTC_x )
        {
            if ( ( RTC_Status = RTC_Port_Initialize( RTC_x ) ) != RTC_Status_Success )
            {
                Status = RTC_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

RTC_Status_t RTC_Cycle( RTC_t RTCx )
{
    RTC_Status_t Status = RTC_Status_Success;
    RTC_Status_t RTC_Status = RTC_Status_Success;

    do
    {
        RTC_Trace( "%s( RTCx=%d )", __FUNCTION__, RTCx );

        RTC_t RTC_start = ( RTCx == RTC_All ? RTC_Null : RTCx );
        RTC_t RTC_end = ( RTCx == RTC_All ? RTC_Count : RTCx + 1 );
        for ( RTC_t RTC_x = RTC_start; RTC_x < RTC_end; ++RTC_x )
        {
            if ( ( RTC_Status = RTC_Port_Cycle( RTC_x ) ) != RTC_Status_Success )
            {
                Status = RTC_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

RTC_Status_t RTC_DeInitialize( RTC_t RTCx )
{
    RTC_Status_t Status = RTC_Status_Success;
    RTC_Status_t RTC_Status = RTC_Status_Success;

    do
    {
        RTC_Trace( "%s( RTCx=%d )", __FUNCTION__, RTCx );

        RTC_t RTC_start = ( RTCx == RTC_All ? RTC_Null : RTCx );
        RTC_t RTC_end = ( RTCx == RTC_All ? RTC_Count : RTCx + 1 );
        for ( RTC_t RTC_x = RTC_start; RTC_x < RTC_end; ++RTC_x )
        {
            if ( ( RTC_Status = RTC_Port_DeInitialize( RTC_x ) ) != RTC_Status_Success )
            {
                Status = RTC_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

RTC_Status_t RTC_Get_Timestamp( RTC_t RTCx, RTC_Timestamp_t * Timestamp )
{
    RTC_Status_t Status = RTC_Status_Success;

    do
    {
        RTC_Trace( "%s( RTCx=%d, Timestamp=%p )", __FUNCTION__, RTCx, Timestamp );

        if ( Timestamp == NULL )
        {
            Status = RTC_Status_ArgumentInvalid;
            break;
        }

        Status = RTC_Port_GetTimestamp( RTCx, Timestamp );
    }
    while ( 0 );

    return Status;
}

RTC_Status_t RTC_Set_Timestamp( RTC_t RTCx, RTC_Timestamp_t Timestamp )
{
    RTC_Status_t Status = RTC_Status_Success;

    do
    {
        RTC_Trace( "%s( RTCx=%d, Timestamp={Weekday=%d, Year=%d, Month=%d, Day=%d, Hour=%d, Minute=%d, Second=%d, Millisecond=%d, Microsecond=%d} )", __FUNCTION__, RTCx, Timestamp.Weekday, Timestamp.Year, Timestamp.Month, Timestamp.Day, Timestamp.Hour, Timestamp.Minute, Timestamp.Second, Timestamp.Millisecond, Timestamp.Microsecond );

        Status = RTC_Port_SetTimestamp( RTCx, Timestamp );
    }
    while ( 0 );

    return Status;
}

RTC_Status_t RTC_Set_TimestampAlarm( RTC_t RTCx, RTC_Timestamp_t Timestamp )
{
    RTC_Status_t Status = RTC_Status_Success;

    do
    {
        RTC_Trace( "%s( RTCx=%d, Timestamp={Weekday=%d, Year=%d, Month=%d, Day=%d, Hour=%d, Minute=%d, Second=%d, Millisecond=%d, Microsecond=%d} )", __FUNCTION__, RTCx, Timestamp.Weekday, Timestamp.Year, Timestamp.Month, Timestamp.Day, Timestamp.Hour, Timestamp.Minute, Timestamp.Second, Timestamp.Millisecond, Timestamp.Microsecond );

        Status = RTC_Port_SetTimestampAlarm( RTCx, Timestamp );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char RTC_VERSION[] = "0.0.0.v20260818-0345";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
