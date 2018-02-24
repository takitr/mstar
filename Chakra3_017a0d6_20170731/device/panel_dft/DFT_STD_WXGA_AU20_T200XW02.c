//<MStar Software>
//******************************************************************************
// MStar Software
// Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
// All software, firmware and related documentation herein ("MStar Software") are
// intellectual property of MStar Semiconductor, Inc. ("MStar") and protected by
// law, including, but not limited to, copyright law and international treaties.
// Any use, modification, reproduction, retransmission, or republication of all 
// or part of MStar Software is expressly prohibited, unless prior written 
// permission has been granted by MStar. 
//
// By accessing, browsing and/or using MStar Software, you acknowledge that you
// have read, understood, and agree, to be bound by below terms ("Terms") and to
// comply with all applicable laws and regulations:
//
// 1. MStar shall retain any and all right, ownership and interest to MStar
//    Software and any modification/derivatives thereof.
//    No right, ownership, or interest to MStar Software and any
//    modification/derivatives thereof is transferred to you under Terms.
//
// 2. You understand that MStar Software might include, incorporate or be
//    supplied together with third party`s software and the use of MStar
//    Software may require additional licenses from third parties.  
//    Therefore, you hereby agree it is your sole responsibility to separately
//    obtain any and all third party right and license necessary for your use of
//    such third party`s software. 
//
// 3. MStar Software and any modification/derivatives thereof shall be deemed as
//    MStar`s confidential information and you agree to keep MStar`s 
//    confidential information in strictest confidence and not disclose to any
//    third party.  
//
// 4. MStar Software is provided on an "AS IS" basis without warranties of any
//    kind. Any warranties are hereby expressly disclaimed by MStar, including
//    without limitation, any warranties of merchantability, non-infringement of
//    intellectual property rights, fitness for a particular purpose, error free
//    and in conformity with any international standard.  You agree to waive any
//    claim against MStar for any loss, damage, cost or expense that you may
//    incur related to your use of MStar Software.
//    In no event shall MStar be liable for any direct, indirect, incidental or
//    consequential damages, including without limitation, lost of profit or
//    revenues, lost or damage of data, and unauthorized system use.
//    You agree that this Section 4 shall still apply without being affected
//    even if MStar Software has been modified by MStar in accordance with your
//    request or instruction for your use, except otherwise agreed by both
//    parties in writing.
//
// 5. If requested, MStar may from time to time provide technical supports or
//    services in relation with MStar Software to you for your use of
//    MStar Software in conjunction with your or your customer`s product
//    ("Services").
//    You understand and agree that, except otherwise agreed by both parties in
//    writing, Services are provided on an "AS IS" basis and the warranty
//    disclaimer set forth in Section 4 above shall apply.  
//
// 6. Nothing contained herein shall be construed as by implication, estoppels
//    or otherwise:
//    (a) conferring any license or right to use MStar name, trademark, service
//        mark, symbol or any other identification;
//    (b) obligating MStar or any of its affiliates to furnish any person,
//        including without limitation, you and your customers, any assistance
//        of any kind whatsoever, or any information; or 
//    (c) conferring any license or right under any intellectual property right.
//
// 7. These terms shall be governed by and construed in accordance with the laws
//    of Taiwan, R.O.C., excluding its conflict of law rules.
//    Any and all dispute arising out hereof or related hereto shall be finally
//    settled by arbitration referred to the Chinese Arbitration Association,
//    Taipei in accordance with the ROC Arbitration Law and the Arbitration
//    Rules of the Association by three (3) arbitrators appointed in accordance
//    with the said Rules.
//    The place of arbitration shall be in Taipei, Taiwan and the language shall
//    be English.  
//    The arbitration award shall be final and binding to both parties.
//
//******************************************************************************
//<MStar Software>

#if ENABLE_DLC
#if DLC_PARAMETER_ALGORITHM_MODE   //for NEW DLC ALGORITHM


#include "New_NoOS_DLC.c"

#else //for OLD DLC ALGORITHM

static MS_U8 tLumaCurve[16] =
    { 0x02, 0x0C, 0x1C, 0x2F, 0x41, 0x53, 0x65, 0x78, 0x8B, 0x9B, 0xAC, 0xBA, 0xC8, 0xD5, 0xE5, 0xF7 };

