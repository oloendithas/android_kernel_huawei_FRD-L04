

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include  "CnasHsdSndMscc.h"
#include  "PsCommonDef.h"
#include  "CnasMntn.h"
#include  "CnasHsdComFunc.h"

#include  "hsm_hsd_pif.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define THIS_FILE_ID                    PS_FILE_ID_CNAS_HSD_SND_MSCC_C

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)

/*****************************************************************************
  2 全局变量定义
*****************************************************************************/


/*****************************************************************************
  3 函数实现
*****************************************************************************/
/*lint -save -e958*/

VOS_VOID CNAS_HSD_SndMsccStartCnf(
    HSD_MSCC_START_RESULT_ENUM_UINT32    enRslt
)
{
    HSD_MSCC_START_CNF_STRU            *pstStartCnf  = VOS_NULL_PTR;

    /* 分配消息 */
    pstStartCnf = (HSD_MSCC_START_CNF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                         sizeof(HSD_MSCC_START_CNF_STRU));
    if (VOS_NULL_PTR == pstStartCnf)
    {
        return;
    }

    /* 填充消息 */
    pstStartCnf->stMsgHeader.ulReceiverPid      = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstStartCnf->stMsgHeader.ulMsgName          = ID_HSD_MSCC_START_CNF;
    pstStartCnf->enRslt                         = enRslt;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstStartCnf);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstStartCnf);

    return;
}


VOS_VOID CNAS_HSD_SndMsccPowerOffCnf(VOS_VOID)
{
    HSD_MSCC_POWER_OFF_CNF_STRU         *pstPowerOffCnf  = VOS_NULL_PTR;

    /* 分配消息 */
    pstPowerOffCnf = (HSD_MSCC_POWER_OFF_CNF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                                sizeof(HSD_MSCC_POWER_OFF_CNF_STRU));
    if (VOS_NULL_PTR == pstPowerOffCnf)
    {
        return;
    }

    /* 填充消息 */
    pstPowerOffCnf->stMsgHeader.ulReceiverPid   = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstPowerOffCnf->stMsgHeader.ulMsgName       = ID_HSD_MSCC_POWER_OFF_CNF;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstPowerOffCnf);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstPowerOffCnf);

    return;
}


VOS_VOID CNAS_HSD_SndMsccSysAcqCnf(NAS_MSCC_PIF_ACQUIRED_RESULT_ENUM_UINT32 enRslt)
{
    HSD_MSCC_SYSTEM_ACQUIRE_CNF_STRU    *pstSysAcqCnf;

    /* 分配消息 */
    pstSysAcqCnf = (HSD_MSCC_SYSTEM_ACQUIRE_CNF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                                   sizeof(HSD_MSCC_SYSTEM_ACQUIRE_CNF_STRU));
    if (VOS_NULL_PTR == pstSysAcqCnf)
    {
        return;
    }

    /* 填充消息 */
    pstSysAcqCnf->stMsgHeader.ulReceiverPid          = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstSysAcqCnf->stMsgHeader.ulMsgName              = ID_HSD_MSCC_SYSTEM_ACQUIRE_CNF;
    pstSysAcqCnf->enRslt                 = enRslt;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstSysAcqCnf);

    CNAS_HSD_LogMsgInfo((MSG_HEADER_STRU*)pstSysAcqCnf);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstSysAcqCnf);

    return;
}


VOS_VOID CNAS_HSD_SndMsccSysAcqInd(NAS_MSCC_PIF_ACQUIRED_RESULT_ENUM_UINT32 enRslt)
{
    HSD_MSCC_SYSTEM_ACQUIRE_END_IND_STRU                   *pstSysAcqInd;

    /* 分配消息 */
    pstSysAcqInd = (HSD_MSCC_SYSTEM_ACQUIRE_END_IND_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                                   sizeof(HSD_MSCC_SYSTEM_ACQUIRE_END_IND_STRU));
    if (VOS_NULL_PTR == pstSysAcqInd)
    {
        return;
    }

    /* 填充消息 */
    pstSysAcqInd->stMsgHeader.ulReceiverPid     = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstSysAcqInd->stMsgHeader.ulMsgName         = ID_HSD_MSCC_SYSTEM_ACQUIRE_END_IND;
    pstSysAcqInd->enRslt                        = enRslt;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstSysAcqInd);

    CNAS_HSD_LogMsgInfo((MSG_HEADER_STRU*)pstSysAcqInd);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstSysAcqInd);

    return;
}


