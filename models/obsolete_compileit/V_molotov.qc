// Created by Crowbar 0.74

$modelname "weapons/v_molotov.mdl"

$bodygroup "studio"
{
	studio "BB_Bottle_reference.smd"
}
$bodygroup "bottle"
{
	studio "BB_Molotov_reference.smd"
}


$surfaceprop "default"

$contents "solid"

$illumposition -9.43 -16.201 -8.825

$cdmaterials "models\Weapons\V_hand\"
$cdmaterials "models\Weapons\W_molotov\"

$cbox 0 0 0 0 0 0

$bbox -1.401 -14.557 -17.186 33.804 -4.304 -0.464

$definebone "Bip01" "" 0.134138 -0.053419 43.181469 0 -89.999921 0 0 0 0 0 0 0
$definebone "Bip01 Pelvis" "Bip01" 0 0 0 -89.980215 -89.999921 0 0 0 0 0 0 0
$definebone "Bip01 Spine" "Bip01 Pelvis" 4.443615 -0.009642 0.000006 -0.000057 0.045607 -0.000229 0 0 0 0 0 0
$definebone "Bip01 Neck" "Bip01 Spine" 12.111412 -0.011446 0 0 0 0 0 0 0 0 0 0
$definebone "Bip01 R Clavicle" "Bip01 Neck" 0.000008 0.011449 -1.352403 78.540823 179.953614 -0.000802 0 0 0 0 0 0
$definebone "Bip01 R UpperArm" "Bip01 R Clavicle" 6.078086 0 0 -2.569601 -88.156548 72.743762 0 0 0 0 0 0
$definebone "Bip01 R Forearm" "Bip01 R UpperArm" 13.446753 0 0 0 -3.959138 -0.000002 0 0 0 0 0 0
$definebone "Bip01 R Hand" "Bip01 R Forearm" 15.997002 0 0.000001 0 0 96.454354 0 0 0 0 0 0
$definebone "Bip01 R Finger0" "Bip01 R Hand" 1.885326 0.833277 2.177876 -39.999992 -0.038272 91.559587 0 0 0 0 0 0
$definebone "Bip01 R Finger01" "Bip01 R Finger0" 1.506962 -0.000002 0 0.000001 -8.000002 -0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger02" "Bip01 R Finger01" 0.798351 0 0 0.000001 -6.499998 -0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger1" "Bip01 R Hand" 3.950306 -0.539876 2.108868 -9.000012 -0.007219 0.046182 0 0 0 0 0 0
$definebone "Bip01 R Finger11" "Bip01 R Finger1" 1.545788 0 0.000004 0.000007 26.999992 0.000005 0 0 0 0 0 0
$definebone "Bip01 R Finger12" "Bip01 R Finger11" 1.667393 -0.000002 -0.000004 0.000003 24.999961 0.000009 0 0 0 0 0 0
$definebone "Bip01 R Finger2" "Bip01 R Hand" 3.899464 -0.475376 1.170887 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger21" "Bip01 R Finger2" 1.528217 0 0.000004 0 19.00002 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger22" "Bip01 R Finger21" 1.528215 -0.000002 -0.000011 -0.000001 27.499964 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger3" "Bip01 R Hand" 3.899464 -0.431804 -0.168228 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger31" "Bip01 R Finger3" 1.506962 0 0 0 24.500008 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger32" "Bip01 R Finger31" 1.506964 0 0.000008 -0.000001 19.499977 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger4" "Bip01 R Hand" 3.915634 -0.278019 -1.402603 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger41" "Bip01 R Finger4" 1.33308 0 0.000008 -0.000001 36.499971 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger42" "Bip01 R Finger41" 1.159208 0 -0.000004 -0.000001 12.499975 0.000001 0 0 0 0 0 0
$definebone "Beer Bottle" "Bip01 R Hand" 3.967457 1.549654 2.149052 7.445582 35.431009 -7.49698 0 0 0 0 0 0
$definebone "Cylinder01" "Beer Bottle" -0.793058 -0.067486 -0.408058 0.977179 91.95539 0.888312 0 0 0 0 0 0


$animation "a_HC_idle" "v_molotov_anims\a_HC_idle.smd" {
	fps 30
	loop
}

$animation "a_HC_draw" "v_molotov_anims\a_HC_draw.smd" {
	fps 30
}

$animation "a_HC_pullback" "v_molotov_anims\a_HC_pullback.smd" {
	fps 30
}

$animation "a_HC_throw" "v_molotov_anims\a_HC_throw.smd" {
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
