/******************************************************************************/
/* File   : SwcServiceOs.cpp                                                  */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "infSwcServiceOs_EcuM.hpp"
#include "infSwcServiceOs_Dcm.hpp"
#include "infSwcServiceOs_SchM.hpp"
#include "infSwcServiceOs_Os.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SWCSERVICEOS_AR_RELEASE_MAJOR_VERSION                                  4
#define SWCSERVICEOS_AR_RELEASE_MINOR_VERSION                                  3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(SWCSERVICEOS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
   #error "Incompatible SWCSERVICEOS_AR_RELEASE_MAJOR_VERSION!"
#endif

#if(SWCSERVICEOS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)
   #error "Incompatible SWCSERVICEOS_AR_RELEASE_MINOR_VERSION!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_SwcServiceOs:
      public abstract_module
   ,  public infSwcServiceOs_Os
{
   public:
      module_SwcServiceOs(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, _CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, _CONFIG_DATA, _APPL_CONST) lptrCfgModule
      );
      FUNC(void, SWCSERVICEOS_CODE) InitFunction   (void);
      FUNC(void, SWCSERVICEOS_CODE) DeInitFunction (void);
      FUNC(void, SWCSERVICEOS_CODE) MainFunction   (void);

      FUNC(void, SWCSERVICEOS_CODE) StartupHook    (void);
      FUNC(void, SWCSERVICEOS_CODE) ShutdownHook   (void);
      FUNC(void, SWCSERVICEOS_CODE) TASK_Idle      (void);
};

extern VAR(module_SwcServiceOs, SWCSERVICEOS_VAR) SwcServiceOs;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient,      SWCSERVICEOS_VAR, SWCSERVICEOS_CONST) gptrinfEcuMClient_SwcServiceOs = &SwcServiceOs;
CONSTP2VAR(infDcmClient,       SWCSERVICEOS_VAR, SWCSERVICEOS_CONST) gptrinfDcmClient_SwcServiceOs  = &SwcServiceOs;
CONSTP2VAR(infSchMClient,      SWCSERVICEOS_VAR, SWCSERVICEOS_CONST) gptrinfSchMClient_SwcServiceOs = &SwcServiceOs;
CONSTP2VAR(infSwcServiceOs_Os, SWCSERVICEOS_VAR, SWCSERVICEOS_CONST) gptrinfSwcServiceOs_Os         = &SwcServiceOs;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/
//#include "CfgSwcServiceOs.hpp"

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_SwcServiceOs, SWCSERVICEOS_VAR) SwcServiceOs(
   {
         0x0000
      ,  0xFFFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::InitFunction(
   CONSTP2CONST(CfgSwcServiceOs_Type, CFGSWCSERVICEOS_CONFIG_DATA, CFGSWCSERVICEOS_APPL_CONST) lptrCfgSwcServiceOs
){
   if(NULL_PTR == lptrCfgSwcServiceOs){
#if(STD_ON == SwcServiceOs_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
// check lptrCfgSwcServiceOs for memory faults
// use PBcfg_SwcServiceOs as back-up configuration
   }
   SwcServiceOs.IsInitDone = E_OK;
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::DeInitFunction(void){
   SwcServiceOs.IsInitDone = E_NOT_OK;
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::MainFunction(void){
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::StartupHook(void){
}

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::ShutdownHook(void){
}

#include "infNvM_SchM.hpp"
#include "infEcuM_SchM.hpp"

FUNC(void, SWCSERVICEOS_CODE) module_SwcServiceOs::TASK_Idle(void){
   gptrinfSchMClient_EcuM->MainFunction();
   gptrinfSchMClient_NvM->MainFunction();
}

class class_SwcServiceOs_Unused{
   public:
      FUNC(void, SWCSERVICEOS_CODE) StartupHook  (void);
      FUNC(void, SWCSERVICEOS_CODE) ShutdownHook (void);
      FUNC(void, SWCSERVICEOS_CODE) TASK_Idle    (void);
};

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

