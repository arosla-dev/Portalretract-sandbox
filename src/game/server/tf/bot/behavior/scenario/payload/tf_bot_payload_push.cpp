//========= Copyright Valve Corporation, All rights reserved. ============//
// tf_bot_payload_push.cpp
// Push the cartTrigger to the goal
// Michael Booth, April 2010

#include "cbase.h"
#include "nav_mesh.h"
#include "tf_player.h"
#include "tf_gamerules.h"
#include "team_control_point_master.h"
#include "team_train_watcher.h"
#include "trigger_area_capture.h"
#include "bot/tf_bot.h"
#include "bot/behavior/scenario/payload/tf_bot_payload_push.h"
#include "bot/behavior/medic/tf_bot_medic_heal.h"
#include "bot/behavior/engineer/tf_bot_engineer_build.h"