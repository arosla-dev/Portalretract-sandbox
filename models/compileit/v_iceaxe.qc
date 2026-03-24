// Created by Crowbar 0.74

$modelname "Weapons/v_iceaxe.mdl"

$bodygroup "studio"
{
	studio "Iceaxe_reference.smd"
}


$contents "solid"

$illumposition -10.986 -25.919 -19.667

$cdmaterials "models\Weapons\V_hand\"
$cdmaterials "models\Weapons\V_iceaxe\"

$attachment "0" "tip" 0 0 0 rotate 0 0 0

$cbox 0 0 0 0 0 0

$bbox 10.813 -13.991 -37.21 41.025 -7.981 -2.123

$definebone "Bip01" "" 0.134137 21.745049 43.181469 0 -89.999927 0 0 0 0 0 0 0
$definebone "Bip01 Pelvis" "Bip01" 0 0 0 -89.980215 -89.999927 0 0 0 0 0 0 0
$definebone "Bip01 Spine" "Bip01 Pelvis" 4.443615 -0.00964 0.000006 -0.000057 0.045607 -0.000229 0 0 0 0 0 0
$definebone "Bip01 Neck" "Bip01 Spine" 12.111413 -0.011447 0 0 0 0 0 0 0 0 0 0
$definebone "Bip01 R Clavicle" "Bip01 Neck" 0.000009 0.011449 -1.352403 78.540823 179.953614 -0.000802 0 0 0 0 0 0
$definebone "Bip01 R UpperArm" "Bip01 R Clavicle" 6.078088 0.000001 0.000002 -2.569601 -88.156548 72.743762 0 0 0 0 0 0
$definebone "Bip01 R Forearm" "Bip01 R UpperArm" 13.446755 -0.000001 0 0 -3.959138 -0.000002 0 0 0 0 0 0
$definebone "Bip01 R Hand" "Bip01 R Forearm" 15.997 -0.000001 0 0 0 96.454354 0 0 0 0 0 0
$definebone "Bip01 R Finger0" "Bip01 R Hand" 1.885327 0.833277 2.177879 -40.000002 -0.038272 91.559587 0 0 0 0 0 0
$definebone "Bip01 R Finger01" "Bip01 R Finger0" 1.506962 0 0 0.000001 -7.999994 -0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger02" "Bip01 R Finger01" 0.798349 -0.000006 0 0.000001 -6.49999 -0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger1" "Bip01 R Hand" 3.950304 -0.539875 2.108873 -9.000016 -0.007219 0.046182 0 0 0 0 0 0
$definebone "Bip01 R Finger11" "Bip01 R Finger1" 1.545798 0 0 0.000003 26.999999 0.000003 0 0 0 0 0 0
$definebone "Bip01 R Finger12" "Bip01 R Finger11" 1.667398 -0.000002 0.000001 0.000001 24.999973 0.000005 0 0 0 0 0 0
$definebone "Bip01 R Finger2" "Bip01 R Hand" 3.899461 -0.475376 1.170894 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger21" "Bip01 R Finger2" 1.528215 0 -0.000001 0 19.000024 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger22" "Bip01 R Finger21" 1.528216 0.000001 -0.000005 -0.000001 27.499965 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger3" "Bip01 R Hand" 3.899461 -0.431804 -0.168222 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger31" "Bip01 R Finger3" 1.506964 0 0 0 24.500015 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger32" "Bip01 R Finger31" 1.506962 0 0.000006 -0.000001 19.499985 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger4" "Bip01 R Hand" 3.915634 -0.278019 -1.402606 0 0 0.045609 0 0 0 0 0 0
$definebone "Bip01 R Finger41" "Bip01 R Finger4" 1.333083 0 0.000003 -0.000001 36.499981 0.000001 0 0 0 0 0 0
$definebone "Bip01 R Finger42" "Bip01 R Finger41" 1.159203 0 0.000002 -0.000001 12.499986 0.000001 0 0 0 0 0 0
$definebone "tip" "Bip01 R Hand" 13.333944 0.905787 19.735237 -1.064753 -179.115414 90.655885 0 0 0 0 0 0

