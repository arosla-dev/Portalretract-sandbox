// Created by Crowbar 0.74

$modelname "Weapons/W_bb_Bottle.mdl"

$bodygroup "body"
{
	studio "W_bb_Bottle.smd"
}


$surfaceprop "glassbottle"

$contents "solid"

$illumposition 0.032 0.064 1.379

$cdmaterials "models\weapons\w_bb_bottle\"

$cbox 0 0 0 0 0 0

$bbox -1.352 -1.238 -3.445 1.225 1.301 6.204

$definebone "ValveBiped.Bip01_R_Hand" "" 1.094099 3.500179 -1.510751 4.603352 -138.709982 167.821545 0 0 0 0 0 0
$definebone "base" "ValveBiped.Bip01_R_Hand" 3.000398 -1.494358 -2.120183 4.603372 -138.709982 -102.178428 0 0 0 0 0 0

$animation "a_idle" "w_bb_Bottle_anims\idle.smd" {
	fps 30
	loop
}

$animation "a_throw" "w_bb_Bottle_anims\throw.smd" {
	fps 30
	loop
}

$sequence "idle" {
	"a_idle"
	fadein 0.2
	fadeout 0.2
}

$sequence "throw" {
	"a_throw"
	activity "ACT_RANGE_ATTACK_THROW" 1
	fadein 0.2
	fadeout 0.2
}


$collisionmodel "w_bb_Bottle_physics.smd"
{
	$mass 0.5
	$inertia 1
	$damping 1
	$rotdamping 6
	$rootbone " "

}