static MS_U8 tLumaCurve2_a[16] =
    { 0x02, 0x0C, 0x1A, 0x2C, 0x3E, 0x4D, 0x5D, 0x6E, 0x7E, 0x8F, 0x9E, 0xB0, 0xC0, 0xD2, 0xE3, 0xF6 };

static MS_U8 tLumaCurve2_b[16] =
    { 0x07, 0x1E, 0x33, 0x43, 0x51, 0x5F, 0x6D, 0x7B, 0x89, 0x9A, 0xA8, 0xB7, 0xC7, 0xD7, 0xE7, 0xF8 };

static MS_U8 tDlcSlopLimit[17] =
    { 0x88, 0x90, 0x93, 0x92, 0x8E, 0x89, 0x84, 0x80, 0x7E, 0x7D, 0x7E, 0x81, 0x85, 0x88, 0x8B, 0x8C, 0x8A };

#endif


#endif // #if ENABLE_DLC

#if 0
code BYTE tNormalGammaR[] =
{
    0x10,0x00,0x00,0x32,0x00,0x00,0x54,0x00,0x00,
    0x76,0x00,0x00,0x98,0x00,0x00,0xBA,0x00,0x00,
    0xDC,0x00,0x00,0xFE,0x00,0x00,0x10,0x01,0x01,
    0x32,0x01,0x01,0x54,0x01,0x01,0x76,0x01,0x01,
    0x98,0x01,0x01,0xBA,0x01,0x01,0xDC,0x01,0x01,
    0xFE,0x01,0x01,0x10,0x02,0x02,0x32,0x02,0x02,
    0x54,0x02,0x02,0x76,0x02,0x02,0x98,0x02,0x02,
    0xBA,0x02,0x02,0xDC,0x02,0x02,0xFE,0x02,0x02,
    0x10,0x03,0x03,0x32,0x03,0x03,0x54,0x03,0x03,
    0x76,0x03,0x03,0x98,0x03,0x03,0xBA,0x03,0x03,
    0xDC,0x03,0x03,0xFE,0x03,0x03,0x10,0x04,0x04,
    0x32,0x04,0x04,0x54,0x04,0x04,0x76,0x04,0x04,
    0x98,0x04,0x04,0xBA,0x04,0x04,0xDC,0x04,0x04,
    0xFE,0x04,0x04,0x10,0x05,0x05,0x32,0x05,0x05,
    0x54,0x05,0x05,0x76,0x05,0x05,0x98,0x05,0x05,
    0xBA,0x05,0x05,0xDC,0x05,0x05,0xFE,0x05,0x05,
    0x10,0x06,0x06,0x32,0x06,0x06,0x54,0x06,0x06,
    0x76,0x06,0x06,0x98,0x06,0x06,0xBA,0x06,0x06,
    0xDC,0x06,0x06,0xFE,0x06,0x06,0x10,0x07,0x07,
    0x32,0x07,0x07,0x54,0x07,0x07,0x76,0x07,0x07,
    0x98,0x07,0x07,0xBA,0x07,0x07,0xDC,0x07,0x07,
    0xFE,0x07,0x07,0x10,0x08,0x08,0x32,0x08,0x08,
    0x54,0x08,0x08,0x76,0x08,0x08,0x98,0x08,0x08,
    0xBA,0x08,0x08,0xDC,0x08,0x08,0xFE,0x08,0x08,
    0x10,0x09,0x09,0x32,0x09,0x09,0x54,0x09,0x09,
    0x76,0x09,0x09,0x98,0x09,0x09,0xBA,0x09,0x09,
    0xDC,0x09,0x09,0xFE,0x09,0x09,0x10,0x0A,0x0A,
    0x32,0x0A,0x0A,0x54,0x0A,0x0A,0x76,0x0A,0x0A,
    0x98,0x0A,0x0A,0xBA,0x0A,0x0A,0xDC,0x0A,0x0A,
    0xFE,0x0A,0x0A,0x10,0x0B,0x0B,0x32,0x0B,0x0B,
    0x54,0x0B,0x0B,0x76,0x0B,0x0B,0x98,0x0B,0x0B,
    0xBA,0x0B,0x0B,0xDC,0x0B,0x0B,0xFE,0x0B,0x0B,
    0x10,0x0C,0x0C,0x32,0x0C,0x0C,0x54,0x0C,0x0C,
    0x76,0x0C,0x0C,0x98,0x0C,0x0C,0xBA,0x0C,0x0C,
    0xDC,0x0C,0x0C,0xFE,0x0C,0x0C,0x10,0x0D,0x0D,
    0x32,0x0D,0x0D,0x54,0x0D,0x0D,0x76,0x0D,0x0D,
    0x98,0x0D,0x0D,0xBA,0x0D,0x0D,0xDC,0x0D,0x0D,
    0xFE,0x0D,0x0D,0x10,0x0E,0x0E,0x32,0x0E,0x0E,
    0x54,0x0E,0x0E,0x76,0x0E,0x0E,0x98,0x0E,0x0E,
    0xBA,0x0E,0x0E,0xDC,0x0E,0x0E,0xFE,0x0E,0x0E,
    0x10,0x0F,0x0F,0x32,0x0F,0x0F,0x54,0x0F,0x0F,
    0x76,0x0F,0x0F,0x98,0x0F,0x0F,0xBA,0x0F,0x0F,
    0xDC,0x0F,0x0F,0xFE,0x0F,0x0F,0x0F,0x3F
};