VOS_VOID CNAS_HSD_SndMsccSysAcqStartInd(VOS_VOID)
{
    HSD_MSCC_SYSTEM_ACQUIRE_START_IND_STRU                  *pstSysAcqStartInd;

    /* 分配消息 */
    pstSysAcqStartInd = (HSD_MSCC_SYSTEM_ACQUIRE_START_IND_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                                              sizeof(HSD_MSCC_SYSTEM_ACQUIRE_START_IND_STRU));
    if (VOS_NULL_PTR == pstSysAcqStartInd)
    {
        return;
    }

    /* 填充消息 */
    pstSysAcqStartInd->stMsgHeader.ulReceiverPid    = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstSysAcqStartInd->stMsgHeader.ulMsgName        = ID_HSD_MSCC_SYSTEM_ACQUIRE_START_IND;

    CNAS_HSD_LogMsgInfo((MSG_HEADER_STRU*)pstSysAcqStartInd);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstSysAcqStartInd);

    return;
}


VOS_VOID CNAS_HSD_SndMsccHrpdIratToLteNtf(VOS_VOID)
{
    HSD_MSCC_HRPD_IRAT_TO_LTE_NTF_STRU  *pstHrpdIratToLteNtf;

    /* 分配消息 */
    pstHrpdIratToLteNtf = (HSD_MSCC_HRPD_IRAT_TO_LTE_NTF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                                            sizeof(HSD_MSCC_HRPD_IRAT_TO_LTE_NTF_STRU));
    if (VOS_NULL_PTR == pstHrpdIratToLteNtf)
    {
        return;
    }

    /* 填充消息 */
    pstHrpdIratToLteNtf->stMsgHeader.ulReceiverPid  = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstHrpdIratToLteNtf->stMsgHeader.ulMsgName      = ID_HSD_MSCC_HRPD_IRAT_TO_LTE_NTF;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstHrpdIratToLteNtf);

    CNAS_HSD_LogMsgInfo((MSG_HEADER_STRU*)pstHrpdIratToLteNtf);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstHrpdIratToLteNtf);

    return;
}


VOS_VOID CNAS_HSD_SndMsccDataCallRedialSysAcqCnf(NAS_MSCC_PIF_ACQUIRED_RESULT_ENUM_UINT32 enRslt)
{
    HSD_MSCC_DATA_CALL_REDIAL_SYS_ACQ_CNF_STRU  *pstDataCallSysAcqCnf;

    /* 分配消息 */
    pstDataCallSysAcqCnf = (HSD_MSCC_DATA_CALL_REDIAL_SYS_ACQ_CNF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                                            sizeof(HSD_MSCC_DATA_CALL_REDIAL_SYS_ACQ_CNF_STRU));
    if (VOS_NULL_PTR == pstDataCallSysAcqCnf)
    {
        return;
    }

    /* 填充消息 */
    pstDataCallSysAcqCnf->stMsgHeader.ulReceiverPid     = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstDataCallSysAcqCnf->stMsgHeader.ulMsgName         = ID_HSD_MSCC_DATA_CALL_REDIAL_SYS_ACQ_CNF;
    pstDataCallSysAcqCnf->enRslt                        = enRslt;
    pstDataCallSysAcqCnf->ucIsEhrpdSupport              = VOS_FALSE;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstDataCallSysAcqCnf);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstDataCallSysAcqCnf);

    return;
}


