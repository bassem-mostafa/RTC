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
    RTC_Instance_t Instance[ RTC_Count ];
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
    RTC_Status_t Status = RTC_Status_Error;
    do
    {
        RTC_Trace( "%s( void )", __FUNCTION__ );
        for ( RTC_t RTC_x = RTC_Null; RTC_x < RTC_Count; ++RTC_x )
        {
            RTC_Context.Instance[ RTC_x ].RTCx = RTC_x;
            if ( ( Status = RTC_Instance_Initialize( &RTC_Context.Instance[ RTC_x ] ) ) != RTC_Status_Success )
            {
                RTC_Warning( "RTC_%d Initialize Failed: Status %d", RTC_x, Status );
            }
        }
        Status = RTC_Status_Success;
    }
    while ( 0 );
    return Status;
}

static RTC_Status_t RTC_Context_Cycle( void )
{
    RTC_Status_t Status = RTC_Status_Error;
    do
    {
        RTC_Trace( "%s( void )", __FUNCTION__ );
        for ( RTC_t RTC_x = RTC_Null; RTC_x < RTC_Count; ++RTC_x )
        {
            if ( ( Status = RTC_Instance_Cycle( &RTC_Context.Instance[ RTC_x ] ) ) != RTC_Status_Success )
            {
                RTC_Warning( "RTC_%d Cycle Failed: Status %d", RTC_x, Status );
            }
        }
        Status = RTC_Status_Success;
    }
    while ( 0 );
    return Status;
}

static RTC_Status_t RTC_Context_DeInitialize( void )
{
    RTC_Status_t Status = RTC_Status_Error;
    do
    {
        RTC_Trace( "%s( void )", __FUNCTION__ );
        for ( RTC_t RTC_x = RTC_Null; RTC_x < RTC_Count; ++RTC_x )
        {
            if ( ( Status = RTC_Instance_DeInitialize( &RTC_Context.Instance[ RTC_x ] ) ) != RTC_Status_Success )
            {
                RTC_Warning( "RTC_%d DeInitialize Failed: Status %d", RTC_x, Status );
            }
        }
        Status = RTC_Status_Success;
    }
    while ( 0 );
    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

RTC_Status_t RTC_Initialize( RTC_t RTCx )
{
    RTC_Status_t Status = RTC_Status_Error;
    do
    {
        RTC_Trace( "%s( void )", __FUNCTION__ );
        Status = RTC_Context_Initialize( );
    }
    while ( 0 );
    return Status;
}

RTC_Status_t RTC_Cycle( RTC_t RTCx )
{
    RTC_Status_t Status = RTC_Status_Error;
    do
    {
        RTC_Trace( "%s( void )", __FUNCTION__ );
        Status = RTC_Context_Cycle( );
    }
    while ( 0 );
    return Status;
}

RTC_Status_t RTC_DeInitialize( RTC_t RTCx )
{
    RTC_Status_t Status = RTC_Status_Error;
    do
    {
        RTC_Trace( "%s( void )", __FUNCTION__ );
        Status = RTC_Context_DeInitialize( );
    }
    while ( 0 );
    return Status;
}

RTC_Status_t RTC_Get_Timestamp( RTC_t RTCx, RTC_Timestamp_t * Timestamp )
{
    RTC_Status_t Status = RTC_Status_Error;
    do
    {
        RTC_Trace( "%s( RTC=RTC_%d, Timestamp=%p )", __FUNCTION__, RTCx, Timestamp );
        if ( Timestamp == NULL )
        {
            Status = RTC_Status_ArgumentInvalid;
            break;
        }
        if ( ( Status = RTC_IsValid( RTCx ) ) != RTC_Status_Success )
        {
            break;
        }
        RTC_Instance_t * Instance = &RTC_Context.Instance[ RTCx ];
        Status = RTC_Instance_GetTimestamp( Instance, Timestamp );
    }
    while ( 0 );
    return Status;
}

RTC_Status_t RTC_Set_Timestamp( RTC_t RTCx, RTC_Timestamp_t Timestamp )
{
    RTC_Status_t Status = RTC_Status_Error;
    do
    {
        RTC_Trace( "%s( RTC=RTC_%d, Timestamp=%p )", __FUNCTION__, RTCx, Timestamp );
        if ( ( Status = RTC_IsValid( RTCx ) ) != RTC_Status_Success )
        {
            break;
        }
        RTC_Instance_t * Instance = &RTC_Context.Instance[ RTCx ];
        Status = RTC_Instance_SetTimestamp( Instance, Timestamp );
    }
    while ( 0 );
    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char RTC_VERSION[] = "0.0.0.v20260125-0138";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
