// Created by Crowbar 0.74

$modelname "cremator_npc.mdl"

$bodygroup "studio"
{
	studio "cremator_ref.smd"
}
$bodygroup "gun"
{
	studio "gun_reference.smd"
	blank
}
$bodygroup "head"
{
	studio "Head_Original.smd"
	blank
}


$surfaceprop "alienflesh"

$contents "solid"

$illumposition 16.64 -0.291 43.756

$eyeposition 0 0 95.5

$cdmaterials "models\cremator\\"

$attachment "1" "muzzle" 0 0 0 rotate 45 -90 0
$attachment "0" "muzzle" 0 0 0 rotate 45 -90 0
$attachment "footleft" "ValveBiped.Bip01_L_Foot" 5 0 0 rotate 0 -180 180
$attachment "footright" "ValveBiped.Bip01_R_Foot" 5 0 0 rotate 0 -180 180
$attachment "anim_attachment_LH" "ValveBiped.Bip01_L_Hand" 0 0 0 rotate -90 90 0

$cbox 0 0 0 0 0 0

$bbox -28.958 -29.966 -1.375 45.341 24.917 92.743

$hboxset "default"
$hbox 3 "ValveBiped.Bip01_Pelvis" -26.628 -7.951 -14.889 14.62 15.188 12.608
$hbox 2 "ValveBiped.Bip01_Spine" -10.39 0.91 -7.5 4.61 15.91 7.5
$hbox 0 "ValveBiped.Bip01_Spine1" -0.732 -8.705 -17.540001 22.916 15.704 16.552999
$hbox 1 "ValveBiped.Bip01_Neck" 0 -8.424 -8.561 13.33 9.402 9.118
$hbox 1 "ValveBiped.Bip01_Neck1" 0 -8.424 -8.561 13.33 9.402 9.118
$hbox 1 "ValveBiped.Bip01_Head" 0 -4.271 -5.838 11.778 6.894 5.382
$hbox 4 "ValveBiped.Bip01_L_UpperArm" 0 -1.862 -1.531 19.849001 2.177 1.97
$hbox 4 "ValveBiped.Bip01_L_Forearm" -4.926 -2.554 -1.927 18.132999 3.004 1.996
$hbox 4 "ValveBiped.Bip01_L_Hand" -2.605 -1.645 -2.47 9.969 2.768 3.43
$hbox 5 "ValveBiped.Bip01_R_UpperArm" 0 -1.89 -1.987 19.872 2.086 1.515
$hbox 5 "ValveBiped.Bip01_R_Forearm" -4.987 -2.583 -2.013 18.249001 3.011 1.91
$hbox 6 "ValveBiped.Bip01_L_Thigh" 0 -5.404 -6 22.312 1.664 0
$hbox 6 "ValveBiped.Bip01_L_Calf" 0 -5.871 -5.55 27.782 11.678 5.269
$hbox 6 "ValveBiped.Bip01_L_Foot" -5.194 -4.273 -4.874 5.179 11.354 4.772
$hbox 7 "ValveBiped.Bip01_R_Thigh" 0 -5.336 0 22.312 0 2.712
$hbox 7 "ValveBiped.Bip01_R_Calf" 0 -5.958 -4.729 27.695 11.728 6.155
$hbox 7 "ValveBiped.Bip01_R_Foot" -5.171 -4.185 -4.194 5.148 11.403 5.772
$hbox 10 "Object08" -5.845 -54.750999 -6.103 18.108999 4.537 5.549
$skipboneinbbox

