// Created by Crowbar 0.74

$modelname "weapons/v_Gauss.mdl"

$bodygroup "studio"
{
	studio "Gauss_reference.smd"
}


$surfaceprop "default"

$contents "solid"

$illumposition -10.537 -54.64 -17.875

$cdmaterials "models\Weapons\V_hand\"
$cdmaterials "models\Weapons\V_Gauss\"

$attachment "0" "muzzle" 13 0 0 rotate 0 180 0

$cbox 0 0 0 0 0 0

$bbox 25.401 -23.999 -26.629 83.879 2.925 -9.121

$controller 0 "Dummy17" XR 0 360
$controller 1 "Dummy14" XR 0 360

$definebone "Bip01" "" -9.038199 -20.593618 32.734615 0 -89.999921 0 0 0 0 0 0 0
$definebone "Bip01 Pelvis" "Bip01" -0.000002 0 0 -89.980215 -89.999921 0 0 0 0 0 0 0
$definebone "Bip01 Spine" "Bip01 Pelvis" 4.443615 -0.009642 0.000006 -0.000057 0.045607 -0.000229 0 0 0 0 0 0
$definebone "Bip01 Neck" "Bip01 Spine" 12.111412 -0.011446 0.000001 0 0 0 0 0 0 0 0 0
$definebone "Bip01 L Clavicle" "Bip01 Neck" 0.000004 0.011444 1.352403 -78.540823 179.955158 -0.000802 0 0 0 0 0 0
$definebone "Bip01 L UpperArm" "Bip01 L Clavicle" 6.078087 -0.000002 0 2.569601 -88.156487 -72.743762 0 0 0 0 0 0
$definebone "Bip01 L Forearm" "Bip01 L UpperArm" 13.446749 0 0 0 -3.959138 0.000003 0 0 0 0 0 0
$definebone "Bip01 L Hand" "Bip01 L Forearm" 15.996994 0.000004 0 0 0.000001 -96.454354 0 0 0 0 0 0
$definebone "Bip01 L Finger0" "Bip01 L Hand" 1.885326 0.833277 -2.177876 40.000016 -0.038272 -91.559587 0 0 0 0 0 0
$definebone "Bip01 L Finger01" "Bip01 L Finger0" 1.506966 0.000003 0 -0.000001 -7.999983 0.000002 0 0 0 0 0 0
$definebone "Bip01 L Finger02" "Bip01 L Finger01" 0.798355 -0.000002 0 -0.000001 -6.499976 0.000002 0 0 0 0 0 0
$definebone "Bip01 L Finger1" "Bip01 L Hand" 3.950302 -0.539876 -2.108871 9.000018 -0.007219 -0.046182 0 0 0 0 0 0
$definebone "Bip01 L Finger11" "Bip01 L Finger1" 1.545799 0 -0.000004 -0.000002 27.000004 -0.000002 0 0 0 0 0 0
$definebone "Bip01 L Finger12" "Bip01 L Finger11" 1.6674 0.000002 0.000004 -0.000001 24.99998 -0.000004 0 0 0 0 0 0
$definebone "Bip01 L Finger2" "Bip01 L Hand" 3.89946 -0.475376 -1.170887 -0.000001 0 -0.045609 0 0 0 0 0 0
$definebone "Bip01 L Finger21" "Bip01 L Finger2" 1.528214 0 0.000004 0 19.000027 -0.000002 0 0 0 0 0 0
$definebone "Bip01 L Finger22" "Bip01 L Finger21" 1.528217 0 0.000004 0.000001 27.50003 -0.000001 0 0 0 0 0 0
$definebone "Bip01 L Finger3" "Bip01 L Hand" 3.899456 -0.431804 0.168224 -0.000001 0 -0.045609 0 0 0 0 0 0
$definebone "Bip01 L Finger31" "Bip01 L Finger3" 1.506969 0 0 0 24.500017 -0.000002 0 0 0 0 0 0
$definebone "Bip01 L Finger32" "Bip01 L Finger31" 1.506958 0 -0.000004 0.000001 19.499994 -0.000002 0 0 0 0 0 0
$definebone "Bip01 L Finger4" "Bip01 L Hand" 3.915634 -0.278019 1.402611 -0.000001 0 -0.045609 0 0 0 0 0 0
$definebone "Bip01 L Finger41" "Bip01 L Finger4" 1.333084 0 -0.000004 0.000001 36.499988 -0.000002 0 0 0 0 0 0
$definebone "Bip01 L Finger42" "Bip01 L Finger41" 1.159195 0.000004 0.000004 0.000001 12.499992 -0.000001 0 0 0 0 0 0
$definebone "Bip01 R Clavicle" "Bip01 Neck" 0.000004 0.01145 -1.352405 78.540823 179.953614 -0.000802 0 0 0 0 0 0
$definebone "Bip01 R UpperArm" "Bip01 R Clavicle" 6.078088 0 0.000004 -2.569601 -88.156548 72.743762 0 0 0 0 0 0
$definebone "Bip01 R Forearm" "Bip01 R UpperArm" 13.446758 0 -0.000002 0 -3.959138 -0.000002 0 0 0 0 0 0
$definebone "Bip01 R Hand" "Bip01 R Forearm" 15.997002 0 0.000002 0 0 96.454354 0 0 0 0 0 0
$definebone "Dummy16" "Bip01 R Hand" -9.767902 -0.747117 10.168533 -1.064753 -179.115414 90.655885 0 0 0 0 0 0
$definebone "Dummy17" "Dummy16" 3.098373 2.832127 0.074532 0 0 0.000002 0 0 0 0 0 0
$definebone "Dummy14" "Dummy16" -7.410137 -0.113605 -0.123968 0 0 0.000002 0 0 0 0 0 0
$definebone "muzzle" "Dummy16" -43.188026 1.691162 -0.053448 0 0 0.000002 0 0 0 0 0 0


$animation "a_idle" "v_gauss_anims\a_idle.smd" {
	fps 30
	loop
}

$animation "a_fire" "v_gauss_anims\a_fire.smd" {
	fps 30
}

$animation "a_charged_fire" "v_gauss_anims\a_charged_fire.smd" {
	fps 30
}

$animation "a_draw" "v_gauss_anims\a_draw.smd" {
	fps 35
}

$animation "a_shake" "v_gauss_anims\a_shake.smd" {
	fps 30
	loop
}

$sequence "idle" {
	"a_idle"
	activity "ACT_VM_IDLE" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "fire" {
	"a_fire"
	activity "ACT_VM_PRIMARYATTACK" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "charged_fire" {
	"a_charged_fire"
	activity "ACT_VM_SECONDARYATTACK" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "draw" {
	"a_draw"
	activity "ACT_VM_DRAW" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "shake" {
	"a_shake"
	activity "ACT_VM_PULLBACK" 1
	fadein 0.2
	fadeout 0.2
}