VOS_VOID CNAS_HSD_SndMsccSessionNegRsltInd(
    VOS_UINT8                                   ucNegRslt,
    VOS_UINT8                                   ucIsNewSession,
    HSD_MSCC_SESSION_RELEASE_TYPE_ENUM_UINT32   enCurrSessionRelType,
    VOS_UINT8                                   ucIsEhrpdSupport
)
{
    HSD_MSCC_SESSION_NEG_RSLT_IND_STRU                     *pstSessionInfo;
    HSD_MSCC_SESSION_NEG_RSLT_ENUM_UINT32                   enRslt;

    /* 分配消息 */
    pstSessionInfo = (HSD_MSCC_SESSION_NEG_RSLT_IND_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                    sizeof(HSD_MSCC_SESSION_NEG_RSLT_IND_STRU));
    if (VOS_NULL_PTR == pstSessionInfo)
    {
        return;
    }

    if (HSM_HSD_SESSION_NEG_RSLT_SUCCESS == ucNegRslt)
    {
        enRslt = HSD_MSCC_SESSION_NEG_RESULT_SUCC;
    }
    else if (HSM_HSD_SESSION_NEG_RSLT_NO_RF == ucNegRslt)
    {
        enRslt = HSD_MSCC_SESSION_NEG_RESULT_NO_RF;
    }
    else
    {
        enRslt = HSD_MSCC_SESSION_NEG_RESULT_FAIL;
    }

    /* 填充消息 */
    pstSessionInfo->stMsgHeader.ulReceiverPid       = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);;
    pstSessionInfo->stMsgHeader.ulMsgName           = ID_HSD_MSCC_SESSION_NEG_RSLT_IND;
    pstSessionInfo->enRslt                          = enRslt;
    pstSessionInfo->ucIsNewSession                  = ucIsNewSession;
    pstSessionInfo->enCurrSessionRelType            = enCurrSessionRelType;

    pstSessionInfo->ucIsEhrpdSupport                = ucIsEhrpdSupport;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstSessionInfo);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstSessionInfo);

    return;
}



VOS_VOID CNAS_HSD_SndMsccOverheadMsgInd(
    CAS_CNAS_HRPD_OVERHEAD_MSG_IND_STRU                    *pstCasOhmMsg,
    CNAS_PRL_HRPD_SYSTEM_STRU                              *pstHrpdSys
)
{
    HSD_MSCC_OVERHEAD_MSG_IND_STRU      *pstOhmInd;

    /* 分配消息 */
    pstOhmInd = (HSD_MSCC_OVERHEAD_MSG_IND_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                    sizeof(HSD_MSCC_OVERHEAD_MSG_IND_STRU));
    if (VOS_NULL_PTR == pstOhmInd)
    {
        return;
    }

    /* 填充消息 */
    pstOhmInd->stMsgHeader.ulReceiverPid = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstOhmInd->stMsgHeader.ulMsgName     = ID_HSD_MSCC_OVERHEAD_MSG_IND;

    pstOhmInd->usBandClass               = pstCasOhmMsg->usBandClass;
    pstOhmInd->usFreq                    = pstCasOhmMsg->usFreq;
    pstOhmInd->ulMcc                     = CNAS_HSD_ConvertHrpdMccToNasMcc(pstCasOhmMsg->usCountryCode);
    pstOhmInd->ucUATIColorCode           = pstCasOhmMsg->ucColorCode;
    pstOhmInd->ucSubNetMask              = pstCasOhmMsg->ucSubNetMask;
    pstOhmInd->ucSecondaryColorCodeCount = pstCasOhmMsg->ucSecondaryColorCodeCount;
    pstOhmInd->lLongitude                = pstCasOhmMsg->lLongitude;
    pstOhmInd->lLatitude                 = pstCasOhmMsg->lLatitude;
    pstOhmInd->ulSector24                = pstCasOhmMsg->ulSector24;


    pstOhmInd->ucPriClass_AI                              = CNAS_HSD_GetPriClassWithTypeAI(pstHrpdSys);
    pstOhmInd->ucPriClass_HRPD                            = CNAS_HSD_GetPriClassWithTypeHRPD(pstHrpdSys);

    NAS_MEM_CPY_S(pstOhmInd->aucSectorId,
                  HSD_MSCC_SUBNET_ID_MAX_LENGTH,
                  pstCasOhmMsg->aucSectorId,
                  CAS_CNAS_SUBNET_ID_MAX_LENGTH);

    NAS_MEM_CPY_S(pstOhmInd->aucSecondaryColorCode,
                  HSD_MSCC_SECOND_COLORCODE_MAX_LENGTH,
                  pstCasOhmMsg->aucSecondaryColorCode,
                  CAS_CNAS_SECOND_COLORCODE_MAX_LENGTH);

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstOhmInd);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstOhmInd);

    return;
}


