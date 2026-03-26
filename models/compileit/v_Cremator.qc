// Created by Crowbar 0.74

$modelname "weapons/v_cremator.mdl"

$bodygroup "studio"
{
	studio "v_Cremator_reference.smd"
}
$bodygroup "hands"
{
	studio "arms_beta_for_beta.smd"
	studio "arms_retail_for_beta.smd"
}


$surfaceprop "default"

$contents "solid"

$illumposition -7.247 -45.843 -13.515

$cdmaterials "models\Weapons\V_hand\\"
$cdmaterials "models\Weapons\V_Immolator\\"

$attachment "0" "muzzle" 0 0 0 rotate 0 0 0

$cbox 0 0 0 0 0 0

$bbox 18.534 -19.065 -19.219 75.546 3.12 -6.408

$definebone "Bip01" "" -13.101732 -12.071518 43.181469 0 -89.999982 0 0 0 0 0 0 0
$definebone "Bip01 Pelvis" "Bip01" 0 0 0 -89.980215 -90.002222 0 0 0 0 0 0 0
$definebone "Bip01 Spine" "Bip01 Pelvis" 4.443615 -0.009641 0.000006 -0.353171 0.045264 -0.000229 0 0 0 0 0 0
$definebone "Bip01 Neck" "Bip01 Spine" 12.111172 -0.011366 -0.07464 0 0 0 0 0 0 0 0 0
$definebone "Bip01 R Clavicle" "Bip01 Neck" -0.008324 0.011447 -1.352377 78.187716 179.955964 0.001261 0 0 0 0 0 0
$definebone "Bip01 R UpperArm" "Bip01 R Clavicle" 6.078085 0 0.000004 -2.568169 -88.156774 72.74381 0 0 0 0 0 0
$definebone "Bip01 R Forearm" "Bip01 R UpperArm" 13.446774 0.000347 0.000048 0.000516 -3.95908 0.000171 0 0 0 0 0 0
$definebone "Bip01 R Hand" "Bip01 R Forearm" 15.996996 0.000362 0.000198 -0.000974 -0.000343 96.453951 0 0 0 0 0 0
$definebone "Dummy14" "Bip01 R Hand" -2.696754 7.324316 -1.920834 0.655577 90.896376 1.066447 0 0 0 0 0 0
$definebone "muzzle" "Bip01 R Hand" 35.01926 7.487988 -2.08086 -1.064139 -179.116329 90.655653 0 0 0 0 0 0
$definebone "Bip01 L Clavicle" "Bip01 Neck" 0.003906 0.011446 1.352395 -78.705609 179.95412 0.00063 0 0 0 0 0 0
$definebone "Bip01 L UpperArm" "Bip01 L Clavicle" 6.078087 0.00001 0 2.570002 -88.156254 -72.743775 0 0 0 0 0 0
$definebone "Bip01 L Forearm" "Bip01 L UpperArm" 13.446751 -0.000118 -0.000002 0.000115 -3.958853 0.000002 0 0 0 0 0 0
$definebone "Bip01 L Hand" "Bip01 L Forearm" 15.997011 -0.000214 0.000034 0.000344 -0.000574 -96.454074 0 0 0 0 0 0
$definebone "Bip01 L Finger0" "Bip01 L Hand" 1.885342 0.833251 -2.177898 40.000146 -0.038728 -91.559806 0 0 0 0 0 0
$definebone "Bip01 L Finger01" "Bip01 L Finger0" 1.506973 0.000002 -0.000006 0.000112 -7.999792 0.000061 0 0 0 0 0 0
$definebone "Bip01 L Finger02" "Bip01 L Finger01" 0.798355 -0.000006 -0.000001 -0.000002 -6.500357 -0.000053 0 0 0 0 0 0
$definebone "Bip01 L Finger1" "Bip01 L Hand" 3.950314 -0.539917 -2.108883 8.999566 -0.007391 -0.0467 0 0 0 0 0 0
$definebone "Bip01 L Finger11" "Bip01 L Finger1" 1.545788 -0.000009 -0.000023 0.000005 26.999488 0.000572 0 0 0 0 0 0
$definebone "Bip01 L Finger12" "Bip01 L Finger11" 1.667393 0.000006 -0.000015 0.000005 25.000555 -0.000172 0 0 0 0 0 0
$definebone "Bip01 L Finger2" "Bip01 L Hand" 3.899471 -0.475413 -1.170902 -0.000515 -0.000114 -0.046127 0 0 0 0 0 0
$definebone "Bip01 L Finger21" "Bip01 L Finger2" 1.528221 -0.00001 -0.000023 0.000174 18.999857 0.000512 0 0 0 0 0 0
$definebone "Bip01 L Finger22" "Bip01 L Finger21" 1.528214 -0.000004 -0.000011 0.000118 27.499807 0.000284 0 0 0 0 0 0
$definebone "Bip01 L Finger3" "Bip01 L Hand" 3.89946 -0.431834 0.168213 -0.000516 -0.000057 -0.046184 0 0 0 0 0 0
$definebone "Bip01 L Finger31" "Bip01 L Finger3" 1.506962 -0.00001 -0.000008 -0.000112 24.499737 0.000225 0 0 0 0 0 0
$definebone "Bip01 L Finger32" "Bip01 L Finger31" 1.506962 -0.000002 -0.000019 0.000118 19.499878 0.000456 0 0 0 0 0 0
$definebone "Bip01 L Finger4" "Bip01 L Hand" 3.915634 -0.278044 1.402588 -0.000515 -0.000114 -0.046184 0 0 0 0 0 0
$definebone "Bip01 L Finger41" "Bip01 L Finger4" 1.333088 -0.000008 -0.000015 -0.000112 36.499995 0.000341 0 0 0 0 0 0
$definebone "Bip01 L Finger42" "Bip01 L Finger41" 1.159203 -0.000006 -0.000019 0.000176 12.49948 0.00057 0 0 0 0 0 0


$animation "a_Idle" "v_cremator_anims\a_Idle.smd" {
	fps 30
	loop
}

$animation "a_Draw" "v_cremator_anims\a_Draw.smd" {
	fps 30
}

$animation "a_Fire" "v_cremator_anims\a_Fire.smd" {
	fps 30
	loop
}

$sequence "Idle" {
	"a_Idle"
	activity "ACT_VM_IDLE" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "Draw" {
	"a_Draw"
	activity "ACT_VM_DRAW" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "Fire" {
	"a_Fire"
	activity "ACT_VM_PRIMARYATTACK" 1
	fadein 0.2
	fadeout 0.2
}
