// Fill out your copyright notice in the Description page of Project Settings.


#include "WebSocketGameInstance.h"
#include "WebSocketsModule.h"

void UWebSocketGameInstance::Init(){
   Super::Init();

   if(!FModuleManager::Get().IsModuleLoaded("WebSockets")){
	  FModuleManager::Get().LoadModule("WebSockets");
   }

   WebSocket = FWebSocketsModule::Get().CreateWebSocket("ws://192.168.70.128:2024");

   WebSocket->Connect();
}

void UWebSocketGameInstance::Shutdown(){
   if(WebSocket->IsConnected()){
	  WebSocket->Close();
   }

   Super::Shutdown();
}