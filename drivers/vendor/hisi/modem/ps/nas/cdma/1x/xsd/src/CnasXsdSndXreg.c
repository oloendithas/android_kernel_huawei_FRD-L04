

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include  "vos.h"
#include  "xsd_xreg_pif.h"
#include  "CnasMain.h"
#include "cas_1x_idlectrl_proc_nas_pif.h"
#include "CnasXsdComFunc.h"
#include "Nas_Mem.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define THIS_FILE_ID                    PS_FILE_ID_CNAS_XSD_SND_XREG_C

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)

/*****************************************************************************
  2 全局变量定义
*****************************************************************************/


/*****************************************************************************
  3 函数实现
*****************************************************************************/
/*lint -save -e958*/

VOS_VOID CNAS_XSD_SndXregStartReq(VOS_VOID)
{
    XSD_XREG_START_REQ_STRU            *pstInternalMsg      = VOS_NULL_PTR;
    VOS_UINT32                          ulLen;

    /* 从内部消息队列中获取一个还没有使用的空间 */
    ulLen           = sizeof(XSD_XREG_START_REQ_STRU);

    pstInternalMsg  = (XSD_XREG_START_REQ_STRU *)CNAS_GetIntMsgSendBuf(UEPS_PID_XSD, ulLen);
    if (VOS_NULL_PTR == pstInternalMsg)
    {
        return;
    }

    /* 填充消息 */

    pstInternalMsg->ulSenderCpuId               = VOS_LOCAL_CPUID;
    pstInternalMsg->ulSenderPid                 = UEPS_PID_XSD;
    pstInternalMsg->ulReceiverCpuId             = VOS_LOCAL_CPUID;
    pstInternalMsg->ulReceiverPid               = UEPS_PID_XREG;

    pstInternalMsg->enMsgId                     = ID_XSD_XREG_START_REQ;
    pstInternalMsg->usOpId                      = 0;
    pstInternalMsg->ulLength                    = sizeof(XSD_XREG_START_REQ_STRU) - VOS_MSG_HEAD_LENGTH;

    /* 发送内部消息 */
    CNAS_SndInternalMsg(pstInternalMsg);

}


VOS_VOID CNAS_XSD_SndXregPowerOffReq(VOS_VOID)
{
    XSD_XREG_POWER_OFF_REQ_STRU        *pstInternalMsg      = VOS_NULL_PTR;
    VOS_UINT32                          ulLen;

    /* 从内部消息队列中获取一个还没有使用的空间 */
    ulLen           = sizeof(XSD_XREG_POWER_OFF_REQ_STRU);

    pstInternalMsg  = (XSD_XREG_POWER_OFF_REQ_STRU *)CNAS_GetIntMsgSendBuf(UEPS_PID_XSD, ulLen);
    if (VOS_NULL_PTR == pstInternalMsg)
    {
        return;
    }

    /* 填充消息 */

    pstInternalMsg->ulSenderCpuId               = VOS_LOCAL_CPUID;
    pstInternalMsg->ulSenderPid                 = UEPS_PID_XSD;
    pstInternalMsg->ulReceiverCpuId             = VOS_LOCAL_CPUID;
    pstInternalMsg->ulReceiverPid               = UEPS_PID_XREG;

    pstInternalMsg->enMsgId                     = ID_XSD_XREG_POWER_OFF_REQ;
    pstInternalMsg->usOpId                      = 0;
    pstInternalMsg->ulLength                    = sizeof(XSD_XREG_POWER_OFF_REQ_STRU) - VOS_MSG_HEAD_LENGTH;

    /* 发送内部消息 */
    CNAS_SndInternalMsg(pstInternalMsg);

}



