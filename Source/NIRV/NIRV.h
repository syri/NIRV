// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#pragma once


/**
 * NIRV Game Module.
 */
class NIRV_API FNIRVModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual bool IsGameModule() const override { return true; }

};
