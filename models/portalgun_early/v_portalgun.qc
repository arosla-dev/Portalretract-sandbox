// Created by Crowbar 0.74

$modelname "weapons/v_portalgun_early.mdl"

$bodygroup "studio"
{
	studio "v_portalgun_reference.smd"
}


$surfaceprop "default"

$contents "solid"

$illumposition -1.325 -29.59 -7.361

$cdmaterials "models\Weapons\v_models\v_portalgun_early\"

$attachment "Arm1_attach1" "ValveBiped.Arm1_A" 0 0 0 rotate 0 0 0
$attachment "Arm1_attach2" "ValveBiped.Arm1_B" 0 0.2 -0.1 rotate 0 0 0
$attachment "Arm1_attach3" "ValveBiped.Arm1_B" 0 -2 3.25 rotate 0 0 0
$attachment "Arm2_attach1" "ValveBiped.Arm2_A" 0 0 0 rotate 0 0 0
$attachment "Arm2_attach2" "ValveBiped.Arm2_B" 0 0.2 -0.1 rotate 0 0 0
$attachment "Arm2_attach3" "ValveBiped.Arm2_B" 0 -2 3.25 rotate 0 0 0
$attachment "Arm3_attach1" "ValveBiped.Arm4_A" 0 0 -0.3 rotate 0 0 0
$attachment "Arm3_attach2" "ValveBiped.Arm4_B" -0.1 0.3 -0.1 rotate 0 0 0
$attachment "Arm3_attach3" "ValveBiped.Arm4_B" 0 -2 3.25 rotate 0 0 0
$attachment "Body_light" "ValveBiped.Gyro1_RotX" 0 0 0 rotate 0 0 0
$attachment "Beam_point1" "ValveBiped.Mag9_RotZ" 0.01 2.4 -3.1 rotate 0 0 0
$attachment "Beam_point2" "ValveBiped.Mag9_RotZ" -0.01 2.39 -3.4 rotate 0 0 0
$attachment "Beam_point3" "ValveBiped.Mag9_RotZ" -0.02 2.37 -3.7 rotate 0 0 0
$attachment "Beam_point4" "ValveBiped.Mag9_RotZ" -0.04 2.36 -4 rotate 0 0 0
$attachment "Beam_point5" "ValveBiped.Mag9_RotZ" -0.05 2.35 -4.3 rotate 0 0 0
$attachment "Inside_effects" "ValveBiped.Mag9_RotZ" 0 2.2 0 rotate 0 0 0
$attachment "muzzle" "ValveBiped.Mag9_RotZ" 0 2.2 2.8 rotate -90 0 0

$cbox 0 0 0 0 0 0

$bbox -1.521 -17.501 -19.468 60.292 17.019 5.709

