// Copyright 2024 Pavel Suprunov
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//
// Created by jadjer on 3/18/24.
//

#pragma once

#include "ExternalPower.hpp"
#include "Pump.hpp"
#include "Timer.hpp"
#include "WheelSensor.hpp"

#include "configuration/interface/Configuration.hpp"
#include "controller/ControllerBase.hpp"

class Controller : public ControllerBase {
public:
  explicit Controller(ConfigurationPtr configuration);
  ~Controller() override = default;

private:
  void spinOnce() override;

private:
  void pumpEnable();
  void pumpDisable();
  void sleep();

private:
  ConfigurationPtr m_configuration = nullptr;

private:
  PumpPtr m_pumpPtr = nullptr;
  TimerPtr m_timerPtr = nullptr;
  WheelSensorPtr m_wheelSensorPtr = nullptr;
  ExternalPowerPtr m_externalPowerPtr = nullptr;
};