VOS_VOID CNAS_HSD_SndMsccSysCfgCnf(
    CAS_CNAS_HRPD_SYS_CFG_CNF_STRU     *pstRcvMsg
)
{
    HSD_MSCC_SYS_CFG_CNF_STRU          *pstSysCfgCnf = VOS_NULL_PTR;

    /* 分配消息 */
    pstSysCfgCnf = (HSD_MSCC_SYS_CFG_CNF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                             sizeof(HSD_MSCC_SYS_CFG_CNF_STRU));
    if (VOS_NULL_PTR == pstSysCfgCnf)
    {
        return;
    }

    NAS_MEM_SET_S(pstSysCfgCnf, sizeof(HSD_MSCC_SYS_CFG_CNF_STRU), 0, sizeof(HSD_MSCC_SYS_CFG_CNF_STRU));

    pstSysCfgCnf->stMsgHeader.ulSenderPid     = UEPS_PID_HSD;
    pstSysCfgCnf->stMsgHeader.ulSenderCpuId   = VOS_LOCAL_CPUID;
    pstSysCfgCnf->stMsgHeader.ulReceiverPid   = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstSysCfgCnf->stMsgHeader.ulReceiverCpuId = VOS_LOCAL_CPUID;
    pstSysCfgCnf->stMsgHeader.ulLength        = sizeof(HSD_MSCC_SYS_CFG_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    pstSysCfgCnf->usOpId                      = pstRcvMsg->usOpId;
    pstSysCfgCnf->stMsgHeader.ulMsgName       = ID_HSD_MSCC_SYS_CFG_CNF;

    pstSysCfgCnf->enRst                       = NAS_MSCC_PIF_SYS_CFG_SET_SUCCESS;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstSysCfgCnf);

    CNAS_HSD_LogMsgInfo((MSG_HEADER_STRU*)pstSysCfgCnf);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstSysCfgCnf);

}


VOS_VOID CNAS_HSD_SndMsccPowerSaveCnf(
    NAS_MSCC_PIF_POWER_SAVE_RESULT_ENUM_UINT8               enRslt
)
{
    HSD_MSCC_POWER_SAVE_CNF_STRU         *pstPowerSaveCnf  = VOS_NULL_PTR;

    /* 分配消息 */
    pstPowerSaveCnf = (HSD_MSCC_POWER_SAVE_CNF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                                sizeof(HSD_MSCC_POWER_SAVE_CNF_STRU));
    if (VOS_NULL_PTR == pstPowerSaveCnf)
    {
        return;
    }

    /* 填充消息 */
    pstPowerSaveCnf->stMsgHeader.ulReceiverPid   = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstPowerSaveCnf->stMsgHeader.ulMsgName       = ID_HSD_MSCC_POWER_SAVE_CNF;
    pstPowerSaveCnf->usOpId                      = 0;
    pstPowerSaveCnf->enResult                    = enRslt;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstPowerSaveCnf);

    CNAS_HSD_LogMsgInfo((MSG_HEADER_STRU*)pstPowerSaveCnf);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstPowerSaveCnf);

    return;
}


VOS_VOID CNAS_HSD_SndMsccBgSearchCnf(
    CAS_CNAS_HRPD_BSR_LTE_CNF_STRU     *pstMsg
)
{
    HSD_MSCC_BG_SEARCH_CNF_STRU        *pstBgSearchCnf  = VOS_NULL_PTR;

    /* 分配消息 */
    pstBgSearchCnf = (HSD_MSCC_BG_SEARCH_CNF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                                sizeof(HSD_MSCC_BG_SEARCH_CNF_STRU));
    if (VOS_NULL_PTR == pstBgSearchCnf)
    {
        return;
    }

    /* 填充消息 */
    pstBgSearchCnf->stMsgHeader.ulReceiverPid   = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstBgSearchCnf->stMsgHeader.ulMsgName       = ID_HSD_MSCC_BG_SEARCH_CNF;
    pstBgSearchCnf->usOpId                      = 0;
    pstBgSearchCnf->enRslt                      = pstMsg->ucRslt;

    pstBgSearchCnf->stPlmnList.enRat         = NAS_MSCC_PIF_NET_RAT_TYPE_LTE;
    pstBgSearchCnf->stPlmnList.ucHighPlmnNum = CNAS_MIN(pstMsg->ucHighPlmnNum, CNAS_CAS_HRPD_BSR_LTE_MAX_HIGH_PLMN_NUM);
    pstBgSearchCnf->stPlmnList.ucLowPlmnNum  = CNAS_MIN(pstMsg->ucLowPlmnNum, CNAS_CAS_HRPD_BSR_LTE_MAX_LOW_PLMN_NUM);

    if (CNAS_CAS_HRPD_BSR_RSLT_SUCC == pstMsg->ucRslt)
    {
        CNAS_HSD_ConvertLmmPlmnToGUNasPlmn(pstBgSearchCnf->stPlmnList.ucHighPlmnNum,
                                           pstMsg->astHighPlmnList,
                                           pstBgSearchCnf->stPlmnList.astHighPlmnID);

        CNAS_HSD_ConvertLmmPlmnToGUNasPlmn(pstBgSearchCnf->stPlmnList.ucLowPlmnNum,
                                           pstMsg->astLowPlmnList,
                                           pstBgSearchCnf->stPlmnList.astLowPlmnID);

    }

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstBgSearchCnf);

    CNAS_HSD_LogMsgInfo((MSG_HEADER_STRU*)pstBgSearchCnf);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstBgSearchCnf);

    return;
}


