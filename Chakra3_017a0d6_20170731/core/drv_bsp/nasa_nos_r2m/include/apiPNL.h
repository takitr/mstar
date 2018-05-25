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
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2008-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// ("MStar Confidential Information") by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file   apiPNL.h
/// @brief  Panel Interface
/// @author MStar Semiconductor Inc.
//  Ver0100: 1. add OutTimingMode() to XC_PNL_OBJ. 2. adds APIPNL_OUT_TIMING_MODE to PanelType
//  Ver0101: 1. Correct the libversion from '1''0' to '0''1'
//           2. Fix the bug that C++ will have compile error for MACRO: MApi_PNL_Init_Ex
//           3. Remove the MApi_PNL_Init prototype
//  CL215113++:
//           1. Fix Gamma 10bit display error
//           2. Update debug function: MApi_PNL_SetDbgLevel.
//  CL215791++:
//           1. Fix Gamma 10bit display error
//           2. Update debug function: MApi_PNL_SetDbgLevel.
//  CL218113++:
//           1. Enable SUPPORT_SYNC_FOR_DUAL_MODE in T8, T9, Janus.
//  CL215791++:
//
//  CL258947++:sync to utopia_t3_u3 CL 251806
//           1. fix LVDS output output issues: XC_MOD_OUTPUT_CONF MASK is wrong
//           2. Adds MApi_PNL_PreInit for SEC to give output options before panel init.
//           3. Adds SSC related functions: request by SEC, the SPAN value range shall be 400, 500, 600
//           4. Adds SetOutputPattern function.
//           5. Modifies MDrv_PNL_SetGammaTbl with MLoad function.
//           6. Adds MHal_Output_LVDS_Pair_Setting for Vestel project
//  CL261417++: Fix gamma wrong problem.
//              Temprary disable the MLoad function in MDrv_PNL_SetGammaTbl.
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _API_XC_PANEL_H_
#define _API_XC_PANEL_H_

