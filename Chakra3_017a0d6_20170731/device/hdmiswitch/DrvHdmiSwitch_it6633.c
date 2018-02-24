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
#define IT6633_C

#define _IT6633_C_

// C Library
#include <string.h>
#include <stdio.h>

#if (INPUT_HDMI_VIDEO_COUNT>0)
#include "datatype.h"
#include "drvIIC.h"
#include "DrvHdmiSwitch_Ps321.h"

#define PSDBG(x) //x

U8 code EDIDDATA[256]=
{
#if 0
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x42, 0x49, 0x70, 0x06, 0x01, 0x00, 0x00, 0x00,
    0x07, 0x11, 0x01, 0x03, 0x81, 0x46, 0x27, 0x78, 0x0A, 0xDE, 0x58, 0xA3, 0x54, 0x4C, 0x99, 0x26,
    0x0F, 0x45, 0x47, 0xBF, 0x01, 0x1D, 0x80, 0x18, 0x71, 0x1C, 0x16, 0x20, 0x58, 0x2C, 0x25, 0x00,
    0xC4, 0x8E, 0x21, 0x00, 0x00, 0x9E, 0x01, 0x1D, 0x80, 0x18, 0x71, 0x1C, 0x16, 0x20, 0x58, 0x2C,
    0x25, 0x00, 0xC4, 0x8E, 0x21, 0x00, 0x00, 0x9E, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10,
    0x10, 0x3E, 0x96, 0x00, 0x13, 0x8E, 0x21, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x50,
    0x52, 0x49, 0x20, 0x48, 0x44, 0x4D, 0x49, 0x20, 0x54, 0x56, 0x0A, 0x20, 0x00, 0x00, 0x00, 0xFD,
    0x00, 0x30, 0x56, 0x0F, 0x41, 0x09, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0xD1,
    0x02, 0x03, 0x28, 0x71, 0x48, 0x01, 0x02, 0x03, 0x04, 0x85, 0x06, 0x07, 0x10, 0x26, 0x09, 0x07,
    0x07, 0x15, 0x07, 0x50, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10, 0x10, 0x3E, 0x96, 0x00,
    0xC4, 0x66, 0x03, 0x0C, 0x00, 0x10, 0x00, 0x80, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10,
    0x10, 0x3E, 0x96, 0x00, 0xC4, 0x8E, 0x21, 0x00, 0x00, 0x18, 0x01, 0x1D, 0x00, 0x72, 0x51, 0xD0,
    0x1E, 0x20, 0x6E, 0x28, 0x55, 0x00, 0xC4, 0x8E, 0x21, 0x00, 0x00, 0x1E, 0x8C, 0x0A, 0xA0, 0x14,
    0x51, 0xF0, 0x16, 0x00, 0x26, 0x7C, 0x43, 0x00, 0x13, 0x8E, 0x21, 0x00, 0x00, 0x98, 0x8C, 0x0A,
    0xA0, 0x14, 0x51, 0xF0, 0x16, 0x00, 0x26, 0x7C, 0x43, 0x00, 0xC4, 0x8E, 0x21, 0x00, 0x00, 0x98,
    0xD6, 0x09, 0x80, 0xA0, 0x20, 0xE0, 0x2D, 0x10, 0x08, 0x60, 0x22, 0x00, 0x12, 0x8E, 0x21, 0xEC,

#elif 1  // CUS_X HAxxx EDID
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x42, 0x49, 0x70, 0x06, 0x01, 0x00, 0x00, 0x00,
    0x07, 0x11, 0x01, 0x03, 0x81, 0x46, 0x27, 0x78, 0x0A, 0xDE, 0x58, 0xA3, 0x54, 0x4C, 0x99, 0x26,
    0x0F, 0x45, 0x47, 0xBF, 0xEE, 0x00, 0x31, 0x4F, 0x45, 0x4C, 0x45, 0x4F, 0x61, 0x4A, 0x61, 0x4F,
    0x45, 0x59, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1D, 0x80, 0x18, 0x71, 0x1C, 0x16, 0x20, 0x58, 0x2C,
    0x25, 0x00, 0xC4, 0x8E, 0x21, 0x00, 0x00, 0x9E, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10,
    0x10, 0x3E, 0x96, 0x00, 0x13, 0x8E, 0x21, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x50,
    0x52, 0x49, 0x20, 0x48, 0x44, 0x4D, 0x49, 0x20, 0x54, 0x56, 0x0A, 0x20, 0x00, 0x00, 0x00, 0xFD,
    0x00, 0x30, 0x56, 0x0F, 0x41, 0x09, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0x74,
    0x02, 0x03, 0x27, 0x71, 0x47, 0x01, 0x02, 0x03, 0x04, 0x85, 0x06, 0x07, 0x26, 0x09, 0x07, 0x07,
    0x15, 0x07, 0x50, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10, 0x10, 0x3E, 0x96, 0x00, 0xC4,
    0x66, 0x03, 0x0C, 0x00, 0x10, 0x00, 0x80, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10, 0x10,
    0x3E, 0x96, 0x00, 0xC4, 0x8E, 0x21, 0x00, 0x00, 0x18, 0x01, 0x1D, 0x00, 0x72, 0x51, 0xD0, 0x1E,
    0x20, 0x6E, 0x28, 0x55, 0x00, 0xC4, 0x8E, 0x21, 0x00, 0x00, 0x1E, 0x8C, 0x0A, 0xA0, 0x14, 0x51,
    0xF0, 0x16, 0x00, 0x26, 0x7C, 0x43, 0x00, 0x13, 0x8E, 0x21, 0x00, 0x00, 0x98, 0x8C, 0x0A, 0xA0,
    0x14, 0x51, 0xF0, 0x16, 0x00, 0x26, 0x7C, 0x43, 0x00, 0xC4, 0x8E, 0x21, 0x00, 0x00, 0x98, 0xD6,
    0x09, 0x80, 0xA0, 0x20, 0xE0, 0x2D, 0x10, 0x08, 0x60, 0x22, 0x00, 0x12, 0x8E, 0x21, 0x08, 0xF6,

#else
    0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x22,0x4C,0x4C,0x34,0x01,0x00,0x00,0x00,
    0x31,0x11,0x01,0x03,0x80,0x66,0x39,0x78,0x0A,0xD8,0x3D,0xA7,0x53,0x36,0xAB,0x26,
    0x11,0x47,0x4A,0x20,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
    0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x1D,0x80,0x18,0x71,0x1C,0x16,0x20,0x58,0x2C,
    0x25,0x00,0xC4,0x8E,0x21,0x00,0x00,0x9E,0x01,0x1D,0x00,0x72,0x51,0xD0,0x1E,0x20,
    0x6E,0x28,0x55,0x00,0xC4,0x8E,0x21,0x00,0x00,0x1E,0x00,0x00,0x00,0xFC,0x00,0x4C,
    0x34,0x36,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFD,
    0x00,0x2D,0x41,0x0F,0x45,0x0F,0x00,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x01,0x35,
    0x02,0x03,0x1E,0x71,0x4A,0x85,0x04,0x03,0x93,0x14,0x07,0x12,0x16,0x10,0x1F,0x23,
    0x09,0x07,0x07,0x83,0x01,0x00,0x00,0x66,0x03,0x0C,0x00,0x10,0x00,0x00,0x8C,0x0A,
    0xD0,0x8A,0x20,0xE0,0x2D,0x10,0x10,0x3E,0x96,0x00,0xC4,0x8E,0x21,0x00,0x00,0x18,
    0x01,0x1D,0x00,0xBC,0x52,0xD0,0x1E,0x20,0xB8,0x28,0x55,0x40,0xC4,0x8E,0x21,0x00,
    0x00,0x1E,0x01,0x1D,0x80,0xD0,0x72,0x1C,0x16,0x20,0x10,0x2C,0x25,0x80,0xC4,0x8E,
    0x21,0x00,0x00,0x9E,0x8C,0x0A,0xD0,0x90,0x20,0x40,0x31,0x20,0x0C,0x40,0x55,0x00,
    0xC4,0x8E,0x21,0x00,0x00,0x18,0x01,0x1D,0x80,0x18,0x71,0x1C,0x16,0x20,0x58,0x2C,
    0x25,0x00,0xC4,0x8E,0x21,0x00,0x00,0x9E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,
#endif
};

