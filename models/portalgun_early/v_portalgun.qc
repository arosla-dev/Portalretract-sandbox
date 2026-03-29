// Created by Crowbar 0.74

$modelname "weapons/v_portalgun_early.mdl"

$bodygroup "studio"
{
	studio "v_portalgun_reference.smd"
}
$bodygroup "chips"
{
	studio "v_portalgun_chip_1.smd"
	studio "v_portalgun_chip_both.smd"
	studio "v_portalgun_chip_2.smd"
}


$surfaceprop "default"

$contents "solid"

$illumposition -1.325 -29.59 -7.361

$cdmaterials "models\Weapons\v_models\v_portalgun_early"

$attachment "Arm1_attach1" "ValveBiped.Arm1_A" 0 0 0 rotate 0 0 0
$attachment "Arm1_attach2" "ValveBiped.Arm1_B" 0 0.2 -0.1 rotate 0 0 0
$attachment "Arm1_attach3" "ValveBiped.Arm1_B" 0 -2 3.25 rotate 0 0 0
$attachment "Arm2_attach1" "ValveBiped.Arm2_A" 0 0 0 rotate 0 0 0
$attachment "Arm2_attach2" "ValveBiped.Arm2_B" 0 0.2 -0.1 rotate 0 0 0
$attachment "Arm2_attach3" "ValveBiped.Arm2_B" 0 -2 3.25 rotate 0 0 0
$attachment "Arm3_attach1" "ValveBiped.Arm4_A" 0 0 -0.3 rotate 0 0 0
$attachment "Arm3_attach2" "ValveBiped.Arm4_B" -0.1 0.3 -0.1 rotate 0 0 0
$attachment "Arm3_attach3" "ValveBiped.Arm4_B" 0 -2 3.25 rotate 0 0 0
$attachment "Body_light" "ValveBiped.Base" 0.3 3.4 10.55 rotate 0 0 0
$attachment "Body_light_blue" "ValveBiped.Base" 2.5 3.7 10.55 rotate 0 0 0
$attachment "Body_light_purple" "ValveBiped.Base" 1.9 4 10.55 rotate 0 0 0
$attachment "Beam_point1" "ValveBiped.Mag4_RotZ" 0 0 0 rotate 0 0 0
$attachment "Beam_point2" "ValveBiped.Mag5_RotZ" 0 0 0 rotate 0 0 0
$attachment "Beam_point3" "ValveBiped.Mag6_RotZ" 0 0 0 rotate 0 0 0
$attachment "Beam_point4" "ValveBiped.Mag7_RotZ" 0 0 0 rotate 0 0 0
$attachment "Beam_point5" "ValveBiped.Mag8_RotZ" 0 0 0 rotate 0 0 0
$attachment "Inside_effects" "ValveBiped.Mag9_RotZ" 0 0 0 rotate 0 0 0
$attachment "muzzle" "ValveBiped.Mag9_RotZ" 0 2.2 2.8 rotate -90 0 0

$cbox 0 0 0 0 0 0

$bbox -1.521 -17.501 -19.468 60.292 17.019 5.709

