// Created by Crowbar 0.74

$modelname "weapons/v_BB_Headcrab.mdl"

$bodygroup "studio"
{
	studio "BB_Headcrab_reference.smd"
}


$contents "solid"

$illumposition -6.919 -15.184 -11.546

$cdmaterials "models\Weapons\V_hand\"
$cdmaterials "models\Weapons\V_BB_Headcrab\"

$cbox 0 0 0 0 0 0

$bbox -5.232 -15.831 -20.735 35.601 1.992 -2.356

$definebone "Bip01" "" 0.134138 2.728104 43.181469 0 -89.999927 0 0 0 0 0 0 0
$definebone "Bip01 Pelvis" "Bip01" 0 0 0 -89.980215 -89.999927 0 0 0 0 0 0 0
$definebone "Bip01 Spine" "Bip01 Pelvis" 4.443617 -0.009642 0.000006 -0.000057 0.045607 -0.000229 0 0 0 0 0 0
$definebone "Bip01 Neck" "Bip01 Spine" 12.111415 -0.011446 0 0 0 0 0 0 0 0 0 0
$definebone "Bip01 R Clavicle" "Bip01 Neck" 0.000011 0.011449 -1.352403 78.540823 179.953614 -0.000802 0 0 0 0 0 0
$definebone "Bip01 R UpperArm" "Bip01 R Clavicle" 6.078086 0 0.000002 -2.569601 -88.156548 72.743762 0 0 0 0 0 0
$definebone "Bip01 R Forearm" "Bip01 R UpperArm" 13.446753 -0.000002 -0.000001 0 -3.959138 -0.000002 0 0 0 0 0 0
$definebone "Bip01 R Hand" "Bip01 R Forearm" 15.996999 -0.000001 0 0 0 96.454354 0 0 0 0 0 0
$definebone "Bip01 R Finger0" "Bip01 R Hand" 1.885325 0.833277 2.177876 -33.196936 41.21136 66.221833 0 0 0 0 0 0
$definebone "Bip01 R Finger01" "Bip01 R Finger0" 1.506965 0 0 -0.000004 -7.999987 -0.000009 0 0 0 0 0 0
$definebone "Bip01 R Finger02" "Bip01 R Finger01" 0.798348 -0.000004 0 -0.000004 -8.500005 -0.000008 0 0 0 0 0 0
$definebone "Bip01 R Finger1" "Bip01 R Hand" 3.9503 -0.539876 2.10887 -8.639569 16.687679 -2.531441 0 0 0 0 0 0
$definebone "Bip01 R Finger11" "Bip01 R Finger1" 1.5458 -0.000001 0.000004 0.000003 24.500015 0.000004 0 0 0 0 0 0
$definebone "Bip01 R Finger12" "Bip01 R Finger11" 1.667396 0.000001 -0.000002 0.000001 17.999983 0.000005 0 0 0 0 0 0
$definebone "Bip01 R Finger2" "Bip01 R Hand" 3.899458 -0.475376 1.170891 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger21" "Bip01 R Finger2" 1.528215 0 -0.000001 0 13.999992 0.000002 0 0 0 0 0 0
$definebone "Bip01 R Finger22" "Bip01 R Finger21" 1.528214 0.000001 0.000001 -0.000001 27.500022 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger3" "Bip01 R Hand" 3.899459 -0.431804 -0.168225 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger31" "Bip01 R Finger3" 1.506964 0 0 0 15.499996 0.000002 0 0 0 0 0 0
$definebone "Bip01 R Finger32" "Bip01 R Finger31" 1.506964 0 0.000001 0 -2.000026 0.000002 0 0 0 0 0 0
$definebone "Bip01 R Finger4" "Bip01 R Hand" 3.915631 -0.27802 -1.402609 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger41" "Bip01 R Finger4" 1.333082 0 -0.000004 0 4.999973 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger42" "Bip01 R Finger41" 1.159206 0 0.000004 0 12.499991 0.000002 0 0 0 0 0 0
$definebone "Dummy14" "Bip01 R Hand" 7.051337 4.316995 -1.100496 -47.060779 -179.807995 90.962643 0 0 0 0 0 0

$animation "a_HC_idle" "v_BB_Headcrab_anims\HC_idle.smd" {
	fps 30
	loop
}

$animation "a_HC_draw" "v_BB_Headcrab_anims\HC_draw.smd" {
	fps 30
}

$animation "a_HC_pullback" "v_BB_Headcrab_anims\HC_pullback.smd" {
	fps 30
}

$animation "a_HC_throw" "v_BB_Headcrab_anims\HC_throw.smd" {
	fps 30
}

$sequence "HC_idle" {
	"a_HC_idle"
	activity "ACT_VM_IDLE" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "HC_draw" {
	"a_HC_draw"
	activity "ACT_VM_DRAW" 1
	fadein 0.2
	fadeout 0.2
	snap
}

$sequence "HC_pullback" {
	"a_HC_pullback"
	activity "ACT_VM_PULLBACK" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "HC_throw" {
	"a_HC_throw"
	activity "ACT_VM_THROW" 1
	fadein 0.2
	fadeout 0.2
}