VOS_VOID CNAS_HSD_SndMsccHrpdSysInfoCnf(
    VOS_UINT8                            ucHrpdSysNum,
    MSCC_HSD_HRPD_SYS_INFO_STRU         *pstHrpdSysInfoList
)
{
    HSD_MSCC_QRY_HRPD_SYS_INFO_CNF_STRU        *pstHrpdSysInfoCnf  = VOS_NULL_PTR;

    /* 分配消息 */
    pstHrpdSysInfoCnf = (HSD_MSCC_QRY_HRPD_SYS_INFO_CNF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                                sizeof(HSD_MSCC_QRY_HRPD_SYS_INFO_CNF_STRU));
    if (VOS_NULL_PTR == pstHrpdSysInfoCnf)
    {
        return;
    }

    /* 填充消息 */
    pstHrpdSysInfoCnf->stMsgHeader.ulReceiverPid   = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstHrpdSysInfoCnf->stMsgHeader.ulMsgName       = ID_HSD_MSCC_QRY_HRPD_SYS_INFO_CNF;
    pstHrpdSysInfoCnf->usOpId                      = 0;
    pstHrpdSysInfoCnf->ucHrpdSysNum                = ucHrpdSysNum;

    NAS_MEM_CPY_S(pstHrpdSysInfoCnf->astHrpdSysInfoList,
                  sizeof(MSCC_HSD_HRPD_SYS_INFO_STRU) * MSCC_HSD_BG_HRPD_MAX_SYS_NUM,
                  pstHrpdSysInfoList,
                  sizeof(MSCC_HSD_HRPD_SYS_INFO_STRU) * ucHrpdSysNum);

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstHrpdSysInfoCnf);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstHrpdSysInfoCnf);

    return;
}


VOS_VOID CNAS_HSD_SndMsccStopBgSearchCnf(VOS_VOID)
{
    HSD_MSCC_STOP_BG_SEARCH_CNF_STRU                        *pstStopBgSearchCnf  = VOS_NULL_PTR;

    /* 分配消息 */
    pstStopBgSearchCnf = (HSD_MSCC_STOP_BG_SEARCH_CNF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                        sizeof(HSD_MSCC_STOP_BG_SEARCH_CNF_STRU));
    if (VOS_NULL_PTR == pstStopBgSearchCnf)
    {
        return;
    }

    /* 填充消息 */
    pstStopBgSearchCnf->stMsgHeader.ulReceiverPid   = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstStopBgSearchCnf->stMsgHeader.ulMsgName       = ID_HSD_MSCC_STOP_BG_SEARCH_CNF;
    pstStopBgSearchCnf->usOpId                      = 0;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstStopBgSearchCnf);

    CNAS_HSD_LogMsgInfo((MSG_HEADER_STRU*)pstStopBgSearchCnf);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstStopBgSearchCnf);

    return;
}


VOS_VOID CNAS_HSD_SndMsccSystemSyncInd(VOS_VOID)
{
    HSD_MSCC_SYSTEM_SYNC_IND_STRU      *pstSyncInd  = VOS_NULL_PTR;

    /* 分配消息 */
    pstSyncInd = (HSD_MSCC_SYSTEM_SYNC_IND_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                                sizeof(HSD_MSCC_SYSTEM_SYNC_IND_STRU));
    if (VOS_NULL_PTR == pstSyncInd)
    {
        return;
    }

    /* 填充消息 */
    pstSyncInd->stMsgHeader.ulReceiverPid   = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstSyncInd->stMsgHeader.ulMsgName       = ID_HSD_MSCC_SYSTEM_SYNC_IND;
    pstSyncInd->usOpId                      = 0;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstSyncInd);

    CNAS_HSD_LogMsgInfo((MSG_HEADER_STRU*)pstSyncInd);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstSyncInd);

    return;
}