$definebone "ValveBiped.Bip01" "" 0 -0.533595 38.566879 0 0 89.999982 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Spine" "ValveBiped.Bip01" 0 3.345131 -2.981898 4.766608 89.999982 89.999982 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Spine1" "ValveBiped.Bip01_Spine" 3.995838 0 0 0 -1.651035 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Spine2" "ValveBiped.Bip01_Spine1" 3.520283 0 0 0 5.57528 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Spine4" "ValveBiped.Bip01_Spine2" 8.921463 0 0 0 10.680679 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Clavicle" "ValveBiped.Bip01_Spine4" 2.059513 0.97792 1.937661 -73.711873 169.030981 91.085395 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_UpperArm" "ValveBiped.Bip01_L_Clavicle" 15.71209 -18.004032 9.529779 -78.995598 179.290362 89.335534 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Forearm" "ValveBiped.Bip01_L_UpperArm" 11.692564 0 0.000011 -0.000004 -42.733014 -0.000003 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Hand" "ValveBiped.Bip01_L_Forearm" 11.481674 0.000001 -0.000034 5.028162 42.789359 76.158699 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger4" "ValveBiped.Bip01_L_Hand" 3.850418 0.126099 -1.22344 -10.466672 -67.332053 -18.180871 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger41" "ValveBiped.Bip01_L_Finger4" 1.312561 0 0 2.377089 -63.774842 -2.017388 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger42" "ValveBiped.Bip01_L_Finger41" 0.729366 0.000004 0 2.211448 -32.527659 -0.749154 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger3" "ValveBiped.Bip01_L_Hand" 3.92635 0.31649 -0.462519 -9.114025 -62.422274 -9.677951 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger31" "ValveBiped.Bip01_L_Finger3" 1.539101 0 -0.000002 0.099645 -76.471474 -0.189547 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger32" "ValveBiped.Bip01_L_Finger31" 1.196331 -0.000002 0 0.253865 -68.765928 -0.245869 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger2" "ValveBiped.Bip01_L_Hand" 3.88138 0.214687 0.400251 -11.728137 -59.038332 -3.241511 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger21" "ValveBiped.Bip01_L_Finger2" 1.719583 0.000004 0 -0.453555 -88.178316 1.079314 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger22" "ValveBiped.Bip01_L_Finger21" 1.209183 -0.000001 0.000008 -0.464569 -57.21837 0.461908 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger1" "ValveBiped.Bip01_L_Hand" 3.871292 0.117424 1.300905 -10.911283 -66.478873 -1.148328 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger11" "ValveBiped.Bip01_L_Finger1" 1.719425 -0.000004 0.000002 -1.846477 -92.328414 5.800099 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger12" "ValveBiped.Bip01_L_Finger11" 1.099674 0.000004 -0.000004 -3.048259 -51.971336 2.423266 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger0" "ValveBiped.Bip01_L_Hand" 0.838839 -0.300285 1.312777 -27.949167 -36.053027 -48.55743 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger01" "ValveBiped.Bip01_L_Finger0" 1.789783 -0.000002 0.000011 -0.21022 21.707839 -0.03185 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger02" "ValveBiped.Bip01_L_Finger01" 1.207006 0.000001 0.000004 -0.310148 38.061868 -0.096366 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Clavicle" "ValveBiped.Bip01_Spine4" 2.059517 0.977922 -1.937661 73.711873 169.030994 -95.200891 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_UpperArm" "ValveBiped.Bip01_R_Clavicle" 7.186439 -2.479385 7.933254 41.250897 -73.337216 97.486136 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Forearm" "ValveBiped.Bip01_R_UpperArm" 11.69257 -0.000004 0 0.000001 -42.140761 -0.000003 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Hand" "ValveBiped.Bip01_R_Forearm" 11.481654 0 0.000016 10.385554 -11.253239 -92.297658 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger4" "ValveBiped.Bip01_R_Hand" 3.850428 0.126099 1.223438 3.404291 -70.83387 12.515342 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger41" "ValveBiped.Bip01_R_Finger4" 1.312562 0.000001 0 -3.019139 -37.868256 0.776703 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger42" "ValveBiped.Bip01_R_Finger41" 0.729362 0 0 -1.183901 -73.35395 2.012566 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger3" "ValveBiped.Bip01_R_Hand" 3.926355 0.316488 0.462502 1.051095 -60.276836 4.522182 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger31" "ValveBiped.Bip01_R_Finger3" 1.539096 0 -0.000008 -0.124389 -68.678597 0.174234 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger32" "ValveBiped.Bip01_R_Finger31" 1.196321 0.000002 0.000011 -0.229644 -74.156218 0.268602 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger2" "ValveBiped.Bip01_R_Hand" 3.881386 0.214694 -0.400257 -0.12553 -56.987362 -0.776358 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger21" "ValveBiped.Bip01_R_Finger2" 1.719579 0 0 0.529126 -84.10292 -1.044335 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger22" "ValveBiped.Bip01_R_Finger21" 1.20918 -0.000002 -0.000008 0.393674 -65.444824 -0.523629 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger1" "ValveBiped.Bip01_R_Hand" 3.871304 0.117424 -1.300907 -1.447001 -62.332368 -4.480647 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger11" "ValveBiped.Bip01_R_Finger1" 1.719431 0 -0.000004 2.29372 -87.862276 -5.638711 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger12" "ValveBiped.Bip01_R_Finger11" 1.099665 -0.000001 -0.000004 3.001606 -53.062152 -2.480852 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger0" "ValveBiped.Bip01_R_Hand" 0.838848 -0.300291 -1.312786 19.396178 -37.30788 59.495531 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger01" "ValveBiped.Bip01_R_Finger0" 1.78978 -0.000002 0 0.212621 19.064701 -0.000002 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger02" "ValveBiped.Bip01_R_Finger01" 1.207002 0.000004 0 0.324749 35.095117 -0.000003 0 0 0 0 0 0
$definebone "ValveBiped.Base" "ValveBiped.Bip01_R_Hand" -0.534583 0.295797 -0.001972 1.264977 -107.070974 -91.208024 0 0 0 0 0 0
$definebone "ValveBiped.Casing_RotZ" "ValveBiped.Base" 0.113788 -0.132996 14.720029 -0.000005 0.000001 0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Gyro1_RotX" "ValveBiped.Base" 0.113787 -0.13298 9.513787 -0.000005 0.000001 0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Gyro2_RotY" "ValveBiped.Gyro1_RotX" -0.000001 0.000004 0 -0.000005 0.000001 0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Gyro3_RotX" "ValveBiped.Gyro2_RotY" -0.000001 0 0 -0.000005 0.000001 0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Mag1_RotZ" "ValveBiped.Base" 0.113791 -0.132973 16.48138 -0.000005 0.000001 0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Mag2_RotZ" "ValveBiped.Base" 0.113788 -0.132973 18.076752 -0.000005 0.000001 0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Mag3_RotZ" "ValveBiped.Base" 0.113789 -0.132969 19.676247 -0.000005 0.000001 0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Mag4_RotZ" "ValveBiped.Base" 0.113791 -0.13298 21.255905 -0.000005 0.000001 0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Mag5_RotZ" "ValveBiped.Base" 0.113788 -0.13298 22.869106 -0.000005 0.000001 0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Mag6_RotZ" "ValveBiped.Base" 0.113791 -0.13298 24.483315 -0.000005 0.000001 0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Mag7_RotZ" "ValveBiped.Base" 0.11379 -0.132977 26.066456 -0.000005 0.000001 0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Mag8_RotZ" "ValveBiped.Base" 0.11379 -0.13298 27.6651 -0.000005 0.000001 0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Arm1_A" "ValveBiped.Base" 4.717026 4.484177 33.327862 1.693261 -43.673944 1.768957 0 0 0 0 0 0
$definebone "ValveBiped.Arm1_B" "ValveBiped.Arm1_A" 0.089302 4.272583 4.480568 -0.000002 0.000002 0.000007 0 0 0 0 0 0
$definebone "ValveBiped.Arm2_A" "ValveBiped.Base" 4.922175 -5.137234 33.583321 0.000007 -133.342464 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Arm2_B" "ValveBiped.Arm2_A" 0.001394 4.1674 4.226917 0.000007 0.000007 0 0 0 0 0 0 0
$definebone "ValveBiped.Arm3_A" "ValveBiped.Base" -4.578506 -5.283134 33.331905 0.000002 139.738786 -0.000007 0 0 0 0 0 0
$definebone "ValveBiped.Arm3_B" "ValveBiped.Arm3_A" 0.269684 4.148857 4.474522 0.000002 -0.000007 -0.000007 0 0 0 0 0 0
$definebone "ValveBiped.Arm4_A" "ValveBiped.Base" -4.409222 4.440941 33.338566 -0.000007 43.753762 -0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Arm4_B" "ValveBiped.Arm4_A" -0.045498 4.393921 4.464542 -0.000007 -0.000002 0 0 0 0 0 0 0
$definebone "ValveBiped.Dial" "ValveBiped.Base" -4.439061 3.922569 13.956212 -23.598061 36.368336 4.334942 0 0 0 0 0 0
$definebone "ValveBiped.Mag9_RotZ" "ValveBiped.Base" 0.113791 -0.132977 29.243565 -0.000005 0.000001 0.000004 0 0 0 0 0 0
$definebone "Root" "" 0 -6 -0.5 0 0 89.999982 0 0 0 0 0 0


