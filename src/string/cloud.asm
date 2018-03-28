.ifdef LANG_GER
.global str_use_cloud

str_use_cloud:
	.string "Die Wolken scheinen hier tief zu\nschweben.\pMöchtest du auf deine Wolke\nsteigen?"


.global str_cloud_used

str_cloud_used:
	.string "Die Wolke trägt dich empor!"


.global str_use_cloud_back

str_use_cloud_back:
	.string "Die Wolken sind hier durchlässig.\nMöchtest du zum Boden zurückkehren?"


.global str_cloud_used_back

str_cloud_used_back:
	.string "Die Wolke trägt dich hinab!"


.global str_cloud_none

str_cloud_none:
	.string "Die Wolken scheinen hier tief zu\nschweben..."


.elseif LANG_EN
	.global str_use_cloud

	str_use_cloud:
		.string "The clouds seem to be floating\nnear the ground.\npDo you want to ascend\nby using your cloud?"

	.global str_cloud_used

	str_cloud_used:
		.string "The cloud carries you\nupwards!"

	.global str_use_cloud_back

	str_use_cloud_back:
		.string "The clouds seem not to be\nvery dense at this spot.\nDou you want to return\nto the ground?"

	.global str_cloud_used_back

	str_cloud_used_back:
		.string "The cloud returns you\nto the ground."

	.global str_cloud_none

	str_cloud_none:
		.string "The clouds seem to be floating\nnear the ground..."

.endif