$definebone "ValveBiped.Bip01" "" 0 -0.533595 38.566879 0 0 89.999982 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Spine" "ValveBiped.Bip01" 0 3.345131 -2.981898 4.766608 89.999982 89.999982 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Spine1" "ValveBiped.Bip01_Spine" 3.995838 0 0 0 -1.651035 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Spine2" "ValveBiped.Bip01_Spine1" 3.520287 0 0 0 5.57528 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_Spine4" "ValveBiped.Bip01_Spine2" 8.921467 0 0 0 10.680679 0 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Clavicle" "ValveBiped.Bip01_Spine4" 2.059517 0.977921 1.937661 -73.711873 169.030981 91.085395 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_UpperArm" "ValveBiped.Bip01_L_Clavicle" 15.71209 -18.004036 9.529778 -78.995598 179.290362 89.335534 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Forearm" "ValveBiped.Bip01_L_UpperArm" 11.692564 0 0.000011 -0.000003 -42.73302 -0.000003 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Hand" "ValveBiped.Bip01_L_Forearm" 11.481674 0.000001 -0.000038 5.028163 42.789356 76.158699 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger4" "ValveBiped.Bip01_L_Hand" 3.850418 0.126099 -1.22344 -10.466678 -67.332053 -18.180866 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger41" "ValveBiped.Bip01_L_Finger4" 1.312563 0.000004 0 2.377087 -63.774842 -2.017382 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger42" "ValveBiped.Bip01_L_Finger41" 0.729366 0 0 2.211448 -32.527669 -0.749146 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger3" "ValveBiped.Bip01_L_Hand" 3.92635 0.31649 -0.462519 -9.114031 -62.422267 -9.677947 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger31" "ValveBiped.Bip01_L_Finger3" 1.539099 0 -0.000002 0.099643 -76.471474 -0.189542 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger32" "ValveBiped.Bip01_L_Finger31" 1.196327 0.000001 -0.000002 0.25387 -68.765935 -0.245869 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger2" "ValveBiped.Bip01_L_Hand" 3.881382 0.214691 0.400253 -11.728147 -59.038332 -3.241508 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger21" "ValveBiped.Bip01_L_Finger2" 1.719582 0.000004 0 -0.453553 -88.178316 1.079325 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger22" "ValveBiped.Bip01_L_Finger21" 1.209179 0 0.000006 -0.464562 -57.218376 0.461913 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger1" "ValveBiped.Bip01_L_Hand" 3.871292 0.117428 1.300903 -10.91129 -66.478866 -1.148324 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger11" "ValveBiped.Bip01_L_Finger1" 1.719427 -0.000004 0.000002 -1.846473 -92.328421 5.800104 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger12" "ValveBiped.Bip01_L_Finger11" 1.09967 0 -0.000002 -3.048249 -51.971336 2.423269 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger0" "ValveBiped.Bip01_L_Hand" 0.838837 -0.300285 1.312775 -27.949173 -36.053027 -48.55743 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger01" "ValveBiped.Bip01_L_Finger0" 1.789784 -0.000002 0.000008 -0.210222 21.707832 -0.031854 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_L_Finger02" "ValveBiped.Bip01_L_Finger01" 1.207006 0 0.000004 -0.310146 38.061871 -0.096369 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Clavicle" "ValveBiped.Bip01_Spine4" 2.059521 0.977922 -1.937661 73.711873 169.030994 -95.200891 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_UpperArm" "ValveBiped.Bip01_R_Clavicle" 7.18644 -2.479385 7.933253 41.2509 -73.337216 97.486136 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Forearm" "ValveBiped.Bip01_R_UpperArm" 11.69257 -0.000004 0 0.000001 -42.140761 -0.000002 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Hand" "ValveBiped.Bip01_R_Forearm" 11.481656 0 0.000016 10.385551 -11.253236 -92.297658 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger4" "ValveBiped.Bip01_R_Hand" 3.850428 0.1261 1.223442 3.404289 -70.833863 12.515345 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger41" "ValveBiped.Bip01_R_Finger4" 1.312562 0.000001 0 -3.019141 -37.868259 0.776704 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger42" "ValveBiped.Bip01_R_Finger41" 0.729362 0.000001 0 -1.183899 -73.35395 2.012568 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger3" "ValveBiped.Bip01_R_Hand" 3.926356 0.316488 0.462509 1.051092 -60.276829 4.522184 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger31" "ValveBiped.Bip01_R_Finger3" 1.539095 0 -0.000004 -0.124388 -68.678604 0.174236 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger32" "ValveBiped.Bip01_R_Finger31" 1.196321 0.000001 0.000011 -0.229642 -74.156218 0.268602 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger2" "ValveBiped.Bip01_R_Hand" 3.881387 0.214694 -0.400257 -0.125533 -56.987359 -0.776357 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger21" "ValveBiped.Bip01_R_Finger2" 1.719579 0 0 0.529127 -84.10292 -1.044332 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger22" "ValveBiped.Bip01_R_Finger21" 1.20918 -0.000002 -0.000004 0.393677 -65.44483 -0.523628 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger1" "ValveBiped.Bip01_R_Hand" 3.871304 0.117425 -1.300903 -1.447004 -62.332368 -4.480644 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger11" "ValveBiped.Bip01_R_Finger1" 1.71943 0 -0.000004 2.293722 -87.862276 -5.638708 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger12" "ValveBiped.Bip01_R_Finger11" 1.099665 -0.000001 0 3.001609 -53.062148 -2.480852 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger0" "ValveBiped.Bip01_R_Hand" 0.838849 -0.30029 -1.312782 19.396175 -37.307873 59.495531 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger01" "ValveBiped.Bip01_R_Finger0" 1.78978 -0.000002 0 0.212621 19.064707 0.000002 0 0 0 0 0 0
$definebone "ValveBiped.Bip01_R_Finger02" "ValveBiped.Bip01_R_Finger01" 1.207002 0.000004 0 0.324747 35.09511 -0.000002 0 0 0 0 0 0
$definebone "ValveBiped.Base" "ValveBiped.Bip01_R_Hand" -0.534583 0.295798 -0.001972 1.264977 -107.070974 -91.208017 0 0 0 0 0 0
$definebone "ValveBiped.Casing_RotZ" "ValveBiped.Base" 0.113788 -0.132996 14.72003 -0.000004 0.000001 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Gyro1_RotX" "ValveBiped.Base" 0.113788 -0.13298 9.513786 -0.000004 0.000001 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Gyro2_RotY" "ValveBiped.Gyro1_RotX" 0 0 0 -0.000004 0.000001 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Gyro3_RotX" "ValveBiped.Gyro2_RotY" -0.000001 0 0 -0.000004 0.000001 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Mag1_RotZ" "ValveBiped.Base" 0.11379 -0.13298 16.481384 -0.000004 0.000001 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Mag2_RotZ" "ValveBiped.Base" 0.113787 -0.132977 18.076756 -0.000004 0.000001 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Mag3_RotZ" "ValveBiped.Base" 0.113789 -0.132977 19.676249 -0.000004 0.000001 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Mag4_RotZ" "ValveBiped.Base" 0.113791 -0.13298 21.255907 -0.000004 0.000001 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Mag5_RotZ" "ValveBiped.Base" 0.113788 -0.132984 22.869108 -0.000004 0.000001 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Mag6_RotZ" "ValveBiped.Base" 0.113791 -0.132984 24.483316 -0.000004 0.000001 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Mag7_RotZ" "ValveBiped.Base" 0.113789 -0.13298 26.066462 -0.000004 0.000001 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Mag8_RotZ" "ValveBiped.Base" 0.11379 -0.132984 27.665102 -0.000004 0.000001 0.000001 0 0 0 0 0 0
$definebone "ValveBiped.Arm1_A" "ValveBiped.Base" 4.717025 4.484173 33.327866 1.69326 -43.673944 1.768954 0 0 0 0 0 0
$definebone "ValveBiped.Arm1_B" "ValveBiped.Arm1_A" 0.089298 4.272583 4.480568 -0.000003 -0.000005 0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Arm2_A" "ValveBiped.Base" 4.922175 -5.137238 33.583321 0.000004 -133.342464 0.000002 0 0 0 0 0 0
$definebone "ValveBiped.Arm2_B" "ValveBiped.Arm2_A" 0.001396 4.1674 4.226917 0.000004 0.000003 0.000002 0 0 0 0 0 0
$definebone "ValveBiped.Arm3_A" "ValveBiped.Base" -4.578506 -5.283134 33.331909 0.000003 139.738786 -0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Arm3_B" "ValveBiped.Arm3_A" 0.269684 4.148857 4.474522 0.000003 -0.000009 -0.000004 0 0 0 0 0 0
$definebone "ValveBiped.Arm4_A" "ValveBiped.Base" -4.409222 4.440937 33.33857 -0.000004 43.753762 -0.000002 0 0 0 0 0 0
$definebone "ValveBiped.Arm4_B" "ValveBiped.Arm4_A" -0.045496 4.393921 4.464542 -0.000004 0.000002 -0.000002 0 0 0 0 0 0
$definebone "ValveBiped.Dial" "ValveBiped.Base" -4.43906 3.922565 13.956215 -23.598063 36.368336 4.33494 0 0 0 0 0 0
$definebone "ValveBiped.Mag9_RotZ" "ValveBiped.Base" 0.113791 -0.13298 29.243567 -0.000004 0.000001 0.000001 0 0 0 0 0 0
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