$animation "a_idle01" "v_iceaxe_anims\idle01.smd" {
	fps 30
	loop
}

$animation "a_draw" "v_iceaxe_anims\draw.smd" {
	fps 30
}

$animation "a_attackcm" "v_iceaxe_anims\attackcm.smd" {
	fps 30
}

$animation "a_attackch" "v_iceaxe_anims\attackch.smd" {
	fps 30
}

$animation "a_attacklm" "v_iceaxe_anims\attacklm.smd" {
	fps 30
}

$animation "a_attacklh" "v_iceaxe_anims\attacklh.smd" {
	fps 30
}

$animation "a_attackrm" "v_iceaxe_anims\attackrm.smd" {
	fps 30
}

$animation "a_attackrh" "v_iceaxe_anims\attackrh.smd" {
	fps 30
}

$animation "a_battackcm" "v_iceaxe_anims\battackcm.smd" {
	fps 30
}

$animation "a_battackch" "v_iceaxe_anims\battackch.smd" {
	fps 30
}

$animation "a_battacklm" "v_iceaxe_anims\battacklm.smd" {
	fps 30
}

$animation "a_battacklh" "v_iceaxe_anims\battacklh.smd" {
	fps 30
}

$animation "a_battackrm" "v_iceaxe_anims\battackrm.smd" {
	fps 30
}

$animation "a_battackrh" "v_iceaxe_anims\battackrh.smd" {
	fps 30
}

$sequence "idle01" {
	"a_idle01"
	activity "ACT_VM_IDLE" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "draw" {
	"a_draw"
	activity "ACT_VM_DRAW" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "attackcm" {
	"a_attackcm"
	activity "ACT_VM_MISSCENTER" 1
	fadein 0.2
	fadeout 0.2
	snap
}

$sequence "attackch" {
	"a_attackch"
	activity "ACT_VM_HITCENTER" 1
	fadein 0.2
	fadeout 0.2
	snap
}

$sequence "attacklm" {
	"a_attacklm"
	activity "ACT_VM_MISSLEFT" 1
	fadein 0.2
	fadeout 0.2
	snap
}

$sequence "attacklh" {
	"a_attacklh"
	activity "ACT_VM_HITLEFT" 1
	fadein 0.2
	fadeout 0.2
	snap
}

$sequence "attackrm" {
	"a_attackrm"
	activity "ACT_VM_MISSRIGHT" 1
	fadein 0.2
	fadeout 0.2
	snap
}

$sequence "attackrh" {
	"a_attackrh"
	activity "ACT_VM_HITRIGHT" 1
	fadein 0.2
	fadeout 0.2
	snap
}

$sequence "battackcm" {
	"a_battackcm"
	activity "ACT_VM_MISSCENTER2" 1
	fadein 0.2
	fadeout 0.2
	snap
}

$sequence "battackch" {
	"a_battackch"
	activity "ACT_VM_HITCENTER2" 1
	fadein 0.2
	fadeout 0.2
	snap
}

$sequence "battacklm" {
	"a_battacklm"
	activity "ACT_VM_MISSLEFT2" 1
	fadein 0.2
	fadeout 0.2
	snap
}

$sequence "battacklh" {
	"a_battacklh"
	activity "ACT_VM_HITLEFT2" 1
	fadein 0.2
	fadeout 0.2
	snap
}

$sequence "battackrm" {
	"a_battackrm"
	activity "ACT_VM_MISSRIGHT2" 1
	fadein 0.2
	fadeout 0.2
	snap
}

$sequence "battackrh" {
	"a_battackrh"
	activity "ACT_VM_HITRIGHT2" 1
	fadein 0.2
	fadeout 0.2
	snap
}

