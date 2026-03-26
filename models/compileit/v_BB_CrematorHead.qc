// Created by Crowbar 0.74

$modelname "weapons/v_BB_CrematorHead.mdl"

$bodygroup "studio"
{
	studio "BB_crematorhead_reference.smd"
}


$surfaceprop "default"

$contents "solid"

$illumposition -6.869 -13.269 -12.096

$cdmaterials "models\Weapons\V_hand\"
$cdmaterials "models\Weapons\V_BB_CrematorHead\"

$cbox 0 0 0 0 0 0

$bbox -5.232 -14.305 -20.735 31.771 0.567 -3.457

$definebone "Bip01" "" 0.134138 2.728104 43.181469 0 -89.999921 0 0 0 0 0 0 0
$definebone "Bip01 Pelvis" "Bip01" 0 0 0 -89.980215 -89.999921 0 0 0 0 0 0 0
$definebone "Bip01 Spine" "Bip01 Pelvis" 4.443615 -0.009642 0.000006 -0.000057 0.045607 -0.000229 0 0 0 0 0 0
$definebone "Bip01 Neck" "Bip01 Spine" 12.111408 -0.011446 0 0 0 0 0 0 0 0 0 0
$definebone "Bip01 R Clavicle" "Bip01 Neck" 0.000008 0.011449 -1.352403 78.540823 179.953614 -0.000802 0 0 0 0 0 0
$definebone "Bip01 R UpperArm" "Bip01 R Clavicle" 6.078086 0 0 -2.569601 -88.156548 72.743762 0 0 0 0 0 0
$definebone "Bip01 R Forearm" "Bip01 R UpperArm" 13.446753 0 -0.000001 0 -3.959138 -0.000002 0 0 0 0 0 0
$definebone "Bip01 R Hand" "Bip01 R Forearm" 15.997001 0 0.000001 0 0 96.454354 0 0 0 0 0 0
$definebone "Bip01 R Finger0" "Bip01 R Hand" 1.885324 0.833277 2.177876 -33.196932 41.21135 66.221833 0 0 0 0 0 0
$definebone "Bip01 R Finger01" "Bip01 R Finger0" 1.506969 0.000006 0.000004 -0.000009 -7.999999 -0.000013 0 0 0 0 0 0
$definebone "Bip01 R Finger02" "Bip01 R Finger01" 0.798347 -0.000004 0 -0.000005 -8.500015 -0.000012 0 0 0 0 0 0
$definebone "Bip01 R Finger1" "Bip01 R Hand" 3.950298 -0.539876 2.108868 -8.639566 16.687672 -2.531441 0 0 0 0 0 0
$definebone "Bip01 R Finger11" "Bip01 R Finger1" 1.545803 -0.000002 0.000004 0.000006 24.500003 0.000006 0 0 0 0 0 0
$definebone "Bip01 R Finger12" "Bip01 R Finger11" 1.667397 0 0 0.000004 17.999968 0.000008 0 0 0 0 0 0
$definebone "Bip01 R Finger2" "Bip01 R Hand" 3.899458 -0.475376 1.170891 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger21" "Bip01 R Finger2" 1.528219 0 0.000004 0 13.999988 0.000002 0 0 0 0 0 0
$definebone "Bip01 R Finger22" "Bip01 R Finger21" 1.528217 0.000001 0 -0.000001 27.500017 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger3" "Bip01 R Hand" 3.89946 -0.431804 -0.168228 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger31" "Bip01 R Finger3" 1.506962 0 -0.000004 0 15.499992 0.000002 0 0 0 0 0 0
$definebone "Bip01 R Finger32" "Bip01 R Finger31" 1.506964 0.000001 0.000004 0 -2.00003 0.000002 0 0 0 0 0 0
$definebone "Bip01 R Finger4" "Bip01 R Hand" 3.91563 -0.27802 -1.402607 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger41" "Bip01 R Finger4" 1.333084 -0.000001 0 0 4.999972 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger42" "Bip01 R Finger41" 1.15921 -0.000001 0 0 12.499986 0.000002 0 0 0 0 0 0
$definebone "Dummy14" "Bip01 R Hand" 4.150425 4.791649 -1.605122 14.488667 105.506875 -42.485447 0 0 0 0 0 0


$animation "a_HC_idle" "v_bb_crematorhead_anims\a_HC_idle.smd" {
	fps 30
	loop
}

$animation "a_HC_draw" "v_bb_crematorhead_anims\a_HC_draw.smd" {
	fps 30
}

$animation "a_HC_pullback" "v_bb_crematorhead_anims\a_HC_pullback.smd" {
	fps 30
}

$animation "a_HC_throw" "v_bb_crematorhead_anims\a_HC_throw.smd" {
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