BOOLEAN devIT6633_IIC_WriteByte( U8 u8SlaveID, U8 u8RegAddr, U8 u8Data )
{
    return MDrv_IIC_WriteByte( u8SlaveID, u8RegAddr, u8Data );
}

BOOLEAN devIT6633_IIC_ReadByte ( U8 u8SlaveID, U8 u8RegAddr, U8 *pu8Data )
{
    return MDrv_IIC_ReadByte( u8SlaveID, u8RegAddr, pu8Data );
}

void IT6633_Switch_Initial(void)
{
	U8 uc;
			
/*	IT6633_I2cWriteByte (0x15, 0xcc);
	IT6633_I2cWriteByte (0x29, 0x21);//Enable Forcing HPD of selected port
	*///IT6633_I2cWriteByte (0x06, 0x85/*0x80*/);//select port 0
	//IT6633_I2cWriteByte (0x0c, 0x07);//EQ strength:07
        printf("\n init IT6633 \n");
        if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,0x04, 0x00) )
        {
            printf( "\nI2C Error!!! uartI2C_Device_Write=1=\n" );
        }
        MsOS_DelayTask(50);      
        if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,0x04, 0x80) )
        {
            printf( "\nI2C Error!!! uartI2C_Device_Write=2=\n" );
        }
        MsOS_DelayTask(50);  
        if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,0x04, 0x00) )
        {
            printf( "\nI2C Error!!! uartI2C_Device_Write=3=\n" );
        }
        if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,0x15, 0xcc) )
        {
            printf( "\nI2C Error!!! uartI2C_Device_Write=4=\n" );
        }
        if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,0x0c, 0x07) )
        {
            printf( "\nI2C Error!!! uartI2C_Device_Write=5=\n" );
        }

        devIT6633_IIC_ReadByte(HDMI_SW_IT6633_I2C_DEVICE,0x02,&uc);
        
        if ( uc == 0xA0)
        {
            if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,0x28, 0x06) )
            {
                printf( "\nI2C Error!!! uartI2C_Device_Write=6=\n" );
            }
        }
        if ( uc == 0xA1)
        {
            if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,0x0F, 0x80) )
            {
                printf( "\nI2C Error!!! uartI2C_Device_Write=7=\n" );
            }
        }
        if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,0x29, 0x7e) )
        {
            printf( "\nI2C Error!!! uartI2C_Device_Write=8=\n" );
        }
        if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,0x06, 0xA0) )
        {
            printf( "\nI2C Error!!! uartI2C_Device_Write=9=\n" );
        }
		
}