#ifdef __cplusplus
extern "C" {
#endif

//-------------------------------------------------------------------------------------------------
//  Macro and Define
//-------------------------------------------------------------------------------------------------
#ifndef _MS_VERSION_H_
#define MSIF_TAG                    {'M','S','I','F'}                   // MSIF
#define MSIF_CLASS                  {'0','0'}                           // DRV/API (DDI)
#define MSIF_CUS                    0x0000                              // MStar Common library
#define MSIF_MOD                    0x0000                              // MStar Common library
#define MSIF_CHIP                   0x000B
#define MSIF_CPU                    '0'
#define MSIF_OS                     '2'
#endif

// library information
#define MSIF_PNL_LIB_CODE               {'P','N','L','_'}
#define MSIF_PNL_LIBVER                 {'0','3'}
#define MSIF_PNL_BUILDNUM               {'5','2'}
#define MSIF_PNL_CHANGELIST             {'0','0','6','1','4','4','7','7'}

#define PNL_API_VERSION                 /* Character String for DRV/API version             */  \
    MSIF_TAG,                           /* 'MSIF'    */  \
    MSIF_CLASS,                         /* '00'      */  \
    MSIF_CUS,                           /* 0x0000    */  \
    MSIF_MOD,                           /* 0x0000    */  \
    MSIF_CHIP,                                           \
    MSIF_CPU,                                            \
    MSIF_PNL_LIB_CODE  ,                /* IP__      */  \
    MSIF_PNL_LIBVER    ,                /* 0.0 ~ Z.Z */  \
    MSIF_PNL_BUILDNUM  ,                /* 00 ~ 99   */  \
    MSIF_PNL_CHANGELIST,                /* CL#       */  \
    MSIF_OS

/// ApiStatusEX version of current XC lib
#define API_PNLSTATUS_EX_VERSION                          1

//-------------------------------------------------------------------------------------------------
//  Type and Structure
//-------------------------------------------------------------------------------------------------
/// Define return value of MApi_PNL
typedef enum
{
    E_APIPNL_FAIL = 0,
    E_APIPNL_OK = 1,
    E_APIPNL_GET_BASEADDR_FAIL,            ///< get base address failed when initialize panel driver
    E_APIPNL_OBTAIN_MUTEX_FAIL,            ///< obtain mutex timeout when calling this function
} APIPNL_Result;

/// Define aspect ratio
typedef enum
{
    E_PNL_ASPECT_RATIO_4_3    = 0,         ///< set aspect ratio to 4 : 3
    E_PNL_ASPECT_RATIO_WIDE,               ///< set aspect ratio to 16 : 9
    E_PNL_ASPECT_RATIO_OTHER,              ///< resvered for other aspect ratio other than 4:3/ 16:9
}E_PNL_ASPECT_RATIO;

/// Define the panel gamma precision type
typedef enum
{
    E_APIPNL_GAMMA_10BIT = 0,              ///< Gamma Type of 10bit
    E_APIPNL_GAMMA_12BIT,                  ///< Gamma Type of 12bit
    E_APIPNL_GAMMA_ALL                     ///< The library can support all mapping mode
} APIPNL_GAMMA_TYPE;

/// Define Gamma type
typedef enum
{
    E_APIPNL_GAMMA_8BIT_MAPPING = 0,      ///< mapping 1024 to 256 gamma entries
    E_APIPNL_GAMMA_10BIT_MAPPING,         ///< mapping 1024 to 1024 gamma entries
    E_APIPNL_GAMMA_ALL_MAPPING            ///< the library can map to any entries
} APIPNL_GAMMA_MAPPEING_MODE;             ///< samping mode for GAMMA correction

/// Define The dimming control flag. when use with setter/getter, it will set/get MIN/MAX/Current value
typedef enum
{
    E_APIPNL_DIMMING_MIN = 0,              ///< Indicate to Get/Set Min Dimming value.
    E_APIPNL_DIMMING_CURRENT  ,            ///< Indicate to Get/Set Current Dimming value.
    E_APIPNL_DIMMING_MAX    ,              ///< Indicate to Get/Set Max Dimming value.
} APIPNL_DIMMING_CTRL;

/// Define PANEL Signaling Type
typedef enum
{
    LINK_TTL,                              ///< TTL  type
    LINK_LVDS,                             ///< LVDS type
    LINK_RSDS,                             ///< RSDS type
    LINK_MINILVDS,                         ///< TCON
    LINK_ANALOG_MINILVDS,                  ///< Analog TCON
    LINK_DIGITAL_MINILVDS,                 ///< Digital TCON
    LINK_MFC,                              ///< Ursa (TTL output to Ursa)
    LINK_DAC_I,                            ///< DAC output
    LINK_DAC_P,                            ///< DAC output
    LINK_PDPLVDS,                          ///< For PDP(Vsync use Manually MODE)
    LINK_EXT,                              /// EXT LPLL TYPE
}APIPNL_LINK_TYPE;

/// Define PANEL Signaling Type
typedef enum
{
    // M10 New Panel Type
    LINK_EPI34_8P = LINK_EXT,              /// 10
    LINK_EPI28_8P,                         /// 11
    LINK_EPI34_6P,                         /// 12
    LINK_EPI28_6P,                         /// 13

    ///LINK_MINILVDS_6P_2L,                /// replace this with LINK_MINILVDS
    LINK_MINILVDS_5P_2L,                   /// 14
    LINK_MINILVDS_4P_2L,                   /// 15
    LINK_MINILVDS_3P_2L,                   /// 16
    LINK_MINILVDS_6P_1L,                   /// 17
    LINK_MINILVDS_5P_1L,                   /// 18
    LINK_MINILVDS_4P_1L,                   /// 19
    LINK_MINILVDS_3P_1L,                   /// 20

    LINK_HS_LVDS,                          /// 21
    LINK_HF_LVDS,                          /// 22

    LINK_TTL_TCON,                         /// 23
    LINK_MINILVDS_2CH_3P_8BIT,              //  2 channel, 3 pair, 8 bits ///24
    LINK_MINILVDS_2CH_4P_8BIT,              //  2 channel, 4 pair, 8 bits ///25
    LINK_MINILVDS_2CH_5P_8BIT,              // 2 channel, 5 pair, 8 bits ///26
    LINK_MINILVDS_2CH_6P_8BIT,              // 2 channel, 6 pair, 8 bits ///27

    LINK_MINILVDS_1CH_3P_8BIT,              // 1 channel, 3 pair, 8 bits ///28
    LINK_MINILVDS_1CH_4P_8BIT,              // 1 channel, 4 pair, 8 bits ///29
    LINK_MINILVDS_1CH_5P_8BIT,              // 1 channel, 5 pair, 8 bits ///30
    LINK_MINILVDS_1CH_6P_8BIT,              // 1 channel, 6 pair, 8 bits ///31

    LINK_MINILVDS_2CH_3P_6BIT,              // 2 channel, 3 pari, 6 bits ///32
    LINK_MINILVDS_2CH_4P_6BIT,              // 2 channel, 4 pari, 6 bits ///33
    LINK_MINILVDS_2CH_5P_6BIT,              // 2 channel, 5 pari, 6 bits ///34
    LINK_MINILVDS_2CH_6P_6BIT,              //  2 channel, 6 pari, 6 bits ///35

    LINK_MINILVDS_1CH_3P_6BIT,              // 1 channel, 3 pair, 6 bits ///36
    LINK_MINILVDS_1CH_4P_6BIT,              // 1 channel, 4 pair, 6 bits ///37
    LINK_MINILVDS_1CH_5P_6BIT,              // 1 channel, 5 pair, 6 bits ///38
    LINK_MINILVDS_1CH_6P_6BIT,              // 1 channel, 6 pair, 6 bits ///39
    LINK_HDMI_BYPASS_MODE,                   //   HDMI Bypass Mode///40

    LINK_EPI34_2P,                           /// 41
    LINK_EPI34_4P,                         /// 42
    LINK_EPI28_2P,                         /// 43
    LINK_EPI28_4P,                         /// 44

    LINK_VBY1_10BIT_4LANE,     ///45
    LINK_VBY1_10BIT_2LANE,    ///46
    LINK_VBY1_10BIT_1LANE,    ///47
    LINK_VBY1_8BIT_4LANE,     ///48
    LINK_VBY1_8BIT_2LANE,     ///49
    LINK_VBY1_8BIT_1LANE,     ///50

    LINK_VBY1_10BIT_8LANE,     ///51
    LINK_VBY1_8BIT_8LANE,     ///52

}APIPNL_LINK_EXT_TYPE;

/// Define power on and off timing order.
typedef enum
{
    E_APIPNL_POWER_TIMING_1 ,              ///< Timing order 1
    E_APIPNL_POWER_TIMING_2 ,              ///< Timing order 2
    E_APIPNL_POWER_TIMING_NA = 0xFFFF,     ///< Reserved Timing order
} APIPNL_POWER_TIMING_SEQ;

/// Define TI bit mode
typedef enum
{
    TI_10BIT_MODE = 0,
    TI_8BIT_MODE = 2,
    TI_6BIT_MODE = 3,
} APIPNL_TIBITMODE;

/// Define which panel output timing change mode is used to change VFreq for same panel
typedef enum
{
    E_PNL_CHG_DCLK   = 0,      ///<change output DClk to change Vfreq.
    E_PNL_CHG_HTOTAL = 1,      ///<change H total to change Vfreq.
    E_PNL_CHG_VTOTAL = 2,      ///<change V total to change Vfreq.
} APIPNL_OUT_TIMING_MODE;

/// Define panel output format bit mode
typedef enum
{
    OUTPUT_10BIT_MODE = 0,//default is 10bit, becasue 8bit panel can use 10bit config and 8bit config.
    OUTPUT_6BIT_MODE = 1, //but 10bit panel(like PDP panel) can only use 10bit config.
    OUTPUT_8BIT_MODE = 2, //and some PDA panel is 6bit.
} APIPNL_OUTPUTFORMAT_BITMODE;

/// Panel Api information
typedef struct
{
    APIPNL_GAMMA_TYPE eSupportGammaType;   ///< Gamma type supported by apiPNL
} PNL_ApiInfo;

/// Panel status
typedef struct
{
    MS_BOOL bPanel_Initialized;     ///< panel initialized or not
    MS_BOOL bPanel_Enabled;         ///< panel enabled or not, if enabled, you can see OSD/Video
} PNL_ApiStatus;

/// Panel status
typedef struct
{
    MS_U32 u32ApiStatusEx_Version;///<Version of current structure. Please always set to "API_PNLSTATUS_EX_VERSION" as input
    MS_U16 u16ApiStatusEX_Length; ///<Length of this structure, u16PanelInfoEX_Length=sizeof(XC_PANEL_INFO_EX)

    MS_BOOL bPNLInitialize;       ///< panel initialized or not
    MS_BOOL bPNLEnable;           ///< panel enabled or not, if enabled, you can see OSD/Video
    MS_U16  u16VTotal;            ///< Output vertical total
    MS_U16  u16DEVStart;          ///< Output DE vertical start
    MS_U16  u16DEVEnd;            ///< Output DE Vertical end
    MS_U16  u16VSyncStart;        ///< Output VSync start
    MS_U16  u16VSyncEnd;          ///< Output VSync end
    MS_U16  u16HTotal;            ///< Output horizontal total
    MS_U16  u16DEHStart;          ///< Output DE horizontal start
    MS_U16  u16DEHEnd;            ///< Output DE horizontal end
    MS_U16  u16HSyncWidth;        ///< Output HSync width
    MS_BOOL bIsPanelManualVysncMode;   ///< enable manuel V sync control
    MS_BOOL bInterlaceOutput;     ///< enable Scaler Interlace output
    MS_BOOL bYUVOutput;           ///< enable Scaler YUV output
} PNL_ApiExtStatus;

/// Panel output control, must be called before g_IPanel.Enable(), otherwise will output after called g_IPanel.Enable()
typedef enum
{
    E_APIPNL_OUTPUT_NO_OUTPUT = 0,     ///< even called g_IPanel.Enable(TRUE), still no physical output
    E_APIPNL_OUTPUT_CLK_ONLY,          ///< after called g_IPanel.Enable(TRUE), will output clock only
    E_APIPNL_OUTPUT_DATA_ONLY,         ///< after called g_IPanel.Enable(TRUE), will output data only
    E_APIPNL_OUTPUT_CLK_DATA,          ///< after called g_IPanel.Enable(TRUE), will output clock and data
} APIPNL_OUTPUT_MODE;

/// Define Panel MISC control index
/// please enum use BIT0 = 0x01, BIT1 = 0x02, BIT2 = 0x04, BIT3 = 0x08, BIT4 = 0x10,
typedef enum
{
    E_APIPNL_MISC_MFC_ENABLE = 0x0001,
    E_APIPNL_MISC_SKIP_CALIBRATION = 0x0002,

    E_APIPNL_MISC_MFC_MCP    = 0x0010, // bit 4
    E_APIPNL_MISC_MFC_ABChannel = 0x0020,  // bit5
    E_APIPNL_MISC_MFC_ACChannel = 0x0040,  // bit 6
    E_APIPNL_MISC_MFC_ENABLE_60HZ = 0x0080, // bit 7, for 60Hz Panel
    E_APIPNL_MISC_MFC_ENABLE_240HZ = 0x0100, // bit 8, for 240Hz Panel
    E_APIPNL_MISC_4K2K_ENABLE_60HZ = 0x0200, // bit 9, for 4k2K 60Hz Panel
} APIPNL_MISC;

typedef enum
{
    E_APIPNL_TCON_TAB_TYPE_GENERAL,
    E_APIPNL_TCON_TAB_TYPE_GPIO,
    E_APIPNL_TCON_TAB_TYPE_SCALER,
    E_APIPNL_TCON_TAB_TYPE_MOD,
    E_APIPNL_TCON_TAB_TYPE_GAMMA,
    E_APIPNL_TCON_TAB_TYPE_POWER_SEQUENCE_ON,
    E_APIPNL_TCON_TAB_TYPE_POWER_SEQUENCE_OFF,
}APIPNL_TCON_TAB_TYPE;

/**
* Represent a panel interface.
*
* Provide panel attributes, and some panel basic functions
*/
typedef struct
{
    //
    //  Data
    //
    const char*        ( * const Name          ) ( void ); // /< Panel name
    MS_U16             ( * const HStart        ) ( void ); // /< DE H start
    MS_U16             ( * const VStart        ) ( void ); // /< DE V start
    MS_U16             ( * const Width         ) ( void ); // /< DE H width
    MS_U16             ( * const Height        ) ( void ); // /< DE V height
    MS_U16             ( * const HTotal        ) ( void ); // /< Htotal
    MS_U16             ( * const VTotal        ) ( void ); // /< Vtotal
    MS_U8              ( * const HSynWidth     ) ( void ); // /< H sync width
    MS_U8              ( * const HSynBackPorch ) ( void ); // /< H sync back porch
    MS_U8              ( * const VSynBackPorch ) ( void ); // /< V sync back porch
    MS_U16             ( * const DefaultVFreq  ) ( void ); // /< deault V Freq
    MS_U8              ( * const LPLL_Mode     ) ( void ); // /< 0: single,      1: dual mode
    MS_U8              ( * const LPLL_Type     ) ( void ); // /< 0: LVDS,        1: RSDS
    E_PNL_ASPECT_RATIO ( * const AspectRatio   ) ( void ); // /< please refer to E_PNL_ASPECT_RATIO
    MS_U32             ( * const MinSET        ) ( void ); // / < MinSET
    MS_U32             ( * const MaxSET        ) ( void );     // / < MaxSET

    //
    //  Manipulation
    //
    /// @brief Set Span-Spectrum-Control
    /// @param u16Fmodulation  IN:SSC_SPAN_PERIOD
    /// @param u16Rdeviation   IN:SSC_STEP_PERCENT
    /// @param bEnable         IN:Enable / Disable
    ///
    void    ( * const SetSSC      ) ( MS_U16 u16Fmodulation, MS_U16 u16Rdeviation, MS_BOOL bEnable ) ;

    /// @brief Enable panel's output, but "not include the function to turn VCC on".
    /// @param bEnable          IN:Enable / Disable
    MS_BOOL ( * const Enable      ) ( MS_BOOL bEnable ) ;

    /// @brief Set Gamma correction table.
    /// @param eGammaType       Resolution of gamma table
    /// @param pu8GammaTab      gamma table
    /// @param u16NumOfLevel    T2: 256, T3: can be 256 / 1024 levels
    MS_BOOL ( * const SetGammaTbl ) ( APIPNL_GAMMA_TYPE eGammaType,
                                      MS_U8* pu8GammaTab[3],
                                      APIPNL_GAMMA_MAPPEING_MODE Gamma_Map_Mode ) ;

    /// @brief Get Gamma correction table.
    /// @return A Gamma table used currently.
    MS_U8** ( * const GammaTab    ) ( void ) ;

    /// @brief printout panel data, width, height, htt, vtt etc.
    void    ( * const Dump        ) ( void ) ;

    /// @brief Get Min/Max/Current Dimming Value according to the given flag.
    /// @param max_min_setting     Flag of Min / Max / Current Dimming Value.s
    MS_U8   ( * const DimCtrl     ) ( APIPNL_DIMMING_CTRL max_min_setting ) ;

    /// @brief Query Power On Timing with given power on timing order.\n
    /// @param power_on_sequence_timing order
    MS_U16  ( * const OnTiming    ) ( APIPNL_POWER_TIMING_SEQ power_on_sequence_timing  ) ;

    /// @brief Query Power Off Timing with given power on timing order.\n
    /// @param power_off_sequence_timing order
    MS_U16  ( * const OffTiming   ) ( APIPNL_POWER_TIMING_SEQ power_off_sequence_timing ) ;

    //
    // Custimized methods, can be provided by clinets.
    //
    void   ( *TurnBackLightOn     ) ( MS_BOOL bEnable ) ;
    APIPNL_OUT_TIMING_MODE
          ( * const OutTimingMode )( void ); ///<output timing mode

    ///@brief Set Gamma value
    ///@param u8Channel     R/G/B channel, 0->R, 1->G, 2->B
    ///@param u16Offset     The address of Gamma value
    ///@param u16GammaValue Gamma value
    MS_BOOL (* const SetGammaValue)(MS_U8 u8Channel, MS_U16 u16Offset, MS_U16 u16GammaValue);

    /// @brief Get Gamma correction table.
    /// @param eGammaType       Resolution of gamma table
    /// @param pu8GammaTab      gamma table
	/// @param Gamma_Map_Mode   8Bit mapping or 10Bit mapping
    MS_BOOL ( * const GetGammaTbl ) ( APIPNL_GAMMA_TYPE eGammaType,
                                      MS_U8* pu8GammaTab[3],
                                      APIPNL_GAMMA_MAPPEING_MODE Gamma_Map_Mode ) ;
}XC_PNL_OBJ;

/// A panel struct type used to specify the panel attributes, and settings from Board layout
typedef struct
{
    const char *m_pPanelName;                ///<  PanelName
    //
    //  Panel output
    //
    MS_U8 m_bPanelDither :1;                 ///<  PANEL_DITHER, keep the setting
    APIPNL_LINK_TYPE m_ePanelLinkType   :4;  ///<  PANEL_LINK

    ///////////////////////////////////////////////
    // Board related setting
    ///////////////////////////////////////////////
    MS_U8 m_bPanelDualPort  :1;              ///<  VOP_21[8], MOD_4A[1],    PANEL_DUAL_PORT, refer to m_bPanelDoubleClk
    MS_U8 m_bPanelSwapPort  :1;              ///<  MOD_4A[0],               PANEL_SWAP_PORT, refer to "LVDS output app note" A/B channel swap
    MS_U8 m_bPanelSwapOdd_ML    :1;          ///<  PANEL_SWAP_ODD_ML
    MS_U8 m_bPanelSwapEven_ML   :1;          ///<  PANEL_SWAP_EVEN_ML
    MS_U8 m_bPanelSwapOdd_RB    :1;          ///<  PANEL_SWAP_ODD_RB
    MS_U8 m_bPanelSwapEven_RB   :1;          ///<  PANEL_SWAP_EVEN_RB

    MS_U8 m_bPanelSwapLVDS_POL  :1;          ///<  MOD_40[5], PANEL_SWAP_LVDS_POL, for differential P/N swap
    MS_U8 m_bPanelSwapLVDS_CH   :1;          ///<  MOD_40[6], PANEL_SWAP_LVDS_CH, for pair swap
    MS_U8 m_bPanelPDP10BIT      :1;          ///<  MOD_40[3], PANEL_PDP_10BIT ,for pair swap
    MS_U8 m_bPanelLVDS_TI_MODE  :1;          ///<  MOD_40[2], PANEL_LVDS_TI_MODE, refer to "LVDS output app note"

    ///////////////////////////////////////////////
    // For TTL Only
    ///////////////////////////////////////////////
    MS_U8 m_ucPanelDCLKDelay;                ///<  PANEL_DCLK_DELAY
    MS_U8 m_bPanelInvDCLK   :1;              ///<  MOD_4A[4],                   PANEL_INV_DCLK
    MS_U8 m_bPanelInvDE     :1;              ///<  MOD_4A[2],                   PANEL_INV_DE
    MS_U8 m_bPanelInvHSync  :1;              ///<  MOD_4A[12],                  PANEL_INV_HSYNC
    MS_U8 m_bPanelInvVSync  :1;              ///<  MOD_4A[3],                   PANEL_INV_VSYNC

    ///////////////////////////////////////////////
    // Output driving current setting
    ///////////////////////////////////////////////
    // driving current setting (0x00=4mA, 0x01=6mA, 0x02=8mA, 0x03=12mA)
    MS_U8 m_ucPanelDCKLCurrent;              ///<  define PANEL_DCLK_CURRENT
    MS_U8 m_ucPanelDECurrent;                ///<  define PANEL_DE_CURRENT
    MS_U8 m_ucPanelODDDataCurrent;           ///<  define PANEL_ODD_DATA_CURRENT
    MS_U8 m_ucPanelEvenDataCurrent;          ///<  define PANEL_EVEN_DATA_CURRENT

    ///////////////////////////////////////////////
    // panel on/off timing
    ///////////////////////////////////////////////
    MS_U16 m_wPanelOnTiming1;                ///<  time between panel & data while turn on power
    MS_U16 m_wPanelOnTiming2;                ///<  time between data & back light while turn on power
    MS_U16 m_wPanelOffTiming1;               ///<  time between back light & data while turn off power
    MS_U16 m_wPanelOffTiming2;               ///<  time between data & panel while turn off power

    ///////////////////////////////////////////////
    // panel timing spec.
    ///////////////////////////////////////////////
    // sync related
    MS_U8 m_ucPanelHSyncWidth;               ///<  VOP_01[7:0], PANEL_HSYNC_WIDTH
    MS_U8 m_ucPanelHSyncBackPorch;           ///<  PANEL_HSYNC_BACK_PORCH, no register setting, provide value for query only

                                             ///<  not support Manuel VSync Start/End now
                                             ///<  VOP_02[10:0] VSync start = Vtt - VBackPorch - VSyncWidth
                                             ///<  VOP_03[10:0] VSync end = Vtt - VBackPorch
    MS_U8 m_ucPanelVSyncWidth;               ///<  define PANEL_VSYNC_WIDTH
    MS_U8 m_ucPanelVBackPorch;               ///<  define PANEL_VSYNC_BACK_PORCH

    // DE related
    MS_U16 m_wPanelHStart;                   ///<  VOP_04[11:0], PANEL_HSTART, DE H Start (PANEL_HSYNC_WIDTH + PANEL_HSYNC_BACK_PORCH)
    MS_U16 m_wPanelVStart;                   ///<  VOP_06[11:0], PANEL_VSTART, DE V Start
    MS_U16 m_wPanelWidth;                    ///< PANEL_WIDTH, DE width (VOP_05[11:0] = HEnd = HStart + Width - 1)
    MS_U16 m_wPanelHeight;                   ///< PANEL_HEIGHT, DE height (VOP_07[11:0], = Vend = VStart + Height - 1)

    // DClk related
    MS_U16 m_wPanelMaxHTotal;                ///<  PANEL_MAX_HTOTAL. Reserved for future using.
    MS_U16 m_wPanelHTotal;                   ///<  VOP_0C[11:0], PANEL_HTOTAL
    MS_U16 m_wPanelMinHTotal;                ///<  PANEL_MIN_HTOTAL. Reserved for future using.

    MS_U16 m_wPanelMaxVTotal;                ///<  PANEL_MAX_VTOTAL. Reserved for future using.
    MS_U16 m_wPanelVTotal;                   ///<  VOP_0D[11:0], PANEL_VTOTAL
    MS_U16 m_wPanelMinVTotal;                ///<  PANEL_MIN_VTOTAL. Reserved for future using.

    MS_U8 m_dwPanelMaxDCLK;                  ///<  PANEL_MAX_DCLK. Reserved for future using.
    MS_U8 m_dwPanelDCLK;                     ///<  LPLL_0F[23:0], PANEL_DCLK          ,{0x3100_10[7:0], 0x3100_0F[15:0]}
    MS_U8 m_dwPanelMinDCLK;                  ///<  PANEL_MIN_DCLK. Reserved for future using.

                                             ///<  spread spectrum
    MS_U16 m_wSpreadSpectrumStep;            ///<  move to board define, no use now.
    MS_U16 m_wSpreadSpectrumSpan;            ///<  move to board define, no use now.

    MS_U8 m_ucDimmingCtl;                    ///<  Initial Dimming Value
    MS_U8 m_ucMaxPWMVal;                     ///<  Max Dimming Value
    MS_U8 m_ucMinPWMVal;                     ///<  Min Dimming Value

    MS_U8 m_bPanelDeinterMode   :1;          ///<  define PANEL_DEINTER_MODE,  no use now
    E_PNL_ASPECT_RATIO m_ucPanelAspectRatio; ///<  Panel Aspect Ratio, provide information to upper layer application for aspect ratio setting.
  /*
    *
    * Board related params
    *
    *  If a board ( like BD_MST064C_D01A_S ) swap LVDS TX polarity
    *    : This polarity swap value =
    *      (LVDS_PN_SWAP_H<<8) | LVDS_PN_SWAP_L from board define,
    *  Otherwise
    *    : The value shall set to 0.
    */
    MS_U16 m_u16LVDSTxSwapValue;
    APIPNL_TIBITMODE m_ucTiBitMode;                         ///< MOD_4B[1:0], refer to "LVDS output app note"
    APIPNL_OUTPUTFORMAT_BITMODE m_ucOutputFormatBitMode;

    MS_U8 m_bPanelSwapOdd_RG    :1;          ///<  define PANEL_SWAP_ODD_RG
    MS_U8 m_bPanelSwapEven_RG   :1;          ///<  define PANEL_SWAP_EVEN_RG
    MS_U8 m_bPanelSwapOdd_GB    :1;          ///<  define PANEL_SWAP_ODD_GB
    MS_U8 m_bPanelSwapEven_GB   :1;          ///<  define PANEL_SWAP_EVEN_GB

    /**
    *  Others
    */
    MS_U8 m_bPanelDoubleClk     :1;             ///<  LPLL_03[7], define Double Clock ,LVDS dual mode
    MS_U32 m_dwPanelMaxSET;                     ///<  define PANEL_MAX_SET
    MS_U32 m_dwPanelMinSET;                     ///<  define PANEL_MIN_SET
    APIPNL_OUT_TIMING_MODE m_ucOutTimingMode;   ///<Define which panel output timing change mode is used to change VFreq for same panel
    MS_U8 m_bPanelNoiseDith     :1;             ///<  PAFRC mixed with noise dither disable
} PanelType;

//Display information
typedef struct
{
    MS_U32 VDTOT; //Output vertical total
    MS_U32 DEVST; //Output DE vertical start
    MS_U32 DEVEND;//Output DE Vertical end
    MS_U32 HDTOT;// Output horizontal total
    MS_U32 DEHST; //Output DE horizontal start
    MS_U32 DEHEND;// Output DE horizontal end
    MS_BOOL bInterlaceMode;
    MS_BOOL bYUVOutput;
} MS_PNL_DST_DispInfo;

//HW LVDS Reserved Bit to L/R flag Info
typedef struct
{
    MS_U32 u32pair; // pair 0: BIT0, pair 1: BIT1, pair 2: BIT2, pair 3: BIT3, pair 4: BIT4, etc ...
    MS_U16 u16channel; // channel A: BIT0, channel B: BIT1,
    MS_BOOL bEnable;
} MS_PNL_HW_LVDSResInfo;

/// Define the initial OverDrive for XC
typedef struct
{
    MS_U8 u8ODTbl[1056];
    MS_U32 u32PNL_version;                  ///<Version of current structure.
    // OD frame buffer related
    MS_PHYADDR u32OD_MSB_Addr;              ///<OverDrive MSB frame buffer start address, absolute without any alignment
    MS_U32 u32OD_MSB_Size;                  ///<OverDrive MSB frame buffer size, the unit is BYTES
    MS_PHYADDR u32OD_LSB_Addr;              ///<OverDrive LSB frame buffer start address, absolute without any alignment
    MS_U32 u32OD_LSB_Size;                  ///<OverDrive MSB frame buffer size, the unit is BYTES
} MS_PNL_OD_INITDATA;

typedef struct
{
	MS_U16 m_u16ExpectSwingLevel;
    MS_U8 m_u8ModCaliPairSel;
	MS_U8 m_u8ModCaliTarget;
	MS_S8 m_s8ModCaliOffset;
	MS_BOOL m_bPVDD_2V5;
}MS_PNL_ModCaliInfo;

//-------------------------------------------------------------------------------------------------
//  Function and Variable
//-------------------------------------------------------------------------------------------------

/******************************************************************************/
/*                     Variable                                            */
/* ****************************************************************************/
/**
*
*  The global interface for panel manipulation.
*
*  @attention <b>Call "MApi_PNL_Init()" first before using this obj</b>
*/
extern XC_PNL_OBJ g_IPanel;

typedef enum
{
    E_PNL_NO_OUTPUT,
    E_PNL_CLK_ONLY,
    E_PNL_CLK_DATA,
    E_PNL_MAX,
} E_PNL_PREINIT_OPTIONS;

APIPNL_Result       MApi_PNL_GetLibVer(const MSIF_Version **ppVersion);
const PNL_ApiInfo * MApi_PNL_GetInfo(void);
MS_BOOL             MApi_PNL_GetStatus(PNL_ApiStatus *pPnlStatus);
MS_BOOL             MApi_PNL_GetStatusEx(PNL_ApiExtStatus *pPnlExtStatus);

MS_BOOL             MApi_PNL_SetDbgLevel(MS_U16 u16DbgSwitch);

MS_BOOL             MApi_PNL_IOMapBaseInit(void);

MS_BOOL             MApi_PNL_PreInit(E_PNL_PREINIT_OPTIONS eInitParam);

#ifndef _API_XC_PANEL_C_
#define             MApi_PNL_Init(x) MApi_PNL_Init_Ex(x, (MSIF_Version){{ PNL_API_VERSION },});
#endif

MS_BOOL             MApi_PNL_Init_Ex(PanelType *pSelPanelType/* <in > */, MSIF_Version LIBVER);
void                MApi_PNL_SetOutput(APIPNL_OUTPUT_MODE eOutputMode);
MS_BOOL             MApi_PNL_ChangePanelType(PanelType *pSelPanelType);
//------------------------------------------------------------------------------
/// Dump TCON Table
/// @param pTCONTable              \b IN: Table
/// @param u8Tcontype               \b IN: use APIPNL_TCON_TAB_TYPE ad input
/// @return TRUE --OK   FALSE
//------------------------------------------------------------------------------
MS_BOOL             MApi_PNL_TCONMAP_DumpTable(MS_U8 *pTCONTable, MS_U8 u8Tcontype);
MS_BOOL             MApi_PNL_TCONMAP_Power_Sequence(MS_U8 *pTCONTable, MS_BOOL bEnable);
void                MApi_PNL_TCON_Count_Reset ( MS_BOOL bEnable );
void                MApi_PNL_TCON_Init( void );
MS_BOOL             MApi_PNL_GetDstInfo(MS_PNL_DST_DispInfo *pDstInfo, MS_U32 u32SizeofDstInfo);
// MOD Output swing should between 40~600
MS_BOOL             MApi_PNL_Control_Out_Swing(MS_U16 u16Swing_Level);

void                MApi_PNL_SetOutputPattern(MS_BOOL bEnable, MS_U16 u16Red , MS_U16 u16Green, MS_U16 u16Blue);
void MApi_Mod_Calibration_Setting(MS_PNL_ModCaliInfo *pstModCaliInfo);
MS_BOOL             MApi_Mod_Do_Calibration(void);

/*
    Type: This type means package. Different package maybe have different type id.
    Check board define or system configure for type id.
*/
void                MApi_BD_LVDS_Output_Type(MS_U16 Type);
void                MApi_PNL_SetLPLLTypeExt(APIPNL_LINK_EXT_TYPE eLPLL_TypeExt);
void                MApi_PNL_Init_MISC(APIPNL_MISC ePNL_MISC);
void                MApi_PNL_MOD_OutputConfig_User(MS_U32 u32OutputCFG0_7, MS_U32 u32OutputCFG8_15, MS_U32 u32OutputCFG16_21);
void                MApi_PNL_HWLVDSReservedtoLRFlag(MS_PNL_HW_LVDSResInfo lvdsresinfo);

void                MApi_MOD_PVDD_Power_Setting(MS_BOOL bIs2p5);

// more SSC function, shall be added into XC_PNL_OBJ
int                 MApi_PNL_SetSSC_En(MS_BOOL bEnable);
//------------------------------------------------------------------------------
/// Set panel SSC Fmodulation
/// @param u16Fmodulation              \b IN:Fmodulation, Unit:0.1Khz
/// @return TRUE --OK   FALSE
//------------------------------------------------------------------------------
int                 MApi_PNL_SetSSC_Fmodulation(MS_U16 u16Fmodulation);
//------------------------------------------------------------------------------
/// Set panel SSC Rdeviation
/// @param u16Rdeviation              \b IN: u16Rdeviation, Unit:1%%(1/10000)
/// @return TRUE --OK   FALSE
//------------------------------------------------------------------------------
int                 MApi_PNL_SetSSC_Rdeviation(MS_U16 u16Rdeviation);
APIPNL_Result       MApi_PNL_SkipTimingChange(MS_BOOL bFlag);

//-------------------------------------------------------------------------------------------------
/// Initialize OverDrive
/// @param  pPNL_ODInitData                 \b IN: the Initialized Data
/// @param  u32ODInitDataLen                \b IN: the length of the initialized data
/// @return E_APIPNL_OK or E_APIPNL_FAIL
//-------------------------------------------------------------------------------------------------
APIPNL_Result       MApi_PNL_OverDriver_Init(MS_PNL_OD_INITDATA *pPNL_ODInitData, MS_U32 u32ODInitDataLen);

//-------------------------------------------------------------------------------------------------
/// Set per channel OverDrive table
/// @param  u8Channel             \b IN: 0x02:B channel; 0x04:G channel; 0x08:R channel
/// @param  u8ODTbl               \b IN: Overdrive table
/// @return E_APIPNL_OK or E_APIPNL_FAIL
//-------------------------------------------------------------------------------------------------
APIPNL_Result MApi_PNL_SetOverDriverPerChannel(MS_U8 u8Channel,MS_U8* u8ODTbl);

//-------------------------------------------------------------------------------------------------
/// OverDrive Enable
/// @param  bEnable               \b IN: TRUE: Enable OverDrive; FALSE: Disable OverDrive
/// @return E_APIPNL_OK or E_APIPNL_FAIL
//-------------------------------------------------------------------------------------------------
APIPNL_Result       MApi_PNL_OverDriver_Enable(MS_BOOL bEnable);

//-------------------------------------------------------------------------------------------------
/// Get TCON capability
/// @return MS_BOOL
//-------------------------------------------------------------------------------------------------
MS_BOOL MApi_PNL_Get_TCON_Capability(void);


//-------------------------------------------------------------------------------------------------
/// Set FRC MOD pair swap
/// @param  u32Polarity               \b IN: u32Polarity, (d:c:b:a)=([15:14],[13:12],[11:10],[9:8]) => (10,00,11,01), => (2,0,3,1)
//-------------------------------------------------------------------------------------------------
void MApi_PNL_SetPairSwap(MS_U32 u32Polarity);


//-------------------------------------------------------------------------------------------------
/// Cal Ext LPLL Set by DCLK
/// @param  ldHz               \b IN: ldHz = Htt*Vtt*Vfreq
//-------------------------------------------------------------------------------------------------
void MApi_PNL_CalExtLPLLSETbyDClk(MS_U32 ldHz);

//////////////////////////////////////////////
// Below functions are obosolted ! Please do not use them if you do not use them yet.
//////////////////////////////////////////////

//-------------------------------------------------------------------------------------------------
///-obosolte!! use MApi_PNL_Control_Out_Swing instead
//-------------------------------------------------------------------------------------------------
MS_BOOL             MApi_PNL_SetDiffSwingLevel(MS_U8 u8Swing_Level);

//-------------------------------------------------------------------------------------------------
/// Do handshake for special output device, ex. VB1
/// @return TRUE or FALSE
//-------------------------------------------------------------------------------------------------
MS_BOOL MApi_PNL_OutputDeviceHandshake(void);

//-------------------------------------------------------------------------------------------------
/// set necessary setting for outputing interlace timing to rear
/// @return APIPNL_Result
//-------------------------------------------------------------------------------------------------
APIPNL_Result MApi_PNL_SetOutputInterlaceTiming(MS_BOOL bEnable);

#ifdef __cplusplus
}
#endif

#endif