code BYTE tNormalGammaR_2[] = { NULL };

code BYTE tNormalGammaG[] =
{
    0x10,0x00,0x00,0x32,0x00,0x00,0x54,0x00,0x00,
    0x76,0x00,0x00,0x98,0x00,0x00,0xBA,0x00,0x00,
    0xDC,0x00,0x00,0xFE,0x00,0x00,0x10,0x01,0x01,
    0x32,0x01,0x01,0x54,0x01,0x01,0x76,0x01,0x01,
    0x98,0x01,0x01,0xBA,0x01,0x01,0xDC,0x01,0x01,
    0xFE,0x01,0x01,0x10,0x02,0x02,0x32,0x02,0x02,
    0x54,0x02,0x02,0x76,0x02,0x02,0x98,0x02,0x02,
    0xBA,0x02,0x02,0xDC,0x02,0x02,0xFE,0x02,0x02,
    0x10,0x03,0x03,0x32,0x03,0x03,0x54,0x03,0x03,
    0x76,0x03,0x03,0x98,0x03,0x03,0xBA,0x03,0x03,
    0xDC,0x03,0x03,0xFE,0x03,0x03,0x10,0x04,0x04,
    0x32,0x04,0x04,0x54,0x04,0x04,0x76,0x04,0x04,
    0x98,0x04,0x04,0xBA,0x04,0x04,0xDC,0x04,0x04,
    0xFE,0x04,0x04,0x10,0x05,0x05,0x32,0x05,0x05,
    0x54,0x05,0x05,0x76,0x05,0x05,0x98,0x05,0x05,
    0xBA,0x05,0x05,0xDC,0x05,0x05,0xFE,0x05,0x05,
    0x10,0x06,0x06,0x32,0x06,0x06,0x54,0x06,0x06,
    0x76,0x06,0x06,0x98,0x06,0x06,0xBA,0x06,0x06,
    0xDC,0x06,0x06,0xFE,0x06,0x06,0x10,0x07,0x07,
    0x32,0x07,0x07,0x54,0x07,0x07,0x76,0x07,0x07,
    0x98,0x07,0x07,0xBA,0x07,0x07,0xDC,0x07,0x07,
    0xFE,0x07,0x07,0x10,0x08,0x08,0x32,0x08,0x08,
    0x54,0x08,0x08,0x76,0x08,0x08,0x98,0x08,0x08,
    0xBA,0x08,0x08,0xDC,0x08,0x08,0xFE,0x08,0x08,
    0x10,0x09,0x09,0x32,0x09,0x09,0x54,0x09,0x09,
    0x76,0x09,0x09,0x98,0x09,0x09,0xBA,0x09,0x09,
    0xDC,0x09,0x09,0xFE,0x09,0x09,0x10,0x0A,0x0A,
    0x32,0x0A,0x0A,0x54,0x0A,0x0A,0x76,0x0A,0x0A,
    0x98,0x0A,0x0A,0xBA,0x0A,0x0A,0xDC,0x0A,0x0A,
    0xFE,0x0A,0x0A,0x10,0x0B,0x0B,0x32,0x0B,0x0B,
    0x54,0x0B,0x0B,0x76,0x0B,0x0B,0x98,0x0B,0x0B,
    0xBA,0x0B,0x0B,0xDC,0x0B,0x0B,0xFE,0x0B,0x0B,
    0x10,0x0C,0x0C,0x32,0x0C,0x0C,0x54,0x0C,0x0C,
    0x76,0x0C,0x0C,0x98,0x0C,0x0C,0xBA,0x0C,0x0C,
    0xDC,0x0C,0x0C,0xFE,0x0C,0x0C,0x10,0x0D,0x0D,
    0x32,0x0D,0x0D,0x54,0x0D,0x0D,0x76,0x0D,0x0D,
    0x98,0x0D,0x0D,0xBA,0x0D,0x0D,0xDC,0x0D,0x0D,
    0xFE,0x0D,0x0D,0x10,0x0E,0x0E,0x32,0x0E,0x0E,
    0x54,0x0E,0x0E,0x76,0x0E,0x0E,0x98,0x0E,0x0E,
    0xBA,0x0E,0x0E,0xDC,0x0E,0x0E,0xFE,0x0E,0x0E,
    0x10,0x0F,0x0F,0x32,0x0F,0x0F,0x54,0x0F,0x0F,
    0x76,0x0F,0x0F,0x98,0x0F,0x0F,0xBA,0x0F,0x0F,
    0xDC,0x0F,0x0F,0xFE,0x0F,0x0F,0x0F,0x3F
};

