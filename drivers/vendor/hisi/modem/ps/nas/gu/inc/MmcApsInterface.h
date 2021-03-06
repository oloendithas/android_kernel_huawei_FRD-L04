

#ifndef __MMC_APS_INTERFACE_H__
#define __MMC_APS_INTERFACE_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "PsTypeDef.h"

/* 删除ExtAppMmcInterface.h*/
#include "TafMmcInterface.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/

enum MMC_APS_MSG_ID_ENUM
{
    ID_MMC_APS_SERVICE_STATUS_IND = TAFMMC_APS_SERVICE_STATE_IND,               /* _H2ASN_MsgChoice MMC_APS_SERVICE_STATUS_IND_STRU */

    ID_MMC_APS_PS_REG_STATUS_IND  = TAFMMC_APS_PS_REG_STATUS_IND,

    /* 后面的枚举值不能直接递增，MMC有多种上报的消息 */

    ID_MMC_APS_MSG_ID_ENUM_BUTT

};
typedef VOS_UINT32 MMC_APS_MSG_ID_ENUM_UINT32;


/*****************************************************************************
  3 枚举定义
*****************************************************************************/

enum MMC_APS_RAT_TYPE_ENUM
{
    MMC_APS_RAT_TYPE_NULL,          /* 当前未在任何网络上驻留 */
    MMC_APS_RAT_TYPE_GSM,           /* GSM接入技术 */
    MMC_APS_RAT_TYPE_WCDMA,         /* WCDMA接入技术 */
    MMC_APS_RAT_TYPE_LTE,           /* LTE接入技术 */
    MMC_APS_RAT_TYPE_BUTT           /* 无效的接入技术 */
};
typedef VOS_UINT32 MMC_APS_RAT_TYPE_ENUM_UINT32;


enum MMC_APS_PS_REG_RESULT_ENUM
{
    MMC_APS_PS_REG_RESULT_SUCCESS    = 0,    /*PS域注册成功*/
    MMC_APS_PS_REG_RESULT_FAILURE    = 1,    /*PS域注册失败*/
    MMC_APS_PS_REG_RESULT_BUTT
};
typedef VOS_UINT32 MMC_APS_PS_REG_RESULT_ENUM_U32;

/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/

typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /* 消息头 */ /*_H2ASN_Skip*/
    MMC_APS_RAT_TYPE_ENUM_UINT32        enRatType;                              /* 查询返回的当前参数 */
    VOS_UINT32                          ulPsSimRegStatus;                       /* PS域SIM卡状态信息,VOS_TRUE:卡有效,VOS_FALSE:卡无效 */
}MMC_APS_SERVICE_STATUS_IND_STRU;


typedef struct
{
    VOS_UINT32                          ulMcc;                                  /* MCC,3 bytes */
    VOS_UINT32                          ulMnc;                                  /* MNC,2 or 3 bytes */
}MMC_APS_PLMN_ID_STRU;


typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /* 消息头 */ /*_H2ASN_Skip*/
    MMC_APS_PS_REG_RESULT_ENUM_U32      enPsRegResult;                          /* PS域注册结果 */
    MMC_APS_PLMN_ID_STRU                stPlmnId;                               /* 当前的PLMN ID */
}MMC_APS_PS_REG_STATUS_IND_STRU;

/*****************************************************************************
  8 UNION定义
*****************************************************************************/
/*****************************************************************************
  H2ASN顶级消息结构定义
*****************************************************************************/
typedef struct
{
    MMC_APS_MSG_ID_ENUM_UINT32          enMsgID;                /*_H2ASN_MsgChoice_Export MMC_APS_MSG_ID_ENUM_UINT32 */
                                                                /* 为了兼容NAS的消息头定义，所以转换ASN.MMC_APS_MSG_ID_ENUM_UINT32 */

    VOS_UINT8                           aucMsgBlock[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          MMC_APS_MSG_ID_ENUM_UINT32
    ****************************************************************************/
}MMC_APS_SND_INTERNAL_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    MMC_APS_SND_INTERNAL_DATA            stMsgData;
}MmcApsInterfacemsg_MSG;

/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/



#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of MmcApsInteraface.h */

