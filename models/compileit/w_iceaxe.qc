// Created by Crowbar 0.74

$modelname "weapons/W_iceaxe.mdl"

$bodygroup "studio"
{
	studio "w_iceaxe_iceaxe_reference.smd"
}


$surfaceprop "weapon"

$contents "solid"

$illumposition 0.047 -1.119 1.795

$cdmaterials "models\weapons\v_iceaxe\"

$cbox 0 0 0 0 0 0

$bbox -7.042 -1.362 -15.736 9.279 1.456 19.325

$definebone "ValveBiped.Bip01_R_Hand" "" 1.400187 3.73011 -0.355127 3.381868 -137.542675 171.308125 0 0 0 0 0 0
$definebone "base" "ValveBiped.Bip01_R_Hand" 3.523874 -1.700837 -0.830554 3.381885 -137.542648 -98.691869 0 0 0 0 0 0


$animation "a_idle" "w_iceaxe_anims\a_idle.smd" {
	fps 30
	loop
}

$sequence "idle" {
	"a_idle"
	activity "ACT_VM_IDLE" 1
	fadein 0.2
	fadeout 0.2
}