code BYTE tNormalGammaG_2[] = { NULL };

code BYTE tNormalGammaB[] =
{
    0x10,0x00,0x00,0x32,0x00,0x00,0x54,0x00,0x00,
    0x76,0x00,0x00,0x98,0x00,0x00,0xBA,0x00,0x00,
    0xDC,0x00,0x00,0xFE,0x00,0x00,0x10,0x01,0x01,
    0x32,0x01,0x01,0x54,0x01,0x01,0x76,0x01,0x01,
    0x98,0x01,0x01,0xBA,0x01,0x01,0xDC,0x01,0x01,
    0xFE,0x01,0x01,0x10,0x02,0x02,0x32,0x02,0x02,
    0x54,0x02,0x02,0x76,0x02,0x02,0x98,0x02,0x02,
    0xBA,0x02,0x02,0xDC,0x02,0x02,0xFE,0x02,0x02,
    0x10,0x03,0x03,0x32,0x03,0x03,0x54,0x03,0x03,
    0x76,0x03,0x03,0x98,0x03,0x03,0xBA,0x03,0x03,
    0xDC,0x03,0x03,0xFE,0x03,0x03,0x10,0x04,0x04,
    0x32,0x04,0x04,0x54,0x04,0x04,0x76,0x04,0x04,
    0x98,0x04,0x04,0xBA,0x04,0x04,0xDC,0x04,0x04,
    0xFE,0x04,0x04,0x10,0x05,0x05,0x32,0x05,0x05,
    0x54,0x05,0x05,0x76,0x05,0x05,0x98,0x05,0x05,
    0xBA,0x05,0x05,0xDC,0x05,0x05,0xFE,0x05,0x05,
    0x10,0x06,0x06,0x32,0x06,0x06,0x54,0x06,0x06,
    0x76,0x06,0x06,0x98,0x06,0x06,0xBA,0x06,0x06,
    0xDC,0x06,0x06,0xFE,0x06,0x06,0x10,0x07,0x07,
    0x32,0x07,0x07,0x54,0x07,0x07,0x76,0x07,0x07,
    0x98,0x07,0x07,0xBA,0x07,0x07,0xDC,0x07,0x07,
    0xFE,0x07,0x07,0x10,0x08,0x08,0x32,0x08,0x08,
    0x54,0x08,0x08,0x76,0x08,0x08,0x98,0x08,0x08,
    0xBA,0x08,0x08,0xDC,0x08,0x08,0xFE,0x08,0x08,
    0x10,0x09,0x09,0x32,0x09,0x09,0x54,0x09,0x09,
    0x76,0x09,0x09,0x98,0x09,0x09,0xBA,0x09,0x09,
    0xDC,0x09,0x09,0xFE,0x09,0x09,0x10,0x0A,0x0A,
    0x32,0x0A,0x0A,0x54,0x0A,0x0A,0x76,0x0A,0x0A,
    0x98,0x0A,0x0A,0xBA,0x0A,0x0A,0xDC,0x0A,0x0A,
    0xFE,0x0A,0x0A,0x10,0x0B,0x0B,0x32,0x0B,0x0B,
    0x54,0x0B,0x0B,0x76,0x0B,0x0B,0x98,0x0B,0x0B,
    0xBA,0x0B,0x0B,0xDC,0x0B,0x0B,0xFE,0x0B,0x0B,
    0x10,0x0C,0x0C,0x32,0x0C,0x0C,0x54,0x0C,0x0C,
    0x76,0x0C,0x0C,0x98,0x0C,0x0C,0xBA,0x0C,0x0C,
    0xDC,0x0C,0x0C,0xFE,0x0C,0x0C,0x10,0x0D,0x0D,
    0x32,0x0D,0x0D,0x54,0x0D,0x0D,0x76,0x0D,0x0D,
    0x98,0x0D,0x0D,0xBA,0x0D,0x0D,0xDC,0x0D,0x0D,
    0xFE,0x0D,0x0D,0x10,0x0E,0x0E,0x32,0x0E,0x0E,
    0x54,0x0E,0x0E,0x76,0x0E,0x0E,0x98,0x0E,0x0E,
    0xBA,0x0E,0x0E,0xDC,0x0E,0x0E,0xFE,0x0E,0x0E,
    0x10,0x0F,0x0F,0x32,0x0F,0x0F,0x54,0x0F,0x0F,
    0x76,0x0F,0x0F,0x98,0x0F,0x0F,0xBA,0x0F,0x0F,
    0xDC,0x0F,0x0F,0xFE,0x0F,0x0F,0x0F,0x3F
};

