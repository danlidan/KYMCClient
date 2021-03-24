// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Socket.generated.h"

/**
 * 
 */
UCLASS()
class KMYC_API USocket : public UObject
{
	GENERATED_BODY()
	
public:
	USocket();

	void Send(std::string msg, int32 protoID);

	void Recv(std::string &s);

	std::string Int32ToStr16(int32 val);

	int32 Str16ToInt32(std::string s);

private:
	bool CreateKMYCSocket(FString IPStr, int32 port);

	class FSocket *Host;
};
