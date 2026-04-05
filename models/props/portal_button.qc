// Created by Crowbar 0.74

$modelname "props/portal_button.mdl"

$bodygroup "g"
{
	studio "floor_button_ref.smd"
}


$surfaceprop "default"

$contents "solid"

$illumposition -0.032 -0.006 6.819

$cdmaterials "models\props\"

$cbox 0 0 0 0 0 0

$bbox -58.594 -58.632 -0.002 58.606 58.568 13.641

$definebone "portal_button_export" "" 0 0 0 0 0 0 0 0 0 0 0 0
$definebone "portal_button_root" "portal_button_export" 0 0 0 0 0 0 0 0 0 0 0 0
$definebone "portal_button_top" "portal_button_root" 0 13.640244 0 0 0 0 0 0 0 0 0 0


$sequence "BindPose" {
	"portal_button_anims\BindPose.smd"
	fadein 0.2
	fadeout 0.2
	fps 24
}

$sequence "up" {
	"portal_button_anims\up.smd"
	{ event AE_CL_PLAYSOUND 0 "buttons/button_up.wav" }
	fadein 0.2
	fadeout 0.2
	fps 24
}

$sequence "idledown" {
	"portal_button_anims\idledown.smd"
	fadein 0.2
	fadeout 0.2
	fps 24
}

$sequence "down" {
	"portal_button_anims\down.smd"
	{ event AE_CL_PLAYSOUND 0 "buttons/button_down.wav" }
	fadein 0.2
	fadeout 0.2
	fps 24
}

$collisionjoints "portal_button_physics.smd"
{
	$mass 1967.366
	$inertia 1
	$damping 0
	$rotdamping 0
	$rootbone " "


	$jointconstrain "portal_button_top" x limit 0 0 0
	$jointconstrain "portal_button_top" y limit 0 0 0
	$jointconstrain "portal_button_top" z limit 0 0 0
}