VOS_VOID CNAS_XSD_SndXregDeregisterInd(
    XSD_XREG_DEREGISTER_REASON_ENUM_UINT8                   enCause
)
{
    XSD_XREG_DEREGISTER_IND_STRU                           *pstInternalMsg      = VOS_NULL_PTR;
    VOS_UINT32                                              ulLen;

    /* 从内部消息队列中获取一个还没有使用的空间 */
    ulLen           = sizeof(XSD_XREG_DEREGISTER_IND_STRU);

    pstInternalMsg  = (XSD_XREG_DEREGISTER_IND_STRU *)CNAS_GetIntMsgSendBuf(UEPS_PID_XSD, ulLen);
    if (VOS_NULL_PTR == pstInternalMsg)
    {
        return;
    }

    /* 填充消息 */

    pstInternalMsg->ulSenderCpuId               = VOS_LOCAL_CPUID;
    pstInternalMsg->ulSenderPid                 = UEPS_PID_XSD;
    pstInternalMsg->ulReceiverCpuId             = VOS_LOCAL_CPUID;
    pstInternalMsg->ulReceiverPid               = UEPS_PID_XREG;

    pstInternalMsg->enMsgId                     = ID_XSD_XREG_DEREGISTER_IND;
    pstInternalMsg->usOpId                      = 0;
    pstInternalMsg->ulLength                    = sizeof(XSD_XREG_DEREGISTER_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    pstInternalMsg->enCause                     = enCause;

    NAS_MEM_SET_S(pstInternalMsg->aucRsv, sizeof(pstInternalMsg->aucRsv), 0x0, sizeof(VOS_UINT8) * 3);

    /* 发送内部消息 */
    CNAS_SndInternalMsg(pstInternalMsg);

}



VOS_VOID CNAS_XSD_BuildXregSysInfoInd(
    CAS_CNAS_1X_OHM_IND_STRU           *pstCasCnas1xOhmInd,
    XSD_XREG_SYS_INFO_STRU             *pstXsdXregSysInfo
)
{
    pstXsdXregSysInfo->usBandClass                  = pstCasCnas1xOhmInd->usBandClass;
    pstXsdXregSysInfo->usFreq                       = pstCasCnas1xOhmInd->usFreq;
    pstXsdXregSysInfo->usSid                        = pstCasCnas1xOhmInd->usSid;
    pstXsdXregSysInfo->usNid                        = pstCasCnas1xOhmInd->usNid;
    pstXsdXregSysInfo->ucPacketZoneId               = pstCasCnas1xOhmInd->ucPacketZoneId;

    pstXsdXregSysInfo->enRegInfoIncl                = pstCasCnas1xOhmInd->enRegInfoIncl;
    pstXsdXregSysInfo->enBaseStationInfoIncl        = pstCasCnas1xOhmInd->enBaseStationInfoIncl;
    pstXsdXregSysInfo->enServiceInfoIncl            = pstCasCnas1xOhmInd->enServiceInfoIncl;

    pstXsdXregSysInfo->ucMaxSlotCycleIndex          = pstCasCnas1xOhmInd->ucMaxSlotCycleIndex;

    pstXsdXregSysInfo->ucPRevInUse                  = pstCasCnas1xOhmInd->ucPRevInUse;

    pstXsdXregSysInfo->stRegInfo.usRegZone          = pstCasCnas1xOhmInd->stRegInfo.usRegZone;
    pstXsdXregSysInfo->stRegInfo.ucRegZoneNum       = pstCasCnas1xOhmInd->stRegInfo.ucRegZoneNum;
    pstXsdXregSysInfo->stRegInfo.ucZoneTimer        = pstCasCnas1xOhmInd->stRegInfo.ucZoneTimer;
    pstXsdXregSysInfo->stRegInfo.ucMultiSidFlg      = pstCasCnas1xOhmInd->stRegInfo.ucMultiSidFlg;
    pstXsdXregSysInfo->stRegInfo.ucMultiNidFlg      = pstCasCnas1xOhmInd->stRegInfo.ucMultiNidFlg;
    pstXsdXregSysInfo->stRegInfo.usRegDistance      = pstCasCnas1xOhmInd->stRegInfo.usRegDistance;
    pstXsdXregSysInfo->stRegInfo.ucRegPeriod        = pstCasCnas1xOhmInd->stRegInfo.ucRegPeriod;
    pstXsdXregSysInfo->stRegInfo.ucHomeReg          = pstCasCnas1xOhmInd->stRegInfo.ucHomeReg;
    pstXsdXregSysInfo->stRegInfo.ucSidRoamReg       = pstCasCnas1xOhmInd->stRegInfo.ucSidRoamReg;
    pstXsdXregSysInfo->stRegInfo.ucNidRoamReg       = pstCasCnas1xOhmInd->stRegInfo.ucNidRoamReg;
    pstXsdXregSysInfo->stRegInfo.ucPowerUpReg       = pstCasCnas1xOhmInd->stRegInfo.ucPowerUpReg;
    pstXsdXregSysInfo->stRegInfo.ucPowerDownReg     = pstCasCnas1xOhmInd->stRegInfo.ucPowerDownReg;
    pstXsdXregSysInfo->stRegInfo.ucParameterReg     = pstCasCnas1xOhmInd->stRegInfo.ucParameterReg;


    pstXsdXregSysInfo->stBaseStationInfo.usBaseId        = pstCasCnas1xOhmInd->stBaseStationInfo.usBaseId;
    pstXsdXregSysInfo->stBaseStationInfo.ucBaseClass     = pstCasCnas1xOhmInd->stBaseStationInfo.ucBaseClass;
    pstXsdXregSysInfo->stBaseStationInfo.lBaseLatitude   = pstCasCnas1xOhmInd->stBaseStationInfo.lBaseLatitude;
    pstXsdXregSysInfo->stBaseStationInfo.lBaseLongitude  = pstCasCnas1xOhmInd->stBaseStationInfo.lBaseLongitude;

    pstXsdXregSysInfo->stServiceInfo.ucMaxAltSo            = pstCasCnas1xOhmInd->stServiceInfo.ucMaxAltSo;
    pstXsdXregSysInfo->stServiceInfo.ucSDBSupported        = pstCasCnas1xOhmInd->stServiceInfo.ucSDBSupported;
    pstXsdXregSysInfo->stServiceInfo.ucMoQos               = pstCasCnas1xOhmInd->stServiceInfo.ucMoQos;
    pstXsdXregSysInfo->stServiceInfo.ucConcurrentSupported = pstCasCnas1xOhmInd->stServiceInfo.ucConcurrentSupported;
    pstXsdXregSysInfo->stServiceInfo.ucMoPosSupported      = pstCasCnas1xOhmInd->stServiceInfo.ucMoPosSupported;
    pstXsdXregSysInfo->stServiceInfo.ulMcc                 = CNAS_XSD_TransformMccToBcd(pstCasCnas1xOhmInd->stServiceInfo.usMcc);
    pstXsdXregSysInfo->stServiceInfo.usImsi11_12           = CNAS_XSD_TransformImsiToBcd(pstCasCnas1xOhmInd->stServiceInfo.ucImsi11_12);

    return;
}


VOS_VOID CNAS_XSD_SndXregSysInfoInd(
    XSD_XREG_SERVICE_STATUS_ENUM_UINT32                     enSrvSta,
    XSD_XREG_SYS_INFO_STRU                                 *pstSysInfo
)
{
    XSD_XREG_SYS_INFO_IND_STRU         *pstInternalMsg = VOS_NULL_PTR;
    VOS_UINT32                          ulLen;

    /* 从内部消息队列中获取一个还没有使用的空间 */
    ulLen           = sizeof(XSD_XREG_SYS_INFO_IND_STRU);

    pstInternalMsg  = (XSD_XREG_SYS_INFO_IND_STRU *)CNAS_GetIntMsgSendBuf(UEPS_PID_XSD, ulLen);
    if (VOS_NULL_PTR == pstInternalMsg)
    {
        return ;
    }

    /* 填充消息 */

    pstInternalMsg->ulSenderCpuId               = VOS_LOCAL_CPUID;
    pstInternalMsg->ulSenderPid                 = UEPS_PID_XSD;
    pstInternalMsg->ulReceiverCpuId             = VOS_LOCAL_CPUID;
    pstInternalMsg->ulReceiverPid               = UEPS_PID_XREG;
    pstInternalMsg->enMsgId                     = ID_XSD_XREG_SYS_INFO_IND;
    pstInternalMsg->usOpId                      = 0;
    pstInternalMsg->ulLength                    = sizeof(XSD_XREG_SYS_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH;
    pstInternalMsg->enServiceStatus             = enSrvSta;

    NAS_MEM_CPY_S(&(pstInternalMsg->stSysInfo), sizeof(pstInternalMsg->stSysInfo), pstSysInfo, sizeof(XSD_XREG_SYS_INFO_STRU));

    /* 发送内部消息 */
    CNAS_SndInternalMsg(pstInternalMsg);

}



VOS_VOID CNAS_XSD_SndXregRedirInd(VOS_VOID)
{
    XSD_XREG_REDIRECTION_IND_STRU      *pstInternalMsg      = VOS_NULL_PTR;
    VOS_UINT32                          ulLen;

    /* 从内部消息队列中获取一个还没有使用的空间 */
    ulLen           = sizeof(XSD_XREG_REDIRECTION_IND_STRU);

    pstInternalMsg  = (XSD_XREG_REDIRECTION_IND_STRU *)CNAS_GetIntMsgSendBuf(UEPS_PID_XSD, ulLen);
    if (VOS_NULL_PTR == pstInternalMsg)
    {
        return;
    }

    /* 填充消息 */

    pstInternalMsg->ulSenderCpuId               = VOS_LOCAL_CPUID;
    pstInternalMsg->ulSenderPid                 = UEPS_PID_XSD;
    pstInternalMsg->ulReceiverCpuId             = VOS_LOCAL_CPUID;
    pstInternalMsg->ulReceiverPid               = UEPS_PID_XREG;

    pstInternalMsg->enMsgId                     = ID_XSD_XREG_REDIRECTION_IND;
    pstInternalMsg->usOpId                      = 0;
    pstInternalMsg->ulLength                    = sizeof(XSD_XREG_REDIRECTION_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    /* 发送内部消息 */
    CNAS_SndInternalMsg(pstInternalMsg);

}




VOS_VOID CNAS_XSD_SndXregUeStateInd(
    CAS_CNAS_1X_CAS_STATE_ENUM_UINT8                        enCasState,
    CAS_CNAS_1X_CAS_SUB_STATE_ENUM_UINT8                    enCasSubState
)
{
    XSD_XREG_UE_STATE_IND_STRU         *pstInternalMsg      = VOS_NULL_PTR;
    VOS_UINT32                          ulLen;

    /* 从内部消息队列中获取一个还没有使用的空间 */
    ulLen           = sizeof(XSD_XREG_UE_STATE_IND_STRU);

    pstInternalMsg  = (XSD_XREG_UE_STATE_IND_STRU *)CNAS_GetIntMsgSendBuf(UEPS_PID_XSD, ulLen);
    if (VOS_NULL_PTR == pstInternalMsg)
    {
        return;
    }

    /* 填充消息 */

    pstInternalMsg->ulSenderCpuId               = VOS_LOCAL_CPUID;
    pstInternalMsg->ulSenderPid                 = UEPS_PID_XSD;
    pstInternalMsg->ulReceiverCpuId             = VOS_LOCAL_CPUID;
    pstInternalMsg->ulReceiverPid               = UEPS_PID_XREG;

    pstInternalMsg->enMsgId                     = ID_XSD_XREG_UE_STATE_IND;
    pstInternalMsg->usOpId                      = 0;
    pstInternalMsg->ulLength                    = sizeof(XSD_XREG_UE_STATE_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    pstInternalMsg->enCasState                  = enCasState;
    pstInternalMsg->enCasSubState               = enCasSubState;

    /* 发送内部消息 */
    CNAS_SndInternalMsg(pstInternalMsg);

    return;

}



VOS_VOID CNAS_XSD_SndXregNormalServiceInd(
    VOS_UINT32                                              ulMcc,
    VOS_RATMODE_ENUM_UINT32                                 ulRatType
)
{
    XSD_XREG_NORMAL_SERVICE_IND_STRU         *pstInternalMsg      = VOS_NULL_PTR;
    VOS_UINT32                                ulLen;

    /* 从内部消息队列中获取一个还没有使用的空间 */
    ulLen           = sizeof(XSD_XREG_NORMAL_SERVICE_IND_STRU);

    pstInternalMsg  = (XSD_XREG_NORMAL_SERVICE_IND_STRU *)CNAS_GetIntMsgSendBuf(UEPS_PID_XSD, ulLen);
    if (VOS_NULL_PTR == pstInternalMsg)
    {
        return;
    }

    /* 填充消息 */

    pstInternalMsg->ulSenderCpuId               = VOS_LOCAL_CPUID;
    pstInternalMsg->ulSenderPid                 = UEPS_PID_XSD;
    pstInternalMsg->ulReceiverCpuId             = VOS_LOCAL_CPUID;
    pstInternalMsg->ulReceiverPid               = UEPS_PID_XREG;

    pstInternalMsg->enMsgId                     = ID_XSD_XREG_NORMAL_SERVICE_IND;
    pstInternalMsg->ulLength                    = sizeof(XSD_XREG_NORMAL_SERVICE_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    pstInternalMsg->ulMcc                       = ulMcc;
    pstInternalMsg->ulRatMode                   = ulRatType;

    /* 发送内部消息 */
    CNAS_SndInternalMsg(pstInternalMsg);

    return;
}

/*lint -restore*/

#endif







#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