$definebone "ValveBiped.Bip01" "" 0.071583 2.828451 49.705528 0 -89.999921 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Pelvis" "ValveBiped.Bip01" 0.623697 0 0 -89.999982 -89.994702 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Spine" "ValveBiped.Bip01_Pelvis" 5.131859 -0.003106 0.000007 -0.000057 1.993148 -0.000229 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Spine1" "ValveBiped.Bip01_Spine" 3.906616 -0.00329 0 0 2.664998 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Spine2" "ValveBiped.Bip01_Spine1" 4.136856 -0.008541 0 0 3.997469 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Neck" "ValveBiped.Bip01_Spine2" 10.751457 -0.002665 0 0 1.718873 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Neck1" "ValveBiped.Bip01_Neck" 3.346909 -0.003645 0 0 1.718873 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Clavicle" "ValveBiped.Bip01_Neck" -3.078369 -1.591919 2.889395 -78.539048 179.247496 -1.032584 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_UpperArm" "ValveBiped.Bip01_L_Clavicle" 6.038856 0 0 47.595043 -23.394286 -10.580067 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Forearm" "ValveBiped.Bip01_L_UpperArm" 17.594574 -0.000004 -0.000008 0.000015 -12.039166 -0.000012 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Hand" "ValveBiped.Bip01_L_Forearm" 17.98299 -0.000005 -0.000008 -0.070399 2.925975 -134.358427 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger0" "ValveBiped.Bip01_L_Hand" 2.81369 0.799023 -0.493425 51.477572 67.103207 98.41804 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger01" "ValveBiped.Bip01_L_Finger0" 2.065374 0.000004 0 -0.000006 8.097494 0.00002 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger02" "ValveBiped.Bip01_L_Finger01" 2.094709 -0.000004 -0.000002 -0.000003 -5.842512 0.000019 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger1" "ValveBiped.Bip01_L_Hand" 7.522002 -0.014961 -1.158102 10.271413 11.990586 1.403791 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger11" "ValveBiped.Bip01_L_Finger1" 3.20083 0 0 -0.000001 7.79882 -0.00001 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger12" "ValveBiped.Bip01_L_Finger11" 2.731236 -0.000002 0 -0.000004 -19.000017 -0.00001 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger2" "ValveBiped.Bip01_L_Hand" 7.599247 -0.14451 0.591978 -10.695409 1.497723 1.378529 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger21" "ValveBiped.Bip01_L_Finger2" 3.840996 0 0.000002 -0.000004 7.798822 -0.00001 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger22" "ValveBiped.Bip01_L_Finger21" 3.277487 0 0.000002 -0.000005 0.000005 -0.000009 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger3" "ValveBiped.Bip01_L_Hand" 7.447636 -0.525784 2.367266 -10.512346 16.793909 -1.264927 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger31" "ValveBiped.Bip01_L_Finger3" 1.595201 0 0.000002 -0.000006 -0.000002 -0.00001 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger32" "ValveBiped.Bip01_L_Finger31" 1.772444 0 0 -0.000007 -0.000002 -0.000012 0 0 0 0 0 0
$definebone "LSleeve" "ValveBiped.Bip01_L_UpperArm" 2.842163 2.176877 -0.812283 2.277663 172.239708 -79.222695 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Clavicle" "ValveBiped.Bip01_Neck" -3.078384 -1.591902 -2.889401 78.539048 179.245897 1.03098 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_UpperArm" "ValveBiped.Bip01_R_Clavicle" 6.038855 0 0 -47.595036 -23.394267 10.580065 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Forearm" "ValveBiped.Bip01_R_UpperArm" 17.594566 -0.000003 0.000023 -0.000003 -12.03916 0.000003 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Hand" "ValveBiped.Bip01_R_Forearm" 17.982996 -0.000004 0.000011 -0.274851 2.563531 136.356845 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger0" "ValveBiped.Bip01_R_Hand" 2.813692 0.799026 0.493431 -51.477565 67.103221 -98.418047 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger01" "ValveBiped.Bip01_R_Finger0" 2.065372 -0.000004 0 0.000002 8.0975 -0.000014 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger02" "ValveBiped.Bip01_R_Finger01" 2.094709 0 -0.000002 0.000001 -5.842507 -0.000014 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger1" "ValveBiped.Bip01_R_Hand" 7.521999 -0.014961 1.158108 -10.271405 11.990571 -1.403805 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger11" "ValveBiped.Bip01_R_Finger1" 3.200829 0 -0.000004 0.000009 7.798814 -0.000003 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger12" "ValveBiped.Bip01_R_Finger11" 2.731236 0.000004 0.000004 0.000009 -19.000027 -0.000007 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger2" "ValveBiped.Bip01_R_Hand" 7.599252 -0.144506 -0.591976 10.695406 1.497713 -1.37854 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger21" "ValveBiped.Bip01_R_Finger2" 3.841 0.000004 -0.000004 0.000002 7.798811 -0.000003 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger22" "ValveBiped.Bip01_R_Finger21" 3.277483 0.000004 -0.000004 0.000003 -0.000002 -0.000003 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger3" "ValveBiped.Bip01_R_Hand" 7.44764 -0.525784 -2.367264 10.512348 16.793907 1.264913 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger31" "ValveBiped.Bip01_R_Finger3" 1.5952 0 -0.000002 0.000005 -0.000006 -0.000007 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger32" "ValveBiped.Bip01_R_Finger31" 1.772448 -0.000004 0.000004 0.000004 -0.000005 -0.000007 0 0 0 0 0 0
$definebone "muzzle" "ValveBiped.Bip01_R_Hand" 49.389557 35.06768 12.791965 24.239267 116.87302 -59.446879 0 0 0 0 0 0
$definebone "RSleave" "ValveBiped.Bip01_R_UpperArm" 2.662819 2.086401 1.145603 0.249682 -172.063503 -100.987291 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Thigh" "ValveBiped.Bip01_Spine" -5.128643 0.181574 6.425845 -0.030403 172.281686 171.391371 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Calf" "ValveBiped.Bip01_L_Thigh" 22.311977 0 -0.000001 0 -11.459383 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Foot" "ValveBiped.Bip01_L_Calf" 22.311974 0.000004 0 0.825689 5.793807 -10.495843 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Toe0" "ValveBiped.Bip01_L_Foot" 5.131754 6.470467 -0.000001 0.000003 89.999982 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Thigh" "ValveBiped.Bip01_Spine" -5.128643 0.181607 -6.425845 0.030348 172.281686 -171.391713 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Calf" "ValveBiped.Bip01_R_Thigh" 22.311975 -0.000001 0 0 -11.459383 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Foot" "ValveBiped.Bip01_R_Calf" 22.31197 0.000003 0 -0.825689 5.793807 10.495903 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Toe0" "ValveBiped.Bip01_R_Foot" 5.131753 6.470465 0.000001 -0.000002 89.999982 0 0 0 0 0 0 0
$definebone "LBack_Flapa" "ValveBiped.Bip01_Pelvis" -11.211914 -5.662892 9.248472 -75.946588 -4.663704 -85.629399 0 0 0 0 0 0
$definebone "LBack_Flapb" "LBack_Flapa" -0.444927 -22.402105 -1.024192 -0.508959 -1.780697 -0.423187 0 0 0 0 0 0
$definebone "RBack_Flapa" "ValveBiped.Bip01_Pelvis" -7.890469 -7.554842 -9.35337 -78.890556 -167.807366 81.83934 0 0 0 0 0 0
$definebone "RBack_Flapb" "RBack_Flapa" 1.283812 -15.381767 -4.479879 -0.048644 2.073764 13.73569 0 0 0 0 0 0
$definebone "RFront_Flapa" "ValveBiped.Bip01_Pelvis" -12.521675 11.793074 -9.009841 -78.890618 -167.807311 81.839231 0 0 0 0 0 0
$definebone "RFront_Flapb" "RFront_Flapa" 0.785918 -24.943205 -6.367156 -0.285906 3.191432 21.285557 0 0 0 0 0 0
$definebone "Flap3a_Helper" "ValveBiped.Bip01_Pelvis" -10.979866 8.818287 -8.086378 -78.890618 -167.807229 81.839231 0 0 0 0 0 0
$definebone "Flap3b_Helper" "Flap3a_Helper" -0.64131 -11.527763 1.210023 0 -0.000002 -0.000001 0 0 0 0 0 0
$definebone "Flap3c_Helper" "Flap3b_Helper" -0.227779 -19.832264 -4.903646 -0.120779 2.498783 16.583177 0 0 0 0 0 0
$definebone "LFront_Flapa" "ValveBiped.Bip01_Pelvis" -13.121273 11.560147 6.323208 -89.999982 -90.000037 0 0 0 0 0 0 0
$definebone "LFront_Flapb" "LFront_Flapa" -0.186435 -22.871979 -2.848151 0.004526 -2.330449 11.350636 0 0 0 0 0 0
$definebone "Bip01" "" 0.071583 2.828451 49.705528 0 -89.999921 0 0 0 0 0 0 0
$definebone "Bip01 Pelvis" "Bip01" 0.623697 0 0 -89.980215 -89.999921 0 0 0 0 0 0 0
$definebone "Bip01 Spine" "Bip01 Pelvis" 5.131855 -0.003106 0.000007 -0.000057 1.993148 -0.000229 0 0 0 0 0 0
$definebone "Bip01 Spine1" "Bip01 Spine" 3.90662 -0.00329 0 0 2.664998 0 0 0 0 0 0 0
$definebone "Bip01 Spine2" "Bip01 Spine1" 4.136856 -0.008541 0 0 3.997469 0 0 0 0 0 0 0
$definebone "Bip01 Neck" "Bip01 Spine2" 10.751476 -0.002666 0 0 1.718871 0 0 0 0 0 0 0
$definebone "Bip01 R Clavicle" "Bip01 Neck" -3.0784 -1.591904 -2.889401 78.539048 179.245897 1.03098 0 0 0 0 0 0
$definebone "Bip01 R UpperArm" "Bip01 R Clavicle" 6.038857 0.000001 -0.000008 -47.595043 -23.394282 10.580065 0 0 0 0 0 0
$definebone "Bip01 R Forearm" "Bip01 R UpperArm" 17.594566 -0.000003 0.000008 -0.000007 -12.039163 0.000009 0 0 0 0 0 0
$definebone "Bip01 R Hand" "Bip01 R Forearm" 17.982994 -0.000002 -0.000004 -0.274855 2.563523 136.356845 0 0 0 0 0 0
$definebone "Object08" "Bip01 R Hand" 4.004553 6.047382 1.789421 6.986763 121.004615 -14.911852 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Head" "ValveBiped.Bip01_Neck1" 4.579819 0 0 0.000057 -12.09342 0 0 0 0 0 0 0

