// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Runtime/Core/Public/CoreGlobals.h"
#include "EngineMinimal.h"


//ArenaBattleLOG 전용 매크로 정의하기
DECLARE_LOG_CATEGORY_EXTERN(ArenaBattle, Log, All);
#define ABLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define ABLOG_S(Verbosity) UE_LOG(ArenaBattle, Verbosity, TEXT("%s"), *ABLOG_CALLINFO)
#define ABLOG(Verbosity, Format, ...) UE_LOG(ArenaBattle, Verbosity, TEXT("%s %s"), *ABLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
//런타임에서 문제 발생시 붉은색으로 에러 로그 출력 후 바로 함수 반환하도록 하는 매크로 정의
#define ABCHECK(Expr, ...) {if(!(Expr)){ABLOG(Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__;}}