code BYTE tNormalGammaB_2[] = { NULL };

code U16 tGammaMaxValue[] =
{

0x0FF0, 0x0FF0, 0x0FF0,

0x0FF0, 0x0FF0, 0x0FF0,
};
#define GAMMA_Mapping_OneOnOne 0

code BYTE   *tAllGammaTab[3] =
{
    tNormalGammaR,
    tNormalGammaG,
    tNormalGammaB,
};

#else
///////////////////////////////////////////////////////
// Gamma table for panel
///////////////////////////////////////////////////////
BYTE tNormalGammaR[] =
{
    0x10,0x00,0x00,0x32,0x00,0x00,0x54,0x00,0x00,
    0x76,0x00,0x00,0xA9,0x00,0x00,0xCB,0x00,0x00,
    0xED,0x00,0x00,0x0F,0x00,0x01,0x31,0x01,0x01,
    0x54,0x01,0x01,0x76,0x01,0x01,0x98,0x01,0x01,
    0xBA,0x01,0x01,0xED,0x01,0x01,0x0F,0x01,0x02,
    0x21,0x02,0x02,0x43,0x02,0x02,0x76,0x02,0x02,
    0x98,0x02,0x02,0xBA,0x02,0x02,0xDC,0x02,0x02,
    0xFE,0x02,0x02,0x10,0x03,0x03,0x32,0x03,0x03,
    0x64,0x03,0x03,0x87,0x03,0x03,0x99,0x03,0x03,
    0xBB,0x03,0x03,0xEC,0x03,0x03,0x0F,0x03,0x04,
    0x21,0x04,0x04,0x53,0x04,0x04,0x76,0x04,0x04,
    0x98,0x04,0x04,0xBA,0x04,0x04,0xDC,0x04,0x04,
    0xFE,0x04,0x04,0x10,0x05,0x05,0x21,0x05,0x05,
    0x43,0x05,0x05,0x65,0x05,0x05,0x87,0x05,0x05,
    0xA9,0x05,0x05,0xCB,0x05,0x05,0xED,0x05,0x05,
    0x0F,0x05,0x06,0x21,0x06,0x06,0x43,0x06,0x06,
    0x65,0x06,0x06,0x87,0x06,0x06,0x99,0x06,0x06,
    0xBA,0x06,0x06,0xDC,0x06,0x06,0xFE,0x06,0x06,
    0x10,0x07,0x07,0x32,0x07,0x07,0x54,0x07,0x07,
    0x76,0x07,0x07,0x87,0x07,0x07,0xA9,0x07,0x07,
    0xCB,0x07,0x07,0xED,0x07,0x07,0x0F,0x07,0x08,
    0x21,0x08,0x08,0x43,0x08,0x08,0x65,0x08,0x08,
    0x87,0x08,0x08,0xA9,0x08,0x08,0xCB,0x08,0x08,
    0xED,0x08,0x08,0x0F,0x08,0x09,0x21,0x09,0x09,
    0x43,0x09,0x09,0x65,0x09,0x09,0x87,0x09,0x09,
    0x98,0x09,0x09,0xBA,0x09,0x09,0xCC,0x09,0x09,
    0xED,0x09,0x09,0x1F,0x09,0x0A,0x32,0x0A,0x0A,
    0x54,0x0A,0x0A,0x76,0x0A,0x0A,0x98,0x0A,0x0A,
    0xBA,0x0A,0x0A,0xDC,0x0A,0x0A,0xFE,0x0A,0x0A,
    0x10,0x0B,0x0B,0x32,0x0B,0x0B,0x54,0x0B,0x0B,
    0x66,0x0B,0x0B,0x87,0x0B,0x0B,0xA9,0x0B,0x0B,
    0xCB,0x0B,0x0B,0xED,0x0B,0x0B,0x0F,0x0B,0x0C,
    0x32,0x0C,0x0C,0x54,0x0C,0x0C,0x76,0x0C,0x0C,
    0x98,0x0C,0x0C,0xBA,0x0C,0x0C,0xEC,0x0C,0x0C,
    0x0F,0x0C,0x0D,0x21,0x0D,0x0D,0x43,0x0D,0x0D,
    0x65,0x0D,0x0D,0x87,0x0D,0x0D,0xA9,0x0D,0x0D,
    0xBA,0x0D,0x0D,0xDC,0x0D,0x0D,0xEE,0x0D,0x0D,
    0x0F,0x0D,0x0E,0x21,0x0E,0x0E,0x43,0x0E,0x0E,
    0x65,0x0E,0x0E,0x87,0x0E,0x0E,0xA9,0x0E,0x0E,
    0xCB,0x0E,0x0E,0xDC,0x0E,0x0E,0xFE,0x0E,0x0E,
    0x10,0x0F,0x0F,0x32,0x0F,0x0F,0x43,0x0F,0x0F,
    0x65,0x0F,0x0F,0x87,0x0F,0x0F,0xA9,0x0F,0x0F,
    0xCB,0x0F,0x0F,0xFE,0x0F,0x0F,0x0F,0x3F
};

