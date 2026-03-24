// Created by Crowbar 0.74

$modelname "weapons/v_BB_Rock.mdl"

$bodygroup "studio"
{
	studio "BB_Bottle_reference.smd"
}
$bodygroup "rock"
{
	studio "BB_Rock_reference.smd"
}


$contents "solid"

$illumposition -7.795 -11.81 -12.308

$cdmaterials "models\Weapons\V_hand\"
$cdmaterials "models\props_wasteland\"

$cbox 0 0 0 0 0 0

$bbox -5.227 -14.273 -20.744 28.847 -1.318 -3.872

$definebone "Bip01" "" 0.134138 -0.053419 43.181469 0 -89.999927 0 0 0 0 0 0 0
$definebone "Bip01 Pelvis" "Bip01" 0 0 0 -89.980215 -89.999927 0 0 0 0 0 0 0
$definebone "Bip01 Spine" "Bip01 Pelvis" 4.443616 -0.009642 0.000006 -0.000057 0.045607 -0.000229 0 0 0 0 0 0
$definebone "Bip01 Neck" "Bip01 Spine" 12.111416 -0.011446 0 0 0 0 0 0 0 0 0 0
$definebone "Bip01 R Clavicle" "Bip01 Neck" 0.000008 0.011449 -1.352403 78.540823 179.953614 -0.000802 0 0 0 0 0 0
$definebone "Bip01 R UpperArm" "Bip01 R Clavicle" 6.078087 0 0.000002 -2.569601 -88.156548 72.743762 0 0 0 0 0 0
$definebone "Bip01 R Forearm" "Bip01 R UpperArm" 13.446753 -0.000003 0 0 -3.959138 -0.000002 0 0 0 0 0 0
$definebone "Bip01 R Hand" "Bip01 R Forearm" 15.997 -0.000001 0 0 0 96.454354 0 0 0 0 0 0
$definebone "Bip01 R Finger0" "Bip01 R Hand" 1.885324 0.833277 2.177874 -40.000002 -0.038272 91.559587 0 0 0 0 0 0
$definebone "Bip01 R Finger01" "Bip01 R Finger0" 1.506966 0 0 0.000001 -7.999994 -0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger02" "Bip01 R Finger01" 0.79835 0.000001 0 0.000001 -6.49999 -0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger1" "Bip01 R Hand" 3.950305 -0.539875 2.108871 -9.000016 -0.007219 0.046182 0 0 0 0 0 0
$definebone "Bip01 R Finger11" "Bip01 R Finger1" 1.545792 0 0.000004 0.000003 26.999999 0.000003 0 0 0 0 0 0
$definebone "Bip01 R Finger12" "Bip01 R Finger11" 1.667396 -0.000001 -0.000003 0.000001 24.999973 0.000005 0 0 0 0 0 0
$definebone "Bip01 R Finger2" "Bip01 R Hand" 3.899463 -0.475376 1.170888 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger21" "Bip01 R Finger2" 1.528218 0 0 0 19.000024 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger22" "Bip01 R Finger21" 1.528214 -0.000001 -0.000004 -0.000001 27.499965 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger3" "Bip01 R Hand" 3.899462 -0.431804 -0.168228 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger31" "Bip01 R Finger3" 1.506963 0 -0.000002 0 24.500015 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger32" "Bip01 R Finger31" 1.506964 -0.000001 0.000008 -0.000001 19.499985 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger4" "Bip01 R Hand" 3.915634 -0.278019 -1.402608 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger41" "Bip01 R Finger4" 1.33308 0 0.000005 -0.000001 36.499981 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger42" "Bip01 R Finger41" 1.159203 0.000001 0 -0.000001 12.499986 0.000001 0 0 0 0 0 0
$definebone "Dummy14" "Bip01 R Hand" 4.150422 4.791645 -1.60512 14.48901 105.506738 -42.485737 0 0 0 0 0 0

$animation "a_HC_idle" "v_bb_rock_anims\HC_idle.smd" {
	fps 30
	loop
}

$animation "a_HC_draw" "v_bb_rock_anims\HC_draw.smd" {
	fps 30
}

$animation "a_HC_pullback" "v_bb_rock_anims\HC_pullback.smd" {
	fps 30
}

$animation "a_HC_throw" "v_bb_rock_anims\HC_throw.smd" {
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