VOS_VOID CNAS_HSD_SndMsccHrpdCasStatusInd(
    HSD_MSCC_HRPD_CAS_STATUS_ENUM_UINT16                    enHrpdCasStatus
)
{
    HSD_MSCC_CAS_STATUS_IND_STRU       *pstHsdMsccCasStatusInd   = VOS_NULL_PTR;

    pstHsdMsccCasStatusInd = (HSD_MSCC_CAS_STATUS_IND_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                    sizeof(HSD_MSCC_CAS_STATUS_IND_STRU));

    if (VOS_NULL_PTR == pstHsdMsccCasStatusInd)
    {
        return;
    }

    pstHsdMsccCasStatusInd->stMsgHeader.ulReceiverPid      = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstHsdMsccCasStatusInd->stMsgHeader.ulMsgName          = ID_HSD_MSCC_CAS_STATUS_IND;

    pstHsdMsccCasStatusInd->enCasStatus                    = enHrpdCasStatus;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstHsdMsccCasStatusInd);

    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstHsdMsccCasStatusInd);
}



VOS_VOID CNAS_HSD_SndMsccInterSysStartInd(
    VOS_RATMODE_ENUM_UINT32                                 enOrignRatMode,
    VOS_RATMODE_ENUM_UINT32                                 enDestRatMode,
    NAS_MSCC_PIF_INTERSYS_CAUSE_ENUM_UINT32                 enInterSysCause
)
{
    HSD_MSCC_INTERSYS_START_IND_STRU   *pstInterSysStaInd  = VOS_NULL_PTR;

    /* 分配消息 */
    pstInterSysStaInd = (HSD_MSCC_INTERSYS_START_IND_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                                sizeof(HSD_MSCC_INTERSYS_START_IND_STRU));
    if (VOS_NULL_PTR == pstInterSysStaInd)
    {
        return;
    }

    /* 填充消息 */
    pstInterSysStaInd->stMsgHeader.ulReceiverPid    = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstInterSysStaInd->stMsgHeader.ulMsgName        = ID_HSD_MSCC_INTERSYS_START_IND;
    pstInterSysStaInd->usOpId                       = 0;
    pstInterSysStaInd->enOrignRatMode               = enOrignRatMode;
    pstInterSysStaInd->enDestRatMode                = enDestRatMode;
    pstInterSysStaInd->enInterSysCause              = enInterSysCause;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstInterSysStaInd);

    CNAS_HSD_LogMsgInfo((MSG_HEADER_STRU*)pstInterSysStaInd);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstInterSysStaInd);

    return;
}


VOS_VOID CNAS_HSD_SndMsccInterSysEndInd(
    VOS_RATMODE_ENUM_UINT32             enCurrRatMode
)
{
    HSD_MSCC_INTERSYS_END_IND_STRU     *pstInterSysEndInd  = VOS_NULL_PTR;

    /* 分配消息 */
    pstInterSysEndInd = (HSD_MSCC_INTERSYS_END_IND_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                                                                sizeof(HSD_MSCC_INTERSYS_END_IND_STRU));
    if (VOS_NULL_PTR == pstInterSysEndInd)
    {
        return;
    }

    /* 填充消息 */
    pstInterSysEndInd->stMsgHeader.ulReceiverPid    = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstInterSysEndInd->stMsgHeader.ulMsgName        = ID_HSD_MSCC_INTERSYS_END_IND;
    pstInterSysEndInd->usOpId                       = 0;
    pstInterSysEndInd->enCurrRatMode                = enCurrRatMode;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstInterSysEndInd);

    CNAS_HSD_LogMsgInfo((MSG_HEADER_STRU*)pstInterSysEndInd);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstInterSysEndInd);

    return;
}