$bonemerge "ValveBiped.Bip01"
$bonemerge "ValveBiped.Bip01_Pelvis"
$bonemerge "ValveBiped.Bip01_Spine"
$bonemerge "ValveBiped.Bip01_Spine1"
$bonemerge "ValveBiped.Bip01_Spine2"
$bonemerge "ValveBiped.Bip01_Neck"
$bonemerge "ValveBiped.Bip01_R_Clavicle"
$bonemerge "ValveBiped.Bip01_R_UpperArm"
$bonemerge "ValveBiped.Bip01_R_Forearm"
$bonemerge "ValveBiped.Bip01_R_Hand"


$sectionframes 30 154

$poseparameter "ZR" -180 180 loop 0

$animation "a_walk1" "cremator_npc_anims\a_walk1.smd" {
	fps 30
	loop
	walkframe 37 LX LY
}

$animation "a_run" "cremator_npc_anims\a_run.smd" {
	fps 36
	loop
	walkframe 37 LX LY
}

$animation "a_limp1" "cremator_npc_anims\a_limp1.smd" {
	fps 30
	loop
	walkframe 37 LX LY
}

$animation "a_flich1" "cremator_npc_anims\a_flich1.smd" {
	fps 30
	loop
}

$animation "a_fireupleft" "cremator_npc_anims\a_fireupleft.smd" {
	fps 30
	loop
}

