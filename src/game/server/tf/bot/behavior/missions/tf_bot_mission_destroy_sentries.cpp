//========= Copyright Valve Corporation, All rights reserved. ============//
// tf_bot_mission_destroy_sentries.cpp
// Seek and destroy enemy sentries and ignore everything else
// Michael Booth, June 2011

#include "cbase.h"
#include "team.h"
#include "bot/tf_bot.h"
#include "bot/behavior/missions/tf_bot_mission_destroy_sentries.h"
#include "bot/behavior/spy/tf_bot_spy_sap.h"
#include "bot/behavior/tf_bot_destroy_enemy_sentry.h"
#include "bot/behavior/medic/tf_bot_medic_heal.h"
#include "bot/behavior/missions/tf_bot_mission_suicide_bomber.h"
#include "tf_obj_sentrygun.h"