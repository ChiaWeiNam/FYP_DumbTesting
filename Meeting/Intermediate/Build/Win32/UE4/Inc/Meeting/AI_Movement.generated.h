// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MEETING_AI_Movement_generated_h
#error "AI_Movement.generated.h already included, missing '#pragma once' in AI_Movement.h"
#endif
#define MEETING_AI_Movement_generated_h

#define Meeting_Source_Meeting_AI_Movement_h_12_RPC_WRAPPERS
#define Meeting_Source_Meeting_AI_Movement_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define Meeting_Source_Meeting_AI_Movement_h_12_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUAI_Movement(); \
	friend MEETING_API class UClass* Z_Construct_UClass_UAI_Movement(); \
	public: \
	DECLARE_CLASS(UAI_Movement, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Meeting"), NO_API) \
	DECLARE_SERIALIZER(UAI_Movement) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Meeting_Source_Meeting_AI_Movement_h_12_INCLASS \
	private: \
	static void StaticRegisterNativesUAI_Movement(); \
	friend MEETING_API class UClass* Z_Construct_UClass_UAI_Movement(); \
	public: \
	DECLARE_CLASS(UAI_Movement, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Meeting"), NO_API) \
	DECLARE_SERIALIZER(UAI_Movement) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Meeting_Source_Meeting_AI_Movement_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAI_Movement(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAI_Movement) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAI_Movement); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAI_Movement); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAI_Movement(UAI_Movement&&); \
	NO_API UAI_Movement(const UAI_Movement&); \
public:


#define Meeting_Source_Meeting_AI_Movement_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAI_Movement(UAI_Movement&&); \
	NO_API UAI_Movement(const UAI_Movement&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAI_Movement); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAI_Movement); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UAI_Movement)


#define Meeting_Source_Meeting_AI_Movement_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__GrowRate() { return STRUCT_OFFSET(UAI_Movement, GrowRate); } \
	FORCEINLINE static uint32 __PPO__maxSpeed() { return STRUCT_OFFSET(UAI_Movement, maxSpeed); } \
	FORCEINLINE static uint32 __PPO__maxForce() { return STRUCT_OFFSET(UAI_Movement, maxForce); } \
	FORCEINLINE static uint32 __PPO__target() { return STRUCT_OFFSET(UAI_Movement, target); }


#define Meeting_Source_Meeting_AI_Movement_h_9_PROLOG
#define Meeting_Source_Meeting_AI_Movement_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Meeting_Source_Meeting_AI_Movement_h_12_PRIVATE_PROPERTY_OFFSET \
	Meeting_Source_Meeting_AI_Movement_h_12_RPC_WRAPPERS \
	Meeting_Source_Meeting_AI_Movement_h_12_INCLASS \
	Meeting_Source_Meeting_AI_Movement_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Meeting_Source_Meeting_AI_Movement_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Meeting_Source_Meeting_AI_Movement_h_12_PRIVATE_PROPERTY_OFFSET \
	Meeting_Source_Meeting_AI_Movement_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Meeting_Source_Meeting_AI_Movement_h_12_INCLASS_NO_PURE_DECLS \
	Meeting_Source_Meeting_AI_Movement_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Meeting_Source_Meeting_AI_Movement_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