//BYTE tNormalGammaR_2[] = { NULL };

BYTE tNormalGammaG[] =
{
    0x10,0x00,0x00,0x32,0x00,0x00,0x54,0x00,0x00,
    0x87,0x00,0x00,0xA9,0x00,0x00,0xCB,0x00,0x00,
    0xFD,0x00,0x00,0x10,0x01,0x01,0x32,0x01,0x01,
    0x54,0x01,0x01,0x87,0x01,0x01,0xA9,0x01,0x01,
    0xCB,0x01,0x01,0xFE,0x01,0x01,0x10,0x02,0x02,
    0x32,0x02,0x02,0x64,0x02,0x02,0x87,0x02,0x02,
    0xA9,0x02,0x02,0xCB,0x02,0x02,0xFD,0x02,0x02,
    0x10,0x03,0x03,0x32,0x03,0x03,0x54,0x03,0x03,
    0x76,0x03,0x03,0x98,0x03,0x03,0xBA,0x03,0x03,
    0xED,0x03,0x03,0x0F,0x03,0x04,0x21,0x04,0x04,
    0x43,0x04,0x04,0x65,0x04,0x04,0x87,0x04,0x04,
    0xA9,0x04,0x04,0xCB,0x04,0x04,0xED,0x04,0x04,
    0x0F,0x04,0x05,0x21,0x05,0x05,0x43,0x05,0x05,
    0x76,0x05,0x05,0x98,0x05,0x05,0xA9,0x05,0x05,
    0xCB,0x05,0x05,0xED,0x05,0x05,0x0F,0x05,0x06,
    0x21,0x06,0x06,0x43,0x06,0x06,0x65,0x06,0x06,
    0x87,0x06,0x06,0xA9,0x06,0x06,0xBB,0x06,0x06,
    0xDC,0x06,0x06,0xFE,0x06,0x06,0x10,0x07,0x07,
    0x32,0x07,0x07,0x54,0x07,0x07,0x66,0x07,0x07,
    0x87,0x07,0x07,0xA9,0x07,0x07,0xCB,0x07,0x07,
    0xED,0x07,0x07,0x0F,0x07,0x08,0x21,0x08,0x08,
    0x43,0x08,0x08,0x65,0x08,0x08,0x87,0x08,0x08,
    0xA9,0x08,0x08,0xCB,0x08,0x08,0xED,0x08,0x08,
    0x0F,0x08,0x09,0x21,0x09,0x09,0x43,0x09,0x09,
    0x65,0x09,0x09,0x77,0x09,0x09,0x98,0x09,0x09,
    0xBA,0x09,0x09,0xDC,0x09,0x09,0xFE,0x09,0x09,
    0x10,0x0A,0x0A,0x32,0x0A,0x0A,0x54,0x0A,0x0A,
    0x76,0x0A,0x0A,0x98,0x0A,0x0A,0xBA,0x0A,0x0A,
    0xDC,0x0A,0x0A,0xFE,0x0A,0x0A,0x10,0x0B,0x0B,
    0x21,0x0B,0x0B,0x43,0x0B,0x0B,0x65,0x0B,0x0B,
    0x87,0x0B,0x0B,0xA9,0x0B,0x0B,0xCB,0x0B,0x0B,
    0xED,0x0B,0x0B,0x0F,0x0B,0x0C,0x21,0x0C,0x0C,
    0x43,0x0C,0x0C,0x65,0x0C,0x0C,0x87,0x0C,0x0C,
    0xA9,0x0C,0x0C,0xCB,0x0C,0x0C,0xED,0x0C,0x0C,
    0x0F,0x0C,0x0D,0x11,0x0D,0x0D,0x32,0x0D,0x0D,
    0x54,0x0D,0x0D,0x76,0x0D,0x0D,0x98,0x0D,0x0D,
    0xBA,0x0D,0x0D,0xDC,0x0D,0x0D,0xFE,0x0D,0x0D,
    0x10,0x0E,0x0E,0x21,0x0E,0x0E,0x43,0x0E,0x0E,
    0x65,0x0E,0x0E,0x87,0x0E,0x0E,0xA9,0x0E,0x0E,
    0xCB,0x0E,0x0E,0xDC,0x0E,0x0E,0xFE,0x0E,0x0E,
    0x10,0x0F,0x0F,0x32,0x0F,0x0F,0x54,0x0F,0x0F,
    0x65,0x0F,0x0F,0x87,0x0F,0x0F,0xA9,0x0F,0x0F,
    0xDB,0x0F,0x0F,0xFE,0x0F,0x0F,0x0F,0x3F
};

