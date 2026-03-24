// Created by Crowbar 0.74

$modelname "weapons/v_Gauss.mdl"

$bodygroup "studio"
{
	studio "Gauss_reference.smd"
}


$contents "solid"

$illumposition -10.537 -54.64 -17.875

$cdmaterials "models\Weapons\V_hand\"
$cdmaterials "models\Weapons\V_Gauss\"

$attachment "0" "muzzle" 13 0 0 rotate 0 -180 0

$cbox 0 0 0 0 0 0

$bbox 25.401 -23.999 -26.629 83.879 2.925 -9.121

$controller 0 "Dummy17" XR 0 360
$controller 1 "Dummy14" XR 0 360

$definebone "Bip01" "" -9.038199 -20.593618 32.734615 0 -89.999927 0 0 0 0 0 0 0
$definebone "Bip01 Pelvis" "Bip01" -0.000002 0 0 -89.980215 -89.999927 0 0 0 0 0 0 0
$definebone "Bip01 Spine" "Bip01 Pelvis" 4.443614 -0.009642 0.000006 -0.000057 0.045607 -0.000229 0 0 0 0 0 0
$definebone "Bip01 Neck" "Bip01 Spine" 12.111415 -0.011447 0.000001 0 0 0 0 0 0 0 0 0
$definebone "Bip01 L Clavicle" "Bip01 Neck" 0.000006 0.011443 1.352404 -78.540823 179.955158 -0.000802 0 0 0 0 0 0
$definebone "Bip01 L UpperArm" "Bip01 L Clavicle" 6.078087 -0.000001 -0.000003 2.569601 -88.156487 -72.743762 0 0 0 0 0 0
$definebone "Bip01 L Forearm" "Bip01 L UpperArm" 13.446752 -0.000004 0 0 -3.959139 0.000001 0 0 0 0 0 0
$definebone "Bip01 L Hand" "Bip01 L Forearm" 15.996998 0.000002 0 0 0 -96.454354 0 0 0 0 0 0
$definebone "Bip01 L Finger0" "Bip01 L Hand" 1.885325 0.833277 -2.177876 40.000016 -0.038273 -91.559587 0 0 0 0 0 0
$definebone "Bip01 L Finger01" "Bip01 L Finger0" 1.506962 0.000002 0 -0.000001 -7.999983 0.000001 0 0 0 0 0 0
$definebone "Bip01 L Finger02" "Bip01 L Finger01" 0.798351 -0.000003 0 -0.000001 -6.499978 0.000001 0 0 0 0 0 0
$definebone "Bip01 L Finger1" "Bip01 L Hand" 3.9503 -0.539876 -2.108872 9.000021 -0.007219 -0.046181 0 0 0 0 0 0
$definebone "Bip01 L Finger11" "Bip01 L Finger1" 1.545799 0 -0.000003 0 27.000006 -0.000001 0 0 0 0 0 0
$definebone "Bip01 L Finger12" "Bip01 L Finger11" 1.6674 0 0.000002 0 24.999981 -0.000001 0 0 0 0 0 0
$definebone "Bip01 L Finger2" "Bip01 L Hand" 3.899457 -0.475376 -1.170892 0 0 -0.045608 0 0 0 0 0 0
$definebone "Bip01 L Finger21" "Bip01 L Finger2" 1.528212 0 0.000001 0 19.000029 -0.000001 0 0 0 0 0 0
$definebone "Bip01 L Finger22" "Bip01 L Finger21" 1.528216 -0.000002 0.000002 0.000001 27.500029 0 0 0 0 0 0 0
$definebone "Bip01 L Finger3" "Bip01 L Hand" 3.899455 -0.431804 0.168224 0 0 -0.045608 0 0 0 0 0 0
$definebone "Bip01 L Finger31" "Bip01 L Finger3" 1.506968 0 0.000004 0 24.50002 -0.000001 0 0 0 0 0 0
$definebone "Bip01 L Finger32" "Bip01 L Finger31" 1.506958 0.000001 -0.000005 0.000001 19.499992 -0.000001 0 0 0 0 0 0
$definebone "Bip01 L Finger4" "Bip01 L Hand" 3.915631 -0.278019 1.402608 0 0 -0.045608 0 0 0 0 0 0
$definebone "Bip01 L Finger41" "Bip01 L Finger4" 1.333083 0 0.000001 0.000001 36.499991 -0.000001 0 0 0 0 0 0
$definebone "Bip01 L Finger42" "Bip01 L Finger41" 1.1592 0.000002 0 0.000001 12.499993 0 0 0 0 0 0 0
$definebone "Bip01 R Clavicle" "Bip01 Neck" 0.000007 0.01145 -1.352404 78.540823 179.953614 -0.000802 0 0 0 0 0 0
$definebone "Bip01 R UpperArm" "Bip01 R Clavicle" 6.078088 0 0.000001 -2.569601 -88.156548 72.743762 0 0 0 0 0 0
$definebone "Bip01 R Forearm" "Bip01 R UpperArm" 13.446758 -0.000002 0 0 -3.959138 -0.000002 0 0 0 0 0 0
$definebone "Bip01 R Hand" "Bip01 R Forearm" 15.997002 0.000004 0.000001 0 0 96.454354 0 0 0 0 0 0
$definebone "Dummy16" "Bip01 R Hand" -9.7679 -0.747117 10.16853 -1.064753 -179.115414 90.655885 0 0 0 0 0 0
$definebone "Dummy17" "Dummy16" 3.098374 2.832128 0.074532 0 0 0.000002 0 0 0 0 0 0
$definebone "Dummy14" "Dummy16" -7.41014 -0.113609 -0.123968 0 0 0.000002 0 0 0 0 0 0
$definebone "muzzle" "Dummy16" -43.188026 1.691162 -0.053447 0 0 0.000002 0 0 0 0 0 0

$animation "a_idle" "v_Gauss_anims\idle.smd" {
	fps 30
	loop
}

$animation "a_fire" "v_Gauss_anims\fire.smd" {
	fps 30
}

$animation "a_charged_fire" "v_Gauss_anims\charged_fire.smd" {
	fps 30
}

$animation "a_draw" "v_Gauss_anims\draw.smd" {
	fps 35
}

$animation "a_shake" "v_Gauss_anims\shake.smd" {
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

