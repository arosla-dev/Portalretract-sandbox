// Created by Crowbar 0.74

$modelname "weapons/W_binoculars.mdl"

$bodygroup "studio"
{
	studio "w_binoculars_reference.smd"
}


$surfaceprop "default"

$contents "solid"

$illumposition -0.013 -0.201 0.13

$cdmaterials "models\weapons\v_binoculars\\"

$cbox 0 0 0 0 0 0

$bbox -4.904 -4.375 -2.182 5.306 4.348 2.441

$definebone "smdimport" "" 0 0 0 0 0 0 0 0 0 0 0 0


$animation "a_idle" "w_binoculars_anims\a_idle.smd" {
	fps 30
	loop
}

$animation "a_attack1" "w_binoculars_anims\a_attack1.smd" {
	fps 30
}

$sequence "idle" {
	"a_idle"
	activity "ACT_VM_IDLE" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "attack1" {
	"a_attack1"
	fadein 0.2
	fadeout 0.2
}
