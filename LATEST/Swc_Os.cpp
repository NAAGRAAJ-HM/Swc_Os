/*****************************************************/
/* File   : Swc_Os.cpp                               */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "Swc_Os.h"

#include "EcuM.h"
#include "NvM.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
class_Swc_Os Swc_Os;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, SWC_OS_CODE) class_Swc_Os::StartupHook(void){
}

FUNC(void, SWC_OS_CODE) class_Swc_Os::ShutdownHook(void){
}

FUNC(void, SWC_OS_CODE) class_Swc_Os::TASK_Idle(void){
   EcuM.MainFunction();
   NvM.MainFunction();
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

