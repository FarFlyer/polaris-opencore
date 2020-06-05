#include "Arduino.h"
#include "CoreLogging.h"
#include "CoreCommon.h"

#define CHARGE_PIN 13
#define STANDBY_PIN 15
#define USB_PIN 23

#define BLINK_RECHARGE_STATUS_TIME 8000
#define BLINK_RECHARGED_STATUS_TIME 12000

#ifndef CoreRecharge_h
#define CoreRecharge_h

class CoreRecharge
{
public:
  //Costructor
  CoreRecharge();
  //Init
  void init(bool debug);
  //Process loop
  void loop(Status &rStatus, NeedBlinkRecharge &rNeedBlinkRecharge);

private:
  bool debugMode = false;
  CoreLogging logger;
  unsigned long time;
  Status currentStatus;
  NeedBlinkRecharge currentNeedBlinkRechargeStatus = {false, 0};
  NeedBlinkRecharge needBlinkRecharge();
};

#endif