$sectionframes 30 120

$animation "@center_rotation_layer1_corrective_animation" "v_portalgun_anims\@center_rotation_layer1_corrective_animation.smd" {
}

$sequence "idle" {
	"v_portalgun_anims\idle.smd"
	activity "ACT_VM_IDLE" 1
	fadein 0.2
	fadeout 0.2
	node "Ready"
	fps 30
	loop
}

$sequence "fire1" {
	"v_portalgun_anims\fire1.smd"
	activity "ACT_VM_PRIMARYATTACK" 1
	{ event AE_MUZZLEFLASH 0 "COMBINE MUZZLE" }
	fadein 0.2
	fadeout 0.2
	node "Fire"
	snap
	fps 30
}

$sequence "fizzle" {
	"v_portalgun_anims\fizzle.smd"
	activity "ACT_VM_FIZZLE" 1
	fadein 0.2
	fadeout 0.2
	node "Ready"
	snap
	fps 30
}

$sequence "draw" {
	"v_portalgun_anims\draw.smd"
	activity "ACT_VM_DRAW" 1
	fadein 0.2
	fadeout 0.2
	node "Ready"
	snap
	fps 30
}

$sequence "pickup" {
	"v_portalgun_anims\pickup.smd"
	activity "ACT_VM_PICKUP" 1
	fadein 0.2
	fadeout 0.2
	node "Fire"
	fps 30
}

$sequence "release" {
	"v_portalgun_anims\release.smd"
	activity "ACT_VM_RELEASE" 1
	fadein 0.2
	fadeout 0.2
	node "Fire"
	fps 30
}

$sequence "center_rotation_layer1" {
	"v_portalgun_anims\center_rotation_layer1.smd"
	autoplay
	delta
	// Crowbar writes this subtract option to prevent jigglebone and poseparameter problems when delta sequences are recompiled.
	subtract "@center_rotation_layer1_corrective_animation" 0
	fadein 0.2
	fadeout 0.2
	node "Ready"
	fps 30
	loop
}