//BYTE tNormalGammaG_2[] = { NULL };

BYTE tNormalGammaB[] =
{
    0x10,0x00,0x00,0x32,0x00,0x00,0x54,0x00,0x00,
    0x76,0x00,0x00,0xA9,0x00,0x00,0xCB,0x00,0x00,
    0xED,0x00,0x00,0x0F,0x00,0x01,0x31,0x01,0x01,
    0x54,0x01,0x01,0x76,0x01,0x01,0x98,0x01,0x01,
    0xBA,0x01,0x01,0xED,0x01,0x01,0x0F,0x01,0x02,
    0x21,0x02,0x02,0x43,0x02,0x02,0x76,0x02,0x02,
    0x98,0x02,0x02,0xBA,0x02,0x02,0xEC,0x02,0x02,
    0x0F,0x02,0x03,0x21,0x03,0x03,0x43,0x03,0x03,
    0x65,0x03,0x03,0x87,0x03,0x03,0xA9,0x03,0x03,
    0xCB,0x03,0x03,0xED,0x03,0x03,0x1F,0x03,0x04,
    0x32,0x04,0x04,0x64,0x04,0x04,0x87,0x04,0x04,
    0xA9,0x04,0x04,0xBB,0x04,0x04,0xED,0x04,0x04,
    0x0F,0x04,0x05,0x10,0x05,0x05,0x32,0x05,0x05,
    0x54,0x05,0x05,0x76,0x05,0x05,0x98,0x05,0x05,
    0xBA,0x05,0x05,0xDC,0x05,0x05,0xFF,0x05,0x05,
    0x10,0x06,0x06,0x32,0x06,0x06,0x54,0x06,0x06,
    0x76,0x06,0x06,0x98,0x06,0x06,0xBA,0x06,0x06,
    0xDC,0x06,0x06,0xFE,0x06,0x06,0x00,0x07,0x07,
    0x21,0x07,0x07,0x43,0x07,0x07,0x65,0x07,0x07,
    0x87,0x07,0x07,0xA9,0x07,0x07,0xBB,0x07,0x07,
    0xDC,0x07,0x07,0xFE,0x07,0x07,0x10,0x08,0x08,
    0x32,0x08,0x08,0x54,0x08,0x08,0x76,0x08,0x08,
    0x98,0x08,0x08,0xBA,0x08,0x08,0xDC,0x08,0x08,
    0xFE,0x08,0x08,0x10,0x09,0x09,0x32,0x09,0x09,
    0x54,0x09,0x09,0x66,0x09,0x09,0x87,0x09,0x09,
    0xA9,0x09,0x09,0xBB,0x09,0x09,0xDC,0x09,0x09,
    0xFE,0x09,0x09,0x10,0x0A,0x0A,0x42,0x0A,0x0A,
    0x65,0x0A,0x0A,0x87,0x0A,0x0A,0xA9,0x0A,0x0A,
    0xCB,0x0A,0x0A,0xED,0x0A,0x0A,0x0F,0x0A,0x0B,
    0x10,0x0B,0x0B,0x32,0x0B,0x0B,0x54,0x0B,0x0B,
    0x76,0x0B,0x0B,0x98,0x0B,0x0B,0xBA,0x0B,0x0B,
    0xDC,0x0B,0x0B,0xFE,0x0B,0x0B,0x10,0x0C,0x0C,
    0x32,0x0C,0x0C,0x64,0x0C,0x0C,0x87,0x0C,0x0C,
    0x99,0x0C,0x0C,0xBA,0x0C,0x0C,0xDC,0x0C,0x0C,
    0x0E,0x0C,0x0D,0x21,0x0D,0x0D,0x43,0x0D,0x0D,
    0x65,0x0D,0x0D,0x87,0x0D,0x0D,0x99,0x0D,0x0D,
    0xBA,0x0D,0x0D,0xCC,0x0D,0x0D,0xED,0x0D,0x0D,
    0x0F,0x0D,0x0E,0x21,0x0E,0x0E,0x43,0x0E,0x0E,
    0x65,0x0E,0x0E,0x87,0x0E,0x0E,0x99,0x0E,0x0E,
    0xBA,0x0E,0x0E,0xDC,0x0E,0x0E,0xFE,0x0E,0x0E,
    0x10,0x0F,0x0F,0x21,0x0F,0x0F,0x43,0x0F,0x0F,
    0x65,0x0F,0x0F,0x87,0x0F,0x0F,0xA9,0x0F,0x0F,
    0xCB,0x0F,0x0F,0xFE,0x0F,0x0F,0x0F,0x3F
};

//BYTE tNormalGammaB_2[] = { NULL };

BYTE *tAllGammaTab[3] =
{
    // COLOR_TEMP_NORMAL/COLOR_TEMP_USER
    tNormalGammaR,
    tNormalGammaG,
    tNormalGammaB,
};
#endif

APIPNL_GAMMA_MAPPEING_MODE GAMMA_MAPPING_MODE   =   E_APIPNL_GAMMA_8BIT_MAPPING ;
//====================================================================================