void ChangePort(U8 port)
{
	U8 uc,uc3;
         printf( "\nport=%d\n", port);
         
         devIT6633_IIC_ReadByte(HDMI_SW_IT6633_I2C_DEVICE,SEL_PORT_REG,&uc);
         uc &= 0xF0;							//Disable ITE6633 & Select Channel
	uc |= port;							//Enable software mode
         if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,SEL_PORT_REG, uc) )
        {
            printf( "\nI2C Error!!! uartI2C_Device_Write=10=\n" );
        }
        devIT6633_IIC_ReadByte(HDMI_SW_IT6633_I2C_DEVICE,SEL_PORT_REG,&uc3);
        
}
void IT6633_SetHdmiPath(U8  path)
{
        U8 uc1,uc2;
        devIT6633_IIC_ReadByte(HDMI_SW_IT6633_I2C_DEVICE,SEL_PORT_REG,&uc1);
        uc2=uc1 & 0xDF;//bit6:Rx termination of all ports is on regardless of port selection;bit5:Transmitter disabled;bit4: Enable transmitter termination;bit[3:0]:channel not defined
        if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,SEL_PORT_REG, uc2) )
        {
            printf( "\nI2C Error!!! uartI2C_Device_Write=11=\n" );
        }
        ChangePort(path);
        MsOS_DelayTask(10); 

        devIT6633_IIC_ReadByte(HDMI_SW_IT6633_I2C_DEVICE,SEL_PORT_REG,&uc2);
        uc2=uc2 | 0x20;
        if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,SEL_PORT_REG, uc2) )
        {
            printf( "\nI2C Error!!! uartI2C_Device_Write=12=\n" );
        }
        /*
         if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,HPD_FORCE_REG, 0x21) )
        {
            printf( "\nI2C Error!!! uartI2C_Device_Write=13=\n" );
        }
         MsOS_DelayTask(110); 
          if ( FALSE == devIT6633_IIC_WriteByte(HDMI_SW_IT6633_I2C_DEVICE,HPD_FORCE_REG, 0x31) )
        {
            printf( "\nI2C Error!!! uartI2C_Device_Write=14=\n" );
        }

          */

}

#endif
#undef _IT6633DEC_