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

typedef struct RTC_Context
{
} RTC_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static RTC_Status_t RTC_Context_Initialize( void );
static RTC_Status_t RTC_Context_Cycle( void );
static RTC_Status_t RTC_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static RTC_Context_t RTC_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static RTC_Status_t RTC_Context_Initialize( void )
{
    RTC_Status_t Status = RTC_Status_Success;

    do
    {
        RTC_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( RTC_Context );
    }
    while ( 0 );

    return Status;
}

static RTC_Status_t RTC_Context_Cycle( void )
{
    RTC_Status_t Status = RTC_Status_Success;

    do
    {
        RTC_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( RTC_Context );
    }
    while ( 0 );

    return Status;
}

static RTC_Status_t RTC_Context_DeInitialize( void )
{
    RTC_Status_t Status = RTC_Status_Success;

    do
    {
        RTC_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( RTC_Context );
    }
    while ( 0 );

    return Status;
}

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

        if ( ( Status = RTC_Context_Initialize( ) ) != RTC_Status_Success )
        {
            break;
        }

        for ( RTC_t RTC_x = RTC_Null; RTC_x < RTC_Count; ++RTC_x )
        {
            if ( RTCx != RTC_All && RTCx != RTC_x )
            {
                continue;
            }

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

        if ( ( Status = RTC_Context_Cycle( ) ) != RTC_Status_Success )
        {
            break;
        }

        for ( RTC_t RTC_x = RTC_Null; RTC_x < RTC_Count; ++RTC_x )
        {
            if ( RTCx != RTC_All && RTCx != RTC_x )
            {
                continue;
            }

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

        for ( RTC_t RTC_x = RTC_Null; RTC_x < RTC_Count; ++RTC_x )
        {
            if ( RTCx != RTC_All && RTCx != RTC_x )
            {
                continue;
            }

            if ( ( RTC_Status = RTC_Port_DeInitialize( RTC_x ) ) != RTC_Status_Success )
            {
                Status = RTC_Status;
            }
        }

        if ( ( Status = RTC_Context_DeInitialize( ) ) != RTC_Status_Success )
        {
            break;
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

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char RTC_VERSION[] = "0.0.0.v20260524-1513";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