$animation "a_fireupright" "cremator_npc_anims\a_fireupright.smd" {
	fps 30
	loop
}

$animation "a_fireinoutsw" "cremator_npc_anims\a_fireinoutsw.smd" {
	fps 30
	loop
}

$animation "a_breathing" "cremator_npc_anims\a_breathing.smd" {
	fps 30
	loop
}

$animation "a_firebreathing1" "cremator_npc_anims\a_firebreathing1.smd" {
	fps 30
	loop
}

$animation "a_fireimmo" "cremator_npc_anims\a_fireimmo.smd" {
	fps 30
	loop
}

$animation "a_walkdeployed" "cremator_npc_anims\a_walkdeployed.smd" {
	fps 30
	loop
}

$animation "a_rundeployed" "cremator_npc_anims\a_rundeployed.smd" {
	fps 36
	loop
}

$animation "a_firestart" "cremator_npc_anims\a_firestart.smd" {
	fps 30
}

$animation "a_firestop" "cremator_npc_anims\a_firestop.smd" {
	fps 30
}

$animation "a_fireinout" "cremator_npc_anims\a_fireinout.smd" {
	fps 30
	loop
}

$animation "a_ragdoll" "cremator_npc_anims\a_ragdoll.smd" {
	fps 30
}

$sequence "walk1" {
	"a_walk1"
	activity "ACT_WALK" 1
	{ event 5 0 "" }
	{ event 0 20 "Crem.Footstep" }
	{ event 0 2 "Crem.Swish" }
	{ event 0 26 "Crem.Swish" }
	{ event 0 33 "Crem.Swish" }
	{ event 0 35 "Crem.Footstep" }
	fadein 0.2
	fadeout 0.2
}

