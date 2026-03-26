// Created by Crowbar 0.74

$modelname "weapons/w_guardgun.mdl"

$bodygroup "studio"
{
	studio "w_guardgun_reference.smd"
}


$surfaceprop "weapon"

$contents "solid"

$illumposition -0.027 -1.846 -0.915

$cdmaterials "models\weapons\w_guardgun\\"
$cdmaterials "models\weapons\v_hand\\"

$cbox 0 0 0 0 0 0

$bbox -27.38 -9.005 -9.032 31.072 8.951 7.202

$definebone "smdimport" "" 0 0 0 0 0 0 0 0 0 0 0 0


$animation "a_idle1" "w_guardgun_anims\a_idle1.smd" {
	fps 30
	loop
}

$animation "a_fire" "w_guardgun_anims\a_fire.smd" {
	fps 30
}

$sequence "idle1" {
	"a_idle1"
	activity "ACT_VM_IDLE" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "fire" {
	"a_fire"
	activity "ACT_RANGE_ATTACK_AR2" 1
	fadein 0.2
	fadeout 0.2
}