VOS_VOID CNAS_HSD_SndMsccRfAvailInd(
    VOS_UINT8                           ucRfAvail
)
{
    NAS_MSCC_PIF_RF_AVAILABLE_IND_STRU *pstRfAvailInd = VOS_NULL_PTR;
    VOS_UINT32                          ulMsgLength;

    ulMsgLength     = sizeof(NAS_MSCC_PIF_RF_AVAILABLE_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    pstRfAvailInd   = (NAS_MSCC_PIF_RF_AVAILABLE_IND_STRU *)PS_ALLOC_MSG(UEPS_PID_HSD, ulMsgLength);

    if (VOS_NULL_PTR == pstRfAvailInd)
    {
        return;
    }

    NAS_MEM_SET_S(((VOS_UINT8 *)pstRfAvailInd) + VOS_MSG_HEAD_LENGTH, ulMsgLength, 0x00, ulMsgLength);

    pstRfAvailInd->stMsgHeader.ulMsgName           = ID_HSD_MSCC_RF_AVAILABLE_IND;
    pstRfAvailInd->stMsgHeader.ulSenderCpuId       = VOS_LOCAL_CPUID;
    pstRfAvailInd->stMsgHeader.ulSenderPid         = UEPS_PID_HSD;
    pstRfAvailInd->stMsgHeader.ulReceiverCpuId     = VOS_LOCAL_CPUID;
    pstRfAvailInd->stMsgHeader.ulReceiverPid       = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstRfAvailInd->stMsgHeader.ulLength            = ulMsgLength;
    pstRfAvailInd->ucRfAvailFlg                    = ucRfAvail;
    pstRfAvailInd->enRatType                       = NAS_MSCC_PIF_RF_AVAILABLE_RAT_TYPE_HRPD;

    CNAS_HSD_LogMsgInfo((MSG_HEADER_STRU*)pstRfAvailInd);

    PS_SEND_MSG(UEPS_PID_HSD, pstRfAvailInd);

    return;
}



VOS_VOID CNAS_HSD_SndMsccHrpdNoSrvInd(VOS_VOID)
{
    HSD_MSCC_HRPD_NO_SERVICE_IND_STRU                      *pstRptHrpdNoSrvInd = VOS_NULL_PTR;
    VOS_UINT32                                              ulMsgLength;

    ulMsgLength          = sizeof(HSD_MSCC_HRPD_NO_SERVICE_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    pstRptHrpdNoSrvInd   = (HSD_MSCC_HRPD_NO_SERVICE_IND_STRU *)PS_ALLOC_MSG(UEPS_PID_HSD, ulMsgLength);

    if (VOS_NULL_PTR == pstRptHrpdNoSrvInd)
    {
        return;
    }

    NAS_MEM_SET_S(((VOS_UINT8 *)pstRptHrpdNoSrvInd) + VOS_MSG_HEAD_LENGTH, ulMsgLength, 0x00, ulMsgLength);

    pstRptHrpdNoSrvInd->stMsgHeader.ulMsgName           = ID_HSD_MSCC_HRPD_NO_SERVICE_IND;
    pstRptHrpdNoSrvInd->stMsgHeader.ulSenderCpuId       = VOS_LOCAL_CPUID;
    pstRptHrpdNoSrvInd->stMsgHeader.ulSenderPid         = UEPS_PID_HSD;
    pstRptHrpdNoSrvInd->stMsgHeader.ulReceiverCpuId     = VOS_LOCAL_CPUID;
    pstRptHrpdNoSrvInd->stMsgHeader.ulReceiverPid       = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstRptHrpdNoSrvInd->stMsgHeader.ulLength            = ulMsgLength;

    PS_SEND_MSG(UEPS_PID_HSD, pstRptHrpdNoSrvInd);

    return;
}



VOS_VOID CNAS_HSD_SndMsccHdrCsqSetCnf(
    NAS_MSCC_PIF_CDMACSQ_SET_RESULT_ENUM_UINT8      enRslt
)
{
    HSD_MSCC_HDR_CSQ_SET_CNF_STRU      *pstSetCnf = VOS_NULL_PTR;
    VOS_UINT32                          ulMsgLength;

    ulMsgLength     = sizeof(HSD_MSCC_HDR_CSQ_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    pstSetCnf   = (HSD_MSCC_HDR_CSQ_SET_CNF_STRU *)PS_ALLOC_MSG(UEPS_PID_HSD, ulMsgLength);

    if (VOS_NULL_PTR == pstSetCnf)
    {
        return;
    }

    NAS_MEM_SET_S(((VOS_UINT8 *)pstSetCnf) + VOS_MSG_HEAD_LENGTH, ulMsgLength, 0x00, ulMsgLength);

    pstSetCnf->stMsgHeader.ulMsgName           = ID_HSD_MSCC_HDR_CSQ_SET_CNF;
    pstSetCnf->stMsgHeader.ulSenderCpuId       = VOS_LOCAL_CPUID;
    pstSetCnf->stMsgHeader.ulSenderPid         = UEPS_PID_HSD;
    pstSetCnf->stMsgHeader.ulReceiverCpuId     = VOS_LOCAL_CPUID;
    pstSetCnf->stMsgHeader.ulReceiverPid       = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstSetCnf->stMsgHeader.ulLength            = ulMsgLength;

    pstSetCnf->enRslt                          = enRslt;

    PS_SEND_MSG(UEPS_PID_HSD, pstSetCnf);

    return;
}


VOS_VOID CNAS_HSD_SndMsccHdrCsqQualityInd(
    VOS_INT16                            sHrpdRssi,
    VOS_INT16                            sHrpdSnr,
    VOS_INT16                            sHrpdEcio
)
{
    HSD_MSCC_HDR_CSQ_IND_STRU          *pstCsqInd = VOS_NULL_PTR;
    VOS_UINT32                          ulMsgLength;

    ulMsgLength     = sizeof(HSD_MSCC_HDR_CSQ_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    pstCsqInd       = (HSD_MSCC_HDR_CSQ_IND_STRU *)PS_ALLOC_MSG(UEPS_PID_HSD, ulMsgLength);

    if (VOS_NULL_PTR == pstCsqInd)
    {
        return;
    }

    NAS_MEM_SET_S(((VOS_UINT8 *)pstCsqInd) + VOS_MSG_HEAD_LENGTH, ulMsgLength, 0x00, ulMsgLength);

    pstCsqInd->stMsgHeader.ulMsgName           = ID_HSD_MSCC_HDR_CSQ_IND;
    pstCsqInd->stMsgHeader.ulSenderCpuId       = VOS_LOCAL_CPUID;
    pstCsqInd->stMsgHeader.ulSenderPid         = UEPS_PID_HSD;
    pstCsqInd->stMsgHeader.ulReceiverCpuId     = VOS_LOCAL_CPUID;
    pstCsqInd->stMsgHeader.ulReceiverPid       = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstCsqInd->stMsgHeader.ulLength            = ulMsgLength;

    pstCsqInd->sHrpdRssi                       = sHrpdRssi;
    pstCsqInd->sHrpdSnr                        = sHrpdSnr;
    pstCsqInd->sHrpdEcio                       = sHrpdEcio;

    PS_SEND_MSG(UEPS_PID_HSD, pstCsqInd);

    return;
}





VOS_VOID CNAS_HSD_SndMsccStopBgSrchInd(VOS_VOID)
{
    HSD_MSCC_STOP_BG_SEARCH_IND_STRU                        *pstStopBgSearchInd  = VOS_NULL_PTR;

    /* 分配消息 */
    pstStopBgSearchInd = (HSD_MSCC_STOP_BG_SEARCH_IND_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_HSD,
                                        sizeof(HSD_MSCC_STOP_BG_SEARCH_IND_STRU));
    if (VOS_NULL_PTR == pstStopBgSearchInd)
    {
        return;
    }

    /* 填充消息 */
    pstStopBgSearchInd->stMsgHeader.ulReceiverPid   = CNAS_CCB_ConvertPidBasedOnModemId(CNAS_CCB_GetCdmaModeModemId(), UEPS_PID_MSCC);
    pstStopBgSearchInd->stMsgHeader.ulMsgName       = ID_HSD_MSCC_STOP_BG_SEARCH_IND;
    pstStopBgSearchInd->usOpId                      = 0;

    CNAS_MNTN_LogMsgInfo((MSG_HEADER_STRU*)pstStopBgSearchInd);

    CNAS_HSD_LogMsgInfo((MSG_HEADER_STRU*)pstStopBgSearchInd);

    /* 发送消息 */
    (VOS_VOID)PS_SEND_MSG(UEPS_PID_HSD, pstStopBgSearchInd);

    return;
}

/*lint -restore*/

#endif









#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