$sequence "run" {
	"a_run"
	activity "ACT_RUN" 1
	{ event 5 0 "" }
	{ event 0 20 "Crem.Footstep" }
	{ event 0 2 "Crem.Swish" }
	{ event 0 26 "Crem.Swish" }
	{ event 0 33 "Crem.Swish" }
	{ event 0 35 "Crem.Footstep" }
	fadein 0.2
	fadeout 0.2
}

$sequence "limp1" {
	"a_limp1"
	activity "ACT_WALK_HURT" 1
	{ event 5 0 "" }
	{ event 0 20 "Crem.Footstep" }
	{ event 0 2 "Crem.Swish" }
	{ event 0 16 "Crem.Swish" }
	{ event 0 28 "Crem.Swish" }
	{ event 0 30 "Crem.Footstep" }
	fadein 0.2
	fadeout 0.2
}

$sequence "flich1" {
	"a_flich1"
	activity "ACT_SMALL_FLINCH" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "fireupleft" {
	"a_fireupleft"
	activity "ACT_FIREUPLEFT" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "fireupright" {
	"a_fireupright"
	activity "ACT_FIREUPRIGHT" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "fireinoutsw" {
	"a_fireinoutsw"
	activity "ACT_FIRESPREAD" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "breathing" {
	"a_breathing"
	activity "ACT_IDLE" 1
	{ event 5 1 "" }
	fadein 0.2
	fadeout 0.2
}

$sequence "firebreathing1" {
	"a_firebreathing1"
	activity "ACT_IDLE_ANGRY" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "fireimmo" {
	"a_fireimmo"
	activity "ACT_RANGE_ATTACK1" 1
	{ event 4 3 "" }
	{ event 4 6 "" }
	{ event 4 9 "" }
	{ event 4 12 "" }
	{ event 4 15 "" }
	{ event 4 18 "" }
	{ event 4 21 "" }
	{ event 4 24 "" }
	{ event 4 27 "" }
	{ event 4 30 "" }
	{ event 4 33 "" }
	{ event 4 36 "" }
	{ event 4 39 "" }
	{ event 4 42 "" }
	{ event 4 45 "" }
	{ event 4 48 "" }
	{ event 4 51 "" }
	{ event 4 54 "" }
	{ event 4 57 "" }
	{ event 4 60 "" }
	{ event 4 63 "" }
	{ event 4 66 "" }
	{ event 4 69 "" }
	{ event 4 72 "" }
	{ event 4 75 "" }
	{ event 4 78 "" }
	{ event 4 81 "" }
	{ event 4 84 "" }
	{ event 4 87 "" }
	{ event 4 90 "" }
	{ event 4 93 "" }
	{ event 4 96 "" }
	{ event 4 99 "" }
	{ event 4 102 "" }
	{ event 4 105 "" }
	{ event 4 108 "" }
	{ event 4 111 "" }
	{ event 4 114 "" }
	{ event 4 117 "" }
	{ event 4 120 "" }
	{ event 4 123 "" }
	{ event 4 126 "" }
	{ event 4 129 "" }
	{ event 4 132 "" }
	{ event 4 135 "" }
	{ event 4 138 "" }
	{ event 4 141 "" }
	{ event 4 144 "" }
	{ event 4 147 "" }
	{ event 4 150 "" }
	{ event 5 153 "" }
	fadein 0.2
	fadeout 0.2
}

$sequence "walkdeployed" {
	"a_walkdeployed"
	activity "ACT_WALK_DEPLOYED" 1
	{ event 4 3 "" }
	{ event 4 6 "" }
	{ event 4 9 "" }
	{ event 4 12 "" }
	{ event 4 15 "" }
	{ event 4 18 "" }
	{ event 4 21 "" }
	{ event 4 24 "" }
	{ event 4 27 "" }
	{ event 4 30 "" }
	{ event 4 33 "" }
	{ event 5 36 "" }
	fadein 0.2
	fadeout 0.2
}

$sequence "rundeployed" {
	"a_rundeployed"
	activity "ACT_RUN_DEPLOYED" 1
	{ event 4 3 "" }
	{ event 4 6 "" }
	{ event 4 9 "" }
	{ event 4 12 "" }
	{ event 4 15 "" }
	{ event 4 18 "" }
	{ event 4 21 "" }
	{ event 4 24 "" }
	{ event 4 27 "" }
	{ event 4 30 "" }
	{ event 4 33 "" }
	{ event 5 36 "" }
	fadein 0.2
	fadeout 0.2
}

$sequence "firestart" {
	"a_firestart"
	activity "ACT_MELEE_ATTACK1" 1
	{ event 2 9 "" }
	{ event 1 10 "" }
	fadein 0.2
	fadeout 0.2
}

$sequence "firestop" {
	"a_firestop"
	activity "ACT_CREMATOR_DISARM" 1
	{ event 8 1 "" }
	fadein 0.2
	fadeout 0.2
}

$sequence "fireinout" {
	"a_fireinout"
	activity "ACT_RANGE_ATTACK4" 1
	{ event 4 57 "" }
	{ event 4 60 "" }
	{ event 4 63 "" }
	{ event 4 66 "" }
	{ event 4 69 "" }
	{ event 4 72 "" }
	{ event 4 75 "" }
	{ event 4 76 "" }
	{ event 4 79 "" }
	{ event 4 82 "" }
	{ event 4 85 "" }
	{ event 4 88 "" }
	{ event 4 91 "" }
	{ event 4 94 "" }
	{ event 4 97 "" }
	{ event 4 100 "" }
	{ event 4 103 "" }
	{ event 4 106 "" }
	{ event 4 109 "" }
	{ event 4 112 "" }
	{ event 4 115 "" }
	{ event 4 118 "" }
	{ event 4 121 "" }
	{ event 4 124 "" }
	{ event 4 127 "" }
	{ event 4 130 "" }
	{ event 4 133 "" }
	{ event 4 136 "" }
	{ event 4 139 "" }
	{ event 4 142 "" }
	{ event 4 145 "" }
	{ event 4 148 "" }
	{ event 4 151 "" }
	{ event 4 154 "" }
	{ event 4 157 "" }
	{ event 4 160 "" }
	{ event 4 163 "" }
	{ event 4 166 "" }
	{ event 4 169 "" }
	{ event 4 172 "" }
	{ event 4 175 "" }
	{ event 4 178 "" }
	{ event 4 181 "" }
	{ event 4 184 "" }
	{ event 4 187 "" }
	{ event 4 190 "" }
	{ event 4 193 "" }
	{ event 4 196 "" }
	{ event 4 199 "" }
	{ event 5 200 "" }
	fadein 0.2
	fadeout 0.2
}

$sequence "ragdoll" {
	"a_ragdoll"
	activity "ACT_DIERAGDOLL" 1
	fadein 0.2
	fadeout 0.2
}

$collisionjoints "cremator_npc_physics.smd"
{
	$mass 0
	$inertia 5
	$damping 0.01
	$rotdamping 1.5
	$rootbone " "


	$jointconstrain "RFront_Flapa" x limit -6 6 0.2
	$jointconstrain "RFront_Flapa" y limit 0 0 0
	$jointconstrain "RFront_Flapa" z limit 0 0 0

	$jointconstrain "RBack_Flapa" x limit -6 6 0.2
	$jointconstrain "RBack_Flapa" y limit 0 0 0
	$jointconstrain "RBack_Flapa" z limit 0 0 0

	$jointconstrain "LBack_Flapa" x limit -6 6 0.2
	$jointconstrain "LBack_Flapa" y limit 0 0 0
	$jointconstrain "LBack_Flapa" z limit 0 0 0

	$jointconstrain "ValveBiped.Bip01_R_Thigh" x limit 0 0 0.2
	$jointconstrain "ValveBiped.Bip01_R_Thigh" y limit -5 5 0.2
	$jointconstrain "ValveBiped.Bip01_R_Thigh" z limit -6 -1 0.2

	$jointconstrain "ValveBiped.Bip01_R_Calf" x limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_R_Calf" y limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_R_Calf" z limit -15 3 0.2

	$jointconstrain "ValveBiped.Bip01_L_Thigh" x limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_L_Thigh" y limit -5 5 0.2
	$jointconstrain "ValveBiped.Bip01_L_Thigh" z limit -6 1 0.2

	$jointconstrain "ValveBiped.Bip01_L_Calf" x limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_L_Calf" y limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_L_Calf" z limit -15 3 0.2

	$jointconstrain "ValveBiped.Bip01_Spine2" x limit -6 6 0.2
	$jointconstrain "ValveBiped.Bip01_Spine2" y limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_Spine2" z limit -22 31 0.2

	$jointconstrain "ValveBiped.Bip01_R_UpperArm" x limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_R_UpperArm" y limit -6 6 0.2
	$jointconstrain "ValveBiped.Bip01_R_UpperArm" z limit -30 30 0.2

	$jointconstrain "ValveBiped.Bip01_R_Forearm" x limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_R_Forearm" y limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_R_Forearm" z limit -50 0 0.2

	$jointconstrain "ValveBiped.Bip01_L_UpperArm" x limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_L_UpperArm" y limit -6 6 0.2
	$jointconstrain "ValveBiped.Bip01_L_UpperArm" z limit -30 30 0.2

	$jointconstrain "ValveBiped.Bip01_L_Forearm" x limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_L_Forearm" y limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_L_Forearm" z limit -50 0 0.2

	$jointconstrain "ValveBiped.Bip01_L_Hand" x limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_L_Hand" y limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_L_Hand" z limit 0 20 0.2

	$jointconstrain "ValveBiped.Bip01_R_Hand" x limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_R_Hand" y limit 0 0 0
	$jointconstrain "ValveBiped.Bip01_R_Hand" z limit 0 20 0.2

	$jointconstrain "LFront_Flapa" x limit -8 8 0.2
	$jointconstrain "LFront_Flapa" y limit 0 0 0
	$jointconstrain "LFront_Flapa" z limit 0 0 0
}

$collisiontext
{
	animatedfriction 
	{
		"animfrictionmin" "1.000000"
		"animfrictionmax" "400.000000"
		"animfrictiontimein" "0.500000"
		"animfrictiontimeout" "0.300000"
		"animfrictiontimehold" "0.000000"
	}
	editparams 
	{
		"rootname" "ValveBiped.Bip01_spine"
		"totalmass" "100.000000"
	}
}
