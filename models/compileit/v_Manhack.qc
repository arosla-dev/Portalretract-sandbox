// Created by Crowbar 0.74

$modelname "Weapons/v_Manhack.mdl"

$bodygroup "studio"
{
	studio "Manhack_reference.smd"
}


$contents "solid"

$illumposition 0.013 -15.88 -6.377

$cdmaterials "models\weapons\v_manhack\"

$cbox 0 0 0 0 0 0

$bbox 1.998 -13.913 -6.81 29.762 13.939 -5.943

$definebone "Rotate" "" 0.000001 -15.864439 61.57185 0 0 0 0 0 0 0 0 0
$definebone "blade" "Rotate" 0 0 0 0.999983 0.999983 0.999983 0 0 0 0 0 0

$animation "a_idle" "v_Manhack_anims\idle.smd" {
	fps 30
	loop
}

$sequence "idle" {
	"a_idle"
	activity "ACT_VM_IDLE" 1
	fadein 0.2
	fadeout 0.2
}

